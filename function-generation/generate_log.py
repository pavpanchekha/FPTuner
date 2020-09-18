#!/usr/bin/env python3

import sys
import mpmath

from generation_utils import *


def gen_log(order, fptype):
    inf = "-0.25"
    sup = "0.5"
    subn = SUBNORMAL[fptype]
    I_subn = str(mpmath.exp(subn-1))
    I = [inf, sup]
    NI = [I_subn, sup]
    SI = [inf, I_subn]
    monomials = range(1, order+1)

    d = run_sollya('log(1+x)', I, NI, SI, monomials, fptype)

    return d

def convert_log_to_c(func):
    lines = ["{} {}({} xin) {{".format(func["type"], cname(func), func["type"]),
             "  {} x = xin - 1.0;".format(func["type"]),
             "  return {};".format(func["polynomial"]["hexadecimal"]),
             "}"]
    return "\n".join(lines)

def create_range_reduced_log(func):
    lines = ["{type} r{cname}({type} x) {{",
             "  int n;",
             "  {type} f = frexp(x, &n);",
             "  {type} log_f = {cname}(f);",
             "  {type} recons = n*LN2_{type} + log_f;",
             "  return recons;",
             "}}"]
    unformatted = "\n".join(lines)
    return unformatted.format(**{**func, **{"cname": cname(func)}})


if __name__ == "__main__":
    try:
        order = int(sys.argv[1])
        d = gen_log(order, "fp64")
        print(json.dumps(d, sort_keys=True, indent=4))
    except ValueError:
        funcs = read_all_json(sys.argv[1])
        logs = [f for f in funcs if f["function"] == "log(1+x)"]

        for f in logs:
            coeffs = f["polynomial"]["coefficients"]
            monomials = f["polynomial"]["monomials"]
            func = f["function"]
            NI = f["relative_error"]["input"]["inf"], f["relative_error"]["input"]["sup"]
            SI = f["absolute_error"]["input"]["inf"], f["absolute_error"]["input"]["sup"]
            fptype = f["type"]

            rel_err, abs_err = oliver_errors(coeffs, monomials, func, NI, SI, fptype)
            f["relative_error"]["rounding"]["oliver"] = rel_err
            f["absolute_error"]["rounding"]["oliver"] = abs_err

            print(json.dumps(f, sort_keys=True, indent=4))
