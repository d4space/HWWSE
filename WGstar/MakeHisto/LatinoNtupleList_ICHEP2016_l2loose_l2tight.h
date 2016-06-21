  

void ConnectTree(TChain* tree, TString theSample, Bool_t runAtLxplus){


  TString PathDcapKNU = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/CernBox_Jasper_76X/07Jun2016_Run2016B_PromptReco/";
  TString PathUser    = "/u/user/sangilpark/Cernbox_Jasper/07Jun2016_spring16__mAODv2/MCl2loose16__hadd__l2tight/";
  
  TChain* tree = new TChain("latino", "latino");
  
  if (theSample == "DataRun2015") {
  }
  else if (theSample == "DataRun2015_C") {
  }
  else if (theSample == "DataRun2015_D") {
  }
  else if (theSample == "DataRun2016_B") {
    // Luminosity : 805 pb^-1 from Xavier mail,
    // https://groups.cern.ch/group/latinos-hep/Lists/Archive/Flat.aspx?RootFolder=%2Fgroup%2Flatinos%2Dhep%2FLists%2FArchive%2F805%20pb%2D1%20of%20data%20post%2Dprocessed&FolderCTID=0x012002005F41232413B3A741AEE1524B81D499EF
  	tree->Add( PathDcapKNU + "latino_Run2016B_PromptReco_SingleMuon.root");
  }
  else if (theSample == "WJetsLNu") {
    tree->Add(PathUser + "latino_WJetsToLNu.root");
  }
  else if (theSample == "WJetsLNu_HT") { 
  	tree->Add( PathUser + "latino_WJetsToLNu_HT2500_inf.root");
  }
  else if (theSample == "ggWWto2L") {
  }
  else if (theSample == "WWTo2L2Nu") {
  }
  else if (theSample == "WZ") {
  	tree->Add( PathUser + "latino_WZ.root");
  }
  else if (theSample == "WZ2Q") {
  }
  else if (theSample == "WZ3LNu") {
  }
  else if (theSample == "ZZ") {
  }
  else if (theSample == "TTbar") {
  }
  else if (theSample == "TW") {
  }
  else if (theSample == "DY") {
  	tree->Add( PathUser + "latino_DYJetsToLL_M-10to50.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0000__part0.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0000__part1.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0000__part2.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0000__part3.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0000__part4.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0001__part0.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0001__part1.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0001__part2.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0001__part3.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0001__part4.root");
  	tree->Add( PathUser + "latino_DYJetsToLL_M-50_0002__part4.root");
  }
  else if (theSample == "WgammaNoStar") {
  }
  else if (theSample == "WgammaStarToLNuMuMu") {
  	tree->Add( PathUser + "latino_WgStarLNuMuMu.root");
  }
  else if (theSample == "WgammaStarToLNuEE") {
  	tree->Add( PathUser + "latino_WgStarLNuEE.root");
  }
  else if (theSample == "HWW125") { 
	tree->Add( PathUser + "latino_VBFHToTauTau_M125.root");
	tree->Add( PathUser + "latino_VBFHToWWTo2L2Nu_alternative_M125.root");
  }
  else if (theSample == "Zgamma") { 
	tree->Add( PathUser + "latino_Zg.root");
  }
  else {
        cout<<"Check theSample name, exiting......................."<<endl;
  	return;
  }

}
