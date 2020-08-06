

#include "multitimer.h"
#include "xmalloc.h"




static const size_t CHUNK_SIZE = 32;

// Modified from: https://gist.github.com/diabloneo/9619917
static void timespec_diff(struct timespec *start, struct timespec *stop,
                          struct timespec *result)
{
  assert(start != NULL);
  assert(stop != NULL);
  assert(result != NULL);

  result->tv_sec = stop->tv_sec - start->tv_sec;
  result->tv_nsec = stop->tv_nsec - start->tv_nsec;
  if (result->tv_nsec < 0) {
    result->tv_sec -= 1;
    result->tv_nsec += 1000000000L;
  }
}


static fp64 timespec_to_secs(struct timespec* in)
{
  assert(in != NULL);

  return ((fp64) in->tv_sec) + ((fp64) in->tv_nsec) / 1.0e9;
}


multitimer* create_multitimer()
{
  multitimer* retval = (multitimer*) xmalloc(sizeof(multitimer));
  retval->max_entries = CHUNK_SIZE;
  retval->times = (fp64*) xmalloc(sizeof(fp64)*retval->max_entries);
  retval->current_entry = 0;
  retval->timing = 0;

  return retval;
}


void start_multitimer(multitimer* m)
{
  assert(m != NULL);
  assert(m->timing == 0);

  m->timing = 1;
  int status = clock_gettime(CLOCK_MONOTONIC, &(m->start));
  assert(status == 0);
  UNUSED(status);
}


void stop_multitimer(multitimer* m)
{
  assert(m != NULL);
  assert(m->times != NULL);
  assert(m->timing == 1);

  struct timespec end;
  int status = clock_gettime(CLOCK_MONOTONIC, &end);
  assert(status == 0);
  UNUSED(status);

  struct timespec elapsed;
  timespec_diff(&(m->start), &end, &elapsed);

  fp64 elapsed_secs = timespec_to_secs(&elapsed);
  assert(elapsed_secs > 0.0);

  m->times[m->current_entry] = elapsed_secs;
  m->timing = 0;

  m->current_entry += 1;
  if (m->current_entry >= m->max_entries) {
    m->max_entries += CHUNK_SIZE;
    m->times = xrealloc(m->times, sizeof(fp64)*m->max_entries);
  }
}


fp64 index_multitimer(multitimer* m, size_t idx)
{
  assert(m != NULL);
  assert(idx < m->current_entry);

  return m->times[idx];
}


void free_multitimer(multitimer* m)
{
  assert(m != NULL);
  assert(m->times != NULL);

  free(m->times);
  m->times = NULL;

  free(m);
}
