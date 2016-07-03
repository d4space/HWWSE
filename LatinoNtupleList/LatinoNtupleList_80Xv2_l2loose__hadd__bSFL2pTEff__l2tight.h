
void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){

  TString filesPathData;
  TString filesPathMC;
  
  //filesPathData = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_Run2016B_PromptReco/l2loose16bis__hadd__l2tight/";
  //filesPathMC = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_spring16__mAODv2/MCl2loose__hadd__bSFLepEff__l2tight/";
  filesPathData = "/u/user/sangilpark/Latino_CernBox/80Xv2/07Jun2016_Run2016B_PromptReco/l2loose16bis__hadd__l2tight/";
  filesPathMC = "/u/user/sangilpark/Latino_CernBox/80Xv2/07Jun2016_spring16_mAODv2/MCl2loose__hadd__bSFL2pTEff__l2tight/";
  
  // l2sel
  if (theSample == "DataRun2015") {
  }else if (theSample == "DataRun2015_C") {
  }else if (theSample == "DataRun2015_D") {
  }else if (theSample == "DataRun2016_B") {
    // Luminosity : 805 pb^-1 from Xavier mail,
    // https://groups.cern.ch/group/latinos-hep/Lists/Archive/Flat.aspx?RootFolder=%2Fgroup%2Flatinos%2Dhep%2FLists%2FArchive%2F805%20pb%2D1%20of%20data%20post%2Dprocessed&FolderCTID=0x012002005F41232413B3A741AEE1524B81D499EF
  	tree->Add( filesPathData + "latino_Run2016B_PromptReco_SingleMuon.root");
  }else if (theSample == "WJetsLNu") {
        tree->Add( filesPathMC + "latino_WJetsToLNu.root");
  }else if (theSample == "WJetsLNu_HT") { 
 	tree->Add( filesPathMC + "latino_WJetsToLNu_HT200_400.root");
 	tree->Add( filesPathMC + "latino_WJetsToLNu_HT2500_inf.root");
  }else if (theSample == "ggWWto2L") {
        tree->Add( filesPathMC + "latino_GluGluWWTo2L2Nu_MCFM.root"); // /GluGluWWTo2L2Nu_MCFM_13TeV/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM
        //tree->Add( filesPathMC + "latino_GluGluWWTo2L2NuHiggs_MCFM.root"); // /GluGluWWTo2L2Nu_HInt_MCFM_13TeV/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM
  }else if (theSample == "WWTo2L2Nu") {
        tree->Add( filesPathMC + "latino_WWTo2L2Nu.root");
        //tree->Add( filesPathMC + "latino_WWTo2L2NuHerwigPS.root"); // WW PS
        //tree->Add( filesPathMC + "latino_WWTo2L2Nu_CUETDown.root"); // WW CUET variations
  }else if (theSample == "WZ") {
  	tree->Add( filesPathMC + "latino_WZ.root");
  }else if (theSample == "WZ2Q") {
  }else if (theSample == "WZ3LNu") {
  }else if (theSample == "ZZ") {
  	tree->Add( filesPathMC + "latino_ZZ.root");
  	tree->Add( filesPathMC + "latino_ZZTo2L2Nu.root"); // /ZZTo2L2Nu_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM
  	tree->Add( filesPathMC + "latino_ZZTo2L2Q__part0.root"); // /ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM
  	tree->Add( filesPathMC + "latino_ZZTo2L2Q__part1.root");
  	//tree->Add( filesPathMC + "latino_ZZTo2L2Q__part2.root");
  	tree->Add( filesPathMC + "latino_ZZTo2L2Q__part3.root");
  	//tree->Add( filesPathMC + "latino_ZZTo4L.root"); // /ZZTo4L_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM
  }else if (theSample == "TTbar") {
  	tree->Add( filesPathMC + "latino_TTJets.root");
  	tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part0.root"); // /TTTo2L2Nu_13TeV-powheg/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM
  	tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part1.root");
  	tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part2.root");
  	tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part3.root");
  	tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part4.root");
  	tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0000__part2.root");
  	tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0000__part4.root");
  	tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0001__part1.root"); // /TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3_ext1-v1/MINIAODSIM
  }else if (theSample == "TW") {
  	tree->Add( filesPathMC + "latino_ST_tW_antitop.root"); // /ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM
  	//tree->Add( filesPathMC + "latino_ST_tW_antitop_noHad.root");  // /ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM
  	tree->Add( filesPathMC + "latino_ST_tW_top.root"); // /ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v2/MINIAODSIM
  	//tree->Add( filesPathMC + "latino_ST_tW_top_noHad.root"); // /ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM
  }else if (theSample == "DY") {
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-5to50-LO.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-10to50-LO.root");
  	
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

  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part1.root");
  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part2.root");
  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part5.root");
  	//tree->Add( filesPathMC + "latino_DY3JetsToLL.root");
  	//tree->Add( filesPathMC + "latino_DY4JetsToLL.root");

  }else if (theSample == "WgammaNoStar") {
  }else if (theSample == "WgammaStarToLNuMuMu") {
  	tree->Add( filesPathMC + "latino_WgStarLNuMuMu.root");
  }else if (theSample == "WgammaStarToLNuEE") {
  	tree->Add( filesPathMC + "latino_WgStarLNuEE.root");
  }else if (theSample == "HWW125") { 
	tree->Add( filesPathMC + "latino_GluGluHToWWTo2L2NuAMCNLO_M125.root");
	//tree->Add( filesPathMC + "latino_GluGluHToWWTo2L2NuPowheg_M125.root");
	//tree->Add( filesPathMC + "latino_GluGluHToWWTo2L2Nu_alternative_M125.root");
	
	tree->Add( filesPathMC + "latino_VBFHToTauTau_M125.root");
	//tree->Add( filesPathMC + "latino_VBFHToTauTau_M125_HerwigPS.root");
	tree->Add( filesPathMC + "latino_VBFHToWWTo2L2NuPowheg_M125.root");
	//tree->Add( filesPathMC + "latino_VBFHToWWTo2L2Nu_alternative_M125.root");
  }else if (theSample == "Zgamma") { 
	tree->Add( filesPathMC + "latino_Zg.root");
  }
  else {
        cout<<"Check theSample name, exiting......................."<<endl;
  	return;
  }
 
}
