#!/usr/bin/env python3

import sys
import time
import mpmath

from generation_utils import *


def gen_tan(order, fptype):
    inf = "-0.1"
    sup = str(mpmath.pi/4 + 0.1)
    subn = SUBNORMAL[fptype]
    I_subn = "1.1703344634137277e-08" #str(mpmath.atan(subn))
    I = [inf, sup]
    NI = [I_subn, sup]
    SI = [inf, I_subn]
    monomials = range(1, order+1, 2)

    d = run_sollya('tan(x)', I, NI, SI, monomials, fptype)

    return d

def gen_reduced_tan(f, multiples):
    period = mpmath.pi/4
    inf = "-0.1"
    sup = str(period + 0.1)
    I_subn = "1.1703344634137277e-08" #str(mpmath.atan(subn))
    I = [inf, sup]
    NI = [I_subn, sup]
    SI = [inf, I_subn]
    config = FPTAYLOR_CONFIG

    reduced_tans = dict()
    for m in range(1, multiples+1):
        start = time.time()
        lower_inf = str(-m*period)
        lower_sup = str(- (m-1)*period)
        upper_sup = str((m+1)*period)
        upper_inf = str(m*period)

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
              "function" : "tan(x)",
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
        reduced_tans[m] = rf
    return reduced_tans

def convert_tan_to_c(func):
    lines = ["{} {}({} x) {{".format(func["type"], cname(func), func["type"]),
             "  return {};".format(func["polynomial"]["hexadecimal"]),
             "}"]
    return "\n".join(lines)

def create_range_reduced_tan(func):
    lines = ["{type} r{cname}({type} x) {{",
             "  int sign = signbit(x);",
             "  {type} abs_x = fabs(x);",
             "  int k = (int) (abs_x / QPI_{type});",
             "  {type} whole = (({type}) k) * QPI_{type};",
             "  {type} y = abs_x - whole;",
             "  int part = k % 4;",
             "  {type} z;",
             "  switch (part) {{",
             "    case 0:",
             "      z = y;",
             "      break;",
             "    case 1:",
             "      z = QPI_{type} - y;",
             "      break;",
             "    case 2:",
             "      z = -y;",
             "      break;",
             "    case 3:",
             "      z = y - QPI_{type};",
             "      break;",
             "    default:",
             "      exit(3);",
             "  }}",
             "  {type} result = {cname}(z);",
             "  if (part == 1 || part == 2) {{",
             "    result = 1 / result;",
             "  }}",
             "  result *= sign ? -1.0 : 1.0;",
             "  return result;",
             "}}"]
    unformatted = "\n".join(lines)
    return unformatted.format(**{**func, **{"cname": cname(func)}})


if __name__ == "__main__":
    try:
        order = int(sys.argv[1])
        d = gen_tan(order, "fp64")
        print(json.dumps(d, sort_keys=True, indent=4))
    except ValueError:
        funcs = read_all_json(sys.argv[1])
        tans = [f for f in funcs if f["function"] == "tan(x)"]

        for f in tans:
            print(json.dumps(f, sort_keys=True, indent=4))

            reduced = gen_reduced_tan(f, 50)
            for r in reduced.values():
                print(json.dumps(r, sort_keys=True, indent=4))

