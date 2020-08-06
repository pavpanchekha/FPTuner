#include "log.h"


// Generated for input range: [0.75;1.5]


fp32 ord_01_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.70234584856389451029799384535~6/8~e-1
  // Relative algorithmic error: 0.173219799809884599088629996546~1/3~
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * 0x1.e71dd2p-1f ;
}

fp64 ord_01_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.7023458069810978598457132718~3/4~e-1
  // Relative algorithmic error: 0.173219789554305095112970710848~6/8~
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * 0x1.e71dd1b88fb15p-1 ;
}


fp32 ord_02_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.81450908895745992631693654643~4/6~e-2
  // Relative algorithmic error: 0.200883037067879706534674716327~4/6~e-1
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1.04414ep0f + xsub * (-0x1.c69e34p-2f)) ;
}

fp64 ord_02_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.81450946477029633251438456013~4/6~e-2
  // Relative algorithmic error: 0.20088275131043820611556597630~8/9~e-1
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.04414d73fec15p0 + xsub * (-0x1.c69e30a237bcp-2)) ;
}


fp32 ord_03_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.105317239796965122511188453565~0/2~e-2
  // Relative algorithmic error: 0.259744273159184004885069162092~1/4~e-2
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1.00875cp0f + xsub * (-0x1.076a52p-1f + xsub * 0x1.176628p-2f)) ;
}

fp64 ord_03_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.105316615493930853541918238399~0/2~e-2
  // Relative algorithmic error: 0.259742733473817194332841338494~4/7~e-2
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.00875c5c3df0ap0 + xsub * (-0x1.076a520847f1p-1 + xsub * 0x1.17661f03379fcp-2)) ;
}


fp32 ord_04_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.145015072466444966294365464349~1/3~e-3
  // Relative algorithmic error: 0.3576537161873477321935887593~6/7~e-3
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1.fff12p-1f + xsub * (-0x1.01f224p-1f + xsub * (0x1.60ee6cp-2f + xsub * (-0x1.81341p-3f)))) ;
}

fp64 ord_04_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.145014454012389637395732371700~0/2~e-3
  // Relative algorithmic error: 0.35764965004659423737538013940~6/7~e-3
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.fff11fb8250c4p-1 + xsub * (-0x1.01f2241a4c19bp-1 + xsub * (0x1.60ee7544fbaa1p-2 + xsub * (-0x1.8134291fcee9ap-3)))) ;
}


fp32 ord_05_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.207803692504644422749704731508~6/8~e-4
  // Relative algorithmic error: 0.512619796989371633125024960978~3/7~e-4
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1.fff948p-1f + xsub * (-0x1.fffaf6p-2f + xsub * (0x1.5a9deep-2f + xsub * (-0x1.081e34p-2f + xsub * 0x1.1ad316p-3f)))) ;
}

fp64 ord_05_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.207806477904419835116867361798~0/2~e-4
  // Relative algorithmic error: 0.512513835983989157644297680326~1/6~e-4
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.fff9485b188fdp-1 + xsub * (-0x1.fffaf74e758adp-2 + xsub * (0x1.5a9de204e1733p-2 + xsub * (-0x1.081e143b2e08p-2 + xsub * 0x1.1ad2f61923482p-3)))) ;
}


fp32 ord_06_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.305892752261161515911155809913~6/9~e-5
  // Relative algorithmic error: 0.7570107521120046479767981945~0/1~e-5
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1.ffffaap-1f + xsub * (-0x1.ffdfeap-2f + xsub * (0x1.559516p-2f + xsub * (-0x1.064826p-2f + xsub * (0x1.a2f3b6p-3f + xsub * (-0x1.b02d34p-4f)))))) ;
}

fp64 ord_06_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.30612192665292993088676779926~1/3~e-5
  // Relative algorithmic error: 0.75498957132115692581468328801~7/9~e-5
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.ffffaae7bf925p-1 + xsub * (-0x1.ffdfe99440f2p-2 + xsub * (0x1.5594c6118befep-2 + xsub * (-0x1.0647f1f390d0ep-2 + xsub * (0x1.a2f9ce1839abep-3 + xsub * (-0x1.b0400167dfb0fp-4)))))) ;
}


fp32 ord_07_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.459958410251143477363051275863~4/8~e-6
  // Relative algorithmic error: 0.11562084318349457841049724694~7/8~e-5
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1.00000ep0f + xsub * (-0x1.fffc62p-2f + xsub * (0x1.55249p-2f + xsub * (-0x1.00a568p-2f + xsub * (0x1.a760ecp-3f + xsub * (-0x1.57fbccp-3f + xsub * 0x1.532524p-4f)))))) ;
}

fp64 ord_07_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.46017207102587158982001732073~7/8~e-6
  // Relative algorithmic error: 0.113492398652620210514570238316~1/3~e-5
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.00000ed5775c1p0 + xsub * (-0x1.fffc691eda219p-2 + xsub * (0x1.5523de50960a8p-2 + xsub * (-0x1.00a3540790eep-2 + xsub * (0x1.a76da54db149cp-3 + xsub * (-0x1.5835dea2580dp-3 + xsub * 0x1.5391d1cf72d8fp-4)))))) ;
}


fp32 ord_08_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.72176025819775559502183099136~5/7~e-7
  // Relative algorithmic error: 0.185341579520358351583117556465~0/2~e-6
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1.000002p0f + xsub * (-0x1.00004ap-1f + xsub * (0x1.554c7ep-2f + xsub * (-0x1.ff85a6p-3f + xsub * (0x1.9bbbfcp-3f + xsub * (-0x1.63bfd4p-3f + xsub * (0x1.21e668p-3f + xsub * (-0x1.11793p-4f)))))))) ;
}

fp64 ord_08_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.70253932082619379936277254439~3/4~e-7
  // Relative algorithmic error: 0.173267520012416124689075853727~4/7~e-6
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.00000277a395ap0 + xsub * (-0x1.0000483b26345p-1 + xsub * (0x1.554bfa69517aap-2 + xsub * (-0x1.ff86514f112bdp-3 + xsub * (0x1.9bd001b0902f7p-3 + xsub * (-0x1.63c879f2b4f55p-3 + xsub * (0x1.216bad460d9eep-3 + xsub * (-0x1.1038fe0c995a9p-4)))))))) ;
}


fp32 ord_09_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.107116833210020283884419008634~2/4~e-7
  // Relative algorithmic error: 0.29475118047484639090347673911~1/2~e-7
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1p0f + xsub * (-0x1.000016p-1f + xsub * (0x1.5555d8p-2f + xsub * (-0x1.ffdc3p-3f + xsub * (0x1.99248ep-3f + xsub * (-0x1.58a3c8p-3f + xsub * (0x1.32d6ap-3f + xsub * (-0x1.eccaecp-4f + xsub * 0x1.b8277p-5f)))))))) ;
}

fp64 ord_09_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.108575708373434866199920996953~1/2~e-7
  // Relative algorithmic error: 0.267780667799665840232243388846~4/7~e-7
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.ffffffcdb4d65p-1 + xsub * (-0x1.00001647a590ep-1 + xsub * (0x1.555603017b1dfp-2 + xsub * (-0x1.ffdc71d73c905p-3 + xsub * (0x1.991b5048af206p-3 + xsub * (-0x1.588fd96afd9fdp-3 + xsub * (0x1.33165a4a444e3p-3 + xsub * (-0x1.eea99af9655a2p-4 + xsub * 0x1.bb489516568aep-5)))))))) ;
}


fp32 ord_10_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.189391324557075698906054054282~1/4~e-8
  // Relative algorithmic error: 0.53546742487936903979398895701~3/5~e-8
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1p0f + xsub * (-0x1p-1f + xsub * (0x1.5555a8p-2f + xsub * (-0x1.000048p-2f + xsub * (0x1.996834p-3f + xsub * (-0x1.54ec82p-3f + xsub * (0x1.28919ap-3f + xsub * (-0x1.0db426p-3f + xsub * (0x1.aca942p-4f + xsub * (-0x1.70c9fap-5f)))))))))) ;
}

fp64 ord_10_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.169471653833926399351709793938~7/9~e-8
  // Relative algorithmic error: 0.417968716261350736983107813916~2/6~e-8
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.ffffffdc57649p-1 + xsub * (-0x1.00000064ca304p-1 + xsub * (0x1.5555c627b675dp-2 + xsub * (-0x1.000032e9fa4cdp-2 + xsub * (0x1.996148429ec1bp-3 + xsub * (-0x1.54e7f53d8c1bp-3 + xsub * (0x1.28d5210039b5dp-3 + xsub * (-0x1.0e1ce10fc619ap-3 + xsub * (0x1.abc387bceca29p-4 + xsub * (-0x1.6d5d2d973ba6fp-5)))))))))) ;
}


fp32 ord_11_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.279779091666541499556402816553~0/3~e-9
  // Relative algorithmic error: 0.122662559814753848392864796921~5/7~e-8
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1p0f + xsub * (-0x1.fffffep-2f + xsub * (0x1.555558p-2f + xsub * (-0x1.00010cp-2f + xsub * (0x1.999a0ep-3f + xsub * (-0x1.54ff34p-3f + xsub * (0x1.24095ep-3f + xsub * (-0x1.0519d2p-3f + xsub * (0x1.e5595p-4f + xsub * (-0x1.7daf58p-4f + xsub * 0x1.3b65d2p-5f)))))))))) ;
}

fp64 ord_11_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.266696694630202599835727317214~4/7~e-9
  // Relative algorithmic error: 0.657755784475879882883034680957~3/9~e-9
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.fffffffd851cbp-1 + xsub * (-0x1.fffffec0eda1p-2 + xsub * (0x1.55555d7be2f24p-2 + xsub * (-0x1.0000d3dd39e4fp-2 + xsub * (0x1.99972c133fd98p-3 + xsub * (-0x1.5506549bd4feap-3 + xsub * (0x1.244c7d67a71bep-3 + xsub * (-0x1.05428617540b1p-3 + xsub * (0x1.e1c053af5841ep-4 + xsub * (-0x1.753cb560a0184p-4 + xsub * 0x1.302442b3a63ep-5)))))))))) ;
}


fp32 ord_12_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.54005463884123163758416519384~4/6~e-10
  // Relative algorithmic error: 0.14879815693884034686984170511~3/4~e-9
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1p0f + xsub * (-0x1p-1f + xsub * (0x1.555554p-2f + xsub * (-0x1.00000ep-2f + xsub * (0x1.999b4ep-3f + xsub * (-0x1.554fbap-3f + xsub * (0x1.24405ep-3f + xsub * (-0x1.fff9fap-4f + xsub * (0x1.d2533cp-4f + xsub * (-0x1.b00fe2p-4f + xsub * (0x1.480e6p-4f + xsub * (-0x1.022a6ap-5f)))))))))))) ;
}

fp64 ord_12_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.422597701466277997423951818790~5/9~e-10
  // Relative algorithmic error: 0.104225528744503135781751521823~5/7~e-9
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.0000000050779p0 + xsub * (-0x1.ffffffd544fd5p-2 + xsub * (0x1.55555252719d5p-2 + xsub * (-0x1.00001bde91c67p-2 + xsub * (0x1.999c263f79275p-3 + xsub * (-0x1.554db7c0bc2c8p-3 + xsub * (0x1.242ceeb1bb8abp-3 + xsub * (-0x1.ffefd4f1dfb84p-4 + xsub * (0x1.d37bae8d8e9a9p-4 + xsub * (-0x1.b204cd3d1a496p-4 + xsub * (0x1.47edabd221412p-4 + xsub * (-0x1.fe85c33faeebap-6)))))))))))) ;
}


fp32 ord_13_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.65989644636938436129684957432~2/4~e-11
  // Relative algorithmic error: 0.689102678339433743642462393322~0/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1p0f + xsub * (-0x1p-1f + xsub * (0x1.555554p-2f + xsub * (-0x1.fffffap-3f + xsub * (0x1.999a98p-3f + xsub * (-0x1.555892p-3f + xsub * (0x1.2474bcp-3f + xsub * (-0x1.feef44p-4f + xsub * (0x1.c8fcc8p-4f + xsub * (-0x1.aa600ep-4f + xsub * (0x1.85ce1cp-4f + xsub * (-0x1.1152p-4f + xsub * 0x1.7e67f8p-6f)))))))))))) ;
}

fp64 ord_13_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.673572196973169139045075615380~3/9~e-11
  // Relative algorithmic error: 0.166123424609181440333828949577~5/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.0000000010861p0 + xsub * (-0x1.000000024e0b2p-1 + xsub * (0x1.555554aacae4dp-2 + xsub * (-0x1.fffff6115b795p-3 + xsub * (0x1.999a1db015adap-3 + xsub * (-0x1.5558b15afd5cap-3 + xsub * (0x1.2482dd9a2c3fcp-3 + xsub * (-0x1.ff0dccb92c76cp-4 + xsub * (0x1.c7b06b21e759ep-4 + xsub * (-0x1.a79f0bfc3d1f8p-4 + xsub * (0x1.8a0d60b5587f2p-4 + xsub * (-0x1.21b55b13ecfd6p-4 + xsub * 0x1.af6f3517ad827p-6)))))))))))) ;
}


fp32 ord_14_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.37609042253312779344135928783~6/8~e-11
  // Relative algorithmic error: 0.332193882074506847575595350897~5/9~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1p0f + xsub * (-0x1p-1f + xsub * (0x1.555556p-2f + xsub * (-0x1p-2f + xsub * (0x1.999908p-3f + xsub * (-0x1.5554bep-3f + xsub * (0x1.24a7bap-3f + xsub * (-0x1.002b38p-3f + xsub * (0x1.c47c16p-4f + xsub * (-0x1.917f16p-4f + xsub * (0x1.8142e6p-4f + xsub * (-0x1.9d3f66p-4f + xsub * (0x1.69f0a2p-4f + xsub * (-0x1.3284a6p-5f)))))))))))))) ;
}

fp64 ord_14_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.107904272861810671484581469547~3/5~e-11
  // Relative algorithmic error: 0.266127688653933269304329632889~4/7~e-11
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.ffffffffff67ap-1 + xsub * (-0x1.00000000e6a3p-1 + xsub * (0x1.5555555ad2e0cp-2 + xsub * (-0x1.fffffc61c421bp-3 + xsub * (0x1.99998e7c6f7ccp-3 + xsub * (-0x1.55565370438a8p-3 + xsub * (0x1.24961b8a54e19p-3 + xsub * (-0x1.ffcc52758f0f4p-4 + xsub * (0x1.c60c29f18ca03p-4 + xsub * (-0x1.9af52c4388f9dp-4 + xsub * (0x1.83ca438fd8666p-4 + xsub * (-0x1.67e513fda2e49p-4 + xsub * (0x1.0114bfb1ecc19p-4 + xsub * (-0x1.6ebe9e618616dp-6)))))))))))))) ;
}


fp32 ord_15_log_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.305597450519280305582771183406~6/9~e-11
  // Relative algorithmic error: 0.331499080908913666421019151705~4/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp32 xsub = x - 1.0f;
  return  xsub * (0x1p0f + xsub * (-0x1p-1f + xsub * (0x1.555556p-2f + xsub * (-0x1.000002p-2f + xsub * (0x1.99990ep-3f + xsub * (-0x1.55533p-3f + xsub * (0x1.24a3eap-3f + xsub * (-0x1.005e3cp-3f + xsub * (0x1.c5e466p-4f + xsub * (-0x1.8cf25p-4f + xsub * (0x1.680ba8p-4f + xsub * (-0x1.98b1b8p-4f + xsub * (0x1.f9565ep-4f + xsub * (-0x1.ab599ap-4f + xsub * 0x1.3cdacep-5f)))))))))))))) ;
}

fp64 ord_15_log_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.17362347210109126505078170000~3/5~e-12
  // Relative algorithmic error: 0.428213120166967523669390013519~0/5~e-12
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  fp64 xsub = x - 1.0;
  return  xsub * (0x1.ffffffffff15bp-1 + xsub * (-0x1.0000000008ecfp-1 + xsub * (0x1.5555555bdccfcp-2 + xsub * (-0x1.ffffffe7fffb6p-3 + xsub * (0x1.999991e6cf0a4p-3 + xsub * (-0x1.555550c40f1edp-3 + xsub * (0x1.2493f19168b56p-3 + xsub * (-0x1.0003a512076cdp-3 + xsub * (0x1.c6cf31dec0647p-4 + xsub * (-0x1.98784b5090282p-4 + xsub * (0x1.769d5e6e18e67p-4 + xsub * (-0x1.65e4d72788133p-4 + xsub * (0x1.4a361df7c3234p-4 + xsub * (-0x1.c9eae5022a247p-5 + xsub * 0x1.39560bdec9db3p-6)))))))))))))) ;
}


