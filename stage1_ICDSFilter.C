{
  using namespace RNROOT;
  RNROOT::Initialize();
  RNROOT::gReactionInfo.SetReaction("19Ne","2H","n","20Na","1H","19Ne");
  //RNROOT::gReactionInfo.SetReaction("17F","d","n","18Ne","4He","14O");
  RNROOT::gReactionInfo.SetBeamEnergy(86);
  RNROOT::gReactionInfo.SetHiEx(2.65);
  RNROOT::gReactionInfo.SetEFragmentEst(82);
  TGraph state1 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,2.65,0);
  TGraph state2 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,2.85,0);
  TGraph state3 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,3,0);
  TGraph state4 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,3.5,0);

  gMainAnalyzer.SetRootOutputFile("AllData_ICDSTriggerRequired_NoOtherGates.root");  
  //gMainAnalyzer.SetRootOutputFile("Trash.root");
  // This analzyer/filter requires at least mult 1 in both Si dets, and an ICTime>0
  RNfilters::Stage1SiliconFilterD sifilter;

  // This analyzer creates the folder "EventInfo" in the root file.
  // It fills this folder with 6 histograms.  See "EventAnalyzer.c/hpp for more.
  eventinfo::EventAnalyzer eventinfo;

  // This analyzer creates all sorts of neutron detector related histograms.
  psd::NeutPSDAnalyzer b;

  RNfilters::Stage1ICDSFilter ICDS;
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
  //gAnalyzer_stack.Add(&d);
  //gAnalyzer_stack.Add(&f);
  gAnalyzer_stack.Add(&g);
  //gAnalyzer_stack.Add(&sifilter);
  gAnalyzer_stack.Add(&ICDS);
  gAnalyzer_stack.Add(&treeanalyzer);

  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3545.root");

  /*816*/
  RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3552.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3553.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3554.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3555.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3556.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3557.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3558.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3559.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3560.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3561.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3562.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3563.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3564.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3565.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3566.root");
  //Total HRS This Day: 14 hrs 4 mins
  /**/
  /*817*/
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3567.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3567.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3568.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3569.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3570.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3571.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3572.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3573.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3574.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3575.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3576.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3577.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3578.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3579.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3580.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3581.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3582.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3583.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3584.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3585.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3586.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3587.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3588.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3589.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3590.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3591.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3592.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3593.root");
  /*Total HRS This Day: 21 hrs 31 mins
  */
  /*818*/
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3594.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3594.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3595.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3596.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3597.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3598.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3599.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3600.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3601.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3602.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3603.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3604.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3605.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3606.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3607.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3608.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3609.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3610.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3611.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3612.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3613.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3614.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3615.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3616.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3617.root");
  //Total HRS This Day: 21 hrs 5 mins
  /**/
  /*819 + MISC*/
  RNRoot::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3618.root");
  //RNRoot::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3618.root");
  RNRoot::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3619.root");
  //RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3631.root"); // Scalers crashed, need to make sure this is all good
  //    -- No More Data - ShutDown for He Production --
  /**/
  /*820  Total HRS This Day: 18 hrs 19 mins 
   */
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3620.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3620.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3621.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3622.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3623.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3624.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3625.root");  
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3626.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3627.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3628.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3629.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3630.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3632.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3633.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3634.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3635.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3636.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3637.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3638.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3639.root");
  /**/
  /*821
    Total HRS This Day: 18 hrs 16 mins*/    
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3640.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3640.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3641.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3642.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3643.root");
  /* */
  // -- Below here beam is RE-OPTIMIZED.
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3644.root");
  /*  RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3644.root");*/
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3645.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3646.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3647.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3648.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3649.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3650.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3651.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3652.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3653.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3654.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3655.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3656.root");
  // -- Below here the numbering might not agree with log book.
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3657.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3658.root");
  // -- Below here the scalers were not recorded.
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3659.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3660.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3661.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3662.root");
  /* */
  /* 822
    Total HRS This Day: 20 hrs 11 mins.
  */
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3663.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3663.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3664.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3665.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3666.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3667.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3668.root");
  RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3669.root");
  //RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3669.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3670.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3671.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3672.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3673.root");
  RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3674.root");
  //RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3674.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3675.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3676.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3677.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3678.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3679.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3680.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3681.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3682.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3683.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3684.root");
  /**/ 
  /* 823
     Total HRS This Day:  23 hrs 6 mins. */
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3685.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3685.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3686.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3687.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3688.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3689.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3690.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3691.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3692.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3693.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3694.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3695.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3696.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3697.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3698.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3699.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3700.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3701.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3702.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3703.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3704.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3705.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3706.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3707.root");
  /*  */
  /* 824
     Total HRS This Day:  4 hrs 17mins. */
  
  //RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3708.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3708.root"); 
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3709.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3710.root");
  //RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3711.root"); // High noise
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3712.root");
  RNROOT::gMainAnalyzer.AddTree("/data1/res048/ROOT/run3713.root");
  /**/

  LoadVariableFile("config/DetConfig_852014.in");
  
  SetCalibrations();
  

  //silicon::LoadGates("cuts/prots1_852014.root");
  //psd::LoadPSDGates("cuts/neuts_raw_329.root");

  gMainAnalyzer.Loop();
  
  gMainAnalyzer.WriteOut();
}
