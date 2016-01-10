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

   Float_t         metGeneta;
   Float_t         metGenphi;
   Float_t         metGenpt;
   Float_t         metLHEeta;
   Float_t         metLHEphi;
   Float_t         metLHEpt;
   Float_t         metPfNoHf;
   Float_t         metPfProj;
   Float_t         metPfRaw;
   Float_t         metPfRawPhi;
   Float_t         metPfRawSumEt;
   Float_t         metPfType1;
   Float_t         metPfType1ElecDn;
   Float_t         metPfType1ElecUp;
   Float_t         metPfType1JetDn;
   Float_t         metPfType1JetUp;
   Float_t         metPfType1MuonDn;
   Float_t         metPfType1MuonUp;
   Float_t         metPfType1Phi;
   Float_t         metPfType1SumEt;
   Float_t         metPuppi;
   Float_t         metTtrk;
   Float_t         metTtrkPhi;

//------------------------------------------------------------------------------
// LatinosTreeScript
//------------------------------------------------------------------------------
void LatinosTreeScript(Float_t luminosity,
		Int_t   jetChannel,
		TString flavorChannel,
		TString theSample,
		Bool_t  verbose)
{
	//TH1::SetDefaultSumw2();

	TString path = Form("rootfiles/%djet/%s/", jetChannel, flavorChannel.Data());

	gSystem->mkdir(path, kTRUE);

	TFile* output = new TFile(path + theSample + ".root", "recreate");
	//TString NameFout=path + theSample +".txt";
	//ofstream Fout(NameFout);

        TH1D* h_ = new TH1D("h_","h_",20,0,120);
        TH1D* h_metPfType1 = new TH1D("h_metPfType1","h_metPfType1",20,0,120);
        TH1D* h_metPfType1ElecDn = new TH1D("h_metPfType1ElecDn","h_metPfType1ElecDn",20,0,120);
        TH1D* h_metPfType1ElecUp = new TH1D("h_metPfType1ElecUp","h_metPfType1ElecUp",20,0,120);
        TH1D* h_metPfType1MuonDn = new TH1D("h_metPfType1MuonDn","h_metPfType1MuonDn",20,0,120);
        TH1D* h_metPfType1MuonUp = new TH1D("h_metPfType1MuonUp","h_metPfType1MuonUp",20,0,120);
        TH1D* h_metPfType1JetDn = new TH1D("h_metPfType1JetDn","h_metPfType1JetDn",20,0,120);
        TH1D* h_metPfType1JetUp = new TH1D("h_metPfType1JetUp","h_metPfType1JetUp",20,0,120);

	// Histograms
	//----------------------------------------------------------------------------
//	for (UInt_t i=0; i<nLevels; i++) {
//		hPtLepton1      [i] = new TH1F("hPtLepton1"       + sLevel[i], "", 200, 0, 200);
//		hPtLepton2      [i] = new TH1F("hPtLepton2"       + sLevel[i], "", 200, 0, 200);
//	}
//

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

	if (theSample == "Test") {
		tree->Add("./latino_stepB_numEvent100.root");
	}
	else if (theSample == "DataRun2015_D") {
		tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part0.root");
		tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part1.root");
		tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part2.root");
		tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part3.root");
		tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel" + "latino_Run2015D_05Oct2015_SingleMuon_0000__part4.root");
		tree->Add(filesPath + "21Oct_Run2015D_05Oct2015/l2sel" + "latino_Run2015D_05Oct2015_SingleMuon_0001__part0.root");
	}
	else if (theSample == "WJetsFakes_Total") {
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part0.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part1.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part2.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part3.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part4.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WJetsToLNu__part5.root");
	}
	else if (theSample == "ggWWto2L") {
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluWWTo2L2Nu_MCFM__part0.root");
	}
	else if (theSample == "WWTo2L2Nu") {
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WWTo2L2Nu.root");
	}
	else if (theSample == "WZ") {
		//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZJets__part0.root");
		//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZJets__part1.root");
		//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part0.root");
		//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part1.root");
		//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part2.root");
		//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part3.root");
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
	}
	else if (theSample == "TTbar") {
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTTo2L2Nu__part0.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTTo2L2Nu__part1.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTTo2L2Nu__part2.root");
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
	}
	else if (theSample == "DYtautau") {
		//tree->Add("/afs/cern.ch/work/x/xjanssen/public/LatinoTrees/R53X_S1_V08_S2_V09_S3_V13/MoriondeffWPuWtriggW/TauTau_btagvar/latino_DYtt_19.5fb.root");
		//tree->Add(filesPath + "latino_DYtt_19.5fb.root");
	}
	else if (theSample == "WgammaNoStar") {
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_Wg.root");
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
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToTauTau_M125.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_VBFHToTauTau_M125.root");
		tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_VBFHToWWTo2L2NuAMCNLO_M125.root");
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
        tree->SetBranchAddress("std_vector_lepton_flavour", &std_vector_lepton_flavour);
        tree->SetBranchAddress("std_vector_lepton_pt", &std_vector_lepton_pt);
        tree->SetBranchAddress("std_vector_lepton_phi",&std_vector_lepton_phi);
        tree->SetBranchAddress("std_vector_lepton_eta",&std_vector_lepton_eta);
	tree->SetBranchAddress("metPfType1",      &metPfType1);
	tree->SetBranchAddress("metPfType1ElecDn",&metPfType1ElecDn);
	tree->SetBranchAddress("metPfType1ElecUp",&metPfType1ElecUp);
	tree->SetBranchAddress("metPfType1JetDn" ,&metPfType1JetDn);
	tree->SetBranchAddress("metPfType1JetUp" ,&metPfType1JetUp);
	tree->SetBranchAddress("metPfType1MuonDn",&metPfType1MuonDn);
	tree->SetBranchAddress("metPfType1MuonUp",&metPfType1MuonUp);

	//if (theSample.Contains("WJetsFakes"))
//		tree->SetBranchAddress("fakeW", &fakeW);

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
	  h_metPfType1->Fill(metPfType1);
	  h_metPfType1ElecDn->Fill(metPfType1ElecDn);
	  h_metPfType1ElecUp->Fill(metPfType1ElecUp);
	  h_metPfType1MuonDn->Fill(metPfType1MuonDn);
	  h_metPfType1MuonUp->Fill(metPfType1MuonUp);
	  h_metPfType1JetDn->Fill(metPfType1JetDn);
	  h_metPfType1JetUp->Fill(metPfType1JetUp);
	  //cout<<" baseW: "<<baseW<<"\t"<<"channel: "<<channel<<endl;
	  //cout<<"Lepton flavor:          pt"<<endl;
	  //for(int iLept(0); iLept<std_vector_lepton_flavour->size();iLept++)
	  //{
	  //}
	  /************

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

	************/
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
