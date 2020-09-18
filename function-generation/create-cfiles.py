#!/usr/bin/env python3

from generation_utils import *

from generate_exp import *
from generate_log import *
from generate_sin import *
from generate_tan import *



def write_include(funcs, inc_name):
    decls = ["{} {}({} x)".format(f["type"], cname(f), f["type"]) for f in funcs]

    def_name = inc_name.upper().replace('.', '_')

    lines = ['#ifndef {}'.format(def_name),
             '#define {}'.format(def_name),
             '#include "types.h"',
             *["{};".format(d) for d in decls],
             *["{};".format(d.replace(" ord", " rord")) for d in decls],
             '#endif']

    text = "\n".join(lines)

    with open(inc_name, 'w') as f:
        f.write(text)

def write_exp_source(exps, inc_name):
    cdefs = ['#include "{}"'.format(inc_name),
             '#include <math.h>',
             'static const fp32 LN2_fp32 = {}f;'.format(LN2_fp32),
             'static const fp64 LN2_fp64 = {};'.format(LN2_fp64),
             *[convert_exp_to_c(f) for f in exps],
             *[create_range_reduced_exp(f) for f in exps]]

    text = "\n".join(cdefs)

    with open(inc_name.replace(".h", ".c"), 'w') as f:
        f.write(text)

def write_log_source(logs, inc_name):
    cdefs = ['#include "{}"'.format(inc_name),
             '#include <math.h>',
             'static const fp32 LN2_fp32 = {}f;'.format(LN2_fp32),
             'static const fp64 LN2_fp64 = {};'.format(LN2_fp64),
             *[convert_log_to_c(f) for f in logs],
             *[create_range_reduced_log(f) for f in logs]]

    text = "\n".join(cdefs)

    with open(inc_name.replace(".h", ".c"), 'w') as f:
        f.write(text)

def write_sin_source(sins, inc_name):
    cdefs = ['#include "{}"'.format(inc_name),
             '#include <math.h>',
             '#include <stdlib.h>',
             'static const fp32 HPI_fp32 = {}f;'.format(HPI_fp32),
             'static const fp64 HPI_fp64 = {};'.format(HPI_fp64),
             *[convert_sin_to_c(f) for f in sins],
             *[create_range_reduced_sin(f) for f in sins]]

    text = "\n".join(cdefs)

    with open(inc_name.replace(".h", ".c"), 'w') as f:
        f.write(text)

def write_tan_source(tans, inc_name):
    cdefs = ['#include "{}"'.format(inc_name),
             '#include <math.h>',
             '#include <stdlib.h>',
             'static const fp32 QPI_fp32 = {}f;'.format(QPI_fp32),
             'static const fp64 QPI_fp64 = {};'.format(QPI_fp64),
             *[convert_tan_to_c(f) for f in tans],
             *[create_range_reduced_tan(f) for f in tans]]

    text = "\n".join(cdefs)

    with open(inc_name.replace(".h", ".c"), 'w') as f:
        f.write(text)


if __name__ == "__main__":
    funcs = read_all_json(sys.argv[1])

    exps = [f for f in funcs if f["function"] == "exp(x)"]
    inc_name = "ord_exp.h"
    write_include(exps, inc_name)
    write_exp_source(exps, inc_name)

    logs = [f for f in funcs if f["function"] == "log(1+x)"]
    inc_name = "ord_log.h"
    write_include(logs, inc_name)
    write_log_source(logs, inc_name)

    sins = [f for f in funcs if f["function"] == "sin(x)"]
    inc_name = "ord_sin.h"
    write_include(sins, inc_name)
    write_sin_source(sins, inc_name)

    tans = [f for f in funcs if f["function"] == "tan(x)"]
    inc_name = "ord_tan.h"
    write_include(tans, inc_name)
    write_tan_source(tans, inc_name)
