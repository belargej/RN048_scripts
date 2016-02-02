{
  using namespace RNROOT;
  RNROOT::Initialize();
  RNROOT::gReactionInfo.SetReaction("17F","2H","n","18Ne","1H","17F");
  //RNROOT::gReactionInfo.SetReaction("17F","d","n","18Ne","4He","14O");
  RNROOT::gReactionInfo.SetBeamEnergy(93);
  RNROOT::gReactionInfo.SetHiEx(4.59);
  RNROOT::gReactionInfo.SetEFragmentEst(90);
  TGraph state1 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,4.590,0);
  TGraph state2 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,5.14,0);
  TGraph state3 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,5.45,0);
  TGraph state4 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,5.09,0);

  gMainAnalyzer.SetRootOutputFile("C12Test_SecondHalf.root");  
  
  
  //RNfilters::Stage1SiliconFilterA sifilter;
  RNfilters::Stage1SiliconFilterD sifilter;
  // RNfilters::Stage1SiliconFilterB sifilter;
  //  RNfilters::Stage1SiliconFilterC sifilter;
  eventinfo::EventAnalyzer eventinfo;
  psd::NeutPSDAnalyzer b;
  silicon::Si_Analyzer c;
  ionchamber::IC_Analyzer g;
  neut_tof::Neut_TOF_Analyzer d;
  Module_Analyzer e;
  physical::Q_ValueAnalyzer f;
  NewTree_Analyzer treeanalyzer;

  gAnalyzer_stack.Add(&eventinfo);
  gAnalyzer_stack.Add(&e);
  gAnalyzer_stack.Add(&b);
  gAnalyzer_stack.Add(&c);
  gAnalyzer_stack.Add(&d);
  gAnalyzer_stack.Add(&f);
  gAnalyzer_stack.Add(&g);
  gAnalyzer_stack.Add(&sifilter);
  gAnalyzer_stack.Add(&treeanalyzer);
  //  silicon::RequireProton();

  /*  
  RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3025.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3026.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3027.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3028.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3029.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3030.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3031.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3032.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3033.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3034.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3035.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3036.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3037.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3038.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3039.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3040.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3041.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3042.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3043.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3044.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3045.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3046.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3047.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3048.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3049.root");
  */

  //RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/sibT_ICT_noICDS/filter_528.root"); 
  /*
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3050.root"); 
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3050.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3051.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3052.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3053.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3054.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3055.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3056.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3057.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3058.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3059.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3060.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3061.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3062.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3063.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3064.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3065.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3066.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3067.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3068.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3069.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3070.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3071.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3072.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3073.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3074.root");
  


  
  //  RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/sibT_ICT_noICDS/filter_529.root"); 
  //RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_528.root"); 


  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3078.root");    
  //  RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3078.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3079.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3080.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3081.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3082.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3083.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3084.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3085.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3086.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3087.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3088.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3089.root");
  
 
 // RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/sibT_ICT_noICDS/filter_530.root"); 
 // RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_529.root"); 
 // RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_528.root"); 
  
  
  
  
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3100.root");
  //  RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3100.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3101.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3102.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3103.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3104.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3105.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3106.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3107.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3108.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3109.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3110.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3111.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3112.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3113.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3114.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3115.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3116.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3117.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3118.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3119.root");
  
  //  RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/sibT_ICT_noICDS/filter_531.root"); 
  //  RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_530.root"); 
  //  RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_529.root"); 
 //  RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_528.root"); 
  
  
  
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3120.root");
//  RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3120.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3121.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3122.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3123.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3124.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3125.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3126.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3127.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3128.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3129.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3130.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3131.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3132.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3133.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3134.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3135.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3136.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3137.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3138.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3139.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3140.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3141.root");
  
  //RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/noSIB_NAINEUTcoinc/filter_601_noSIB.root"); 


// RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/sibT_ICT_noICDS/filter_601.root"); 
//  RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_531.root"); 

//  RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_529.root"); 
//  RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_528.root"); 


  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3142.root");
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3142.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3143.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3144.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3145.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3146.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3147.root");
  
  

  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3150.root");  
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3150.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3151.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3152.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3153.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3154.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3155.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3156.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3157.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3158.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3159.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3160.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3161.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3162.root");



//RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/sibT_ICT_noICDS/filter_602_a.root"); 
//RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/sibT_ICT_noICDS/filter_602_b.root"); 



RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3163.root");
//RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3163.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3164.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3165.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3166.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3167.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3168.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3169.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3170.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3171.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3172.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3173.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3174.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3175.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3176.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3177.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3178.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3179.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3180.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3181.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3182.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3183.root");


//RNROOT::gMainAnalyzer.InitRootFile("../../ROOT/sibT_ICT_noICDS/filter_603.root"); 
//RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_602_a.root"); 
//RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_602_b.root"); 
//RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_601.root"); 
//RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_531.root"); 
//RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_530.root"); 
//RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_529.root"); 
//RNROOT::gMainAnalyzer.AddTree("../../ROOT/sibT_ICT_noICDS/filter_528.root"); 


RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3184.root"); 
//RNROOT::gMainAnalyzer.InitRootFile("/data1/res046/ROOT/run3184.root"); 
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3185.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3186.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3187.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3188.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3189.root");
//RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3190.root");//missing?
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3203.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3204.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3205.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3206.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3207.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3208.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3209.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3210.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3211.root");
RNROOT::gMainAnalyzer.AddTree("/data1/res046/ROOT/run3212.root");

  */
  /* First Half of 12C run from 8/25-8/26
  RNROOT::gMainAnalyzer.InitRootFile("/data/res046/ROOT/run3714.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3715.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3716.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3717.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3718.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3719.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3720.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3721.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3722.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3723.root");
  RNROOT::gMainAnalyzer.AddTree("/data/res046/ROOT/run3724.root");
  */
  /* Second half of 12C run from 8/25-8/26
   */
  RNROOT::gMainAnalyzer.InitRootFile("/data1/SeanRes047/ROOT/run3725.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/SeanRes047/ROOT/run3726.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/SeanRes047/ROOT/run3727.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/SeanRes047/ROOT/run3728.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/SeanRes047/ROOT/run3729.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/SeanRes047/ROOT/run3730.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/SeanRes047/ROOT/run3731.root");
  
  
  //LoadVariableFile("config/DetConfig_6_7_a.in");
  LoadVariableFile("config/DetConfig_6_7_c.in");
  
  SetCalibrations();
  
  
  //ionchamber::LoadGates("cuts/F17_tighter.root");
  //ionchamber::LoadGates("cuts/Ne18_hi2.root");
  //silicon::LoadGates("cuts/prots1_619.root");
  //psd::LoadPSDGates("cuts/neuts_raw_329.root");

  gMainAnalyzer.Loop();
  
  gMainAnalyzer.WriteOut();
}
