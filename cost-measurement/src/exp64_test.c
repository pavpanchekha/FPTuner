

#include "asserts.h"
#include "exp.h"
#include "xmalloc.h"

#include <float.h>
#include <math.h>
#include <mpfr.h>
#include <stdio.h>
#include <string.h>


const fp64 LOW = 0.0;
const fp64 HIGH = 0.34657359027997265470;



typedef fp64(*exptype)(fp64);

#define FUNC_COUNT (20)

exptype FUNCTIONS[FUNC_COUNT] = {ord_01_exp_fp64,
                                 ord_02_exp_fp64,
                                 ord_03_exp_fp64,
                                 ord_04_exp_fp64,
                                 ord_05_exp_fp64,
                                 ord_06_exp_fp64,
                                 ord_07_exp_fp64,
                                 ord_08_exp_fp64,
                                 ord_09_exp_fp64,
                                 ord_10_exp_fp64,
                                 ord_11_exp_fp64,
                                 ord_12_exp_fp64,
                                 ord_13_exp_fp64,
                                 ord_14_exp_fp64,
                                 ord_15_exp_fp64,
                                 ord_16_exp_fp64,
                                 ord_17_exp_fp64,
                                 ord_18_exp_fp64,
                                 ord_19_exp_fp64,
                                 exp_fp64};

char* NAMES[FUNC_COUNT] = {"ord_01_exp_fp64  ",
                           "ord_02_exp_fp64  ",
                           "ord_03_exp_fp64  ",
                           "ord_04_exp_fp64  ",
                           "ord_05_exp_fp64  ",
                           "ord_06_exp_fp64  ",
                           "ord_07_exp_fp64  ",
                           "ord_08_exp_fp64  ",
                           "ord_09_exp_fp64  ",
                           "ord_10_exp_fp64  ",
                           "ord_11_exp_fp64  ",
                           "ord_12_exp_fp64  ",
                           "ord_13_exp_fp64  ",
                           "ord_14_exp_fp64  ",
                           "ord_15_exp_fp64  ",
                           "ord_16_exp_fp64  ",
                           "ord_17_exp_fp64  ",
                           "ord_18_exp_fp64  ",
                           "ord_19_exp_fp64  ",
                           "exp_fp64         "};

fp64 WORST_ABS_DIFFS[FUNC_COUNT] = {0.0};
fp64 WORST_ABS_INPUTS[FUNC_COUNT] = {NAN};
fp64 WORST_ABS_OUTPUTS[FUNC_COUNT] = {NAN};

fp64 WORST_REL_DIFFS[FUNC_COUNT] = {0.0};
fp64 WORST_REL_INPUTS[FUNC_COUNT] = {NAN};
fp64 WORST_REL_OUTPUTS[FUNC_COUNT] = {NAN};

u_int32_t fp32_to_u_int32_t(fp32 x) {
  u_int32_t y;
  memcpy(&y, &x, sizeof(fp32));
  return y;
}

fp32 u_int32_t_to_fp32(u_int32_t x) {
  fp32 y;
  memcpy(&y, &x, sizeof(fp32));
  return y;
}

u_int64_t fp64_to_u_int64_t(fp64 x) {
  u_int64_t y;
  memcpy(&y, &x, sizeof(fp64));
  return y;
}

fp64 u_int64_t_to_fp64(u_int64_t x) {
  fp64 y;
  memcpy(&y, &x, sizeof(fp64));
  return y;
}


void test_exps_fp64(void)
{
  size_t values = 0;

  u_int64_t lower = fp64_to_u_int64_t(LOW);
  u_int64_t upper = fp64_to_u_int64_t(HIGH);
  printf("lower bound: %lu (%1.10e)\n", lower, LOW);
  printf("upper bound: %lu (%1.10e)\n", upper, HIGH);

  u_int64_t max_values = upper - lower;
  printf("possible points to run: %lu\n\n", max_values);

  size_t randsize = 1 << 17;
  u_int64_t* rand_array = (u_int64_t*) xmalloc(sizeof(u_int64_t)*randsize);
  for (size_t i=0; i<randsize; i++) {
    rand_array[i] = (u_int64_t) rand();
  }

  mpfr_t mx, my;
  mpfr_inits2(53, mx, my, (mpfr_ptr) 0);
  for (u_int64_t hex=lower; hex<=upper; hex+=rand_array[values%randsize]) {
    fp64 input = (fp64)u_int64_t_to_fp64(hex);
    mpfr_set_d(mx, input, MPFR_RNDN);
    mpfr_exp(my, mx, MPFR_RNDN);
    fp64 correct = mpfr_get_d(my, MPFR_RNDN);
    for (size_t i=0; i<FUNC_COUNT; i++) {
      fp64 actual = FUNCTIONS[i](input);
      fp64 absdiff = fabs(correct - actual);
      fp64 reldiff = absdiff / fabs(correct);
      if (absdiff > WORST_ABS_DIFFS[i]) {
        WORST_ABS_DIFFS[i] = absdiff;
        WORST_ABS_INPUTS[i] = input;
        WORST_ABS_OUTPUTS[i] = correct;
      }
      if (reldiff > WORST_REL_DIFFS[i]) {
        WORST_REL_DIFFS[i] = reldiff;
        WORST_REL_INPUTS[i] = input;
        WORST_REL_OUTPUTS[i] = correct;
      }
    }
    values++;

    if ((values+1)%(1<<22) == 0) {
      printf("values: %zu\n", values);
      printf("\n");
      printf("op               \tworst_abs_difference \tworst_abs_input  \tcorrect_abs_output\tworst_rel_difference \tworst_rel_input  \tcorrect_rel_output\n");
      for (size_t i=0; i<FUNC_COUNT; i++) {
        printf("%s\t%1.18e\t%1.18e\t%1.18e\t%1.18e\t%1.18e\t%1.18e\n", NAMES[i],
               WORST_ABS_DIFFS[i], WORST_ABS_INPUTS[i], WORST_ABS_OUTPUTS[i],
               WORST_REL_DIFFS[i], WORST_REL_INPUTS[i], WORST_REL_OUTPUTS[i]);
      }
      printf("\n\n\n\n");
    }
  }
  mpfr_clears(mx, my, (mpfr_ptr) 0);

  printf("values: %zu\n", values);
  printf("\n");
  printf("op               \tworst_abs_difference \tworst_abs_input  \tcorrect_abs_output\tworst_rel_difference \tworst_rel_input  \tcorrect_rel_output\n");
  for (size_t i=0; i<FUNC_COUNT; i++) {
    printf("%s\t%1.18e\t%1.18e\t%1.18e\t%1.18e\t%1.18e\t%1.18e\n", NAMES[i],
           WORST_ABS_DIFFS[i], WORST_ABS_INPUTS[i], WORST_ABS_OUTPUTS[i],
           WORST_REL_DIFFS[i], WORST_REL_INPUTS[i], WORST_REL_OUTPUTS[i]);
  }
  printf("\n\n\n\n");
}


int main(int argc, char** argv)
{
  UNUSED(argc);
  UNUSED(argv);
  test_exps_fp64();
  return 0;
}
