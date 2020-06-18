

from fpcore_ast import Variable, Number, Operation
from fpcore_logging import Logger

import all_modifications_ast
import fractions
import infix_str_ast
import z3

logger = Logger(level=Logger.HIGH, color=Logger.magenta)


class Z3Result:

    BIT_WIDTH_ORDER = ["fp32", "fp64", "fp128"]
    BIT_WIDTH_COST = [1, 20, 40]
    DENOM_ORDER = [2**24, 2**53, 2**113]
    BIT_WIDTH_TO_DENOM = dict(zip(BIT_WIDTH_ORDER, DENOM_ORDER))

    def __init__(self, ssa, raw_max_error):
        self.raw_max_error = raw_max_error
        self.query_string_list = list()
        self.ssa = ssa

        self.bit_width_choices = self.get_bit_width_choices()
        self.epsilons = self.get_epsilons()
        self.operation_choices = self.get_operation_choices()

        self.expression_errors = self.get_expression_errors()
        self.error = self.add_error()
        self.bit_width_costs = self.get_bit_width_costs()
        self.operation_costs = self.get_operation_costs()
        self.cost = self.add_cost()

        max_error = self.get_max_error()
        self.query_string_list.append("(assert (<= {} {}))".format(self.error, max_error))
        self.query_string_list.append("(minimize {})".format(self.cost))
        self.query_string_list.append("(check_sat)")

        self.query = "\n".join(self.query_string_list)

        max_lineno = len(self.query_string_list)+1
        formatter = "{{:{}}}: {{}}".format(len(str(max_lineno)))
        linenos = range(1, max_lineno)
        numbered_lines = [formatter.format(i,l)
                          for i,l in zip(linenos, self.query_string_list)]
        #logger.log("z3 query:\n{}\n", "\n".join(numbered_lines))
        logger.log("z3 query:\n{}\n", self.query)

        self.optimizer = z3.Optimize()
        self.optimizer.from_string(self.query)
        self.optimizer.check()
        z3_model = self.optimizer.model()
        self.model = {d.name(): z3_model[d] for d in z3_model}

        if logger.should_log():
            print(self.model)

    def get_max_error(self):
        return "{:.20f}".format(self.raw_max_error)

    def get_bit_width_choices(self):

        # name -> {bit_width -> z3_name}
        bit_width_choices = dict()

        # add bool_to_int
        self.query_string_list.extend(["(define-fun bool_to_int ((b Bool)) Int",
                                       "  (ite b 1 0)",
                                       ")",
                                       "",])

        # add bool_to_real
        self.query_string_list.extend(["(define-fun bool_to_real ((b Bool)) Real",
                                       "  (ite b 1.0 0.0)",
                                       ")",
                                       "",])

        # Go through every expression
        for name in self.ssa.fptaylor_forms:

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.query_string_list.append("; type for {} = {}".format(name, val))

            # Setup the list of variable names
            bit_options = self.ssa.search_space["bit_widths"]
            names = ["{}_is_{}".format(name, bw) for bw in bit_options]
            query_decls = ["(declare-const {} Bool)".format(n) for n in names]
            self.query_string_list.extend(query_decls)

            # Assert that the sum of the booleans is 1 (i.e. only one is "true")
            converted = ["(bool_to_int {})".format(n) for n in names]
            assertion = "(assert (= 1 (+ {})))".format(" ".join(converted))
            self.query_string_list.append(assertion)

            # Update our dictonary
            bit_width_choices[name] = {bw:n for bw,n
                                       in zip(bit_options, names)}
            self.query_string_list.append("")

        return bit_width_choices

    def get_epsilons(self):

        # name -> z3_name
        epsilons = dict()

        # Go through every expression
        for name, choices in self.bit_width_choices.items():

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.query_string_list.append("; epsilon for {} = {}".format(name, val))

            # Get the associated denominator for each bit width
            bit_options = self.ssa.search_space["bit_widths"]
            denoms = [Z3Result.BIT_WIDTH_TO_DENOM[bw] for bw in bit_options]

            # Use those to create a list so that when one boolean is 1, the
            # sum is the epsilon for the given bit width
            z3_bools = [choices[bw] for bw in bit_options]
            epsilon_parts = ["(/ (bool_to_real {}) {})".format(b, d)
                             for b,d in zip(z3_bools, denoms)]

            # Sum these and get the result
            epsilon_name = "{}_eps".format(name)
            epsilon = "(define-fun {} () Real (+ {}))".format(epsilon_name, " ".join(epsilon_parts))
            self.query_string_list.append(epsilon)

            # Update our dictionary
            epsilons[name] = epsilon_name
            self.query_string_list.append("")

        return epsilons

    def get_operation_choices(self):

        # name -> {impl -> z3_name}
        operation_choices = dict()

        # Go through expressions whose operation we can select
        for name in self.ssa.operations:

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.query_string_list.append("; operation for {} = {}".format(name, val))

            # Setup the list of variable names, and make the z3 booleans
            op = self.ssa.definitions[name].op
            impls = [impl for impl in self.ssa.search_space["operations"][op]]
            names = ["{}_is_{}".format(name, impl) for impl in impls]
            query_decls = ["(declare-const {} Bool)".format(n) for n in names]
            self.query_string_list.extend(query_decls)

            # Assert that the sum of the booleans is 1 (i.e. only one is "true")
            converted = ["(bool_to_int {})".format(n) for n in names]
            assertion = "(assert (= 1 (+ {})))".format(" ".join(converted))
            self.query_string_list.append(assertion)

            # Update our dictonary
            operation_choices[name] = {impl:n for impl,n
                                       in zip(impls, names)}
            self.query_string_list.append("")

        return operation_choices

    def get_expression_errors(self):
        expression_errors = dict()

        # Go through all expressions
        for name, forms in self.ssa.fptaylor_forms.items():

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.query_string_list.append("; error for {} = {}".format(name, val))

            # get out epsilon variable and make the error variable
            this_eps = self.epsilons[name]
            error_name = "{}_error".format(name)
            expression_errors[name] = error_name

            # Check if this expression has only one impl
            if name not in self.ssa.operations:

                # Error can be computed as eps*max(fptaylor_form)
                form = forms["default"]
                error = form.to_z3(this_eps)
                self.query_string_list.append("(define-fun {} () Real {})".format(error_name, error))
                self.query_string_list.append("")

                # Go onto the next expression
                continue

            # The expression has multiple impls
            options_str = list()
            for tup, form in forms.items():
                if type(tup) == str and tup == "default":
                    oper = self.ssa.definitions[name].op
                    bool = self.operation_choices[name][oper]
                    val = forms["default"].to_z3(this_eps)
                    options_str.append("(* {} (bool_to_real {}))".format(val, bool))
                    continue
                target_name, oper = tup
                bool = self.operation_choices[target_name][oper]
                val = form.to_z3(this_eps)
                options_str.append("(* {} (bool_to_real {}))".format(val, bool))

            self.query_string_list.append("(define-fun {} () Real (+ {}))".format(error_name, " ".join(options_str)))
            self.query_string_list.append("")

        return expression_errors

    def add_error(self):
        # Note what we are working on
        self.query_string_list.append("; total error for expression")

        error_name = "total_error"
        errors = " ".join([v for v in self.expression_errors.values()])
        self.query_string_list.append("(define-fun {} () Real (+ {}))".format(error_name,
                                                                                errors))
        self.query_string_list.append("")
        return error_name

    def get_bit_width_costs(self):
        costs = dict()
        for name, bools in self.bit_width_choices.items():

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.query_string_list.append("; cost for bit width of {} = {}".format(name, val))

            cost_name = "{}_bit_width_cost".format(name)
            bw_costs = range(1, 20*len(bools)+1, 20)
            cost_parts = ["(* {} (bool_to_int {}))".format(c, b)
                          for c,b in zip(bw_costs, bools.values())]
            cost = " ".join(cost_parts)
            self.query_string_list.append("(define-fun {} () Int (+ {}))".format(cost_name, cost))
            costs[name] = cost_name
            self.query_string_list.append("")

        return costs

    def get_operation_costs(self):
        costs = dict()
        for name, bools in self.operation_choices.items():

            # Note what we are working on
            val = self.ssa.definitions[name]
            self.query_string_list.append("; cost for implementation of {} = {}".format(name, val))

            cost_name = "{}_operation_cost".format(name)
            op = self.ssa.definitions[name].op
            op_costs = [all_modifications_ast.OperationToCost[oper]
                        for oper in self.ssa.search_space["operations"][op]]
            cost_parts = ["(* {} (bool_to_int {}))".format(c, b)
                          for c,b in zip(op_costs, bools.values())]
            cost = " ".join(cost_parts)
            self.query_string_list.append("(define-fun {} () Int (+ {}))".format(cost_name, cost))
            costs[name] = cost_name
            self.query_string_list.append("")

        return costs

    def add_cost(self):
        self.query_string_list.append("; total cost for expression")

        cost_name = "total_cost"
        costs = " ".join([v for v in self.operation_costs.values()])
        self.query_string_list.append("(define-fun {} () Int (+ {}))".format(cost_name,
                                                                         costs))
        self.query_string_list.append("")
        return cost_name

