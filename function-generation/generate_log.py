#!/usr/bin/env python3

import sys
import time
import mpmath

from generation_utils import *


def gen_log(order, fptype):
    inf = "-0.35"
    sup = "0.6"
    subn = SUBNORMAL[fptype]
    I_subn = str(mpmath.exp(subn-1))
    I = [inf, sup]
    NI = [I_subn, sup]
    SI = [inf, I_subn]
    monomials = range(1, order+1)

    d = run_sollya('log(1+x)', I, NI, SI, monomials, fptype)

    return d

def gen_reduced_log(f, multiples):
    inf = "-0.35"
    sup = "0.6"
    I = [inf, sup]
    NI = [inf, sup]
    SI = [inf, inf]
    config = FPTAYLOR_CONFIG

    reduced_logs = dict()
    for m in range(1, multiples+1):
        start = time.time()
        upper_sup = str(2**(m+1))
        upper_inf = str(2**(m))

        query_lines = ["Variables",
                       "real x in [{}, {}];",
                       "real fx in [-0.4307829160924542, 0.47000362924573563];",
                       "Definitions",
                       "ret rnd64= {}*{} + fx;",
                       "Expressions",
                       "ret;"]
        raw_query = "\n".join(query_lines)

        upper_query = raw_query.format(upper_inf, upper_sup, m, str(mpmath.log(2)))

        upper_res = FPTaylorResult(upper_query, {**config, **{"--abs-error": "true"}})

        assert(upper_res.abs_error is not None)

        reduction_error = upper_res.abs_error

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
              "function" : "log(1+x)",
              "input" : {"inf" : 0.0,
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
        reduced_logs[m] = rf
    return reduced_logs

def convert_log_to_c(func):
    lines = ["{} {}({} xin) {{".format(func["type"], cname(func), func["type"]),
             "  {} x = xin - 1.0;".format(func["type"]),
             "  return {};".format(func["polynomial"]["hexadecimal"]),
             "}"]
    return "\n".join(lines)

def create_range_reduced_log(func):
    lines = ["{type} r{cname}({type} x) {{",
             "  if (0.75 < x && x < 1.5) {",
             "    return {cname}(x);",
             "  }",
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
        sys.exit(0)
    except ValueError:
        funcs = read_all_json(sys.argv[1])
        logs = [f for f in funcs if f["function"] == "log(1+x)"]

        for f in logs:
            print(json.dumps(f, sort_keys=True, indent=4))

            reduced = gen_reduced_log(f, 11)
            for r in reduced.values():
                print(json.dumps(r, sort_keys=True, indent=4))

