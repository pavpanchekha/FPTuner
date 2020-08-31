

#include "timing.h"
#include "xmalloc.h"

#include <signal.h>
#include <time.h>




volatile sig_atomic_t RUNNING = 0;


void print_data(size_t values, size_t secs, size_t run, size_t count, char** names, char** error_bounds, size_t** runs_data)
{
  printf("values\t %zu\n", values);
  printf("secs\t %zu\n", secs);
  printf("\n");
  printf("function\terror_bound");
  for (size_t done=0; done<run; done++) {
    printf("\tcalls");
  }
  printf("\n");

  for (size_t func=0; func<count; func++) {
    printf("%s\t%s", names[func], error_bounds[func]);
    for (size_t done=0; done<run; done++) {
      printf("\t%zu", runs_data[done][func]);
    }
    printf("\n");
  }
}



void sigprof_handler(int sig)
{
  assert(sig == SIGPROF);
  UNUSED(sig);

  RUNNING = 0;
}


void register_performance_handler(void)
{
  struct sigaction action;

  action.sa_handler = sigprof_handler;
  sigemptyset(&action.sa_mask); /* block sigs of type being handled */
  action.sa_flags = SA_RESTART; /* restart syscalls if possible */

  int status = sigaction(SIGPROF, &action, NULL);
  assert(status == 0);
  UNUSED(status);
}


size_t count_unop_calls_fp32(unop_fp32 func, fp32* data, size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;
  timer_t timerid;
  struct sigevent evp;
  struct itimerspec its;

  evp.sigev_notify = SIGEV_SIGNAL;
  evp.sigev_signo = SIGPROF;
  evp.sigev_value.sival_ptr = &timerid;
  status = timer_create(CLOCK_MONOTONIC, &evp, &timerid);
  assert(status==0);
  UNUSED(status);

  its.it_value.tv_sec = (long int) secs;
  its.it_value.tv_nsec = 0;

  RUNNING = 1;
  timer_settime(timerid, 0, &its, NULL);
  while (RUNNING) {
    func(data[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status==0);
  UNUSED(status);

  return calls;
}


size_t count_unop_calls_fp64(unop_fp64 func, fp64* data, size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;
  timer_t timerid;
  struct sigevent evp;
  struct itimerspec its;

  evp.sigev_notify = SIGEV_SIGNAL;
  evp.sigev_signo = SIGPROF;
  evp.sigev_value.sival_ptr = &timerid;
  status = timer_create(CLOCK_MONOTONIC, &evp, &timerid);
  assert(status==0);
  UNUSED(status);

  its.it_value.tv_sec = (long int) secs;
  its.it_value.tv_nsec = 0;

  RUNNING = 1;
  timer_settime(timerid, 0, &its, NULL);
  while (RUNNING) {
    func(data[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status==0);
  UNUSED(status);

  return calls;
}


size_t count_binop_calls_fp32(binop_fp32 func, fp32* data_1, fp32* data_2,
                                     size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;
  timer_t timerid;
  struct sigevent evp;
  struct itimerspec its;

  evp.sigev_notify = SIGEV_SIGNAL;
  evp.sigev_signo = SIGPROF;
  evp.sigev_value.sival_ptr = &timerid;
  status = timer_create(CLOCK_MONOTONIC, &evp, &timerid);
  assert(status==0);
  UNUSED(status);

  its.it_value.tv_sec = (long int) secs;
  its.it_value.tv_nsec = 0;

  RUNNING = 1;
  timer_settime(timerid, 0, &its, NULL);
  while (RUNNING) {
    func(data_1[idx], data_2[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status==0);
  UNUSED(status);

  return calls;
}


size_t count_binop_calls_fp64(binop_fp64 func, fp64* data_1, fp64* data_2,
                                     size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;
  timer_t timerid;
  struct sigevent evp;
  struct itimerspec its;

  evp.sigev_notify = SIGEV_SIGNAL;
  evp.sigev_signo = SIGPROF;
  evp.sigev_value.sival_ptr = &timerid;
  status = timer_create(CLOCK_MONOTONIC, &evp, &timerid);
  assert(status==0);
  UNUSED(status);

  its.it_value.tv_sec = (long int) secs;
  its.it_value.tv_nsec = 0;

  RUNNING = 1;
  timer_settime(timerid, 0, &its, NULL);
  while (RUNNING) {
    func(data_1[idx], data_2[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status==0);
  UNUSED(status);

  return calls;
}


size_t count_triop_calls_fp32(triop_fp32 func, fp32* data_1, fp32* data_2, fp32* data_3,
                                     size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;
  timer_t timerid;
  struct sigevent evp;
  struct itimerspec its;

  evp.sigev_notify = SIGEV_SIGNAL;
  evp.sigev_signo = SIGPROF;
  evp.sigev_value.sival_ptr = &timerid;
  status = timer_create(CLOCK_MONOTONIC, &evp, &timerid);
  assert(status==0);
  UNUSED(status);

  its.it_value.tv_sec = (long int) secs;
  its.it_value.tv_nsec = 0;

  RUNNING = 1;
  timer_settime(timerid, 0, &its, NULL);
  while (RUNNING) {
    func(data_1[idx], data_2[idx], data_3[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status==0);
  UNUSED(status);

  return calls;
}


size_t count_triop_calls_fp64(triop_fp64 func, fp64* data_1, fp64* data_2, fp64* data_3,
                                     size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;
  timer_t timerid;
  struct sigevent evp;
  struct itimerspec its;

  evp.sigev_notify = SIGEV_SIGNAL;
  evp.sigev_signo = SIGPROF;
  evp.sigev_value.sival_ptr = &timerid;
  status = timer_create(CLOCK_MONOTONIC, &evp, &timerid);
  assert(status==0);
  UNUSED(status);

  its.it_value.tv_sec = (long int) secs;
  its.it_value.tv_nsec = 0;

  RUNNING = 1;
  timer_settime(timerid, 0, &its, NULL);
  while (RUNNING) {
    func(data_1[idx], data_2[idx], data_3[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status==0);
  UNUSED(status);

  return calls;
}


fp32 rand_fp32(fp32 low, fp32 high)
{
  const fp32 scale = (low-high) / ((fp32) RAND_MAX);
  fp32 rnd = (fp32) rand();
  return low + rnd * scale;
}


fp64 rand_fp64(fp64 low, fp64 high)
{
  const fp64 scale = (low-high) / ((fp64) RAND_MAX);
  fp64 rnd = (fp64) rand();
  return low + rnd * scale;
}


void time_unop_fp32(fp32 low, fp32 high,
                    unop_fp32* functions, char** names, char** error_bounds, size_t count,
                    size_t log2_values, size_t runs, size_t secs)
{
  size_t values = ((size_t) 1) << log2_values;

  size_t** runs_data = (size_t**) xmalloc(sizeof(size_t*)*runs);
  for (size_t i=0; i<runs; i++) {
    runs_data[i] = (size_t*) xmalloc(sizeof(size_t)*(count));
  }

  fp32* A = (fp32*) xmalloc(sizeof(fp32)*values);

  for(size_t run=0; run<runs; run++) {
    for (size_t i=0; i<values; i++) {
      A[i] = rand_fp32(low, high);
    }

    for(size_t func=0; func<count; func++) {
      const unop_fp32 f = functions[func];
      runs_data[run][func] = count_unop_calls_fp32(f, A, log2_values, secs);
    }
  }

  print_data(values, secs, runs, count, names, error_bounds, runs_data);
}


void time_unop_fp64(fp64 low, fp64 high,
                    unop_fp64* functions, char** names, char** error_bounds, size_t count,
                    size_t log2_values, size_t runs, size_t secs)
{
  size_t values = ((size_t) 1) << log2_values;

  size_t** runs_data = (size_t**) xmalloc(sizeof(size_t*)*runs);
  for (size_t i=0; i<runs; i++) {
    runs_data[i] = (size_t*) xmalloc(sizeof(size_t)*(count));
  }

  fp64* A = (fp64*) xmalloc(sizeof(fp64)*values);

  for(size_t run=0; run<runs; run++) {

    for (size_t i=0; i<values; i++) {
      A[i] = rand_fp64(low, high);
    }

    for(size_t func=0; func<count; func++) {
      const unop_fp64 f = functions[func];
      runs_data[run][func] = count_unop_calls_fp64(f, A, log2_values, secs);
    }
  }

  print_data(values, secs, runs, count, names, error_bounds, runs_data);
}

void time_binop_fp32(fp32 low_1, fp32 high_1, fp32 low_2, fp32 high_2,
                     binop_fp32* functions, char** names, char** error_bounds, size_t count,
                     size_t log2_values, size_t runs, size_t secs)
{
  size_t values = ((size_t) 1) << log2_values;

  size_t** runs_data = (size_t**) xmalloc(sizeof(size_t*)*runs);
  for (size_t i=0; i<runs; i++) {
    runs_data[i] = (size_t*) xmalloc(sizeof(size_t)*(count));
  }

  fp32* A = (fp32*) xmalloc(sizeof(fp32)*values);
  fp32* B = (fp32*) xmalloc(sizeof(fp32)*values);

  for(size_t run=0; run<runs; run++) {

    for (size_t i=0; i<values; i++) {
      A[i] = rand_fp32(low_1, high_1);
      B[i] = rand_fp32(low_2, high_2);
    }

    for(size_t func=0; func<count; func++) {
      const binop_fp32 f = functions[func];
      runs_data[run][func] = count_binop_calls_fp32(f, A, B, log2_values, secs);
    }
  }

  print_data(values, secs, runs, count, names, error_bounds, runs_data);
}


void time_binop_fp64(fp64 low_1, fp64 high_1, fp64 low_2, fp64 high_2,
                     binop_fp64* functions, char** names, char** error_bounds, size_t count,
                     size_t log2_values, size_t runs, size_t secs)
{
  size_t values = ((size_t) 1) << log2_values;

  size_t** runs_data = (size_t**) xmalloc(sizeof(size_t*)*runs);
  for (size_t i=0; i<runs; i++) {
    runs_data[i] = (size_t*) xmalloc(sizeof(size_t)*(count));
  }

  fp64* A = (fp64*) xmalloc(sizeof(fp64)*values);
  fp64* B = (fp64*) xmalloc(sizeof(fp64)*values);

  for(size_t run=0; run<runs; run++) {

    for (size_t i=0; i<values; i++) {
      A[i] = rand_fp64(low_1, high_1);
      B[i] = rand_fp64(low_2, high_2);
    }

    for(size_t func=0; func<count; func++) {
      const binop_fp64 f = functions[func];
      runs_data[run][func] = count_binop_calls_fp64(f, A, B, log2_values, secs);
    }
  }

  print_data(values, secs, runs, count, names, error_bounds, runs_data);
}


void time_triop_fp32(fp32 low_1, fp32 high_1, fp32 low_2, fp32 high_2, fp32 low_3, fp32 high_3,
                     triop_fp32* functions, char** names, char** error_bounds, size_t count,
                     size_t log2_values, size_t runs, size_t secs)
{
  size_t values = ((size_t) 1) << log2_values;

  size_t** runs_data = (size_t**) xmalloc(sizeof(size_t*)*runs);
  for (size_t i=0; i<runs; i++) {
    runs_data[i] = (size_t*) xmalloc(sizeof(size_t)*(count));
  }

  fp32* A = (fp32*) xmalloc(sizeof(fp32)*values);
  fp32* B = (fp32*) xmalloc(sizeof(fp32)*values);
  fp32* C = (fp32*) xmalloc(sizeof(fp32)*values);

  for(size_t run=0; run<runs; run++) {

    for (size_t i=0; i<values; i++) {
      A[i] = rand_fp32(low_1, high_1);
      B[i] = rand_fp32(low_2, high_2);
      C[i] = rand_fp32(low_3, high_3);
    }

    for(size_t func=0; func<count; func++) {
      const triop_fp32 f = functions[func];
      runs_data[run][func] = count_triop_calls_fp32(f, A, B, C, log2_values, secs);
    }
  }

  print_data(values, secs, runs, count, names, error_bounds, runs_data);
}


void time_triop_fp64(fp64 low_1, fp64 high_1, fp64 low_2, fp64 high_2, fp64 low_3, fp64 high_3,
                     triop_fp64* functions, char** names, char** error_bounds, size_t count,
                     size_t log2_values, size_t runs, size_t secs)
{
  size_t values = ((size_t) 1) << log2_values;

  size_t** runs_data = (size_t**) xmalloc(sizeof(size_t*)*runs);
  for (size_t i=0; i<runs; i++) {
    runs_data[i] = (size_t*) xmalloc(sizeof(size_t)*(count));
  }

  fp64* A = (fp64*) xmalloc(sizeof(fp64)*values);
  fp64* B = (fp64*) xmalloc(sizeof(fp64)*values);
  fp64* C = (fp64*) xmalloc(sizeof(fp64)*values);

  for(size_t run=0; run<runs; run++) {

    for (size_t i=0; i<values; i++) {
      A[i] = rand_fp64(low_1, high_1);
      B[i] = rand_fp64(low_2, high_2);
      C[i] = rand_fp64(low_3, high_3);
    }

    for(size_t func=0; func<count; func++) {
      const triop_fp64 f = functions[func];
      runs_data[run][func] = count_triop_calls_fp64(f, A, B, C, log2_values, secs);
    }
  }

  print_data(values, secs, runs, count, names, error_bounds, runs_data);
}
