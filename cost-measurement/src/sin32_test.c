

#include "asserts.h"
#include "sin.h"
#include "xmalloc.h"

#include <float.h>
#include <math.h>
#include <mpfr.h>
#include <stdio.h>
#include <string.h>


const fp32 LOW = 0.0f;
const fp32 HIGH = 0.78539816339744830961f;


typedef fp32(*sintype)(fp32);

#define FUNC_COUNT (25)

sintype FUNCTIONS[FUNC_COUNT] = {zero_sin_fp32,
                                 one_sin_fp32,
                                 m_one_sin_fp32,
                                 taylor_1_sin_fp32,
                                 taylor_3_sin_fp32,
                                 ord_01_sin_fp32,
                                 ord_02_sin_fp32,
                                 ord_03_sin_fp32,
                                 ord_04_sin_fp32,
                                 ord_05_sin_fp32,
                                 ord_06_sin_fp32,
                                 ord_07_sin_fp32,
                                 ord_08_sin_fp32,
                                 ord_09_sin_fp32,
                                 ord_10_sin_fp32,
                                 ord_11_sin_fp32,
                                 ord_12_sin_fp32,
                                 ord_13_sin_fp32,
                                 ord_14_sin_fp32,
                                 ord_15_sin_fp32,
                                 ord_16_sin_fp32,
                                 ord_17_sin_fp32,
                                 ord_18_sin_fp32,
                                 ord_19_sin_fp32,
                                 sin_fp32};

char* NAMES[FUNC_COUNT] = {"zero_sin_fp32    ",
                           "one_sin _fp32    ",
                           "m_one_sin_fp32   ",
                           "taylor_1_sin_fp32",
                           "taylor_3_sin_fp32",
                           "ord_01_sin_fp32  ",
                           "ord_02_sin_fp32  ",
                           "ord_03_sin_fp32  ",
                           "ord_04_sin_fp32  ",
                           "ord_05_sin_fp32  ",
                           "ord_06_sin_fp32  ",
                           "ord_07_sin_fp32  ",
                           "ord_08_sin_fp32  ",
                           "ord_09_sin_fp32  ",
                           "ord_10_sin_fp32  ",
                           "ord_11_sin_fp32  ",
                           "ord_12_sin_fp32  ",
                           "ord_13_sin_fp32  ",
                           "ord_14_sin_fp32  ",
                           "ord_15_sin_fp32  ",
                           "ord_16_sin_fp32  ",
                           "ord_17_sin_fp32  ",
                           "ord_18_sin_fp32  ",
                           "ord_19_sin_fp32  ",
                           "sin_fp32         "};

fp32 WORST_ABS_DIFFS[FUNC_COUNT] = {0.0};
fp32 WORST_ABS_INPUTS[FUNC_COUNT] = {NAN};
fp32 WORST_ABS_OUTPUTS[FUNC_COUNT] = {NAN};

fp32 WORST_REL_DIFFS[FUNC_COUNT] = {0.0};
fp32 WORST_REL_INPUTS[FUNC_COUNT] = {NAN};
fp32 WORST_REL_OUTPUTS[FUNC_COUNT] = {NAN};

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


void test_sins_fp32(void)
{
  size_t values = 0;

  u_int32_t lower = fp32_to_u_int32_t(LOW);
  u_int32_t upper = fp32_to_u_int32_t(HIGH);
  printf("lower bound: %d (%1.10e)\n", lower, LOW);
  printf("upper bound: %d (%1.10e)\n", upper, HIGH);

  u_int32_t max_values = upper - lower;
  printf("total points to run: %u\n\n", max_values);

  mpfr_t mx, my;
  mpfr_inits2(24, mx, my, (mpfr_ptr) 0);
  for (u_int32_t hex=lower; hex<=upper; hex++) {
    fp32 input = u_int32_t_to_fp32(hex);
    mpfr_set_flt(mx, input, MPFR_RNDN);
    mpfr_sin(my, mx, MPFR_RNDN);
    fp32 correct = mpfr_get_flt(my, MPFR_RNDN);
    for (size_t i=0; i<FUNC_COUNT; i++) {
      fp32 actual = FUNCTIONS[i](input);
      fp32 absdiff = fabsf(correct - actual);
      fp32 reldiff = absdiff / fabsf(correct);
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
        printf("%s\t%1.10e\t%1.10e\t%1.10e\t%1.10e\t%1.10e\t%1.10e\n", NAMES[i],
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
    printf("%s\t%1.10e\t%1.10e\t%1.10e\t%1.10e\t%1.10e\t%1.10e\n", NAMES[i],
           WORST_ABS_DIFFS[i], WORST_ABS_INPUTS[i], WORST_ABS_OUTPUTS[i],
           WORST_REL_DIFFS[i], WORST_REL_INPUTS[i], WORST_REL_OUTPUTS[i]);
  }
  printf("\n\n\n\n");
}


int main(int argc, char** argv)
{
  UNUSED(argc);
  UNUSED(argv);
  test_sins_fp32();
  return 0;
}
