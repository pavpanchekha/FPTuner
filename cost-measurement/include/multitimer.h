#ifndef MULTITIMER_H
#define MULTITIMER_H

#include "types.h"

#include <stddef.h>
#include <time.h>




typedef struct {
  fp64* times;
  size_t max_entries;
  size_t current_entry;
  int timing;
  struct timespec start;
} multitimer;




multitimer* create_multitimer(void);

void start_multitimer(multitimer* m);
void stop_multitimer(multitimer* m);
fp64 index_multitimer(multitimer* m, size_t idx);

void free_multitimer(multitimer* m);




#endif
