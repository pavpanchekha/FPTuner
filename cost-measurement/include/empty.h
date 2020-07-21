#ifndef EMPTY_H
#define EMPTY_H

#include "types.h"




void empty(void);

void empty_fp32(fp32 a);
void empty_fp64(fp64 a);

void empty_fp32_fp32(fp32 a, fp32 b);
void empty_fp32_fp64(fp32 a, fp64 b);
void empty_fp64_fp32(fp64 a, fp32 b);
void empty_fp64_fp64(fp64 a, fp64 b);




#endif
