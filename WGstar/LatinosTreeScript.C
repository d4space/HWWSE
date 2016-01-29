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
   Float_t fakeW;
   Float_t channel;
   Float_t Gen_ZGstar_deltaR;
   Float_t Gen_ZGstar_mass;
   Float_t Gen_ZGstar_mu1_eta;
   Float_t Gen_ZGstar_mu1_phi;
   Float_t Gen_ZGstar_mu1_pt;
   Float_t Gen_ZGstar_mu2_eta;
   Float_t Gen_ZGstar_mu2_phi;
   Float_t Gen_ZGstar_mu2_pt;

   vector<float>   *std_vector_lepton_flavour;
   vector<float>   *std_vector_lepton_pt;
   vector<float>   *std_vector_lepton_eta;
   vector<float>   *std_vector_lepton_phi;

//------------------------------------------------------------------------------
// LatinosTreeScript
//------------------------------------------------------------------------------
void LatinosTreeScript(Float_t luminosity,
		Int_t   jetChannel,
		TString flavorChannel,
		TString theSample,
		Bool_t  GEnStudy,
		Bool_t  verbose)
{
  TH1::SetDefaultSumw2();
  
  TString path = Form("rootfiles/%djet/%s/", jetChannel, flavorChannel.Data());
  
  gSystem->mkdir(path, kTRUE);
  
  TFile* output = new TFile(path + theSample + ".root", "recreate");
  TString NameFout=path + theSample +".txt";
  ofstream Fout(NameFout);
  
  TH1D*   hInvDimu_Recon = new TH1D("hInvDimu_Recon","hInvDimu_Recon",50,0,15);
  TH1D*   hInvDimu_Gen   = new TH1D("hInvDimu_Gen","hInvDimu_Gen",50,0,15); 
  TH1D*   hNmuons   = new TH1D("hNmuons","hNmuons",5,0,5); 
  TH1D*   hTriMuOrder   = new TH1D("hTriMuOrder","hTriMuOrder",10,0,10); 
  TH1D*   hMu1_pt   = new TH1D("hMu1_pt","hMu1_pt",50,0,50); 
  TH1D*   hMu2_pt   = new TH1D("hMu2_pt","hMu2_pt",50,0,50); 
  TH1D*   hMu3_pt   = new TH1D("hMu3_pt","hMu3_pt",50,0,50); 
  
  // Histograms
  //----------------------------------------------------------------------------
  //for (UInt_t i=0; i<nLevels; i++) {
  //	hPtLepton1      [i] = new TH1F("hPtLepton1"       + sLevel[i], "", 200, 0, 200);
  //	hPtLepton2      [i] = new TH1F("hPtLepton2"       + sLevel[i], "", 200, 0, 200);
  //}
  
  
  // Data-driven methods: Z+jets
  //----------------------------------------------------------------------------

  
  // Data-driven methods:
  //----------------------------------------------------------------------------
  
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

  // l2sel
  if (theSample == "DataRun2015_D") {
  	tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel/" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part0.root");
  	tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel/" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part1.root");
  	tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel/" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part2.root");
  	tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel/" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part3.root");
  	tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel/" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part4.root");
  	tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel/" + "latino_Run2015D_05Oct2015_SingleMuon_0001__part0.root");
  }
  else if (theSample == "WJetsFakes_Total") {
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part0.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part1.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part2.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part3.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part4.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part5.root");
  	
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT100_200__part0.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT100_200__part1.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT200_400.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT400_600.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT600_800.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT800_1200.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT1200_2500.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT2500_inf.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu_HT2500_inf__part0.root");
  }
  else if (theSample == "ggWWto2L") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluWWTo2L2Nu_MCFM__part0.root");
  }
  else if (theSample == "WWTo2L2Nu") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WWTo2L2Nu.root");
  }
  else if (theSample == "WZ") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZJets__part0.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZJets__part1.root");
  }
  else if (theSample == "WZ2Q") {
  	/tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part0.root");
  	/tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part1.root");
  	/tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part2.root");
  	/tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part3.root");
  }
  else if (theSample == "WZ3LNu") {
  	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZ.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo3LNu.root");
  }
  else if (theSample == "ZZ") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZ.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part0.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part1.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part2.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part3.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part4.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part5.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part6.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part7.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part8.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part9.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part10.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part11.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part12.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part13.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part14.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part15.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part16.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part17.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part18.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part19.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part20.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part21.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part22.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part23.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Q__part24.root");
  	
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part0.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part1.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part2.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part3.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part4.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part5.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part6.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part7.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part8.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part9.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part10.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part11.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part12.root");

	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part0.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part1.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part2.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part3.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part4.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part5.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part6.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part7.root");
  }
  else if (theSample == "TTbar") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTTo2L2Nu__part0.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTTo2L2Nu__part1.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTTo2L2Nu__part2.root");
  	
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part0.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part1.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part2.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part3.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part4.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part5.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part6.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part7.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part8.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part9.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part10.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part11.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part12.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part13.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part14.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part15.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part16.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part17.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part18.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part19.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part20.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part21.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part22.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part23.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part24.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part25.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part26.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part27.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part28.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part29.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part30.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part31.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part32.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part33.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part34.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part35.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part36.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part37.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part38.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part39.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part40.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part41.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part42.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part43.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part44.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part45.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part46.root");
	
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TT__part0.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TT__part1.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TT__part2.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TT__part3.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TT__part4.root");
	
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTWJetsToLNu.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTZToLLNuNu_M-10.root");
  }
  else if (theSample == "TW") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ST_tW_antitop.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ST_tW_top.root");
  }
  else if (theSample == "DY") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_00.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_01.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_02.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_03.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_04.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_05.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_06.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_07.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_08.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_09.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_10.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_11.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_12.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_13.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_14.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_15.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_16.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_17.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_18.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_19.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_20.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_21.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_22.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_23.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_24.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_25.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_26.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_27.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_28.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_29.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_30.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_31.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_32.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_33.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_34.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_35.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-10to50_0000_36.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_00.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_01.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_02.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_03.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_04.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_05.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_06.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_07.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_08.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_09.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_10.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_11.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_12.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_13.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_14.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_15.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_16.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_17.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_18.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_19.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_20.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_21.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_22.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_23.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_24.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_25.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_26.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_27.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_28.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_29.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_30.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_31.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_32.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_33.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_34.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_35.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_36.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_37.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_38.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_39.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_40.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_41.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_42.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_43.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_44.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_45.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_46.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_47.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_48.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0000_49.root");

  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_00.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_01.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_02.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_03.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_04.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_05.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_06.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_07.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_08.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_09.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_DYJetsToLL_M-50_0001_10.root");
  }
  else if (theSample == "DYtautau") {
  	//tree->Add("/afs/cern.ch/work/x/xjanssen/public/LatinoTrees/R53X_S1_V08_S2_V09_S3_V13/MoriondeffWPuWtriggW/TauTau_btagvar/latino_DYtt_19.5fb.root");
  	//tree->Add(filesPath + "latino_DYtt_19.5fb.root");
  }
  else if (theSample == "WgammaNoStar") {
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_Wg.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_Wg500.root");
  }
  else if (theSample == "WgammaStar") {
  	//tree->Add(filesPath + "latino_082_WGstarToElNuMad.root");
  	//tree->Add(filesPath + "latino_083_WGstarToMuNuMad.root");
  	//tree->Add(filesPath + "latino_084_WGstarToTauNuMad.root");
  }
  else if (theSample == "HWW125") { 
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToWWTo2L2NuAMCNLO_M125__part0.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToWWTo2L2NuAMCNLO_M125__part1.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToWWTo2L2NuAMCNLO_M125__part2.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToWWTo2L2NuAMCNLO_M125__part3.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToWWTo2L2NuAMCNLO_M125.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToTauTau_M125.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_VBFHToTauTau_M125.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_VBFHToWWTo2L2NuAMCNLO_M125.root");
  	
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToWWTo2L2Nu_M125.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_HWminusJ_HToTauTau_M125.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_HWminusJ_HToWW_M125.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_HWplusJ_HToTauTau_M125.root");
	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_HWplusJ_HToWW_M125.root");
  }
  else if (theSample == "Zgamma") { 
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_Zg__part1.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_Zg__part2.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_Zg__part3.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_Zg__part4.root");
  	tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_Zg__part5.root");
  }
  else {
  	return;
  }


  // Declaration of leaf types
  //----------------------------------------------------------------------------
  tree->SetBranchAddress("baseW",        &baseW);
  tree->SetBranchAddress("channel",      &channel);
  //tree->SetBranchAddress("Gen_ZGstar_deltaR",      &Gen_ZGstar_deltaR);
  //tree->SetBranchAddress("Gen_ZGstar_mass",        &Gen_ZGstar_mass);
  //tree->SetBranchAddress("Gen_ZGstar_mu1_eta",     &Gen_ZGstar_mu1_eta);
  //tree->SetBranchAddress("Gen_ZGstar_mu1_phi",     &Gen_ZGstar_mu1_phi);
  //tree->SetBranchAddress("Gen_ZGstar_mu1_pt",      &Gen_ZGstar_mu1_pt);
  //tree->SetBranchAddress("Gen_ZGstar_mu2_eta",     &Gen_ZGstar_mu2_eta);
  //tree->SetBranchAddress("Gen_ZGstar_mu2_phi",     &Gen_ZGstar_mu2_phi);
  //tree->SetBranchAddress("Gen_ZGstar_mu2_pt",      &Gen_ZGstar_mu2_pt);

  tree->SetBranchAddress("std_vector_lepton_flavour", &std_vector_lepton_flavour);
  tree->SetBranchAddress("std_vector_lepton_pt", &std_vector_lepton_pt);
  tree->SetBranchAddress("std_vector_lepton_phi",&std_vector_lepton_phi);
  tree->SetBranchAddress("std_vector_lepton_eta",&std_vector_lepton_eta);
  
  if(theSample.Contains("WJetsFakes"))
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
  std::vector<TLorentzVector> *v_muon4d_recon;
  std::vector<TLorentzVector> *v_muon4d_gen;
  std::vector<int> *v_muonFlv_recon;
  std::vector<int> *v_muonFlv_gen;
  v_muon4d_recon  = new std::vector<TLorentzVector>;
  v_muon4d_gen  = new std::vector<TLorentzVector>;
  v_muonFlv_recon = new std::vector<int>;
  v_muonFlv_gen   = new std::vector<int>;
  
  TLorentzVector muon4d;
  int MuonPtOrder;

  //Cuts=======================
  struct Cuts{
    const double firstMu=20;
    const double secndMu=10;
    const double thirdMu=8;
  }Cuts;

  int TotNtry=tree->GetEntries();
  //TotNtry=500;

  for (int ievent=0; ievent<TotNtry; ievent++) {
    if(ievent%1000 ==0) cout<<"Processing "<<ievent<<"th event"<<endl; 

    // initialize
    v_muon4d_recon->clear();
    v_muon4d_gen->clear();
    v_muonFlv_recon->clear();
    v_muonFlv_gen->clear();
    MuonPtOrder=0;
    //v_muon4d_recon=0;
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
      lepton_pt   = (*std_vector_lepton_pt)[iLept];
      lepton_eta  = (*std_vector_lepton_eta)[iLept];
      lepton_phi  = (*std_vector_lepton_phi)[iLept];
      //cout<<iLept<<"\t"<<lepton_flv<<
      //  "\t"<<lepton_pt<<"\t"<<lepton_eta<<"\t"<<lepton_phi<<endl;
      if(fabs(lepton_flv) ==13)
      {
        muon4d.SetPtEtaPhiM(lepton_pt,lepton_eta,lepton_phi,M_Muon);
        v_muon4d_recon->push_back(muon4d);
        v_muonFlv_recon->push_back(lepton_flv);
      }
      iLept++;

    }
    int Nmuon = v_muon4d_recon->size();
    hNmuons->Fill(Nmuon);
    if(Nmuon < 3)continue;
    //cout<<"Nmuon: "<<Nmuon<<endl;
    bool WGstarMuonPtCut(false);
    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[0].Pt() > Cuts.firstMu && (*v_muon4d_recon)[1].Pt() > Cuts.secndMu && (*v_muon4d_recon)[2].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(1);
      hMu1_pt->Fill((*v_muon4d_recon)[0].Pt());
      hMu2_pt->Fill((*v_muon4d_recon)[1].Pt());
      hMu3_pt->Fill((*v_muon4d_recon)[2].Pt());
    }

    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[0].Pt() > Cuts.firstMu && (*v_muon4d_recon)[2].Pt() > Cuts.secndMu && (*v_muon4d_recon)[1].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(2);
      hMu1_pt->Fill((*v_muon4d_recon)[0].Pt());
      hMu2_pt->Fill((*v_muon4d_recon)[2].Pt());
      hMu3_pt->Fill((*v_muon4d_recon)[1].Pt());
    }
    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[2].Pt() > Cuts.firstMu && (*v_muon4d_recon)[0].Pt() > Cuts.secndMu && (*v_muon4d_recon)[1].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(3);
      hMu1_pt->Fill((*v_muon4d_recon)[2].Pt());
      hMu2_pt->Fill((*v_muon4d_recon)[0].Pt());
      hMu3_pt->Fill((*v_muon4d_recon)[1].Pt());
    }
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[2].Pt() > Cuts.firstMu && (*v_muon4d_recon)[1].Pt() > Cuts.secndMu  && (*v_muon4d_recon)[0].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(4);
      hMu1_pt->Fill((*v_muon4d_recon)[2].Pt());
      hMu2_pt->Fill((*v_muon4d_recon)[1].Pt());
      hMu3_pt->Fill((*v_muon4d_recon)[0].Pt());
    }
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[1].Pt() > Cuts.firstMu && (*v_muon4d_recon)[2].Pt() > Cuts.secndMu && (*v_muon4d_recon)[0].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(5);
      hMu1_pt->Fill((*v_muon4d_recon)[1].Pt());
      hMu2_pt->Fill((*v_muon4d_recon)[2].Pt());
      hMu3_pt->Fill((*v_muon4d_recon)[0].Pt());
    }
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[1].Pt() > Cuts.firstMu && (*v_muon4d_recon)[0].Pt() > Cuts.secndMu && (*v_muon4d_recon)[2].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(6);
      hMu1_pt->Fill((*v_muon4d_recon)[1].Pt());
      hMu2_pt->Fill((*v_muon4d_recon)[0].Pt());
      hMu3_pt->Fill((*v_muon4d_recon)[2].Pt());
    }

    if( Nmuon == 3 && WGstarMuonPtCut){
      //cout<<"WG* Sample!"<<endl;
      double M_mumu(1000000000.);
      if( (*v_muonFlv_recon)[0] * (*v_muonFlv_recon)[1] < 0)
      {
        TLorentzVector mumu4d = (*v_muon4d_recon)[0];
        mumu4d += (*v_muon4d_recon)[1];
        M_mumu = mumu4d.M();
      }
      if( (*v_muonFlv_recon)[0] * (*v_muonFlv_recon)[2] < 0)
      {
        TLorentzVector mumu4d = (*v_muon4d_recon)[0];
        mumu4d += (*v_muon4d_recon)[2];
        if( mumu4d.M() < M_mumu ) M_mumu = mumu4d.M();
      }
      if( (*v_muonFlv_recon)[1] * (*v_muonFlv_recon)[2] < 0)
      {
        TLorentzVector mumu4d = (*v_muon4d_recon)[1];
        mumu4d += (*v_muon4d_recon)[2];
        if( mumu4d.M() < M_mumu ) M_mumu = mumu4d.M();
      }
      //cout<<"M_mumu: "<<M_mumu<<endl;
      if(M_mumu < 15)
      {
	hInvDimu_Recon->Fill(M_mumu);
	if(!theSample.Contains("Data"))hInvDimu_Gen->Fill(Gen_ZGstar_mass);
      }
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
