

import fpcore_ast

import ast_modifications.can_have_fptaylor_form_ast
import ast_modifications.equals_ast
import ast_modifications.expand_ast
import ast_modifications.infix_str_ast
import ast_modifications.to_single_assignment_ast

from collections import OrderedDict
from fpcore_lexer import FPCoreLexer
from fptaylor_lexer import FPTaylorLexer
from math import inf


BitWidthCost = {
    # bit_width cost
    "fp32":     0,
    "fp64":    20,
}

OperationTable = [
    # srcOp operation           FPTaylorOperation                         Cost InputRange
    ("exp", "ord_01_exp_fp64", "rnd[64,ne,67503984194187.00,-53,-1022](exp",  10, [0,0.69314718055994531]),
    ("exp", "ord_02_exp_fp64", "rnd[64,ne,1950130268376.00,-53,-1022](exp",   115, [0,0.69314718055994531]),
    ("exp", "ord_03_exp_fp64", "rnd[64,ne,42250199109.00,-53,-1022](exp",     138, [0,0.69314718055994531]),
    ("exp", "ord_04_exp_fp64", "rnd[64,ne,732256204.00,-53,-1022](exp",       140, [0,0.69314718055994531]),
    ("exp", "ord_05_exp_fp64", "rnd[64,ne,10575501.00,-53,-1022](exp",        155, [0,0.69314718055994531]),
    ("exp", "ord_06_exp_fp64", "rnd[64,ne,130913.00,-53,-1022](exp",          205, [0,0.69314718055994531]),
    ("exp", "ord_07_exp_fp64", "rnd[64,ne,1420.00,-53,-1022](exp",            248, [0,0.69314718055994531]),
    ("exp", "ord_08_exp_fp64", "rnd[64,ne,16.00,-53,-1022](exp",              311, [0,0.69314718055994531]),
    ("exp", "ord_09_exp_fp64", "rnd[64,ne,2.00,-53,-1022](exp",               365, [0,0.69314718055994531]),

    ("exp", "rord_01_exp_fp64", "rnd[64,ne,67503984194188.00,-53,-1022](exp", 113, [-inf, 709]),
    ("exp", "rord_02_exp_fp64", "rnd[64,ne,1950130268377.00,-53,-1022](exp",  125, [-inf, 709]),
    ("exp", "rord_03_exp_fp64", "rnd[64,ne,42250199110.00,-53,-1022](exp",    139, [-inf, 709]),
    ("exp", "rord_04_exp_fp64", "rnd[64,ne,732256205.00,-53,-1022](exp",      152, [-inf, 709]),
    ("exp", "rord_05_exp_fp64", "rnd[64,ne,10575502.00,-53,-1022](exp",       186, [-inf, 709]),
    ("exp", "rord_06_exp_fp64", "rnd[64,ne,130914.00,-53,-1022](exp",         237, [-inf, 709]),
    ("exp", "rord_07_exp_fp64", "rnd[64,ne,1421.00,-53,-1022](exp",           275, [-inf, 709]),
    ("exp", "rord_08_exp_fp64", "rnd[64,ne,17.00,-53,-1022](exp",             312, [-inf, 709]),
    ("exp", "rord_09_exp_fp64", "rnd[64,ne,2.10,-53,-1022](exp",              381, [-inf, 709]),

    ("exp", "exp",             "exp",                                         600, [-inf, 709]),


    ("log", "log",          "log",                                       13, [-inf, inf]),


    ("sin", "zero_sin",     "zero_sin",                                  0,  [-inf, inf]),
    ("sin", "one_sin",      "one_sin",                                   0,  [-inf, inf]),
    ("sin", "m_one_sin",    "m_one_sin",                                 0,  [-inf, inf]),
    ("sin", "taylor_1_sin", "taylor_1_sin",                              1,  [-inf, inf]),
    ("sin", "taylor_3_sin", "taylor_3_sin",                              2,  [-inf, inf]),
    ("sin", "sin",          "sin",                                       13, [-inf, inf]),


    ("tan", "tan",          "tan",                                       13, [-inf, inf]),
]

OperationToFPTaylor = dict([(row[1],row[2]) for row in OperationTable])
FPTaylorToOperation = dict([(row[2],row[1]) for row in OperationTable])
OperationToCost = dict([(row[1],row[3]) for row in OperationTable])
for row in OperationTable:
    FPCoreLexer.UNARY_OPERATIONS.add(row[1])
    if row[1] == row[2]:
        FPTaylorLexer.UNARY_OPERATIONS.add(row[2])
