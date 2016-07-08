
void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){

  TString filesPathData;
  TString filesPathMC;
  
  //filesPathData = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_Run2016B_PromptReco/l2loose16bis__hadd__l2tight/";
  //filesPathMC = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_spring16__mAODv2/MCl2loose__hadd__bSFLepEff__l2tight/";
  filesPathData = "/u/user/sangilpark/Latino_CernBox/80Xv2/23JunFake/";
  //filesPathMC = "/u/user/sangilpark/Latino_CernBox/80Xv2/07Jun2016_spring16_mAODv2/MCWgStarsel__hadd__EpTCorr/";
  
  // l2sel
  if (theSample == "DataRun2015") {
  }else if (theSample == "DataRun2015_C") {
  }else if (theSample == "DataRun2015_D") {
  }else if (theSample == "DataRun2016_B") {
  	tree->Add( filesPathData + "latino_DD_Run2016B_PromptReco_SingleMuon.root");
  	tree->Add( filesPathData + "latino_DD_Run2016B_PromptReco_SingleElectron.root");
  	tree->Add( filesPathData + "latino_DD_Run2016B_PromptReco_DoubleMuon.root");
  	tree->Add( filesPathData + "latino_DD_Run2016B_PromptReco_DoubleEG.root");
  	tree->Add( filesPathData + "latino_DD_Run2016B_PromptReco_MuonEG.root");
  }else if (theSample == "WJetsLNu") {
  }else if (theSample == "WJetsLNu_HT") { 
  }else if (theSample == "ggWWto2L") {
  }else if (theSample == "WWTo2L2Nu") {
  }else if (theSample == "WZ") {
  }else if (theSample == "WZ2Q") {
  }else if (theSample == "WgammaNoStar") {
  }else if (theSample == "WgammaStarToLNuMuMu") {
  }else if (theSample == "WgammaStarToLNuEE") {
  }else if (theSample == "HWW125") { 
  }else if (theSample == "Zgamma") { 
  }
  else {
        cout<<"Check theSample name, exiting......................."<<endl;
  	return;
  }
 
}
