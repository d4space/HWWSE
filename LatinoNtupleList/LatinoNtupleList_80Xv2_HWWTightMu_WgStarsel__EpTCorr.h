
void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){

  TString filesPathData_21Jun;
  TString filesPathData_05Jul;
  TString filesPathData_08Jul;
  TString filesPathData_08Jul_Run2016C;
  TString filesPathMC;
  
  //filesPathData = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_Run2016B_PromptReco/l2loose16bis__hadd__l2tight/";
  //filesPathMC = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_spring16__mAODv2/MCl2loose__hadd__bSFLepEff__l2tight/";
  filesPathData_21Jun = "/u/user/sangilpark/Latino_CernBox/80Xv2/HWWTightMu/21Jun2016_Run2016B_PromptReco/WgStarsel__hadd__EpTCorr/";
  filesPathData_05Jul = "/u/user/sangilpark/Latino_CernBox/80Xv2/HWWTightMu/05Jul2016_Run2016B_PromptReco/WgStarsel__hadd__EpTCorr/";
  filesPathData_08Jul = "/u/user/sangilpark/Latino_CernBox/80Xv2/HWWTightMu/08Jul2016_Run2016B_PromptReco/WgStarsel__hadd__EpTCorr/";
  filesPathData_08Jul_Run2016C = "/u/user/sangilpark/Latino_CernBox/80Xv2/HWWTightMu/08Jul2016_Run2016C_PromptReco/WgStarsel__hadd__EpTCorr/";
  filesPathMC = "/u/user/sangilpark/Latino_CernBox/80Xv2/HWWTightMu/07Jun2016_spring16_mAODv2_4p0fbm1/MCWgStarsel__hadd__EpTCorr/";
  
  // l2sel
  if (theSample == "DataRun2015") {
  }else if (theSample == "DataRun2015_C") {
  }else if (theSample == "DataRun2015_D") {
  }else if (theSample == "DataRun2016_B") {
    // Luminosity 2.791 + 1.546 + 1.549 +  0.378  (21June + 05Jul + 08Jul + 08Jul_Run2016C) fb^-1 from Xavier's mail,
    // https://groups.cern.ch/group/latinos-hep/Lists/Archive/Flat.aspx?RootFolder=%2Fgroup%2Flatinos%2Dhep%2FLists%2FArchive%2F6fb%2D1%20of%20data%20post%2Dprocessed&FolderCTID=0x012002005F41232413B3A741AEE1524B81D499EF
  	tree->Add( filesPathData_21Jun + "latino_Run2016B_PromptReco_SingleMuon.root");
  	tree->Add( filesPathData_05Jul + "latino_Run2016B_PromptReco_SingleMuon.root");
  	tree->Add( filesPathData_08Jul + "latino_Run2016B_PromptReco_SingleMuon.root");
  }else if (theSample == "DataRun2016_C") {
  	tree->Add( filesPathData_08Jul_Run2016C + "latino_Run2016B_PromptReco_SingleMuon.root");
  }else if (theSample == "WJetsLNu") {
  }else if (theSample == "WJetsLNu_HT") { 
  }else if (theSample == "ggWWto2L") {
  }else if (theSample == "WWTo2L2Nu") {
  }else if (theSample == "WZ") {
  }else if (theSample == "WZ2Q") {
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part0.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part1.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part2.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part3.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part4.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part5.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part6.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part7.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part8.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part9.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part10.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part11.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part12.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part13.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part14.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part15.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part16.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part17.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part18.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part19.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part20.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part21.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part22.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part23.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part24.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part25.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part26.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part27.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part28.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part29.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part30.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part31.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part32.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part33.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part34.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part35.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part36.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part37.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part38.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part39.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part40.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part41.root");
    	tree->Add( filesPathMC + "latino_WZTo2L2Q__part42.root");
  }else if (theSample == "WZ3LNu") {
    	tree->Add( filesPathMC + "latino_WZTo3LNu.root");
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
  	tree->Add( filesPathMC + "latino_Wg_MADGRAPHMLM.root");
  	tree->Add( filesPathMC + "latino_Wg500.root");
  }else if (theSample == "WgammaStarToLNuMuMu") {
  	tree->Add( filesPathMC + "latino_WgStarLNuMuMu.root");
  }else if (theSample == "WgammaStarToLNuEE") {
  	tree->Add( filesPathMC + "latino_WgStarLNuEE.root");
  }else if (theSample == "HWW125") { 
  }else if (theSample == "Zgamma") { 
  }
  else {
        cout<<"Check theSample name, exiting......................."<<endl;
  	return;
  }
 
}
