

#include "exp.h"
#include "timing.h"
#include "xmalloc.h"

#include <float.h>
#include <math.h>
#include <stdio.h>


const fp64 LOW = 0.0f;
const fp64 HIGH = 709.0f;

#define FUNC_COUNT (14)

unop_fp64 FUNCTIONS[FUNC_COUNT] = {rord_01_exp_fp64,
                                   rord_02_exp_fp64,
                                   rord_03_exp_fp64,
                                   rord_04_exp_fp64,
                                   rord_05_exp_fp64,
                                   rord_06_exp_fp64,
                                   rord_07_exp_fp64,
                                   rord_08_exp_fp64,
                                   rord_09_exp_fp64,
                                   rord_10_exp_fp64,
                                   rord_11_exp_fp64,
                                   rord_12_exp_fp64,
                                   rord_13_exp_fp64,
                                   exp_fp64};

char* NAMES[FUNC_COUNT] = {"rord_01_exp_fp64",
                           "rord_02_exp_fp64",
                           "rord_03_exp_fp64",
                           "rord_04_exp_fp64",
                           "rord_05_exp_fp64",
                           "rord_06_exp_fp64",
                           "rord_07_exp_fp64",
                           "rord_08_exp_fp64",
                           "rord_09_exp_fp64",
                           "rord_10_exp_fp64",
                           "rord_11_exp_fp64",
                           "rord_12_exp_fp64",
                           "rord_13_exp_fp64",
                           "exp_64          "};




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

  time_unop_fp64(LOW, HIGH,
                 FUNCTIONS, NAMES, FUNC_COUNT,
                 log2_values, runs, secs);


  return 0;
}
