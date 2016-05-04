#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TMath.h"
#include "TSystem.h"
#include "TTree.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Math/PtEtaPhiM4D.h"
#include "TLorentzVector.h"

//typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> > LorentzVector;
// Constants
//------------------------------------------------------------------------------
const Bool_t runAtOviedo = true;

const Double_t ZMASS = 91.1876;  // GeV

const UInt_t numberMetCuts = 5;

const Double_t MetCut[numberMetCuts] = {20, 25, 30, 45, 1000};  // GeV

const UInt_t nLevels = 10;

const Int_t HwidthMVA_NoBin = 17 ;// sizeof(HwidthMVA_Bins);
const Double_t HwidthMVA_Bins[HwidthMVA_NoBin+1] = {-1.00, -0.70, -0.60, -0.50, -0.40, -0.30, -0.20, -0.10, 0.00, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 1.00};

enum {
	TriggerLevel,
	MetCutLevel,
	LowMinvLevel,
	ZVetoLevel,
	pMetCutLevel,
	JetVetoLevel,
	DeltaPhiJetLevel,
	SoftMuVetoLevel,
	ExtraLeptonLevel,
	TopTaggingLevel
};

const TString sLevel[nLevels] = {
	"Trigger",
	"MetCut",
	"LowMinv",
	"ZVeto",
	"pMetCut",
	"JetVeto",
	"DeltaPhiJet",
	"SoftMuVeto",
	"ExtraLepton",
	"TopTagging"
};


// Member functions
//------------------------------------------------------------------------------
void    FillHistograms(UInt_t level,
		UInt_t check);


// Data members
//------------------------------------------------------------------------------
TH1F*   hWeff           [nLevels];

Float_t efficiencyW;
Float_t totalW;
double M_Muon(0.105);

// Tree variables
//------------------------------------------------------------------------------
   Float_t baseW;
   Float_t channel;
   vector<float>   *std_vector_lepton_flavour;
   vector<float>   *std_vector_lepton_pt;
   vector<float>   *std_vector_lepton_eta;
   vector<float>   *std_vector_lepton_phi;

//------------------------------------------------------------------------------
// LatinosTreeScript
//------------------------------------------------------------------------------
void LatinosTreeScript_21OctBis_mcwghtcount_MC_l2selFix_hadd(Float_t luminosity,
		Int_t   jetChannel,
		TString flavorChannel,
		TString theSample,
		Bool_t  isMC,
		Bool_t  verbose)
{
  TH1D*   hMmumu = new TH1D("hMmumu","hMmumu",50,0,15);    ;
  TH1::SetDefaultSumw2();
  
  TString path = Form("rootfiles/%djet/%s/", jetChannel, flavorChannel.Data());
  
  gSystem->mkdir(path, kTRUE);
  
  TFile* output = new TFile(path + theSample + ".root", "recreate");
  //TString NameFout=path + theSample +".txt";
  //ofstream Fout(NameFout);
  
  
  // Histograms
  //----------------------------------------------------------------------------
  //for (UInt_t i=0; i<nLevels; i++) {
  //	hPtLepton1      [i] = new TH1F("hPtLepton1"       + sLevel[i], "", 200, 0, 200);
  //	hPtLepton2      [i] = new TH1F("hPtLepton2"       + sLevel[i], "", 200, 0, 200);
  //}
  
  
  // Data-driven methods: Z+jets
  //----------------------------------------------------------------------------
  TH1F* hMassInZevents  [numberMetCuts];
  TH1F* hMassOutZevents [numberMetCuts];

  for (size_t nC=0; nC<numberMetCuts; nC++) {
  	hMassInZevents  [nC] = new TH1F(Form("hMassInZevents%.2f",   MetCut[nC]), "", 200, 0, 200);
  	hMassOutZevents [nC] = new TH1F(Form("hMassOutZevents%.2f",  MetCut[nC]), "", 200, 0, 200);
  }
  
  
  // Data-driven methods: Top
  //----------------------------------------------------------------------------
  TH1F* hTopTaggedEvents            = new TH1F("hTopTaggedEvents",            "", 3, 0, 3);
  
  //----------------------------------------------------------------------------
  // Input files
  //----------------------------------------------------------------------------
  TString filesPath;
  
  //if (runAtOviedo) filesPath = "/afs/cern.ch/work/x/xjanssen/public/LatinoTrees/R53X_S1_V08_S2_V09_S3_V13/MoriondeffWPuWtriggW/MC_TightTight_DABCABC/";
  //else             filesPath = "/afs/cern.ch/work/x/xjanssen/public/LatinoTrees/R53X_S1_V08_S2_V09_S3_V13/MoriondeffWPuWtriggW/MC_TightTight_DABCABC/";
  
  if (runAtOviedo) filesPath = "/u/user/sangilpark/RunIIData/CernBoxHWW2015/";
  else             filesPath = "/u/user/sangilpark/RunIIData/CernBoxHWW2015/";
  //if (runAtOviedo) filesPath = "root://eoscms.cern.ch//eos/cms/store/user/yjcho/nTuple/";
  //else             filesPath = "root://eoscms.cern.ch//eos/cms/store/user/yjcho/nTuple/";
  TChain* tree = new TChain("latino", "latino");

  if (theSample == "DataRun2015_D") {
  	tree->Add(filesPath + "21OctBis_Run2015D_05Oct2015/l2sel__hadd/" + "latino_Run2015D_05Oct2015_SingleMuon.root");
  	tree->Add(filesPath + "21OctBis_Run2015D_05Oct2015/l2sel__hadd/" + "latino_Run2015D_05Oct2015_SingleElectron.root");
  	tree->Add(filesPath + "21OctBis_Run2015D_05Oct2015/l2sel__hadd/" + "latino_Run2015D_05Oct2015_MuonEG.root");
  	tree->Add(filesPath + "21OctBis_Run2015D_05Oct2015/l2sel__hadd/" + "latino_Run2015D_05Oct2015_DoubleMuon.root");
  	tree->Add(filesPath + "21OctBis_Run2015D_05Oct2015/l2sel__hadd/" + "latino_Run2015D_05Oct2015_DoubleEG.root");
  	
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0716pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_SingleMuon_0716pb.root");
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0716pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_SingleElectron_0716pb.root");
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0716pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_MuonEG_0716pb.root");
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0716pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_DoubleMuon_0716pb.root");
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0716pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_DoubleEG_0716pb.root");
	
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0851pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_DoubleEG_0851pb.root");
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0851pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_SingleElectron_0851pb.root");
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0851pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_MuonEG_0851pb.root");
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0851pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_DoubleMuon_0851pb.root");
	tree->Add(filesPath + "21OctBis_Run2015D_PromptReco_0851pb/l2sel__hadd/" + "latino_Run2915D_PromptReco_DoubleEG_0851pb.root");
  }
  else if (theSample == "WJetsFakes_Total") {
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WJetsToLNu.root");
  	
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WJetsToLNu_HT100_200.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WJetsToLNu_HT200_400.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WJetsToLNu_HT400_600.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WJetsToLNu_HT600_800.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WJetsToLNu_HT800_1200.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WJetsToLNu_HT1200_2500.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WJetsToLNu_HT2500_inf.root");
  }
  else if (theSample == "ggWWto2L") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_GluGluWWTo2L2Nu_MCFM.root");
  }
  else if (theSample == "WWTo2L2Nu") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WWTo2L2Nu.root");
  }
  else if (theSample == "WZ") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WZJets.root");
  }
  else if (theSample == "WZ2Q") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WZTo2L2Q.root");
  }
  else if (theSample == "WZ3LNu") {
  	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WZ.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_WZTo3LNu.root");
  }
  else if (theSample == "ZZ") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_ZZ.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_ZZTo2L2Q.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_ZZTo2L2Nu.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_ZZTo4L.root");
  }
  else if (theSample == "TTbar") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_TTTo2L2Nu.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_TTJets.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_TT.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_TTWJetsToLNu.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_TTZToLLNuNu_M-10.root");
  }
  else if (theSample == "TW") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_ST_tW_antitop.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_ST_tW_top.root");
  }
  else if (theSample == "DY") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_DYJetsToLL_M-10to50.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_DYJetsToLL_M-50.root");
  }
  else if (theSample == "DYtautau") {
  	//tree->Add("/afs/cern.ch/work/x/xjanssen/public/LatinoTrees/R53X_S1_V08_S2_V09_S3_V13/MoriondeffWPuWtriggW/TauTau_btagvar/latino_DYtt_19.5fb.root");
  	//tree->Add(filesPath + "latino_DYtt_19.5fb.root");
  }
  else if (theSample == "WgammaNoStar") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_Wg.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_Wg500.root");
  }
  else if (theSample == "WgammaStar") {
  	//tree->Add(filesPath + "latino_082_WGstarToElNuMad.root");
  	//tree->Add(filesPath + "latino_083_WGstarToMuNuMad.root");
  	//tree->Add(filesPath + "latino_084_WGstarToTauNuMad.root");
  }
  else if (theSample == "HWW125") { 
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_GluGluHToWWTo2L2NuAMCNLO_M125.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_GluGluHToTauTau_M125.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_VBFHToWWTo2L2NuAMCNLO_M125.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_VBFHToTauTau_M125.root");
  	
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_GluGluHToWWTo2L2Nu_M125.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_HWminusJ_HToTauTau_M125.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_HWminusJ_HToWW_M125.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_HWplusJ_HToTauTau_M125.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_HWplusJ_HToWW_M125.root");
  }
  else if (theSample == "Zgamma") { 
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2selFix__hadd/" + "latino_Zg.root");
  }
  else {
  	return;
  }

  // Declaration of leaf types
  //----------------------------------------------------------------------------
  tree->SetBranchAddress("baseW",        &baseW);
  tree->SetBranchAddress("channel",      &channel);
  tree->SetBranchAddress("std_vector_lepton_flavour", &std_vector_lepton_flavour);
  tree->SetBranchAddress("std_vector_lepton_pt", &std_vector_lepton_pt);
  tree->SetBranchAddress("std_vector_lepton_phi",&std_vector_lepton_phi);
  tree->SetBranchAddress("std_vector_lepton_eta",&std_vector_lepton_eta);
  
  //if (theSample.Contains("WJetsFakes"))
  	tree->SetBranchAddress("fakeW", &fakeW);
  
  //if (!theSample.Contains("WJetsFakes") && !theSample.Contains("Data"))
  //	tree->SetBranchAddress("puW", &puW);
  
  
  // Set the channel
  //----------------------------------------------------------------------------
  Float_t SelectedChannel = -999;
  
  if      (flavorChannel == "MuMu") SelectedChannel =  0;
  else if (flavorChannel == "EE"  ) SelectedChannel =  1;
  else if (flavorChannel == "EMu" ) SelectedChannel =  2;
  else if (flavorChannel == "MuE" ) SelectedChannel =  3;
  else if (flavorChannel == "All" ) SelectedChannel = -1;
  else if (flavorChannel == "SSEMuPlus"  ) SelectedChannel =  2; //Channel is the same
  else if (flavorChannel == "SSEMuMinus" ) SelectedChannel =  2;
  else if (flavorChannel == "SSMuEPlus"  ) SelectedChannel =  3;
  else if (flavorChannel == "SSMuEMinus" ) SelectedChannel =  3;
  
  
  //----------------------------------------------------------------------------
  // Loop
  //----------------------------------------------------------------------------
  int TotNtry=tree->GetEntries();
  //TotNtry=50;
  std::vector<TLorentzVector> *v_muon4d;
  std::vector<int> *v_muonFlv;
  v_muon4d  = new std::vector<TLorentzVector>;
  v_muonFlv = new std::vector<int>;
  
  TLorentzVector muon4d;
  for (int ievent=0; ievent<TotNtry; ievent++) {
    // initialize
    v_muon4d->clear();
    v_muonFlv->clear();
    //v_muon4d=0;
    // dump variable
    tree->GetEntry(ievent);
    //cout<<" baseW: "<<baseW<<"\t"<<"channel: "<<channel<<endl;
    //cout<<"Lepton flavor:          pt"<<endl;
    //for(int iLept(0); iLept<std_vector_lepton_flavour->size();iLept++)
    //{
    //}
    int iLept(0);
    double lepton_pt, lepton_eta, lepton_phi, lepton_flv;
    while((*std_vector_lepton_flavour)[iLept] >-9999)
    {
      lepton_flv  = (*std_vector_lepton_flavour)[iLept];
      lepton_pt    = (*std_vector_lepton_pt)[iLept];
      lepton_eta   = (*std_vector_lepton_eta)[iLept];
      lepton_phi   = (*std_vector_lepton_phi)[iLept];
      //cout<<iLept<<"\t"<<lepton_flv<<
      //  "\t"<<lepton_pt<<"\t"<<lepton_eta<<"\t"<<lepton_phi<<endl;
      if(fabs(lepton_flv) ==13)
      {
        muon4d.SetPtEtaPhiM(lepton_pt,lepton_eta,lepton_phi,M_Muon);
        v_muon4d->push_back(muon4d);
        v_muonFlv->push_back(lepton_flv);
      }
      
      iLept++;

    }
    int Nmuon = v_muon4d->size();
    bool WGstarMuonPtCut(false);
    if( (*v_muon4d)[0].Pt() > 20 && (*v_muon4d)[0].Pt() > 10 && (*v_muon4d)[0].Pt() > 3)
      WGstarMuonPtCut = true;
    if( Nmuon == 3 && WGstarMuonPtCut){
      //cout<<"WG* Sample!"<<endl;
      double M_mumu(1000000000.);
      if( (*v_muonFlv)[0] * (*v_muonFlv)[1] < 0)
      {
        TLorentzVector mumu4d = (*v_muon4d)[0];
        mumu4d += (*v_muon4d)[1];
        M_mumu = mumu4d.M();
      }
      if( (*v_muonFlv)[0] * (*v_muonFlv)[2] < 0)
      {
        TLorentzVector mumu4d = (*v_muon4d)[0];
        mumu4d += (*v_muon4d)[2];
        if( mumu4d.M() < M_mumu ) M_mumu = mumu4d.M();
      }
      if( (*v_muonFlv)[1] * (*v_muonFlv)[2] < 0)
      {
        TLorentzVector mumu4d = (*v_muon4d)[1];
        mumu4d += (*v_muon4d)[2];
        if( mumu4d.M() < M_mumu ) M_mumu = mumu4d.M();
      }
      //cout<<"M_mumu: "<<M_mumu<<endl;
      if(M_mumu < 15) hMmumu->Fill(M_mumu);
    }
    totalW      = -999;

    if (theSample.Contains("Data"))
    {
    	totalW = baseW;
    	//totalW = 1.0;
    }
    else if (theSample.Contains("WJetsFakes"))
    {
    	totalW = baseW * luminosity;
    	//totalW = fakeW;
    }
    else
    {
    	//efficiencyW = puW * effW * triggW;
    
    	//totalW = (1 + 0.6 * (dataset >= 82 && dataset <= 84)) * baseW * efficiencyW * luminosity;
    	totalW = baseW * luminosity;
    }

  }

/***************
	// Print
	//----------------------------------------------------------------------------
	if (verbose) {

		printf("\n Expected number of RAW events for %s\n", theSample.Data());
		printf(" -------------------+-----------\n");

		for (UInt_t i=0; i<nLevels; i++)
			printf(" %18s | %.0f\n", sLevel[i].Data(), hW[i]->GetEntries());

		printf("\n");

		if (!theSample.Contains("Data")) {

			printf("\n Normalized to %.3f 1/fb\n", luminosity);
			printf(" -------------------+-----------\n");

			for (UInt_t i=0; i<nLevels; i++)
				printf(" %18s | %.0f\n", sLevel[i].Data(), hW[i]->GetSumOfWeights());

			printf("\n");
		}
	}

**************/
  // Save the histograms
  //----------------------------------------------------------------------------
  output->cd();
  output->Write("", TObject::kOverwrite);
  output->Close();
  //Fout.close();
}


//------------------------------------------------------------------------------
// FillHistograms
//------------------------------------------------------------------------------
void FillHistograms(UInt_t level, UInt_t check)
{
	if (check != 0) return;
/*
	hWeff           [level]->Fill(1,         efficiencyW);
	hW              [level]->Fill(1,         totalW);
	hPtLepton1      [level]->Fill(pt1,       totalW);
	hPtLepton2      [level]->Fill(pt2,       totalW);
	hBDT1           [level]->Fill(bdt1,       totalW);
	hBDT2           [level]->Fill(bdt2,       totalW);
	hPtDiLepton     [level]->Fill(ptll,      totalW);
	hMinv           [level]->Fill(mll,       totalW);
	hMt             [level]->Fill(mth,       totalW);
	hNJets30        [level]->Fill(njet,      totalW);
	hpfMet          [level]->Fill(pfmet,     totalW);
	hppfMet         [level]->Fill(ppfmet,    totalW);
	hchMet          [level]->Fill(chmet,     totalW);
	hpchMet         [level]->Fill(pchmet,    totalW);
	hpminMet        [level]->Fill(mpmet,     totalW);
	hDeltaRLeptons  [level]->Fill(drll,      totalW);
	hDeltaPhiLeptons[level]->Fill(dphill,    totalW);
	hDPhiPtllJet    [level]->Fill(dphilljet, totalW);
	hHwidthMVA      [level]->Fill(HwidthMVAbkg,       totalW);
	*********/
}
