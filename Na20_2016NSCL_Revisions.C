{
  using namespace RNROOT;
  RNROOT::Initialize();
  RNROOT::gReactionInfo.SetReaction("19Ne","2H","n","20Na","1H","19Ne");
  RNROOT::gReactionInfo.SetBeamEnergy(86.0);
  //RNROOT::gReactionInfo.SetBeamELoss(3.761);// 90 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.790);// 89 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.818);// 88 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.847);// 87 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.854);// 86.75 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.861);// 86.5 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.868);// 86.25 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.875);// 86 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.882);// 85.75 MeV Beam
  RNROOT::gReactionInfo.SetBeamELoss(3.889);// 85.5 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.904);// 85 MeV Beam
  //RNROOT::gReactionInfo.SetBeamELoss(3.932);// 84 MeV Beam 
  //RNROOT::gReactionInfo.SetBeamELoss(3.761);// Test 
  //RNROOT::gReactionInfo.SetBeamEnergy(87);
  RNROOT::gReactionInfo.SetHiEx(2.65);
  //RNROOT::gReactionInfo.SetEFragmentEst(83.6); // 89 MeV Beam
  //RNROOT::gReactionInfo.SetEFragmentEst(82.6); // 88 MeV Beam
  //RNROOT::gReactionInfo.SetEFragmentEst(82.2); // 87.5 MeV Beam
  //RNROOT::gReactionInfo.SetEFragmentEst(80.6); // 86 MeV Beam
  //RNROOT::gReactionInfo.SetEFragmentEst(80.2); // 85.5 MeV Beam
  //RNROOT::gReactionInfo.SetEFragmentEst(79.6); // 85 MeV Beam
  //RNROOT::gReactionInfo.SetEFragmentEst(79.2); // 84.5 MeV Beam
  RNROOT::gReactionInfo.SetEFragmentEst(78.6); // 84 MeV Beam
  //RNROOT::gReactionInfo.SetEFragmentEst(78.2); // 83.5 MeV Beam 
  //RNROOT::gReactionInfo.SetEFragmentEst(77.6); // 83.0 MeV Beam 
  //RNROOT::gReactionInfo.SetEFragmentEst(77.2); // 82.5 MeV Beam 
  //RNROOT::gReactionInfo.SetEFragmentEst(75.6); // 81.0 MeV Beam 
  //RNROOT::gReactionInfo.SetEFragmentEst(75.2); // 80.5 MeV Beam 
  //RNROOT::gReactionInfo.SetEFragmentEst(74.6); // 80.0 MeV Beam 
  //RNROOT::gReactionInfo.SetEFragmentEst(74.2); // 79.5 MeV Beam 
  //RNROOT::gReactionInfo.SetEFragmentEst(72.6); // 78.0 MeV Beam  
  //RNROOT::gReactionInfo.SetEFragmentEst(72.2); // 77.5 MeV Beam  
  //RNROOT::gReactionInfo.SetEFragmentEst(70.6); // 76.0 MeV Beam 
  //RNROOT::gReactionInfo.SetEFragmentEst(70.2); // 75.5 MeV Beam  
  
  //RNROOT::gReactionInfo.SetEFragmentEst(60.0);
  TGraph state1 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,2.4,0);
  TGraph state2 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,2.65,0);
  TGraph state3 = RNROOT::gReactionInfo.GetSecondaryDecayCurve(45,2.85,0);
 
  RNROOT::rftime.LoadTable("config/RFTimeShift_102314.rfin");


  
  //std::cout << " Before LoadTable" << std::endl;
  /*
  RNROOT::si_[0].front.LoadTable("config/RunConfigFile_111714.in");
  RNROOT::si_[1].front.LoadTable("config/RunConfigFile_111714.in");
  RNROOT::si_[0].back.LoadTable("config/RunConfigFile_111714.in");
  RNROOT::si_[1].back.LoadTable("config/RunConfigFile_111714.in");
  */
  
  RNROOT::si_[0].front.LoadTable("config/RunConfigFile_292015.in");
  RNROOT::si_[1].front.LoadTable("config/RunConfigFile_292015.in");
  RNROOT::si_[0].back.LoadTable("config/RunConfigFile_292015.in");
  RNROOT::si_[1].back.LoadTable("config/RunConfigFile_292015.in");
  
  //std::cout << " After LoadTable" << std::endl;
 
  // Used to look at beam stuff:
  //gMainAnalyzer.SetRootOutputFile("JUNK_BeamEnergyStuff_86.root");
  gMainAnalyzer.SetRootOutputFile("0216-816-818_AllGates_BeamEn86p0_RandOn_ICEnPlus1p0_SiX-1p5_SiY1_ICX2_ICY0_3.root");

  //gMainAnalyzer.SetRootOutputFile("0116-DataAll_AllBeamEn85_IterQVal_EverythingTight_A_SiX-1_SiY-0p5.root"); 
  //gMainAnalyzer.SetRootOutputFile("1204-DataAll_AllBeamEn87_InvMass_ICPosTest_X320_Y360_GARBAGE.root"); 
 

  eventinfo::EventAnalyzer eventinfo;
  psd::NeutPSDAnalyzer PSDAn;
  silicon::Si_Analyzer SiAn;
  ionchamber::IC_Analyzer ICAn;
  neut_tof::Neut_TOF_Analyzer TOFAn;
  Module_Analyzer ModAn;
  physical::Q_ValueAnalyzer QValAn;
  _F17::F17dn_Analyzer f17analyzer;
  RF_analyzer::RF_Analyzer rf1; 
  NamedTree_Analyzer NamedTree1;
  beamspotA::ReconstructBeamSpotA bsA;
  RNfilters::RFTimeFilter RFtime;
  RNfilters::ICTimeFilter ICtime;
  RNfilters::NaITimeFilter NaItime;
  RNfilters::SiAngleFilter SiAng;
  RNfilters::SiHitFilter SiHit;
  RNfilters::ICRawEDEFilter ICdEE;
  RNfilters::ICCalEDEFilter ICdEECal;
  RNfilters::NaIEnFilter NaIen1;
  RNfilters::SiChanFilter SiChanFilt;

  QValAn.SetQValIterations(5);
  //QValAn.SetInvMass(2.195);
  bsA.SetDispersionScaleFactor(0.2);
  bsA.SetInvMass(2.195);
  NamedTree1.SetDispersionScaleFactor(0.3);
  QValAn.SetSiliconAngle(0);
  //ICAn.TwoHitReconOn();
  //NamedTree1.TwoHitReconOn();
  //g.UseTwoWirePosForRecon();
  
  NamedTree1.SetICOffset(1.0);

  //=====================
  // RFTime Filter Stuff:
  RFtime.SetUseSiSubtract();
  RFtime.SetWindow(-60,-48,22,33); //Large Peak in RF-Si for 19Ne gate
  //RFtime.SetWindow(-60,-48,22,33,-150,-100,-48,-10); // Large and coin peaks for RF-Si for 19NeGate
  //RFtime.SetWindow(-86,-74,-4,8); //Small Peak in RF-Si for 19Ne gate
  //RFtime.SetWindow(-150,-110,-45,-27);//small Peak in RF-Si for no heavy gate
  //RFtime.SetWindow(-86,-72,-8,8); //Mid Peak in RF-Si for no heavy gate
  //RFtime.SetWindow(-64,-47,16,34); //Big End Peak in RF-Si for no heavy gate 

  //================
  // NaI Time Stuff:
  NaItime.YesNaITimeOn(); // Turn this on if you want NaI.t>0

  //==================
  // NaI Energy Stuff:
  NaIen1.SetWindow(0,250);
  //NaIen1.YesNaIEnOn(); 
  
  //=====================
  // ICTime Filter Stuff:
  ICtime.SetWindow(270,340);
  
  //=======================
  // ICRawEDE Filter Stuff:
  //ICdEE.SetWindow(1400,4096);
  //ICdEECal.SetWindow(70,100);
  
  //======================
  // SiAngle Filter Stuff:
  SiAng.SetWindow(8,26);

  //====================
  // SiHit Filter Stuff:
  //SiHit.SetDoubleHit();
  SiHit.SetSingleHit();

  //=================
  // Si Chan Filter :
  SiChanFilt.SetKillBackEquFront();
  SiChanFilt.SetKillBackEquFrontPlusOne();
  
  gAnalyzer_stack.Add(&RFtime);// USE
  //gAnalyzer_stack.Add(&NaItime);
  //gAnalyzer_stack.Add(&NaIen1);
  gAnalyzer_stack.Add(&ICtime);  // USE
  gAnalyzer_stack.Add(&SiAng);
  gAnalyzer_stack.Add(&SiHit);// USE
  gAnalyzer_stack.Add(&SiChanFilt);// USE
  gAnalyzer_stack.Add(&ICdEE);// USE
  gAnalyzer_stack.Add(&ICdEECal);// USE
  RNROOT::gAnalyzer_stack.Add(&SiAn);// USE
  gAnalyzer_stack.Add(&eventinfo);// USE
  gAnalyzer_stack.Add(&ModAn);// USE
  gAnalyzer_stack.Add(&PSDAn);// USE
  gAnalyzer_stack.Add(&TOFAn);// USE
  gAnalyzer_stack.Add(&ICAn);// USE
  gAnalyzer_stack.Add(&QValAn);// USE
  gAnalyzer_stack.Add(&rf1);// USE
  RNROOT::gAnalyzer_stack.Add(&bsA);// USE
  RNROOT::gAnalyzer_stack.Add(&NamedTree1);// USE
  
  //================================
  // Turn on various graphical cuts:
  //silicon::RequireAlpha();
  ionchamber::RequireHI1();
  silicon::RequireProton();
  //ionchamber::RequireNe19(1);
  //ionchamber::RequireF19_HE_CS(1);
  //ionchamber::RequireF19_LE_CS(1);
  //silicon::RequirePThetaCut();
  //ionchamber::RequireHI1();
  // //ionchamber::RequireHI2();
  //ionchamber::RequireHI3();
  //psd::Require_RawNeut_ORCheck();
  
  gMainAnalyzer.InitRootFile("Stage1Files/Data816-818_Stage1.root");
  //gMainAnalyzer.InitRootFile("Stage1Files/NoTarget_run3545.root");
  //gMainAnalyzer.InitRootFile("Stage1Files/Data820-821_run3643_Stage1_102414.root");
  //gMainAnalyzer.AddTree("Stage1Files/Data820-821_run3643_Stage1_102414.root");
  //gMainAnalyzer.AddTree("Stage1Files/Data821-824_run3644+_Stage1.root");

  // Random Below, USE ABOVE (For Now)

  //gMainAnalyzer.AddTree("Stage1Files/Data820-821_run3643_Stage1_102414.root");
  
  //gMainAnalyzer.InitRootFile("Stage1Files/Data821-824_run3644+_Stage1.root");

  //gMainAnalyzer.InitRootFile("Stage1Files/Data820-821_run3643_Stage1_102414.root");
  //gMainAnalyzer.InitRootFile("Stage1Files/Data820-end_runs3644-3668_Stage1_012915.root");
  //gMainAnalyzer.AddTree("Stage1Files/Data820-end_runs3644-3668_Stage1_012915.root");
  //gMainAnalyzer.AddTree("Stage1Files/Data820-end_runs3669-3673_Stage1_012915.root");
  //gMainAnalyzer.AddTree("Stage1Files/Data820-end_runs3674-end_Stage1_012915.root");
  //gMainAnalyzer.InitRootFile("Stage1Files/Data820-end_runs3669-3673_Stage1_012915.root");
  //gMainAnalyzer.InitRootFile("Stage1Files/Data820-end_runs3674-end_Stage1_012915.root");

  //========================
  // Different calibrations.
  //LoadVariableFile("config/DetConfig_852014.in");
  //LoadVariableFile("config/DetConfig_9242014.in");
  //LoadVariableFile("config/DetConfig_9242014-After.in");
  //LoadVariableFile("config/DetConfig_9252014.in");
  //  LoadVariableFile("config/DetConfig_10162014.in");
  //LoadVariableFile("config/DetConfig_10302014.in");
  //LoadVariableFile("config/DetConfig_11172014.in");
  LoadVariableFile("config/DetConfig_292015.in");
  //LoadVariableFile("config/DetConfig_292015-after.in");
  //LoadVariableFile("config/DetConfig_10302014-after.in");
  
  SetCalibrations();
  
  //=================
  // Different gates:
  //silicon::LoadGates("cuts/Prot1_9-25-14.root");
  //silicon::LoadGates("cuts/ProtCut1_9-29_runs816-818.root");
  //silicon::LoadGates("cuts/ProtCut_820-821_930.root");
  //silicon::LoadGates("cuts/ProtCut_820-824_930_WithTail.root");
  //silicon::LoadGates("cuts/PC_820-24_NoTail.root");
  // silicon::LoadGates("cuts/ProtCuts_WithAndWithoutTail_9-30-14.root");
  //silicon::LoadGates("cuts/ProtCuts_TailAndProtSeparate_101.root");
  //silicon::LoadGates("cuts/GenerousProtonCut_10-2-14.root"); // This one
  //silicon::LoadGates("cuts/TightProtonCut_10-2-14.root");
  //silicon::LoadGates("cuts/ProtCut_102714.root"); // This one
  silicon::LoadGates("cuts/ProtCut_NewProtCal_2915.root"); // THIS ONE
  //silicon::LoadGates("cuts/ProtCuts_Tighter_102714.root");
  

  //ionchamber::LoadGates("cuts/IC_9-24-14.root");
  //ionchamber::LoadGates("cuts/ICGate_9-26-14.root");
  //ionchamber::LoadGates("cuts/ProtCut1_9-29_runs816-818.root");
  //ionchamber::LoadGates("cuts/IC_CutsForIC_AndProt_DEE_9-29.root");
  //ionchamber::LoadGates("cuts/ICCut_820-821_930.root");
  //ionchamber::LoadGates("cuts/ICCut_820-824_930.root");
  //ionchamber::LoadGates("cuts/ICCuts_WithBeamCuts_101.root");
  ionchamber::LoadGates("cuts/HI_edeGate_21015.root");
  //ionchamber::LoadGates("cuts/EventsWith19FHECS_IC.root");
  //ionchamber::LoadGates("cuts/TighterIC_19NeEventsCut_11314.root");
  //ionchamber::LoadGates("cuts/IC_dEECut_110414.root");

  //psd::LoadPSDGates("cuts/neuts_raw_329.root");
  psd::LoadPSDGates("cuts/RawNeutCuts_1020.root");

  //RF_analyzer::LoadGates("cuts/RFCuts_929.root");
  RF_analyzer::LoadGates("cuts/RF_CleanUpHopefully_101.root");
  //RF_analyzer::LoadGates("cuts/RF_NotCleanUpHopefully_101.root");

  gMainAnalyzer.Loop();
  
  gMainAnalyzer.WriteOut();
}
