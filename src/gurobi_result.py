

from fpcore_ast import Variable, Number, Operation
from fpcore_logging import Logger
from gurobipy import GRB

import all_modifications_ast
import gurobipy as gp
import infix_str_ast
import mpmath

mpmath.prec = 1000
logger = Logger(level=Logger.HIGH, color=Logger.magenta)


class GurobiResult:
    # Notes:
    # https://www.gurobi.com/documentation/9.0/refman/num_advanced_user_scaling.html
    # Gurobi wants coefficients in the range [10^-3, 10^6]
    # https://www.gurobi.com/documentation/9.0/refman/num_dealing_with_big_m_con.html
    # use SOS constraints for what we want
    # https://www.gurobi.com/documentation/9.0/refman/num_presolve.html
    # ways to check numerical instability

    BIT_WIDTH_ORDER = ["fp32", "fp64", "fp128"]
    BIT_WIDTH_COST = [1, 20, 40]
    DENOM_ORDER = [2**24, 2**53, 2**113]
    BIT_WIDTH_TO_DENOM = dict(zip(BIT_WIDTH_ORDER, DENOM_ORDER))

    def __init__(self, ssa, max_error):
        self.raw_max_error = max_error
        self.max_error = mpmath.ceil(mpmath.mpf(max_error) / mpmath.mpf(2**53))
        self.string_list = list()
        self.ssa = ssa

        self.model = gp.Model()
        # self.model.Params.OutputFlag = 0
        self.model.Params.NumericFocus = 3
        self.model.Params.IntFeasTol = 1e-9

        self.bit_width_choices = self.get_bit_width_choices()
        #self.epsilons = self.get_epsilons()
        self.operation_choices = self.get_operation_choices()

        self.expression_errors = self.get_expression_errors()
        self.error = self.add_error()
        self.bit_width_costs = self.get_bit_width_costs()
        self.operation_costs = self.get_operation_costs()
        self.cost = self.add_cost()

        self.model.addConstr(self.error <= self.max_error)
        self.model.update()
        self.string_list.append("{} <= {}".format(self.error.VarName, max_error))

        self.model.setObjective(self.cost, GRB.MINIMIZE)
        self.string_list.append("minimize {}".format(self.cost.VarName))

        logger.log("gurobi query:\n{}\n", "\n".join(self.string_list))

        self.model.optimize()

        if logger.should_log():
            self.model.printQuality()

    def get_bit_width_choices(self):

        # name -> {bit_width -> gurobi_bool}
        bit_width_choices = dict()

        # Go through every expression
        for name in self.ssa.fptaylor_forms:

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.string_list.append("# type for {} = {}".format(name, val))

            # Setup the list of variable names, and make the gurobi booleans
            bit_options = self.ssa.search_space["bit_widths"]
            names = ["{}_is_{}".format(name, bw) for bw in bit_options]
            grb_vars = [self.model.addVar(vtype=GRB.BINARY, name=n)
                        for n in names]
            self.string_list.append("bool {}".format(", ".join(names)))

            # Assert that the sum of the booleans is 1 (i.e. only one is "true")
            self.model.addConstr(1 == sum(grb_vars))
            self.string_list.append("1 == {}".format(" + ".join(names)))

            # Update our dictonary
            bit_width_choices[name] = {bw:var for bw,var
                                       in zip(bit_options, grb_vars)}
            self.string_list.append("")

        return bit_width_choices

    def get_epsilons(self):

        # name -> gurobi_real
        epsilons = dict()

        # Go through every expression
        for name, choices in self.bit_width_choices.items():

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.string_list.append("# epsilon for {} = {}".format(name, val))

            # Get the associated denominator for each bit width
            bit_options = self.ssa.search_space["bit_widths"]
            denoms = [GurobiResult.BIT_WIDTH_TO_DENOM[bw] for bw in bit_options]

            # Use those to create a list so that when one boolean is 1, the
            # sum is the epsilon for the given bit width
            grb_bools = [choices[bw] for bw in bit_options]
            epsilon_parts = [grb_var/d for grb_var,d in zip(grb_bools, denoms)]
            self.model.update()
            strings = ["{}/{}".format(grb_var.VarName, d)
                       for grb_var, d in zip(grb_bools, denoms)]
            epsilon_name = "{}_eps".format(name)

            # Sum these and get the result
            grb_epsilon = self.model.addVar(name=epsilon_name)
            self.model.addConstr(grb_epsilon == sum(epsilon_parts))
            self.string_list.append("real {} = {}".format(epsilon_name,
                                                          " + ".join(strings)))
            # Update our dictionary
            epsilons[name] = grb_epsilon
            self.string_list.append("")

        return epsilons

    def get_operation_choices(self):

        # name -> {impl -> gurobi_bool}
        operation_choices = dict()

        # Go through expressions whose operation we can select
        for name in self.ssa.operations:

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.string_list.append("# operation for {} = {}".format(name, val))

            # Setup the list of variable names, and make the gurobi booleans
            op = self.ssa.definitions[name].op
            impls = [impl for impl in self.ssa.search_space["operations"][op]]
            names = ["{}_is_{}".format(name, impl) for impl in impls]
            grb_vars = [self.model.addVar(vtype=GRB.BINARY, name=n)
                        for n in names]
            self.string_list.append("bool {}".format(", ".join(names)))

            # Assert that the sum of the booleans is 1 (i.e. only one is "true")
            self.model.addConstr(1 == sum(grb_vars))
            self.string_list.append("1 == {}".format(" + ".join(names)))

            # Update our dictonary
            operation_choices[name] = {impl:var for impl,var
                                       in zip(impls, grb_vars)}
            self.string_list.append("")

        return operation_choices

    def get_expression_errors(self):
        expression_errors = dict()
        self.model.update()

        # Go through all expressions
        for name, forms in self.ssa.fptaylor_forms.items():

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.string_list.append("# error for {} = {}".format(name, val))

            # get out epsilon variable and make the error variable
            bit_options = self.ssa.search_space["bit_widths"]
            denoms = [GurobiResult.BIT_WIDTH_TO_DENOM[bw] for bw in bit_options]
            bit_choices = [self.bit_width_choices[name][bw] for bw in bit_options]
            error_name = "{}_error".format(name)
            this_error = self.model.addVar(name=error_name)

            # Check if this expression has only one impl
            if name not in self.ssa.operations:

                # Error can be computed as eps*max(fptaylor_form)
                form = forms["default"]
                err, err_string = form.to_gurobi(bit_choices, denoms)
                self.model.addConstr(this_error == err)
                self.string_list.append("{} = {}".format(error_name, err_string))
                expression_errors[name] = this_error
                self.string_list.append("")

                # Go onto the next expression
                continue

            # The expression has multiple impls
            options = list()
            options_str = list()
            for tup, form in forms.items():
                if type(tup) == str and tup == "default":
                    oper = self.ssa.definitions[name].op
                    bool = self.operation_choices[name][oper]
                    val, val_str = forms["default"].to_gurobi(bit_choices, denoms)
                    options.append(val * bool)
                    options_str.append("({})*{}".format(val_str, bool.VarName))
                    continue
                target_name, oper = tup
                bool = self.operation_choices[target_name][oper]
                val, val_str = form.to_gurobi(bit_choices, denoms)
                options.append(val * bool)
                options_str.append("({})*{}".format(val_str, bool.VarName))
            self.model.addConstr(this_error == sum(options))
            self.string_list.append("{} = {}".format(error_name, " + ".join(options_str)))
            expression_errors[name] = this_error
            self.string_list.append("")

        return expression_errors

        # def get_expression_errors(self):
        # expression_errors = dict()
        # self.model.update()

        # # Go through all expressions
        # for name, forms in self.ssa.fptaylor_forms.items():

        #     # Note what we are working on
        #     val = self.ssa.definitions[name]
        #     self.string_list.append("# error for {} = {}".format(name, val))

        #     # get out epsilon variable and make the error variable
        #     this_eps = self.epsilons[name]
        #     error_name = "{}_error".format(name)
        #     this_error = self.model.addVar(name=error_name)

        #     # Check if this expression has only one impl
        #     if name not in self.ssa.operations:

        #         # Error can be computed as eps*max(fptaylor_form)
        #         form = forms["default"]
        #         err, err_string = form.to_gurobi(this_eps)
        #         self.model.addConstr(this_error == err)
        #         self.string_list.append("{} = {}".format(error_name, err_string))
        #         expression_errors[name] = this_error
        #         self.string_list.append("")

        #         # Go onto the next expression
        #         continue

        #     # The expression has multiple impls
        #     options = list()
        #     options_str = list()
        #     for tup, form in forms.items():
        #         if type(tup) == str and tup == "default":
        #             oper = self.ssa.definitions[name].op
        #             bool = self.operation_choices[name][oper]
        #             val, val_str = forms["default"].to_gurobi(this_eps)
        #             options.append(val * bool)
        #             options_str.append("({})*{}".format(val_str, bool.VarName))
        #             continue
        #         target_name, oper = tup
        #         bool = self.operation_choices[target_name][oper]
        #         val, val_str = form.to_gurobi(this_eps)
        #         options.append(val * bool)
        #         options_str.append("({})*{}".format(val_str, bool.VarName))
        #     self.model.addConstr(this_error == sum(options))
        #     self.string_list.append("{} = {}".format(error_name, " + ".join(options_str)))
        #     expression_errors[name] = this_error
        #     self.string_list.append("")

        # return expression_errors

    def add_error(self):
        # Note what we are working on
        self.string_list.append("# total error for expression")

        error = self.model.addVar(name="total_error")
        self.model.addConstr(error == sum(self.expression_errors.values()))
        self.model.update()
        self.string_list.append("{} = {}".format(error.VarName,
                                                 " + ".join([v.VarName for v in self.expression_errors.values()])))
        self.string_list.append("")
        return error

    def get_bit_width_costs(self):
        costs = dict()
        for name, bools in self.bit_width_choices.items():

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.string_list.append("# cost for bit width of {} = {}".format(name, val))

            cost = self.model.addVar(name="{}_bit_width_cost".format(name))
            cost_pairs = list(zip(range(1, 20*len(bools)+1, 20), bools.values()))
            self.model.addConstr(cost == sum([i*b for i, b in cost_pairs]))
            costs[name] = cost
            self.model.update()
            self.string_list.append("{} = {}".format(cost.VarName,
                                                     " + ".join(["{}*{}".format(i, b.VarName) for i,b in cost_pairs])))
            self.string_list.append("")

        return costs

    def get_operation_costs(self):
        costs = dict()
        for name, bools in self.operation_choices.items():

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.string_list.append("# cost for implementation of {} = {}".format(name, val))

            op = self.ssa.definitions[name].op
            op_costs = [all_modifications_ast.OperationToCost[oper]
                        for oper in self.ssa.search_space["operations"][op]]
            cost_pairs = list(zip(op_costs, bools.values()))
            cost = self.model.addVar(name="{}_operation_cost".format(name))
            self.model.addConstr(cost == sum([c*b for c, b in cost_pairs]))
            self.model.update()
            costs[name] = cost
            self.string_list.append("{} = {}".format(cost.VarName,
                                                     " + ".join(["{}*{}".format(c, b.VarName) for c,b in cost_pairs])))
            self.string_list.append("")

        return costs

    def add_cost(self):
        self.string_list.append("# total cost for expression")

        cost = self.model.addVar(name="total_cost")
        self.model.addConstr(cost == sum(self.bit_width_costs.values())
                             + sum(self.operation_costs.values()))
        self.model.update()
        self.string_list.append("{} = {} + {}".format(cost.VarName,
                                                      " + ".join([v.VarName for v in self.bit_width_costs.values()]),
                                                      " + ".join([v.VarName for v in self.operation_costs.values()])))
        self.string_list.append("")
        return cost

