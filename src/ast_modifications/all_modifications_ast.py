

from collections import OrderedDict
from fpcore_lexer import FPCoreLexer
from fptaylor_lexer import FPTaylorLexer

import can_have_fptaylor_form_ast
import equals_ast
import expand_ast
import fpcore_ast
import infix_str_ast
import to_single_assignment_ast

BitWidthCost = {
    # bit_width cost
    "fp32":     0,
    "fp64":    20,
}

OperationTable = [
    # srcOp operation       FPTaylorOperation                            Cost
    ("sin", "zero_sin",     "zero_sin",                                  0),
    ("sin", "one_sin",      "one_sin",                                   0),
    ("sin", "m_one_sin",    "m_one_sin",                                 0),
    ("sin", "taylor_1_sin", "taylor_1_sin",                              1),
    ("sin", "taylor_3_sin", "taylor_3_sin",                              2),
    ("sin", "mlm_40_sin",   "rnd[64,ne,1099511627776.50,-53,-1022](sin", 3),
    ("sin", "mlm_36_sin",   "rnd[64,ne,68719476736.50,-53,-1022](sin",   4),
    ("sin", "mlm_32_sin",   "rnd[64,ne,4294967296.50,-53,-1022](sin",    5),
    ("sin", "mlm_28_sin",   "rnd[64,ne,268435456.50,-53,-1022](sin",     6),
    ("sin", "mlm_24_sin",   "rnd[64,ne,16777216.50,-53,-1022](sin",      7),
    ("sin", "mlm_20_sin",   "rnd[64,ne,1048576.50,-53,-1022](sin",       8),
    ("sin", "mlm_16_sin",   "rnd[64,ne,65536.50,-53,-1022](sin",         9),
    ("sin", "mlm_12_sin",   "rnd[64,ne,4096.50,-53,-1022](sin",          10),
    ("sin", "mlm_8_sin",    "rnd[64,ne,256.50,-53,-1022](sin",           11),
    ("sin", "mlm_4_sin",    "rnd[64,ne,16.50,-53,-1022](sin",            12),
    ("sin", "sin",          "sin",                                       13),

    ("exp", "mlm_40_exp",   "rnd[64,ne,1099511627776.50,-53,-1022](exp", 3),
    ("exp", "mlm_36_exp",   "rnd[64,ne,68719476736.50,-53,-1022](exp",   4),
    ("exp", "mlm_32_exp",   "rnd[64,ne,4294967296.50,-53,-1022](exp",    5),
    ("exp", "mlm_28_exp",   "rnd[64,ne,268435456.50,-53,-1022](exp",     6),
    ("exp", "mlm_24_exp",   "rnd[64,ne,16777216.50,-53,-1022](exp",      7),
    ("exp", "mlm_20_exp",   "rnd[64,ne,1048576.50,-53,-1022](exp",       8),
    ("exp", "mlm_16_exp",   "rnd[64,ne,65536.50,-53,-1022](exp",         9),
    ("exp", "mlm_12_exp",   "rnd[64,ne,4096.50,-53,-1022](exp",          10),
    ("exp", "mlm_8_exp",    "rnd[64,ne,256.50,-53,-1022](exp",           11),
    ("exp", "mlm_4_exp",    "rnd[64,ne,16.50,-53,-1022](exp",            12),
    ("exp", "exp",          "exp",                                       13),

    ("log", "mlm_40_log",   "rnd[64,ne,1099511627776.50,-53,-1022](log", 3),
    ("log", "mlm_36_log",   "rnd[64,ne,68719476736.50,-53,-1022](log",   4),
    ("log", "mlm_32_log",   "rnd[64,ne,4294967296.50,-53,-1022](log",    5),
    ("log", "mlm_28_log",   "rnd[64,ne,268435456.50,-53,-1022](log",     6),
    ("log", "mlm_24_log",   "rnd[64,ne,16777216.50,-53,-1022](log",      7),
    ("log", "mlm_20_log",   "rnd[64,ne,1048576.50,-53,-1022](log",       8),
    ("log", "mlm_16_log",   "rnd[64,ne,65536.50,-53,-1022](log",         9),
    ("log", "mlm_12_log",   "rnd[64,ne,4096.50,-53,-1022](log",          10),
    ("log", "mlm_8_log",    "rnd[64,ne,256.50,-53,-1022](log",           11),
    ("log", "mlm_4_log",    "rnd[64,ne,16.50,-53,-1022](log",            12),
    ("log", "log",          "log",                                       13),
]

OperationToFPTaylor = dict([(row[1],row[2]) for row in OperationTable])
FPTaylorToOperation = dict([(row[2],row[1]) for row in OperationTable])
OperationToCost = dict([(row[1],row[3]) for row in OperationTable])
for row in OperationTable:
    FPCoreLexer.UNARY_OPERATIONS.add(row[1])
    if row[1] == row[2]:
        FPTaylorLexer.UNARY_OPERATIONS.add(row[2])
