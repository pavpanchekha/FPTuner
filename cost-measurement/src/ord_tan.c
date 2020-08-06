#include "tan.h"


// Generated for input range: [0;0.78539816339744830961566084581987572104929234984379140812357603907383566711463950912153004138036333120250903700923769259014707577737368637826875783503055572509765625]









fp32 ord_01_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.120198351952775047967357413205~1/3~
  // Relative algorithmic error: error
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * 0x1.1ec55p0f ;
}








fp64 ord_01_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.120198307023114763790955111663~7/9~
  // Relative algorithmic error: error
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * 0x1.1ec550f5b2e78p0 ;
}


fp32 ord_02_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.85721202443458511401269402544~6/8~e-2
  // Relative algorithmic error: 0.85721240786341963108823648956~2/4~e-2
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fb9c7p-1f + (x*x) * 0x1.c1b3b8p-2f) ;
}

fp64 ord_02_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.85721152441659574999898333882~5/7~e-2
  // Relative algorithmic error: 0.85721209257014693816093344195~7/9~e-2
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fb9c6f8abcceap-1 + (x*x) * 0x1.c1b3ba2d82329p-2) ;
}


fp32 ord_03_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.61491862165338000193997352673~6/7~e-3
  // Relative algorithmic error: 0.61491862165338000193997352673~6/7~e-3
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.00284cp0f + (x*x) * (0x1.4371fcp-2f + (x*x) * 0x1.9e715ep-3f)) ;
}

fp64 ord_03_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.61491190304644217672180097798~3/5~e-3
  // Relative algorithmic error: 0.614911903050902655995105030957~2/8~e-3
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.00284c8283752p0 + (x*x) * (0x1.4371edd8c7082p-2 + (x*x) * 0x1.9e71842ff309p-3)) ;
}


fp32 ord_04_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.44141615464780821803166462594~7/9~e-4
  // Relative algorithmic error: 0.4416704177856445312~4/6~e-4
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffa36p-1f + (x*x) * (0x1.57a31ep-2f + (x*x) * (0x1.db087p-4f + (x*x) * 0x1.819018p-4f))) ;
}

fp64 ord_04_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.44144959692813564150039215841~1/3~e-4
  // Relative algorithmic error: 0.44144965951644584895473388571~7/9~e-4
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffa36bdaf052p-1 + (x*x) * (0x1.57a3099097c15p-2 + (x*x) * (0x1.db098379cfcd9p-4 + (x*x) * 0x1.818f121cf9a59p-4))) ;
}


fp32 ord_05_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.316430153981046681520765609629~1/5~e-5
  // Relative algorithmic error: 0.32186508178710937~4/6~e-5
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.000036p0f + (x*x) * (0x1.551296p-2f + (x*x) * (0x1.1799c2p-3f + (x*x) * (0x1.4ad39ap-5f + (x*x) * 0x1.67107p-5f)))) ;
}

fp64 ord_05_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.316943973522509870616887521979~4/7~e-5
  // Relative algorithmic error: 0.31694397353921495417134945458~1/2~e-5
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.0000352ca3d7bp0 + (x*x) * (0x1.5512df434bdb8p-2 + (x*x) * (0x1.1796597a0daa7p-3 + (x*x) * (0x1.4af18817f51e7p-5 + (x*x) * 0x1.66fa9c17c5a95p-5)))) ;
}


fp32 ord_06_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.226575473128357289912184938910~5/8~e-6
  // Relative algorithmic error: 0.238418579101562~4/6~e-6
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffff8p-1f + (x*x) * (0x1.555c52p-2f + (x*x) * (0x1.101098p-3f + (x*x) * (0x1.d49fb6p-5f + (x*x) * (0x1.994f54p-7f + (x*x) * 0x1.4e770cp-6f))))) ;
}

fp64 ord_06_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.227555285338048315713156948550~6/9~e-6
  // Relative algorithmic error: 0.22755545680022855490580470539~6/7~e-6
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffff85d50a2bp-1 + (x*x) * (0x1.555c3949a3ef1p-2 + (x*x) * (0x1.101264c322c27p-3 + (x*x) * (0x1.d4848870b8d68p-5 + (x*x) * (0x1.9a0209f1694d7p-7 + (x*x) * 0x1.4e41cb6d0d482p-6))))) ;
}


fp32 ord_07_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.175863854191290382707189005498~0/2~e-7
  // Relative algorithmic error: 0.182807352424623013332366087971~3/5~e-7
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.5554dcp-2f + (x*x) * (0x1.112e2p-3f + (x*x) * (0x1.b581ap-5f + (x*x) * (0x1.907be2p-6f + (x*x) * (0x1.9697f8p-9f + (x*x) * 0x1.33d5e6p-7f)))))) ;
}

fp64 ord_07_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.163377365185449257518340308675~0/2~e-7
  // Relative algorithmic error: 0.16337744844349554422863322640~7/8~e-7
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.000000462b88p0 + (x*x) * (0x1.5554a8a281e68p-2 + (x*x) * (0x1.11337280c8d95p-3 + (x*x) * (0x1.b5093b734c09fp-5 + (x*x) * (0x1.930f8aa39402cp-6 + (x*x) * (0x1.7b8d709b3ee4bp-9 + (x*x) * 0x1.373d6c5a6132dp-7)))))) ;
}


fp32 ord_08_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.127405666375954563240753998587~6/8~e-8
  // Relative algorithmic error: 0.127405666375954563240753998587~6/8~e-8
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.55556p-2f + (x*x) * (0x1.110dap-3f + (x*x) * (0x1.bad938p-5f + (x*x) * (0x1.5cc78ap-6f + (x*x) * (0x1.62a482p-7f + (x*x) * (0x1.b64e02p-14f + (x*x) * 0x1.1e5b6ep-8f))))))) ;
}

fp64 ord_08_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.117299679790840945299129006791~6/8~e-8
  // Relative algorithmic error: 0.117299681706532614954219913999~5/7~e-8
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffffff5ec8d8p-1 + (x*x) * (0x1.5555658ca4fddp-2 + (x*x) * (0x1.110cd080c6d3cp-3 + (x*x) * (0x1.baf33fbab1a42p-5 + (x*x) * (0x1.5bf38d5982274p-6 + (x*x) * (0x1.663acab9891a8p-7 + (x*x) * (-0x1.07c6f54037bacp-16 + (x*x) * 0x1.21cedad197d62p-8))))))) ;
}


fp32 ord_09_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.819363441951301926928375408315~2/9~e-10
  // Relative algorithmic error: 0.134589707374031599671124616782~5/7~e-9
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555554p-2f + (x*x) * (0x1.11118ep-3f + (x*x) * (0x1.b9fb2cp-5f + (x*x) * (0x1.685fbcp-6f + (x*x) * (0x1.0fdd96p-7f + (x*x) * (0x1.4b4c86p-8f + (x*x) * (-0x1.576362p-11f + (x*x) * 0x1.0e89fep-9f)))))))) ;
}

fp64 ord_09_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.8421735932929382064921760626~0/1~e-10
  // Relative algorithmic error: 0.84217421155513517045190944017~2/4~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.000000005c991p0 + (x*x) * (0x1.555553dbbf2fp-2 + (x*x) * (0x1.11118f1b79ef9p-3 + (x*x) * (0x1.b9fb71d6a75ccp-5 + (x*x) * (0x1.6859c521d429p-6 + (x*x) * (0x1.100ed2f82ef45p-7 + (x*x) * (0x1.4a80361a2a57p-8 + (x*x) * (-0x1.50c11a83217ddp-11 + (x*x) * 0x1.0dda18135b389p-9)))))))) ;
}


fp32 ord_10_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.104681346063435698612782833387~4/5~e-10
  // Relative algorithmic error: 0.7243375676599476707356770730~6/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.1110d6p-3f + (x*x) * (0x1.ba2af2p-5f + (x*x) * (0x1.654adp-6f + (x*x) * (0x1.2c738cp-7f + (x*x) * (0x1.5eaabp-9f + (x*x) * (0x1.9aca4cp-9f + (x*x) * (-0x1.38bcc2p-10f + (x*x) * 0x1.321a16p-10f))))))))) ;
}

fp64 ord_10_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.604653799390361776258418426359~3/9~e-11
  // Relative algorithmic error: 0.604653799390361776258418426359~3/9~e-11
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffffffff2b42p-1 + (x*x) * (0x1.55555576d3a94p-2 + (x*x) * (0x1.11110334ba7dp-3 + (x*x) * (0x1.ba200f1c67712p-5 + (x*x) * (0x1.65f3f4b9473e3p-6 + (x*x) * (0x1.269e9f80bcb7ap-7 + (x*x) * (0x1.9bbe0929ba7b5p-9 + (x*x) * (0x1.3cd7fec7e610bp-9 + (x*x) * (-0x1.37c7585076387p-11 + (x*x) * 0x1.f68a3dabcf227p-11))))))))) ;
}


fp32 ord_11_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.1010822577769973242404197751798~0/9~e-10
  // Relative algorithmic error: 0.637798516732222309711176183056~4/9~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.1110cep-3f + (x*x) * (0x1.ba2f54p-5f + (x*x) * (0x1.64d3ccp-6f + (x*x) * (0x1.33042cp-7f + (x*x) * (0x1.e66288p-10f + (x*x) * (0x1.51bbd4p-8f + (x*x) * (-0x1.0fa716p-8f + (x*x) * (0x1.ce779cp-9f + (x*x) * (-0x1.a1066cp-11f))))))))))) ;
}

fp64 ord_11_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.43412289345893738972371713680~0/2~e-12
  // Relative algorithmic error: 0.43412289345893738972371713680~0/2~e-12
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.00000000007a3p0 + (x*x) * (0x1.555555526c045p-2 + (x*x) * (0x1.11111287716ep-3 + (x*x) * (0x1.ba1b0fa4b74f9p-5 + (x*x) * (0x1.665dd38983802p-6 + (x*x) * (0x1.21976c72bd318p-7 + (x*x) * (0x1.e621f3717084ap-9 + (x*x) * (0x1.2543b3049a681p-10 + (x*x) * (0x1.3aa0e1e0cf784p-10 + (x*x) * (-0x1.b2a1d861d15dap-12 + (x*x) * 0x1.d3ef62d2c2459p-12)))))))))) ;
}


fp32 ord_12_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.718644496633142482592892330756~3/9~e-11
  // Relative algorithmic error: 0.52958069809420324680175742099~6/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.1110cp-3f + (x*x) * (0x1.ba38aap-5f + (x*x) * (0x1.639c32p-6f + (x*x) * (0x1.487946p-7f + (x*x) * (-0x1.9bd536p-10f + (x*x) * (0x1.0bdb84p-6f + (x*x) * (-0x1.be2074p-6f + (x*x) * (0x1.0c2394p-5f + (x*x) * (-0x1.6030b2p-6f + (x*x) * 0x1.9ca6fap-8f))))))))))) ;
}

fp64 ord_12_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.31167307122461997357094237263~6/7~e-13
  // Relative algorithmic error: 0.311972669919668987859040498733~5/8~e-13
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.ffffffffffee7p-1 + (x*x) * (0x1.555555559510fp-2 + (x*x) * (0x1.111110eae1c8fp-3 + (x*x) * (0x1.ba1bb3963492dp-5 + (x*x) * (0x1.664d225b806c1p-6 + (x*x) * (0x1.229510e93d21ep-7 + (x*x) * (0x1.d35f236ce8e37p-9 + (x*x) * (0x1.9747f32d2653fp-10 + (x*x) * (0x1.70a262d0fad0ap-12 + (x*x) * (0x1.4194dcda0266p-11 + (x*x) * (-0x1.0d8c839057e69p-12 + (x*x) * 0x1.b3b74310c755dp-13))))))))))) ;
}


fp32 ord_13_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.59752319858371294597110175601~4/6~e-11
  // Relative algorithmic error: 0.44256625167611427676815720~1/3~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.1110bp-3f + (x*x) * (0x1.ba4548p-5f + (x*x) * (0x1.61a4b6p-6f + (x*x) * (0x1.727d82p-7f + (x*x) * (-0x1.42cbecp-7f + (x*x) * (0x1.9e8c88p-5f + (x*x) * (-0x1.ec38fcp-4f + (x*x) * (0x1.94417cp-3f + (x*x) * (-0x1.a3d2ap-3f + (x*x) * (0x1.f81346p-4f + (x*x) * (-0x1.091b9cp-5f))))))))))))) ;
}

fp64 ord_13_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.223849049174449532542164064821~3/6~e-14
  // Relative algorithmic error: 0.223849049174449532542164064821~3/6~e-14
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.000000000000ap0 + (x*x) * (0x1.555555554ff9cp-2 + (x*x) * (0x1.11111114d8795p-3 + (x*x) * (0x1.ba1b9fa3d09dp-5 + (x*x) * (0x1.664f94e3f4956p-6 + (x*x) * (0x1.2267bd0d507e8p-7 + (x*x) * (0x1.d786f0e2a23acp-9 + (x*x) * (0x1.773228b5457c2p-10 + (x*x) * (0x1.5d83efd98575cp-11 + (x*x) * (0x1.462c885b30584p-14 + (x*x) * (0x1.4fb2b91d33344p-12 + (x*x) * (-0x1.3983d91c36a0ap-13 + (x*x) * 0x1.95b14082bc913p-14)))))))))))) ;
}


fp32 ord_14_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.47745395914014789252887143449~1/3~e-11
  // Relative algorithmic error: 0.38073185863378595435782907061~8/9~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.1110ap-3f + (x*x) * (0x1.ba546cp-5f + (x*x) * (0x1.5ecfb8p-6f + (x*x) * (0x1.bb778cp-7f + (x*x) * (-0x1.c08144p-6f + (x*x) * (0x1.1f7e82p-3f + (x*x) * (-0x1.b78aacp-2f + (x*x) * (0x1.d66b1cp-1f + (x*x) * (-0x1.54e2aap0f + (x*x) * (0x1.4020dp0f + (x*x) * (-0x1.5f46d8p-1f + (x*x) * 0x1.560ec4p-3f))))))))))))) ;
}

fp64 ord_14_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.162507835028722943665894825324~6/8~e-15
  // Relative algorithmic error: 0.16283684996361255086128097611~2/4~e-15
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffffffffffffp-1 + (x*x) * (0x1.5555555555bcbp-2 + (x*x) * (0x1.11111110b881dp-3 + (x*x) * (0x1.ba1ba1f4293c2p-5 + (x*x) * (0x1.664f3eb1e1049p-6 + (x*x) * (0x1.226f320a2015bp-7 + (x*x) * (0x1.d6b31b0cc5d1ep-9 + (x*x) * (0x1.7f10ce0ba28e9p-10 + (x*x) * (0x1.2a532aaeebc99p-11 + (x*x) * (0x1.35fd879cbab85p-12 + (x*x) * (-0x1.0767f16a7a44p-17 + (x*x) * (0x1.6234c023b4761p-13 + (x*x) * (-0x1.5ceef511196c3p-14 + (x*x) * 0x1.792783abb1357p-15))))))))))))) ;
}


fp32 ord_15_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.483617352833945781480610075757~1/5~e-11
  // Relative algorithmic error: 0.328877315211138896792589463~7/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.11108ep-3f + (x*x) * (0x1.ba682ap-5f + (x*x) * (0x1.5a81fap-6f + (x*x) * (0x1.1ed346p-6f + (x*x) * (-0x1.07e5c6p-4f + (x*x) * (0x1.7935dcp-2f + (x*x) * (-0x1.63aaaep0f + (x*x) * (0x1.ddb09ap1f + (x*x) * (-0x1.c427ap2f + (x*x) * (0x1.271f4p3f + (x*x) * (-0x1.f98bb4p2f + (x*x) * (0x1.ff61ep1f + (x*x) * (-0x1.cefc24p-1f))))))))))))))) ;
}

fp64 ord_15_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.119310678773853127755913509363~4/6~e-16
  // Relative algorithmic error: 0.125851687050712611197550434887~6/8~e-16
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.55555555554eep-2 + (x*x) * (0x1.11111111185b7p-3 + (x*x) * (0x1.ba1ba1b451c22p-5 + (x*x) * (0x1.664f49ac36a85p-6 + (x*x) * (0x1.226e120338655p-7 + (x*x) * (0x1.d6d93e09237ap-9 + (x*x) * (0x1.7d5af1531a3e5p-10 + (x*x) * (0x1.37fd9b472c5bp-11 + (x*x) * (0x1.d250fec1abd1p-13 + (x*x) * (0x1.1e6348b8db864p-13 + (x*x) * (-0x1.bb44c69423694p-16 + (x*x) * (0x1.7746f47c54adep-14 + (x*x) * (-0x1.788095b6bf35bp-15 + (x*x) * 0x1.5e089a20ad45cp-16)))))))))))))) ;
}


fp32 ord_16_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.316613012764906187789009711938~5/9~e-11
  // Relative algorithmic error: 0.28945124658588808978500388743~5/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.11107cp-3f + (x*x) * (0x1.ba7edap-5f + (x*x) * (0x1.54cc4ap-6f + (x*x) * (0x1.831b8ap-6f + (x*x) * (-0x1.0cc2d8p-3f + (x*x) * (0x1.b56928p-1f + (x*x) * (-0x1.ebc5eap1f + (x*x) * (0x1.90431cp3f + (x*x) * (-0x1.d7df9p4f + (x*x) * (0x1.8f172ap5f + (x*x) * (-0x1.d7f6aep5f + (x*x) * (0x1.726cd4p5f + (x*x) * (-0x1.5aa4dp4f + (x*x) * 0x1.24b018p2f))))))))))))))) ;
}

fp64 ord_16_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.85084073080043573739281975114~3/5~e-18
  // Relative algorithmic error: 0.9370094650626425223806607270~7/8~e-18
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.555555555555ep-2 + (x*x) * (0x1.1111111110606p-3 + (x*x) * (0x1.ba1ba1babaeaep-5 + (x*x) * (0x1.664f485e453afp-6 + (x*x) * (0x1.226e3a58401d2p-7 + (x*x) * (0x1.d6d2eefbebddcp-9 + (x*x) * (0x1.7db1209991f2fp-10 + (x*x) * (0x1.34c09e2794fdfp-11 + (x*x) * (0x1.feeba2048c057p-13 + (x*x) * (0x1.5fda7ade8ff81p-14 + (x*x) * (0x1.175f7ba816182p-14 + (x*x) * (-0x1.a0c409f1ac612p-16 + (x*x) * (0x1.9256dae2ab79ep-15 + (x*x) * (-0x1.9190f7f9edc19p-16 + (x*x) * 0x1.463cb4a0c722bp-17))))))))))))))) ;
}


fp32 ord_17_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.406488723640447439771855833349~0/4~e-11
  // Relative algorithmic error: 0.255750453071502463426434580722~2/5~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.111068p-3f + (x*x) * (0x1.ba9beep-5f + (x*x) * (0x1.4c5e5ep-6f + (x*x) * (0x1.16f87ap-5f + (x*x) * (-0x1.0d6c92p-2f + (x*x) * (0x1.f93e68p0f + (x*x) * (-0x1.4fe884p3f + (x*x) * (0x1.47848p5f + (x*x) * (-0x1.d76c72p6f + (x*x) * (0x1.f3de62p7f + (x*x) * (-0x1.8162a6p8f + (x*x) * (0x1.a40724p8f + (x*x) * (-0x1.3292acp8f + (x*x) * (0x1.0cd0ap7f + (x*x) * (-0x1.ac0ef8p4f))))))))))))))))) ;
}

fp64 ord_17_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.66072952245401865312134369892~5/7~e-19
  // Relative algorithmic error: 0.66072952245401865312134369892~5/7~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.11111111111b7p-3 + (x*x) * (0x1.ba1ba1ba0f823p-5 + (x*x) * (0x1.664f488629717p-6 + (x*x) * (0x1.226e34cfc9f3cp-7 + (x*x) * (0x1.d6d3eee73f1ffp-9 + (x*x) * (0x1.7da13af046912p-10 + (x*x) * (0x1.357476ae13c4cp-11 + (x*x) * (0x1.f36166cbbbc9ap-13 + (x*x) * (0x1.a550c0a3aaaap-14 + (x*x) * (0x1.f90e56b47f6d5p-16 + (x*x) * (0x1.1810497dcaccp-15 + (x*x) * (-0x1.2468c1ea17082p-16 + (x*x) * (0x1.a4d56b61df922p-16 + (x*x) * (-0x1.9c52ebe7aec3bp-17 + (x*x) * 0x1.2c6d0f5f23584p-18)))))))))))))))) ;
}


fp32 ord_18_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.303757311187415107556885714916~4/8~e-11
  // Relative algorithmic error: 0.228758798975167822713840641161~0/3~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.111054p-3f + (x*x) * (0x1.babc26p-5f + (x*x) * (0x1.41ed76p-6f + (x*x) * (0x1.8e1b34p-5f + (x*x) * (-0x1.e309f2p-2f + (x*x) * (0x1.ffb182p1f + (x*x) * (-0x1.8627d6p4f + (x*x) * (0x1.b8d4fp6f + (x*x) * (-0x1.74fb7ap8f + (x*x) * (0x1.da0ac2p9f + (x*x) * (-0x1.c2178p10f + (x*x) * (0x1.3a58fp11f + (x*x) * (-0x1.39632cp11f + (x*x) * (0x1.a5eefp10f + (x*x) * (-0x1.57a87ep9f + (x*x) * 0x1.ff78cp6f))))))))))))))))) ;
}

fp64 ord_18_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.90571852671574499930758930414~1/3~e-20
  // Relative algorithmic error: 0.455573330480906249105035647577~3/7~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.1111111111169p-3 + (x*x) * (0x1.ba1ba1ba175cep-5 + (x*x) * (0x1.664f48839e948p-6 + (x*x) * (0x1.226e3543a31e4p-7 + (x*x) * (0x1.d6d3d4fcce7b5p-9 + (x*x) * (0x1.7da330cf3f63bp-10 + (x*x) * (0x1.35599e010fcccp-11 + (x*x) * (0x1.f577dd394e252p-13 + (x*x) * (0x1.95f85a8a6240ap-14 + (x*x) * (0x1.50535730eac32p-15 + (x*x) * (0x1.ba6f959384cbep-17 + (x*x) * (0x1.a057a30ca652fp-17 + (x*x) * (-0x1.9f407d0b4be68p-18 + (x*x) * (0x1.46a42dfdbbab8p-17 + (x*x) * (-0x1.469b6894e4a5p-18 + (x*x) * 0x1.e45f3b4a8cac3p-20))))))))))))))))) ;
}


fp32 ord_19_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.307426164904036831124597914016~3/6~e-11
  // Relative algorithmic error: 0.205046657663354130601955434227~5/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.11103ep-3f + (x*x) * (0x1.bae3f6p-5f + (x*x) * (0x1.33709ap-6f + (x*x) * (0x1.2410eep-4f + (x*x) * (-0x1.ade4ap-1f + (x*x) * (0x1.019baep3f + (x*x) * (-0x1.c1533ap5f + (x*x) * (0x1.24f086p8f + (x*x) * (-0x1.215e8ap10f + (x*x) * (0x1.b3df4p11f + (x*x) * (-0x1.f45c3cp12f + (x*x) * (0x1.b24d36p13f + (x*x) * (-0x1.1817aap14f + (x*x) * (0x1.041068p14f + (x*x) * (-0x1.487cdp13f + (x*x) * (0x1.f92c1cp11f + (x*x) * (-0x1.64d922p9f))))))))))))))))))) ;
}

fp64 ord_19_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.30226954486499272696374437199~2/4~e-20
  // Relative algorithmic error: 0.376990102555101545493386664065~5/9~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.111111111117cp-3 + (x*x) * (0x1.ba1ba1ba15339p-5 + (x*x) * (0x1.664f48846912fp-6 + (x*x) * (0x1.226e351ace16ap-7 + (x*x) * (0x1.d6d3df5eb9e5ap-9 + (x*x) * (0x1.7da24b354d9dbp-10 + (x*x) * (0x1.3567bae8c2876p-11 + (x*x) * (0x1.f4325dfc987a1p-13 + (x*x) * (0x1.a0e9e5cd59317p-14 + (x*x) * (0x1.0958ef404f6dfp-15 + (x*x) * (0x1.1c6239b67878cp-15 + (x*x) * (-0x1.ae3dc88aa36fap-16 + (x*x) * (0x1.7cf498e2ae9c7p-15 + (x*x) * (-0x1.5292446849c2fp-15 + (x*x) * (0x1.d6beea807e0dep-16 + (x*x) * (-0x1.7bb614143cae3p-17 + (x*x) * 0x1.41348efeafe74p-19)))))))))))))))))) ;
}


fp32 ord_20_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.16079859324250329596443139556~5/7~e-11
  // Relative algorithmic error: 0.185931946278157671824467280088~0/3~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.111028p-3f + (x*x) * (0x1.bb10aep-5f + (x*x) * (0x1.212e2ep-6f + (x*x) * (0x1.a79d72p-4f + (x*x) * (-0x1.6ca98ap0f + (x*x) * (0x1.e9ffecp3f + (x*x) * (-0x1.e2a6a4p6f + (x*x) * (0x1.65c956p9f + (x*x) * (-0x1.9554c8p11f + (x*x) * (0x1.61fdb6p13f + (x*x) * (-0x1.de11d6p14f + (x*x) * (0x1.f1ba2cp15f + (x*x) * (-0x1.8b9164p16f + (x*x) * (0x1.d6f2fap16f + (x*x) * (-0x1.96638cp16f + (x*x) * (0x1.dfe0d8p15f + (x*x) * (-0x1.5abc58p14f + (x*x) * 0x1.ce6178p11f))))))))))))))))))) ;
}

fp64 ord_20_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.290049912184273854365762956010~2/6~e-20
  // Relative algorithmic error: 0.34200049279278678601466862639~6/8~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.1111111111187p-3 + (x*x) * (0x1.ba1ba1ba13cd5p-5 + (x*x) * (0x1.664f4884fbe45p-6 + (x*x) * (0x1.226e34f994b01p-7 + (x*x) * (0x1.d6d3e8e12c2fap-9 + (x*x) * (0x1.7da15d86a92dep-10 + (x*x) * (0x1.3578543a608f2p-11 + (x*x) * (0x1.f27c7a2a52918p-13 + (x*x) * (0x1.b1e5fd267bbb6p-14 + (x*x) * (0x1.11b035930cef6p-16 + (x*x) * (0x1.485e532641098p-14 + (x*x) * (-0x1.042113991ce45p-13 + (x*x) * (0x1.ba2ed74de72f1p-13 + (x*x) * (-0x1.039b25cf2bba3p-12 + (x*x) * (0x1.c38af3d93426bp-13 + (x*x) * (-0x1.0990060121942p-13 + (x*x) * (0x1.7f4d89eaf3f09p-15 + (x*x) * (-0x1.f5e453c2afeffp-18)))))))))))))))))))) ;
}


fp32 ord_21_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.59735662137261730356624526460~1/3~e-11
  // Relative algorithmic error: 0.16627008085495771781242317356~2/4~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.11100cp-3f + (x*x) * (0x1.bb505p-5f + (x*x) * (0x1.042ddap-6f + (x*x) * (0x1.48a534p-3f + (x*x) * (-0x1.4b8d76p1f + (x*x) * (0x1.fa07cap4f + (x*x) * (-0x1.1cc5fap8f + (x*x) * (0x1.e53bacp10f + (x*x) * (-0x1.3e2d9ep13f + (x*x) * (0x1.44936ep15f + (x*x) * (-0x1.02edcap17f + (x*x) * (0x1.432f4ap18f + (x*x) * (-0x1.3a019ap19f + (x*x) * (0x1.d59588p19f + (x*x) * (-0x1.08ce9cp20f + (x*x) * (0x1.b376b4p19f + (x*x) * (-0x1.ec6a12p18f + (x*x) * (0x1.562ce6p17f + (x*x) * (-0x1.b8762ap14f))))))))))))))))))))) ;
}

fp64 ord_21_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.243255153191032776562127381954~1/4~e-20
  // Relative algorithmic error: 0.31073451259954580746203906047~0/2~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.1111111111193p-3 + (x*x) * (0x1.ba1ba1ba121a8p-5 + (x*x) * (0x1.664f4885c235p-6 + (x*x) * (0x1.226e34c790b95p-7 + (x*x) * (0x1.d6d3f8df19a1dp-9 + (x*x) * (0x1.7d9f9d8e7482cp-10 + (x*x) * (0x1.359b8ad95b42bp-11 + (x*x) * (0x1.ee611e4a53d9cp-13 + (x*x) * (0x1.e05f89e0260d6p-14 + (x*x) * (-0x1.0b6c44f91aa3ep-15 + (x*x) * (0x1.f8b358efbb47p-13 + (x*x) * (-0x1.1fb1cdc4e14f8p-11 + (x*x) * (0x1.188472f2623e8p-10 + (x*x) * (-0x1.9dc4f100cf25fp-10 + (x*x) * (0x1.ce270bc102b1fp-10 + (x*x) * (-0x1.77dfdf166dd3cp-10 + (x*x) * (0x1.a4bebf7402d92p-11 + (x*x) * (-0x1.2168d0ddeea59p-12 + (x*x) * 0x1.7140f89371358p-15)))))))))))))))))))) ;
}


fp32 ord_22_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.47034725803708390387050592414~1/3~e-11
  // Relative algorithmic error: 0.14985744400210539570304598415~3/5~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.110ffp-3f + (x*x) * (0x1.bb93f8p-5f + (x*x) * (0x1.c5c074p-7f + (x*x) * (0x1.dac13cp-3f + (x*x) * (-0x1.0bf1dcp2f + (x*x) * (0x1.c1a36ap5f + (x*x) * (-0x1.170922p9f + (x*x) * (0x1.070be4p12f + (x*x) * (-0x1.7f7e46p14f + (x*x) * (0x1.b5949cp16f + (x*x) * (-0x1.89a16ap18f + (x*x) * (0x1.17f77p20f + (x*x) * (-0x1.3a67bcp21f + (x*x) * (0x1.14f74ap22f + (x*x) * (-0x1.7a012cp22f + (x*x) * (0x1.87498ap22f + (x*x) * (-0x1.28bedp22f + (x*x) * (0x1.36d8d6p21f + (x*x) * (-0x1.91c048p19f + (x*x) * 0x1.e29848p16f))))))))))))))))))))) ;
}

fp64 ord_22_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.21118615945566481348777741920~4/5~e-20
  // Relative algorithmic error: 0.282591061162463412753838316563~0/3~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.11111111111ap-3 + (x*x) * (0x1.ba1ba1ba10174p-5 + (x*x) * (0x1.664f4886c444dp-6 + (x*x) * (0x1.226e347fdae8dp-7 + (x*x) * (0x1.d6d4123841212p-9 + (x*x) * (0x1.7d9c89a6a7a86p-10 + (x*x) * (0x1.35e08f6f55cb8p-11 + (x*x) * (0x1.e55d2d67b9834p-13 + (x*x) * (0x1.29aab3651b466p-13 + (x*x) * (-0x1.5ea8ae1ea155ap-13 + (x*x) * (0x1.900d972db653dp-11 + (x*x) * (-0x1.177f22be952e4p-9 + (x*x) * (0x1.3d2cb9d9f31b6p-8 + (x*x) * (-0x1.19528b9e395b3p-7 + (x*x) * (0x1.83201f36b1fb1p-7 + (x*x) * (-0x1.942cd6b94493ep-7 + (x*x) * (0x1.35551cbc3aa14p-7 + (x*x) * (-0x1.472525b22e57ep-8 + (x*x) * (0x1.ab10a45dd9b7ep-10 + (x*x) * (-0x1.0328c6cf82dafp-12)))))))))))))))))))))) ;
}


fp32 ord_23_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.531424654130142295769390790749~3/8~e-11
  // Relative algorithmic error: 0.132820847068714369725388561020~4/6~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.110fccp-3f + (x*x) * (0x1.bbf362p-5f + (x*x) * (0x1.5e40e4p-7f + (x*x) * (0x1.6ac012p-2f + (x*x) * (-0x1.ce14f4p2f + (x*x) * (0x1.b04252p6f + (x*x) * (-0x1.2c230cp10f + (x*x) * (0x1.3dd9a8p13f + (x*x) * (-0x1.0596d6p16f + (x*x) * (0x1.530fb8p18f + (x*x) * (-0x1.5d1468p20f + (x*x) * (0x1.1ecec4p22f + (x*x) * (-0x1.787104p23f + (x*x) * (0x1.8971d6p24f + (x*x) * (-0x1.44f424p25f + (x*x) * (0x1.a27484p25f + (x*x) * (-0x1.9af4c8p25f + (x*x) * (0x1.291c82p25f + (x*x) * (-0x1.29f452p24f + (x*x) * (0x1.72091ep22f + (x*x) * (-0x1.ac882p19f))))))))))))))))))))))) ;
}

fp64 ord_23_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.18644809007623530743404028886~8/9~e-20
  // Relative algorithmic error: 0.257391807751415625622931548478~1/4~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.11111111111aep-3 + (x*x) * (0x1.ba1ba1ba0db85p-5 + (x*x) * (0x1.664f48881183dp-6 + (x*x) * (0x1.226e341a1c696p-7 + (x*x) * (0x1.d6d439d5471a9p-9 + (x*x) * (0x1.7d97397f1011fp-10 + (x*x) * (0x1.3664a00d8af81p-11 + (x*x) * (0x1.d229e06a8d9e2p-13 + (x*x) * (0x1.b2991da3a9577p-13 + (x*x) * (-0x1.15df231574a86p-11 + (x*x) * (0x1.341cef91081a8p-9 + (x*x) * (-0x1.f4ad12376b12bp-8 + (x*x) * (0x1.47eba864eeeadp-6 + (x*x) * (-0x1.55da58f0137e1p-5 + (x*x) * (0x1.19d3703efdfb5p-4 + (x*x) * (-0x1.6a6f568de726ep-4 + (x*x) * (0x1.63a8df3cb69a4p-4 + (x*x) * (-0x1.01107ac7b6a7p-4 + (x*x) * (0x1.01db6f23d5ab7p-5 + (x*x) * (-0x1.4079e93ca90dbp-7 + (x*x) * 0x1.739875512868fp-10)))))))))))))))))))))) ;
}


fp32 ord_24_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.4974930774080633509421554901~1/2~e-11
  // Relative algorithmic error: 0.125159514254682527437158381873~7/9~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.110fb8p-3f + (x*x) * (0x1.bc2fb8p-5f + (x*x) * (0x1.147674p-7f + (x*x) * (0x1.cfb61ep-2f + (x*x) * (-0x1.3f852ep3f + (x*x) * (0x1.435446p7f + (x*x) * (-0x1.e8b894p10f + (x*x) * (0x1.1b7c5cp14f + (x*x) * (-0x1.015b34p17f + (x*x) * (0x1.72c4eap19f + (x*x) * (-0x1.abe9cp21f + (x*x) * (0x1.8df686p23f + (x*x) * (-0x1.2afd9ep25f + (x*x) * (0x1.6aa2acp26f + (x*x) * (-0x1.616ed6p27f + (x*x) * (0x1.125e0cp28f + (x*x) * (-0x1.4e64ccp28f + (x*x) * (0x1.38b78ap28f + (x*x) * (-0x1.b0e70ep27f + (x*x) * (0x1.a19d8ap26f + (x*x) * (-0x1.f50808p24f + (x*x) * 0x1.1952c6p22f))))))))))))))))))))))) ;
}

fp64 ord_24_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.162569058310396985064843522656~5/7~e-20
  // Relative algorithmic error: 0.236437479001498054258726698826~4/7~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.11111111111bcp-3 + (x*x) * (0x1.ba1ba1ba0b1b2p-5 + (x*x) * (0x1.664f4889a5fc8p-6 + (x*x) * (0x1.226e3392323b4p-7 + (x*x) * (0x1.d6d4741e6f7d7p-9 + (x*x) * (0x1.7d8e99cd47325p-10 + (x*x) * (0x1.3751a01ba66fep-11 + (x*x) * (0x1.abf3f0fd4a147p-13 + (x*x) * (0x1.70f9acf85de6dp-12 + (x*x) * (-0x1.769750015398fp-10 + (x*x) * (0x1.bc22d5e5ea142p-8 + (x*x) * (-0x1.9a45ee8065fa4p-6 + (x*x) * (0x1.329bb6c0efacfp-4 + (x*x) * (-0x1.714e31eab4c9ep-3 + (x*x) * (0x1.650fd3ac98652p-2 + (x*x) * (-0x1.12b4979333776p-1 + (x*x) * (0x1.4b8b2b7124678p-1 + (x*x) * (-0x1.32d39a17b3d1cp-1 + (x*x) * (0x1.a41b870254444p-2 + (x*x) * (-0x1.90ae367ca2d8cp-3 + (x*x) * (0x1.db2031f6554e8p-5 + (x*x) * (-0x1.079fa06996997p-7)))))))))))))))))))))))) ;
}


fp32 ord_25_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.679443600956395320821802565650~0/6~e-11
  // Relative algorithmic error: 0.130813919697750846849607397837~5/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.110fc2p-3f + (x*x) * (0x1.bc2504p-5f + (x*x) * (0x1.0ff034p-7f + (x*x) * (0x1.e82dd4p-2f + (x*x) * (-0x1.61e308p3f + (x*x) * (0x1.7ac038p7f + (x*x) * (-0x1.30baccp11f + (x*x) * (0x1.7af608p14f + (x*x) * (-0x1.73835p17f + (x*x) * (0x1.233e2p20f + (x*x) * (-0x1.70cd94p22f + (x*x) * (0x1.7b9fe8p24f + (x*x) * (-0x1.3eb498p26f + (x*x) * (0x1.b4a4dp27f + (x*x) * (-0x1.e6e838p28f + (x*x) * (0x1.b75854p29f + (x*x) * (-0x1.3d9a6p30f + (x*x) * (0x1.6a3e2cp30f + (x*x) * (-0x1.3e587p30f + (x*x) * (0x1.9f9f8p29f + (x*x) * (-0x1.7b4f7p28f + (x*x) * (0x1.afaf7cp26f + (x*x) * (-0x1.ccf4bp23f))))))))))))))))))))))))) ;
}

fp64 ord_25_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.144011647810357221402740083330~5/8~e-20
  // Relative algorithmic error: 0.217402575572907225813400553171~1/4~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.11111111111cbp-3 + (x*x) * (0x1.ba1ba1ba08124p-5 + (x*x) * (0x1.664f488ba402dp-6 + (x*x) * (0x1.226e32d7a55ep-7 + (x*x) * (0x1.d6d4cb62ed4bap-9 + (x*x) * (0x1.7d807b982a678p-10 + (x*x) * (0x1.38fb000e1255fp-11 + (x*x) * (0x1.6087572092eebp-13 + (x*x) * (0x1.5db9a23115b1fp-11 + (x*x) * (-0x1.d7e7c3a42b573p-9 + (x*x) * (0x1.323d9b43c0537p-6 + (x*x) * (-0x1.3db65a5cd6213p-4 + (x*x) * (0x1.0c2f23de79036p-2 + (x*x) * (-0x1.705f72e64d52p-1 + (x*x) * (0x1.9af43f335c4f8p0 + (x*x) * (-0x1.725ef3c2e71fbp1 + (x*x) * (0x1.0b1d2e78243d5p2 + (x*x) * (-0x1.2fb4ee34bacf6p2 + (x*x) * (0x1.09f1f2013a449p2 + (x*x) * (-0x1.59e332969213ap1 + (x*x) * (0x1.3a748e23908f3p0 + (x*x) * (-0x1.648b1bd6b6508p-2 + (x*x) * 0x1.7b63a9d23f8d1p-5)))))))))))))))))))))))) ;
}


fp32 ord_26_tan_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.98981592597721630486037291020~0/2~e-11
  // Relative algorithmic error: 0.180165298035093096365698995158~5/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (0x1.555556p-2f + (x*x) * (0x1.110fcp-3f + (x*x) * (0x1.bc2dbcp-5f + (x*x) * (0x1.09a234p-7f + (x*x) * (0x1.e782ap-2f + (x*x) * (-0x1.57dc8cp3f + (x*x) * (0x1.62261p7f + (x*x) * (-0x1.0f50fp11f + (x*x) * (0x1.3e246p14f + (x*x) * (-0x1.23888p17f + (x*x) * (0x1.a83bdp19f + (x*x) * (-0x1.f0246p21f + (x*x) * (0x1.d6aap23f + (x*x) * (-0x1.6cbe2p25f + (x*x) * (0x1.d04cep26f + (x*x) * (-0x1.e764cp27f + (x*x) * (0x1.a71ccp28f + (x*x) * (-0x1.301b4p29f + (x*x) * (0x1.6939cp29f + (x*x) * (-0x1.5fc6p29f + (x*x) * (0x1.13b98p29f + (x*x) * (-0x1.4faep28f + (x*x) * (0x1.29934p27f + (x*x) * (-0x1.5440cp25f + (x*x) * 0x1.7664cp22f))))))))))))))))))))))))) ;
}

fp64 ord_26_tan_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.12926803147431144947499014322~0/2~e-20
  // Relative algorithmic error: 0.20015824032087782140790188628~2/4~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (0x1.5555555555555p-2 + (x*x) * (0x1.11111111111dbp-3 + (x*x) * (0x1.ba1ba1ba04917p-5 + (x*x) * (0x1.664f488e22358p-6 + (x*x) * (0x1.226e31da38cb6p-7 + (x*x) * (0x1.d6d54c4ecee39p-9 + (x*x) * (0x1.7d69c2067b533p-10 + (x*x) * (0x1.3be6b498e7016p-11 + (x*x) * (0x1.9ebd3dd388465p-14 + (x*x) * (0x1.5d7febe9a0da7p-10 + (x*x) * (-0x1.1bc55a109f357p-7 + (x*x) * (0x1.94ed1b890def6p-5 + (x*x) * (-0x1.d3bc6777dedcbp-3 + (x*x) * (0x1.ba1238e8d3aaap-1 + (x*x) * (-0x1.5692b49fc798ep1 + (x*x) * (0x1.b34ac671d16f4p2 + (x*x) * (-0x1.c425ccc69e74p3 + (x*x) * (0x1.7d94a77f042b7p4 + (x*x) * (-0x1.02fcb6be8ca77p5 + (x*x) * (0x1.165910eb9e397p5 + (x*x) * (-0x1.ce9c55b23c7d5p4 + (x*x) * (0x1.1e7ea2b62e04fp4 + (x*x) * (-0x1.f1a8984a1dbc3p2 + (x*x) * (0x1.0e4e2f47e0fa1p1 + (x*x) * (-0x1.1447af0f4a7c6p-2)))))))))))))))))))))))))) ;
}


