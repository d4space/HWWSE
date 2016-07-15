
void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){

  TString filesPathMC;
  
  filesPathMC = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/Old_MediumMuID/07Jun2016_spring16_mAODv2/MCl2loose__hadd__bSFL2pTEff__l2tight/";
  
  // l2sel
  if (theSample == "DataRun2015") {
  }else if (theSample == "DataRun2015_C") {
  }else if (theSample == "DataRun2015_D") {
  }else if (theSample == "DataRun2016_B") {
  }else if (theSample == "WJetsLNu") {
        tree->Add( filesPathMC + "latino_WJetsToLNu.root");
  }else if (theSample == "WJetsLNu_HT") { 
 	tree->Add( filesPathMC + "latino_WJetsToLNu_HT200_400.root");
 	tree->Add( filesPathMC + "latino_WJetsToLNu_HT2500_inf.root");
  }else if (theSample == "ggWWto2L") {
        tree->Add( filesPathMC + "latino_GluGluWWTo2L2Nu_MCFM.root"); 
        //tree->Add( filesPathMC + "latino_GluGluWWTo2L2NuHiggs_MCFM.root"); 
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
  	//tree->Add( filesPathMC + "latino_ZZTo2L2Nu.root"); 
  	//tree->Add( filesPathMC + "latino_ZZTo2L2Q__part0.root"); 
  	//tree->Add( filesPathMC + "latino_ZZTo2L2Q__part1.root");
  	//tree->Add( filesPathMC + "latino_ZZTo2L2Q__part2.root");
  	//tree->Add( filesPathMC + "latino_ZZTo2L2Q__part3.root");
  	//tree->Add( filesPathMC + "latino_ZZTo4L.root"); 
  }else if (theSample == "TTbar") {
  	tree->Add( filesPathMC + "latino_TTJets.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part0.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part1.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part2.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part3.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part4.root");
  	//tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0000__part2.root");
  	//tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0000__part4.root");
  	//tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0001__part1.root"); 
  }else if (theSample == "TW") {
  	tree->Add( filesPathMC + "latino_ST_tW_antitop.root"); 
  	//tree->Add( filesPathMC + "latino_ST_tW_antitop_noHad.root"); 
  	tree->Add( filesPathMC + "latino_ST_tW_top.root"); 
  	//tree->Add( filesPathMC + "latino_ST_tW_top_noHad.root"); 
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
  
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0000__part1.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0000__part2.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0000__part3.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0001__part2.root");
  }else if (theSample == "DY_HT") {
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_HT-100to200_ext1.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_HT-200to400_ext1.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_HT-600toInf.root");

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
	//tree->Add( filesPathMC + "latino_VBFHToTauTau_M125_PythiaFragment_Up.root");
	//tree->Add( filesPathMC + "latino_VBFHToTauTau_M125_PythiaFragment_Down.root");
	tree->Add( filesPathMC + "latino_VBFHToWWTo2L2NuPowheg_M125.root");
	//tree->Add( filesPathMC + "latino_VBFHToWWTo2L2Nu_alternative_M125.root");
  }else if (theSample == "Zgamma") { 
	tree->Add( filesPathMC + "latino_Zg.root");
  }else if (theSample == "QCD") { 
	tree->Add( filesPathMC + "latino_QCD_Pt-15to20_MuEnrichedPt5.root");
	tree->Add( filesPathMC + "latino_QCD_Pt_250toInf_bcToE.root");
  }else if (theSample == "TTWJetsLNu") { 
	tree->Add( filesPathMC + "latino_TTWJetsToLNu.root");
  }else if (theSample == "TTWJets2Q") { 
	tree->Add( filesPathMC + "latino_TTWJetsToQQ.root");
  }else if (theSample == "TTZjet") { 
	tree->Add( filesPathMC + "latino_TTZjets.root");
	//tree->Add( filesPathMC + "latino_TTZToQQ.root");
	//tree->Add( filesPathMC + "latino_TTZToLLNuNu_M-10.root");
  }else if (theSample == "WWW") { 
	tree->Add( filesPathMC + "latino_WWW.root");
  }else if (theSample == "WWZ") { 
	tree->Add( filesPathMC + "latino_WWZ.root");
  }else if (theSample == "WZZ") { 
	tree->Add( filesPathMC + "latino_WZZ.root");
  }else if (theSample == "ZZZ") { 
	tree->Add( filesPathMC + "latino_ZZZ.root");
  }else if (theSample == "WW") { 
	tree->Add( filesPathMC + "latino_WW-LO.root");
	//tree->Add( filesPathMC + "latino_WW_DoubleScattering.root");
	//tree->Add( filesPathMC + "latino_WWTo4Q.root");
	//tree->Add( filesPathMC + "latino_WWToLNuQQext.root");
  }else if (theSample == "WpWpJJ") { 
	tree->Add( filesPathMC + "latino_WpWpJJ_EWK.root");
	tree->Add( filesPathMC + "latino_WpWpJJ_EWK_QCD.root");
	tree->Add( filesPathMC + "latino_WpWpJJ_QCD.root");
  }else if (theSample == "bbHWWTo2L2Nu_M125") { 
	tree->Add( filesPathMC + "latino_bbHToWWTo2L2Nu_M125_yb2.root");
	tree->Add( filesPathMC + "latino_bbHToWWTo2L2Nu_M125_ybyt.root");
  }else if (theSample == "ST") { 
	tree->Add( filesPathMC + "latino_ST_s-channel.root");
	tree->Add( filesPathMC + "latino_ST_t-channel_antitop.root");
  }else if (theSample == "ggHToTauTau_M125") { 
	tree->Add( filesPathMC + "latino_GluGluHToTauTau_M125.root");
  }
  else {
        cout<<"Check theSample name, exiting......................."<<endl;
  	return;
  }
 
}
