
void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){

  TString filesPathData;
  
  filesPathData = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/Old_MediumMuID/23JunFake/";
  
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
