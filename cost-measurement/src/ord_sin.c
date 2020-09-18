#include "ord_sin.h"
#include <math.h>
#include <stdlib.h>
//static const fp32 HPI_fp32 = 1.5707963268f;
static const fp64 HPI_fp64 = 1.570796326794896619;
fp64 ord_01_sin_fp64(fp64 x) {
  return x * 0x1.8e51f5e5f553p-1;
}
fp64 ord_03_sin_fp64(fp64 x) {
  return x * (0x1.fc4eac57b4a27p-1 + (x*x) * (-0x1.2b704cf682899p-3));
}
fp64 ord_05_sin_fp64(fp64 x) {
  return x * (0x1.fff1d21fa9c5ap-1 + (x*x) * (-0x1.53e2e5c7de0dfp-3 + (x*x) * 0x1.f2438d36e4474p-8));
}
fp64 ord_07_sin_fp64(fp64 x) {
  return x * (0x1.ffffe07d2f183p-1 + (x*x) * (-0x1.554f800fd8d69p-3 + (x*x) * (0x1.105d44e837a33p-7 + (x*x) * (-0x1.83b972867e8fdp-13))));
}
fp64 ord_09_sin_fp64(fp64 x) {
  return x * (0x1.ffffffd25a681p-1 + (x*x) * (-0x1.555547ef5150bp-3 + (x*x) * (0x1.110e7b396c556p-7 + (x*x) * (-0x1.9f6445023f77bp-13 + (x*x) * 0x1.5d38b56aee80bp-19))));
}
fp64 ord_11_sin_fp64(fp64 x) {
  return x * (0x1.ffffffffd17d1p-1 + (x*x) * (-0x1.55555541759fap-3 + (x*x) * (0x1.11110b74adb08p-7 + (x*x) * (-0x1.a017a8fe14b61p-13 + (x*x) * (0x1.716ba4fe4cdc8p-19 + (x*x) * (-0x1.9a0e19297139fp-26))))));
}
fp64 ord_13_sin_fp64(fp64 x) {
  return x * (0x1.ffffffffffdcep-1 + (x*x) * (-0x1.5555555540b9bp-3 + (x*x) * (0x1.111111090f0bcp-7 + (x*x) * (-0x1.a019fce979937p-13 + (x*x) * (0x1.71dce5ace58d2p-19 + (x*x) * (-0x1.ae00fd733fe8dp-26 + (x*x) * 0x1.52ace959bd024p-33))))));
}
fp64 ord_15_sin_fp64(fp64 x) {
  return x * (0x1.fffffffffffffp-1 + (x*x) * (-0x1.5555555555469p-3 + (x*x) * (0x1.111111110941dp-7 + (x*x) * (-0x1.a01a0199e0eb3p-13 + (x*x) * (0x1.71de37e62aac6p-19 + (x*x) * (-0x1.ae634d22bb1b9p-26 + (x*x) * (0x1.60e59ae003e7fp-33 + (x*x) * (-0x1.9ef5d5932bfd7p-41))))))));
}
fp64 ord_17_sin_fp64(fp64 x) {
  return x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.11111111110c9p-7 + (x*x) * (-0x1.a01a01a014eb6p-13 + (x*x) * (0x1.71de3a52aab96p-19 + (x*x) * (-0x1.ae6454d960ac4p-26 + (x*x) * (0x1.6123ce513b09fp-33 + (x*x) * (-0x1.ae43dc9bf8ba7p-41 + (x*x) * 0x1.883c1c5deffbep-49))))))));
}
fp64 ord_19_sin_fp64(fp64 x) {
  return x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.11111111110dcp-7 + (x*x) * (-0x1.a01a01a016ef6p-13 + (x*x) * (0x1.71de3a53fa85cp-19 + (x*x) * (-0x1.ae6455b871495p-26 + (x*x) * (0x1.612421756fa37p-33 + (x*x) * (-0x1.ae671378cef25p-41 + (x*x) * (0x1.90277db349c6p-49 + (x*x) * (-0x1.78262ef11eaafp-58))))))))));
}
fp64 rord_01_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_01_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_01_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_03_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_03_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_03_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_05_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_05_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_05_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_07_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_07_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_07_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_09_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_09_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_09_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_11_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_11_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_11_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_13_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_13_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_13_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_15_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_15_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_15_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_17_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_17_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_17_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
fp64 rord_19_sin_fp64(fp64 x) {
  if (x < HPI_fp64) {
    return ord_19_sin_fp64(x);
  }
  int k = (int) (x / HPI_fp64);
  fp64 whole = ((fp64) k) * HPI_fp64;
  fp64 y = x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
    case 2:
      z = y;
      break;
    case 1:
    case 3:
      z = HPI_fp64 - y;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_19_sin_fp64(z);
  if (part == 2 || part == 3) {
    result *= (fp64) -1.0;  }
  return result;
}
