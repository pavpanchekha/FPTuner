/**
 * generated using metalibm 1.1
 * sha1 git: b'"ac97294a9b850112cf27d1abe41cf7c601a3bf06"'(clean)
 * 
 * INFO: git status was clean when file was generated.
 * 
 * command used for generation:
 *   metalibm_functions/ml_sin.py --fuse-fma --target x86_sse42 --precision \
 *     binary32 --output mlm_16_sin_fp32.c --fname mlm_16_sin_fp32 --accuracy \
 *     dar(0.0078125)
 * 
**/
#include <emmintrin.h>
#include <support_lib/ml_utils.h>
#include <fenv.h>
#include <xmmintrin.h>
#include <math.h>
#include <support_lib/ml_special_values.h>
#include <inttypes.h>


static const __m128i mlm_16_sin_fp32_cst = {INT32_C(23)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst1 = {INT32_C(255)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst2 = {INT32_C(255)}/*sse*/;
static const __m128 mlm_16_sin_fp32_cst3 = {__builtin_nanf("")}/*sse*/;
static const __m128 mlm_16_sin_fp32_cst4 = {0x1p10f}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst5 = {INT32_C(8)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst6 = {INT32_C(-127)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst7 = {INT32_C(23)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst8 = {INT32_C(255)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst9 = {INT32_C(100)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst10 = {INT32_C(4)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst11 = {INT32_C(10)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst12 = {INT32_C(1)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst13 = {INT32_C(23)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst14 = {INT32_C(10)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst15 = {INT32_C(0)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst16 = {INT32_C(-5792)}/*sse*/;
static const __m128 mlm_16_sin_fp32_cst17 = {0.0f}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst18 = {INT32_C(0)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst19 = {INT32_C(1)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst20 = {INT32_C(10)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst21 = {INT32_C(-12)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst22 = {INT32_C(10)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst23 = {INT32_C(0)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst24 = {INT32_C(0)}/*sse*/;
static const __m128 mlm_16_sin_fp32_cst25 = {0.0f}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst26 = {INT32_C(0)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst27 = {INT32_C(2048)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst28 = {INT32_C(1)}/*sse*/;
static const __m128 mlm_16_sin_fp32_cst29 = {0x1.921fcp-9f}/*sse*/;
static const __m128 mlm_16_sin_fp32_cst30 = {-0x1.5777a6p-30f}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst31 = {INT32_C(1536)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst32 = {INT32_C(0)}/*sse*/;
static const __m128i mlm_16_sin_fp32_C32 = {INT32_C(2048)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst33 = {INT32_C(2047)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst34 = {INT32_C(1536)}/*sse*/;
static const __m128 mlm_16_sin_fp32_cst35 = {0x1.45f3p8f}/*sse*/;
static const __m128 mlm_16_sin_fp32_cst36 = {0x1.b72722p-14f}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst37 = {INT32_C(2047)}/*sse*/;
static const __m128 mlm_16_sin_fp32_inv_frac_pi = {0x1.921fcp-9f}/*sse*/;
static const __m128 mlm_16_sin_fp32_inv_frac_pi_lo = {-0x1.5777a6p-30f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_1 = {0x1.217cp-81f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_2 = {-0x1p-1f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_3 = {-0x1.4d707cp-60f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_4 = {0x1.555556p-5f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_5 = {0x1.11986ap-41f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_6 = {-0x1.018046p-9f}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst38 = {INT32_C(0)}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_21 = {0x1.b29e54p-67f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_31 = {-0x1.555556p-3f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_41 = {-0x1.29d2b4p-47f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_51 = {0x1.5debbp-7f}/*sse*/;
static const __m128 mlm_16_sin_fp32_c_61 = {0x1.005c7p-30f}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst39 = {INT32_C(512)}/*sse*/;
static const __m128i mlm_16_sin_fp32_cst40 = {INT32_C(2048)}/*sse*/;
static const float PH_scale_table[18][1]  = {
    { 0x1p0f},
    { 0x1.306fep-5f},
    { 0x1.6a09e6p-10f},
    { 0x1.ae89fap-15f},
    { 0x1p-19f},
    { 0x1.306fep-24f},
    { 0x1.6a09e6p-29f},
    { 0x1.ae89fap-34f},
    { 0x1p-38f},
    { 0x1.306fep-43f},
    { 0x1.6a09e6p-48f},
    { 0x1.ae89fap-53f},
    { 0x1p-57f},
    { 0x1.306fep-62f},
    { 0x1.6a09e6p-67f},
    { 0x1.ae89fap-72f},
    { 0x1p-76f},
    { 0x1.306fep-81f}
};
static const float PH_cst_table[18][1]  = {
    { 0x1.45f9eap8f},
    { -0x1.372082p4f},
    { -0x1.8bfad4p4f},
    { -0x1.6a09e6p-1f},
    { 0x1.3b5eap6f},
    { -0x1.e67d4ep6f},
    { 0x1.728622p5f},
    { -0x1.21e9eep6f},
    { -0x1.6a09e6p-1f},
    { -0x1.e3a93ap5f},
    { 0x1.f775c4p4f},
    { -0x1.f775c4p4f},
    { 0x1.5d4f8ep6f},
    { -0x1.cb9e92p6f},
    { -0x1.c48c6p1f},
    { 0x1.b4fdf4p6f},
    { -0x1.070b32p5f},
    { 0x1.0f876cp1f}
};
static const float mlm_16_sin_fp32_cos_table[2048][1]  = {
    { 0x1p0f},
    { 0x1.ffff62p-1f},
    { 0x1.fffd88p-1f},
    { 0x1.fffa72p-1f},
    { 0x1.fff622p-1f},
    { 0x1.fff094p-1f},
    { 0x1.ffe9ccp-1f},
    { 0x1.ffe1c6p-1f},
    { 0x1.ffd886p-1f},
    { 0x1.ffce0ap-1f},
    { 0x1.ffc252p-1f},
    { 0x1.ffb55ep-1f},
    { 0x1.ffa72ep-1f},
    { 0x1.ff97c4p-1f},
    { 0x1.ff871ep-1f},
    { 0x1.ff753cp-1f},
    { 0x1.ff621ep-1f},
    { 0x1.ff4dc6p-1f},
    { 0x1.ff383p-1f},
    { 0x1.ff2162p-1f},
    { 0x1.ff0956p-1f},
    { 0x1.fef01p-1f},
    { 0x1.fed58ep-1f},
    { 0x1.feb9d2p-1f},
    { 0x1.fe9cdap-1f},
    { 0x1.fe7ea8p-1f},
    { 0x1.fe5f3ap-1f},
    { 0x1.fe3e92p-1f},
    { 0x1.fe1cbp-1f},
    { 0x1.fdf992p-1f},
    { 0x1.fdd53ap-1f},
    { 0x1.fdafa8p-1f},
    { 0x1.fd88dap-1f},
    { 0x1.fd60d2p-1f},
    { 0x1.fd3792p-1f},
    { 0x1.fd0d16p-1f},
    { 0x1.fce16p-1f},
    { 0x1.fcb47p-1f},
    { 0x1.fc8646p-1f},
    { 0x1.fc56e4p-1f},
    { 0x1.fc2648p-1f},
    { 0x1.fbf47p-1f},
    { 0x1.fbc162p-1f},
    { 0x1.fb8d18p-1f},
    { 0x1.fb5798p-1f},
    { 0x1.fb20dcp-1f},
    { 0x1.fae8e8p-1f},
    { 0x1.faafbcp-1f},
    { 0x1.fa7558p-1f},
    { 0x1.fa39bap-1f},
    { 0x1.f9fce6p-1f},
    { 0x1.f9bed8p-1f},
    { 0x1.f97f92p-1f},
    { 0x1.f93f14p-1f},
    { 0x1.f8fd6p-1f},
    { 0x1.f8ba74p-1f},
    { 0x1.f8765p-1f},
    { 0x1.f830f4p-1f},
    { 0x1.f7ea62p-1f},
    { 0x1.f7a29ap-1f},
    { 0x1.f7599ap-1f},
    { 0x1.f70f64p-1f},
    { 0x1.f6c3f8p-1f},
    { 0x1.f67756p-1f},
    { 0x1.f6297cp-1f},
    { 0x1.f5da6ep-1f},
    { 0x1.f58a2cp-1f},
    { 0x1.f538b2p-1f},
    { 0x1.f4e604p-1f},
    { 0x1.f4922p-1f},
    { 0x1.f43d08p-1f},
    { 0x1.f3e6bcp-1f},
    { 0x1.f38f3ap-1f},
    { 0x1.f33686p-1f},
    { 0x1.f2dc9cp-1f},
    { 0x1.f2818p-1f},
    { 0x1.f2253p-1f},
    { 0x1.f1c7acp-1f},
    { 0x1.f168f6p-1f},
    { 0x1.f1090cp-1f},
    { 0x1.f0a7fp-1f},
    { 0x1.f045a2p-1f},
    { 0x1.efe22p-1f},
    { 0x1.ef7d6ep-1f},
    { 0x1.ef178ap-1f},
    { 0x1.eeb074p-1f},
    { 0x1.ee482ep-1f},
    { 0x1.eddeb6p-1f},
    { 0x1.ed740ep-1f},
    { 0x1.ed0836p-1f},
    { 0x1.ec9b2ep-1f},
    { 0x1.ec2cf4p-1f},
    { 0x1.ebbd8cp-1f},
    { 0x1.eb4cf6p-1f},
    { 0x1.eadb2ep-1f},
    { 0x1.ea683ap-1f},
    { 0x1.e9f416p-1f},
    { 0x1.e97ec4p-1f},
    { 0x1.e90844p-1f},
    { 0x1.e89096p-1f},
    { 0x1.e817bap-1f},
    { 0x1.e79db2p-1f},
    { 0x1.e7227ep-1f},
    { 0x1.e6a61cp-1f},
    { 0x1.e6288ep-1f},
    { 0x1.e5a9d6p-1f},
    { 0x1.e529fp-1f},
    { 0x1.e4a8ep-1f},
    { 0x1.e426a4p-1f},
    { 0x1.e3a33ep-1f},
    { 0x1.e31eaep-1f},
    { 0x1.e298f4p-1f},
    { 0x1.e2121p-1f},
    { 0x1.e18a02p-1f},
    { 0x1.e100ccp-1f},
    { 0x1.e0766ep-1f},
    { 0x1.dfeae6p-1f},
    { 0x1.df5e36p-1f},
    { 0x1.ded06p-1f},
    { 0x1.de416p-1f},
    { 0x1.ddb13cp-1f},
    { 0x1.dd1ffp-1f},
    { 0x1.dc8d7cp-1f},
    { 0x1.dbf9e4p-1f},
    { 0x1.db6526p-1f},
    { 0x1.dacf42p-1f},
    { 0x1.da383ap-1f},
    { 0x1.d9a00ep-1f},
    { 0x1.d906bcp-1f},
    { 0x1.d86c48p-1f},
    { 0x1.d7d0bp-1f},
    { 0x1.d733f6p-1f},
    { 0x1.d69618p-1f},
    { 0x1.d5f718p-1f},
    { 0x1.d556f6p-1f},
    { 0x1.d4b5b2p-1f},
    { 0x1.d4134ep-1f},
    { 0x1.d36fc8p-1f},
    { 0x1.d2cb22p-1f},
    { 0x1.d2255cp-1f},
    { 0x1.d17e78p-1f},
    { 0x1.d0d672p-1f},
    { 0x1.d02d5p-1f},
    { 0x1.cf830ep-1f},
    { 0x1.ced7bp-1f},
    { 0x1.ce2b32p-1f},
    { 0x1.cd7d98p-1f},
    { 0x1.cccee2p-1f},
    { 0x1.cc1f1p-1f},
    { 0x1.cb6e2p-1f},
    { 0x1.cabc16p-1f},
    { 0x1.ca08f2p-1f},
    { 0x1.c954b2p-1f},
    { 0x1.c89f58p-1f},
    { 0x1.c7e8e6p-1f},
    { 0x1.c73158p-1f},
    { 0x1.c678b4p-1f},
    { 0x1.c5bef6p-1f},
    { 0x1.c5042p-1f},
    { 0x1.c44834p-1f},
    { 0x1.c38b3p-1f},
    { 0x1.c2cd14p-1f},
    { 0x1.c20de4p-1f},
    { 0x1.c14d9ep-1f},
    { 0x1.c08c42p-1f},
    { 0x1.bfc9d2p-1f},
    { 0x1.bf064ep-1f},
    { 0x1.be41b6p-1f},
    { 0x1.bd7c0ap-1f},
    { 0x1.bcb54cp-1f},
    { 0x1.bbed7cp-1f},
    { 0x1.bb249ap-1f},
    { 0x1.ba5aa6p-1f},
    { 0x1.b98fa2p-1f},
    { 0x1.b8c38ep-1f},
    { 0x1.b7f668p-1f},
    { 0x1.b72834p-1f},
    { 0x1.b658f2p-1f},
    { 0x1.b588ap-1f},
    { 0x1.b4b74p-1f},
    { 0x1.b3e4d4p-1f},
    { 0x1.b3115ap-1f},
    { 0x1.b23cd4p-1f},
    { 0x1.b16742p-1f},
    { 0x1.b090a6p-1f},
    { 0x1.afb8fep-1f},
    { 0x1.aee04cp-1f},
    { 0x1.ae069p-1f},
    { 0x1.ad2bcap-1f},
    { 0x1.ac4ffcp-1f},
    { 0x1.ab7326p-1f},
    { 0x1.aa9548p-1f},
    { 0x1.a9b662p-1f},
    { 0x1.a8d676p-1f},
    { 0x1.a7f586p-1f},
    { 0x1.a7138ep-1f},
    { 0x1.a63092p-1f},
    { 0x1.a54c92p-1f},
    { 0x1.a4678cp-1f},
    { 0x1.a38184p-1f},
    { 0x1.a29a7ap-1f},
    { 0x1.a1b26ep-1f},
    { 0x1.a0c95ep-1f},
    { 0x1.9fdf5p-1f},
    { 0x1.9ef43ep-1f},
    { 0x1.9e082ep-1f},
    { 0x1.9d1b2p-1f},
    { 0x1.9c2d12p-1f},
    { 0x1.9b3e04p-1f},
    { 0x1.9a4dfap-1f},
    { 0x1.995cf2p-1f},
    { 0x1.986afp-1f},
    { 0x1.9777fp-1f},
    { 0x1.9683f4p-1f},
    { 0x1.958efep-1f},
    { 0x1.94990ep-1f},
    { 0x1.93a224p-1f},
    { 0x1.92aa42p-1f},
    { 0x1.91b166p-1f},
    { 0x1.90b794p-1f},
    { 0x1.8fbccap-1f},
    { 0x1.8ec10ap-1f},
    { 0x1.8dc454p-1f},
    { 0x1.8cc6a8p-1f},
    { 0x1.8bc806p-1f},
    { 0x1.8ac872p-1f},
    { 0x1.89c7eap-1f},
    { 0x1.88c66ep-1f},
    { 0x1.87c4p-1f},
    { 0x1.86c0a2p-1f},
    { 0x1.85bc52p-1f},
    { 0x1.84b712p-1f},
    { 0x1.83b0ep-1f},
    { 0x1.82a9c2p-1f},
    { 0x1.81a1b4p-1f},
    { 0x1.8098b8p-1f},
    { 0x1.7f8ecep-1f},
    { 0x1.7e83f8p-1f},
    { 0x1.7d7836p-1f},
    { 0x1.7c6b8ap-1f},
    { 0x1.7b5df2p-1f},
    { 0x1.7a4f7p-1f},
    { 0x1.794006p-1f},
    { 0x1.782fb2p-1f},
    { 0x1.771e76p-1f},
    { 0x1.760c52p-1f},
    { 0x1.74f948p-1f},
    { 0x1.73e558p-1f},
    { 0x1.72d084p-1f},
    { 0x1.71bacap-1f},
    { 0x1.70a42cp-1f},
    { 0x1.6f8caap-1f},
    { 0x1.6e7446p-1f},
    { 0x1.6d5afep-1f},
    { 0x1.6c40d8p-1f},
    { 0x1.6b25cep-1f},
    { 0x1.6a09e6p-1f},
    { 0x1.68ed1ep-1f},
    { 0x1.67cf78p-1f},
    { 0x1.66b0f4p-1f},
    { 0x1.659192p-1f},
    { 0x1.647154p-1f},
    { 0x1.63503ap-1f},
    { 0x1.622e44p-1f},
    { 0x1.610b76p-1f},
    { 0x1.5fe7ccp-1f},
    { 0x1.5ec34ap-1f},
    { 0x1.5d9deep-1f},
    { 0x1.5c77bcp-1f},
    { 0x1.5b50b2p-1f},
    { 0x1.5a28d2p-1f},
    { 0x1.59001ep-1f},
    { 0x1.57d694p-1f},
    { 0x1.56ac36p-1f},
    { 0x1.558104p-1f},
    { 0x1.5455p-1f},
    { 0x1.53282ap-1f},
    { 0x1.51fa82p-1f},
    { 0x1.50cc0ap-1f},
    { 0x1.4f9cc2p-1f},
    { 0x1.4e6cacp-1f},
    { 0x1.4d3bc6p-1f},
    { 0x1.4c0a14p-1f},
    { 0x1.4ad796p-1f},
    { 0x1.49a44ap-1f},
    { 0x1.487034p-1f},
    { 0x1.473b52p-1f},
    { 0x1.4605a6p-1f},
    { 0x1.44cf32p-1f},
    { 0x1.4397f6p-1f},
    { 0x1.425ff2p-1f},
    { 0x1.412726p-1f},
    { 0x1.3fed96p-1f},
    { 0x1.3eb33ep-1f},
    { 0x1.3d7824p-1f},
    { 0x1.3c3c44p-1f},
    { 0x1.3affa2p-1f},
    { 0x1.39c23ep-1f},
    { 0x1.388418p-1f},
    { 0x1.374532p-1f},
    { 0x1.36058cp-1f},
    { 0x1.34c526p-1f},
    { 0x1.3384p-1f},
    { 0x1.32421ep-1f},
    { 0x1.30ff8p-1f},
    { 0x1.2fbc24p-1f},
    { 0x1.2e780ep-1f},
    { 0x1.2d333ep-1f},
    { 0x1.2bedb2p-1f},
    { 0x1.2aa76ep-1f},
    { 0x1.296072p-1f},
    { 0x1.2818bep-1f},
    { 0x1.26d054p-1f},
    { 0x1.258734p-1f},
    { 0x1.243d6p-1f},
    { 0x1.22f2d6p-1f},
    { 0x1.21a79ap-1f},
    { 0x1.205baap-1f},
    { 0x1.1f0f08p-1f},
    { 0x1.1dc1b6p-1f},
    { 0x1.1c73b4p-1f},
    { 0x1.1b2502p-1f},
    { 0x1.19d5ap-1f},
    { 0x1.188592p-1f},
    { 0x1.1734d6p-1f},
    { 0x1.15e36ep-1f},
    { 0x1.14915ap-1f},
    { 0x1.133e9cp-1f},
    { 0x1.11eb36p-1f},
    { 0x1.109724p-1f},
    { 0x1.0f426cp-1f},
    { 0x1.0ded0cp-1f},
    { 0x1.0c9704p-1f},
    { 0x1.0b4058p-1f},
    { 0x1.09e908p-1f},
    { 0x1.089112p-1f},
    { 0x1.07387ap-1f},
    { 0x1.05df3ep-1f},
    { 0x1.048562p-1f},
    { 0x1.032ae6p-1f},
    { 0x1.01cfc8p-1f},
    { 0x1.00740cp-1f},
    { 0x1.fe2f64p-2f},
    { 0x1.fb7576p-2f},
    { 0x1.f8ba4ep-2f},
    { 0x1.f5fdeep-2f},
    { 0x1.f3405ap-2f},
    { 0x1.f0819p-2f},
    { 0x1.edc196p-2f},
    { 0x1.eb006ap-2f},
    { 0x1.e83e0ep-2f},
    { 0x1.e57a86p-2f},
    { 0x1.e2b5d4p-2f},
    { 0x1.dfeff6p-2f},
    { 0x1.dd28f2p-2f},
    { 0x1.da60c6p-2f},
    { 0x1.d79776p-2f},
    { 0x1.d4cd02p-2f},
    { 0x1.d2016ep-2f},
    { 0x1.cf34bap-2f},
    { 0x1.cc66eap-2f},
    { 0x1.c997fcp-2f},
    { 0x1.c6c7f4p-2f},
    { 0x1.c3f6d4p-2f},
    { 0x1.c1249ep-2f},
    { 0x1.be5152p-2f},
    { 0x1.bb7cf2p-2f},
    { 0x1.b8a782p-2f},
    { 0x1.b5d1p-2f},
    { 0x1.b2f972p-2f},
    { 0x1.b020d6p-2f},
    { 0x1.ad4732p-2f},
    { 0x1.aa6c82p-2f},
    { 0x1.a790cep-2f},
    { 0x1.a4b412p-2f},
    { 0x1.a1d654p-2f},
    { 0x1.9ef794p-2f},
    { 0x1.9c17d4p-2f},
    { 0x1.993716p-2f},
    { 0x1.96555cp-2f},
    { 0x1.9372a6p-2f},
    { 0x1.908ef8p-2f},
    { 0x1.8daa52p-2f},
    { 0x1.8ac4b8p-2f},
    { 0x1.87de2ap-2f},
    { 0x1.84f6aap-2f},
    { 0x1.820e3cp-2f},
    { 0x1.7f24dep-2f},
    { 0x1.7c3a94p-2f},
    { 0x1.794f5ep-2f},
    { 0x1.76634p-2f},
    { 0x1.73763cp-2f},
    { 0x1.708854p-2f},
    { 0x1.6d9986p-2f},
    { 0x1.6aa9d8p-2f},
    { 0x1.67b94ap-2f},
    { 0x1.64c7dep-2f},
    { 0x1.61d596p-2f},
    { 0x1.5ee274p-2f},
    { 0x1.5bee78p-2f},
    { 0x1.58f9a8p-2f},
    { 0x1.560402p-2f},
    { 0x1.530d88p-2f},
    { 0x1.50163ep-2f},
    { 0x1.4d1e24p-2f},
    { 0x1.4a253ep-2f},
    { 0x1.472b8ap-2f},
    { 0x1.44310ep-2f},
    { 0x1.4135cap-2f},
    { 0x1.3e39bep-2f},
    { 0x1.3b3cfp-2f},
    { 0x1.383f5ep-2f},
    { 0x1.35410cp-2f},
    { 0x1.3241fcp-2f},
    { 0x1.2f422ep-2f},
    { 0x1.2c41a4p-2f},
    { 0x1.294062p-2f},
    { 0x1.263e6ap-2f},
    { 0x1.233bbap-2f},
    { 0x1.203858p-2f},
    { 0x1.1d3444p-2f},
    { 0x1.1a2f8p-2f},
    { 0x1.172a0ep-2f},
    { 0x1.1423eep-2f},
    { 0x1.111d26p-2f},
    { 0x1.0e15b4p-2f},
    { 0x1.0b0d9cp-2f},
    { 0x1.0804ep-2f},
    { 0x1.04fb8p-2f},
    { 0x1.01f18p-2f},
    { 0x1.fdcdc2p-3f},
    { 0x1.f7b748p-3f},
    { 0x1.f19f98p-3f},
    { 0x1.eb86b4p-3f},
    { 0x1.e56ca2p-3f},
    { 0x1.df5164p-3f},
    { 0x1.d934fep-3f},
    { 0x1.d31774p-3f},
    { 0x1.ccf8ccp-3f},
    { 0x1.c6d906p-3f},
    { 0x1.c0b826p-3f},
    { 0x1.ba9634p-3f},
    { 0x1.b4732ep-3f},
    { 0x1.ae4f1ep-3f},
    { 0x1.a82a02p-3f},
    { 0x1.a203e2p-3f},
    { 0x1.9bdccp-3f},
    { 0x1.95b49ep-3f},
    { 0x1.8f8b84p-3f},
    { 0x1.896172p-3f},
    { 0x1.83366ep-3f},
    { 0x1.7d0a7cp-3f},
    { 0x1.76dd9ep-3f},
    { 0x1.70afd8p-3f},
    { 0x1.6a813p-3f},
    { 0x1.6451a8p-3f},
    { 0x1.5e2144p-3f},
    { 0x1.57f008p-3f},
    { 0x1.51bdf8p-3f},
    { 0x1.4b8b18p-3f},
    { 0x1.45576cp-3f},
    { 0x1.3f22f6p-3f},
    { 0x1.38edbcp-3f},
    { 0x1.32b7cp-3f},
    { 0x1.2c8106p-3f},
    { 0x1.264994p-3f},
    { 0x1.20116ep-3f},
    { 0x1.19d894p-3f},
    { 0x1.139f0cp-3f},
    { 0x1.0d64dcp-3f},
    { 0x1.072a04p-3f},
    { 0x1.00ee8ap-3f},
    { 0x1.f564e6p-4f},
    { 0x1.e8eb8p-4f},
    { 0x1.dc70ecp-4f},
    { 0x1.cff534p-4f},
    { 0x1.c3785cp-4f},
    { 0x1.b6fa6ep-4f},
    { 0x1.aa7b72p-4f},
    { 0x1.9dfb6ep-4f},
    { 0x1.917a6cp-4f},
    { 0x1.84f872p-4f},
    { 0x1.787586p-4f},
    { 0x1.6bf1b4p-4f},
    { 0x1.5f6dp-4f},
    { 0x1.52e774p-4f},
    { 0x1.466118p-4f},
    { 0x1.39d9f2p-4f},
    { 0x1.2d520ap-4f},
    { 0x1.20c968p-4f},
    { 0x1.144014p-4f},
    { 0x1.07b614p-4f},
    { 0x1.f656e8p-5f},
    { 0x1.dd407p-5f},
    { 0x1.c428d2p-5f},
    { 0x1.ab101cp-5f},
    { 0x1.91f66p-5f},
    { 0x1.78dbaap-5f},
    { 0x1.5fc00ep-5f},
    { 0x1.46a396p-5f},
    { 0x1.2d8658p-5f},
    { 0x1.14685ep-5f},
    { 0x1.f69374p-6f},
    { 0x1.c454f4p-6f},
    { 0x1.92156p-6f},
    { 0x1.5fd4d2p-6f},
    { 0x1.2d936cp-6f},
    { 0x1.f6a296p-7f},
    { 0x1.921d2p-7f},
    { 0x1.2d96bp-7f},
    { 0x1.921f1p-8f},
    { 0x1.921f8cp-9f},
    { 0.0f},
    { -0x1.921f8cp-9f},
    { -0x1.921f1p-8f},
    { -0x1.2d96bp-7f},
    { -0x1.921d2p-7f},
    { -0x1.f6a296p-7f},
    { -0x1.2d936cp-6f},
    { -0x1.5fd4d2p-6f},
    { -0x1.92156p-6f},
    { -0x1.c454f4p-6f},
    { -0x1.f69374p-6f},
    { -0x1.14685ep-5f},
    { -0x1.2d8658p-5f},
    { -0x1.46a396p-5f},
    { -0x1.5fc00ep-5f},
    { -0x1.78dbaap-5f},
    { -0x1.91f66p-5f},
    { -0x1.ab101cp-5f},
    { -0x1.c428d2p-5f},
    { -0x1.dd407p-5f},
    { -0x1.f656e8p-5f},
    { -0x1.07b614p-4f},
    { -0x1.144014p-4f},
    { -0x1.20c968p-4f},
    { -0x1.2d520ap-4f},
    { -0x1.39d9f2p-4f},
    { -0x1.466118p-4f},
    { -0x1.52e774p-4f},
    { -0x1.5f6dp-4f},
    { -0x1.6bf1b4p-4f},
    { -0x1.787586p-4f},
    { -0x1.84f872p-4f},
    { -0x1.917a6cp-4f},
    { -0x1.9dfb6ep-4f},
    { -0x1.aa7b72p-4f},
    { -0x1.b6fa6ep-4f},
    { -0x1.c3785cp-4f},
    { -0x1.cff534p-4f},
    { -0x1.dc70ecp-4f},
    { -0x1.e8eb8p-4f},
    { -0x1.f564e6p-4f},
    { -0x1.00ee8ap-3f},
    { -0x1.072a04p-3f},
    { -0x1.0d64dcp-3f},
    { -0x1.139f0cp-3f},
    { -0x1.19d894p-3f},
    { -0x1.20116ep-3f},
    { -0x1.264994p-3f},
    { -0x1.2c8106p-3f},
    { -0x1.32b7cp-3f},
    { -0x1.38edbcp-3f},
    { -0x1.3f22f6p-3f},
    { -0x1.45576cp-3f},
    { -0x1.4b8b18p-3f},
    { -0x1.51bdf8p-3f},
    { -0x1.57f008p-3f},
    { -0x1.5e2144p-3f},
    { -0x1.6451a8p-3f},
    { -0x1.6a813p-3f},
    { -0x1.70afd8p-3f},
    { -0x1.76dd9ep-3f},
    { -0x1.7d0a7cp-3f},
    { -0x1.83366ep-3f},
    { -0x1.896172p-3f},
    { -0x1.8f8b84p-3f},
    { -0x1.95b49ep-3f},
    { -0x1.9bdccp-3f},
    { -0x1.a203e2p-3f},
    { -0x1.a82a02p-3f},
    { -0x1.ae4f1ep-3f},
    { -0x1.b4732ep-3f},
    { -0x1.ba9634p-3f},
    { -0x1.c0b826p-3f},
    { -0x1.c6d906p-3f},
    { -0x1.ccf8ccp-3f},
    { -0x1.d31774p-3f},
    { -0x1.d934fep-3f},
    { -0x1.df5164p-3f},
    { -0x1.e56ca2p-3f},
    { -0x1.eb86b4p-3f},
    { -0x1.f19f98p-3f},
    { -0x1.f7b748p-3f},
    { -0x1.fdcdc2p-3f},
    { -0x1.01f18p-2f},
    { -0x1.04fb8p-2f},
    { -0x1.0804ep-2f},
    { -0x1.0b0d9cp-2f},
    { -0x1.0e15b4p-2f},
    { -0x1.111d26p-2f},
    { -0x1.1423eep-2f},
    { -0x1.172a0ep-2f},
    { -0x1.1a2f8p-2f},
    { -0x1.1d3444p-2f},
    { -0x1.203858p-2f},
    { -0x1.233bbap-2f},
    { -0x1.263e6ap-2f},
    { -0x1.294062p-2f},
    { -0x1.2c41a4p-2f},
    { -0x1.2f422ep-2f},
    { -0x1.3241fcp-2f},
    { -0x1.35410cp-2f},
    { -0x1.383f5ep-2f},
    { -0x1.3b3cfp-2f},
    { -0x1.3e39bep-2f},
    { -0x1.4135cap-2f},
    { -0x1.44310ep-2f},
    { -0x1.472b8ap-2f},
    { -0x1.4a253ep-2f},
    { -0x1.4d1e24p-2f},
    { -0x1.50163ep-2f},
    { -0x1.530d88p-2f},
    { -0x1.560402p-2f},
    { -0x1.58f9a8p-2f},
    { -0x1.5bee78p-2f},
    { -0x1.5ee274p-2f},
    { -0x1.61d596p-2f},
    { -0x1.64c7dep-2f},
    { -0x1.67b94ap-2f},
    { -0x1.6aa9d8p-2f},
    { -0x1.6d9986p-2f},
    { -0x1.708854p-2f},
    { -0x1.73763cp-2f},
    { -0x1.76634p-2f},
    { -0x1.794f5ep-2f},
    { -0x1.7c3a94p-2f},
    { -0x1.7f24dep-2f},
    { -0x1.820e3cp-2f},
    { -0x1.84f6aap-2f},
    { -0x1.87de2ap-2f},
    { -0x1.8ac4b8p-2f},
    { -0x1.8daa52p-2f},
    { -0x1.908ef8p-2f},
    { -0x1.9372a6p-2f},
    { -0x1.96555cp-2f},
    { -0x1.993716p-2f},
    { -0x1.9c17d4p-2f},
    { -0x1.9ef794p-2f},
    { -0x1.a1d654p-2f},
    { -0x1.a4b412p-2f},
    { -0x1.a790cep-2f},
    { -0x1.aa6c82p-2f},
    { -0x1.ad4732p-2f},
    { -0x1.b020d6p-2f},
    { -0x1.b2f972p-2f},
    { -0x1.b5d1p-2f},
    { -0x1.b8a782p-2f},
    { -0x1.bb7cf2p-2f},
    { -0x1.be5152p-2f},
    { -0x1.c1249ep-2f},
    { -0x1.c3f6d4p-2f},
    { -0x1.c6c7f4p-2f},
    { -0x1.c997fcp-2f},
    { -0x1.cc66eap-2f},
    { -0x1.cf34bap-2f},
    { -0x1.d2016ep-2f},
    { -0x1.d4cd02p-2f},
    { -0x1.d79776p-2f},
    { -0x1.da60c6p-2f},
    { -0x1.dd28f2p-2f},
    { -0x1.dfeff6p-2f},
    { -0x1.e2b5d4p-2f},
    { -0x1.e57a86p-2f},
    { -0x1.e83e0ep-2f},
    { -0x1.eb006ap-2f},
    { -0x1.edc196p-2f},
    { -0x1.f0819p-2f},
    { -0x1.f3405ap-2f},
    { -0x1.f5fdeep-2f},
    { -0x1.f8ba4ep-2f},
    { -0x1.fb7576p-2f},
    { -0x1.fe2f64p-2f},
    { -0x1.00740cp-1f},
    { -0x1.01cfc8p-1f},
    { -0x1.032ae6p-1f},
    { -0x1.048562p-1f},
    { -0x1.05df3ep-1f},
    { -0x1.07387ap-1f},
    { -0x1.089112p-1f},
    { -0x1.09e908p-1f},
    { -0x1.0b4058p-1f},
    { -0x1.0c9704p-1f},
    { -0x1.0ded0cp-1f},
    { -0x1.0f426cp-1f},
    { -0x1.109724p-1f},
    { -0x1.11eb36p-1f},
    { -0x1.133e9cp-1f},
    { -0x1.14915ap-1f},
    { -0x1.15e36ep-1f},
    { -0x1.1734d6p-1f},
    { -0x1.188592p-1f},
    { -0x1.19d5ap-1f},
    { -0x1.1b2502p-1f},
    { -0x1.1c73b4p-1f},
    { -0x1.1dc1b6p-1f},
    { -0x1.1f0f08p-1f},
    { -0x1.205baap-1f},
    { -0x1.21a79ap-1f},
    { -0x1.22f2d6p-1f},
    { -0x1.243d6p-1f},
    { -0x1.258734p-1f},
    { -0x1.26d054p-1f},
    { -0x1.2818bep-1f},
    { -0x1.296072p-1f},
    { -0x1.2aa76ep-1f},
    { -0x1.2bedb2p-1f},
    { -0x1.2d333ep-1f},
    { -0x1.2e780ep-1f},
    { -0x1.2fbc24p-1f},
    { -0x1.30ff8p-1f},
    { -0x1.32421ep-1f},
    { -0x1.3384p-1f},
    { -0x1.34c526p-1f},
    { -0x1.36058cp-1f},
    { -0x1.374532p-1f},
    { -0x1.388418p-1f},
    { -0x1.39c23ep-1f},
    { -0x1.3affa2p-1f},
    { -0x1.3c3c44p-1f},
    { -0x1.3d7824p-1f},
    { -0x1.3eb33ep-1f},
    { -0x1.3fed96p-1f},
    { -0x1.412726p-1f},
    { -0x1.425ff2p-1f},
    { -0x1.4397f6p-1f},
    { -0x1.44cf32p-1f},
    { -0x1.4605a6p-1f},
    { -0x1.473b52p-1f},
    { -0x1.487034p-1f},
    { -0x1.49a44ap-1f},
    { -0x1.4ad796p-1f},
    { -0x1.4c0a14p-1f},
    { -0x1.4d3bc6p-1f},
    { -0x1.4e6cacp-1f},
    { -0x1.4f9cc2p-1f},
    { -0x1.50cc0ap-1f},
    { -0x1.51fa82p-1f},
    { -0x1.53282ap-1f},
    { -0x1.5455p-1f},
    { -0x1.558104p-1f},
    { -0x1.56ac36p-1f},
    { -0x1.57d694p-1f},
    { -0x1.59001ep-1f},
    { -0x1.5a28d2p-1f},
    { -0x1.5b50b2p-1f},
    { -0x1.5c77bcp-1f},
    { -0x1.5d9deep-1f},
    { -0x1.5ec34ap-1f},
    { -0x1.5fe7ccp-1f},
    { -0x1.610b76p-1f},
    { -0x1.622e44p-1f},
    { -0x1.63503ap-1f},
    { -0x1.647154p-1f},
    { -0x1.659192p-1f},
    { -0x1.66b0f4p-1f},
    { -0x1.67cf78p-1f},
    { -0x1.68ed1ep-1f},
    { -0x1.6a09e6p-1f},
    { -0x1.6b25cep-1f},
    { -0x1.6c40d8p-1f},
    { -0x1.6d5afep-1f},
    { -0x1.6e7446p-1f},
    { -0x1.6f8caap-1f},
    { -0x1.70a42cp-1f},
    { -0x1.71bacap-1f},
    { -0x1.72d084p-1f},
    { -0x1.73e558p-1f},
    { -0x1.74f948p-1f},
    { -0x1.760c52p-1f},
    { -0x1.771e76p-1f},
    { -0x1.782fb2p-1f},
    { -0x1.794006p-1f},
    { -0x1.7a4f7p-1f},
    { -0x1.7b5df2p-1f},
    { -0x1.7c6b8ap-1f},
    { -0x1.7d7836p-1f},
    { -0x1.7e83f8p-1f},
    { -0x1.7f8ecep-1f},
    { -0x1.8098b8p-1f},
    { -0x1.81a1b4p-1f},
    { -0x1.82a9c2p-1f},
    { -0x1.83b0ep-1f},
    { -0x1.84b712p-1f},
    { -0x1.85bc52p-1f},
    { -0x1.86c0a2p-1f},
    { -0x1.87c4p-1f},
    { -0x1.88c66ep-1f},
    { -0x1.89c7eap-1f},
    { -0x1.8ac872p-1f},
    { -0x1.8bc806p-1f},
    { -0x1.8cc6a8p-1f},
    { -0x1.8dc454p-1f},
    { -0x1.8ec10ap-1f},
    { -0x1.8fbccap-1f},
    { -0x1.90b794p-1f},
    { -0x1.91b166p-1f},
    { -0x1.92aa42p-1f},
    { -0x1.93a224p-1f},
    { -0x1.94990ep-1f},
    { -0x1.958efep-1f},
    { -0x1.9683f4p-1f},
    { -0x1.9777fp-1f},
    { -0x1.986afp-1f},
    { -0x1.995cf2p-1f},
    { -0x1.9a4dfap-1f},
    { -0x1.9b3e04p-1f},
    { -0x1.9c2d12p-1f},
    { -0x1.9d1b2p-1f},
    { -0x1.9e082ep-1f},
    { -0x1.9ef43ep-1f},
    { -0x1.9fdf5p-1f},
    { -0x1.a0c95ep-1f},
    { -0x1.a1b26ep-1f},
    { -0x1.a29a7ap-1f},
    { -0x1.a38184p-1f},
    { -0x1.a4678cp-1f},
    { -0x1.a54c92p-1f},
    { -0x1.a63092p-1f},
    { -0x1.a7138ep-1f},
    { -0x1.a7f586p-1f},
    { -0x1.a8d676p-1f},
    { -0x1.a9b662p-1f},
    { -0x1.aa9548p-1f},
    { -0x1.ab7326p-1f},
    { -0x1.ac4ffcp-1f},
    { -0x1.ad2bcap-1f},
    { -0x1.ae069p-1f},
    { -0x1.aee04cp-1f},
    { -0x1.afb8fep-1f},
    { -0x1.b090a6p-1f},
    { -0x1.b16742p-1f},
    { -0x1.b23cd4p-1f},
    { -0x1.b3115ap-1f},
    { -0x1.b3e4d4p-1f},
    { -0x1.b4b74p-1f},
    { -0x1.b588ap-1f},
    { -0x1.b658f2p-1f},
    { -0x1.b72834p-1f},
    { -0x1.b7f668p-1f},
    { -0x1.b8c38ep-1f},
    { -0x1.b98fa2p-1f},
    { -0x1.ba5aa6p-1f},
    { -0x1.bb249ap-1f},
    { -0x1.bbed7cp-1f},
    { -0x1.bcb54cp-1f},
    { -0x1.bd7c0ap-1f},
    { -0x1.be41b6p-1f},
    { -0x1.bf064ep-1f},
    { -0x1.bfc9d2p-1f},
    { -0x1.c08c42p-1f},
    { -0x1.c14d9ep-1f},
    { -0x1.c20de4p-1f},
    { -0x1.c2cd14p-1f},
    { -0x1.c38b3p-1f},
    { -0x1.c44834p-1f},
    { -0x1.c5042p-1f},
    { -0x1.c5bef6p-1f},
    { -0x1.c678b4p-1f},
    { -0x1.c73158p-1f},
    { -0x1.c7e8e6p-1f},
    { -0x1.c89f58p-1f},
    { -0x1.c954b2p-1f},
    { -0x1.ca08f2p-1f},
    { -0x1.cabc16p-1f},
    { -0x1.cb6e2p-1f},
    { -0x1.cc1f1p-1f},
    { -0x1.cccee2p-1f},
    { -0x1.cd7d98p-1f},
    { -0x1.ce2b32p-1f},
    { -0x1.ced7bp-1f},
    { -0x1.cf830ep-1f},
    { -0x1.d02d5p-1f},
    { -0x1.d0d672p-1f},
    { -0x1.d17e78p-1f},
    { -0x1.d2255cp-1f},
    { -0x1.d2cb22p-1f},
    { -0x1.d36fc8p-1f},
    { -0x1.d4134ep-1f},
    { -0x1.d4b5b2p-1f},
    { -0x1.d556f6p-1f},
    { -0x1.d5f718p-1f},
    { -0x1.d69618p-1f},
    { -0x1.d733f6p-1f},
    { -0x1.d7d0bp-1f},
    { -0x1.d86c48p-1f},
    { -0x1.d906bcp-1f},
    { -0x1.d9a00ep-1f},
    { -0x1.da383ap-1f},
    { -0x1.dacf42p-1f},
    { -0x1.db6526p-1f},
    { -0x1.dbf9e4p-1f},
    { -0x1.dc8d7cp-1f},
    { -0x1.dd1ffp-1f},
    { -0x1.ddb13cp-1f},
    { -0x1.de416p-1f},
    { -0x1.ded06p-1f},
    { -0x1.df5e36p-1f},
    { -0x1.dfeae6p-1f},
    { -0x1.e0766ep-1f},
    { -0x1.e100ccp-1f},
    { -0x1.e18a02p-1f},
    { -0x1.e2121p-1f},
    { -0x1.e298f4p-1f},
    { -0x1.e31eaep-1f},
    { -0x1.e3a33ep-1f},
    { -0x1.e426a4p-1f},
    { -0x1.e4a8ep-1f},
    { -0x1.e529fp-1f},
    { -0x1.e5a9d6p-1f},
    { -0x1.e6288ep-1f},
    { -0x1.e6a61cp-1f},
    { -0x1.e7227ep-1f},
    { -0x1.e79db2p-1f},
    { -0x1.e817bap-1f},
    { -0x1.e89096p-1f},
    { -0x1.e90844p-1f},
    { -0x1.e97ec4p-1f},
    { -0x1.e9f416p-1f},
    { -0x1.ea683ap-1f},
    { -0x1.eadb2ep-1f},
    { -0x1.eb4cf6p-1f},
    { -0x1.ebbd8cp-1f},
    { -0x1.ec2cf4p-1f},
    { -0x1.ec9b2ep-1f},
    { -0x1.ed0836p-1f},
    { -0x1.ed740ep-1f},
    { -0x1.eddeb6p-1f},
    { -0x1.ee482ep-1f},
    { -0x1.eeb074p-1f},
    { -0x1.ef178ap-1f},
    { -0x1.ef7d6ep-1f},
    { -0x1.efe22p-1f},
    { -0x1.f045a2p-1f},
    { -0x1.f0a7fp-1f},
    { -0x1.f1090cp-1f},
    { -0x1.f168f6p-1f},
    { -0x1.f1c7acp-1f},
    { -0x1.f2253p-1f},
    { -0x1.f2818p-1f},
    { -0x1.f2dc9cp-1f},
    { -0x1.f33686p-1f},
    { -0x1.f38f3ap-1f},
    { -0x1.f3e6bcp-1f},
    { -0x1.f43d08p-1f},
    { -0x1.f4922p-1f},
    { -0x1.f4e604p-1f},
    { -0x1.f538b2p-1f},
    { -0x1.f58a2cp-1f},
    { -0x1.f5da6ep-1f},
    { -0x1.f6297cp-1f},
    { -0x1.f67756p-1f},
    { -0x1.f6c3f8p-1f},
    { -0x1.f70f64p-1f},
    { -0x1.f7599ap-1f},
    { -0x1.f7a29ap-1f},
    { -0x1.f7ea62p-1f},
    { -0x1.f830f4p-1f},
    { -0x1.f8765p-1f},
    { -0x1.f8ba74p-1f},
    { -0x1.f8fd6p-1f},
    { -0x1.f93f14p-1f},
    { -0x1.f97f92p-1f},
    { -0x1.f9bed8p-1f},
    { -0x1.f9fce6p-1f},
    { -0x1.fa39bap-1f},
    { -0x1.fa7558p-1f},
    { -0x1.faafbcp-1f},
    { -0x1.fae8e8p-1f},
    { -0x1.fb20dcp-1f},
    { -0x1.fb5798p-1f},
    { -0x1.fb8d18p-1f},
    { -0x1.fbc162p-1f},
    { -0x1.fbf47p-1f},
    { -0x1.fc2648p-1f},
    { -0x1.fc56e4p-1f},
    { -0x1.fc8646p-1f},
    { -0x1.fcb47p-1f},
    { -0x1.fce16p-1f},
    { -0x1.fd0d16p-1f},
    { -0x1.fd3792p-1f},
    { -0x1.fd60d2p-1f},
    { -0x1.fd88dap-1f},
    { -0x1.fdafa8p-1f},
    { -0x1.fdd53ap-1f},
    { -0x1.fdf992p-1f},
    { -0x1.fe1cbp-1f},
    { -0x1.fe3e92p-1f},
    { -0x1.fe5f3ap-1f},
    { -0x1.fe7ea8p-1f},
    { -0x1.fe9cdap-1f},
    { -0x1.feb9d2p-1f},
    { -0x1.fed58ep-1f},
    { -0x1.fef01p-1f},
    { -0x1.ff0956p-1f},
    { -0x1.ff2162p-1f},
    { -0x1.ff383p-1f},
    { -0x1.ff4dc6p-1f},
    { -0x1.ff621ep-1f},
    { -0x1.ff753cp-1f},
    { -0x1.ff871ep-1f},
    { -0x1.ff97c4p-1f},
    { -0x1.ffa72ep-1f},
    { -0x1.ffb55ep-1f},
    { -0x1.ffc252p-1f},
    { -0x1.ffce0ap-1f},
    { -0x1.ffd886p-1f},
    { -0x1.ffe1c6p-1f},
    { -0x1.ffe9ccp-1f},
    { -0x1.fff094p-1f},
    { -0x1.fff622p-1f},
    { -0x1.fffa72p-1f},
    { -0x1.fffd88p-1f},
    { -0x1.ffff62p-1f},
    { -0x1p0f},
    { -0x1.ffff62p-1f},
    { -0x1.fffd88p-1f},
    { -0x1.fffa72p-1f},
    { -0x1.fff622p-1f},
    { -0x1.fff094p-1f},
    { -0x1.ffe9ccp-1f},
    { -0x1.ffe1c6p-1f},
    { -0x1.ffd886p-1f},
    { -0x1.ffce0ap-1f},
    { -0x1.ffc252p-1f},
    { -0x1.ffb55ep-1f},
    { -0x1.ffa72ep-1f},
    { -0x1.ff97c4p-1f},
    { -0x1.ff871ep-1f},
    { -0x1.ff753cp-1f},
    { -0x1.ff621ep-1f},
    { -0x1.ff4dc6p-1f},
    { -0x1.ff383p-1f},
    { -0x1.ff2162p-1f},
    { -0x1.ff0956p-1f},
    { -0x1.fef01p-1f},
    { -0x1.fed58ep-1f},
    { -0x1.feb9d2p-1f},
    { -0x1.fe9cdap-1f},
    { -0x1.fe7ea8p-1f},
    { -0x1.fe5f3ap-1f},
    { -0x1.fe3e92p-1f},
    { -0x1.fe1cbp-1f},
    { -0x1.fdf992p-1f},
    { -0x1.fdd53ap-1f},
    { -0x1.fdafa8p-1f},
    { -0x1.fd88dap-1f},
    { -0x1.fd60d2p-1f},
    { -0x1.fd3792p-1f},
    { -0x1.fd0d16p-1f},
    { -0x1.fce16p-1f},
    { -0x1.fcb47p-1f},
    { -0x1.fc8646p-1f},
    { -0x1.fc56e4p-1f},
    { -0x1.fc2648p-1f},
    { -0x1.fbf47p-1f},
    { -0x1.fbc162p-1f},
    { -0x1.fb8d18p-1f},
    { -0x1.fb5798p-1f},
    { -0x1.fb20dcp-1f},
    { -0x1.fae8e8p-1f},
    { -0x1.faafbcp-1f},
    { -0x1.fa7558p-1f},
    { -0x1.fa39bap-1f},
    { -0x1.f9fce6p-1f},
    { -0x1.f9bed8p-1f},
    { -0x1.f97f92p-1f},
    { -0x1.f93f14p-1f},
    { -0x1.f8fd6p-1f},
    { -0x1.f8ba74p-1f},
    { -0x1.f8765p-1f},
    { -0x1.f830f4p-1f},
    { -0x1.f7ea62p-1f},
    { -0x1.f7a29ap-1f},
    { -0x1.f7599ap-1f},
    { -0x1.f70f64p-1f},
    { -0x1.f6c3f8p-1f},
    { -0x1.f67756p-1f},
    { -0x1.f6297cp-1f},
    { -0x1.f5da6ep-1f},
    { -0x1.f58a2cp-1f},
    { -0x1.f538b2p-1f},
    { -0x1.f4e604p-1f},
    { -0x1.f4922p-1f},
    { -0x1.f43d08p-1f},
    { -0x1.f3e6bcp-1f},
    { -0x1.f38f3ap-1f},
    { -0x1.f33686p-1f},
    { -0x1.f2dc9cp-1f},
    { -0x1.f2818p-1f},
    { -0x1.f2253p-1f},
    { -0x1.f1c7acp-1f},
    { -0x1.f168f6p-1f},
    { -0x1.f1090cp-1f},
    { -0x1.f0a7fp-1f},
    { -0x1.f045a2p-1f},
    { -0x1.efe22p-1f},
    { -0x1.ef7d6ep-1f},
    { -0x1.ef178ap-1f},
    { -0x1.eeb074p-1f},
    { -0x1.ee482ep-1f},
    { -0x1.eddeb6p-1f},
    { -0x1.ed740ep-1f},
    { -0x1.ed0836p-1f},
    { -0x1.ec9b2ep-1f},
    { -0x1.ec2cf4p-1f},
    { -0x1.ebbd8cp-1f},
    { -0x1.eb4cf6p-1f},
    { -0x1.eadb2ep-1f},
    { -0x1.ea683ap-1f},
    { -0x1.e9f416p-1f},
    { -0x1.e97ec4p-1f},
    { -0x1.e90844p-1f},
    { -0x1.e89096p-1f},
    { -0x1.e817bap-1f},
    { -0x1.e79db2p-1f},
    { -0x1.e7227ep-1f},
    { -0x1.e6a61cp-1f},
    { -0x1.e6288ep-1f},
    { -0x1.e5a9d6p-1f},
    { -0x1.e529fp-1f},
    { -0x1.e4a8ep-1f},
    { -0x1.e426a4p-1f},
    { -0x1.e3a33ep-1f},
    { -0x1.e31eaep-1f},
    { -0x1.e298f4p-1f},
    { -0x1.e2121p-1f},
    { -0x1.e18a02p-1f},
    { -0x1.e100ccp-1f},
    { -0x1.e0766ep-1f},
    { -0x1.dfeae6p-1f},
    { -0x1.df5e36p-1f},
    { -0x1.ded06p-1f},
    { -0x1.de416p-1f},
    { -0x1.ddb13cp-1f},
    { -0x1.dd1ffp-1f},
    { -0x1.dc8d7cp-1f},
    { -0x1.dbf9e4p-1f},
    { -0x1.db6526p-1f},
    { -0x1.dacf42p-1f},
    { -0x1.da383ap-1f},
    { -0x1.d9a00ep-1f},
    { -0x1.d906bcp-1f},
    { -0x1.d86c48p-1f},
    { -0x1.d7d0bp-1f},
    { -0x1.d733f6p-1f},
    { -0x1.d69618p-1f},
    { -0x1.d5f718p-1f},
    { -0x1.d556f6p-1f},
    { -0x1.d4b5b2p-1f},
    { -0x1.d4134ep-1f},
    { -0x1.d36fc8p-1f},
    { -0x1.d2cb22p-1f},
    { -0x1.d2255cp-1f},
    { -0x1.d17e78p-1f},
    { -0x1.d0d672p-1f},
    { -0x1.d02d5p-1f},
    { -0x1.cf830ep-1f},
    { -0x1.ced7bp-1f},
    { -0x1.ce2b32p-1f},
    { -0x1.cd7d98p-1f},
    { -0x1.cccee2p-1f},
    { -0x1.cc1f1p-1f},
    { -0x1.cb6e2p-1f},
    { -0x1.cabc16p-1f},
    { -0x1.ca08f2p-1f},
    { -0x1.c954b2p-1f},
    { -0x1.c89f58p-1f},
    { -0x1.c7e8e6p-1f},
    { -0x1.c73158p-1f},
    { -0x1.c678b4p-1f},
    { -0x1.c5bef6p-1f},
    { -0x1.c5042p-1f},
    { -0x1.c44834p-1f},
    { -0x1.c38b3p-1f},
    { -0x1.c2cd14p-1f},
    { -0x1.c20de4p-1f},
    { -0x1.c14d9ep-1f},
    { -0x1.c08c42p-1f},
    { -0x1.bfc9d2p-1f},
    { -0x1.bf064ep-1f},
    { -0x1.be41b6p-1f},
    { -0x1.bd7c0ap-1f},
    { -0x1.bcb54cp-1f},
    { -0x1.bbed7cp-1f},
    { -0x1.bb249ap-1f},
    { -0x1.ba5aa6p-1f},
    { -0x1.b98fa2p-1f},
    { -0x1.b8c38ep-1f},
    { -0x1.b7f668p-1f},
    { -0x1.b72834p-1f},
    { -0x1.b658f2p-1f},
    { -0x1.b588ap-1f},
    { -0x1.b4b74p-1f},
    { -0x1.b3e4d4p-1f},
    { -0x1.b3115ap-1f},
    { -0x1.b23cd4p-1f},
    { -0x1.b16742p-1f},
    { -0x1.b090a6p-1f},
    { -0x1.afb8fep-1f},
    { -0x1.aee04cp-1f},
    { -0x1.ae069p-1f},
    { -0x1.ad2bcap-1f},
    { -0x1.ac4ffcp-1f},
    { -0x1.ab7326p-1f},
    { -0x1.aa9548p-1f},
    { -0x1.a9b662p-1f},
    { -0x1.a8d676p-1f},
    { -0x1.a7f586p-1f},
    { -0x1.a7138ep-1f},
    { -0x1.a63092p-1f},
    { -0x1.a54c92p-1f},
    { -0x1.a4678cp-1f},
    { -0x1.a38184p-1f},
    { -0x1.a29a7ap-1f},
    { -0x1.a1b26ep-1f},
    { -0x1.a0c95ep-1f},
    { -0x1.9fdf5p-1f},
    { -0x1.9ef43ep-1f},
    { -0x1.9e082ep-1f},
    { -0x1.9d1b2p-1f},
    { -0x1.9c2d12p-1f},
    { -0x1.9b3e04p-1f},
    { -0x1.9a4dfap-1f},
    { -0x1.995cf2p-1f},
    { -0x1.986afp-1f},
    { -0x1.9777fp-1f},
    { -0x1.9683f4p-1f},
    { -0x1.958efep-1f},
    { -0x1.94990ep-1f},
    { -0x1.93a224p-1f},
    { -0x1.92aa42p-1f},
    { -0x1.91b166p-1f},
    { -0x1.90b794p-1f},
    { -0x1.8fbccap-1f},
    { -0x1.8ec10ap-1f},
    { -0x1.8dc454p-1f},
    { -0x1.8cc6a8p-1f},
    { -0x1.8bc806p-1f},
    { -0x1.8ac872p-1f},
    { -0x1.89c7eap-1f},
    { -0x1.88c66ep-1f},
    { -0x1.87c4p-1f},
    { -0x1.86c0a2p-1f},
    { -0x1.85bc52p-1f},
    { -0x1.84b712p-1f},
    { -0x1.83b0ep-1f},
    { -0x1.82a9c2p-1f},
    { -0x1.81a1b4p-1f},
    { -0x1.8098b8p-1f},
    { -0x1.7f8ecep-1f},
    { -0x1.7e83f8p-1f},
    { -0x1.7d7836p-1f},
    { -0x1.7c6b8ap-1f},
    { -0x1.7b5df2p-1f},
    { -0x1.7a4f7p-1f},
    { -0x1.794006p-1f},
    { -0x1.782fb2p-1f},
    { -0x1.771e76p-1f},
    { -0x1.760c52p-1f},
    { -0x1.74f948p-1f},
    { -0x1.73e558p-1f},
    { -0x1.72d084p-1f},
    { -0x1.71bacap-1f},
    { -0x1.70a42cp-1f},
    { -0x1.6f8caap-1f},
    { -0x1.6e7446p-1f},
    { -0x1.6d5afep-1f},
    { -0x1.6c40d8p-1f},
    { -0x1.6b25cep-1f},
    { -0x1.6a09e6p-1f},
    { -0x1.68ed1ep-1f},
    { -0x1.67cf78p-1f},
    { -0x1.66b0f4p-1f},
    { -0x1.659192p-1f},
    { -0x1.647154p-1f},
    { -0x1.63503ap-1f},
    { -0x1.622e44p-1f},
    { -0x1.610b76p-1f},
    { -0x1.5fe7ccp-1f},
    { -0x1.5ec34ap-1f},
    { -0x1.5d9deep-1f},
    { -0x1.5c77bcp-1f},
    { -0x1.5b50b2p-1f},
    { -0x1.5a28d2p-1f},
    { -0x1.59001ep-1f},
    { -0x1.57d694p-1f},
    { -0x1.56ac36p-1f},
    { -0x1.558104p-1f},
    { -0x1.5455p-1f},
    { -0x1.53282ap-1f},
    { -0x1.51fa82p-1f},
    { -0x1.50cc0ap-1f},
    { -0x1.4f9cc2p-1f},
    { -0x1.4e6cacp-1f},
    { -0x1.4d3bc6p-1f},
    { -0x1.4c0a14p-1f},
    { -0x1.4ad796p-1f},
    { -0x1.49a44ap-1f},
    { -0x1.487034p-1f},
    { -0x1.473b52p-1f},
    { -0x1.4605a6p-1f},
    { -0x1.44cf32p-1f},
    { -0x1.4397f6p-1f},
    { -0x1.425ff2p-1f},
    { -0x1.412726p-1f},
    { -0x1.3fed96p-1f},
    { -0x1.3eb33ep-1f},
    { -0x1.3d7824p-1f},
    { -0x1.3c3c44p-1f},
    { -0x1.3affa2p-1f},
    { -0x1.39c23ep-1f},
    { -0x1.388418p-1f},
    { -0x1.374532p-1f},
    { -0x1.36058cp-1f},
    { -0x1.34c526p-1f},
    { -0x1.3384p-1f},
    { -0x1.32421ep-1f},
    { -0x1.30ff8p-1f},
    { -0x1.2fbc24p-1f},
    { -0x1.2e780ep-1f},
    { -0x1.2d333ep-1f},
    { -0x1.2bedb2p-1f},
    { -0x1.2aa76ep-1f},
    { -0x1.296072p-1f},
    { -0x1.2818bep-1f},
    { -0x1.26d054p-1f},
    { -0x1.258734p-1f},
    { -0x1.243d6p-1f},
    { -0x1.22f2d6p-1f},
    { -0x1.21a79ap-1f},
    { -0x1.205baap-1f},
    { -0x1.1f0f08p-1f},
    { -0x1.1dc1b6p-1f},
    { -0x1.1c73b4p-1f},
    { -0x1.1b2502p-1f},
    { -0x1.19d5ap-1f},
    { -0x1.188592p-1f},
    { -0x1.1734d6p-1f},
    { -0x1.15e36ep-1f},
    { -0x1.14915ap-1f},
    { -0x1.133e9cp-1f},
    { -0x1.11eb36p-1f},
    { -0x1.109724p-1f},
    { -0x1.0f426cp-1f},
    { -0x1.0ded0cp-1f},
    { -0x1.0c9704p-1f},
    { -0x1.0b4058p-1f},
    { -0x1.09e908p-1f},
    { -0x1.089112p-1f},
    { -0x1.07387ap-1f},
    { -0x1.05df3ep-1f},
    { -0x1.048562p-1f},
    { -0x1.032ae6p-1f},
    { -0x1.01cfc8p-1f},
    { -0x1.00740cp-1f},
    { -0x1.fe2f64p-2f},
    { -0x1.fb7576p-2f},
    { -0x1.f8ba4ep-2f},
    { -0x1.f5fdeep-2f},
    { -0x1.f3405ap-2f},
    { -0x1.f0819p-2f},
    { -0x1.edc196p-2f},
    { -0x1.eb006ap-2f},
    { -0x1.e83e0ep-2f},
    { -0x1.e57a86p-2f},
    { -0x1.e2b5d4p-2f},
    { -0x1.dfeff6p-2f},
    { -0x1.dd28f2p-2f},
    { -0x1.da60c6p-2f},
    { -0x1.d79776p-2f},
    { -0x1.d4cd02p-2f},
    { -0x1.d2016ep-2f},
    { -0x1.cf34bap-2f},
    { -0x1.cc66eap-2f},
    { -0x1.c997fcp-2f},
    { -0x1.c6c7f4p-2f},
    { -0x1.c3f6d4p-2f},
    { -0x1.c1249ep-2f},
    { -0x1.be5152p-2f},
    { -0x1.bb7cf2p-2f},
    { -0x1.b8a782p-2f},
    { -0x1.b5d1p-2f},
    { -0x1.b2f972p-2f},
    { -0x1.b020d6p-2f},
    { -0x1.ad4732p-2f},
    { -0x1.aa6c82p-2f},
    { -0x1.a790cep-2f},
    { -0x1.a4b412p-2f},
    { -0x1.a1d654p-2f},
    { -0x1.9ef794p-2f},
    { -0x1.9c17d4p-2f},
    { -0x1.993716p-2f},
    { -0x1.96555cp-2f},
    { -0x1.9372a6p-2f},
    { -0x1.908ef8p-2f},
    { -0x1.8daa52p-2f},
    { -0x1.8ac4b8p-2f},
    { -0x1.87de2ap-2f},
    { -0x1.84f6aap-2f},
    { -0x1.820e3cp-2f},
    { -0x1.7f24dep-2f},
    { -0x1.7c3a94p-2f},
    { -0x1.794f5ep-2f},
    { -0x1.76634p-2f},
    { -0x1.73763cp-2f},
    { -0x1.708854p-2f},
    { -0x1.6d9986p-2f},
    { -0x1.6aa9d8p-2f},
    { -0x1.67b94ap-2f},
    { -0x1.64c7dep-2f},
    { -0x1.61d596p-2f},
    { -0x1.5ee274p-2f},
    { -0x1.5bee78p-2f},
    { -0x1.58f9a8p-2f},
    { -0x1.560402p-2f},
    { -0x1.530d88p-2f},
    { -0x1.50163ep-2f},
    { -0x1.4d1e24p-2f},
    { -0x1.4a253ep-2f},
    { -0x1.472b8ap-2f},
    { -0x1.44310ep-2f},
    { -0x1.4135cap-2f},
    { -0x1.3e39bep-2f},
    { -0x1.3b3cfp-2f},
    { -0x1.383f5ep-2f},
    { -0x1.35410cp-2f},
    { -0x1.3241fcp-2f},
    { -0x1.2f422ep-2f},
    { -0x1.2c41a4p-2f},
    { -0x1.294062p-2f},
    { -0x1.263e6ap-2f},
    { -0x1.233bbap-2f},
    { -0x1.203858p-2f},
    { -0x1.1d3444p-2f},
    { -0x1.1a2f8p-2f},
    { -0x1.172a0ep-2f},
    { -0x1.1423eep-2f},
    { -0x1.111d26p-2f},
    { -0x1.0e15b4p-2f},
    { -0x1.0b0d9cp-2f},
    { -0x1.0804ep-2f},
    { -0x1.04fb8p-2f},
    { -0x1.01f18p-2f},
    { -0x1.fdcdc2p-3f},
    { -0x1.f7b748p-3f},
    { -0x1.f19f98p-3f},
    { -0x1.eb86b4p-3f},
    { -0x1.e56ca2p-3f},
    { -0x1.df5164p-3f},
    { -0x1.d934fep-3f},
    { -0x1.d31774p-3f},
    { -0x1.ccf8ccp-3f},
    { -0x1.c6d906p-3f},
    { -0x1.c0b826p-3f},
    { -0x1.ba9634p-3f},
    { -0x1.b4732ep-3f},
    { -0x1.ae4f1ep-3f},
    { -0x1.a82a02p-3f},
    { -0x1.a203e2p-3f},
    { -0x1.9bdccp-3f},
    { -0x1.95b49ep-3f},
    { -0x1.8f8b84p-3f},
    { -0x1.896172p-3f},
    { -0x1.83366ep-3f},
    { -0x1.7d0a7cp-3f},
    { -0x1.76dd9ep-3f},
    { -0x1.70afd8p-3f},
    { -0x1.6a813p-3f},
    { -0x1.6451a8p-3f},
    { -0x1.5e2144p-3f},
    { -0x1.57f008p-3f},
    { -0x1.51bdf8p-3f},
    { -0x1.4b8b18p-3f},
    { -0x1.45576cp-3f},
    { -0x1.3f22f6p-3f},
    { -0x1.38edbcp-3f},
    { -0x1.32b7cp-3f},
    { -0x1.2c8106p-3f},
    { -0x1.264994p-3f},
    { -0x1.20116ep-3f},
    { -0x1.19d894p-3f},
    { -0x1.139f0cp-3f},
    { -0x1.0d64dcp-3f},
    { -0x1.072a04p-3f},
    { -0x1.00ee8ap-3f},
    { -0x1.f564e6p-4f},
    { -0x1.e8eb8p-4f},
    { -0x1.dc70ecp-4f},
    { -0x1.cff534p-4f},
    { -0x1.c3785cp-4f},
    { -0x1.b6fa6ep-4f},
    { -0x1.aa7b72p-4f},
    { -0x1.9dfb6ep-4f},
    { -0x1.917a6cp-4f},
    { -0x1.84f872p-4f},
    { -0x1.787586p-4f},
    { -0x1.6bf1b4p-4f},
    { -0x1.5f6dp-4f},
    { -0x1.52e774p-4f},
    { -0x1.466118p-4f},
    { -0x1.39d9f2p-4f},
    { -0x1.2d520ap-4f},
    { -0x1.20c968p-4f},
    { -0x1.144014p-4f},
    { -0x1.07b614p-4f},
    { -0x1.f656e8p-5f},
    { -0x1.dd407p-5f},
    { -0x1.c428d2p-5f},
    { -0x1.ab101cp-5f},
    { -0x1.91f66p-5f},
    { -0x1.78dbaap-5f},
    { -0x1.5fc00ep-5f},
    { -0x1.46a396p-5f},
    { -0x1.2d8658p-5f},
    { -0x1.14685ep-5f},
    { -0x1.f69374p-6f},
    { -0x1.c454f4p-6f},
    { -0x1.92156p-6f},
    { -0x1.5fd4d2p-6f},
    { -0x1.2d936cp-6f},
    { -0x1.f6a296p-7f},
    { -0x1.921d2p-7f},
    { -0x1.2d96bp-7f},
    { -0x1.921f1p-8f},
    { -0x1.921f8cp-9f},
    { 0.0f},
    { 0x1.921f8cp-9f},
    { 0x1.921f1p-8f},
    { 0x1.2d96bp-7f},
    { 0x1.921d2p-7f},
    { 0x1.f6a296p-7f},
    { 0x1.2d936cp-6f},
    { 0x1.5fd4d2p-6f},
    { 0x1.92156p-6f},
    { 0x1.c454f4p-6f},
    { 0x1.f69374p-6f},
    { 0x1.14685ep-5f},
    { 0x1.2d8658p-5f},
    { 0x1.46a396p-5f},
    { 0x1.5fc00ep-5f},
    { 0x1.78dbaap-5f},
    { 0x1.91f66p-5f},
    { 0x1.ab101cp-5f},
    { 0x1.c428d2p-5f},
    { 0x1.dd407p-5f},
    { 0x1.f656e8p-5f},
    { 0x1.07b614p-4f},
    { 0x1.144014p-4f},
    { 0x1.20c968p-4f},
    { 0x1.2d520ap-4f},
    { 0x1.39d9f2p-4f},
    { 0x1.466118p-4f},
    { 0x1.52e774p-4f},
    { 0x1.5f6dp-4f},
    { 0x1.6bf1b4p-4f},
    { 0x1.787586p-4f},
    { 0x1.84f872p-4f},
    { 0x1.917a6cp-4f},
    { 0x1.9dfb6ep-4f},
    { 0x1.aa7b72p-4f},
    { 0x1.b6fa6ep-4f},
    { 0x1.c3785cp-4f},
    { 0x1.cff534p-4f},
    { 0x1.dc70ecp-4f},
    { 0x1.e8eb8p-4f},
    { 0x1.f564e6p-4f},
    { 0x1.00ee8ap-3f},
    { 0x1.072a04p-3f},
    { 0x1.0d64dcp-3f},
    { 0x1.139f0cp-3f},
    { 0x1.19d894p-3f},
    { 0x1.20116ep-3f},
    { 0x1.264994p-3f},
    { 0x1.2c8106p-3f},
    { 0x1.32b7cp-3f},
    { 0x1.38edbcp-3f},
    { 0x1.3f22f6p-3f},
    { 0x1.45576cp-3f},
    { 0x1.4b8b18p-3f},
    { 0x1.51bdf8p-3f},
    { 0x1.57f008p-3f},
    { 0x1.5e2144p-3f},
    { 0x1.6451a8p-3f},
    { 0x1.6a813p-3f},
    { 0x1.70afd8p-3f},
    { 0x1.76dd9ep-3f},
    { 0x1.7d0a7cp-3f},
    { 0x1.83366ep-3f},
    { 0x1.896172p-3f},
    { 0x1.8f8b84p-3f},
    { 0x1.95b49ep-3f},
    { 0x1.9bdccp-3f},
    { 0x1.a203e2p-3f},
    { 0x1.a82a02p-3f},
    { 0x1.ae4f1ep-3f},
    { 0x1.b4732ep-3f},
    { 0x1.ba9634p-3f},
    { 0x1.c0b826p-3f},
    { 0x1.c6d906p-3f},
    { 0x1.ccf8ccp-3f},
    { 0x1.d31774p-3f},
    { 0x1.d934fep-3f},
    { 0x1.df5164p-3f},
    { 0x1.e56ca2p-3f},
    { 0x1.eb86b4p-3f},
    { 0x1.f19f98p-3f},
    { 0x1.f7b748p-3f},
    { 0x1.fdcdc2p-3f},
    { 0x1.01f18p-2f},
    { 0x1.04fb8p-2f},
    { 0x1.0804ep-2f},
    { 0x1.0b0d9cp-2f},
    { 0x1.0e15b4p-2f},
    { 0x1.111d26p-2f},
    { 0x1.1423eep-2f},
    { 0x1.172a0ep-2f},
    { 0x1.1a2f8p-2f},
    { 0x1.1d3444p-2f},
    { 0x1.203858p-2f},
    { 0x1.233bbap-2f},
    { 0x1.263e6ap-2f},
    { 0x1.294062p-2f},
    { 0x1.2c41a4p-2f},
    { 0x1.2f422ep-2f},
    { 0x1.3241fcp-2f},
    { 0x1.35410cp-2f},
    { 0x1.383f5ep-2f},
    { 0x1.3b3cfp-2f},
    { 0x1.3e39bep-2f},
    { 0x1.4135cap-2f},
    { 0x1.44310ep-2f},
    { 0x1.472b8ap-2f},
    { 0x1.4a253ep-2f},
    { 0x1.4d1e24p-2f},
    { 0x1.50163ep-2f},
    { 0x1.530d88p-2f},
    { 0x1.560402p-2f},
    { 0x1.58f9a8p-2f},
    { 0x1.5bee78p-2f},
    { 0x1.5ee274p-2f},
    { 0x1.61d596p-2f},
    { 0x1.64c7dep-2f},
    { 0x1.67b94ap-2f},
    { 0x1.6aa9d8p-2f},
    { 0x1.6d9986p-2f},
    { 0x1.708854p-2f},
    { 0x1.73763cp-2f},
    { 0x1.76634p-2f},
    { 0x1.794f5ep-2f},
    { 0x1.7c3a94p-2f},
    { 0x1.7f24dep-2f},
    { 0x1.820e3cp-2f},
    { 0x1.84f6aap-2f},
    { 0x1.87de2ap-2f},
    { 0x1.8ac4b8p-2f},
    { 0x1.8daa52p-2f},
    { 0x1.908ef8p-2f},
    { 0x1.9372a6p-2f},
    { 0x1.96555cp-2f},
    { 0x1.993716p-2f},
    { 0x1.9c17d4p-2f},
    { 0x1.9ef794p-2f},
    { 0x1.a1d654p-2f},
    { 0x1.a4b412p-2f},
    { 0x1.a790cep-2f},
    { 0x1.aa6c82p-2f},
    { 0x1.ad4732p-2f},
    { 0x1.b020d6p-2f},
    { 0x1.b2f972p-2f},
    { 0x1.b5d1p-2f},
    { 0x1.b8a782p-2f},
    { 0x1.bb7cf2p-2f},
    { 0x1.be5152p-2f},
    { 0x1.c1249ep-2f},
    { 0x1.c3f6d4p-2f},
    { 0x1.c6c7f4p-2f},
    { 0x1.c997fcp-2f},
    { 0x1.cc66eap-2f},
    { 0x1.cf34bap-2f},
    { 0x1.d2016ep-2f},
    { 0x1.d4cd02p-2f},
    { 0x1.d79776p-2f},
    { 0x1.da60c6p-2f},
    { 0x1.dd28f2p-2f},
    { 0x1.dfeff6p-2f},
    { 0x1.e2b5d4p-2f},
    { 0x1.e57a86p-2f},
    { 0x1.e83e0ep-2f},
    { 0x1.eb006ap-2f},
    { 0x1.edc196p-2f},
    { 0x1.f0819p-2f},
    { 0x1.f3405ap-2f},
    { 0x1.f5fdeep-2f},
    { 0x1.f8ba4ep-2f},
    { 0x1.fb7576p-2f},
    { 0x1.fe2f64p-2f},
    { 0x1.00740cp-1f},
    { 0x1.01cfc8p-1f},
    { 0x1.032ae6p-1f},
    { 0x1.048562p-1f},
    { 0x1.05df3ep-1f},
    { 0x1.07387ap-1f},
    { 0x1.089112p-1f},
    { 0x1.09e908p-1f},
    { 0x1.0b4058p-1f},
    { 0x1.0c9704p-1f},
    { 0x1.0ded0cp-1f},
    { 0x1.0f426cp-1f},
    { 0x1.109724p-1f},
    { 0x1.11eb36p-1f},
    { 0x1.133e9cp-1f},
    { 0x1.14915ap-1f},
    { 0x1.15e36ep-1f},
    { 0x1.1734d6p-1f},
    { 0x1.188592p-1f},
    { 0x1.19d5ap-1f},
    { 0x1.1b2502p-1f},
    { 0x1.1c73b4p-1f},
    { 0x1.1dc1b6p-1f},
    { 0x1.1f0f08p-1f},
    { 0x1.205baap-1f},
    { 0x1.21a79ap-1f},
    { 0x1.22f2d6p-1f},
    { 0x1.243d6p-1f},
    { 0x1.258734p-1f},
    { 0x1.26d054p-1f},
    { 0x1.2818bep-1f},
    { 0x1.296072p-1f},
    { 0x1.2aa76ep-1f},
    { 0x1.2bedb2p-1f},
    { 0x1.2d333ep-1f},
    { 0x1.2e780ep-1f},
    { 0x1.2fbc24p-1f},
    { 0x1.30ff8p-1f},
    { 0x1.32421ep-1f},
    { 0x1.3384p-1f},
    { 0x1.34c526p-1f},
    { 0x1.36058cp-1f},
    { 0x1.374532p-1f},
    { 0x1.388418p-1f},
    { 0x1.39c23ep-1f},
    { 0x1.3affa2p-1f},
    { 0x1.3c3c44p-1f},
    { 0x1.3d7824p-1f},
    { 0x1.3eb33ep-1f},
    { 0x1.3fed96p-1f},
    { 0x1.412726p-1f},
    { 0x1.425ff2p-1f},
    { 0x1.4397f6p-1f},
    { 0x1.44cf32p-1f},
    { 0x1.4605a6p-1f},
    { 0x1.473b52p-1f},
    { 0x1.487034p-1f},
    { 0x1.49a44ap-1f},
    { 0x1.4ad796p-1f},
    { 0x1.4c0a14p-1f},
    { 0x1.4d3bc6p-1f},
    { 0x1.4e6cacp-1f},
    { 0x1.4f9cc2p-1f},
    { 0x1.50cc0ap-1f},
    { 0x1.51fa82p-1f},
    { 0x1.53282ap-1f},
    { 0x1.5455p-1f},
    { 0x1.558104p-1f},
    { 0x1.56ac36p-1f},
    { 0x1.57d694p-1f},
    { 0x1.59001ep-1f},
    { 0x1.5a28d2p-1f},
    { 0x1.5b50b2p-1f},
    { 0x1.5c77bcp-1f},
    { 0x1.5d9deep-1f},
    { 0x1.5ec34ap-1f},
    { 0x1.5fe7ccp-1f},
    { 0x1.610b76p-1f},
    { 0x1.622e44p-1f},
    { 0x1.63503ap-1f},
    { 0x1.647154p-1f},
    { 0x1.659192p-1f},
    { 0x1.66b0f4p-1f},
    { 0x1.67cf78p-1f},
    { 0x1.68ed1ep-1f},
    { 0x1.6a09e6p-1f},
    { 0x1.6b25cep-1f},
    { 0x1.6c40d8p-1f},
    { 0x1.6d5afep-1f},
    { 0x1.6e7446p-1f},
    { 0x1.6f8caap-1f},
    { 0x1.70a42cp-1f},
    { 0x1.71bacap-1f},
    { 0x1.72d084p-1f},
    { 0x1.73e558p-1f},
    { 0x1.74f948p-1f},
    { 0x1.760c52p-1f},
    { 0x1.771e76p-1f},
    { 0x1.782fb2p-1f},
    { 0x1.794006p-1f},
    { 0x1.7a4f7p-1f},
    { 0x1.7b5df2p-1f},
    { 0x1.7c6b8ap-1f},
    { 0x1.7d7836p-1f},
    { 0x1.7e83f8p-1f},
    { 0x1.7f8ecep-1f},
    { 0x1.8098b8p-1f},
    { 0x1.81a1b4p-1f},
    { 0x1.82a9c2p-1f},
    { 0x1.83b0ep-1f},
    { 0x1.84b712p-1f},
    { 0x1.85bc52p-1f},
    { 0x1.86c0a2p-1f},
    { 0x1.87c4p-1f},
    { 0x1.88c66ep-1f},
    { 0x1.89c7eap-1f},
    { 0x1.8ac872p-1f},
    { 0x1.8bc806p-1f},
    { 0x1.8cc6a8p-1f},
    { 0x1.8dc454p-1f},
    { 0x1.8ec10ap-1f},
    { 0x1.8fbccap-1f},
    { 0x1.90b794p-1f},
    { 0x1.91b166p-1f},
    { 0x1.92aa42p-1f},
    { 0x1.93a224p-1f},
    { 0x1.94990ep-1f},
    { 0x1.958efep-1f},
    { 0x1.9683f4p-1f},
    { 0x1.9777fp-1f},
    { 0x1.986afp-1f},
    { 0x1.995cf2p-1f},
    { 0x1.9a4dfap-1f},
    { 0x1.9b3e04p-1f},
    { 0x1.9c2d12p-1f},
    { 0x1.9d1b2p-1f},
    { 0x1.9e082ep-1f},
    { 0x1.9ef43ep-1f},
    { 0x1.9fdf5p-1f},
    { 0x1.a0c95ep-1f},
    { 0x1.a1b26ep-1f},
    { 0x1.a29a7ap-1f},
    { 0x1.a38184p-1f},
    { 0x1.a4678cp-1f},
    { 0x1.a54c92p-1f},
    { 0x1.a63092p-1f},
    { 0x1.a7138ep-1f},
    { 0x1.a7f586p-1f},
    { 0x1.a8d676p-1f},
    { 0x1.a9b662p-1f},
    { 0x1.aa9548p-1f},
    { 0x1.ab7326p-1f},
    { 0x1.ac4ffcp-1f},
    { 0x1.ad2bcap-1f},
    { 0x1.ae069p-1f},
    { 0x1.aee04cp-1f},
    { 0x1.afb8fep-1f},
    { 0x1.b090a6p-1f},
    { 0x1.b16742p-1f},
    { 0x1.b23cd4p-1f},
    { 0x1.b3115ap-1f},
    { 0x1.b3e4d4p-1f},
    { 0x1.b4b74p-1f},
    { 0x1.b588ap-1f},
    { 0x1.b658f2p-1f},
    { 0x1.b72834p-1f},
    { 0x1.b7f668p-1f},
    { 0x1.b8c38ep-1f},
    { 0x1.b98fa2p-1f},
    { 0x1.ba5aa6p-1f},
    { 0x1.bb249ap-1f},
    { 0x1.bbed7cp-1f},
    { 0x1.bcb54cp-1f},
    { 0x1.bd7c0ap-1f},
    { 0x1.be41b6p-1f},
    { 0x1.bf064ep-1f},
    { 0x1.bfc9d2p-1f},
    { 0x1.c08c42p-1f},
    { 0x1.c14d9ep-1f},
    { 0x1.c20de4p-1f},
    { 0x1.c2cd14p-1f},
    { 0x1.c38b3p-1f},
    { 0x1.c44834p-1f},
    { 0x1.c5042p-1f},
    { 0x1.c5bef6p-1f},
    { 0x1.c678b4p-1f},
    { 0x1.c73158p-1f},
    { 0x1.c7e8e6p-1f},
    { 0x1.c89f58p-1f},
    { 0x1.c954b2p-1f},
    { 0x1.ca08f2p-1f},
    { 0x1.cabc16p-1f},
    { 0x1.cb6e2p-1f},
    { 0x1.cc1f1p-1f},
    { 0x1.cccee2p-1f},
    { 0x1.cd7d98p-1f},
    { 0x1.ce2b32p-1f},
    { 0x1.ced7bp-1f},
    { 0x1.cf830ep-1f},
    { 0x1.d02d5p-1f},
    { 0x1.d0d672p-1f},
    { 0x1.d17e78p-1f},
    { 0x1.d2255cp-1f},
    { 0x1.d2cb22p-1f},
    { 0x1.d36fc8p-1f},
    { 0x1.d4134ep-1f},
    { 0x1.d4b5b2p-1f},
    { 0x1.d556f6p-1f},
    { 0x1.d5f718p-1f},
    { 0x1.d69618p-1f},
    { 0x1.d733f6p-1f},
    { 0x1.d7d0bp-1f},
    { 0x1.d86c48p-1f},
    { 0x1.d906bcp-1f},
    { 0x1.d9a00ep-1f},
    { 0x1.da383ap-1f},
    { 0x1.dacf42p-1f},
    { 0x1.db6526p-1f},
    { 0x1.dbf9e4p-1f},
    { 0x1.dc8d7cp-1f},
    { 0x1.dd1ffp-1f},
    { 0x1.ddb13cp-1f},
    { 0x1.de416p-1f},
    { 0x1.ded06p-1f},
    { 0x1.df5e36p-1f},
    { 0x1.dfeae6p-1f},
    { 0x1.e0766ep-1f},
    { 0x1.e100ccp-1f},
    { 0x1.e18a02p-1f},
    { 0x1.e2121p-1f},
    { 0x1.e298f4p-1f},
    { 0x1.e31eaep-1f},
    { 0x1.e3a33ep-1f},
    { 0x1.e426a4p-1f},
    { 0x1.e4a8ep-1f},
    { 0x1.e529fp-1f},
    { 0x1.e5a9d6p-1f},
    { 0x1.e6288ep-1f},
    { 0x1.e6a61cp-1f},
    { 0x1.e7227ep-1f},
    { 0x1.e79db2p-1f},
    { 0x1.e817bap-1f},
    { 0x1.e89096p-1f},
    { 0x1.e90844p-1f},
    { 0x1.e97ec4p-1f},
    { 0x1.e9f416p-1f},
    { 0x1.ea683ap-1f},
    { 0x1.eadb2ep-1f},
    { 0x1.eb4cf6p-1f},
    { 0x1.ebbd8cp-1f},
    { 0x1.ec2cf4p-1f},
    { 0x1.ec9b2ep-1f},
    { 0x1.ed0836p-1f},
    { 0x1.ed740ep-1f},
    { 0x1.eddeb6p-1f},
    { 0x1.ee482ep-1f},
    { 0x1.eeb074p-1f},
    { 0x1.ef178ap-1f},
    { 0x1.ef7d6ep-1f},
    { 0x1.efe22p-1f},
    { 0x1.f045a2p-1f},
    { 0x1.f0a7fp-1f},
    { 0x1.f1090cp-1f},
    { 0x1.f168f6p-1f},
    { 0x1.f1c7acp-1f},
    { 0x1.f2253p-1f},
    { 0x1.f2818p-1f},
    { 0x1.f2dc9cp-1f},
    { 0x1.f33686p-1f},
    { 0x1.f38f3ap-1f},
    { 0x1.f3e6bcp-1f},
    { 0x1.f43d08p-1f},
    { 0x1.f4922p-1f},
    { 0x1.f4e604p-1f},
    { 0x1.f538b2p-1f},
    { 0x1.f58a2cp-1f},
    { 0x1.f5da6ep-1f},
    { 0x1.f6297cp-1f},
    { 0x1.f67756p-1f},
    { 0x1.f6c3f8p-1f},
    { 0x1.f70f64p-1f},
    { 0x1.f7599ap-1f},
    { 0x1.f7a29ap-1f},
    { 0x1.f7ea62p-1f},
    { 0x1.f830f4p-1f},
    { 0x1.f8765p-1f},
    { 0x1.f8ba74p-1f},
    { 0x1.f8fd6p-1f},
    { 0x1.f93f14p-1f},
    { 0x1.f97f92p-1f},
    { 0x1.f9bed8p-1f},
    { 0x1.f9fce6p-1f},
    { 0x1.fa39bap-1f},
    { 0x1.fa7558p-1f},
    { 0x1.faafbcp-1f},
    { 0x1.fae8e8p-1f},
    { 0x1.fb20dcp-1f},
    { 0x1.fb5798p-1f},
    { 0x1.fb8d18p-1f},
    { 0x1.fbc162p-1f},
    { 0x1.fbf47p-1f},
    { 0x1.fc2648p-1f},
    { 0x1.fc56e4p-1f},
    { 0x1.fc8646p-1f},
    { 0x1.fcb47p-1f},
    { 0x1.fce16p-1f},
    { 0x1.fd0d16p-1f},
    { 0x1.fd3792p-1f},
    { 0x1.fd60d2p-1f},
    { 0x1.fd88dap-1f},
    { 0x1.fdafa8p-1f},
    { 0x1.fdd53ap-1f},
    { 0x1.fdf992p-1f},
    { 0x1.fe1cbp-1f},
    { 0x1.fe3e92p-1f},
    { 0x1.fe5f3ap-1f},
    { 0x1.fe7ea8p-1f},
    { 0x1.fe9cdap-1f},
    { 0x1.feb9d2p-1f},
    { 0x1.fed58ep-1f},
    { 0x1.fef01p-1f},
    { 0x1.ff0956p-1f},
    { 0x1.ff2162p-1f},
    { 0x1.ff383p-1f},
    { 0x1.ff4dc6p-1f},
    { 0x1.ff621ep-1f},
    { 0x1.ff753cp-1f},
    { 0x1.ff871ep-1f},
    { 0x1.ff97c4p-1f},
    { 0x1.ffa72ep-1f},
    { 0x1.ffb55ep-1f},
    { 0x1.ffc252p-1f},
    { 0x1.ffce0ap-1f},
    { 0x1.ffd886p-1f},
    { 0x1.ffe1c6p-1f},
    { 0x1.ffe9ccp-1f},
    { 0x1.fff094p-1f},
    { 0x1.fff622p-1f},
    { 0x1.fffa72p-1f},
    { 0x1.fffd88p-1f},
    { 0x1.ffff62p-1f}
};

float mlm_16_sin_fp32(float);
float mlm_16_sin_fp32(float vx){
    int32_t tmp;
    int32_t tmp1;
    uint32_t _srl_cast;
    int32_t tmp2;
    int32_t tmp3;
    int32_t tmp4;
    int32_t tmp5;
    int NaN_or_Inf;
    
    tmp = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst);
    tmp1 = float_to_32b_encoding(vx);
    _srl_cast = tmp1;
    tmp2 = _srl_cast >> tmp;
    tmp3 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst1);
    tmp4 = tmp2 & tmp3;
    tmp5 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst2);
    NaN_or_Inf = tmp4 == tmp5;

    if (__builtin_expect(NaN_or_Inf, 0)) {
        float tmp0;

        feclearexcept(FE_ALL_EXCEPT);
        tmp0 = _mm_cvtss_f32(mlm_16_sin_fp32_cst3);
        return tmp0;
    } else {
        int32_t modk;
        float red_vx;
        float tmp0;
        int tmp6;
        __m128 tmp7;
        __m128 pm_5;
        __m128 pa_5;
        __m128 pm_4;
        __m128 pa_4;
        __m128 pm_3;
        __m128 pa_3;
        __m128 pm_2;
        __m128 pa_2;
        __m128 tmp8;
        __m128 tmp9;
        __m128 poly_cos;
        int32_t tmp10;
        float tab_cos;
        __m128 tmp11;
        __m128 mul_cos_x;
        float tmp12;
        float tmp13;
        float tmp14;
        float mul_cos_y;
        __m128 tmp15;
        __m128 mul_cos;
        __m128 red_vx2_;
        __m128 pm_51;
        __m128 pa_51;
        __m128 pm_41;
        __m128 pa_41;
        __m128 pm_31;
        __m128 pa_31;
        __m128 tmp16;
        __m128 tmp17;
        __m128 poly_sin;
        __m128i tmp18;
        __m128i tmp19;
        int32_t tmp20;
        int32_t tmp21;
        int32_t sin_index;
        float tab_sin;
        float tmp22;
        __m128 tmp23;
        __m128 mul_sin_x;
        float tmp24;
        float tmp25;
        float tmp26;
        float mul_sin_y;
        __m128 tmp27;
        __m128 tmp28;
        float tmp29;
        float mul_sin;
        __m128 tmp30;
        __m128 tmp31;
        __m128 tmp32;
        float tmp33;
        float tmp34;
        float tmp35;
        __m128 tmp36;
        __m128 tmp37;
        float tmp38;
        float mul_coeff_sin;
        __m128 tmp39;
        __m128 tmp40;
        __m128 cos_eval_d_1;
        float tmp41;

        tmp0 = _mm_cvtss_f32(mlm_16_sin_fp32_cst4);
        tmp6 = vx >= tmp0;

        if (__builtin_expect(tmp6, 0)) {
            int32_t tmp7;
            int32_t tmp8;
            int32_t tmp9;
            uint32_t _srl_cast0;
            int32_t tmp10;
            int32_t tmp11;
            int32_t tmp12;
            __m128i tmp13;
            __m128i tmp14;
            __m128i id_tmp;
            __m128i tmp15;
            __m128i tmp16;
            int32_t tmp17;
            int32_t lsb_exp;
            __m128i tmp18;
            __m128i id_tmp1;
            int32_t tmp19;
            int32_t tmp20;
            int32_t tmp21;
            int32_t lsb_index;
            int32_t tmp22;
            int32_t tmp23;
            int32_t tmp24;
            __m128i tmp25;
            __m128i tmp26;
            int32_t tmp27;
            int32_t tmp28;
            int32_t tmp29;
            int32_t msb_exp;
            __m128i tmp30;
            __m128i id_tmp2;
            int32_t tmp31;
            int tmp32;
            int32_t tmp33;
            int32_t tmp34;
            int32_t tmp35;
            int32_t msb_index;
            int32_t tmp36;
            int32_t tmp37;
            int32_t tmp38;
            float vx_hi_ph;
            __m128 tmp39;
            __m128 tmp40;
            __m128 vx_lo_ph;
            float tmp41;
            int32_t i;
            float acc;
            float tmp42;
            int32_t acc_int;
            int32_t tmp43;
            float lar_vx;
            __m128 tmp44;
            __m128 tmp45;
            __m128 tmp46;
            __m128 lar_red_vx;
            float tmp47;
            int32_t tmp48;
            int tmp49;
            __m128i tmp50;
            int32_t tmp51;
            int32_t ph_acc_int_red;
            __m128i tmp52;
            __m128i lar_offset_k;
            int32_t tmp53;
            int32_t tmp54;
            int32_t lar_modk;
            __m128i tmp74;

            tmp7 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst5);
            tmp8 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst7);
            tmp9 = float_to_32b_encoding(vx);
            _srl_cast0 = tmp9;
            tmp10 = _srl_cast0 >> tmp8;
            tmp11 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst8);
            tmp12 = tmp10 & tmp11;
            tmp13 = _mm_set1_epi32(tmp12);
            tmp14 = _mm_add_epi32(tmp13, mlm_16_sin_fp32_cst6);
            id_tmp = tmp14;
            tmp15 = _mm_add_epi32(id_tmp, mlm_16_sin_fp32_cst9);
            tmp16 = _mm_add_epi32(tmp15, mlm_16_sin_fp32_cst10);
            tmp17 = _mm_cvtsi128_si32(tmp16);
            lsb_exp =  - tmp17;
            tmp18 = _mm_set1_epi32(lsb_exp);
            id_tmp1 = tmp18;
            tmp19 = _mm_cvtsi128_si32(id_tmp1);
            tmp20 = tmp7 - tmp19;
            tmp21 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst11);
            lsb_index = tmp20 / tmp21;
            tmp22 = _mm_cvtsi128_si32(id_tmp);
            tmp23 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst13);
            tmp24 = tmp22 - tmp23;
            tmp25 = _mm_set1_epi32(tmp24);
            tmp26 = _mm_add_epi32(tmp25, mlm_16_sin_fp32_cst12);
            tmp27 = _mm_cvtsi128_si32(tmp26);
            tmp28 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst14);
            tmp29 = tmp27 - tmp28;
            msb_exp =  - tmp29;
            tmp30 = _mm_set1_epi32(msb_exp);
            id_tmp2 = tmp30;
            tmp31 = _mm_cvtsi128_si32(id_tmp2);
            tmp32 = tmp7 < tmp31;
            tmp33 = tmp7 - tmp31;
            tmp34 = tmp33 / tmp21;
            tmp35 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst15);
            msb_index = tmp32 ? tmp35 : tmp34;
            tmp36 = float_to_32b_encoding(vx);
            tmp37 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst16);
            tmp38 = tmp36 & tmp37;
            vx_hi_ph = float_from_32b_encoding(tmp38);
            tmp39 = _mm_set_ss(vx);
            tmp40 = _mm_set_ss(vx_hi_ph);
            vx_lo_ph = _mm_sub_ss(tmp39, tmp40);
            tmp41 = _mm_cvtss_f32(vx_lo_ph);
            i = msb_index;
            tmp42 = _mm_cvtss_f32(mlm_16_sin_fp32_cst17);
            acc = tmp42;
            tmp43 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst18);
            acc_int = tmp43;

            for (;(i <= lsb_index);){
                __m128 tmp44;
                __m128i tmp45;
                __m128i tmp46;
                int32_t tmp47;
                int32_t tmp48;
                int32_t tmp49;
                int32_t tmp50;
                __m128i tmp51;
                __m128i tmp52;
                __m128i tmp53;
                __m128i pre_exclude_hi;
                int32_t tmp54;
                int32_t tmp55;
                int exclude_hi;
                int32_t tmp56;
                float sca_load;
                __m128 tmp57;
                __m128 tmp58;
                int32_t tmp59;
                float cst_load;
                __m128 tmp60;
                __m128 tmp61;
                __m128 hi_mult;
                float tmp62;
                __m128 carg;
                int32_t hi_mult_int;
                float hi_mult_int_f;
                __m128 tmp63;
                __m128 hi_mult_red;
                float tmp64;
                float tmp65;
                float tmp66;
                __m128 tmp67;
                __m128 tmp68;
                __m128 tmp69;
                __m128 tmp70;
                __m128 lo_mult;
                float tmp71;
                __m128 carg1;
                int32_t lo_mult_int;
                float lo_mult_int_f;
                __m128 tmp72;
                __m128 lo_mult_red;
                __m128 acc_expr;
                float tmp73;
                int32_t tmp75;
                int32_t tmp76;
                __m128i tmp77;
                __m128i tmp78;
                __m128i tmp79;
                __m128i tmp80;
                int32_t tmp81;
                int32_t tmp82;
                int32_t int_expr;
                __m128 carg2;
                int32_t tmp83;
                float id_tmp0;
                __m128 tmp84;
                __m128 tmp85;
                float tmp86;
                __m128i tmp87;
                __m128i tmp88;
                __m128i tmp89;
                int32_t tmp90;
                __m128i tmp91;
                int32_t tmp92;

                tmp44 = _mm_set_ss(acc);
                tmp45 = _mm_set1_epi32(i);
                tmp46 = _mm_add_epi32(tmp45, mlm_16_sin_fp32_cst19);
                tmp47 = _mm_cvtsi128_si32(tmp46);
                tmp48 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst20);
                tmp49 = tmp47 * tmp48;
                tmp50 = tmp7 - tmp49;
                tmp51 = _mm_set1_epi32(tmp50);
                tmp52 = _mm_add_epi32(tmp51, mlm_16_sin_fp32_cst19);
                tmp53 = _mm_add_epi32(id_tmp, mlm_16_sin_fp32_cst21);
                pre_exclude_hi = _mm_add_epi32(tmp52, tmp53);
                tmp54 = _mm_cvtsi128_si32(pre_exclude_hi);
                tmp55 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst22);
                exclude_hi = tmp54 <= tmp55;
                tmp56 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst23);
                sca_load = PH_scale_table[i][tmp56];
                tmp57 = _mm_set_ss(sca_load);
                tmp58 = _mm_mul_ss(tmp40, tmp57);
                tmp59 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst24);
                cst_load = PH_cst_table[i][tmp59];
                tmp60 = _mm_set_ss(cst_load);
                tmp61 = _mm_mul_ss(tmp60, tmp57);
                hi_mult = _mm_mul_ss(tmp58, tmp61);
                tmp62 = _mm_cvtss_f32(hi_mult);
                carg = _mm_set_ss(tmp62);
                hi_mult_int = _mm_cvt_ss2si(carg);
                hi_mult_int_f = hi_mult_int;
                tmp63 = _mm_set_ss(hi_mult_int_f);
                hi_mult_red = _mm_sub_ss(hi_mult, tmp63);
                tmp64 = _mm_cvtss_f32(hi_mult_red);
                tmp65 = _mm_cvtss_f32(mlm_16_sin_fp32_cst25);
                tmp66 = exclude_hi ? tmp64 : tmp65;
                tmp67 = _mm_set_ss(tmp66);
                tmp68 = _mm_add_ss(tmp44, tmp67);
                tmp69 = _mm_mul_ss(vx_lo_ph, tmp57);
                tmp70 = _mm_mul_ss(tmp60, tmp57);
                lo_mult = _mm_mul_ss(tmp69, tmp70);
                tmp71 = _mm_cvtss_f32(lo_mult);
                carg1 = _mm_set_ss(tmp71);
                lo_mult_int = _mm_cvt_ss2si(carg1);
                lo_mult_int_f = lo_mult_int;
                tmp72 = _mm_set_ss(lo_mult_int_f);
                lo_mult_red = _mm_sub_ss(lo_mult, tmp72);
                acc_expr = _mm_add_ss(tmp68, lo_mult_red);
                tmp73 = _mm_cvtss_f32(acc_expr);
                tmp74 = _mm_set1_epi32(acc_int);
                tmp75 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst26);
                tmp76 = exclude_hi ? hi_mult_int : tmp75;
                tmp77 = _mm_set1_epi32(tmp76);
                tmp78 = _mm_add_epi32(tmp74, tmp77);
                tmp79 = _mm_set1_epi32(lo_mult_int);
                tmp80 = _mm_add_epi32(tmp78, tmp79);
                tmp81 = _mm_cvtsi128_si32(tmp80);
                tmp82 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst27);
                int_expr = tmp81 % tmp82;
                carg2 = _mm_set_ss(tmp73);
                tmp83 = _mm_cvt_ss2si(carg2);
                id_tmp0 = tmp83;
                tmp84 = _mm_set_ss(id_tmp0);
                tmp85 = _mm_sub_ss(acc_expr, tmp84);
                tmp86 = _mm_cvtss_f32(tmp85);
                acc = tmp86;
                tmp87 = _mm_set1_epi32(int_expr);
                tmp88 = _mm_set1_epi32(tmp83);
                tmp89 = _mm_add_epi32(tmp87, tmp88);
                tmp90 = _mm_cvtsi128_si32(tmp89);
                acc_int = tmp90;
                tmp91 = _mm_add_epi32(tmp45, mlm_16_sin_fp32_cst28);
                tmp92 = _mm_cvtsi128_si32(tmp91);
                i = tmp92;
            }
            lar_vx = acc;
            tmp44 = _mm_set_ss(lar_vx);
            tmp45 = _mm_mul_ss(tmp44, mlm_16_sin_fp32_cst29);
            tmp46 = _mm_mul_ss(tmp44, mlm_16_sin_fp32_cst30);
            lar_red_vx = _mm_add_ss(tmp45, tmp46);
            tmp47 = _mm_cvtss_f32(lar_red_vx);
            red_vx = tmp47;
            tmp48 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst32);
            tmp49 = acc_int < tmp48;
            tmp50 = _mm_add_epi32(mlm_16_sin_fp32_C32, tmp74);
            tmp51 = _mm_cvtsi128_si32(tmp50);
            ph_acc_int_red = tmp49 ? tmp51 : acc_int;
            tmp52 = _mm_set1_epi32(ph_acc_int_red);
            lar_offset_k = _mm_add_epi32(tmp52, mlm_16_sin_fp32_cst31);
            tmp53 = _mm_cvtsi128_si32(lar_offset_k);
            tmp54 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst33);
            lar_modk = tmp53 & tmp54;
            modk = lar_modk;
        } else {
            __m128 tmp7;
            __m128 tmp8;
            __m128 tmp9;
            __m128 vx_pi;
            float tmp10;
            __m128 carg;
            int32_t k;
            __m128i tmp11;
            __m128i offset_k;
            int32_t tmp12;
            int32_t tmp13;
            int32_t modk0;
            float fk;
            __m128 tmp14;
            __m128 tmp15;
            __m128 tmp16;
            float tmp17;
            __m128 tmp18;
            __m128 tmp19;
            __m128 s;
            __m128 z;
            __m128 t;
            __m128 red_vx_std;
            float tmp20;

            tmp7 = _mm_set_ss(vx);
            tmp8 = _mm_mul_ss(tmp7, mlm_16_sin_fp32_cst35);
            tmp9 = _mm_mul_ss(tmp7, mlm_16_sin_fp32_cst36);
            vx_pi = _mm_add_ss(tmp8, tmp9);
            tmp10 = _mm_cvtss_f32(vx_pi);
            carg = _mm_set_ss(tmp10);
            k = _mm_cvt_ss2si(carg);
            tmp11 = _mm_set1_epi32(k);
            offset_k = _mm_add_epi32(tmp11, mlm_16_sin_fp32_cst34);
            tmp12 = _mm_cvtsi128_si32(offset_k);
            tmp13 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst37);
            modk0 = tmp12 & tmp13;
            modk = modk0;
            fk = k;
            tmp14 = _mm_set_ss(fk);
            tmp15 = _mm_mul_ss(tmp14, mlm_16_sin_fp32_inv_frac_pi);
            tmp16 = _mm_sub_ss(tmp7, tmp15);
            tmp17 =  - fk;
            tmp18 = _mm_set_ss(tmp17);
            tmp19 = _mm_mul_ss(tmp18, mlm_16_sin_fp32_inv_frac_pi_lo);
            s = _mm_add_ss(tmp16, tmp19);
            z = _mm_sub_ss(s, tmp16);
            t = _mm_sub_ss(tmp19, z);
            red_vx_std = _mm_add_ss(s, t);
            tmp20 = _mm_cvtss_f32(red_vx_std);
            red_vx = tmp20;
        }
        tmp7 = _mm_set_ss(red_vx);
        pm_5 = _mm_mul_ss(tmp7, mlm_16_sin_fp32_c_6);
        pa_5 = _mm_add_ss(mlm_16_sin_fp32_c_5, pm_5);
        pm_4 = _mm_mul_ss(tmp7, pa_5);
        pa_4 = _mm_add_ss(mlm_16_sin_fp32_c_4, pm_4);
        pm_3 = _mm_mul_ss(tmp7, pa_4);
        pa_3 = _mm_add_ss(mlm_16_sin_fp32_c_3, pm_3);
        pm_2 = _mm_mul_ss(tmp7, pa_3);
        pa_2 = _mm_add_ss(mlm_16_sin_fp32_c_2, pm_2);
        tmp8 = _mm_mul_ss(tmp7, pa_2);
        tmp9 = _mm_add_ss(mlm_16_sin_fp32_c_1, tmp8);
        poly_cos = _mm_mul_ss(tmp7, tmp9);
        tmp10 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst38);
        tab_cos = mlm_16_sin_fp32_cos_table[modk][tmp10];
        tmp11 = _mm_set_ss(tab_cos);
        mul_cos_x = _mm_mul_ss(tmp11, poly_cos);
        tmp12 = _mm_cvtss_f32(mul_cos_x);
        tmp13 =  - tmp12;
        tmp14 = _mm_cvtss_f32(poly_cos);
        mul_cos_y = fmaf(tab_cos, tmp14, tmp13);
        tmp15 = _mm_set_ss(mul_cos_y);
        mul_cos = _mm_add_ss(mul_cos_x, tmp15);
        red_vx2_ = _mm_mul_ss(tmp7, tmp7);
        pm_51 = _mm_mul_ss(tmp7, mlm_16_sin_fp32_c_61);
        pa_51 = _mm_add_ss(mlm_16_sin_fp32_c_51, pm_51);
        pm_41 = _mm_mul_ss(tmp7, pa_51);
        pa_41 = _mm_add_ss(mlm_16_sin_fp32_c_41, pm_41);
        pm_31 = _mm_mul_ss(tmp7, pa_41);
        pa_31 = _mm_add_ss(mlm_16_sin_fp32_c_31, pm_31);
        tmp16 = _mm_mul_ss(tmp7, pa_31);
        tmp17 = _mm_add_ss(mlm_16_sin_fp32_c_21, tmp16);
        poly_sin = _mm_mul_ss(red_vx2_, tmp17);
        tmp18 = _mm_set1_epi32(modk);
        tmp19 = _mm_add_epi32(tmp18, mlm_16_sin_fp32_cst39);
        tmp20 = _mm_cvtsi128_si32(tmp19);
        tmp21 = _mm_cvtsi128_si32(mlm_16_sin_fp32_cst40);
        sin_index = tmp20 % tmp21;
        tab_sin = mlm_16_sin_fp32_cos_table[sin_index][tmp10];
        tmp22 =  - tab_sin;
        tmp23 = _mm_set_ss(tmp22);
        mul_sin_x = _mm_mul_ss(tmp23, poly_sin);
        tmp24 = _mm_cvtss_f32(mul_sin_x);
        tmp25 =  - tmp24;
        tmp26 = _mm_cvtss_f32(poly_sin);
        mul_sin_y = fmaf(tmp22, tmp26, tmp25);
        tmp27 = _mm_set_ss(mul_sin_y);
        tmp28 = _mm_add_ss(mul_sin_x, tmp27);
        tmp29 = _mm_cvtss_f32(tmp28);
        mul_sin =  - tmp29;
        tmp30 = _mm_set_ss(mul_sin);
        tmp31 = _mm_add_ss(mul_cos, tmp30);
        tmp32 = _mm_mul_ss(tmp23, tmp7);
        tmp33 = _mm_cvtss_f32(tmp32);
        tmp34 =  - tmp33;
        tmp35 = fmaf(tmp22, red_vx, tmp34);
        tmp36 = _mm_set_ss(tmp35);
        tmp37 = _mm_add_ss(tmp32, tmp36);
        tmp38 = _mm_cvtss_f32(tmp37);
        mul_coeff_sin =  - tmp38;
        tmp39 = _mm_set_ss(mul_coeff_sin);
        tmp40 = _mm_add_ss(tmp31, tmp39);
        cos_eval_d_1 = _mm_add_ss(tmp40, tmp11);
        tmp41 = _mm_cvtss_f32(cos_eval_d_1);
        return tmp41;
    }
}
