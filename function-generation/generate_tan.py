#!/usr/bin/env python3

import sys
import mpmath

from generation_utils import *


def gen_tan(order, fptype):
    inf = "0.0"
    sup = str(mpmath.pi/4)
    subn = SUBNORMAL[fptype]
    I_subn = "1.1703344634137277e-08" #str(mpmath.atan(subn))
    I = [inf, sup]
    NI = [I_subn, sup]
    SI = [inf, I_subn]
    monomials = range(1, order+1, 2)

    d = run_sollya('tan(x)', I, NI, SI, monomials, fptype)

    return d

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

        #print_tsv(tans)
