

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
    # srcOp operation       FPTaylorOperation                            Cost InputRange
    ("exp", "exp",          "exp",                                       13, [-inf, inf]),

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
