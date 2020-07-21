#ifndef TYPES_H
#define TYPES_H

#include "asserts.h"

#include <limits.h>




STATIC_ASSERT(sizeof(float)*CHAR_BIT == 32, "float must be 32 bits");
typedef float fp32;

STATIC_ASSERT(sizeof(double)*CHAR_BIT == 64, "double must be 64 bits");
typedef double fp64;




#endif
