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
   Float_t puW;
   Float_t GEN_weight_SM;
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
void LatinosTreeScript_76X_WgStar(Float_t luminosity,
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
  
  TH1D*   hInvDimu_Recon = new TH1D("hInvDimu_Recon","hInvDimu_Recon",10,4,14);
  TH1D*   hInvDimu_Gen   = new TH1D("hInvDimu_Gen","hInvDimu_Gen",10,4,14); 
  TH1D*   hNmuons   = new TH1D("hNmuons","hNmuons",5,0,5); 
  TH1D*   hTriMuOrder   = new TH1D("hTriMuOrder","hTriMuOrder",5,0,10); 
  TH1D*   hMu1_pt   = new TH1D("hMu1_pt","hMu1_pt",5,0,50); 
  TH1D*   hMu2_pt   = new TH1D("hMu2_pt","hMu2_pt",5,0,50); 
  TH1D*   hMu3_pt   = new TH1D("hMu3_pt","hMu3_pt",5,0,50); 
  
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
  
  if (runAtLxplus) filesPath = "~/eos/user/j/jlauwers/HWW2015/";
  else             filesPath = "/u/user/sangilpark/RunIIData/cernboxHWW76X/";
  //if (runAtOviedo) filesPath = "root://eoscms.cern.ch//eos/cms/store/user/yjcho/nTuple/";
  //else             filesPath = "root://eoscms.cern.ch//eos/cms/store/user/yjcho/nTuple/";
  TChain* tree = new TChain("latino", "latino");

  // l2sel
  if (theSample == "DataRun2015_C") {
  	tree->Add(filesPath + "22Jan_Run2015C_16Dec2015/WgStarsel__hadd/" + "latino_Run2015D_16Dec2015_SingleMuon.root");
  	tree->Add(filesPath + "22Jan_Run2015C_16Dec2015/WgStarsel__hadd/" + "latino_Run2015C_16Dec2015_SingleElectron.root");
  	tree->Add(filesPath + "22Jan_Run2015C_16Dec2015/WgStarsel__hadd/" + "latino_Run2015C_16Dec2015_DoubleMuon.root");
  	tree->Add(filesPath + "22Jan_Run2015C_16Dec2015/l2loose__hadd/" + "latino_Run2015C_16Dec2015_DoubleEG.root");
  	tree->Add(filesPath + "22Jan_Run2015C_16Dec2015/l2loose__hadd/" + "latino_Run2015C_16Dec2015_MuonEG.root");
  }
  if (theSample == "DataRun2015_D") {
  	tree->Add(filesPath + "22Jan_Run2015D_16Dec2015/WgStarsel__hadd/" + "latino_Run2015D_16Dec2015_SingleMuon.root");
  	tree->Add(filesPath + "22Jan_Run2015D_16Dec2015/WgStarsel__hadd/" + "latino_Run2015C_16Dec2015_SingleElectron.root");
  	tree->Add(filesPath + "22Jan_Run2015D_16Dec2015/WgStarsel__hadd/" + "latino_Run2015D_16Dec2015_DoubleMuon.root");
  	tree->Add(filesPath + "22Jan_Run2015D_16Dec2015/l2loose__hadd/" + "latino_Run2015D_16Dec2015_DoubleEG.root");
  	tree->Add(filesPath + "22Jan_Run2015D_16Dec2015/l2loose__hadd/" + "latino_Run2015D_16Dec2015_MuonEG.root");
  }
  else if (theSample == "WJetsLNu") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu.root");
  }
  else if (theSample == "WJetsLNu_HT") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu_HT100_200.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu_HT200_400.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu_HT400_600.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu_HT600_800.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu_HT800_1200.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu_HT1200_2500.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu_HT2500_inf.root");

  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WJetsToLNu_HT600_inf.root");
  }
  else if (theSample == "ggWWto2L") {
  	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluWWTo2L2Nu_MCFM__part0.root");
  }
  else if (theSample == "WWTo2L2Nu") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WWTo2L2Nu.root");
  }
  else if (theSample == "WZ") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WZ.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_WZJets.root");
  }
  else if (theSample == "WZ2Q") {
  	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_WZTo2L2Q__part0.root");
  }
  else if (theSample == "WZ3LNu") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MC__WgStarsel__hadd/" + "latino_WZTo3LNu.root");
  }
  else if (theSample == "ZZ") {
  	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZ.root");
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo2L2Nu__part0.root");
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ZZTo4L__part0.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_ZZ.root");
  }
  else if (theSample == "TTbar") {
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTJets__part0.root");
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TT__part0.root");
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_TTWJetsToLNu.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_TTTo2L2Nu.root");
  }
  else if (theSample == "TW") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_ST_tW_antitop.root");
  	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_ST_tW_top.root");
  }
  else if (theSample == "DY") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-10to50.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0000__part0.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0000__part1.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0000__part2.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0000__part3.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0000__part4.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0001__part0.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0001__part1.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0001__part2.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0001__part3.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0001__part4.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50_0002__part0.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_DYJetsToLL_M-50-LO.root");
  }
  else if (theSample == "DYtautau") {
  	//tree->Add("/afs/cern.ch/work/x/xjanssen/public/LatinoTrees/R53X_S1_V08_S2_V09_S3_V13/MoriondeffWPuWtriggW/TauTau_btagvar/latino_DYtt_19.5fb.root");
  	//tree->Add(filesPath + "latino_DYtt_19.5fb.root");
  }
  else if (theSample == "WgammaNoStar") {
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MC__WgStarsel__hadd/" + "latino_Wg500.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MC__WgStarsel__hadd/" + "latino_Wg_AMCNLOFXFX.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_Wg_MADGRAPHMLM.root");
  }
  else if (theSample == "WgammaStar") {
  }
  else if (theSample == "HWW125") { 
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_GluGluHToWWTo2L2NuAMCNLO_M125.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_GluGluHToWWTo2L2NuPowheg_M125.root");
  	
	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_GluGluHToTauTau_M125.root");
  	
	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_VBFHToTauTau_M125.root");
  
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_VBFHToWWTo2L2NuAMCNLO_M125.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_VBFHToWWTo2L2NuHerwigPS_M125.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_VBFHToWWTo2L2NuPowheg_M125.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_VBFHToWWTo2L2Nu_M125.root");
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_VBFHToWWTo2L2Nu_alternative_M125.root");
	
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_GluGluHToWWTo2L2Nu_M125.root");
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_HWminusJ_HToTauTau_M125.root");
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_HWminusJ_HToWW_M125.root");
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_HWplusJ_HToTauTau_M125.root");
	//tree->Add(filesPath + "21Oct_25ns_MC/mcwghtcount__MC__l2sel/" + "latino_HWplusJ_HToWW_M125.root");
  }
  else if (theSample == "Zgamma") { 
  	tree->Add(filesPath + "22Jan_25ns_mAODv2_MC/MCl2loose__hadd/" + "latino_Zg.root");
  }
  else {
  	return;
  }


  // Declaration of leaf types
  //----------------------------------------------------------------------------
  tree->SetBranchAddress("baseW",        &baseW);
  tree->SetBranchAddress("puW",      &puW);
  if(!theSample.Contains("Data"))
  {
    tree->SetBranchAddress("GEN_weight_SM",      &GEN_weight_SM);
  }
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
    	totalW = baseW * puW* GEN_weight_SM/abs(GEN_weight_SM)* luminosity;
    }

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
    hNmuons->Fill(Nmuon,totalW);
    if(Nmuon < 3)continue;
    //cout<<"Nmuon: "<<Nmuon<<endl;
    bool WGstarMuonPtCut(false);
    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[0].Pt() > Cuts.firstMu && (*v_muon4d_recon)[1].Pt() > Cuts.secndMu && (*v_muon4d_recon)[2].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(1,totalW);
      hMu1_pt->Fill((*v_muon4d_recon)[0].Pt(),totalW);
      hMu2_pt->Fill((*v_muon4d_recon)[1].Pt(),totalW);
      hMu3_pt->Fill((*v_muon4d_recon)[2].Pt(),totalW);
    }

    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[0].Pt() > Cuts.firstMu && (*v_muon4d_recon)[2].Pt() > Cuts.secndMu && (*v_muon4d_recon)[1].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(2,totalW);
      hMu1_pt->Fill((*v_muon4d_recon)[0].Pt(),totalW);
      hMu2_pt->Fill((*v_muon4d_recon)[2].Pt(),totalW);
      hMu3_pt->Fill((*v_muon4d_recon)[1].Pt(),totalW);
    }
    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[2].Pt() > Cuts.firstMu && (*v_muon4d_recon)[0].Pt() > Cuts.secndMu && (*v_muon4d_recon)[1].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(3,totalW);
      hMu1_pt->Fill((*v_muon4d_recon)[2].Pt(),totalW);
      hMu2_pt->Fill((*v_muon4d_recon)[0].Pt(),totalW);
      hMu3_pt->Fill((*v_muon4d_recon)[1].Pt(),totalW);
    }
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[1].Pt() )
    if( (*v_muon4d_recon)[2].Pt() > Cuts.firstMu && (*v_muon4d_recon)[1].Pt() > Cuts.secndMu  && (*v_muon4d_recon)[0].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(4,totalW);
      hMu1_pt->Fill((*v_muon4d_recon)[2].Pt(),totalW);
      hMu2_pt->Fill((*v_muon4d_recon)[1].Pt(),totalW);
      hMu3_pt->Fill((*v_muon4d_recon)[0].Pt(),totalW);
    }
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[2].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[1].Pt() > Cuts.firstMu && (*v_muon4d_recon)[2].Pt() > Cuts.secndMu && (*v_muon4d_recon)[0].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(5,totalW);
      hMu1_pt->Fill((*v_muon4d_recon)[1].Pt(),totalW);
      hMu2_pt->Fill((*v_muon4d_recon)[2].Pt(),totalW);
      hMu3_pt->Fill((*v_muon4d_recon)[0].Pt(),totalW);
    }
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[0].Pt() >=(*v_muon4d_recon)[2].Pt() )
    if( (*v_muon4d_recon)[1].Pt() >=(*v_muon4d_recon)[0].Pt() )
    if( (*v_muon4d_recon)[1].Pt() > Cuts.firstMu && (*v_muon4d_recon)[0].Pt() > Cuts.secndMu && (*v_muon4d_recon)[2].Pt() > Cuts.thirdMu)
    {
      WGstarMuonPtCut = true;
      hTriMuOrder->Fill(6,totalW);
      hMu1_pt->Fill((*v_muon4d_recon)[1].Pt(),totalW);
      hMu2_pt->Fill((*v_muon4d_recon)[0].Pt(),totalW);
      hMu3_pt->Fill((*v_muon4d_recon)[2].Pt(),totalW);
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
	hInvDimu_Recon->Fill(M_mumu, totalW);
	if(!theSample.Contains("Data"))hInvDimu_Gen->Fill(Gen_ZGstar_mass, totalW);
      }
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
