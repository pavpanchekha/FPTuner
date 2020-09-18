#include "ord_log.h"
#include <math.h>
//static const fp32 LN2_fp32 = 0.69314718056f;
static const fp64 LN2_fp64 = 0.6931471805599453094;
fp64 ord_01_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * 0x1.e71dd1b88fb15p-1;
}
fp64 ord_02_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.04414d73ff066p0 + x * (-0x1.c69e30a238347p-2));
}
fp64 ord_03_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.00875c5c3fd09p0 + x * (-0x1.076a520848a3p-1 + x * 0x1.17661f030dadfp-2));
}
fp64 ord_04_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.fff11fb825e36p-1 + x * (-0x1.01f2241a4d929p-1 + x * (0x1.60ee7544f578fp-2 + x * (-0x1.8134291fa62eap-3))));
}
fp64 ord_05_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.fff9485b18ba8p-1 + x * (-0x1.fffaf74e7515ep-2 + x * (0x1.5a9de204e2945p-2 + x * (-0x1.081e143b35606p-2 + x * 0x1.1ad2f6191cce7p-3))));
}
fp64 ord_06_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.ffffaae7bfa92p-1 + x * (-0x1.ffdfe9944133ep-2 + x * (0x1.5594c61187478p-2 + x * (-0x1.0647f1f38a60dp-2 + x * (0x1.a2f9ce1871466p-3 + x * (-0x1.b0400168960b7p-4))))));
}
fp64 ord_07_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.00000ed5775dfp0 + x * (-0x1.fffc691eda987p-2 + x * (0x1.5523de5095222p-2 + x * (-0x1.00a3540783fc7p-2 + x * (0x1.a76da54dab995p-3 + x * (-0x1.5835dea30859cp-3 + x * 0x1.5391d1d133737p-4))))));
}
fp64 ord_08_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.00000277a3995p0 + x * (-0x1.0000483b26916p-1 + x * (0x1.554bfa694bc1ep-2 + x * (-0x1.ff86514ed85d8p-3 + x * (0x1.9bd001b125f6dp-3 + x * (-0x1.63c879f54bbf6p-3 + x * (0x1.216bad4624d96p-3 + x * (-0x1.1038fe0533126p-4))))))));
}
fp64 ord_09_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.ffffffcdb4d65p-1 + x * (-0x1.00001647a5d36p-1 + x * (0x1.555603017baa7p-2 + x * (-0x1.ffdc71d7100f5p-3 + x * (0x1.991b504858421p-3 + x * (-0x1.588fd96caf76fp-3 + x * (0x1.33165a4f25a4bp-3 + x * (-0x1.eea99afb8a5aep-4 + x * 0x1.bb489507706c9p-5))))))));
}
fp64 ord_10_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.ffffffdc5763ap-1 + x * (-0x1.00000064ca43dp-1 + x * (0x1.5555c627b7562p-2 + x * (-0x1.000032e9f3e2dp-2 + x * (0x1.9961484262119p-3 + x * (-0x1.54e7f53e09485p-3 + x * (0x1.28d5210324ba2p-3 + x * (-0x1.0e1ce11068d52p-3 + x * (0x1.abc387aa4421p-4 + x * (-0x1.6d5d2d71258a5p-5))))))))));
}
fp64 ord_11_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.fffffffd851c5p-1 + x * (-0x1.fffffec0eda8dp-2 + x * (0x1.55555d7be3527p-2 + x * (-0x1.0000d3dd385bdp-2 + x * (0x1.99972c1322635p-3 + x * (-0x1.5506549bf20b1p-3 + x * (0x1.244c7d698b74p-3 + x * (-0x1.0542861929a3cp-3 + x * (0x1.e1c0539af8c2fp-4 + x * (-0x1.753cb52d15ca4p-4 + x * 0x1.3024426d83735p-5))))))))));
}
fp64 ord_12_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.0000000050779p0 + x * (-0x1.ffffffd544fdap-2 + x * (0x1.555552527198ap-2 + x * (-0x1.00001bde91a79p-2 + x * (0x1.999c263f7c1dfp-3 + x * (-0x1.554db7c0cb4edp-3 + x * (0x1.242ceeb1866c3p-3 + x * (-0x1.ffefd4ef0e4c6p-4 + x * (0x1.d37bae8cdeef4p-4 + x * (-0x1.b204cd50ce523p-4 + x * (0x1.47edabfb72d65p-4 + x * (-0x1.fe85c3a71e64cp-6))))))))))));
}
fp64 ord_13_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.0000000010861p0 + x * (-0x1.000000024e0bp-1 + x * (0x1.555554aacae31p-2 + x * (-0x1.fffff6115bb58p-3 + x * (0x1.999a1db017198p-3 + x * (-0x1.5558b15af5febp-3 + x * (0x1.2482dd99fa186p-3 + x * (-0x1.ff0dccb99fd69p-4 + x * (0x1.c7b06b279bcebp-4 + x * (-0x1.a79f0c01259a9p-4 + x * (0x1.8a0d609a60772p-4 + x * (-0x1.21b55ad4f3d99p-4 + x * 0x1.af6f347892058p-6))))))))))));
}
fp64 ord_14_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.ffffffffff67ap-1 + x * (-0x1.00000000e6a3p-1 + x * (0x1.5555555ad2dfep-2 + x * (-0x1.fffffc61c41f3p-3 + x * (0x1.99998e7c70243p-3 + x * (-0x1.5556537045163p-3 + x * (0x1.24961b8a409cap-3 + x * (-0x1.ffcc5275061ffp-4 + x * (0x1.c60c29f344d13p-4 + x * (-0x1.9af52c4c96c38p-4 + x * (0x1.83ca439111d07p-4 + x * (-0x1.67e513cc61652p-4 + x * (0x1.0114bf576afe9p-4 + x * (-0x1.6ebe9d9738754p-6))))))))))))));
}
fp64 ord_15_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.ffffffffff15bp-1 + x * (-0x1.0000000008ecfp-1 + x * (0x1.5555555bdccf9p-2 + x * (-0x1.ffffffe7fff9fp-3 + x * (0x1.999991e6cf2fcp-3 + x * (-0x1.555550c40fb82p-3 + x * (0x1.2493f19164285p-3 + x * (-0x1.0003a511f0ec5p-3 + x * (0x1.c6cf31df18116p-4 + x * (-0x1.98784b534ddc1p-4 + x * (0x1.769d5e6fa3e0cp-4 + x * (-0x1.65e4d71996104p-4 + x * (0x1.4a361dd9d750ap-4 + x * (-0x1.c9eae4dc7c5bcp-5 + x * 0x1.39560bdc1d94bp-6))))))))))))));
}
fp64 ord_16_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.ffffffffffeadp-1 + x * (-0x1.fffffffff4598p-2 + x * (0x1.55555555f391bp-2 + x * (-0x1.00000010604c8p-2 + x * (0x1.999998fb6411bp-3 + x * (-0x1.5555479a87ecap-3 + x * (0x1.2492594df659bp-3 + x * (-0x1.00027dd4ab94ap-3 + x * (0x1.c72185e8b6895p-4 + x * (-0x1.992ef7ad84774p-4 + x * (0x1.733abd69b0defp-4 + x * (-0x1.589074655d3ffp-4 + x * (0x1.4c7c3bd8af2cp-4 + x * (-0x1.30103a1c69b5ep-4 + x * (0x1.990f09128f039p-5 + x * (-0x1.0ce39cde344fdp-6))))))))))))))));
}
fp64 ord_17_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.000000000001fp0 + x * (-0x1.fffffffffe228p-2 + x * (0x1.55555555307a3p-2 + x * (-0x1.000000029cafep-2 + x * (0x1.999999d888d11p-3 + x * (-0x1.55555370c5129p-3 + x * (0x1.249233e36c242p-3 + x * (-0x1.00003a2dc7036p-3 + x * (0x1.c723531d427b5p-4 + x * (-0x1.999a19fa9a024p-4 + x * (0x1.73d2884519385p-4 + x * (-0x1.5443f93bb0272p-4 + x * (0x1.3f587166de619p-4 + x * (-0x1.368952f0d8394p-4 + x * (0x1.18c72bef9c79cp-4 + x * (-0x1.6e5ab5de83d5bp-5 + x * 0x1.cf4fd5be4d2ep-7))))))))))))))));
}
fp64 ord_18_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1.0000000000008p0 + x * (-0x1.000000000010dp-1 + x * (0x1.555555554b7e3p-2 + x * (-0x1.ffffffff73be7p-3 + x * (0x1.999999a92a004p-3 + x * (-0x1.555555b434a8fp-3 + x * (0x1.249244c418454p-3 + x * (-0x1.ffffc60bd8452p-4 + x * (0x1.c71d735d7a4fap-4 + x * (-0x1.99a270530b619p-4 + x * (0x1.74562f5b033fp-4 + x * (-0x1.54a9b3f1cddeap-4 + x * (0x1.3a2714323183ap-4 + x * (-0x1.29e9d00d7a808p-4 + x * (0x1.234c99864e167p-4 + x * (-0x1.03d4d15913845p-4 + x * (0x1.48c219b24960ap-5 + x * (-0x1.906acae45f0c3p-7))))))))))))))))));
}
fp64 ord_19_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1p0 + x * (-0x1.000000000009p-1 + x * (0x1.555555555560ap-2 + x * (-0x1.ffffffffbc645p-3 + x * (0x1.999999991f6d7p-3 + x * (-0x1.55555579e7ac7p-3 + x * (0x1.2492498ef0905p-3 + x * (-0x1.ffffef117b09cp-4 + x * (0x1.c71c2c637f2a7p-4 + x * (-0x1.999b69d8fdfc6p-4 + x * (0x1.7467b5d91da02p-4 + x * (-0x1.5544172b650cap-4 + x * (0x1.3a47e525d03e8p-4 + x * (-0x1.23dda5af5e323p-4 + x * (0x1.17795625669dep-4 + x * (-0x1.12379b4c0d1f6p-4 + x * (0x1.e1d27bf588d2bp-5 + x * (-0x1.27b47db1b0329p-5 + x * 0x1.5b63d729fc5cbp-7))))))))))))))))));
}
fp64 ord_20_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1p0 + x * (-0x1.0000000000009p-1 + x * (0x1.55555555558f8p-2 + x * (-0x1.fffffffffbf89p-3 + x * (0x1.9999999903615p-3 + x * (-0x1.55555556c2193p-3 + x * (0x1.2492496761302p-3 + x * (-0x1.000000173e2cep-3 + x * (0x1.c71c55f4f62ddp-4 + x * (-0x1.99995cbcbd9d5p-4 + x * (0x1.745ff85fb6c68p-4 + x * (-0x1.556097226f684p-4 + x * (0x1.3af3f4adeb296p-4 + x * (-0x1.23ae18be3bbf4p-4 + x * (0x1.10bb703c0b477p-4 + x * (-0x1.0777e6e7f2da4p-4 + x * (0x1.028b23552952dp-4 + x * (-0x1.bde9116547b3ap-5 + x * (0x1.091c37124a34dp-5 + x * (-0x1.2c7139c57295p-7))))))))))))))))))));
}
fp64 ord_21_log_fp64(fp64 xin) {
  fp64 x = xin - 1.0;
  return x * (0x1p0 + x * (-0x1.ffffffffffff9p-2 + x * (0x1.55555555555bep-2 + x * (-0x1.000000000106p-2 + x * (0x1.999999998a986p-3 + x * (-0x1.55555553da313p-3 + x * (0x1.24924929547adp-3 + x * (-0x1.0000007ecb612p-3 + x * (0x1.c71c713e75d35p-4 + x * (-0x1.99996ce94a14ap-4 + x * (0x1.745cd92c4d73cp-4 + x * (-0x1.5559862a2db63p-4 + x * (0x1.3b20a0fd19f08p-4 + x * (-0x1.2464e750c6d15p-4 + x * (0x1.100d19ea26a16p-4 + x * (-0x1.ffcb70b93622dp-5 + x * (0x1.f29c8f6d920dbp-5 + x * (-0x1.ea33ab528da99p-5 + x * (0x1.a0f36c050a231p-5 + x * (-0x1.e33e418aeaa62p-6 + x * 0x1.099ffb25408d9p-7))))))))))))))))))));
}
fp64 rord_01_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_01_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_02_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_02_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_03_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_03_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_04_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_04_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_05_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_05_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_06_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_06_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_07_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_07_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_08_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_08_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_09_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_09_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_10_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_10_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_11_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_11_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_12_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_12_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_13_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_13_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_14_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_14_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_15_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_15_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_16_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_16_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_17_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_17_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_18_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_18_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_19_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_19_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_20_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_20_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
fp64 rord_21_log_fp64(fp64 x) {
  int n;
  fp64 f = frexp(x, &n);
  fp64 log_f = ord_21_log_fp64(f);
  fp64 recons = n*LN2_fp64 + log_f;
  return recons;
}
