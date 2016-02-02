{
  using namespace RNROOT;
  RNROOT::Initialize();
  RNROOT::gReactionInfo.SetReaction("19Ne","2H","n","20Na","1H","19Ne");
  RNROOT::gReactionInfo.SetBeamEnergy(86.1);
  RNROOT::gReactionInfo.SetHiEx(2.65);
  RNROOT::gReactionInfo.SetEFragmentEst(83);
  TGraph state1 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,2.4,0);
  TGraph state2 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,2.65,0);
  TGraph state3 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,2.85,0);
  
  RNROOT::si_[0].front.LoadTable("config/RunConfigFile_4272015.in");
  RNROOT::si_[1].front.LoadTable("config/RunConfigFile_4272015.in");
  RNROOT::si_[0].back.LoadTable("config/RunConfigFile_4272015.in");
  RNROOT::si_[1].back.LoadTable("config/RunConfigFile_4272015.in");

  gMainAnalyzer.SetRootOutputFile("0623-NaINeut_TEST1.root"); 


  eventinfo::EventAnalyzer eventinfo;
  psd::NeutPSDAnalyzer b;
  //silicon::Si_Analyzer c;
  ionchamber::IC_Analyzer g;
  neut_tof::Neut_TOF_Analyzer d;
  Module_Analyzer e;
  physical::Q_ValueAnalyzer f;
  RNfilters::ICTimeFilter time;
  //_F17::F17dn_Analyzer f17analyzer;
  //RF_analyzer::RF_Analyzer rf1; 
  //NamedTree_Analyzer NamedTree1;
  //beamspotA::ReconstructBeamSpotA bsA;
  NamedTree_Analyzer NamedTree1;

  //bsA.SetDispersionScaleFactor(0.4);
  //NamedTree1.SetDispersionScaleFactor(0.3);
  f.SetSiliconAngle(0);
  d.SetNeutronTimeGate(0,500);
  d.RequireNeutTimeGate();
  
  //RNROOT::gAnalyzer_stack.Add(&c);
  //gAnalyzer_stack.Add(&time);
  gAnalyzer_stack.Add(&eventinfo);
  gAnalyzer_stack.Add(&e);
  gAnalyzer_stack.Add(&b);
  //gAnalyzer_stack.Add(&d); // REPEATED BELOW
  gAnalyzer_stack.Add(&f);
  gAnalyzer_stack.Add(&g);
  gAnalyzer_stack.Add(&d); // REPEATED HERE
  //gAnalyzer_stack.Add(&rf1);
  //RNROOT::gAnalyzer_stack.Add(&bsA);
  RNROOT::gAnalyzer_stack.Add(&NamedTree1);
  
  //================================
  // Turn on various graphical cuts:
  //  ionchamber::RequireHI1();
  //ionchamber::RequireHI2();
  //ionchamber::RequireHI3();
  //psd::Require_RawNeut_ORCheck();
  
  gMainAnalyzer.InitRootFile("Stage1Files/Data816-818_Stage1_NaINeut.root");
  gMainAnalyzer.AddTree("Stage1Files/Data820-821_run3643_Stage1_NaINeut.root");
  gMainAnalyzer.AddTree("Stage1Files/Data821-824_run3644+_Stage1_NaINeut.root");

  //========================
  // Different calibrations.
  //LoadVariableFile("config/DetConfig_852014.in");
  //LoadVariableFile("config/DetConfig_9242014.in");
  //LoadVariableFile("config/DetConfig_9242014-After.in");
  //LoadVariableFile("config/DetConfig_9252014.in");
  LoadVariableFile("config/DetConfig_4272015.in");


  SetCalibrations();
  
  //=================
  // Different gates:
  //ionchamber::LoadGates("cuts/IC_9-24-14.root");
  //ionchamber::LoadGates("cuts/ICGate_9-26-14.root");
  //ionchamber::LoadGates("cuts/ProtCut1_9-29_runs816-818.root");
  //ionchamber::LoadGates("cuts/IC_CutsForIC_AndProt_DEE_9-29.root");
  //ionchamber::LoadGates("cuts/ICCut_820-821_930.root");
  //ionchamber::LoadGates("cuts/ICCut_820-824_930.root");
  //ionchamber::LoadGates("cuts/ICCuts_WithBeamCuts_101.root");
  //ionchamber::LoadGates("cuts/ICCuts_NeutGamma1_1029.root");
  ionchamber::LoadGates("cuts/ICCuts_NeutGam2_1029.root");

  psd::LoadPSDGates("cuts/neuts_raw_329.root");

  //RF_analyzer::LoadGates("cuts/RFCuts_929.root");
  //RF_analyzer::LoadGates("cuts/RF_CleanUpHopefully_101.root");
  //RF_analyzer::LoadGates("cuts/RF_NotCleanUpHopefully_101.root");

  gMainAnalyzer.Loop();
  
  gMainAnalyzer.WriteOut();
}
