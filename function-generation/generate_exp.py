#!/usr/bin/env python3

import sys
import mpmath

from generation_utils import *


def gen_exp(order, fptype):
    inf = "0.0"
    sup = str(mpmath.log(2))
    I = [inf, sup]
    NI = [inf, sup]
    SI = [inf, inf]
    monomials = range(0, order+1)

    d = run_sollya('exp(x)', I, NI, SI, monomials, fptype)

    return d

def convert_exp_to_c(func):
    lines = ["{} {}({} x) {{".format(func["type"], cname(func), func["type"]),
             "  return {};".format(func["polynomial"]["hexadecimal"]),
             "}"]
    return "\n".join(lines)

def create_range_reduced_exp(func):
    lines = ["{type} r{cname}({type} x) {{",
             "  if (x < LN2_{type}) {{",
             "    return {cname}(x);",
             "  }}",
             "  int N = (int) (x / LN2_{type});",
             "  {type} whole = (({type}) N) * LN2_{type};",
             "  {type} t = x - whole;",
             "  {type} exp_t = {cname}(t);",
             "  {type} recons = ldexp(exp_t, N);",
             "  return recons;",
             "}}"]
    unformatted = "\n".join(lines)
    return unformatted.format(**{**func, **{"cname": cname(func)}})


if __name__ == "__main__":
    try:
        order = int(sys.argv[1])
        d = gen_exp(order, "fp64")
        print(json.dumps(d, sort_keys=True, indent=4))
    except ValueError:
        funcs = read_all_json(sys.argv[1])
        exps = [f for f in funcs if f["function"] == "exp(x)"]

        for f in exps:
            coeffs = f["polynomial"]["coefficients"]
            monomials = f["polynomial"]["monomials"]
            func = f["function"]
            NI = f["relative_error"]["input"]["inf"], f["relative_error"]["input"]["sup"]
            SI = f["absolute_error"]["input"]["inf"], f["absolute_error"]["input"]["sup"]
            fptype = f["type"]

            rel_err, abs_err = oliver_errors_1(coeffs, monomials, func, NI, SI, fptype)
            f["relative_error"]["rounding"]["oliver_1"] = rel_err
            f["absolute_error"]["rounding"]["oliver_1"] = rel_err

            rel_err, abs_err = oliver_errors_2(coeffs, monomials, func, NI, SI, fptype)
            f["relative_error"]["rounding"]["oliver_2"] = rel_err
            f["absolute_error"]["rounding"]["oliver_2"] = rel_err

            print(json.dumps(f, sort_keys=True, indent=4))

        #print_tsv(exps)
