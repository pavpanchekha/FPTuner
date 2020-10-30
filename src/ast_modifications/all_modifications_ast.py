

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
    ("exp", "ord_01_exp_fp64", "rnd[64,ne,268605542767869.34,-53,-37](exp", 10462, [-0.1,0.7931471805599453]),
    ("exp", "ord_02_exp_fp64", "rnd[64,ne,15535285942523.35,-53,-37](exp", 11805, [-0.1,0.7931471805599453]),
    ("exp", "ord_03_exp_fp64", "rnd[64,ne,673571306338.82,-53,-37](exp", 13151, [-0.1,0.7931471805599453]),
    ("exp", "ord_04_exp_fp64", "rnd[64,ne,23359006590.86,-53,-37](exp", 13553, [-0.1,0.7931471805599453]),
    ("exp", "ord_05_exp_fp64", "rnd[64,ne,674967751.71,-53,-37](exp", 15097, [-0.1,0.7931471805599453]),
    ("exp", "ord_06_exp_fp64", "rnd[64,ne,16715563.46,-53,-37](exp", 19093, [-0.1,0.7931471805599453]),
    ("exp", "ord_07_exp_fp64", "rnd[64,ne,362189.50,-53,-37](exp", 22906, [-0.1,0.7931471805599453]),
    ("exp", "ord_08_exp_fp64", "rnd[64,ne,6977.00,-53,-37](exp", 27299, [-0.1,0.7931471805599453]),
    ("exp", "ord_09_exp_fp64", "rnd[64,ne,121.50,-53,-37](exp", 32380, [-0.1,0.7931471805599453]),
    ("exp", "ord_10_exp_fp64", "rnd[64,ne,3.00,-53,-37](exp", 38006, [-0.1,0.7931471805599453]),
    ("exp", "ord_11_exp_fp64", "rnd[64,ne,0.53,-53,-37](exp", 43985, [-0.1,0.7931471805599453]),
    ("exp", "ord_12_exp_fp64", "rnd[64,ne,0.50,-53,-37](exp", 48891, [-0.1,0.7931471805599453]),
    ("exp", "ord_13_exp_fp64", "rnd[64,ne,1.00,-52,-38](exp", 55242, [-0.1,0.7931471805599453]),
    ("exp", "rord_01_exp_fp64", "rnd[64,ne,537211085535738.69,-52,-38](exp", 11459, [-inf,709]),
    ("exp", "rord_02_exp_fp64", "rnd[64,ne,31070571885046.70,-52,-38](exp", 12908, [-inf,709]),
    ("exp", "rord_03_exp_fp64", "rnd[64,ne,1347142612677.63,-52,-38](exp", 12960, [-inf,709]),
    ("exp", "rord_04_exp_fp64", "rnd[64,ne,46718013181.71,-52,-38](exp", 14469, [-inf,709]),
    ("exp", "rord_05_exp_fp64", "rnd[64,ne,1349935503.42,-52,-38](exp", 15943, [-inf,709]),
    ("exp", "rord_06_exp_fp64", "rnd[64,ne,33431126.92,-52,-38](exp", 19178, [-inf,709]),
    ("exp", "rord_07_exp_fp64", "rnd[64,ne,724379.00,-52,-38](exp", 24417, [-inf,709]),
    ("exp", "rord_08_exp_fp64", "rnd[64,ne,13954.00,-52,-38](exp", 27797, [-inf,709]),
    ("exp", "rord_09_exp_fp64", "rnd[64,ne,243.00,-52,-38](exp", 34092, [-inf,709]),
    ("exp", "rord_10_exp_fp64", "rnd[64,ne,6.00,-52,-38](exp", 38560, [-inf,709]),
    ("exp", "rord_11_exp_fp64", "rnd[64,ne,1.06,-52,-38](exp", 44709, [-inf,709]),
    ("exp", "rord_12_exp_fp64", "rnd[64,ne,2.00,-51,-39](exp", 50468, [-inf,709]),
    ("exp", "rord_13_exp_fp64", "rnd[64,ne,4.00,-50,-40](exp", 56820, [-inf,709]),
    ("exp", "exp", "exp", 56901, [-inf, 709]),
    ("log", "ord_01_log_fp64", "rnd[64,ne,1560225159379928.50,-53,-38](log", 11366, [0.65,1.6]),
    ("log", "ord_02_log_fp64", "rnd[64,ne,180939096786966.81,-53,-38](log", 11356, [0.65,1.6]),
    ("log", "ord_03_log_fp64", "rnd[64,ne,23395545541212.62,-53,-38](log", 11483, [0.65,1.6]),
    ("log", "ord_04_log_fp64", "rnd[64,ne,3221421663262.33,-53,-38](log", 12851, [0.65,1.6]),
    ("log", "ord_05_log_fp64", "rnd[64,ne,461631423991.96,-53,-38](log", 14325, [0.65,1.6]),
    ("log", "ord_06_log_fp64", "rnd[64,ne,68003414721.27,-53,-38](log", 17240, [0.65,1.6]),
    ("log", "ord_07_log_fp64", "rnd[64,ne,10222486410.48,-53,-38](log", 20890, [0.65,1.6]),
    ("log", "ord_08_log_fp64", "rnd[64,ne,1560654991.88,-53,-38](log", 25132, [0.65,1.6]),
    ("log", "ord_09_log_fp64", "rnd[64,ne,241195374.53,-53,-38](log", 31049, [0.65,1.6]),
    ("log", "ord_10_log_fp64", "rnd[64,ne,37647263.34,-53,-38](log", 36393, [0.65,1.6]),
    ("log", "ord_11_log_fp64", "rnd[64,ne,5924532.27,-53,-38](log", 42476, [0.65,1.6]),
    ("log", "ord_12_log_fp64", "rnd[64,ne,938780.22,-53,-38](log", 48382, [0.65,1.6]),
    ("log", "ord_13_log_fp64", "rnd[64,ne,149631.40,-53,-38](log", 53806, [0.65,1.6]),
    ("log", "ord_14_log_fp64", "rnd[64,ne,23971.13,-53,-38](log", 60123, [0.65,1.6]),
    ("log", "ord_15_log_fp64", "rnd[64,ne,3857.70,-53,-38](log", 69465, [0.65,1.6]),
    ("log", "ord_16_log_fp64", "rnd[64,ne,623.75,-53,-38](log", 74712, [0.65,1.6]),
    ("log", "ord_17_log_fp64", "rnd[64,ne,101.73,-53,-38](log", 82979, [0.65,1.6]),
    ("log", "ord_18_log_fp64", "rnd[64,ne,17.13,-53,-38](log", 92074, [0.65,1.6]),
    ("log", "ord_19_log_fp64", "rnd[64,ne,3.42,-53,-38](log", 95147, [0.65,1.6]),
    ("log", "ord_20_log_fp64", "rnd[64,ne,1.18,-53,-38](log", 104583, [0.65,1.6]),
    ("log", "ord_21_log_fp64", "rnd[64,ne,0.81,-53,-38](log", 163122, [0.65,1.6]),
    ("log", "rord_01_log_fp64", "rnd[64,ne,3120450318759857.00,-52,-39](log", 35227, [0,inf]),
    ("log", "rord_02_log_fp64", "rnd[64,ne,361878193573933.62,-52,-39](log", 35261, [0,inf]),
    ("log", "rord_03_log_fp64", "rnd[64,ne,46791091082425.25,-52,-39](log", 38067, [0,inf]),
    ("log", "rord_04_log_fp64", "rnd[64,ne,6442843326524.67,-52,-39](log", 38083, [0,inf]),
    ("log", "rord_05_log_fp64", "rnd[64,ne,923262847983.91,-52,-39](log", 39975, [0,inf]),
    ("log", "rord_06_log_fp64", "rnd[64,ne,136006829442.54,-52,-39](log", 43587, [0,inf]),
    ("log", "rord_07_log_fp64", "rnd[64,ne,20444972820.97,-52,-39](log", 47045, [0,inf]),
    ("log", "rord_08_log_fp64", "rnd[64,ne,3121309983.75,-52,-39](log", 53003, [0,inf]),
    ("log", "rord_09_log_fp64", "rnd[64,ne,482390749.05,-52,-39](log", 59232, [0,inf]),
    ("log", "rord_10_log_fp64", "rnd[64,ne,75294526.68,-52,-39](log", 67685, [0,inf]),
    ("log", "rord_11_log_fp64", "rnd[64,ne,11849064.53,-52,-39](log", 73794, [0,inf]),
    ("log", "rord_12_log_fp64", "rnd[64,ne,1877560.45,-52,-39](log", 79624, [0,inf]),
    ("log", "rord_13_log_fp64", "rnd[64,ne,299262.79,-52,-39](log", 86745, [0,inf]),
    ("log", "rord_14_log_fp64", "rnd[64,ne,47942.26,-52,-39](log", 93845, [0,inf]),
    ("log", "rord_15_log_fp64", "rnd[64,ne,7715.40,-52,-39](log", 99256, [0,inf]),
    ("log", "rord_16_log_fp64", "rnd[64,ne,1247.50,-52,-39](log", 108638, [0,inf]),
    ("log", "rord_17_log_fp64", "rnd[64,ne,203.46,-52,-39](log", 114724, [0,inf]),
    ("log", "rord_18_log_fp64", "rnd[64,ne,34.26,-52,-39](log", 121685, [0,inf]),
    ("log", "rord_19_log_fp64", "rnd[64,ne,6.84,-52,-39](log", 128550, [0,inf]),
    ("log", "rord_20_log_fp64", "rnd[64,ne,2.37,-52,-39](log", 135428, [0,inf]),
    ("log", "rord_21_log_fp64", "rnd[64,ne,1.63,-52,-39](log", 167378, [0,inf]),
    ("log", "log", "log", 62772, [0, inf]),
    ("sin", "ord_01_sin_fp64", "rnd[64,ne,1999876923632337.25,-53,-55](sin", 10075, [-0.1,1.6707963267948966]),
    ("sin", "ord_03_sin_fp64", "rnd[64,ne,64962362127833.27,-53,-55](sin", 11512, [-0.1,1.6707963267948966]),
    ("sin", "ord_05_sin_fp64", "rnd[64,ne,974387504040.37,-53,-55](sin", 13080, [-0.1,1.6707963267948966]),
    ("sin", "ord_07_sin_fp64", "rnd[64,ne,8458670513.24,-53,-55](sin", 13079, [-0.1,1.6707963267948966]),
    ("sin", "ord_09_sin_fp64", "rnd[64,ne,47864191.00,-53,-55](sin", 14499, [-0.1,1.6707963267948966]),
    ("sin", "ord_11_sin_fp64", "rnd[64,ne,190511.46,-53,-55](sin", 18509, [-0.1,1.6707963267948966]),
    ("sin", "ord_13_sin_fp64", "rnd[64,ne,562.44,-53,-55](sin", 21944, [-0.1,1.6707963267948966]),
    ("sin", "ord_15_sin_fp64", "rnd[64,ne,1.30,-53,-54](sin", 26454, [-0.1,1.6707963267948966]),
    ("sin", "ord_17_sin_fp64", "rnd[64,ne,0.00,-53,-49](sin", 31511, [-0.1,1.6707963267948966]),
    ("sin", "ord_19_sin_fp64", "rnd[64,ne,0.01,-52,-50](sin", 35848, [-0.1,1.6707963267948966]),
    ("sin", "rord_01_sin_fp64", "rnd[64,ne,3999753847264674.50,-52,-56](sin", 14272, [-inf,inf]),
    ("sin", "rord_03_sin_fp64", "rnd[64,ne,129924724255666.55,-52,-56](sin", 14274, [-inf,inf]),
    ("sin", "rord_05_sin_fp64", "rnd[64,ne,1948775008080.73,-52,-56](sin", 14309, [-inf,inf]),
    ("sin", "rord_07_sin_fp64", "rnd[64,ne,16917341026.47,-52,-56](sin", 15745, [-inf,inf]),
    ("sin", "rord_09_sin_fp64", "rnd[64,ne,95728382.00,-52,-56](sin", 17177, [-inf,inf]),
    ("sin", "rord_11_sin_fp64", "rnd[64,ne,381022.92,-52,-56](sin", 18216, [-inf,inf]),
    ("sin", "rord_13_sin_fp64", "rnd[64,ne,1124.89,-52,-56](sin", 24230, [-inf,inf]),
    ("sin", "rord_15_sin_fp64", "rnd[64,ne,2.60,-52,-55](sin", 26607, [-inf,inf]),
    ("sin", "rord_17_sin_fp64", "rnd[64,ne,0.01,-51,-51](sin", 31790, [-inf,inf]),
    ("sin", "rord_19_sin_fp64", "rnd[64,ne,0.02,-50,-52](sin", 36732, [-inf,inf]),
    ("sin", "sin", "sin", 88006, [-inf, inf]),
    ("tan", "ord_01_tan_fp64", "rnd[64,ne,1082650101439728.25,-53,-56](tan", 10000, [-0.1,0.8853981633974483]),
    ("tan", "ord_03_tan_fp64", "rnd[64,ne,77210775406829.00,-53,-56](tan", 11354, [-0.1,0.8853981633974483]),
    ("tan", "ord_05_tan_fp64", "rnd[64,ne,5538634035107.86,-53,-56](tan", 12824, [-0.1,0.8853981633974483]),
    ("tan", "ord_07_tan_fp64", "rnd[64,ne,397622473307.75,-53,-56](tan", 12881, [-0.1,0.8853981633974483]),
    ("tan", "ord_09_tan_fp64", "rnd[64,ne,28547937179.54,-53,-56](tan", 14322, [-0.1,0.8853981633974483]),
    ("tan", "ord_11_tan_fp64", "rnd[64,ne,2049636459.78,-53,-56](tan", 18482, [-0.1,0.8853981633974483]),
    ("tan", "ord_13_tan_fp64", "rnd[64,ne,147157866.39,-53,-56](tan", 21664, [-0.1,0.8853981633974483]),
    ("tan", "ord_15_tan_fp64", "rnd[64,ne,10565478.79,-53,-56](tan", 26187, [-0.1,0.8853981633974483]),
    ("tan", "ord_17_tan_fp64", "rnd[64,ne,758562.78,-53,-56](tan", 31004, [-0.1,0.8853981633974483]),
    ("tan", "ord_19_tan_fp64", "rnd[64,ne,54462.50,-53,-56](tan", 35497, [-0.1,0.8853981633974483]),
    ("tan", "ord_21_tan_fp64", "rnd[64,ne,3910.23,-53,-55](tan", 41134, [-0.1,0.8853981633974483]),
    ("tan", "ord_23_tan_fp64", "rnd[64,ne,281.00,-53,-55](tan", 46747, [-0.1,0.8853981633974483]),
    ("tan", "ord_25_tan_fp64", "rnd[64,ne,20.16,-53,-55](tan", 52426, [-0.1,0.8853981633974483]),
    ("tan", "ord_27_tan_fp64", "rnd[64,ne,1.47,-53,-55](tan", 58535, [-0.1,0.8853981633974483]),
    ("tan", "ord_29_tan_fp64", "rnd[64,ne,0.11,-53,-53](tan", 66404, [-0.1,0.8853981633974483]),
    ("tan", "ord_33_tan_fp64", "rnd[64,ne,0.00,-53,-48](tan", 81198, [-0.1,0.8853981633974483]),
    ("tan", "ord_35_tan_fp64", "rnd[64,ne,0.00,-52,-49](tan", 89777, [-0.1,0.8853981633974483]),
    ("tan", "ord_31_tan_fp64", "rnd[64,ne,0.01,-53,-51](tan", 74463, [-0.1,0.8853981633974483]),
    ("tan", "ord_37_tan_fp64", "rnd[64,ne,0.00,-51,-50](tan", 95380, [-0.1,0.8853981633974483]),
    ("tan", "rord_01_tan_fp64", "rnd[64,ne,2165300202879456.50,-52,-57](tan", 31224, [-inf,inf]),
    ("tan", "rord_03_tan_fp64", "rnd[64,ne,154421550813658.00,-52,-57](tan", 32378, [-inf,inf]),
    ("tan", "rord_05_tan_fp64", "rnd[64,ne,11077268070215.73,-52,-57](tan", 35508, [-inf,inf]),
    ("tan", "rord_07_tan_fp64", "rnd[64,ne,795244946615.51,-52,-57](tan", 41162, [-inf,inf]),
    ("tan", "rord_09_tan_fp64", "rnd[64,ne,57095874359.08,-52,-57](tan", 49613, [-inf,inf]),
    ("tan", "rord_11_tan_fp64", "rnd[64,ne,4099272919.56,-52,-57](tan", 58066, [-inf,inf]),
    ("tan", "rord_13_tan_fp64", "rnd[64,ne,294315732.78,-52,-57](tan", 63512, [-inf,inf]),
    ("tan", "rord_15_tan_fp64", "rnd[64,ne,21130957.59,-52,-57](tan", 65362, [-inf,inf]),
    ("tan", "rord_17_tan_fp64", "rnd[64,ne,1517125.55,-52,-57](tan", 69522, [-inf,inf]),
    ("tan", "rord_19_tan_fp64", "rnd[64,ne,108925.00,-52,-57](tan", 74583, [-inf,inf]),
    ("tan", "rord_21_tan_fp64", "rnd[64,ne,7820.46,-52,-56](tan", 80889, [-inf,inf]),
    ("tan", "rord_23_tan_fp64", "rnd[64,ne,562.00,-52,-56](tan", 88186, [-inf,inf]),
    ("tan", "rord_25_tan_fp64", "rnd[64,ne,40.33,-52,-56](tan", 92181, [-inf,inf]),
    ("tan", "rord_27_tan_fp64", "rnd[64,ne,2.93,-52,-56](tan", 101388, [-inf,inf]),
    ("tan", "rord_29_tan_fp64", "rnd[64,ne,0.23,-52,-54](tan", 110556, [-inf,inf]),
    ("tan", "rord_33_tan_fp64", "rnd[64,ne,0.00,-50,-51](tan", 123996, [-inf,inf]),
    ("tan", "rord_35_tan_fp64", "rnd[64,ne,0.01,-49,-52](tan", 131049, [-inf,inf]),
    ("tan", "rord_31_tan_fp64", "rnd[64,ne,0.02,-52,-52](tan", 114830, [-inf,inf]),
    ("tan", "rord_37_tan_fp64", "rnd[64,ne,0.01,-48,-53](tan", 138651, [-inf,inf]),
    ("tan", "tan", "tan", 147363, [-inf, inf]),

    # ("exp", "ord_01_exp_fp64", "rnd[64,ne,67503984194187.00,-53,-1022](exp",  10, [0,0.69314718055994531]),
    # ("exp", "ord_02_exp_fp64", "rnd[64,ne,1950130268376.00,-53,-1022](exp",   115, [0,0.69314718055994531]),
    # ("exp", "ord_03_exp_fp64", "rnd[64,ne,42250199109.00,-53,-1022](exp",     138, [0,0.69314718055994531]),
    # ("exp", "ord_04_exp_fp64", "rnd[64,ne,732256204.00,-53,-1022](exp",       140, [0,0.69314718055994531]),
    # ("exp", "ord_05_exp_fp64", "rnd[64,ne,10575501.00,-53,-1022](exp",        155, [0,0.69314718055994531]),
    # ("exp", "ord_06_exp_fp64", "rnd[64,ne,130913.00,-53,-1022](exp",          205, [0,0.69314718055994531]),
    # ("exp", "ord_07_exp_fp64", "rnd[64,ne,1420.00,-53,-1022](exp",            248, [0,0.69314718055994531]),
    # ("exp", "ord_08_exp_fp64", "rnd[64,ne,16.00,-53,-1022](exp",              311, [0,0.69314718055994531]),
    # ("exp", "ord_09_exp_fp64", "rnd[64,ne,2.00,-53,-1022](exp",               365, [0,0.69314718055994531]),

    # ("exp", "rord_01_exp_fp64", "rnd[64,ne,67503984194188.00,-53,-1022](exp", 113, [-inf, 709]),
    # ("exp", "rord_02_exp_fp64", "rnd[64,ne,1950130268377.00,-53,-1022](exp",  125, [-inf, 709]),
    # ("exp", "rord_03_exp_fp64", "rnd[64,ne,42250199110.00,-53,-1022](exp",    139, [-inf, 709]),
    # ("exp", "rord_04_exp_fp64", "rnd[64,ne,732256205.00,-53,-1022](exp",      152, [-inf, 709]),
    # ("exp", "rord_05_exp_fp64", "rnd[64,ne,10575502.00,-53,-1022](exp",       186, [-inf, 709]),
    # ("exp", "rord_06_exp_fp64", "rnd[64,ne,130914.00,-53,-1022](exp",         237, [-inf, 709]),
    # ("exp", "rord_07_exp_fp64", "rnd[64,ne,1421.00,-53,-1022](exp",           275, [-inf, 709]),
    # ("exp", "rord_08_exp_fp64", "rnd[64,ne,17.00,-53,-1022](exp",             312, [-inf, 709]),
    # ("exp", "rord_09_exp_fp64", "rnd[64,ne,2.10,-53,-1022](exp",              381, [-inf, 709]),

    # ("exp", "exp",             "exp",                                         600, [-inf, 709]),


    # ("log", "log",          "log",                                       13, [-inf, inf]),


    # ("sin", "zero_sin",     "zero_sin",                                  0,  [-inf, inf]),
    # ("sin", "one_sin",      "one_sin",                                   0,  [-inf, inf]),
    # ("sin", "m_one_sin",    "m_one_sin",                                 0,  [-inf, inf]),
    # ("sin", "taylor_1_sin", "taylor_1_sin",                              1,  [-inf, inf]),
    # ("sin", "taylor_3_sin", "taylor_3_sin",                              2,  [-inf, inf]),
    # ("sin", "sin",          "sin",                                       13, [-inf, inf]),


    # ("tan", "tan",          "tan",                                       13, [-inf, inf]),
]

Implementations = [row[1] for row in OperationTable]
ImplToDomain = dict([(row[1], row[4]) for row in OperationTable])
OperationToFPTaylor = dict([(row[1],row[2]) for row in OperationTable])
FPTaylorToOperation = dict([(row[2],row[1]) for row in OperationTable])
OperationToCost = dict([(row[1],row[3]) for row in OperationTable])
for row in OperationTable:
    FPCoreLexer.UNARY_OPERATIONS.add(row[1])
    if row[1] == row[2]:
        FPTaylorLexer.UNARY_OPERATIONS.add(row[2])
