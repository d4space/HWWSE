
void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){

  TString filesPathData;
  TString filesPathMC;
  
  //filesPathData = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_Run2016B_PromptReco/l2loose16bis__hadd__l2tight/";
  //filesPathMC = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/Latino_CernBox/80Xv2/07Jun2016_spring16__mAODv2/MCl2loose__hadd__bSFLepEff__l2tight/";
  filesPathData = "/u/user/sangilpark/Latino_CernBox/80Xv2/21Jun2016_Run2016B_PromptReco/l2loose__hadd__EpTCorr__l2tight/";
  filesPathMC = "/u/user/sangilpark/Latino_CernBox/80Xv2/07Jun2016_spring16_mAODv2/MCl2loose__hadd__bSFL2pTEff__l2tight_Jonatan/";
  
  // l2sel
  if (theSample == "DataRun2015") {
  }else if (theSample == "DataRun2015_C") {
  }else if (theSample == "DataRun2015_D") {
  }else if (theSample == "DataRun2016_B") {
    // Luminosity 2.6 fb^-1 from Xavier mail,
    // https://groups.cern.ch/group/latinos-hep/Lists/Archive/Flat.aspx?RootFolder=%2Fgroup%2Flatinos%2Dhep%2FLists%2FArchive%2FPost%20processing%20for%202%2E6%20fb%2D1%20DONE%20%28AND%20CLOSED%29&FolderCTID=0x012002005F41232413B3A741AEE1524B81D499EF
  	tree->Add( filesPathData + "latino_Run2016B_PromptReco_SingleMuon.root");
  }else if (theSample == "WJetsLNu") {
        tree->Add( filesPathMC + "latino_WJetsToLNu.root");
  }else if (theSample == "WJetsLNu_HT") { 
 	tree->Add( filesPathMC + "latino_WJetsToLNu_HT200_400.root");
 	tree->Add( filesPathMC + "latino_WJetsToLNu_HT400_600.root");
 	tree->Add( filesPathMC + "latino_WJetsToLNu_HT600_800.root");
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
  	tree->Add( filesPathMC + "latino_WZTo1L3Nu.root");
  }else if (theSample == "WZ2Q") {
  	tree->Add( filesPathMC + "latino_WZTo1L1Nu2Q.root");
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
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part5.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part6.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part7.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part8.root");
  	//tree->Add( filesPathMC + "latino_TTTo2L2Nu_ext1__part9.root");
  	//tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0000__part0.root");
  	//tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0000__part2.root");
  	//tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0000__part3.root");
  	//tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0000__part4.root");
  	//tree->Add( filesPathMC + "latino_TTJetsDiLep-LO-ext1_0001__part0.root"); 
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

  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0000__part0.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0000__part1.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0000__part2.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0000__part3.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0000__part4.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0001__part0.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0001__part1.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0001__part2.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0001__part3.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0001__part4.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0002__part0.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0002__part1.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0002__part2.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0002__part3.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0002__part4.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0003__part0.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0003__part1.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0003__part2.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0003__part3.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0003__part4.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0004__part0.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0004__part1.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0004__part2.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50-LO-ext1_0004__part3.root");
  	
	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part0.root");
  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part1.root");
  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part2.root");
  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part3.root");
  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part4.root");
  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part5.root");
  	//tree->Add( filesPathMC + "latino_DY2JetsToLL__part6.root");
  	//tree->Add( filesPathMC + "latino_DY3JetsToLL.root");
  	//tree->Add( filesPathMC + "latino_DY4JetsToLL.root");
  
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0000__part0.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0000__part1.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0000__part2.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0000__part3.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0001__part0.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0001__part1.root");
	//tree->Add( filesPathMC + "latino_DYJetsToEE_Pow_0001__part2.root");
	//tree->Add( filesPathMC + "latino_DYJetsToTT_MuEle_M-50.root");
	
  }else if (theSample == "DY_HT") {
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_HT-100to200_ext1.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_HT-200to400_ext1.root");
  	tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_HT-600toInf.root");
  	//tree->Add( filesPathMC + "latino_DYJetsToLL_M-50_HT-600toInf_ext1.root");

  }else if (theSample == "WgammaNoStar") {
  	tree->Add( filesPathMC + "latino_Wg_MADGRAPHMLM.root");
  	//tree->Add( filesPathMC + "latino_Wg500.root");
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
	tree->Add( filesPathMC + "latino_VBFHToWWTo2L2Nu_M125.root");
	//tree->Add( filesPathMC + "latino_VBFHToWWTo2L2NuAMCNLO_M125.root");
	//tree->Add( filesPathMC + "latino_VBFHToWWTo2L2NuPowheg_M125.root");
	//tree->Add( filesPathMC + "latino_VBFHToWWTo2L2Nu_alternative_M125.root");
  }else if (theSample == "Zgamma") { 
	tree->Add( filesPathMC + "latino_Zg.root");
  }else if (theSample == "QCD") { 
	tree->Add( filesPathMC + "latino_QCD_Pt-15to20_MuEnrichedPt5.root");
	tree->Add( filesPathMC + "latino_QCD_Pt-15to20_EMEnriched.root");
	tree->Add( filesPathMC + "latino_QCD_Pt-20to30_EMEnriched.root");
	tree->Add( filesPathMC + "latino_QCD_Pt-20toInf_MuEnrichedPt15.root");
	tree->Add( filesPathMC + "latino_QCD_Pt-30to50_EMEnriched.root");
	tree->Add( filesPathMC + "latino_QCD_Pt-30toInf_DoubleEMEnriched.root");
	tree->Add( filesPathMC + "latino_QCD_Pt-50to80_EMEnriched.root");
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
  }else if (theSample == "ggZH_HToWW_M125") { 
	tree->Add( filesPathMC + "latino_ggZH_HToWW_M125.root");
  }else if (theSample == "ST") { 
	tree->Add( filesPathMC + "latino_ST_s-channel.root");
	tree->Add( filesPathMC + "latino_ST_t-channel_antitop.root");
  }else if (theSample == "ggHToTauTau_M125") { 
	tree->Add( filesPathMC + "latino_GluGluHToTauTau_M125.root");
  }else if (theSample == "HWJ_M125") { 
	tree->Add( filesPathMC + "latino_HWminusJ_HToWW_M125.root");
	tree->Add( filesPathMC + "latino_HWplusJ_HToWW_M125.root");
  }else if (theSample == "HZJ_M125") { 
	tree->Add( filesPathMC + "latino_HZJ_HToWW_M125.root");
  }else if (theSample == "VVTo2L2Nu") { 
	tree->Add( filesPathMC + "latino_VVTo2L2Nu.root");
  }else if (theSample == "WWG") { 
	tree->Add( filesPathMC + "latino_WWG.root");
  }
  else {
        cout<<"Check theSample name, exiting......................."<<endl;
  	return;
  }
 
}
