#!/usr/bin/env python3

from generation_utils import *

from generate_cos import *
from generate_exp import *
from generate_log import *
from generate_sin import *
from generate_tan import *


ROUNDINGS = set()

def rounding(args, src_op):
    return "rnd[{},{},{:.2f},{},{}]({}".format(*(args + [src_op]))

def try_rounding(args, src_op):
    fpt_op = rounding(args, src_op)
    return fpt_op in ROUNDINGS

def fix_rounding(args, src_op):
    new_args = list(args)
    while try_rounding(new_args, src_op):
        new_args[3] += 1
        new_args[4] -= 1
        new_args[2] *= 2
    new_rounding = rounding(new_args, src_op)
    ROUNDINGS.add(new_rounding)
    return new_rounding

def read_costs(fname):
    with open(fname, 'r') as f:
        raw = f.read()
    raw_errors = raw.split("}\n{")
    if len(raw_errors) > 1:
        raw_errors = [raw_errors[0]+"}"] + ["{"+rf+"}" for rf in raw_errors[1:-1]] + ["{"+raw_errors[-1]]
    errors = [json.loads(rf) for rf in raw_errors]

    secs_per_call = dict()
    for e in errors:
        secs = e["secs"]
        for f in e["functions_data"]:
            counts = f["counts"]
            avg_counts = sum(counts) / len(counts)
            avg_secs_per_call = secs / avg_counts
            secs_per_call[f["name"]] = avg_secs_per_call

    mintime = min(secs_per_call.values())

    costs = {k:v/mintime for k,v in secs_per_call.items()}

    scale = 1
    intcosts = {k:int(scale*v) for k,v in costs.items()}
    while True:
        intcosts = {k:int(scale*v) for k,v in costs.items()}
        unique_costs = set(intcosts.values())
        if len(unique_costs) == len(costs):
            break
        scale *= 10

    return intcosts


def do_ops(funcs, costs, shift_input=None):
    if shift_input is None:
        shift_input = 0.0
    squashed = dict()
    for i,f in enumerate(funcs):
        src_op = strip_paren(f["function"])
        operation = cname(f)
        if "reduced" in f:
            operation = "r" + operation
        args = fptaylor_round_args(f)
        input_lower = float(f["input"]["inf"]) + shift_input
        input_upper = float(f["input"]["sup"]) + shift_input
        cost = costs[operation]
        key = (src_op, "reduced" in f, *args)
        if "reduced" in f:
            operation = operation + "_" + str(int(f["reduced"]))
        if key in squashed:
            entry = squashed[key]
            assert(entry[0] == src_op)
            assert(entry[3] == cost)
            if input_lower < entry[4]:
                assert(entry[5] < input_upper)
                entry[1] = operation
                entry[4] = input_lower
                entry[5] = input_upper
                continue

        fpt_op = fix_rounding(args, src_op)

        squashed[key] = [src_op,
                         operation,
                         fpt_op,
                         cost,
                         input_lower,
                         input_upper]
    id_num = 0
    for entry in squashed.values():
        entry[4] = str(entry[4])
        entry[5] = str(entry[5])
        print('("{}", "{}", "{}", {}, [{},{}]),'.format(*entry))
        id_num += 1

def do_rops(funcs, costs, input_lower, input_upper):
    done_no_reduction = False
    reduction_count = 0
    for f in funcs:
        src_op = strip_paren(f["function"])
        operation = "r" + cname(f)
        args = fptaylor_round_args(f)
        fpt_op = fix_rounding(args, src_op)
        cost = costs[operation]
        print('("{}", "{}", "{}", {}, [{},{}]),'.format(src_op,
                                                        operation,
                                                        fpt_op,
                                                        cost,
                                                        input_lower,
                                                        input_upper))

def strip_paren(string):
    return string[0:string.index("(")]


if __name__ == "__main__":
    funcs = read_all_json(sys.argv[1])
    costs = read_costs(sys.argv[2])

    # coss = [f for f in funcs if f["function"] == "cos(x-pi/2)"]
    # do_ops(coss, costs)
    # do_rops(coss, costs, "-inf", "inf")
    # print('("cos", "cos", "cos", {}, [-inf, inf]),'.format(costs["cos_fp64"]))

    exps = [f for f in funcs if f["function"] == "exp(x)"]
    do_ops(exps, costs)
    #do_rops(exps, costs, "-inf", "709")
    print('("exp", "exp", "exp", {}, [-inf, 709]),'.format(costs["exp_fp64"]))

    logs = [f for f in funcs if f["function"] == "log(1+x)"]
    do_ops(logs, costs, 1.0)
    #do_rops(logs, costs, "0", "inf")
    print('("log", "log", "log", {}, [0, inf]),'.format(costs["log_fp64"]))

    sins = [f for f in funcs if f["function"] == "sin(x)"]
    do_ops(sins, costs)
    #do_rops(sins, costs, "-inf", "inf")
    print('("sin", "sin", "sin", {}, [-inf, inf]),'.format(costs["sin_fp64"]))

    tans = [f for f in funcs if f["function"] == "tan(x)"]
    do_ops(tans, costs)
    #do_rops(tans, costs, "-inf", "inf")
    print('("tan", "tan", "tan", {}, [-inf, inf]),'.format(costs["tan_fp64"]))
