#include "sin.h"


// Generated for input range: [0;0.78539816339744830961566084581987572104929234984379140812357603907383566711463950912153004138036333120250903700923769259014707577737368637826875783503055572509765625]









fp32 ord_01_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.37092238535482937060505668863~3/4~e-1
  // Relative algorithmic error: error
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * 0x1.e5247p-1f ;
}








fp64 ord_01_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.370922504951743086386616831847~2/6~e-1
  // Relative algorithmic error: error
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * 0x1.e5247082cdbdbp-1 ;
}


fp32 ord_02_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.288803400157736608325434687901~3/6~e-3
  // Relative algorithmic error: 0.4084314986522100972093548046~0/2~e-3
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.ffca78p-1f + (x*x) * (-0x1.4ad2eep-3f)) ;
}

fp64 ord_02_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.28880043127071690612936333081~6/8~e-3
  // Relative algorithmic error: 0.408426083892075242311477129862~2/7~e-3
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.ffca7783c889ap-1 + (x*x) * (-0x1.4ad2ea07f3804p-3)) ;
}


fp32 ord_03_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.10683031313738548666611330286~0/1~e-5
  // Relative algorithmic error: 0.151096843518339506614114904247~4/6~e-5
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.ffffcep-1f + (x*x) * (-0x1.553eeep-3f + (x*x) * 0x1.0b10dap-7f)) ;
}

fp64 ord_03_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.10656896195663149486831826774~6/8~e-5
  // Relative algorithmic error: 0.150711271329484475245408248156~3/5~e-5
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.ffffcd6e00184p-1 + (x*x) * (-0x1.553edef7432e8p-3 + (x*x) * 0x1.0b0fa12fa0a53p-7)) ;
}


fp32 ord_04_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.24882594998651037479554107083~0/1~e-8
  // Relative algorithmic error: 0.422654063794137391366539900035~3/7~e-8
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555544p-3f + (x*x) * (0x1.1106e6p-7f + (x*x) * (-0x1.992cf8p-13f)))) ;
}

fp64 ord_04_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.228975443491601239484012923548~3/6~e-8
  // Relative algorithmic error: 0.32382023328192210423479594646~6/7~e-8
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.ffffffe42f1e7p-1 + (x*x) * (-0x1.55553f43c2231p-3 + (x*x) * (0x1.1106051679bcap-7 + (x*x) * (-0x1.98fb9c14dc121p-13)))) ;
}


fp32 ord_05_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.62248569426219244919148163628~2/4~e-10
  // Relative algorithmic error: 0.197072387489163104165873376511~3/5~e-9
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.111164p-7f + (x*x) * (-0x1.a04866p-13f + (x*x) * 0x1.77e21p-19f)))) ;
}

fp64 ord_05_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.321708353922134173940522253511~3/7~e-11
  // Relative algorithmic error: 0.45496939549138915026560425758~3/4~e-11
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffffffff5fecp-1 + (x*x) * (-0x1.55555548e3564p-3 + (x*x) * (0x1.111107187297ep-7 + (x*x) * (-0x1.a00ec71bab5e6p-13 + (x*x) * 0x1.6cb0a8ccc2f9cp-19)))) ;
}


fp32 ord_06_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.31425542176248927739384759217~3/4~e-10
  // Relative algorithmic error: 0.122895043654797239428554145412~2/4~e-9
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.11119ap-7f + (x*x) * (-0x1.a0acdcp-13f + (x*x) * (0x1.b2660ep-19f + (x*x) * (-0x1.5b129p-22f)))))) ;
}

fp64 ord_06_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.31823334402993010123624642332~8/9~e-14
  // Relative algorithmic error: 0.455191440096314181573688983917~2/6~e-14
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1.fffffffffffd7p-1 + (x*x) * (-0x1.5555555550c42p-3 + (x*x) * (0x1.1111110bbbf03p-7 + (x*x) * (-0x1.a019f87b803e2p-13 + (x*x) * (0x1.71d71fc979703p-19 + (x*x) * (-0x1.a94acae83b894p-26)))))) ;
}


fp32 ord_07_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.190181779714250049603248401944~2/4~e-10
  // Relative algorithmic error: 0.87274550116276233233231409691~5/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.1111d4p-7f + (x*x) * (-0x1.a152d8p-13f + (x*x) * (0x1.2b4c8cp-18f + (x*x) * (-0x1.3b2a2ep-19f + (x*x) * 0x1.41e4f8p-20f)))))) ;
}

fp64 ord_07_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.252490201284449535676748633593~1/4~e-17
  // Relative algorithmic error: 0.377915421823937117530195897~0/1~e-17
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555548p-3 + (x*x) * (0x1.111111110f75ep-7 + (x*x) * (-0x1.a01a019bf2621p-13 + (x*x) * (0x1.71de355f53fb8p-19 + (x*x) * (-0x1.ae5e54bfd5bd7p-26 + (x*x) * 0x1.5d8e4fd05fdbdp-33)))))) ;
}


fp32 ord_08_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.121776691944524249641465694071~0/2~e-10
  // Relative algorithmic error: 0.64564959804437359475349828743~4/6~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.11121ap-7f + (x*x) * (-0x1.a26afep-13f + (x*x) * (0x1.f7c36ep-18f + (x*x) * (-0x1.6523f2p-17f + (x*x) * (0x1.8f0268p-17f + (x*x) * (-0x1.61fec4p-18f)))))))) ;
}

fp64 ord_08_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.221157884915308605688375693638~1/4~e-19
  // Relative algorithmic error: 0.118159134993604215282107213904~2/3~e-18
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.111111111108ap-7 + (x*x) * (-0x1.a01a01a0069e2p-13 + (x*x) * (0x1.71de3a3fc9b4p-19 + (x*x) * (-0x1.ae643cdcf8645p-26 + (x*x) * (0x1.6114666ed60c3p-33 + (x*x) * (-0x1.a53e75d09b059p-41)))))))) ;
}


fp32 ord_09_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.836190411506695702935541715562~1/9~e-11
  // Relative algorithmic error: 0.50097349125704066318483343684~6/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.111268p-7f + (x*x) * (-0x1.a40e36p-13f + (x*x) * (0x1.cf42b2p-17f + (x*x) * (-0x1.2b4dp-15f + (x*x) * (0x1.0e6478p-14f + (x*x) * (-0x1.00ea28p-14f + (x*x) * 0x1.8f90c6p-16f)))))))) ;
}

fp64 ord_09_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.15640546471112731334857092074~1/3~e-19
  // Relative algorithmic error: 0.93561846628731475183216204436~3/5~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111111066p-7 + (x*x) * (-0x1.a01a019ffa7edp-13 + (x*x) * (0x1.71de3a274c32fp-19 + (x*x) * (-0x1.ae640c2399215p-26 + (x*x) * (0x1.60e13135f68b6p-33 + (x*x) * (-0x1.6eae78d1c6bc1p-41 + (x*x) * (-0x1.73a31e95dda1ap-45))))))))) ;
}


fp32 ord_10_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.59815571329587146628901632848~4/5~e-11
  // Relative algorithmic error: 0.399846229940253389219673143110~3/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.1112cp-7f + (x*x) * (-0x1.a66c64p-13f + (x*x) * (0x1.af7fb2p-16f + (x*x) * (-0x1.a25b16p-14f + (x*x) * (0x1.0e086cp-12f + (x*x) * (-0x1.9a7162p-12f + (x*x) * (0x1.530f0ep-12f + (x*x) * (-0x1.d5bd9ep-14f)))))))))) ;
}

fp64 ord_10_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.110860839982044409156678184629~1/3~e-19
  // Relative algorithmic error: 0.74241897666950946464141946639~3/4~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111111039p-7 + (x*x) * (-0x1.a01a019fe7339p-13 + (x*x) * (0x1.71de39f48cea6p-19 + (x*x) * (-0x1.ae6383f9a3417p-26 + (x*x) * (0x1.60145ba198262p-33 + (x*x) * (-0x1.0ceda3d6ae678p-45 + (x*x) * (-0x1.544e8d1cc6956p-41 + (x*x) * 0x1.d9d0af441edd5p-43))))))))) ;
}


fp32 ord_11_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.442248457361083486163517846528~2/7~e-11
  // Relative algorithmic error: 0.326435973390863001051529000531~5/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.111322p-7f + (x*x) * (-0x1.a9b586p-13f + (x*x) * (0x1.86ee6ep-15f + (x*x) * (-0x1.00b64cp-12f + (x*x) * (0x1.b9e552p-11f + (x*x) * (-0x1.dbb974p-10f + (x*x) * (0x1.380bf8p-9f + (x*x) * (-0x1.c849a4p-10f + (x*x) * 0x1.1d16c4p-11f)))))))))) ;
}

fp64 ord_11_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.82042223455379990407626053932~3/5~e-20
  // Relative algorithmic error: 0.60647378600192935434841388750~5/7~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111111008p-7 + (x*x) * (-0x1.a01a019fccdbfp-13 + (x*x) * (0x1.71de399ca355ep-19 + (x*x) * (-0x1.ae62524661297p-26 + (x*x) * (0x1.5dab24d43788dp-33 + (x*x) * (0x1.73437e04fc3bfp-39 + (x*x) * (-0x1.3a0cc4f35d4bap-38 + (x*x) * (0x1.cba8cb08fa7c3p-39 + (x*x) * (-0x1.1f4745bea33bfp-40))))))))))) ;
}


fp32 ord_12_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.3360173473337647795603260151~6/8~e-11
  // Relative algorithmic error: 0.271498164615937058819900464178~4/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.11138ep-7f + (x*x) * (-0x1.ae1f6p-13f + (x*x) * (0x1.5447f6p-14f + (x*x) * (-0x1.1d8c96p-11f + (x*x) * (0x1.396abp-9f + (x*x) * (-0x1.be9ee8p-8f + (x*x) * (0x1.9c578ap-7f + (x*x) * (-0x1.dc08cap-7f + (x*x) * (0x1.384f1cp-7f + (x*x) * (-0x1.638d8ep-9f)))))))))))) ;
}

fp64 ord_12_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.62375443065161897061102750194~3/5~e-20
  // Relative algorithmic error: 0.504617965395689353527677495797~1/6~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111110fd2p-7 + (x*x) * (-0x1.a01a019fa97ecp-13 + (x*x) * (0x1.71de390b6e447p-19 + (x*x) * (-0x1.ae5fdb473b0eap-26 + (x*x) * (0x1.574cce89ff65ap-33 + (x*x) * (0x1.a60c4d4a76d73p-37 + (x*x) * (-0x1.9e8fa2a3af0a1p-36 + (x*x) * (0x1.dec3333483b86p-36 + (x*x) * (-0x1.3a28e1e0626acp-36 + (x*x) * 0x1.65b83307ef057p-38))))))))))) ;
}


fp32 ord_13_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.261178110490104438717485010860~5/8~e-11
  // Relative algorithmic error: 0.229320985682575373144235870224~4/7~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.111404p-7f + (x*x) * (-0x1.b3e4b2p-13f + (x*x) * (0x1.1c468ap-13f + (x*x) * (-0x1.25d366p-10f + (x*x) * (0x1.8e7a98p-8f + (x*x) * (-0x1.67b2b4p-6f + (x*x) * (0x1.b50a1p-5f + (x*x) * (-0x1.613df2p-4f + (x*x) * (0x1.6c3c76p-4f + (x*x) * (-0x1.b1960ep-5f + (x*x) * 0x1.c5729ep-7f)))))))))))) ;
}

fp64 ord_13_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.485078569478717986041383696573~3/7~e-20
  // Relative algorithmic error: 0.426365725189668189854248051923~4/8~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111110f97p-7 + (x*x) * (-0x1.a01a019f7b444p-13 + (x*x) * (0x1.71de3826a7047p-19 + (x*x) * (-0x1.ae5b1f73b1be7p-26 + (x*x) * (0x1.4823e6be5b11fp-33 + (x*x) * (0x1.626fe8e6fdcc8p-35 + (x*x) * (-0x1.b6db44e670fe8p-34 + (x*x) * (0x1.62bdeaae86fa7p-33 + (x*x) * (-0x1.6dca589377c92p-33 + (x*x) * (0x1.b36ecae559ab9p-34 + (x*x) * (-0x1.c75d871f53ac9p-36))))))))))))) ;
}


fp32 ord_14_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.206901887394385288189327145695~6/9~e-11
  // Relative algorithmic error: 0.196216874363349674967603262418~5/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.111484p-7f + (x*x) * (-0x1.bb4344p-13f + (x*x) * (0x1.c8dee4p-13f + (x*x) * (-0x1.1b55bep-9f + (x*x) * (0x1.cf518p-7f + (x*x) * (-0x1.00ab8cp-4f + (x*x) * (0x1.88bb34p-3f + (x*x) * (-0x1.9f772p-2f + (x*x) * (0x1.2a6ed8p-1f + (x*x) * (-0x1.15e666p-1f + (x*x) * (0x1.2e9e02p-2f + (x*x) * (-0x1.248e98p-4f)))))))))))))) ;
}

fp64 ord_14_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.38455125869171098573556200082~3/5~e-20
  // Relative algorithmic error: 0.3649639717492232325725711403~3/4~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111110f57p-7 + (x*x) * (-0x1.a01a019f40295p-13 + (x*x) * (0x1.71de36cbf6396p-19 + (x*x) * (-0x1.ae528c4c4478dp-26 + (x*x) * (0x1.26e8d0e996279p-33 + (x*x) * (0x1.0099923a474f1p-33 + (x*x) * (-0x1.8b7821447d4e1p-32 + (x*x) * (0x1.a29eeb2039ee6p-31 + (x*x) * (-0x1.2cdbba837bd41p-30 + (x*x) * (0x1.1848b1e59b35bp-30 + (x*x) * (-0x1.3153ab0e5b2ddp-31 + (x*x) * 0x1.2743f53e333c6p-33))))))))))))) ;
}


fp32 ord_15_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.166167867482916649280859507377~3/5~e-11
  // Relative algorithmic error: 0.169454839712856296825080418348~0/3~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.11151p-7f + (x*x) * (-0x1.c4a6dap-13f + (x*x) * (0x1.65044ep-12f + (x*x) * (-0x1.0546dp-8f + (x*x) * (0x1.faa4e4p-6f + (x*x) * (-0x1.5136dep-3f + (x*x) * (0x1.3ba7e6p-1f + (x*x) * (-0x1.a353e2p0f + (x*x) * (0x1.893576p1f + (x*x) * (-0x1.fcebcep1f + (x*x) * (0x1.b089eap1f + (x*x) * (-0x1.b27a3p0f + (x*x) * 0x1.86dea2p-2f)))))))))))))) ;
}

fp64 ord_15_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.309933929249701995035420932407~5/8~e-20
  // Relative algorithmic error: 0.315908767857466502836412015868~4/7~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111110f12p-7 + (x*x) * (-0x1.a01a019ef5ff2p-13 + (x*x) * (0x1.71de34cf7390fp-19 + (x*x) * (-0x1.ae43bff17447fp-26 + (x*x) * (0x1.c59abca141854p-34 + (x*x) * (0x1.4f68907eaee5ep-32 + (x*x) * (-0x1.3aa7b9e0e857bp-30 + (x*x) * (0x1.a1e0da57d19d1p-29 + (x*x) * (-0x1.87be08a91fcb5p-28 + (x*x) * (0x1.fae42ab8188e5p-28 + (x*x) * (-0x1.aeb5207cf4ebp-28 + (x*x) * (0x1.b08988280529cp-29 + (x*x) * (-0x1.8509f52f9224ep-31))))))))))))))) ;
}


fp32 ord_16_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.136255007074191734084233398236~2/4~e-11
  // Relative algorithmic error: 0.148384614915207848609977063366~6/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.1115a2p-7f + (x*x) * (-0x1.cff3acp-13f + (x*x) * (0x1.0c0cecp-11f + (x*x) * (-0x1.c6f8dcp-8f + (x*x) * (0x1.010266p-4f + (x*x) * (-0x1.92b9a6p-2f + (x*x) * (0x1.c1dda4p0f + (x*x) * (-0x1.6b5296p2f + (x*x) * (0x1.a9591ep3f + (x*x) * (-0x1.65681cp4f + (x*x) * (0x1.a41954p4f + (x*x) * (-0x1.47d3ap4f + (x*x) * (0x1.311c1p3f + (x*x) * (-0x1.0047cep1f)))))))))))))))) ;
}

fp64 ord_16_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.253403550423103914861248573698~0/2~e-20
  // Relative algorithmic error: 0.276103637946161820950432737533~0/3~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111110ec8p-7 + (x*x) * (-0x1.a01a019e9a6b8p-13 + (x*x) * (0x1.71de31fa0a1e6p-19 + (x*x) * (-0x1.ae2b3c12eb905p-26 + (x*x) * (0x1.7b4ce4e46c0eap-35 + (x*x) * (0x1.94c2a5dca477bp-31 + (x*x) * (-0x1.c50fd58d15238p-29 + (x*x) * (0x1.6e44e2768ae8fp-27 + (x*x) * (-0x1.ad38db10c4699p-26 + (x*x) * (0x1.6903d6fc51586p-25 + (x*x) * (-0x1.a8bfe7a11022ep-25 + (x*x) * (0x1.4bc513cc701f2p-25 + (x*x) * (-0x1.3510cf85b6ab8p-26 + (x*x) * 0x1.03d6816e8ed9ap-28))))))))))))))) ;
}


fp32 ord_17_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.120360421118800420565491969867~7/9~e-11
  // Relative algorithmic error: 0.130991288727688338097010730284~6/8~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.11163ep-7f + (x*x) * (-0x1.ddb78p-13f + (x*x) * (0x1.88c40ap-11f + (x*x) * (-0x1.7e626cp-7f + (x*x) * (0x1.f1d3d6p-4f + (x*x) * (-0x1.c526acp-1f + (x*x) * (0x1.29385ap2f + (x*x) * (-0x1.1debap4f + (x*x) * (0x1.966fcp5f + (x*x) * (-0x1.a9f69ap6f + (x*x) * (0x1.44dbbep7f + (x*x) * (-0x1.5e7fd6p7f + (x*x) * (0x1.fadd4cp6f + (x*x) * (-0x1.b89354p5f + (x*x) * 0x1.5bf408p3f)))))))))))))))) ;
}

fp64 ord_17_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.210375628940488102243156770529~3/6~e-20
  // Relative algorithmic error: 0.243782442005799680902134558595~4/7~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111110e7ap-7 + (x*x) * (-0x1.a01a019e2c20bp-13 + (x*x) * (0x1.71de2e118df2ep-19 + (x*x) * (-0x1.ae045e0f4dfcap-26 + (x*x) * (-0x1.2616c615e87bp-34 + (x*x) * (0x1.c7643aae9bb54p-30 + (x*x) * (-0x1.2afa1d4f2f1ep-27 + (x*x) * (0x1.1fb47fa278509p-25 + (x*x) * (-0x1.99096d6a0aa19p-24 + (x*x) * (0x1.acae8c749cb32p-23 + (x*x) * (-0x1.46df6d7e28f0cp-22 + (x*x) * (0x1.608de4019965ep-22 + (x*x) * (-0x1.fd9736a61b349p-23 + (x*x) * (0x1.baac3f21dac2ep-24 + (x*x) * (-0x1.5d5a36de39f76p-26))))))))))))))))) ;
}


fp32 ord_18_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.128748708173497234120848132179~5/7~e-11
  // Relative algorithmic error: 0.11581423843606238109462873081~1/3~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.1116ecp-7f + (x*x) * (-0x1.ef0f92p-13f + (x*x) * (0x1.1d604ap-10f + (x*x) * (-0x1.3cd20ep-6f + (x*x) * (0x1.d7f20ep-3f + (x*x) * (-0x1.ee852cp0f + (x*x) * (0x1.785d58p3f + (x*x) * (-0x1.a88af6p5f + (x*x) * (0x1.66cad2p7f + (x*x) * (-0x1.c7abfep8f + (x*x) * (0x1.b0786ep9f + (x*x) * (-0x1.2dfd6ap10f + (x*x) * (0x1.2d1278p10f + (x*x) * (-0x1.956902p9f + (x*x) * (0x1.4a461p8f + (x*x) * (-0x1.ebae34p5f)))))))))))))))))) ;
}

fp64 ord_18_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.176070850892649823817607310652~5/8~e-20
  // Relative algorithmic error: 0.216443692719343275387455645428~0/3~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111110e26p-7 + (x*x) * (-0x1.a01a019da624fp-13 + (x*x) * (0x1.71de28b2376a3p-19 + (x*x) * (-0x1.adc7ab5e04d92p-26 + (x*x) * (-0x1.2126b801a1471p-32 + (x*x) * (0x1.e6e3fd865a123p-29 + (x*x) * (-0x1.71edd9c8e3dcfp-26 + (x*x) * (0x1.a08a7b33392c8p-24 + (x*x) * (-0x1.5f72785c6d451p-22 + (x*x) * (0x1.bda8811fe484cp-21 + (x*x) * (-0x1.a65dcdce128bcp-20 + (x*x) * (0x1.268c9bb0f65a7p-19 + (x*x) * (-0x1.254da2933afedp-19 + (x*x) * (0x1.8a851e491bf75p-20 + (x*x) * (-0x1.4116378e6b0dcp-21 + (x*x) * 0x1.dd95a47a70825p-24))))))))))))))))) ;
}


fp32 ord_19_sin_fp32(fp32 x)
{
  // Absolute algorithmic error: 0.80084418539949899458747996127~4/6~e-12
  // Relative algorithmic error: 0.104032316570258965742585591061~3/5~e-10
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0f + (x*x) * (-0x1.555556p-3f + (x*x) * (0x1.111796p-7f + (x*x) * (-0x1.0109bep-12f + (x*x) * (0x1.8b30a4p-10f + (x*x) * (-0x1.ebda98p-6f + (x*x) * (0x1.9c19acp-2f + (x*x) * (-0x1.e857d4p1f + (x*x) * (0x1.a73012p4f + (x*x) * (-0x1.122372p7f + (x*x) * (0x1.0d1718p9f + (x*x) * (-0x1.92c4eap10f + (x*x) * (0x1.cb6b84p11f + (x*x) * (-0x1.8c32d8p12f + (x*x) * (0x1.fbb254p12f + (x*x) * (-0x1.d442dep12f + (x*x) * (0x1.25bc16p12f + (x*x) * (-0x1.c0a1ecp10f + (x*x) * 0x1.3ab5bap8f)))))))))))))))))) ;
}

fp64 ord_19_sin_fp64(fp64 x)
{
  // Absolute algorithmic error: 0.14882995105728367017258410263~4/6~e-20
  // Relative algorithmic error: 0.193455780814454994258020872219~3/6~e-19
  // Absolute rounding error: error
  // Relative rounding error: error
  // Total absolute error: error
  // Total relative error: error
  return  x * (0x1p0 + (x*x) * (-0x1.5555555555555p-3 + (x*x) * (0x1.1111111110dcdp-7 + (x*x) * (-0x1.a01a019d06adcp-13 + (x*x) * (0x1.71de21801084dp-19 + (x*x) * (-0x1.ad6bec2e10a5bp-26 + (x*x) * (-0x1.492ecca76c188p-31 + (x*x) * (0x1.f016db4fbf7d3p-28 + (x*x) * (-0x1.af3340759282p-25 + (x*x) * (0x1.18248b3a25058p-22 + (x*x) * (-0x1.13c7d44a97be3p-20 + (x*x) * (0x1.9df7a4b1e728ap-19 + (x*x) * (-0x1.d9877ff2ae9bep-18 + (x*x) * (0x1.99807cf19249ap-17 + (x*x) * (-0x1.07161eff07a29p-16 + (x*x) * (0x1.e697af0d59485p-17 + (x*x) * (-0x1.320601dd16d1bp-17 + (x*x) * (0x1.d493397d2e2c8p-19 + (x*x) * (-0x1.497f7baebf175p-21))))))))))))))))))) ;
}


