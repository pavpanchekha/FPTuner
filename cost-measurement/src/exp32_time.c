

#include "exp.h"
#include "multitimer.h"
#include "xmalloc.h"

#include <float.h>
#include <math.h>
#include <stdio.h>


const fp32 LOW = 0.0f;
const fp32 HIGH = 0.34657359027997265470f;


#define time_func(f)                            \
  for (volatile size_t j=0; j<iters; j++) {     \
    for (volatile size_t i=0; i<values; i+=4) { \
      (void)f(A[i]);                            \
      (void)f(A[i+1]);                          \
      (void)f(A[i+2]);                          \
      (void)f(A[i+3]);                          \
    }                                           \
  }                                             \
  start_multitimer(my_timer);                   \
  for (volatile size_t j=0; j<iters; j++) {     \
    for (volatile size_t i=0; i<values; i+=4) { \
      (void)f(A[i]);                            \
      (void)f(A[i+1]);                          \
      (void)f(A[i+2]);                          \
      (void)f(A[i+3]);                          \
    }                                           \
  }                                             \
  stop_multitimer(my_timer);


typedef fp32(*exptype)(fp32);

#define FUNC_COUNT (20)

exptype FUNCTIONS[FUNC_COUNT] = {ord_01_exp_fp32,
                                 ord_02_exp_fp32,
                                 ord_03_exp_fp32,
                                 ord_04_exp_fp32,
                                 ord_05_exp_fp32,
                                 ord_06_exp_fp32,
                                 ord_07_exp_fp32,
                                 ord_08_exp_fp32,
                                 ord_09_exp_fp32,
                                 ord_10_exp_fp32,
                                 ord_11_exp_fp32,
                                 ord_12_exp_fp32,
                                 ord_13_exp_fp32,
                                 ord_14_exp_fp32,
                                 ord_15_exp_fp32,
                                 ord_16_exp_fp32,
                                 ord_17_exp_fp32,
                                 ord_18_exp_fp32,
                                 ord_19_exp_fp32,
                                 exp_fp32};

char* NAMES[FUNC_COUNT] = {"ord_01_exp_fp32  ",
                           "ord_02_exp_fp32  ",
                           "ord_03_exp_fp32  ",
                           "ord_04_exp_fp32  ",
                           "ord_05_exp_fp32  ",
                           "ord_06_exp_fp32  ",
                           "ord_07_exp_fp32  ",
                           "ord_08_exp_fp32  ",
                           "ord_09_exp_fp32  ",
                           "ord_10_exp_fp32  ",
                           "ord_11_exp_fp32  ",
                           "ord_12_exp_fp32  ",
                           "ord_13_exp_fp32  ",
                           "ord_14_exp_fp32  ",
                           "ord_15_exp_fp32  ",
                           "ord_16_exp_fp32  ",
                           "ord_17_exp_fp32  ",
                           "ord_18_exp_fp32  ",
                           "ord_19_exp_fp32  ",
                           "exp_32           "};


fp32 rand_fp32(void)
{
  const fp32 scale = (LOW-HIGH) / ((fp32) RAND_MAX);
  fp32 rnd = (fp32) rand();
  return LOW + rnd * scale;
}


void time_exps32(size_t log2_values, size_t log2_invocations, size_t runs)
{
  size_t values = ((size_t) 1) << log2_values;
  size_t invocations = ((size_t) 1) << log2_invocations;
  size_t log2_iters = log2_invocations - log2_values;
  size_t iters = ((size_t) 1) << log2_iters;

  fp64** runs_data = (fp64**) xmalloc(sizeof(fp64*)*runs);
  for (size_t i=0; i<runs; i++) {
    runs_data[i] = (fp64*) xmalloc(sizeof(fp64)*(FUNC_COUNT+1));
  }

  fp32* A = (fp32*) xmalloc(sizeof(fp32)*values);

  for(size_t run=0; run<runs; run++) {
    multitimer* my_timer = create_multitimer();

    for (size_t i=0; i<values; i++) {
      A[i] = rand_fp32();
    }

    time_func();

    for(size_t func=0; func<FUNC_COUNT; func++) {
      const exptype f = FUNCTIONS[func];
      time_func(f);
    }

    fp64 loop_overhead = index_multitimer(my_timer, 0);
    runs_data[run][0] = loop_overhead / (fp64) invocations;

    for (size_t func=0; func<FUNC_COUNT; func++) {
      runs_data[run][func+1] = (index_multitimer(my_timer, func+1) - loop_overhead) / (fp64) invocations;
    }

    printf("values: %zu\n", values);
    printf("iters: %zu\n", iters);
    printf("\n");
    printf("action   ");
    for (size_t done=0; done<=run; done++) {
      printf("\ttime    ");
    }
    printf("\n");

    printf("overhead");
    for (size_t done=0; done<=run; done++) {
      printf("\t%e", runs_data[done][0]);
    }
    printf("\n");

    for (size_t func=0; func<FUNC_COUNT; func++) {
      printf("%s", NAMES[func]);
      for (size_t done=0; done<=run; done++) {
        printf("\t%e", runs_data[done][func+1]);
      }
      printf("\n");
    }

    printf("\n\n\n\n");

    free_multitimer(my_timer);
  }
}

int main(int argc, char** argv)
{
  size_t log2_values = 18;
  size_t log2_invocations = 32;
  size_t runs = 10;
  if (argc > 1) {
    log2_values = strtoul(argv[1], NULL, 10);
  }
  if (argc > 2) {
    log2_invocations = strtoul(argv[2], NULL, 10);
  }
  if (argc > 3) {
    runs = strtoul(argv[3], NULL, 10);
  }
  time_exps32(log2_values, log2_invocations, runs);
  return 0;
}
