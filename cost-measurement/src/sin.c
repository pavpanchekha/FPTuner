

#include "sin.h"

#include <math.h>




fp32 sin_fp32(fp32 a)
{
  return sinf(a);
}

fp64 sin_fp64(fp64 a)
{
  return sin(a);
}


fp32 zero_sin_fp32(fp32 a)
{
  UNUSED(a);
  return 0.0f;
}

fp64 zero_sin_fp64(fp64 a)
{
  UNUSED(a);
  return 0.0;
}


fp32 one_sin_fp32(fp32 a)
{
  UNUSED(a);
  return 1.0f;
}

fp64 one_sin_fp64(fp64 a)
{
  UNUSED(a);
  return 1.0;
}


fp32 m_one_sin_fp32(fp32 a)
{
  UNUSED(a);
  return -1.0f;
}

fp64 m_one_sin_fp64(fp64 a)
{
  UNUSED(a);
  return -1.0;
}


fp32 taylor_1_sin_fp32(fp32 a)
{
  return a;
}

fp64 taylor_1_sin_fp64(fp64 a)
{
  return a;
}


fp32 taylor_3_sin_fp32(fp32 a)
{
  return a - (a*a*a)/6;
}

fp64 taylor_3_sin_fp64(fp64 a)
{
  return a - (a*a*a)/6;
}


