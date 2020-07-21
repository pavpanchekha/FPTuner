

#include "asserts.h"
#include "empty.h"




void empty(void)
{
  ;
}


void empty_fp32(fp32 a)
{
  UNUSED(a);
}

void empty_fp64(fp64 a)
{
  UNUSED(a);
}


void empty_fp32_fp32(fp32 a, fp32 b)
{
  UNUSED(a);
  UNUSED(b);
}

void empty_fp32_fp64(fp32 a, fp64 b)
{
  UNUSED(a);
  UNUSED(b);
}

void empty_fp64_fp32(fp64 a, fp32 b)
{
  UNUSED(a);
  UNUSED(b);
}

void empty_fp64_fp64(fp64 a, fp64 b)
{
  UNUSED(a);
  UNUSED(b);
}
