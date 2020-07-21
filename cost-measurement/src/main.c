

#include "add.h"
#include "cos.h"
#include "div.h"
#include "empty.h"
#include "exp.h"
#include "log.h"
#include "mul.h"
#include "multitimer.h"
#include "sin.h"
#include "sqrt.h"
#include "sub.h"
#include "tan.h"
#include "xmalloc.h"

#include <float.h>
#include <math.h>
#include <stdio.h>


#define time_func(f)                            \
  for (volatile size_t j=0; j<iters; j++) {     \
    for (volatile size_t i=0; i<values; i++) {  \
      f;                                        \
    }                                           \
  }                                             \
  start_multitimer(my_timer);                   \
  for (volatile size_t j=0; j<iters; j++) {     \
    for (volatile size_t i=0; i<values; i++) {  \
      f;                                        \
    }                                           \
  }                                             \
  stop_multitimer(my_timer);                    \



fp64 rand_fp64(void)
{
  const fp64 scale = 1000 / ((fp64) RAND_MAX);
  fp64 rnd = (fp64) rand();
  fp64 sign = rand()%2 == 0 ? 1.0 : -1.0;
  return sign * rnd * scale;
}


size_t GLOBAL = 0;


void time_ops(size_t log2_values, size_t log2_invocations)
{
  size_t values = ((size_t) 1) << log2_values;
  size_t invocations = ((size_t) 1) << log2_invocations;
  size_t log2_iters = log2_invocations - log2_values;
  size_t iters = ((size_t) 1) << log2_iters;

  multitimer* my_timer = create_multitimer();

  start_multitimer(my_timer);

  fp64* a_64 = (fp64*) xmalloc(sizeof(fp64)*values);
  fp32* a_32 = (fp32*) xmalloc(sizeof(fp32)*values);

  fp64* b_64 = (fp64*) xmalloc(sizeof(fp64)*values);
  fp32* b_32 = (fp32*) xmalloc(sizeof(fp32)*values);

  for (size_t i=0; i<values; i++) {
    a_64[i] = rand_fp64();
    a_32[i] = (fp32) a_64[i];

    b_64[i] = rand_fp64();
    b_32[i] = (fp32) b_64[i];
  }

  stop_multitimer(my_timer);

  for (volatile size_t j=0; j<iters; j++) {
    for (volatile size_t i=0; i<values; i++) {
    }
  }

  start_multitimer(my_timer);
  for (volatile size_t j=0; j<iters; j++) {
    for (volatile size_t i=0; i<values; i++) {
    }
  }
  stop_multitimer(my_timer);

  /* time_func(add_fp32(a_32[i], b_32[i])); */
  /* time_func(add_fp64(a_64[i], b_64[i])); */

  /* time_func(sub_fp32(a_32[i], b_32[i])); */
  /* time_func(sub_fp64(a_64[i], b_64[i])); */

  /* time_func(mul_fp32(a_32[i], b_32[i])); */
  /* time_func(mul_fp64(a_64[i], b_64[i])); */

  /* time_func(div_fp32(a_32[i], b_32[i])); */
  /* time_func(div_fp64(a_64[i], b_64[i])); */


  /* for (size_t i=0; i<values; i++) { */
  /*   a_64[i] = fabs(a_64[i]); */
  /*   a_32[i] = fabsf(a_32[i]); */
  /* } */


  /* time_func(sqrt_fp32(a_32[i])); */
  /* time_func(sqrt_fp64(a_64[i])); */

  time_func(zero_sin_fp32(b_32[i]));
  time_func(zero_sin_fp64(b_64[i]));

  time_func(one_sin_fp32(b_32[i]));
  time_func(one_sin_fp64(b_64[i]));

  time_func(m_one_sin_fp32(b_32[i]));
  time_func(m_one_sin_fp64(b_64[i]));

  time_func(taylor_1_sin_fp32(b_32[i]));
  time_func(taylor_1_sin_fp64(b_64[i]));

  time_func(taylor_3_sin_fp32(b_32[i]));
  time_func(taylor_3_sin_fp64(b_64[i]));

  time_func(mlm_4_sin_fp32(b_32[i]));
  time_func(mlm_4_sin_fp64(b_64[i]));

  time_func(mlm_8_sin_fp32(b_32[i]));
  time_func(mlm_8_sin_fp64(b_64[i]));

  time_func(mlm_12_sin_fp32(b_32[i]));
  time_func(mlm_12_sin_fp64(b_64[i]));

  time_func(mlm_16_sin_fp32(b_32[i]));
  time_func(mlm_16_sin_fp64(b_64[i]));

  time_func(mlm_20_sin_fp32(b_32[i]));
  time_func(mlm_20_sin_fp64(b_64[i]));

  time_func(mlm_24_sin_fp32(b_32[i]));
  time_func(mlm_24_sin_fp64(b_64[i]));

  time_func(mlm_28_sin_fp32(b_32[i]));
  time_func(mlm_28_sin_fp64(b_64[i]));

  time_func(mlm_32_sin_fp32(b_32[i]));
  time_func(mlm_32_sin_fp64(b_64[i]));

  time_func(mlm_36_sin_fp32(b_32[i]));
  time_func(mlm_36_sin_fp64(b_64[i]));

  time_func(mlm_40_sin_fp32(b_32[i]));
  time_func(mlm_40_sin_fp64(b_64[i]));

  time_func(sin_fp32(b_32[i]));
  time_func(sin_fp64(b_64[i]));

  /* time_func(cos_fp32(b_32[i])); */
  /* time_func(cos_fp64(b_64[i])); */

  /* time_func(tan_fp32(b_32[i])); */
  /* time_func(tan_fp64(b_64[i])); */

  /* time_func(exp_fp32(b_32[i])); */
  /* time_func(exp_fp64(b_64[i])); */

  /* time_func(log_fp32(a_32[i])); */
  /* time_func(log_fp64(a_64[i])); */

  fp64 loop_overhead = index_multitimer(my_timer, 1) / invocations;

  printf("values: %zu\n", values);
  printf("iters: %zu\n", iters);
  printf("setup time: %f\n", index_multitimer(my_timer, 0));
  printf("\n");
  printf("op          \ttype\ttime per call\n");
  /* printf("add         \tfp32\t%e\n", index_multitimer(my_timer, 1) / invocations - loop_overhead); */
  /* printf("add         \tfp64\t%e\n", index_multitimer(my_timer, 2) / invocations - loop_overhead); */
  /* printf("sub         \tfp32\t%e\n", index_multitimer(my_timer, 3) / invocations - loop_overhead); */
  /* printf("sub         \tfp64\t%e\n", index_multitimer(my_timer, 4) / invocations - loop_overhead); */
  /* printf("mul         \tfp32\t%e\n", index_multitimer(my_timer, 5) / invocations - loop_overhead); */
  /* printf("mul         \tfp64\t%e\n", index_multitimer(my_timer, 6) / invocations - loop_overhead); */
  /* printf("div         \tfp32\t%e\n", index_multitimer(my_timer, 7) / invocations - loop_overhead); */
  /* printf("div         \tfp64\t%e\n", index_multitimer(my_timer, 8) / invocations - loop_overhead); */
  /* printf("sqrt        \tfp32\t%e\n", index_multitimer(my_timer, 9) / invocations - loop_overhead); */
  /* printf("sqrt        \tfp64\t%e\n", index_multitimer(my_timer, 10) / invocations - loop_overhead); */
  printf("zero_sin    \tfp32\t%e\n", index_multitimer(my_timer, 2) / invocations - loop_overhead);
  printf("zero_sin    \tfp64\t%e\n", index_multitimer(my_timer, 3) / invocations - loop_overhead);
  printf("one_sin     \tfp32\t%e\n", index_multitimer(my_timer, 4) / invocations - loop_overhead);
  printf("one_sin     \tfp64\t%e\n", index_multitimer(my_timer, 5) / invocations - loop_overhead);
  printf("m_one_sin   \tfp32\t%e\n", index_multitimer(my_timer, 6) / invocations - loop_overhead);
  printf("m_one_sin   \tfp64\t%e\n", index_multitimer(my_timer, 7) / invocations - loop_overhead);
  printf("taylor_1_sin\tfp32\t%e\n", index_multitimer(my_timer, 8) / invocations - loop_overhead);
  printf("taylor_1_sin\tfp64\t%e\n", index_multitimer(my_timer, 9) / invocations - loop_overhead);
  printf("taylor_3_sin\tfp32\t%e\n", index_multitimer(my_timer, 10) / invocations - loop_overhead);
  printf("taylor_3_sin\tfp64\t%e\n", index_multitimer(my_timer, 11) / invocations - loop_overhead);
  printf("mlm_4_sin   \tfp32\t%e\n", index_multitimer(my_timer, 12) / invocations - loop_overhead);
  printf("mlm_4_sin   \tfp64\t%e\n", index_multitimer(my_timer, 13) / invocations - loop_overhead);
  printf("mlm_8_sin   \tfp32\t%e\n", index_multitimer(my_timer, 14) / invocations - loop_overhead);
  printf("mlm_8_sin   \tfp64\t%e\n", index_multitimer(my_timer, 15) / invocations - loop_overhead);
  printf("mlm_12_sin  \tfp32\t%e\n", index_multitimer(my_timer, 16) / invocations - loop_overhead);
  printf("mlm_12_sin  \tfp64\t%e\n", index_multitimer(my_timer, 17) / invocations - loop_overhead);
  printf("mlm_16_sin  \tfp32\t%e\n", index_multitimer(my_timer, 18) / invocations - loop_overhead);
  printf("mlm_16_sin  \tfp64\t%e\n", index_multitimer(my_timer, 19) / invocations - loop_overhead);
  printf("mlm_20_sin  \tfp32\t%e\n", index_multitimer(my_timer, 20) / invocations - loop_overhead);
  printf("mlm_20_sin  \tfp64\t%e\n", index_multitimer(my_timer, 21) / invocations - loop_overhead);
  printf("mlm_24_sin  \tfp32\t%e\n", index_multitimer(my_timer, 22) / invocations - loop_overhead);
  printf("mlm_24_sin  \tfp64\t%e\n", index_multitimer(my_timer, 23) / invocations - loop_overhead);
  printf("mlm_28_sin  \tfp32\t%e\n", index_multitimer(my_timer, 24) / invocations - loop_overhead);
  printf("mlm_28_sin  \tfp64\t%e\n", index_multitimer(my_timer, 25) / invocations - loop_overhead);
  printf("mlm_32_sin  \tfp32\t%e\n", index_multitimer(my_timer, 26) / invocations - loop_overhead);
  printf("mlm_32_sin  \tfp64\t%e\n", index_multitimer(my_timer, 27) / invocations - loop_overhead);
  printf("mlm_36_sin  \tfp32\t%e\n", index_multitimer(my_timer, 28) / invocations - loop_overhead);
  printf("mlm_36_sin  \tfp64\t%e\n", index_multitimer(my_timer, 29) / invocations - loop_overhead);
  printf("mlm_40_sin  \tfp32\t%e\n", index_multitimer(my_timer, 30) / invocations - loop_overhead);
  printf("mlm_40_sin  \tfp64\t%e\n", index_multitimer(my_timer, 31) / invocations - loop_overhead);
  printf("sin         \tfp32\t%e\n", index_multitimer(my_timer, 32) / invocations - loop_overhead);
  printf("sin         \tfp64\t%e\n", index_multitimer(my_timer, 33) / invocations - loop_overhead);
  /* printf("cos         \tfp32\t%e\n", index_multitimer(my_timer, 23) / invocations - loop_overhead); */
  /* printf("cos         \tfp64\t%e\n", index_multitimer(my_timer, 24) / invocations - loop_overhead); */
  /* printf("tan         \tfp32\t%e\n", index_multitimer(my_timer, 25) / invocations - loop_overhead); */
  /* printf("tan         \tfp64\t%e\n", index_multitimer(my_timer, 26) / invocations - loop_overhead); */
  /* printf("exp         \tfp32\t%e\n", index_multitimer(my_timer, 27) / invocations - loop_overhead); */
  /* printf("exp         \tfp64\t%e\n", index_multitimer(my_timer, 28) / invocations - loop_overhead); */
  /* printf("log         \tfp32\t%e\n", index_multitimer(my_timer, 29) / invocations - loop_overhead); */
  /* printf("log         \tfp64\t%e\n", index_multitimer(my_timer, 30) / invocations - loop_overhead); */
}


void time_add_size(size_t log2_invocations)
{
  size_t invocations = ((size_t) 1) << log2_invocations;

  printf("invocations: %zu\n", invocations);

  size_t max_log2_size = 29;
  size_t max_size = ((size_t) 1) << max_log2_size;

  multitimer* my_timer = create_multitimer();

  start_multitimer(my_timer);

  fp64* a_64 = (fp64*) xmalloc(sizeof(fp64)*max_size);
  fp64* b_64 = (fp64*) xmalloc(sizeof(fp64)*max_size);

  for (size_t i=0; i<max_size; i++) {
    a_64[i] = rand_fp64();
    b_64[i] = rand_fp64();
  }

  stop_multitimer(my_timer);

  printf("setup time: %f\n", index_multitimer(my_timer, 0));
  printf("\n");
  printf("values\ttime per call\n");

  for (size_t log2_size=1; log2_size<=max_log2_size; log2_size++) {
    size_t values = ((size_t) 1) << log2_size;
    size_t log2_iters = log2_invocations - log2_size;
    size_t iters =  ((size_t) 1) << log2_iters;

    start_multitimer(my_timer);
    for (volatile size_t j=0; j<iters; j++) {
      for (volatile size_t i=0; i<values; i++) {
      }
    }
    stop_multitimer(my_timer);

    for (volatile size_t j=0; j<iters; j++) {
      for (volatile size_t i=0; i<values; i++) {
        add_fp64(a_64[i], b_64[i]);
      }
    }

    start_multitimer(my_timer);
    for (volatile size_t j=0; j<iters; j++) {
      for (volatile size_t i=0; i<values; i++) {
        add_fp64(a_64[i], b_64[i]);
      }
    }
    stop_multitimer(my_timer);

    fp64 loop_time = index_multitimer(my_timer, log2_size*2-1);
    fp64 op_time = index_multitimer(my_timer, log2_size*2);
    fp64 call_time = (op_time - loop_time) / invocations;
    printf("%zu\t%e\n", values, call_time);
  }

}

int main(int argc, char** argv)
{
  size_t log2_values = 19;
  size_t log2_invocations = 24;
  if (argc > 1) {
    log2_values = strtol(argv[1], NULL, 10);
  }
  if (argc > 2) {
    log2_invocations = strtol(argv[2], NULL, 10);
  }
  time_ops(log2_values, log2_invocations);
  return 0;
}
