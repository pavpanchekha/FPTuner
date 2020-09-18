#include "ord_tan.h"
#include <math.h>
#include <stdlib.h>
//static const fp32 QPI_fp32 = 0.7853981634f;
static const fp64 QPI_fp64 = 0.7853981633974483096;
fp64 ord_01_tan_fp64(fp64 x) {
  return x * 0x1.1ec550f5b2e78p0;
}
fp64 ord_03_tan_fp64(fp64 x) {
  return x * (0x1.fb9c6f728b713p-1 + (x*x) * 0x1.c1b3ba1813616p-2);
}
fp64 ord_05_tan_fp64(fp64 x) {
  return x * (0x1.00284c828370cp0 + (x*x) * (0x1.4371edd8c8236p-2 + (x*x) * 0x1.9e71842ff043ep-3));
}
fp64 ord_07_tan_fp64(fp64 x) {
  return x * (0x1.fffa36bda9e73p-1 + (x*x) * (0x1.57a309901ca52p-2 + (x*x) * (0x1.db0983860e542p-4 + (x*x) * 0x1.818f120dfeab2p-4)));
}
fp64 ord_09_tan_fp64(fp64 x) {
  return x * (0x1.0000352c96f14p0 + (x*x) * (0x1.5512df47fd206p-2 + (x*x) * (0x1.17965964e2cd7p-3 + (x*x) * (0x1.4af1880dd1431p-5 + (x*x) * 0x1.66fa9c801c46p-5))));
}
fp64 ord_11_tan_fp64(fp64 x) {
  return x * (0x1.fffff85d507d8p-1 + (x*x) * (0x1.555c3949bd1cp-2 + (x*x) * (0x1.101264c0677acp-3 + (x*x) * (0x1.d48488a49bc41p-5 + (x*x) * (0x1.9a02086aa0eb9p-7 + (x*x) * 0x1.4e41cbeb435dap-6)))));
}
fp64 ord_13_tan_fp64(fp64 x) {
  return x * (0x1.000000462b7cdp0 + (x*x) * (0x1.5554a8a28b12p-2 + (x*x) * (0x1.11337280c5ef3p-3 + (x*x) * (0x1.b5093b5d414c8p-5 + (x*x) * (0x1.930f8b847f2cdp-6 + (x*x) * (0x1.7b8d63e32175ap-9 + (x*x) * 0x1.373d6e50c8f7p-7))))));
}
fp64 ord_15_tan_fp64(fp64 x) {
  return x * (0x1.fffffff5ec8eap-1 + (x*x) * (0x1.5555658ca3d9ap-2 + (x*x) * (0x1.110cd080ef75bp-3 + (x*x) * (0x1.baf33fb7d4c5dp-5 + (x*x) * (0x1.5bf38d58f825bp-6 + (x*x) * (0x1.663acb243fe1bp-7 + (x*x) * (-0x1.07c8b302435e1p-16 + (x*x) * 0x1.21cedbe703857p-8)))))));
}
fp64 ord_17_tan_fp64(fp64 x) {
  return x * (0x1.000000005c991p0 + (x*x) * (0x1.555553dbbf2c1p-2 + (x*x) * (0x1.11118f1b7accep-3 + (x*x) * (0x1.b9fb71d67aba8p-5 + (x*x) * (0x1.6859c523fc0ecp-6 + (x*x) * (0x1.100ed2e9f63a4p-7 + (x*x) * (0x1.4a80364d53482p-8 + (x*x) * (-0x1.50c11bfd0d47dp-11 + (x*x) * 0x1.0dda18365629ap-9))))))));
}
fp64 ord_19_tan_fp64(fp64 x) {
  return x * (0x1.fffffffff2b42p-1 + (x*x) * (0x1.55555576d3a81p-2 + (x*x) * (0x1.11110334bae9ap-3 + (x*x) * (0x1.ba200f1c4dac3p-5 + (x*x) * (0x1.65f3f4bac063fp-6 + (x*x) * (0x1.269e9f7502c5ep-7 + (x*x) * (0x1.9bbe09934c227p-9 + (x*x) * (0x1.3cd7fe442de0ep-9 + (x*x) * (-0x1.37c757079ec57p-11 + (x*x) * 0x1.f68a3d6134487p-11)))))))));
}
fp64 ord_21_tan_fp64(fp64 x) {
  return x * (0x1.00000000007a3p0 + (x*x) * (0x1.555555526c045p-2 + (x*x) * (0x1.11111287716ep-3 + (x*x) * (0x1.ba1b0fa4b74f9p-5 + (x*x) * (0x1.665dd38983803p-6 + (x*x) * (0x1.21976c72bd2f4p-7 + (x*x) * (0x1.e621f37170c16p-9 + (x*x) * (0x1.2543b30498cf9p-10 + (x*x) * (0x1.3aa0e1e0d2582p-10 + (x*x) * (-0x1.b2a1d861dc03bp-12 + (x*x) * 0x1.d3ef62d2c643ap-12))))))))));
}
fp64 ord_23_tan_fp64(fp64 x) {
  return x * (0x1.ffffffffffee7p-1 + (x*x) * (0x1.555555559510fp-2 + (x*x) * (0x1.111110eae1c8fp-3 + (x*x) * (0x1.ba1bb3963492bp-5 + (x*x) * (0x1.664d225b80749p-6 + (x*x) * (0x1.229510e93c461p-7 + (x*x) * (0x1.d35f236cffe31p-9 + (x*x) * (0x1.9747f32c73645p-10 + (x*x) * (0x1.70a262d78d9dp-12 + (x*x) * (0x1.4194dcd566764p-11 + (x*x) * (-0x1.0d8c83893da2dp-12 + (x*x) * 0x1.b3b7430c2614p-13)))))))))));
}
fp64 ord_25_tan_fp64(fp64 x) {
  return x * (0x1.000000000000ap0 + (x*x) * (0x1.555555554ff9cp-2 + (x*x) * (0x1.11111114d8795p-3 + (x*x) * (0x1.ba1b9fa3d09dcp-5 + (x*x) * (0x1.664f94e3f4607p-6 + (x*x) * (0x1.2267bd0d569a5p-7 + (x*x) * (0x1.d786f0e1dd65dp-9 + (x*x) * (0x1.773228bcbed32p-10 + (x*x) * (0x1.5d83efabba6d2p-11 + (x*x) * (0x1.462c8b23e786p-14 + (x*x) * (0x1.4fb2b84783111p-12 + (x*x) * (-0x1.3983d7fbe6673p-13 + (x*x) * 0x1.95b13fdb3e45bp-14))))))))))));
}
fp64 ord_27_tan_fp64(fp64 x) {
  return x * (0x1.fffffffffffffp-1 + (x*x) * (0x1.5555555555bcbp-2 + (x*x) * (0x1.11111110b881dp-3 + (x*x) * (0x1.ba1ba1f4293c2p-5 + (x*x) * (0x1.664f3eb1e1049p-6 + (x*x) * (0x1.226f320a20158p-7 + (x*x) * (0x1.d6b31b0cc5e2bp-9 + (x*x) * (0x1.7f10ce0ba1523p-10 + (x*x) * (0x1.2a532aaef8a12p-11 + (x*x) * (0x1.35fd879c69b07p-12 + (x*x) * (-0x1.0767f1568749fp-17 + (x*x) * (0x1.6234c02234092p-13 + (x*x) * (-0x1.5ceef50f12748p-14 + (x*x) * 0x1.792783aa8401cp-15)))))))))))));
}
fp64 ord_29_tan_fp64(fp64 x) {
  return x * (0x1p0 + (x*x) * (0x1.55555555554eep-2 + (x*x) * (0x1.11111111185b7p-3 + (x*x) * (0x1.ba1ba1b451c22p-5 + (x*x) * (0x1.664f49ac36a85p-6 + (x*x) * (0x1.226e120338654p-7 + (x*x) * (0x1.d6d93e092380ep-9 + (x*x) * (0x1.7d5af153199bap-10 + (x*x) * (0x1.37fd9b4734dcdp-11 + (x*x) * (0x1.d250fec11d944p-13 + (x*x) * (0x1.1e6348ba5d404p-13 + (x*x) * (-0x1.bb44c6a9620f4p-16 + (x*x) * (0x1.7746f4823514ap-14 + (x*x) * (-0x1.788095be2ad32p-15 + (x*x) * 0x1.5e089a24c1bf9p-16))))))))))))));
}
fp64 ord_33_tan_fp64(fp64 x) {
  return x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.11111111111b7p-3 + (x*x) * (0x1.ba1ba1ba0f823p-5 + (x*x) * (0x1.664f488629717p-6 + (x*x) * (0x1.226e34cfc9f3bp-7 + (x*x) * (0x1.d6d3eee73f293p-9 + (x*x) * (0x1.7da13af045688p-10 + (x*x) * (0x1.357476ae291cdp-11 + (x*x) * (0x1.f36166c9c3ad5p-13 + (x*x) * (0x1.a550c0b3628e5p-14 + (x*x) * (0x1.f90e5606c7c1bp-16 + (x*x) * (0x1.18104a24799b8p-15 + (x*x) * (-0x1.2468c39ec25a7p-16 + (x*x) * (0x1.a4d56cd69e877p-16 + (x*x) * (-0x1.9c52ed5db4591p-17 + (x*x) * 0x1.2c6d10068e72ap-18))))))))))))))));
}
fp64 ord_35_tan_fp64(fp64 x) {
  return x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.1111111111169p-3 + (x*x) * (0x1.ba1ba1ba175cep-5 + (x*x) * (0x1.664f48839e948p-6 + (x*x) * (0x1.226e3543a31e4p-7 + (x*x) * (0x1.d6d3d4fcce7b5p-9 + (x*x) * (0x1.7da330cf3f63cp-10 + (x*x) * (0x1.35599e010fc92p-11 + (x*x) * (0x1.f577dd394edap-13 + (x*x) * (0x1.95f85a8a582cap-14 + (x*x) * (0x1.505357314658p-15 + (x*x) * (0x1.ba6f958f2bfe9p-17 + (x*x) * (0x1.a057a3159e979p-17 + (x*x) * (-0x1.9f407d243069dp-18 + (x*x) * (0x1.46a42e08dea67p-17 + (x*x) * (-0x1.469b68a0846adp-18 + (x*x) * 0x1.e45f3b554fe6cp-20)))))))))))))))));
}
fp64 ord_31_tan_fp64(fp64 x) {
  return x * (0x1p0 + (x*x) * (0x1.555555555555ep-2 + (x*x) * (0x1.1111111110606p-3 + (x*x) * (0x1.ba1ba1babaeaep-5 + (x*x) * (0x1.664f485e453afp-6 + (x*x) * (0x1.226e3a58401d2p-7 + (x*x) * (0x1.d6d2eefbebddcp-9 + (x*x) * (0x1.7db1209991f3p-10 + (x*x) * (0x1.34c09e2794fdep-11 + (x*x) * (0x1.feeba2048bc07p-13 + (x*x) * (0x1.5fda7ade94d81p-14 + (x*x) * (0x1.175f7ba801eb2p-14 + (x*x) * (-0x1.a0c409f0f1562p-16 + (x*x) * (0x1.9256dae22e26dp-15 + (x*x) * (-0x1.9190f7f937ae1p-16 + (x*x) * 0x1.463cb4a057d5ap-17)))))))))))))));
}
fp64 ord_37_tan_fp64(fp64 x) {
  return x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.111111111117cp-3 + (x*x) * (0x1.ba1ba1ba15339p-5 + (x*x) * (0x1.664f48846912fp-6 + (x*x) * (0x1.226e351ace16ap-7 + (x*x) * (0x1.d6d3df5eb9e5ap-9 + (x*x) * (0x1.7da24b354d9dbp-10 + (x*x) * (0x1.3567bae8c2876p-11 + (x*x) * (0x1.f4325dfc987a1p-13 + (x*x) * (0x1.a0e9e5cd59317p-14 + (x*x) * (0x1.0958ef404f6dfp-15 + (x*x) * (0x1.1c6239b67878cp-15 + (x*x) * (-0x1.ae3dc88aa36fap-16 + (x*x) * (0x1.7cf498e2ae9c7p-15 + (x*x) * (-0x1.5292446849c2fp-15 + (x*x) * (0x1.d6beea807e0dep-16 + (x*x) * (-0x1.7bb614143cae3p-17 + (x*x) * 0x1.41348efeafe74p-19))))))))))))))))));
}
fp64 rord_01_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_01_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_03_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_03_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_05_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_05_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_07_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_07_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_09_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_09_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_11_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_11_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_13_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_13_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_15_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_15_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_17_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_17_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_19_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_19_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_21_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_21_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_23_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_23_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_25_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_25_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_27_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_27_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_29_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_29_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_33_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_33_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_35_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_35_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_31_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_31_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
fp64 rord_37_tan_fp64(fp64 x) {
  int sign = signbit(x);
  fp64 abs_x = fabs(x);
  int k = (int) (abs_x / QPI_fp64);
  fp64 whole = ((fp64) k) * QPI_fp64;
  fp64 y = abs_x - whole;
  int part = k % 4;
  fp64 z;
  switch (part) {
    case 0:
      z = y;
      break;
    case 1:
      z = QPI_fp64 - y;
      break;
    case 2:
      z = -y;
      break;
    case 3:
      z = y - QPI_fp64;
      break;
    default:
      exit(3);
  }
  fp64 result = ord_37_tan_fp64(z);
  if (part == 1 || part == 2) {
    result = 1 / result;
  }
  result *= sign ? -1.0 : 1.0;
  return result;
}
