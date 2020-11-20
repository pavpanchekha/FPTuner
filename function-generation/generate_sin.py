#!/usr/bin/env python3

import sys
import time
import mpmath

from generation_utils import *


def gen_sin(order, fptype):
    inf = "-0.1"
    sup = mpmath.nstr(mpmath.pi/2 + 0.1, 19)
    subn = SUBNORMAL[fptype]
    I_subn = "2.1491193328908223e-08"
    I = [inf, sup]
    NI = [I_subn, sup]
    SI = [inf, I_subn]
    monomials = range(1, order+1, 2)

    d = run_sollya('sin(x)', I, NI, SI, monomials, fptype)

    return d

def gen_reduced_sin(f, multiples):
    period = mpmath.pi/2
    inf = "-0.1"
    sup = mpmath.nstr(period + 0.1, 19)
    I_subn = "2.1491193328908223e-08" #mpmath.nstr(mpmath.asin(subn))
    I = [inf, sup]
    NI = [I_subn, sup]
    SI = [inf, I_subn]
    config = FPTAYLOR_CONFIG

    reduced_sins = dict()
    for m in range(1, multiples+1, multiples-1):
        start = time.time()
        if m%4 == 1 or m%4 == 3:
            lower_sup = mpmath.nstr(-(m-1)*period - mpmath.mpf(I_subn), 19)
            lower_inf = mpmath.nstr(-m*period, 19)
        if m%4 == 2 or m%4 == 0:
            lower_sup = mpmath.nstr(-(m-1)*period, 19)
            lower_inf = mpmath.nstr(-m*period + mpmath.mpf(I_subn), 19)

        if m%4 == 1 or m%4 == 3:
            upper_sup = mpmath.nstr((m+1)*period - mpmath.mpf(I_subn), 19)
            upper_inf = mpmath.nstr(m*period, 19)
        if m%4 == 2 or m%4 == 0:
            upper_sup = mpmath.nstr((m+1)*period, 19)
            upper_inf = mpmath.nstr(m*period + mpmath.mpf(I_subn), 19)

        query_lines = ["Variables",
                       "real x in [{}, {}];",
                       "Definitions",
                       "ret rnd64= x - {}*{};",
                       "Expressions",
                       "ret;"]
        raw_query = "\n".join(query_lines)

        lower_query = raw_query.format(lower_inf, lower_sup, -m, mpmath.nstr(period, 19))
        upper_query = raw_query.format(upper_inf, upper_sup, m, mpmath.nstr(period, 19))

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
              "function" : "sin(x)",
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
        reduced_sins[m] = rf
    return reduced_sins

def convert_sin_to_c(func):
    lines = ["{} {}({} x) {{".format(func["type"], cname(func), func["type"]),
             "  return {};".format(func["polynomial"]["hexadecimal"]),
             "}"]
    return "\n".join(lines)

def create_range_reduced_sin(func):
    lines = ["{type} r{cname}({type} x) {{",
             "  if (x < HPI_{type}) {{",
             "    return {cname}(x);",
             "  }}",
             "  int k = (int) (x / HPI_{type});",
             "  {type} whole = (({type}) k) * HPI_{type};",
             "  {type} y = x - whole;",
             "  int part = k % 4;",
             "  {type} z;",
             "  switch (part) {{",
             "    case 0:",
             "    case 2:",
             "      z = y;",
             "      break;",
             "    case 1:",
             "    case 3:",
             "      z = HPI_{type} - y;",
             "      break;",
             "    default:",
             "      exit(3);",
             "  }}",
             "  {type} result = {cname}(z);",
             "  if (part == 2 || part == 3) {{",
             "    result *= ({type}) -1.0;"
             "  }}",
             "  return result;",
             "}}"]
    unformatted = "\n".join(lines)
    return unformatted.format(**{**func, **{"cname": cname(func)}})

if __name__ == "__main__":
    try:
        order = int(sys.argv[1])
        d = gen_sin(order, "fp64")
        print(json.dumps(d, sort_keys=True, indent=4))
    except ValueError:
        funcs = read_all_json(sys.argv[1])
        sins = [f for f in funcs if f["function"] == "sin(x)"]

        for f in sins:
            print(json.dumps(f, sort_keys=True, indent=4))

            reduced = gen_reduced_sin(f, 40)
            for r in reduced.values():
                print(json.dumps(r, sort_keys=True, indent=4), flush=True)

