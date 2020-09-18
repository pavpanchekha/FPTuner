#include "ord_exp.h"
#include <math.h>
//static const fp32 LN2_fp32 = 0.69314718056f;
static const fp64 LN2_fp64 = 0.6931471805599453094;
fp64 ord_01_exp_fp64(fp64 x) {
  return 0x1.f0bb4660ae0aap-1 + x * 0x1.6650e9bda3339p0;
}
fp64 ord_02_exp_fp64(fp64 x) {
  return 0x1.007108b999c43p0 + x * (0x1.e5c4ff42f0abfp-1 + x * 0x1.675460d4d4545p-1);
}
fp64 ord_03_exp_fp64(fp64 x) {
  return 0x1.fff632c05854dp-1 + x * (0x1.00fdfdbf552e8p0 + x * (0x1.e1d265bcc197cp-2 + x * 0x1.dfd3b6cc921b5p-3));
}
fp64 ord_04_exp_fp64(fp64 x) {
  return 0x1.00002b82713bbp0 + x * (0x1.ffe4e4c936787p-1 + x * (0x1.014bcdddc30cbp-1 + x * (0x1.3fdac7f2620b2p-3 + x * 0x1.e04ecd756dfe6p-5)));
}
fp64 ord_05_exp_fp64(fp64 x) {
  return 0x1.fffffd7c4cf39p-1 + x * (0x1.00008ea0bb51fp0 + x * (0x1.ffd83adc2c3d7p-2 + x * (0x1.575098397d238p-3 + x * (0x1.3f04be7046d13p-5 + x * 0x1.80856ea70ab72p-7))));
}
fp64 ord_06_exp_fp64(fp64 x) {
  return 0x1.00000007f8795p0 + x * (0x1.fffff67a2004ap-1 + x * (0x1.0000e8843b765p-1 + x * (0x1.5534a3d018c43p-3 + x * (0x1.577ce7a237d7ep-5 + x * (0x1.fd8561b94780bp-8 + x * 0x1.007c2b47a30cp-9)))));
}
fp64 ord_07_exp_fp64(fp64 x) {
  return 0x1.ffffffffa7933p-1 + x * (0x1.000000223a697p0 + x * (0x1.ffffeee95eaffp-2 + x * (0x1.5556efb155eep-3 + x * (0x1.552ff9841cc1fp-5 + x * (0x1.12e413bfa187bp-7 + x * (0x1.533dd87d737cep-10 + x * 0x1.253f82070487ap-12))))));
}
fp64 ord_08_exp_fp64(fp64 x) {
  return 0x1.0000000000dap0 + x * (0x1.fffffffe5790dp-1 + x * (0x1.0000004310c7ap-1 + x * (0x1.55554531bc243p-3 + x * (0x1.555742acef6d1p-5 + x * (0x1.10f04675d1238p-7 + x * (0x1.6e9f84d7b4445p-10 + x * (0x1.8352e2314cdfep-13 + x * 0x1.255894992c254p-15)))))));
}
fp64 ord_09_exp_fp64(fp64 x) {
  return 0x1.fffffffffff87p-1 + x * (0x1.0000000004848p0 + x * (0x1.fffffffc7a21bp-2 + x * (0x1.555555dc7aed9p-3 + x * (0x1.555540ece8d6ap-5 + x * (0x1.1112d2f073013p-7 + x * (0x1.6be7f08faf222p-10 + x * (0x1.a316df95903ap-13 + x * (0x1.83063fca76075p-16 + x * 0x1.04d2cfe830758p-18))))))));
}
fp64 ord_10_exp_fp64(fp64 x) {
  return 0x1.0000000000001p0 + x * (0x1.ffffffffffd37p-1 + x * (0x1.000000000a6e6p-1 + x * (0x1.555555518a0fp-3 + x * (0x1.5555560988e25p-5 + x * (0x1.1110fdab24f6cp-7 + x * (0x1.6c19583ef1c5p-10 + x * (0x1.9fe18b72dd3fcp-13 + x * (0x1.a32a6e91303d2p-16 + x * (0x1.57cb1b94f32fdp-19 + x * 0x1.a1718972b0737p-22)))))))));
}
fp64 ord_11_exp_fp64(fp64 x) {
  return 0x1p0 + x * (0x1.0000000000004p0 + x * (0x1.ffffffffffa8bp-2 + x * (0x1.5555555569e36p-3 + x * (0x1.55555550892c9p-5 + x * (0x1.111111b6be046p-7 + x * (0x1.6c16a573eff92p-10 + x * (0x1.a01d15923c21p-13 + x * (0x1.9fe0ac10d6e0bp-16 + x * (0x1.7498ad0658811p-19 + x * (0x1.13203d020406p-22 + x * 0x1.2f2db37f4d257p-25))))))))));
}
fp64 ord_12_exp_fp64(fp64 x) {
  return 0x1p0 + x * (0x1p0 + x * (0x1.0000000000004p-1 + x * (0x1.55555555551cep-3 + x * (0x1.5555555568cb6p-5 + x * (0x1.1111110d7c2e4p-7 + x * (0x1.6c16c238f3e12p-10 + x * (0x1.a019e3f9afe27p-13 + x * (0x1.a01ce03c16a19p-16 + x * (0x1.71ae4b09fb91bp-19 + x * (0x1.29f8b6412b3acp-22 + x * (0x1.913d565f90f2p-26 + x * 0x1.91f7f24f035bep-29)))))))))));
}
fp64 ord_13_exp_fp64(fp64 x) {
  return 0x1p0 + x * (0x1p0 + x * (0x1p-1 + x * (0x1.555555555555ap-3 + x * (0x1.5555555555239p-5 + x * (0x1.111111111eda3p-7 + x * (0x1.6c16c167d6036p-10 + x * (0x1.a01a02724d8d4p-13 + x * (0x1.a019e6ba583e1p-16 + x * (0x1.71e092161763ap-19 + x * (0x1.27c142f50972ep-22 + x * (0x1.b14001efcc1f3p-26 + x * (0x1.0c3bb13d6088ap-29 + x * 0x1.ebce490034a45p-33))))))))))));
}
fp64 rord_01_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_01_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_01_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_02_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_02_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_02_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_03_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_03_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_03_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_04_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_04_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_04_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_05_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_05_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_05_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_06_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_06_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_06_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_07_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_07_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_07_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_08_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_08_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_08_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_09_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_09_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_09_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_10_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_10_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_10_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_11_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_11_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_11_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_12_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_12_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_12_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
fp64 rord_13_exp_fp64(fp64 x) {
  if (x < LN2_fp64) {
    return ord_13_exp_fp64(x);
  }
  int N = (int) (x / LN2_fp64);
  fp64 whole = ((fp64) N) * LN2_fp64;
  fp64 t = x - whole;
  fp64 exp_t = ord_13_exp_fp64(t);
  fp64 recons = ldexp(exp_t, N);
  return recons;
}
