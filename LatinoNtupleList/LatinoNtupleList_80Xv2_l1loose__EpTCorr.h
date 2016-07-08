
void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){

  TString filesPathData;
  TString filesPathMC;
  
  //filesPathData = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_Run2016B_PromptReco/l2loose16bis__hadd__l2tight/";
  //filesPathMC = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_spring16__mAODv2/MCl2loose__hadd__bSFLepEff__l2tight/";
  filesPathData = "/u/user/sangilpark/Latino_CernBox/80Xv2/21Jun2016_Run2016B_PromptReco/l1loose__EpTCorr__hadd/";
  filesPathMC = "/u/user/sangilpark/Latino_CernBox/80Xv2/07Jun2016_spring16_mAODv2/MCl1loose__EpTCorr__hadd/";
  
  // l2sel
  if (theSample == "DataRun2015") {
  }else if (theSample == "DataRun2015_C") {
  }else if (theSample == "DataRun2015_D") {
  }else if (theSample == "DataRun2016_B") {
    // Luminosity : 2.6fb pb^-1 from Xavier mail,
    // https://groups.cern.ch/group/latinos-hep/Lists/Archive/Flat.aspx?RootFolder=%2Fgroup%2Flatinos%2Dhep%2FLists%2FArchive%2FPost%20processing%20for%202%2E6%20fb%2D1%20DONE%20%28AND%20CLOSED%29&FolderCTID=0x012002005F41232413B3A741AEE1524B81D499EF
  	tree->Add( filesPathData + "latino_Run2016B_PromptReco_SingleMuon.root");
  }else if (theSample == "WJetsLNu") {
  }else if (theSample == "WJetsLNu_HT") { 
  }else if (theSample == "ggWWto2L") {
  }else if (theSample == "WWTo2L2Nu") {
  }else if (theSample == "WZ") {
  }else if (theSample == "WZ2Q") {
  }else if (theSample == "WZ3LNu") {
  }else if (theSample == "ZZ") {
  }else if (theSample == "TTbar") {
  }else if (theSample == "TW") {
  }else if (theSample == "DY") {
    	tree->Add( filesPathMC + "latino_DYJetsToLL_M-10to50.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0000__part0.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0000__part1.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0000__part2.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0000__part3.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0000__part4.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0001__part0.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0001__part1.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0001__part2.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0001__part3.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0001__part4.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_0002__part0.root");
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
