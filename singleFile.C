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
  TGraph state4 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,3,0);

  gMainAnalyzer.SetRootOutputFile("_run3700.root");  

  RNfilters::Stage1SiliconFilterD sifilter;
  eventinfo::EventAnalyzer eventinfo;
  psd::NeutPSDAnalyzer b;
  silicon::Si_Analyzer c;
  ionchamber::IC_Analyzer g;
  neut_tof::Neut_TOF_Analyzer d;
  Module_Analyzer e;
  physical::Q_ValueAnalyzer f;
  _F17::F17dn_Analyzer f17analyzer;
  f.SetSiliconAngle(0);

  gAnalyzer_stack.Add(&sifilter);
  gAnalyzer_stack.Add(&eventinfo);
  gAnalyzer_stack.Add(&e);
  gAnalyzer_stack.Add(&b);
  gAnalyzer_stack.Add(&c);
  gAnalyzer_stack.Add(&d);
  gAnalyzer_stack.Add(&f);
  gAnalyzer_stack.Add(&g);
  gAnalyzer_stack.Add(&f17analyzer);
  
  //silicon::RequireAlpha();
  // silicon::RequireProton();
  //silicon::RequirePThetaCut();
  // ionchamber::RequireHI1();
  //  ionchamber::RequireHI2();
  //ionchamber::RequireHI3();
  //psd::Require_RawNeut_ORCheck();
  
  RNROOT::gMainAnalyzer.InitRootFile("../ROOT/run3700.root"); 
  //RNROOT::gMainAnalyzer.InitRootFile("filterfiles/filterD_runs316_19_31.root"); 
  /*  RNROOT::gMainAnalyzer.InitRootFile("filterfiles/filterD_823.root"); 
  RNROOT::gMainAnalyzer.AddTree("filterfiles/filterD_822.root"); 
  RNROOT::gMainAnalyzer.AddTree("filterfiles/filterD_821.root"); 
  RNROOT::gMainAnalyzer.AddTree("filterfiles/filterD_820.root"); 
  RNROOT::gMainAnalyzer.AddTree("filterfiles/filterD_818.root");  
  RNROOT::gMainAnalyzer.AddTree("filterfiles/filterD_817.root"); 
  RNROOT::gMainAnalyzer.AddTree("filterfiles/filterD_816.root"); 
  RNROOT::gMainAnalyzer.AddTree("filterfiles/filterD_runs316_19_31.root"); 
  */
  LoadVariableFile("config/DetConfig_852014.in");
  
  SetCalibrations();
  
  silicon::LoadGates("cuts/alphas_817.root");
  silicon::LoadGates("cuts/prots1_852014.root");
  // ionchamber::LoadGates("cuts/F19recoils.root");
  ionchamber::LoadGates("cuts/Ne19recoils.root");
  //ionchamber::LoadGates("cuts/ne19b.root");
  // ionchamber::LoadGates("cuts/ne19a.root");
  //ionchamber::LoadGates("cuts/f19peak.root");
  //ionchamber::LoadGates("cuts/FbandB.root");
  // ionchamber::LoadGates("cuts/FBandC.root");
  //ionchamber::LoadGates("cuts/Oband.root");
  psd::LoadPSDGates("cuts/neuts_raw_329.root");
  silicon::LoadGates("cuts/pthetacutA.root");
  gMainAnalyzer.Loop();
  
  gMainAnalyzer.WriteOut();
}
