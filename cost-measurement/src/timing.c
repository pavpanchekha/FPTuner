

#include "timing.h"
#include "xmalloc.h"

#include <signal.h>
#include <pthread.h>
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



void sigprof_handler(union sigval val)
{
  UNUSED(val);

  RUNNING = 0;
}


void register_performance_handler(void)
{
}

timer_t start_timer(size_t secs)
{
  int status;

  pthread_attr_t attr;
  pthread_attr_init( &attr );

  struct sched_param parm;
  parm.sched_priority = 255;
  pthread_attr_setschedparam(&attr, &parm);

  struct sigevent sig;
  sig.sigev_notify = SIGEV_THREAD;
  sig.sigev_signo = SIGPROF;
  sig.sigev_notify_function = sigprof_handler;
  sig.sigev_value.sival_int = 20;
  sig.sigev_notify_attributes = &attr;

  timer_t timerid;
  status = timer_create(CLOCK_REALTIME, &sig, &timerid);
  assert(status == 0);

  struct itimerspec in, out;
  in.it_value.tv_sec = 1;
  in.it_value.tv_nsec = 0;
  in.it_interval.tv_sec = (long int) secs;
  in.it_interval.tv_nsec = 0;
  status = timer_settime(timerid, 0, &in, &out);
  assert(status == 0);

  return timerid;
}

size_t count_unop_calls_fp32(unop_fp32 func, fp32* data, size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;

  RUNNING = 1;
  timer_t timerid = start_timer(secs);
  while (RUNNING) {
    func(data[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status == 0);

  return calls;
}


size_t count_unop_calls_fp64(unop_fp64 func, fp64* data, size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;

  RUNNING = 1;
  timer_t timerid = start_timer(secs);
  while (RUNNING) {
    func(data[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status == 0);

  return calls;
}


size_t count_binop_calls_fp32(binop_fp32 func, fp32* data_1, fp32* data_2,
                              size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;

  RUNNING = 1;
  timer_t timerid = start_timer(secs);
  while (RUNNING) {
    func(data_1[idx], data_2[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status == 0);

  return calls;
}


size_t count_binop_calls_fp64(binop_fp64 func, fp64* data_1, fp64* data_2,
                              size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;

  RUNNING = 1;
  timer_t timerid = start_timer(secs);
  while (RUNNING) {
    func(data_1[idx], data_2[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status == 0);

  return calls;
}


size_t count_triop_calls_fp32(triop_fp32 func, fp32* data_1, fp32* data_2, fp32* data_3,
                              size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;

  RUNNING = 1;
  timer_t timerid = start_timer(secs);
  while (RUNNING) {
    func(data_1[idx], data_2[idx], data_3[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status == 0);

  return calls;
}


size_t count_triop_calls_fp64(triop_fp64 func, fp64* data_1, fp64* data_2, fp64* data_3,
                              size_t log2_len, size_t secs)
{
  size_t calls = 0;
  size_t idx = 0;
  size_t len = ((size_t) 1) << log2_len;
  int status;

  RUNNING = 1;
  timer_t timerid = start_timer(secs);
  while (RUNNING) {
    func(data_1[idx], data_2[idx], data_3[idx]);
    idx = (idx+1) % len;
    calls += 1;
  };

  status = timer_delete(timerid);
  assert(status == 0);

  return calls;
}


fp32 rand_fp32(fp32 low, fp32 high)
{
  assert(low < high);

  fp32 ret;

  do {
    const fp32 scale = (high-low) / ((fp32) RAND_MAX);
    fp32 rnd = (fp32) rand();
    ret = low + rnd * scale;
  } while (ret < low || ret > high);

  return ret;
}


fp64 rand_fp64(fp64 low, fp64 high)
{
  assert(low < high);

  fp64 ret;

  do {
    const fp64 scale = (high-low) / ((fp64) RAND_MAX);
    fp64 rnd = (fp64) rand();
    ret = low + rnd * scale;
  } while(ret < low || ret > high);

  return ret;
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
