#!/usr/bin/env python3

import sys
import time
import mpmath

from generation_utils import *


def gen_exp(order, fptype):
    inf = "-0.1"
    sup = str(mpmath.log(2) + 0.1)
    I = [inf, sup]
    NI = [inf, sup]
    SI = [inf, inf]
    monomials = range(0, order+1)

    d = run_sollya('exp(x)', I, NI, SI, monomials, fptype)

    return d

def gen_reduced_exp(f, multiples):
    period = mpmath.log(2)
    inf = "-0.1"
    sup = str(period + 0.1)
    I = [inf, sup]
    NI = [inf, sup]
    SI = [inf, inf]
    config = FPTAYLOR_CONFIG

    reduced_exps = dict()
    for m in range(1, multiples+1):
        start = time.time()
        lower_inf = str(mpmath.mpf(inf) - m*period)
        lower_sup = str(mpmath.mpf(inf) - (m-1)*period)
        upper_sup = str((m+1)*period + 0.1)
        upper_inf = str(m*period + 0.1)

        query_lines = ["Variables",
                       "real x in [{}, {}];",
                       "Definitions",
                       "ret rnd64= x - {}*{};",
                       "Expressions",
                       "ret;"]
        raw_query = "\n".join(query_lines)

        lower_query = raw_query.format(lower_inf, lower_sup, -m, period)
        upper_query = raw_query.format(upper_inf, upper_sup, m, period)

        lower_res = FPTaylorResult(lower_query, {**config, **{"--abs-error": "true"}})
        upper_res = FPTaylorResult(upper_query, {**config, **{"--abs-error": "true"}})

        assert(lower_res.abs_error is not None)
        assert(upper_res.abs_error is not None)

        reduction_error = max(lower_res.abs_error, upper_res.abs_error)

        abs_err, rel_err = fptaylor_errors(f["polynomial"]["decimal"], NI, SI, "fp64",
                                           reduction_error)
        assert(abs_err != None)
        assert(rel_err != None)
        elapsed = time.time() - start
        rf = {"reduced" : m,
              "generation_time" : elapsed,
              "absolute_error" : {"algorithmic" :
                                  {"gelpia": f["absolute_error"]["algorithmic"]["gelpia"],
                                   "sollya" : f["absolute_error"]["algorithmic"]["sollya"]},
                                  "input" : {"inf" : f["absolute_error"]["input"]["inf"],
                                             "sup" : f["absolute_error"]["input"]["sup"]},
                                  "rounding" :
                                  {"fptaylor" : abs_err}},
              "function" : "exp(x)",
              "input" : {"inf" : lower_inf,
                         "sup" : upper_sup},
              "order" : f["order"],
              "polynomial" : {"coefficients" : f["polynomial"]["coefficients"],
                              "decimal" : f["polynomial"]["decimal"],
                              "hexadecimal" : f["polynomial"]["hexadecimal"] ,
                              "monomials" : f["polynomial"]["monomials"]},
              "relative_error" : {"algorithmic" :
                                  {"gelpia": f["relative_error"]["algorithmic"]["gelpia"],
                                   "sollya" : f["relative_error"]["algorithmic"]["sollya"]},
                                  "input" : {"inf" : f["relative_error"]["input"]["inf"],
                                             "sup" : f["relative_error"]["input"]["sup"]},
                                  "rounding" :
                                  {"fptaylor" : rel_err}},
              "type" : "fp64"}
        reduced_exps[m] = rf
    return reduced_exps

def convert_exp_to_c(func):
    lines = ["{} {}({} x) {{".format(func["type"], cname(func), func["type"]),
             "  return {};".format(func["polynomial"]["hexadecimal"]),
             "}"]
    return "\n".join(lines)

def create_range_reduced_exp(func):
    lines = ["{type} r{cname}({type} x) {{",
             "  if (0.0 < x && x < LN2_{type}) {{",
             "    return {cname}(x);",
             "  }}",
             "  int N = floor(x / LN2_{type});",
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
            print(json.dumps(f, sort_keys=True, indent=4))

            reduced = gen_reduced_exp(f, 50)
            for r in reduced.values():
                print(json.dumps(r, sort_keys=True, indent=4))

