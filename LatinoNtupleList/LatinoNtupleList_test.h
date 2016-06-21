
void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){

  TString filesPath;
  
  
  filesPath = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/CernBox_Rebeca/";
  
  // l2sel
  if (theSample == "DataRun2015") {
  	tree->Add(filesPath + "03Mar_Run2015C_16Dec2015/WgStarsel__hadd__EpTCorr/" + "latino_Run2015C_16Dec2015_SingleMuon.root");
  	tree->Add(filesPath + "03Mar_Run2015D_16Dec2015/WgStarsel__hadd__EpTCorr/" + "latino_Run2015D_16Dec2015_SingleMuon.root");
  	//tree->Add(filesPath + "03Mar_Run2015C_16Dec2015/WgStarsel__hadd__EpTCorr/" + "latino_Run2015C_16Dec2015_SingleElectron.root");
  	//tree->Add(filesPath + "03Mar_Run2015D_16Dec2015/WgStarsel__hadd__EpTCorr/" + "latino_Run2015D_16Dec2015_SingleElectron.root");
  }else if (theSample == "DataRun2015_C") {
  	tree->Add(filesPath + "03Mar_Run2015C_16Dec2015/WgStarsel__hadd__EpTCorr/" + "latino_Run2015C_16Dec2015_SingleMuon.root");
  	//tree->Add(filesPath + "03Mar_Run2015C_16Dec2015/WgStarsel__hadd__EpTCorr/" + "latino_Run2015C_16Dec2015_SingleElectron.root");
  }else if (theSample == "DataRun2015_D") {
  	tree->Add(filesPath + "03Mar_Run2015D_16Dec2015/WgStarsel__hadd__EpTCorr/" + "latino_Run2015D_16Dec2015_SingleMuon.root");
  	//tree->Add(filesPath + "03Mar_Run2015D_16Dec2015/WgStarsel__hadd__EpTCorr/" + "latino_Run2015D_16Dec2015_SingleElectron.root");
  }
  else if (theSample == "WJetsLNu") {
    if (runAtLxplus) tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu.root");
    else tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu.root");
  }
  else if (theSample == "WJetsLNu_HT") { 
    if (runAtLxplus)
    {
  	tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT100_200.root");
  	tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT200_400.root");
  	tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT400_600.root");
  	tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT600_800.root");
  	tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT800_1200.root");
  	tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT1200_2500.root");
  	tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT2500_inf.root");
    }
    else
    {
  	tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT100_200.root");
  	tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT200_400.root");
  	tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT400_600.root");
  	tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT600_800.root");
  	tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT800_1200.root");
  	tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT1200_2500.root");
  	tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WJetsToLNu_HT2500_inf.root");
    }
  }
  else if (theSample == "ggWWto2L") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_GluGluWWTo2L2Nu_MCFM.root");
  }
  else if (theSample == "WWTo2L2Nu") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_WWTo2L2Nu.root");
  }
  else if (theSample == "WZ") {
  	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WZ.root");
  	if (runAtLxplus) tree->Add("~/eos_cernbox/user/j/jlauwers/HWW2015/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WZJets.root");
  	else tree->Add("dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/cernboxHWW76X/22Jan_25ns_mAODv2_MC/MCl2loose__hadd/latino_WZJets.root");
  }
  else if (theSample == "WZ2Q") {
  	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part0.root");
  }
  else if (theSample == "WZ3LNu") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCWgStarsel__hadd__EpTCorr/" + "latino_WZTo3LNu.root");
  }
  else if (theSample == "ZZ") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZ.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo4L.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Nu.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Q_0000__part0.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Q_0000__part1.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Q_0000__part2.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Q_0000__part3.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Q_0000__part4.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Q_0001__part0.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Q_0001__part1.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ZZTo2L2Q_0001__part2.root");
  }
  else if (theSample == "TTbar") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_TTTo2L2Nu.root");
  }
  else if (theSample == "TW") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ST_tW_antitop.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_ST_tW_top.root");
  }
  else if (theSample == "DY") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-10to50.root"); // buggy
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-10to50ext3.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0000__part0.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0000__part1.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0000__part2.root");
  	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0000__part3.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0000__part4.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0001__part0.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0001__part1.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0001__part2.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0001__part3.root");
  	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0001__part4.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50_0002__part0.root");
  	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50-LO__part0.root");
  	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_DYJetsToLL_M-50-LO__part1.root");
  }
  else if (theSample == "DYtautau") {
  	//tree->Add("/afs/cern.ch/work/x/xjanssen/public/LatinoTrees/R53X_S1_V08_S2_V09_S3_V13/MoriondeffWPuWtriggW/TauTau_btagvar/latino_DYtt_19.5fb.root");
  	//tree->Add(filesPath + "latino_DYtt_19.5fb.root");
  }
  else if (theSample == "WgammaNoStar") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCWgStarsel__hadd__EpTCorr/" + "latino_Wg_AMCNLOFXFX.root");
  }
  else if (theSample == "WgammaStarToLNuMuMu") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCWgStarsel__hadd__EpTCorr/" + "latino_WgStarLNuMuMu.root");
  }
  else if (theSample == "WgammaStarToLNuEE") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCWgStarsel__hadd__EpTCorr/" + "latino_WgStarLNuEE.root");
  }
  else if (theSample == "HWW125") { 
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_GluGluHToWWTo2L2Nu_M125.root");
  	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_GluGluHToWWTo2L2Nu_alternative_M125.root");
  	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_GluGluHToWWTo2L2NuPowheg_M125.root");
  	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_GluGluHToWWTo2L2NuHerwigPS_M125.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_GluGluHToTauTau_M125.root");
  	
	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_VBFHToTauTau_M125.root");
	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_VBFHToWWTo2L2Nu_M125.root");
	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_VBFHToWWTo2L2Nu_HerwigPS_M125.root");
	//tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_VBFHToWWTo2L2Nu_alternative_M125.root");
  }
  else if (theSample == "Zgamma") { 
	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd__bSFL2pTEff__l2tight/" + "latino_Zg.root");
  }
  else {
        cout<<"Check theSample name, exiting......................."<<endl;
  	return;
  }
 
}
