#!/usr/bin/env python3

import os.path as path
import sys

PYTHON_DIR = path.abspath(path.dirname(__file__))
GIT_DIR = path.split(PYTHON_DIR)[0]
sys.path.append(path.join(GIT_DIR, "src"))
sys.path.append(path.join(GIT_DIR, "src", "fptaylor"))
sys.path.append(path.join(GIT_DIR, "src", "fpcore_parser", "src"))

import check_requirements

from datetime import date
from fpcore_logging import Logger
from exceptions import DomainError, UnsupportedError, NoPreError, BadPreError, GelpiaInfError
from fpcore_ast import Number
from fpcore_lexer import FPCoreLexer
from fpcore_parser import FPCoreParser
from z3_result import Z3Result
from tuned_expression import TunedExpression
from fptaylor_result import FPTaylorResult
from gelpia_result import GelpiaResult

import math
import json
import shlex
import subprocess
import tempfile
import mpmath

from pprint import pprint


SOLLYA_PREC = 2**14
SOLLYA_BOUND = 2**(-100)

mpmath.mp.prec = SOLLYA_PREC

GelpiaResult.CONFIG["epsilons"] = (1e-300, 1e-300, 1e-300)
GelpiaResult.CONFIG["timeout"] = 60

MANT = {'fp32': 24,
        'fp64': 53}

SUBNORMAL = {'fp32': mpmath.mpf("1/{}".format(2**126)),
             'fp64': mpmath.mpf("1/{}".format(2**1022))}

EPSILON = {'fp32': mpmath.mpf("1/{}".format(2**24)),
           'fp64': mpmath.mpf("1/{}".format(2**53))}

PREC = {'fp32': 32,
        'fp64': 64}

SOLLYA_TYPE = {'fp32': 'single',
               'fp64': 'double'}

LN2_fp32 = mpmath.nstr(mpmath.log(2), 11)
LN2_fp64 = mpmath.nstr(mpmath.log(2), 19)

HPI_fp32 = mpmath.nstr(mpmath.pi/2, 11)
HPI_fp64 = mpmath.nstr(mpmath.pi/2, 19)

QPI_fp32 = mpmath.nstr(mpmath.pi/4, 11)
QPI_fp64 = mpmath.nstr(mpmath.pi/4, 19)


def replace_ints(d):
    for k in d:
        if type(d[k]) == int:
            d[k] = float(d[k])
        elif type(d[k]) == dict:
            replace_ints(d[k])


def run_sollya(func, I, NI, SI, monomials, fptype):
    stype = SOLLYA_TYPE[fptype]
    monomials_str = ", ".join([str(m) for m in monomials])
    lines = ['prec = {}!;'.format(SOLLYA_PREC),
             'algo_analysis_bound = {};'.format(SOLLYA_BOUND),
             'I = [{};{}];'.format(*I),
             'NI = [{};{}];'.format(*NI),
             'SI = [{};{}];'.format(*SI),
             'f = {};'.format(func),
             'monomials = [|{}|];'.format(monomials_str),
             'p = fpminimax(f, monomials, [|{}...|], I, floating, relative);'.format(stype),
             'rel_err = sup(supnorm(p, f, NI, relative, algo_analysis_bound));',
             'abs_err = sup(supnorm(p, f, SI, absolute, algo_analysis_bound));',
             'print("{");',
             'print("  \\"function\\" : \\"{}\\",");'.format(func),
             'print("  \\"type\\" : \\"{}\\",");'.format(fptype),
             'print("  \\"input\\" : {\\"inf\\" : "@inf(I)@",  \\"sup\\" : "@sup(I)@"},");',
             'print("  \\"order\\" : {},");'.format(monomials[-1]),
             'print("  \\"polynomial\\" : {");',
             'display = hexadecimal!;',
             'print("    \\"hexadecimal\\" : \\""@horner(p)@"\\",");',
             'display = decimal!;',
             'print("    \\"decimal\\" : \\""@horner(p)@"\\",");',
             'print("    \\"coefficients\\" : [\\""@{}@"\\"],");'.format('@"\\", \\""@'.join(['coeff(p,{})'.format(m) for m in monomials])),
             'print("    \\"monomials\\" : [{}]");'.format(', '.join([str(m) for m in monomials])),
             'print("  },");',
             'print("  \\"relative_error\\" : {");',
             'print("  \\"input\\" : {\\"inf\\" : "@inf(NI)@",  \\"sup\\" : "@sup(NI)@"},");',
             'print("    \\"algorithmic\\" : {");',
             'print("      \\"sollya\\" : \\""@rel_err@"\\"");',
             'print("    }");',
             'print("  },");',
             'print("  \\"absolute_error\\" : {");',
             'print("  \\"input\\" : {\\"inf\\" : "@inf(SI)@",  \\"sup\\" : "@sup(SI)@"},");',
             'print("    \\"algorithmic\\" : {");',
             'print("      \\"sollya\\" : \\""@abs_err@"\\"");',
             'print("    }");',
             'print("  }");',
             'print("}");']

    script = "\n".join(lines)

    with tempfile.NamedTemporaryFile("w") as f:
        f.write(script)
        f.flush()

        command = "sollya --warnonstderr {}".format(f.name)

        with subprocess.Popen(shlex.split(command),
                              stdout=subprocess.PIPE,
                              stderr=subprocess.PIPE) as p:
            raw_out, raw_err = p.communicate()
            out = raw_out.decode("utf8")
            err = raw_err.decode("utf8")
            retcode = p.returncode

    f = json.loads(out)

    f["polynomial"]["hexadecimal"] = f["polynomial"]["hexadecimal"].replace("x^0x1p1", "(x*x)")
    f["polynomial"]["decimal"] = f["polynomial"]["decimal"].replace("x^2", "(x*x)")

    try:
        flt = float(f["relative_error"]["algorithmic"]["sollya"])
        int(flt)
    except ValueError:
        flt = None
    f["relative_error"]["algorithmic"]["sollya"] = flt

    try:
        flt = float(f["absolute_error"]["algorithmic"]["sollya"])
        int(flt)
    except ValueError:
        flt = None
    f["absolute_error"]["algorithmic"]["sollya"] = flt

    rel_err, abs_err = gelpia_errors(f["polynomial"]["decimal"],
                                     func,
                                     NI,
                                     SI)
    f["relative_error"]["algorithmic"]["gelpia"] = rel_err
    f["absolute_error"]["algorithmic"]["gelpia"] = abs_err

    f["relative_error"]["rounding"] = dict()
    f["absolute_error"]["rounding"] = dict()

    rel_err, abs_err = fptaylor_errors(f["polynomial"]["decimal"], NI, SI, fptype)
    f["relative_error"]["rounding"]["fptaylor"] = rel_err
    f["absolute_error"]["rounding"]["fptaylor"] = abs_err

    rel_err, abs_err = oliver_errors(f["polynomial"]["coefficients"], monomials, func, NI, SI, fptype)
    f["relative_error"]["rounding"]["oliver"] = rel_err
    f["absolute_error"]["rounding"]["oliver"] = abs_err

    replace_ints(f)

    return f


def cname(func):
    fname = func["function"]
    fname = fname[0:fname.index("(")]
    return "ord_{:02}_{}_{}".format(int(func["order"]), fname, func["type"])

def gelpia_errors(poly, func, NI, SI):
    rel_query = "x = [{}, {}]; (({})-({}))/({})".format(*NI, poly, func, func)
    abs_query = "x = [{}, {}]; (({})-({}))".format(*SI, poly, func)

    try:
        gr = GelpiaResult(None, None, raw_query=rel_query)
        rel_err =  gr.abs_max
    except GelpiaInfError:
        rel_err = None

    try:
        gr = GelpiaResult(None, None, raw_query=abs_query)
        abs_err =  gr.abs_max
    except GelpiaInfError:
        abs_err = None

    return rel_err, abs_err

def oliver_errors(coeffs, monomials, func, NI, SI, fptype):
    parts = list()
    for j in range(len(coeffs)):
        sub_parts = list()
        for i in range(j, len(coeffs)):
            power = monomials[i]
            p = coeffs[i]
            sub_parts.append("{}*(x^{})".format(p, power))
        sub_sum = " + ".join(sub_parts)
        parts.append("abs({})".format(sub_sum))
    parts[0] = "({})/2".format(parts[0])
    parts[-1] = "({})/2".format(parts[-1])
    parts_sum = " + ".join(parts)

    rel_query = "x = [{}, {}]; ({}) / {}".format(*NI, parts_sum, func)
    abs_query = "x = [{}, {}]; {}".format(*SI, parts_sum)

    try:
        gr = GelpiaResult(None, None, raw_query=rel_query)
        rel_sum =  gr.abs_max
        rel_err = float(mpmath.mpf(2) * EPSILON[fptype] * mpmath.mpf(rel_sum))
    except GelpiaInfError:
        rel_err = None

    try:
        gr = GelpiaResult(None, None, raw_query=abs_query)
        abs_sum =  gr.abs_max
        abs_err = float(mpmath.mpf(2) * EPSILON[fptype] * mpmath.mpf(abs_sum))
    except GelpiaInfError:
        abs_err = None

    return rel_err, abs_err

def fptaylor_errors(poly, NI, SI, fptype):
    config = {"--fp-power2-model": "true",
              "--opt": "gelpia",
              "--opt-exact": "true",
              "--opt-f-rel-tol": "1e-300",
              "--opt-f-abs-tol": "1e-300",
              "--opt-x-rel-tol": "1e-300",
              "--opt-x-abs-tol": "1e-300",
              "--opt-max-iters": "4294967290",
              "--opt-timeout": "10"}

    rel_query_lines = ["Variables",
                       "real x in [{},{}];".format(*NI),
                       "Definitions",
                       "ret rnd{}= {};".format(PREC[fptype], poly),
                       "Expressions",
                       "ret;"]

    abs_query_lines = ["Variables",
                       "real x in [{},{}];".format(*SI),
                       "Definitions",
                       "ret rnd{}= {};".format(PREC[fptype], poly),
                       "Expressions",
                       "ret;"]

    rel_query = "\n".join(rel_query_lines)
    abs_query = "\n".join(abs_query_lines)

    rel_fpt_res = FPTaylorResult(rel_query, {**config, **{"--rel-error": "true"}})
    abs_fpt_res = FPTaylorResult(abs_query, {**config, **{"--abs-error": "true"}})

    try:
        rel_err = rel_fpt_res.rel_error
    except:
        rel_err = None

    try:
        abs_err = abs_fpt_res.abs_error
    except:
        abs_err = None

    return abs_err, rel_err


def read_all_json(filename):
    with open(filename, 'r') as f:
        raw = f.read()
    raw_funcs = raw.split("}\n{")
    if len(raw_funcs) > 1:
        raw_funcs = [raw_funcs[0]+"}"] + ["{"+rf+"}" for rf in raw_funcs[1:-1]] + ["{"+raw_funcs[-1]]
    funcs = [json.loads(rf) for rf in raw_funcs]
    for func in funcs:
        replace_ints(func)
    return funcs

def print_tsv(funcs):
    funcs.sort(key=lambda f:f["type"])
    funcs.sort(key=lambda f:f["order"])
    print("\t".join(["func",
                     "order",
                     "type",
                     "rel_input", "rel_algo_gelpia", "rel_algo_sollya", "rel_rnd_fptaylor", "rel_rnd_oliver",
                     "abs_input", "abs_algo_gelpia", "abs_algo_sollya", "abs_rnd_fptaylor", "abs_rnd_oliver",
    ]))
    for f in funcs:
        row = [f["function"],
               f["order"],
               f["type"],
               "[{}, {}]".format(f["relative_error"]["input"]["inf"], f["relative_error"]["input"]["sup"]),
               f["relative_error"]["algorithmic"]["gelpia"],
               f["relative_error"]["algorithmic"]["sollya"],
               f["relative_error"]["rounding"]["fptaylor"],
               f["relative_error"]["rounding"]["oliver"],
               "[{}, {}]".format(f["absolute_error"]["input"]["inf"], f["absolute_error"]["input"]["sup"]),
               f["absolute_error"]["algorithmic"]["gelpia"],
               f["absolute_error"]["algorithmic"]["sollya"],
               f["absolute_error"]["rounding"]["fptaylor"],
               f["absolute_error"]["rounding"]["oliver"],
        ]
        row = [str(r) for r in row]
        print("\t".join(row))

def min_skpi_none(l):
    l = [i for i in l if i is not None]
    return min(l)

def fptaylor_round_args(func):
    min_rel_algo = min_skpi_none(func["relative_error"]["algorithmic"].values())
    min_rel_rnd = min_skpi_none(func["relative_error"]["rounding"].values())
    min_abs_algo = min_skpi_none(func["absolute_error"]["algorithmic"].values())
    min_abs_rnd = min_skpi_none(func["absolute_error"]["rounding"].values())

    tot_rel_err = min_rel_algo + min_rel_rnd
    tot_abs_err = min_abs_algo + min_abs_rnd

    bits = PREC[func["type"]]
    typ = "ne"
    eps = -MANT[func["type"]]

    scale = tot_rel_err * mpmath.power(2, abs(eps))
    delta = mpmath.floor(mpmath.log(tot_abs_err / scale))

    return [bits, typ, float(scale), eps, int(delta)]
