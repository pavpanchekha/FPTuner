

#include "exp.h"
#include "timing.h"
#include "xmalloc.h"

#include <float.h>
#include <math.h>
#include <stdio.h>


const fp32 LOW = 0.0f;
const fp32 HIGH = 88.0f;

#define FUNC_COUNT (14)

unop_fp32 FUNCTIONS[FUNC_COUNT] = {rord_01_exp_fp32,
                                   rord_02_exp_fp32,
                                   rord_03_exp_fp32,
                                   rord_04_exp_fp32,
                                   rord_05_exp_fp32,
                                   rord_06_exp_fp32,
                                   rord_07_exp_fp32,
                                   rord_08_exp_fp32,
                                   rord_09_exp_fp32,
                                   rord_10_exp_fp32,
                                   rord_11_exp_fp32,
                                   rord_12_exp_fp32,
                                   rord_13_exp_fp32,
                                   exp_fp32};

char* NAMES[FUNC_COUNT] = {"rord_01_exp_fp32",
                           "rord_02_exp_fp32",
                           "rord_03_exp_fp32",
                           "rord_04_exp_fp32",
                           "rord_05_exp_fp32",
                           "rord_06_exp_fp32",
                           "rord_07_exp_fp32",
                           "rord_08_exp_fp32",
                           "rord_09_exp_fp32",
                           "rord_10_exp_fp32",
                           "rord_11_exp_fp32",
                           "rord_12_exp_fp32",
                           "rord_13_exp_fp32",
                           "exp_32          "};




int main(int argc, char** argv)
{
  size_t log2_values = 18;
  size_t secs = 10;
  size_t runs = 10;

  if (argc > 1) {
    log2_values = strtoul(argv[1], NULL, 10);
  }
  if (argc > 2) {
    secs = strtoul(argv[2], NULL, 10);
  }
  if (argc > 3) {
    runs = strtoul(argv[3], NULL, 10);
  }

  register_performance_handler();

  time_unop_fp32(LOW, HIGH,
                 FUNCTIONS, NAMES, FUNC_COUNT,
                 log2_values, runs, secs);


  return 0;
}
