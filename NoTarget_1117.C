{
  using namespace RNROOT;
  RNROOT::Initialize();
  RNROOT::gReactionInfo.SetReaction("19Ne","2H","n","20Na","1H","19Ne");
  RNROOT::gReactionInfo.SetBeamEnergy(86.1);
  RNROOT::gReactionInfo.SetHiEx(2.65);
  RNROOT::gReactionInfo.SetEFragmentEst(83);
  gMainAnalyzer.SetRootOutputFile("Run3734_NoTarget_ICX2p2_ICY3p8.root");
  
  eventinfo::EventAnalyzer eventinfo;
  ionchamber::IC_Analyzer ICAn;
  Module_Analyzer ModAn;
  

  gAnalyzer_stack.Add(&eventinfo);
  gAnalyzer_stack.Add(&ModAn);
  gAnalyzer_stack.Add(&ICAn);


  RNROOT::gMainAnalyzer.InitRootFile("/data1/res048/ROOT/run3734.root");  
  
  LoadVariableFile("config/DetConfig_10302014.in");

  SetCalibrations();
  
  gMainAnalyzer.Loop();
  
  gMainAnalyzer.WriteOut();
}
