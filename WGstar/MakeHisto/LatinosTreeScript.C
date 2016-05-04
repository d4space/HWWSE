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
const Bool_t runAtLxplus = false;

const Double_t ZMASS = 91.1876;  // GeV
const Double_t JpsiMASS = 3.09691;  // GeV

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
   Float_t puW;
   //Float_t GEN_weight_SM;
   Float_t fakeW;
   Float_t channel;
   Float_t gen_mll;
   Float_t Gen_ZGstar_deltaR;
   Float_t Gen_ZGstar_mass;
   Float_t Gen_ZGstar_mu1_eta;
   Float_t Gen_ZGstar_mu1_phi;
   Float_t Gen_ZGstar_mu1_pt;
   Float_t Gen_ZGstar_mu2_eta;
   Float_t Gen_ZGstar_mu2_phi;
   Float_t Gen_ZGstar_mu2_pt;
   Float_t   Gen_ZGstar_MomId;
   Float_t   Gen_ZGstar_MomStatus;
   Float_t   Gen_ZGstar_MomInitStatus;

   // B-jet
   Float_t njet;
   Float_t nbjettche;
   Float_t nbjet;
   Float_t mpmet;
   Float_t mth;
   Float_t metPfType1;
   //Int_t   bveto_mu;
   Int_t   bveto_ip;


   vector<float>   *std_vector_lepton_flavour;
   vector<float>   *std_vector_lepton_pt;
   vector<float>   *std_vector_lepton_eta;
   vector<float>   *std_vector_lepton_phi;
   vector<float>   *std_vector_lepton_eleIdTight;
   vector<float>   *std_vector_lepton_photonIso;
   vector<float>   *std_vector_lepton_neutralHadronIso;
   vector<float>   *std_vector_lepton_sumPUPt;
   vector<float>   *std_vector_lepton_isMediumMuon;
   vector<float>   *std_vector_lepton_d0;
   vector<float>   *std_vector_lepton_dz;
   vector<float>   *std_vector_lepton_isLooseLepton;
   vector<float>   *std_vector_lepton_isTightLepton;
   vector<float>   *std_vector_lepton_isWgsLepton;

   vector<float>   *std_vector_leptonGen_pt;
   vector<float>   *std_vector_leptonGen_pid;
   vector<float>   *std_vector_leptonGen_status;

//------------------------------------------------------------------------------
// LatinosTreeScript
//------------------------------------------------------------------------------
void LatinosTreeScript(Float_t luminosity,
		Int_t   jetChannel,
		TString flavorChannel,
		TString theSample,
		TString  TypeStudy="Nominal",
		Bool_t  verbose=true)
{
  TH1::SetDefaultSumw2();

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

  enum TYPeSTUDY {Nominal, GenStudy};
  int SelectedStudy;
  cout<<"TypeStudy: "<<TypeStudy<<endl;
  if      (TypeStudy == "GenStudy") SelectedStudy = GenStudy;
  else if (TypeStudy == "Nominal")  SelectedStudy = Nominal;
  else                              SelectedStudy = Nominal;

  bool MuonPtCut(false);

  cout<<"Study Type is "<<SelectedStudy<<endl;
 
  // OutPut 
  //-------------------------------------------------
  TString path = Form("rootfiles/%djet/%s/", jetChannel, flavorChannel.Data());
  //TString path = Form("rootfiles_WgIso_mll_110_met25pt30103/%djet/%s/", jetChannel, flavorChannel.Data());
  gSystem->mkdir(path, kTRUE);
  
  TFile* output = new TFile(path + theSample + ".root", "recreate");
  TString NameFout=path + theSample +".txt";
  ofstream Fout(NameFout);


  // Histograms
  //----------------------------------------------------------------------------
  
  TH1D*   hCutFlow  = new TH1D("hCutFlow","hCutFlow",20,0,20);
  TH1D*   hGen_mll   = new TH1D("hGen_mll","hGen_mll",55,0,110);
  TH1D*   hInvDimu_Recon = new TH1D("hInvDimu_Recon","hInvDimu_Recon",55,0,110);
  TH1D*   hInvDimu_Recon_SmallWindow = new TH1D("hInvDimu_Recon_SmallWindow","hInvDimu_Recon_SmallWindow",24,0,12);
  TH1D*   hInvDimu_Gen   = new TH1D("hInvDimu_Gen","hInvDimu_Gen",100,0,20); 
  TH1D*   hInvDimu_Gen_All=new TH1D("hInvDimu_Gen_All","hInvDimu_Gen_All",100,0,20); 
  TH1D*   hZGstar_Gen_InvDimu=new TH1D("hZGstar_Gen_InvDimu","hZGstar_Gen_InvDimu",50,0,10); 
  TH1D*   hGen_mu1_pt=new TH1D("hGen_mu1_pt","hGen_mu1_pt",100,0,50); 
  TH1D*   hGen_ZGstar_mu1_pt=new TH1D("hGen_ZGstar_mu1_pt","hGen_ZGstar_mu1_pt",100,0,50); 
  TH1D*   hGen_ZGstar_mu2_pt=new TH1D("hGen_ZGstar_mu2_pt","hGen_ZGstar_mu2_pt",100,0,50); 
  TH1D*   hZGstar_Gen_MomId=new TH1D("hZGstar_Gen_MomId","hZGstar_Gen_MomId",100,0,100); 
  TH1D*   hZGstar_Gen_MomStatus=new TH1D("hZGstar_Gen_MomStatus","hZGstar_Gen_MomStatus",100,0,100); 
  TH1D*   hZGstar_Gen_MomInitStatus=new TH1D("hZGstar_Gen_MomInitStatus","hZGstar_Gen_MomInitStatus",100,0,100); 
  TH1D*   hNmuons   = new TH1D("hNmuons","hNmuons",5,0,5); 
  TH1D*   hRecNmuons_forGenDiMu   = new TH1D("hRecNmuons_forGenDiMu","hRecNmuons_forGenDiMu",5,0,5); 
  TH1D*   hTriMuOrder   = new TH1D("hTriMuOrder","hTriMuOrder",5,0,10); 
  TH1D*   hMu1_pt   = new TH1D("hMu1_pt","hMu1_pt",5,0,50); 
  TH1D*   hMu2_pt   = new TH1D("hMu2_pt","hMu2_pt",5,0,50); 
  TH1D*   hMu3_pt   = new TH1D("hMu3_pt","hMu3_pt",5,0,50); 
  
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
  
  
  if (runAtLxplus) filesPath = "~/eos_cernbox/user/r/rebeca/HWW2015/";
  else             filesPath = "dcap://cluster142.knu.ac.kr//pnfs/knu.ac.kr/data/cms/store/user/spak/CernBox_Rebeca/";
  //else             filesPath = "/u/user/sangilpark/RunIIData/cernboxHWW76X/";
  //if (runAtOviedo) filesPath = "root://eoscms.cern.ch//eos/cms/store/user/yjcho/nTuple/";
  //else             filesPath = "root://eoscms.cern.ch//eos/cms/store/user/yjcho/nTuple/";
  TChain* tree = new TChain("latino", "latino");
  
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
 
  //----------------------------------------------------------------------------
  // Input files End
  //----------------------------------------------------------------------------


  // Declaration of leaf types
  //----------------------------------------------------------------------------
  tree->SetBranchAddress("baseW",        &baseW);
  tree->SetBranchAddress("puW",      &puW);
  tree->SetBranchAddress("channel",      &channel);
  //tree->SetBranchAddress("Gen_ZGstar_deltaR",      &Gen_ZGstar_deltaR);

  tree->SetBranchAddress("Gen_ZGstar_mass",        &Gen_ZGstar_mass);
  if(theSample == "WgammaNoStar"){
  tree->SetBranchAddress("Gen_ZGstar_MomId",       &Gen_ZGstar_MomId);
  tree->SetBranchAddress("Gen_ZGstar_MomStatus",   &Gen_ZGstar_MomStatus);
  tree->SetBranchAddress("Gen_ZGstar_MomInitStatus",&Gen_ZGstar_MomInitStatus);
  }
  if(!theSample.Contains("Data")){ 
    tree->SetBranchAddress("Gen_ZGstar_mu1_eta",     &Gen_ZGstar_mu1_eta);
    tree->SetBranchAddress("Gen_ZGstar_mu1_phi",     &Gen_ZGstar_mu1_phi);
    tree->SetBranchAddress("Gen_ZGstar_mu1_pt",      &Gen_ZGstar_mu1_pt);
    tree->SetBranchAddress("Gen_ZGstar_mu2_eta",     &Gen_ZGstar_mu2_eta);
    tree->SetBranchAddress("Gen_ZGstar_mu2_phi",     &Gen_ZGstar_mu2_phi);
    tree->SetBranchAddress("Gen_ZGstar_mu2_pt",      &Gen_ZGstar_mu2_pt);
    tree->SetBranchAddress("std_vector_leptonGen_pt",&std_vector_leptonGen_pt);
    tree->SetBranchAddress("std_vector_leptonGen_pid",&std_vector_leptonGen_pid);
    tree->SetBranchAddress("std_vector_leptonGen_status",&std_vector_leptonGen_status);
  }
  tree->SetBranchAddress("std_vector_lepton_flavour", &std_vector_lepton_flavour);
  tree->SetBranchAddress("std_vector_lepton_pt", &std_vector_lepton_pt);
  tree->SetBranchAddress("std_vector_lepton_phi",&std_vector_lepton_phi);
  tree->SetBranchAddress("std_vector_lepton_eta",&std_vector_lepton_eta);
  tree->SetBranchAddress("std_vector_lepton_eleIdTight",&std_vector_lepton_eleIdTight);
  tree->SetBranchAddress("std_vector_lepton_photonIso", &std_vector_lepton_photonIso);
  tree->SetBranchAddress("std_vector_lepton_neutralHadronIso", &std_vector_lepton_neutralHadronIso);
  tree->SetBranchAddress("std_vector_lepton_sumPUPt",          &std_vector_lepton_sumPUPt);
  tree->SetBranchAddress("std_vector_lepton_isMediumMuon",    &std_vector_lepton_isMediumMuon);
  tree->SetBranchAddress("std_vector_lepton_d0",    &std_vector_lepton_d0);
  tree->SetBranchAddress("std_vector_lepton_dz",    &std_vector_lepton_dz);
  tree->SetBranchAddress("njet",         &njet);
  tree->SetBranchAddress("nbjettche",    &nbjettche);
  tree->SetBranchAddress("nbjet",        &nbjet);
  tree->SetBranchAddress("mpmet",        &mpmet);
  tree->SetBranchAddress("metPfType1",          &metPfType1);
  //tree->SetBranchAddress("bveto_mu",        &bveto_mu);
  tree->SetBranchAddress("bveto_ip",        &bveto_ip);
  if(theSample.Contains("WJetsFakes"))
    tree->SetBranchAddress("fakeW", &fakeW);

  if( SelectedStudy== GenStudy){
    tree->SetBranchAddress("gen_mll",          &gen_mll);
  }else{
    tree->SetBranchAddress("mth",          &mth);
    tree->SetBranchAddress("std_vector_lepton_isLooseLepton",    &std_vector_lepton_isLooseLepton);
    tree->SetBranchAddress("std_vector_lepton_isTightLepton",    &std_vector_lepton_isTightLepton);
    tree->SetBranchAddress("std_vector_lepton_isWgsLepton",    &std_vector_lepton_isWgsLepton);
  }

  
  
  //if (!theSample.Contains("WJetsFakes") && !theSample.Contains("Data"))
  //	tree->SetBranchAddress("puW", &puW);
  
  
  
  //----------------------------------------------------------------------------
  // Loop
  //----------------------------------------------------------------------------
  std::vector<TLorentzVector> *vMuon_4d_rec;
  std::vector<TLorentzVector> *vMuon_4d_gen;
  std::vector<int> *vMuon_Flv_rec;
  std::vector<int> *vMuon_isWgsLepton_rec;
  std::vector<int> *vMuon_isTightLepton_rec;
  std::vector<int> *vMuon_isLooseLepton_rec;
  std::vector<int> *vMuon_Flv_gen;

  vMuon_4d_rec  = new std::vector<TLorentzVector>;
  vMuon_4d_gen  = new std::vector<TLorentzVector>;
  vMuon_Flv_rec = new std::vector<int>;
  vMuon_isWgsLepton_rec = new std::vector<int>;
  vMuon_isTightLepton_rec = new std::vector<int>;
  vMuon_isLooseLepton_rec = new std::vector<int>;
  vMuon_Flv_gen   = new std::vector<int>;

  std::vector<TLorentzVector> *vElec_4d_rec;
  std::vector<TLorentzVector> *vElec_4d_gen;
  std::vector<int> *vElec_Flv_rec;
  std::vector<int> *vElec_isWgsLepton_rec;
  std::vector<int> *vElec_isTightLepton_rec;
  std::vector<int> *vElec_isLooseLepton_rec;
  std::vector<int> *vElec_Flv_gen;

  vElec_4d_rec  = new std::vector<TLorentzVector>;
  vElec_4d_gen  = new std::vector<TLorentzVector>;
  vElec_Flv_rec = new std::vector<int>;
  vElec_isWgsLepton_rec = new std::vector<int>;
  vElec_isTightLepton_rec = new std::vector<int>;
  vElec_isLooseLepton_rec = new std::vector<int>;
  vElec_Flv_gen   = new std::vector<int>;

  int iLept, Nmuon;
  double lepton_pt, lepton_eta, lepton_phi, lepton_flv;
  double lepton_isWgsLepton, lepton_isTightLepton, lepton_isLooseLepton;
  
  TLorentzVector muon4d;
  TLorentzVector electron4d;
  int MuonPtOrder;

  //Cuts=======================
  struct Cuts{
    const double firstMu=30;
    const double secndMu=7;
    const double thirdMu=5;
  }Cuts;

  int TotNtry=tree->GetEntries();
  //TotNtry=500;
  cout<<"Total number of event to process: "<<TotNtry<<endl;

  int Nzgstar(0);
  for (int ievent=0; ievent<TotNtry; ievent++) {
    if(ievent%100000 ==0) cout<<"Processing "<<ievent<<"th event"<<endl; 

    // initialize
    vMuon_4d_rec->clear();
    vMuon_4d_gen->clear();
    vMuon_Flv_rec->clear();
    vMuon_isWgsLepton_rec->clear();
    vMuon_isTightLepton_rec->clear();
    vMuon_isLooseLepton_rec->clear();
    vMuon_Flv_gen->clear();

    vElec_4d_rec->clear();
    vElec_4d_gen->clear();
    vElec_Flv_rec->clear();
    vElec_isWgsLepton_rec->clear();
    vElec_isTightLepton_rec->clear();
    vElec_isLooseLepton_rec->clear();
    vElec_Flv_gen->clear();

    iLept=0;
    Nmuon=0;
    MuonPtOrder=0;
    //vMuon_4d_rec=0;
    // dump variable
    tree->GetEntry(ievent);
    //cout<<" baseW: "<<baseW<<"\t"<<"channel: "<<channel<<endl;
    //cout<<"Lepton flavor:          pt"<<endl;
    //for(int iLept(0); iLept<std_vector_lepton_flavour->size();iLept++)
    //{
    //}

    // Weight Calc.
    //
    //
    totalW      = -999;

    if (theSample.Contains("Data"))
    {
    	//totalW = baseW;
    	totalW = 1.0;
    }
    else if (theSample.Contains("WZ") || theSample.Contains("HWW125"))
    {
    	totalW = baseW * puW* luminosity;
    	//totalW = fakeW;
    }
    else
    {
    	//efficiencyW = puW * effW * triggW;
    
    	//totalW = (1 + 0.6 * (dataset >= 82 && dataset <= 84)) * baseW * efficiencyW * luminosity;
    	totalW = baseW * puW* luminosity;
    	//totalW = baseW * puW* GEN_weight_SM/abs(GEN_weight_SM)* luminosity;
    }
    while((*std_vector_lepton_flavour)[iLept] >-9999)
    {
      lepton_flv  = (*std_vector_lepton_flavour)[iLept];
      lepton_pt   = (*std_vector_lepton_pt)[iLept];
      lepton_eta  = (*std_vector_lepton_eta)[iLept];
      lepton_phi  = (*std_vector_lepton_phi)[iLept];
      if(TypeStudy == "Nominal")
      {
        lepton_isWgsLepton  = (*std_vector_lepton_isWgsLepton)[iLept];
        lepton_isTightLepton  = (*std_vector_lepton_isTightLepton)[iLept];
        lepton_isLooseLepton  = (*std_vector_lepton_isLooseLepton)[iLept];
      }
      //cout<<iLept<<"\t"<<lepton_flv<<
      //  "\t"<<lepton_pt<<"\t"<<lepton_eta<<"\t"<<lepton_phi<<" isWgsLepton:"<<lepton_isWgsLepton<<" isTightLepton: "<<lepton_isTightLepton<<endl;
      if(fabs(lepton_flv) ==13)
      {
        muon4d.SetPtEtaPhiM(lepton_pt,lepton_eta,lepton_phi,M_Muon);
        vMuon_4d_rec->push_back(muon4d);
        vMuon_Flv_rec->push_back(lepton_flv);
	if(TypeStudy == "Nominal")
	{
          vMuon_isWgsLepton_rec->push_back(lepton_isWgsLepton);
          vMuon_isTightLepton_rec->push_back(lepton_isTightLepton);
          vMuon_isLooseLepton_rec->push_back(lepton_isLooseLepton);
	}
      }
      if(fabs(lepton_flv) ==11)
      {
        electron4d.SetPtEtaPhiM(lepton_pt,lepton_eta,lepton_phi,M_Muon);
        vElec_4d_rec->push_back(electron4d);
        vElec_Flv_rec->push_back(lepton_flv);
	if(TypeStudy == "Nominal")
	{
          vElec_isWgsLepton_rec->push_back(lepton_isWgsLepton);
          vElec_isTightLepton_rec->push_back(lepton_isTightLepton);
          vElec_isLooseLepton_rec->push_back(lepton_isLooseLepton);
	}
      }
      iLept++;

    }

    Nmuon = vMuon_4d_rec->size();

    // Fill gen info
    // --------------------------------
    if(!theSample.Contains("Data"))
    {
      hGen_mll->Fill(gen_mll);
      hInvDimu_Gen_All->Fill(Gen_ZGstar_mass);
      // g* case
      if(Gen_ZGstar_mass > 0)
      {
	// g* decays to diMuon
        if(Gen_ZGstar_mu1_pt > 0){
	  // W->muon nu case
	  //if( abs( (*std_vector_leptonGen_pid)[0] ) == 13){
	    hGen_mu1_pt->Fill( (*std_vector_leptonGen_pt)[0], totalW);
	    hGen_ZGstar_mu1_pt->Fill(Gen_ZGstar_mu1_pt,totalW);
	    hGen_ZGstar_mu2_pt->Fill(Gen_ZGstar_mu2_pt,totalW);
	    //if((*std_vector_leptonGen_pt)[0] > 10 && Gen_ZGstar_mu1_pt > 5 && Gen_ZGstar_mu2_pt >5)
	    if(Gen_ZGstar_mu1_pt > 5 && Gen_ZGstar_mu2_pt >5){
	      hZGstar_Gen_InvDimu->Fill(Gen_ZGstar_mass, totalW);
              hRecNmuons_forGenDiMu->Fill(Nmuon,totalW);
	    }
	  //}
	}
        if(theSample == "WgammaNoStar")if(Gen_ZGstar_mass > 0){
  	  Nzgstar++;
          //cout<<"Gen_ZGstar_mass: "<<Gen_ZGstar_mass<<endl;
          //cout<<"Gen_ZGstar_MomId: "<<Gen_ZGstar_MomId<<endl;
          //cout<<"Gen_ZGstar_MomStatus: "<<Gen_ZGstar_MomStatus<<endl;
          //cout<<"Gen_ZGstar_MomInitStatus: "<<Gen_ZGstar_MomInitStatus<<endl;
	  hZGstar_Gen_MomId->Fill(Gen_ZGstar_MomId);
	  hZGstar_Gen_MomStatus->Fill(Gen_ZGstar_MomStatus);
	  hZGstar_Gen_MomInitStatus->Fill(Gen_ZGstar_MomInitStatus);
        }
      }
    }

    hNmuons->Fill(Nmuon,totalW);

    // Cuts
    // --------------------------------------------
    if(Nmuon < 3)continue;
    hCutFlow->Fill(1.,totalW);

    // Wg* veto for Wgamma sample
    if(theSample == "WgammaNoStar")
    {
      if(Gen_ZGstar_mass>0 && Gen_ZGstar_MomId == 22) continue;
    }
    hCutFlow->Fill(2.,totalW);

    //cout<<"Nmuon: "<<Nmuon<<endl;
    MuonPtCut=false;
    // b-jet cut
    //cout<<"nbjettche: "<<nbjettche<<"  bveto_ip: "<<bveto_ip<<" njet: "<<njet<<" mpmet: "<<mpmet<<" mth: "<<mth<<"  metPfType1: "<<metPfType1<<endl;
    //if(nbjettche !=0 )continue;
    hCutFlow->Fill(3.,totalW);
    //if(bveto_mu !=1 )continue;
    //if(bveto_ip !=1 )continue;
    if(njet > 1 )continue;
    hCutFlow->Fill(4.,totalW);

    //if(mpmet < 20 )continue;
    if(metPfType1 < 25 )continue;
    hCutFlow->Fill(5.,totalW);
    //if(mth < 25 )continue;

    if( (*vMuon_4d_rec)[0].Pt() >=(*vMuon_4d_rec)[1].Pt() )
    if( (*vMuon_4d_rec)[1].Pt() >=(*vMuon_4d_rec)[2].Pt() )
    if( (*vMuon_4d_rec)[0].Pt() > Cuts.firstMu && (*vMuon_4d_rec)[1].Pt() > Cuts.secndMu && (*vMuon_4d_rec)[2].Pt() > Cuts.thirdMu)
    {
      MuonPtCut = true;
      hTriMuOrder->Fill(1,totalW);
      hMu1_pt->Fill((*vMuon_4d_rec)[0].Pt(),totalW);
      hMu2_pt->Fill((*vMuon_4d_rec)[1].Pt(),totalW);
      hMu3_pt->Fill((*vMuon_4d_rec)[2].Pt(),totalW);
    }

    if( (*vMuon_4d_rec)[0].Pt() >=(*vMuon_4d_rec)[1].Pt() )
    if( (*vMuon_4d_rec)[2].Pt() >=(*vMuon_4d_rec)[1].Pt() )
    if( (*vMuon_4d_rec)[0].Pt() >=(*vMuon_4d_rec)[2].Pt() )
    if( (*vMuon_4d_rec)[0].Pt() > Cuts.firstMu && (*vMuon_4d_rec)[2].Pt() > Cuts.secndMu && (*vMuon_4d_rec)[1].Pt() > Cuts.thirdMu)
    {
      MuonPtCut = true;
      hTriMuOrder->Fill(2,totalW);
      hMu1_pt->Fill((*vMuon_4d_rec)[0].Pt(),totalW);
      hMu2_pt->Fill((*vMuon_4d_rec)[2].Pt(),totalW);
      hMu3_pt->Fill((*vMuon_4d_rec)[1].Pt(),totalW);
    }
    if( (*vMuon_4d_rec)[0].Pt() >=(*vMuon_4d_rec)[1].Pt() )
    if( (*vMuon_4d_rec)[2].Pt() >=(*vMuon_4d_rec)[1].Pt() )
    if( (*vMuon_4d_rec)[2].Pt() >=(*vMuon_4d_rec)[0].Pt() )
    if( (*vMuon_4d_rec)[2].Pt() > Cuts.firstMu && (*vMuon_4d_rec)[0].Pt() > Cuts.secndMu && (*vMuon_4d_rec)[1].Pt() > Cuts.thirdMu)
    {
      MuonPtCut = true;
      hTriMuOrder->Fill(3,totalW);
      hMu1_pt->Fill((*vMuon_4d_rec)[2].Pt(),totalW);
      hMu2_pt->Fill((*vMuon_4d_rec)[0].Pt(),totalW);
      hMu3_pt->Fill((*vMuon_4d_rec)[1].Pt(),totalW);
    }
    if( (*vMuon_4d_rec)[1].Pt() >=(*vMuon_4d_rec)[0].Pt() )
    if( (*vMuon_4d_rec)[2].Pt() >=(*vMuon_4d_rec)[0].Pt() )
    if( (*vMuon_4d_rec)[2].Pt() >=(*vMuon_4d_rec)[1].Pt() )
    if( (*vMuon_4d_rec)[2].Pt() > Cuts.firstMu && (*vMuon_4d_rec)[1].Pt() > Cuts.secndMu  && (*vMuon_4d_rec)[0].Pt() > Cuts.thirdMu)
    {
      MuonPtCut = true;
      hTriMuOrder->Fill(4,totalW);
      hMu1_pt->Fill((*vMuon_4d_rec)[2].Pt(),totalW);
      hMu2_pt->Fill((*vMuon_4d_rec)[1].Pt(),totalW);
      hMu3_pt->Fill((*vMuon_4d_rec)[0].Pt(),totalW);
    }
    if( (*vMuon_4d_rec)[1].Pt() >=(*vMuon_4d_rec)[0].Pt() )
    if( (*vMuon_4d_rec)[2].Pt() >=(*vMuon_4d_rec)[0].Pt() )
    if( (*vMuon_4d_rec)[1].Pt() >=(*vMuon_4d_rec)[2].Pt() )
    if( (*vMuon_4d_rec)[1].Pt() > Cuts.firstMu && (*vMuon_4d_rec)[2].Pt() > Cuts.secndMu && (*vMuon_4d_rec)[0].Pt() > Cuts.thirdMu)
    {
      MuonPtCut = true;
      hTriMuOrder->Fill(5,totalW);
      hMu1_pt->Fill((*vMuon_4d_rec)[1].Pt(),totalW);
      hMu2_pt->Fill((*vMuon_4d_rec)[2].Pt(),totalW);
      hMu3_pt->Fill((*vMuon_4d_rec)[0].Pt(),totalW);
    }
    if( (*vMuon_4d_rec)[1].Pt() >=(*vMuon_4d_rec)[2].Pt() )
    if( (*vMuon_4d_rec)[0].Pt() >=(*vMuon_4d_rec)[2].Pt() )
    if( (*vMuon_4d_rec)[1].Pt() >=(*vMuon_4d_rec)[0].Pt() )
    if( (*vMuon_4d_rec)[1].Pt() > Cuts.firstMu && (*vMuon_4d_rec)[0].Pt() > Cuts.secndMu && (*vMuon_4d_rec)[2].Pt() > Cuts.thirdMu)
    {
      MuonPtCut = true;
      hTriMuOrder->Fill(6,totalW);
      hMu1_pt->Fill((*vMuon_4d_rec)[1].Pt(),totalW);
      hMu2_pt->Fill((*vMuon_4d_rec)[0].Pt(),totalW);
      hMu3_pt->Fill((*vMuon_4d_rec)[2].Pt(),totalW);
    }


    int diMuonCombi(-1);
    if( Nmuon >= 3 && MuonPtCut){
    hCutFlow->Fill(6.,totalW);
      //cout<<"WG* Sample!"<<endl;
      double mMini_mumu(1000000000.);
      if( (*vMuon_Flv_rec)[0] * (*vMuon_Flv_rec)[1] < 0)
      {
        TLorentzVector mumu4d = (*vMuon_4d_rec)[0];
        mumu4d += (*vMuon_4d_rec)[1];
        mMini_mumu = mumu4d.M();
	diMuonCombi=0;
      }
      if( (*vMuon_Flv_rec)[0] * (*vMuon_Flv_rec)[2] < 0)
      {
        TLorentzVector mumu4d = (*vMuon_4d_rec)[0];
        mumu4d += (*vMuon_4d_rec)[2];
        if( mumu4d.M() < mMini_mumu ){
	  mMini_mumu = mumu4d.M();
	  diMuonCombi=1;
	}
      }
      if( (*vMuon_Flv_rec)[1] * (*vMuon_Flv_rec)[2] < 0)
      {
        TLorentzVector mumu4d = (*vMuon_4d_rec)[1];
        mumu4d += (*vMuon_4d_rec)[2];
        if( mumu4d.M() < mMini_mumu ){
	  mMini_mumu = mumu4d.M();
	  diMuonCombi=2;
	}
      }
      if( diMuonCombi== -1 ) continue;

      if( abs(mMini_mumu - JpsiMASS) < 0.1 ) continue;
      // id check
      switch( diMuonCombi)
      {
	case 0:
	  {
	    if( ((*vMuon_isTightLepton_rec)[2] != 1) ) continue;
            if( ((*vMuon_isWgsLepton_rec)[0] != 1) ) continue;
            if( ((*vMuon_isWgsLepton_rec)[1] != 1) ) continue;
	    break;
	  }
	case 1:
	  {
	    if( ((*vMuon_isTightLepton_rec)[1] != 1) ) continue;
            if( ((*vMuon_isWgsLepton_rec)[0] != 1) ) continue;
            if( ((*vMuon_isWgsLepton_rec)[2] != 1) ) continue;
	    break;
	  }
	case 2:
	  {
	    if( ((*vMuon_isTightLepton_rec)[0] != 1) ) continue;
            if( ((*vMuon_isWgsLepton_rec)[1] != 1) ) continue;
            if( ((*vMuon_isWgsLepton_rec)[2] != 1) ) continue;
	    break;
	  }
	default:
	  continue;
      }
      //cout<<"mMini_mumu: "<<mMini_mumu<<endl;
      //if(mMini_mumu < 15)
      //{
	hInvDimu_Recon->Fill(mMini_mumu, totalW);
	hInvDimu_Recon_SmallWindow->Fill(mMini_mumu, totalW);
	if(!theSample.Contains("Data"))hInvDimu_Gen->Fill(Gen_ZGstar_mass, totalW);
      //}
    }
  }
  //cout<<"Nzgstar/Ntot: "<<float(Nzgstar)/float(TotNtry)<<endl;

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
