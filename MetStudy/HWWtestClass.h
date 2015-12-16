//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Dec 16 15:37:15 2015 by ROOT version 6.04/12
// from TChain latino/
//////////////////////////////////////////////////////////

#ifndef HWWtestClass_h
#define HWWtestClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

class HWWtestClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         baseW;
   Float_t         chSumEt;
   Float_t         channel;
   Float_t         chmet;
   Float_t         chmetphi;
   Float_t         dataset;
   Float_t         effW;
   Float_t         evt;
   Float_t         fakeW;
   Float_t         hardbjpb;
   Float_t         hardcmva;
   Float_t         hardcsvv2ivf;
   Float_t         hardpfcsv;
   Float_t         hardssvhb;
   Float_t         hardssvhe;
   Float_t         hardtche;
   Float_t         higgsGeneta;
   Float_t         higgsGenmass;
   Float_t         higgsGenphi;
   Float_t         higgsGenpt;
   Float_t         higgsLHEeta;
   Float_t         higgsLHEm;
   Float_t         higgsLHEphi;
   Float_t         higgsLHEpt;
   Float_t         imet;
   Float_t         jetRho;
   Float_t         jetcmva1;
   Float_t         jetcmva2;
   Float_t         jetcsvv2ivf1;
   Float_t         jetcsvv2ivf2;
   Float_t         jetpfcsv1;
   Float_t         jetpfcsv2;
   Float_t         jetssvhb1;
   Float_t         jetssvhb2;
   Float_t         jetssvhe1;
   Float_t         jetssvhe2;
   Float_t         kfW;
   Float_t         lumi;
   Float_t         mctruth;
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
   Float_t         mllg;
   Float_t         mllgid;
   Float_t         mpmet;
   Float_t         nPhos;
   Float_t         nbjet;
   Float_t         nbjettche;
   Float_t         nextra;
   Float_t         njet;
   Float_t         njetid;
   Float_t         pchmet;
   Float_t         pdfid1;
   Float_t         pdfid2;
   Float_t         pdfscalePDF;
   Float_t         pdfx1;
   Float_t         pdfx1PDF;
   Float_t         pdfx2;
   Float_t         pdfx2PDF;
   Float_t         peaking;
   Float_t         pfmetMEtSig;
   Float_t         pfmetSignificance;
   Float_t         pho_n_id;
   Float_t         predmet;
   Float_t         puW;
   Float_t         redmet;
   Float_t         run;
   Float_t         softbjpb;
   Float_t         softcmva;
   Float_t         softcsvv2ivf;
   Float_t         softpfcsv;
   Float_t         softssvhb;
   Float_t         softssvhe;
   Float_t         softtche;
   vector<float>   *std_vector_LHElepton_eta;
   vector<float>   *std_vector_LHElepton_id;
   vector<float>   *std_vector_LHElepton_phi;
   vector<float>   *std_vector_LHElepton_pt;
   vector<float>   *std_vector_LHEneutrino_eta;
   vector<float>   *std_vector_LHEneutrino_id;
   vector<float>   *std_vector_LHEneutrino_phi;
   vector<float>   *std_vector_LHEneutrino_pt;
   vector<float>   *std_vector_LHEparton_eta;
   vector<float>   *std_vector_LHEparton_id;
   vector<float>   *std_vector_LHEparton_phi;
   vector<float>   *std_vector_LHEparton_pt;
   vector<float>   *std_vector_VBoson_eta;
   vector<float>   *std_vector_VBoson_mass;
   vector<float>   *std_vector_VBoson_phi;
   vector<float>   *std_vector_VBoson_pid;
   vector<float>   *std_vector_VBoson_pt;
   vector<float>   *std_vector_dressedLeptonGen_eta;
   vector<float>   *std_vector_dressedLeptonGen_phi;
   vector<float>   *std_vector_dressedLeptonGen_pid;
   vector<float>   *std_vector_dressedLeptonGen_pt;
   vector<float>   *std_vector_electron_dEtaIn;
   vector<float>   *std_vector_electron_dPhiIn;
   vector<float>   *std_vector_electron_ecalPFClusterIso;
   vector<float>   *std_vector_electron_effectiveArea;
   vector<float>   *std_vector_electron_expectedMissingInnerHits;
   vector<float>   *std_vector_electron_full5x5_sigmaIetaIeta;
   vector<float>   *std_vector_electron_hOverE;
   vector<float>   *std_vector_electron_hcalPFClusterIso;
   vector<float>   *std_vector_electron_ooEmooP;
   vector<float>   *std_vector_electron_passConversionVeto;
   vector<float>   *std_vector_electron_scEta;
   vector<float>   *std_vector_jetGen_eta;
   vector<float>   *std_vector_jetGen_phi;
   vector<float>   *std_vector_jetGen_pt;
   vector<float>   *std_vector_jet_HadronFlavour;
   vector<float>   *std_vector_jet_NumberSoftMu;
   vector<float>   *std_vector_jet_PartonFlavour;
   vector<float>   *std_vector_jet_QGlikelihood;
   vector<float>   *std_vector_jet_bjpb;
   vector<float>   *std_vector_jet_cmva;
   vector<float>   *std_vector_jet_csvv2ivf;
   vector<float>   *std_vector_jet_eta;
   vector<float>   *std_vector_jet_mass;
   vector<float>   *std_vector_jet_pfcsv;
   vector<float>   *std_vector_jet_phi;
   vector<float>   *std_vector_jet_pt;
   vector<float>   *std_vector_jet_puid;
   vector<float>   *std_vector_jet_softMuD0;
   vector<float>   *std_vector_jet_softMuDz;
   vector<float>   *std_vector_jet_softMuEta;
   vector<float>   *std_vector_jet_softMuIso;
   vector<float>   *std_vector_jet_softMuPhi;
   vector<float>   *std_vector_jet_softMuPt;
   vector<float>   *std_vector_jet_ssvhb;
   vector<float>   *std_vector_jet_ssvhe;
   vector<float>   *std_vector_jet_tche;
   vector<float>   *std_vector_jet_tchp;
   vector<float>   *std_vector_leptonGen_eta;
   vector<float>   *std_vector_leptonGen_isDirectPromptTauDecayProduct;
   vector<float>   *std_vector_leptonGen_isPrompt;
   vector<float>   *std_vector_leptonGen_phi;
   vector<float>   *std_vector_leptonGen_pid;
   vector<float>   *std_vector_leptonGen_pt;
   vector<float>   *std_vector_leptonGen_status;
   vector<float>   *std_vector_lepton_PfIsoDeltaBeta;
   vector<float>   *std_vector_lepton_ch;
   vector<float>   *std_vector_lepton_chargedHadronIso;
   vector<float>   *std_vector_lepton_chargedParticleIso;
   vector<float>   *std_vector_lepton_closejet_PartonFlavour;
   vector<float>   *std_vector_lepton_closejet_drlj;
   vector<float>   *std_vector_lepton_closejet_eta;
   vector<float>   *std_vector_lepton_closejet_phi;
   vector<float>   *std_vector_lepton_closejet_pt;
   vector<float>   *std_vector_lepton_d0;
   vector<float>   *std_vector_lepton_dz;
   vector<float>   *std_vector_lepton_elSIP3D;
   vector<float>   *std_vector_lepton_eleIdLoose;
   vector<float>   *std_vector_lepton_eleIdMedium;
   vector<float>   *std_vector_lepton_eleIdTight;
   vector<float>   *std_vector_lepton_eleIdVeto;
   vector<float>   *std_vector_lepton_eta;
   vector<float>   *std_vector_lepton_flavour;
   vector<float>   *std_vector_lepton_isMediumMuon;
   vector<float>   *std_vector_lepton_isTightMuon;
   vector<float>   *std_vector_lepton_isTrackerMuon;
   vector<float>   *std_vector_lepton_muSIP3D;
   vector<float>   *std_vector_lepton_neutralHadronIso;
   vector<float>   *std_vector_lepton_phi;
   vector<float>   *std_vector_lepton_photonIso;
   vector<float>   *std_vector_lepton_pt;
   vector<float>   *std_vector_lepton_sumPUPt;
   vector<float>   *std_vector_lepton_trackIso;
   vector<float>   *std_vector_muon_Chi2LocalPos;
   vector<float>   *std_vector_muon_NTkLayers;
   vector<float>   *std_vector_muon_NValidFractInTrk;
   vector<float>   *std_vector_muon_NValidHitsInTrk;
   vector<float>   *std_vector_muon_NValidHitsSATrk;
   vector<float>   *std_vector_muon_NValidPixelHitsInTrk;
   vector<float>   *std_vector_muon_NormChi2GTrk;
   vector<float>   *std_vector_muon_NumOfMatchedStations;
   vector<float>   *std_vector_muon_SegCompatibilty;
   vector<float>   *std_vector_muon_TrkKink;
   vector<float>   *std_vector_neutrinoGen_eta;
   vector<float>   *std_vector_neutrinoGen_isDirectPromptTauDecayProduct;
   vector<float>   *std_vector_neutrinoGen_isPrompt;
   vector<float>   *std_vector_neutrinoGen_phi;
   vector<float>   *std_vector_neutrinoGen_pid;
   vector<float>   *std_vector_neutrinoGen_pt;
   vector<float>   *std_vector_partonGen_eta;
   vector<float>   *std_vector_partonGen_isHardProcess;
   vector<float>   *std_vector_partonGen_isPrompt;
   vector<float>   *std_vector_partonGen_phi;
   vector<float>   *std_vector_partonGen_pid;
   vector<float>   *std_vector_partonGen_pt;
   vector<float>   *std_vector_photon_eta;
   vector<float>   *std_vector_photon_phi;
   vector<float>   *std_vector_photon_pt;
   vector<float>   *std_vector_photonid_eta;
   vector<float>   *std_vector_photonid_phi;
   vector<float>   *std_vector_photonid_pt;
   vector<float>   *std_vector_puppijet_eta;
   vector<float>   *std_vector_puppijet_phi;
   vector<float>   *std_vector_puppijet_pt;
   vector<float>   *std_vector_tau_eta;
   vector<float>   *std_vector_tau_phi;
   vector<float>   *std_vector_tau_pt;
   vector<float>   *std_vector_trigger_special;
   Float_t         tightmu;
   Float_t         triggW;
   Float_t         trigger;
   Float_t         triggerFakeRate;
   Float_t         itpu;
   Float_t         nvtx;
   Float_t         ootpum1;
   Float_t         ootpum2;
   Float_t         ootpum3;
   Float_t         ootpum4;
   Float_t         ootpum5;
   Float_t         ootpup1;
   Float_t         ootpup2;
   Float_t         ootpup3;
   Float_t         trpu;
   Int_t           bveto_ip;

   // List of branches
   TBranch        *b_baseW;   //!
   TBranch        *b_chSumEt;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_chmet;   //!
   TBranch        *b_chmetphi;   //!
   TBranch        *b_dataset;   //!
   TBranch        *b_effW;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_fakeW;   //!
   TBranch        *b_hardbjpb;   //!
   TBranch        *b_hardcmva;   //!
   TBranch        *b_hardcsvv2ivf;   //!
   TBranch        *b_hardpfcsv;   //!
   TBranch        *b_hardssvhb;   //!
   TBranch        *b_hardssvhe;   //!
   TBranch        *b_hardtche;   //!
   TBranch        *b_higgsGeneta;   //!
   TBranch        *b_higgsGenmass;   //!
   TBranch        *b_higgsGenphi;   //!
   TBranch        *b_higgsGenpt;   //!
   TBranch        *b_higgsLHEeta;   //!
   TBranch        *b_higgsLHEm;   //!
   TBranch        *b_higgsLHEphi;   //!
   TBranch        *b_higgsLHEpt;   //!
   TBranch        *b_imet;   //!
   TBranch        *b_jetRho;   //!
   TBranch        *b_jetcmva1;   //!
   TBranch        *b_jetcmva2;   //!
   TBranch        *b_jetcsvv2ivf1;   //!
   TBranch        *b_jetcsvv2ivf2;   //!
   TBranch        *b_jetpfcsv1;   //!
   TBranch        *b_jetpfcsv2;   //!
   TBranch        *b_jetssvhb1;   //!
   TBranch        *b_jetssvhb2;   //!
   TBranch        *b_jetssvhe1;   //!
   TBranch        *b_jetssvhe2;   //!
   TBranch        *b_kfW;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_mctruth;   //!
   TBranch        *b_metGeneta;   //!
   TBranch        *b_metGenphi;   //!
   TBranch        *b_metGenpt;   //!
   TBranch        *b_metLHEeta;   //!
   TBranch        *b_metLHEphi;   //!
   TBranch        *b_metLHEpt;   //!
   TBranch        *b_metPfNoHf;   //!
   TBranch        *b_metPfProj;   //!
   TBranch        *b_metPfRaw;   //!
   TBranch        *b_metPfRawPhi;   //!
   TBranch        *b_metPfRawSumEt;   //!
   TBranch        *b_metPfType1;   //!
   TBranch        *b_metPfType1ElecDn;   //!
   TBranch        *b_metPfType1ElecUp;   //!
   TBranch        *b_metPfType1JetDn;   //!
   TBranch        *b_metPfType1JetUp;   //!
   TBranch        *b_metPfType1MuonDn;   //!
   TBranch        *b_metPfType1MuonUp;   //!
   TBranch        *b_metPfType1Phi;   //!
   TBranch        *b_metPfType1SumEt;   //!
   TBranch        *b_metPuppi;   //!
   TBranch        *b_metTtrk;   //!
   TBranch        *b_metTtrkPhi;   //!
   TBranch        *b_mllg;   //!
   TBranch        *b_mllgid;   //!
   TBranch        *b_mpmet;   //!
   TBranch        *b_nPhos;   //!
   TBranch        *b_nbjet;   //!
   TBranch        *b_nbjettche;   //!
   TBranch        *b_nextra;   //!
   TBranch        *b_njet;   //!
   TBranch        *b_njetid;   //!
   TBranch        *b_pchmet;   //!
   TBranch        *b_pdfid1;   //!
   TBranch        *b_pdfid2;   //!
   TBranch        *b_pdfscalePDF;   //!
   TBranch        *b_pdfx1;   //!
   TBranch        *b_pdfx1PDF;   //!
   TBranch        *b_pdfx2;   //!
   TBranch        *b_pdfx2PDF;   //!
   TBranch        *b_peaking;   //!
   TBranch        *b_pfmetMEtSig;   //!
   TBranch        *b_pfmetSignificance;   //!
   TBranch        *b_pho_n_id;   //!
   TBranch        *b_predmet;   //!
   TBranch        *b_puW;   //!
   TBranch        *b_redmet;   //!
   TBranch        *b_run;   //!
   TBranch        *b_softbjpb;   //!
   TBranch        *b_softcmva;   //!
   TBranch        *b_softcsvv2ivf;   //!
   TBranch        *b_softpfcsv;   //!
   TBranch        *b_softssvhb;   //!
   TBranch        *b_softssvhe;   //!
   TBranch        *b_softtche;   //!
   TBranch        *b_std_vector_LHElepton_eta;   //!
   TBranch        *b_std_vector_LHElepton_id;   //!
   TBranch        *b_std_vector_LHElepton_phi;   //!
   TBranch        *b_std_vector_LHElepton_pt;   //!
   TBranch        *b_std_vector_LHEneutrino_eta;   //!
   TBranch        *b_std_vector_LHEneutrino_id;   //!
   TBranch        *b_std_vector_LHEneutrino_phi;   //!
   TBranch        *b_std_vector_LHEneutrino_pt;   //!
   TBranch        *b_std_vector_LHEparton_eta;   //!
   TBranch        *b_std_vector_LHEparton_id;   //!
   TBranch        *b_std_vector_LHEparton_phi;   //!
   TBranch        *b_std_vector_LHEparton_pt;   //!
   TBranch        *b_std_vector_VBoson_eta;   //!
   TBranch        *b_std_vector_VBoson_mass;   //!
   TBranch        *b_std_vector_VBoson_phi;   //!
   TBranch        *b_std_vector_VBoson_pid;   //!
   TBranch        *b_std_vector_VBoson_pt;   //!
   TBranch        *b_std_vector_dressedLeptonGen_eta;   //!
   TBranch        *b_std_vector_dressedLeptonGen_phi;   //!
   TBranch        *b_std_vector_dressedLeptonGen_pid;   //!
   TBranch        *b_std_vector_dressedLeptonGen_pt;   //!
   TBranch        *b_std_vector_electron_dEtaIn;   //!
   TBranch        *b_std_vector_electron_dPhiIn;   //!
   TBranch        *b_std_vector_electron_ecalPFClusterIso;   //!
   TBranch        *b_std_vector_electron_effectiveArea;   //!
   TBranch        *b_std_vector_electron_expectedMissingInnerHits;   //!
   TBranch        *b_std_vector_electron_full5x5_sigmaIetaIeta;   //!
   TBranch        *b_std_vector_electron_hOverE;   //!
   TBranch        *b_std_vector_electron_hcalPFClusterIso;   //!
   TBranch        *b_std_vector_electron_ooEmooP;   //!
   TBranch        *b_std_vector_electron_passConversionVeto;   //!
   TBranch        *b_std_vector_electron_scEta;   //!
   TBranch        *b_std_vector_jetGen_eta;   //!
   TBranch        *b_std_vector_jetGen_phi;   //!
   TBranch        *b_std_vector_jetGen_pt;   //!
   TBranch        *b_std_vector_jet_HadronFlavour;   //!
   TBranch        *b_std_vector_jet_NumberSoftMu;   //!
   TBranch        *b_std_vector_jet_PartonFlavour;   //!
   TBranch        *b_std_vector_jet_QGlikelihood;   //!
   TBranch        *b_std_vector_jet_bjpb;   //!
   TBranch        *b_std_vector_jet_cmva;   //!
   TBranch        *b_std_vector_jet_csvv2ivf;   //!
   TBranch        *b_std_vector_jet_eta;   //!
   TBranch        *b_std_vector_jet_mass;   //!
   TBranch        *b_std_vector_jet_pfcsv;   //!
   TBranch        *b_std_vector_jet_phi;   //!
   TBranch        *b_std_vector_jet_pt;   //!
   TBranch        *b_std_vector_jet_puid;   //!
   TBranch        *b_std_vector_jet_softMuD0;   //!
   TBranch        *b_std_vector_jet_softMuDz;   //!
   TBranch        *b_std_vector_jet_softMuEta;   //!
   TBranch        *b_std_vector_jet_softMuIso;   //!
   TBranch        *b_std_vector_jet_softMuPhi;   //!
   TBranch        *b_std_vector_jet_softMuPt;   //!
   TBranch        *b_std_vector_jet_ssvhb;   //!
   TBranch        *b_std_vector_jet_ssvhe;   //!
   TBranch        *b_std_vector_jet_tche;   //!
   TBranch        *b_std_vector_jet_tchp;   //!
   TBranch        *b_std_vector_leptonGen_eta;   //!
   TBranch        *b_std_vector_leptonGen_isDirectPromptTauDecayProduct;   //!
   TBranch        *b_std_vector_leptonGen_isPrompt;   //!
   TBranch        *b_std_vector_leptonGen_phi;   //!
   TBranch        *b_std_vector_leptonGen_pid;   //!
   TBranch        *b_std_vector_leptonGen_pt;   //!
   TBranch        *b_std_vector_leptonGen_status;   //!
   TBranch        *b_std_vector_lepton_PfIsoDeltaBeta;   //!
   TBranch        *b_std_vector_lepton_ch;   //!
   TBranch        *b_std_vector_lepton_chargedHadronIso;   //!
   TBranch        *b_std_vector_lepton_chargedParticleIso;   //!
   TBranch        *b_std_vector_lepton_closejet_PartonFlavour;   //!
   TBranch        *b_std_vector_lepton_closejet_drlj;   //!
   TBranch        *b_std_vector_lepton_closejet_eta;   //!
   TBranch        *b_std_vector_lepton_closejet_phi;   //!
   TBranch        *b_std_vector_lepton_closejet_pt;   //!
   TBranch        *b_std_vector_lepton_d0;   //!
   TBranch        *b_std_vector_lepton_dz;   //!
   TBranch        *b_std_vector_lepton_elSIP3D;   //!
   TBranch        *b_std_vector_lepton_eleIdLoose;   //!
   TBranch        *b_std_vector_lepton_eleIdMedium;   //!
   TBranch        *b_std_vector_lepton_eleIdTight;   //!
   TBranch        *b_std_vector_lepton_eleIdVeto;   //!
   TBranch        *b_std_vector_lepton_eta;   //!
   TBranch        *b_std_vector_lepton_flavour;   //!
   TBranch        *b_std_vector_lepton_isMediumMuon;   //!
   TBranch        *b_std_vector_lepton_isTightMuon;   //!
   TBranch        *b_std_vector_lepton_isTrackerMuon;   //!
   TBranch        *b_std_vector_lepton_muSIP3D;   //!
   TBranch        *b_std_vector_lepton_neutralHadronIso;   //!
   TBranch        *b_std_vector_lepton_phi;   //!
   TBranch        *b_std_vector_lepton_photonIso;   //!
   TBranch        *b_std_vector_lepton_pt;   //!
   TBranch        *b_std_vector_lepton_sumPUPt;   //!
   TBranch        *b_std_vector_lepton_trackIso;   //!
   TBranch        *b_std_vector_muon_Chi2LocalPos;   //!
   TBranch        *b_std_vector_muon_NTkLayers;   //!
   TBranch        *b_std_vector_muon_NValidFractInTrk;   //!
   TBranch        *b_std_vector_muon_NValidHitsInTrk;   //!
   TBranch        *b_std_vector_muon_NValidHitsSATrk;   //!
   TBranch        *b_std_vector_muon_NValidPixelHitsInTrk;   //!
   TBranch        *b_std_vector_muon_NormChi2GTrk;   //!
   TBranch        *b_std_vector_muon_NumOfMatchedStations;   //!
   TBranch        *b_std_vector_muon_SegCompatibilty;   //!
   TBranch        *b_std_vector_muon_TrkKink;   //!
   TBranch        *b_std_vector_neutrinoGen_eta;   //!
   TBranch        *b_std_vector_neutrinoGen_isDirectPromptTauDecayProduct;   //!
   TBranch        *b_std_vector_neutrinoGen_isPrompt;   //!
   TBranch        *b_std_vector_neutrinoGen_phi;   //!
   TBranch        *b_std_vector_neutrinoGen_pid;   //!
   TBranch        *b_std_vector_neutrinoGen_pt;   //!
   TBranch        *b_std_vector_partonGen_eta;   //!
   TBranch        *b_std_vector_partonGen_isHardProcess;   //!
   TBranch        *b_std_vector_partonGen_isPrompt;   //!
   TBranch        *b_std_vector_partonGen_phi;   //!
   TBranch        *b_std_vector_partonGen_pid;   //!
   TBranch        *b_std_vector_partonGen_pt;   //!
   TBranch        *b_std_vector_photon_eta;   //!
   TBranch        *b_std_vector_photon_phi;   //!
   TBranch        *b_std_vector_photon_pt;   //!
   TBranch        *b_std_vector_photonid_eta;   //!
   TBranch        *b_std_vector_photonid_phi;   //!
   TBranch        *b_std_vector_photonid_pt;   //!
   TBranch        *b_std_vector_puppijet_eta;   //!
   TBranch        *b_std_vector_puppijet_phi;   //!
   TBranch        *b_std_vector_puppijet_pt;   //!
   TBranch        *b_std_vector_tau_eta;   //!
   TBranch        *b_std_vector_tau_phi;   //!
   TBranch        *b_std_vector_tau_pt;   //!
   TBranch        *b_std_vector_trigger_special;   //!
   TBranch        *b_tightmu;   //!
   TBranch        *b_triggW;   //!
   TBranch        *b_trigger;   //!
   TBranch        *b_triggerFakeRate;   //!
   TBranch        *b_itpu;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_ootpum1;   //!
   TBranch        *b_ootpum2;   //!
   TBranch        *b_ootpum3;   //!
   TBranch        *b_ootpum4;   //!
   TBranch        *b_ootpum5;   //!
   TBranch        *b_ootpup1;   //!
   TBranch        *b_ootpup2;   //!
   TBranch        *b_ootpup3;   //!
   TBranch        *b_trpu;   //!
   TBranch        *b_bveto_ip;   //!

   HWWtestClass(TTree *tree=0);
   virtual ~HWWtestClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HWWtestClass_cxx
HWWtestClass::HWWtestClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("latino",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("latino","");
      chain->Add("./latino_stepB_numEvent100.root/latino");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

HWWtestClass::~HWWtestClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HWWtestClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HWWtestClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HWWtestClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   std_vector_LHElepton_eta = 0;
   std_vector_LHElepton_id = 0;
   std_vector_LHElepton_phi = 0;
   std_vector_LHElepton_pt = 0;
   std_vector_LHEneutrino_eta = 0;
   std_vector_LHEneutrino_id = 0;
   std_vector_LHEneutrino_phi = 0;
   std_vector_LHEneutrino_pt = 0;
   std_vector_LHEparton_eta = 0;
   std_vector_LHEparton_id = 0;
   std_vector_LHEparton_phi = 0;
   std_vector_LHEparton_pt = 0;
   std_vector_VBoson_eta = 0;
   std_vector_VBoson_mass = 0;
   std_vector_VBoson_phi = 0;
   std_vector_VBoson_pid = 0;
   std_vector_VBoson_pt = 0;
   std_vector_dressedLeptonGen_eta = 0;
   std_vector_dressedLeptonGen_phi = 0;
   std_vector_dressedLeptonGen_pid = 0;
   std_vector_dressedLeptonGen_pt = 0;
   std_vector_electron_dEtaIn = 0;
   std_vector_electron_dPhiIn = 0;
   std_vector_electron_ecalPFClusterIso = 0;
   std_vector_electron_effectiveArea = 0;
   std_vector_electron_expectedMissingInnerHits = 0;
   std_vector_electron_full5x5_sigmaIetaIeta = 0;
   std_vector_electron_hOverE = 0;
   std_vector_electron_hcalPFClusterIso = 0;
   std_vector_electron_ooEmooP = 0;
   std_vector_electron_passConversionVeto = 0;
   std_vector_electron_scEta = 0;
   std_vector_jetGen_eta = 0;
   std_vector_jetGen_phi = 0;
   std_vector_jetGen_pt = 0;
   std_vector_jet_HadronFlavour = 0;
   std_vector_jet_NumberSoftMu = 0;
   std_vector_jet_PartonFlavour = 0;
   std_vector_jet_QGlikelihood = 0;
   std_vector_jet_bjpb = 0;
   std_vector_jet_cmva = 0;
   std_vector_jet_csvv2ivf = 0;
   std_vector_jet_eta = 0;
   std_vector_jet_mass = 0;
   std_vector_jet_pfcsv = 0;
   std_vector_jet_phi = 0;
   std_vector_jet_pt = 0;
   std_vector_jet_puid = 0;
   std_vector_jet_softMuD0 = 0;
   std_vector_jet_softMuDz = 0;
   std_vector_jet_softMuEta = 0;
   std_vector_jet_softMuIso = 0;
   std_vector_jet_softMuPhi = 0;
   std_vector_jet_softMuPt = 0;
   std_vector_jet_ssvhb = 0;
   std_vector_jet_ssvhe = 0;
   std_vector_jet_tche = 0;
   std_vector_jet_tchp = 0;
   std_vector_leptonGen_eta = 0;
   std_vector_leptonGen_isDirectPromptTauDecayProduct = 0;
   std_vector_leptonGen_isPrompt = 0;
   std_vector_leptonGen_phi = 0;
   std_vector_leptonGen_pid = 0;
   std_vector_leptonGen_pt = 0;
   std_vector_leptonGen_status = 0;
   std_vector_lepton_PfIsoDeltaBeta = 0;
   std_vector_lepton_ch = 0;
   std_vector_lepton_chargedHadronIso = 0;
   std_vector_lepton_chargedParticleIso = 0;
   std_vector_lepton_closejet_PartonFlavour = 0;
   std_vector_lepton_closejet_drlj = 0;
   std_vector_lepton_closejet_eta = 0;
   std_vector_lepton_closejet_phi = 0;
   std_vector_lepton_closejet_pt = 0;
   std_vector_lepton_d0 = 0;
   std_vector_lepton_dz = 0;
   std_vector_lepton_elSIP3D = 0;
   std_vector_lepton_eleIdLoose = 0;
   std_vector_lepton_eleIdMedium = 0;
   std_vector_lepton_eleIdTight = 0;
   std_vector_lepton_eleIdVeto = 0;
   std_vector_lepton_eta = 0;
   std_vector_lepton_flavour = 0;
   std_vector_lepton_isMediumMuon = 0;
   std_vector_lepton_isTightMuon = 0;
   std_vector_lepton_isTrackerMuon = 0;
   std_vector_lepton_muSIP3D = 0;
   std_vector_lepton_neutralHadronIso = 0;
   std_vector_lepton_phi = 0;
   std_vector_lepton_photonIso = 0;
   std_vector_lepton_pt = 0;
   std_vector_lepton_sumPUPt = 0;
   std_vector_lepton_trackIso = 0;
   std_vector_muon_Chi2LocalPos = 0;
   std_vector_muon_NTkLayers = 0;
   std_vector_muon_NValidFractInTrk = 0;
   std_vector_muon_NValidHitsInTrk = 0;
   std_vector_muon_NValidHitsSATrk = 0;
   std_vector_muon_NValidPixelHitsInTrk = 0;
   std_vector_muon_NormChi2GTrk = 0;
   std_vector_muon_NumOfMatchedStations = 0;
   std_vector_muon_SegCompatibilty = 0;
   std_vector_muon_TrkKink = 0;
   std_vector_neutrinoGen_eta = 0;
   std_vector_neutrinoGen_isDirectPromptTauDecayProduct = 0;
   std_vector_neutrinoGen_isPrompt = 0;
   std_vector_neutrinoGen_phi = 0;
   std_vector_neutrinoGen_pid = 0;
   std_vector_neutrinoGen_pt = 0;
   std_vector_partonGen_eta = 0;
   std_vector_partonGen_isHardProcess = 0;
   std_vector_partonGen_isPrompt = 0;
   std_vector_partonGen_phi = 0;
   std_vector_partonGen_pid = 0;
   std_vector_partonGen_pt = 0;
   std_vector_photon_eta = 0;
   std_vector_photon_phi = 0;
   std_vector_photon_pt = 0;
   std_vector_photonid_eta = 0;
   std_vector_photonid_phi = 0;
   std_vector_photonid_pt = 0;
   std_vector_puppijet_eta = 0;
   std_vector_puppijet_phi = 0;
   std_vector_puppijet_pt = 0;
   std_vector_tau_eta = 0;
   std_vector_tau_phi = 0;
   std_vector_tau_pt = 0;
   std_vector_trigger_special = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("baseW", &baseW, &b_baseW);
   fChain->SetBranchAddress("chSumEt", &chSumEt, &b_chSumEt);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   fChain->SetBranchAddress("chmet", &chmet, &b_chmet);
   fChain->SetBranchAddress("chmetphi", &chmetphi, &b_chmetphi);
   fChain->SetBranchAddress("dataset", &dataset, &b_dataset);
   fChain->SetBranchAddress("effW", &effW, &b_effW);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("fakeW", &fakeW, &b_fakeW);
   fChain->SetBranchAddress("hardbjpb", &hardbjpb, &b_hardbjpb);
   fChain->SetBranchAddress("hardcmva", &hardcmva, &b_hardcmva);
   fChain->SetBranchAddress("hardcsvv2ivf", &hardcsvv2ivf, &b_hardcsvv2ivf);
   fChain->SetBranchAddress("hardpfcsv", &hardpfcsv, &b_hardpfcsv);
   fChain->SetBranchAddress("hardssvhb", &hardssvhb, &b_hardssvhb);
   fChain->SetBranchAddress("hardssvhe", &hardssvhe, &b_hardssvhe);
   fChain->SetBranchAddress("hardtche", &hardtche, &b_hardtche);
   fChain->SetBranchAddress("higgsGeneta", &higgsGeneta, &b_higgsGeneta);
   fChain->SetBranchAddress("higgsGenmass", &higgsGenmass, &b_higgsGenmass);
   fChain->SetBranchAddress("higgsGenphi", &higgsGenphi, &b_higgsGenphi);
   fChain->SetBranchAddress("higgsGenpt", &higgsGenpt, &b_higgsGenpt);
   fChain->SetBranchAddress("higgsLHEeta", &higgsLHEeta, &b_higgsLHEeta);
   fChain->SetBranchAddress("higgsLHEm", &higgsLHEm, &b_higgsLHEm);
   fChain->SetBranchAddress("higgsLHEphi", &higgsLHEphi, &b_higgsLHEphi);
   fChain->SetBranchAddress("higgsLHEpt", &higgsLHEpt, &b_higgsLHEpt);
   fChain->SetBranchAddress("imet", &imet, &b_imet);
   fChain->SetBranchAddress("jetRho", &jetRho, &b_jetRho);
   fChain->SetBranchAddress("jetcmva1", &jetcmva1, &b_jetcmva1);
   fChain->SetBranchAddress("jetcmva2", &jetcmva2, &b_jetcmva2);
   fChain->SetBranchAddress("jetcsvv2ivf1", &jetcsvv2ivf1, &b_jetcsvv2ivf1);
   fChain->SetBranchAddress("jetcsvv2ivf2", &jetcsvv2ivf2, &b_jetcsvv2ivf2);
   fChain->SetBranchAddress("jetpfcsv1", &jetpfcsv1, &b_jetpfcsv1);
   fChain->SetBranchAddress("jetpfcsv2", &jetpfcsv2, &b_jetpfcsv2);
   fChain->SetBranchAddress("jetssvhb1", &jetssvhb1, &b_jetssvhb1);
   fChain->SetBranchAddress("jetssvhb2", &jetssvhb2, &b_jetssvhb2);
   fChain->SetBranchAddress("jetssvhe1", &jetssvhe1, &b_jetssvhe1);
   fChain->SetBranchAddress("jetssvhe2", &jetssvhe2, &b_jetssvhe2);
   fChain->SetBranchAddress("kfW", &kfW, &b_kfW);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("mctruth", &mctruth, &b_mctruth);
   fChain->SetBranchAddress("metGeneta", &metGeneta, &b_metGeneta);
   fChain->SetBranchAddress("metGenphi", &metGenphi, &b_metGenphi);
   fChain->SetBranchAddress("metGenpt", &metGenpt, &b_metGenpt);
   fChain->SetBranchAddress("metLHEeta", &metLHEeta, &b_metLHEeta);
   fChain->SetBranchAddress("metLHEphi", &metLHEphi, &b_metLHEphi);
   fChain->SetBranchAddress("metLHEpt", &metLHEpt, &b_metLHEpt);
   fChain->SetBranchAddress("metPfNoHf", &metPfNoHf, &b_metPfNoHf);
   fChain->SetBranchAddress("metPfProj", &metPfProj, &b_metPfProj);
   fChain->SetBranchAddress("metPfRaw", &metPfRaw, &b_metPfRaw);
   fChain->SetBranchAddress("metPfRawPhi", &metPfRawPhi, &b_metPfRawPhi);
   fChain->SetBranchAddress("metPfRawSumEt", &metPfRawSumEt, &b_metPfRawSumEt);
   fChain->SetBranchAddress("metPfType1", &metPfType1, &b_metPfType1);
   fChain->SetBranchAddress("metPfType1ElecDn", &metPfType1ElecDn, &b_metPfType1ElecDn);
   fChain->SetBranchAddress("metPfType1ElecUp", &metPfType1ElecUp, &b_metPfType1ElecUp);
   fChain->SetBranchAddress("metPfType1JetDn", &metPfType1JetDn, &b_metPfType1JetDn);
   fChain->SetBranchAddress("metPfType1JetUp", &metPfType1JetUp, &b_metPfType1JetUp);
   fChain->SetBranchAddress("metPfType1MuonDn", &metPfType1MuonDn, &b_metPfType1MuonDn);
   fChain->SetBranchAddress("metPfType1MuonUp", &metPfType1MuonUp, &b_metPfType1MuonUp);
   fChain->SetBranchAddress("metPfType1Phi", &metPfType1Phi, &b_metPfType1Phi);
   fChain->SetBranchAddress("metPfType1SumEt", &metPfType1SumEt, &b_metPfType1SumEt);
   fChain->SetBranchAddress("metPuppi", &metPuppi, &b_metPuppi);
   fChain->SetBranchAddress("metTtrk", &metTtrk, &b_metTtrk);
   fChain->SetBranchAddress("metTtrkPhi", &metTtrkPhi, &b_metTtrkPhi);
   fChain->SetBranchAddress("mllg", &mllg, &b_mllg);
   fChain->SetBranchAddress("mllgid", &mllgid, &b_mllgid);
   fChain->SetBranchAddress("mpmet", &mpmet, &b_mpmet);
   fChain->SetBranchAddress("nPhos", &nPhos, &b_nPhos);
   fChain->SetBranchAddress("nbjet", &nbjet, &b_nbjet);
   fChain->SetBranchAddress("nbjettche", &nbjettche, &b_nbjettche);
   fChain->SetBranchAddress("nextra", &nextra, &b_nextra);
   fChain->SetBranchAddress("njet", &njet, &b_njet);
   fChain->SetBranchAddress("njetid", &njetid, &b_njetid);
   fChain->SetBranchAddress("pchmet", &pchmet, &b_pchmet);
   fChain->SetBranchAddress("pdfid1", &pdfid1, &b_pdfid1);
   fChain->SetBranchAddress("pdfid2", &pdfid2, &b_pdfid2);
   fChain->SetBranchAddress("pdfscalePDF", &pdfscalePDF, &b_pdfscalePDF);
   fChain->SetBranchAddress("pdfx1", &pdfx1, &b_pdfx1);
   fChain->SetBranchAddress("pdfx1PDF", &pdfx1PDF, &b_pdfx1PDF);
   fChain->SetBranchAddress("pdfx2", &pdfx2, &b_pdfx2);
   fChain->SetBranchAddress("pdfx2PDF", &pdfx2PDF, &b_pdfx2PDF);
   fChain->SetBranchAddress("peaking", &peaking, &b_peaking);
   fChain->SetBranchAddress("pfmetMEtSig", &pfmetMEtSig, &b_pfmetMEtSig);
   fChain->SetBranchAddress("pfmetSignificance", &pfmetSignificance, &b_pfmetSignificance);
   fChain->SetBranchAddress("pho_n_id", &pho_n_id, &b_pho_n_id);
   fChain->SetBranchAddress("predmet", &predmet, &b_predmet);
   fChain->SetBranchAddress("puW", &puW, &b_puW);
   fChain->SetBranchAddress("redmet", &redmet, &b_redmet);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("softbjpb", &softbjpb, &b_softbjpb);
   fChain->SetBranchAddress("softcmva", &softcmva, &b_softcmva);
   fChain->SetBranchAddress("softcsvv2ivf", &softcsvv2ivf, &b_softcsvv2ivf);
   fChain->SetBranchAddress("softpfcsv", &softpfcsv, &b_softpfcsv);
   fChain->SetBranchAddress("softssvhb", &softssvhb, &b_softssvhb);
   fChain->SetBranchAddress("softssvhe", &softssvhe, &b_softssvhe);
   fChain->SetBranchAddress("softtche", &softtche, &b_softtche);
   fChain->SetBranchAddress("std_vector_LHElepton_eta", &std_vector_LHElepton_eta, &b_std_vector_LHElepton_eta);
   fChain->SetBranchAddress("std_vector_LHElepton_id", &std_vector_LHElepton_id, &b_std_vector_LHElepton_id);
   fChain->SetBranchAddress("std_vector_LHElepton_phi", &std_vector_LHElepton_phi, &b_std_vector_LHElepton_phi);
   fChain->SetBranchAddress("std_vector_LHElepton_pt", &std_vector_LHElepton_pt, &b_std_vector_LHElepton_pt);
   fChain->SetBranchAddress("std_vector_LHEneutrino_eta", &std_vector_LHEneutrino_eta, &b_std_vector_LHEneutrino_eta);
   fChain->SetBranchAddress("std_vector_LHEneutrino_id", &std_vector_LHEneutrino_id, &b_std_vector_LHEneutrino_id);
   fChain->SetBranchAddress("std_vector_LHEneutrino_phi", &std_vector_LHEneutrino_phi, &b_std_vector_LHEneutrino_phi);
   fChain->SetBranchAddress("std_vector_LHEneutrino_pt", &std_vector_LHEneutrino_pt, &b_std_vector_LHEneutrino_pt);
   fChain->SetBranchAddress("std_vector_LHEparton_eta", &std_vector_LHEparton_eta, &b_std_vector_LHEparton_eta);
   fChain->SetBranchAddress("std_vector_LHEparton_id", &std_vector_LHEparton_id, &b_std_vector_LHEparton_id);
   fChain->SetBranchAddress("std_vector_LHEparton_phi", &std_vector_LHEparton_phi, &b_std_vector_LHEparton_phi);
   fChain->SetBranchAddress("std_vector_LHEparton_pt", &std_vector_LHEparton_pt, &b_std_vector_LHEparton_pt);
   fChain->SetBranchAddress("std_vector_VBoson_eta", &std_vector_VBoson_eta, &b_std_vector_VBoson_eta);
   fChain->SetBranchAddress("std_vector_VBoson_mass", &std_vector_VBoson_mass, &b_std_vector_VBoson_mass);
   fChain->SetBranchAddress("std_vector_VBoson_phi", &std_vector_VBoson_phi, &b_std_vector_VBoson_phi);
   fChain->SetBranchAddress("std_vector_VBoson_pid", &std_vector_VBoson_pid, &b_std_vector_VBoson_pid);
   fChain->SetBranchAddress("std_vector_VBoson_pt", &std_vector_VBoson_pt, &b_std_vector_VBoson_pt);
   fChain->SetBranchAddress("std_vector_dressedLeptonGen_eta", &std_vector_dressedLeptonGen_eta, &b_std_vector_dressedLeptonGen_eta);
   fChain->SetBranchAddress("std_vector_dressedLeptonGen_phi", &std_vector_dressedLeptonGen_phi, &b_std_vector_dressedLeptonGen_phi);
   fChain->SetBranchAddress("std_vector_dressedLeptonGen_pid", &std_vector_dressedLeptonGen_pid, &b_std_vector_dressedLeptonGen_pid);
   fChain->SetBranchAddress("std_vector_dressedLeptonGen_pt", &std_vector_dressedLeptonGen_pt, &b_std_vector_dressedLeptonGen_pt);
   fChain->SetBranchAddress("std_vector_electron_dEtaIn", &std_vector_electron_dEtaIn, &b_std_vector_electron_dEtaIn);
   fChain->SetBranchAddress("std_vector_electron_dPhiIn", &std_vector_electron_dPhiIn, &b_std_vector_electron_dPhiIn);
   fChain->SetBranchAddress("std_vector_electron_ecalPFClusterIso", &std_vector_electron_ecalPFClusterIso, &b_std_vector_electron_ecalPFClusterIso);
   fChain->SetBranchAddress("std_vector_electron_effectiveArea", &std_vector_electron_effectiveArea, &b_std_vector_electron_effectiveArea);
   fChain->SetBranchAddress("std_vector_electron_expectedMissingInnerHits", &std_vector_electron_expectedMissingInnerHits, &b_std_vector_electron_expectedMissingInnerHits);
   fChain->SetBranchAddress("std_vector_electron_full5x5_sigmaIetaIeta", &std_vector_electron_full5x5_sigmaIetaIeta, &b_std_vector_electron_full5x5_sigmaIetaIeta);
   fChain->SetBranchAddress("std_vector_electron_hOverE", &std_vector_electron_hOverE, &b_std_vector_electron_hOverE);
   fChain->SetBranchAddress("std_vector_electron_hcalPFClusterIso", &std_vector_electron_hcalPFClusterIso, &b_std_vector_electron_hcalPFClusterIso);
   fChain->SetBranchAddress("std_vector_electron_ooEmooP", &std_vector_electron_ooEmooP, &b_std_vector_electron_ooEmooP);
   fChain->SetBranchAddress("std_vector_electron_passConversionVeto", &std_vector_electron_passConversionVeto, &b_std_vector_electron_passConversionVeto);
   fChain->SetBranchAddress("std_vector_electron_scEta", &std_vector_electron_scEta, &b_std_vector_electron_scEta);
   fChain->SetBranchAddress("std_vector_jetGen_eta", &std_vector_jetGen_eta, &b_std_vector_jetGen_eta);
   fChain->SetBranchAddress("std_vector_jetGen_phi", &std_vector_jetGen_phi, &b_std_vector_jetGen_phi);
   fChain->SetBranchAddress("std_vector_jetGen_pt", &std_vector_jetGen_pt, &b_std_vector_jetGen_pt);
   fChain->SetBranchAddress("std_vector_jet_HadronFlavour", &std_vector_jet_HadronFlavour, &b_std_vector_jet_HadronFlavour);
   fChain->SetBranchAddress("std_vector_jet_NumberSoftMu", &std_vector_jet_NumberSoftMu, &b_std_vector_jet_NumberSoftMu);
   fChain->SetBranchAddress("std_vector_jet_PartonFlavour", &std_vector_jet_PartonFlavour, &b_std_vector_jet_PartonFlavour);
   fChain->SetBranchAddress("std_vector_jet_QGlikelihood", &std_vector_jet_QGlikelihood, &b_std_vector_jet_QGlikelihood);
   fChain->SetBranchAddress("std_vector_jet_bjpb", &std_vector_jet_bjpb, &b_std_vector_jet_bjpb);
   fChain->SetBranchAddress("std_vector_jet_cmva", &std_vector_jet_cmva, &b_std_vector_jet_cmva);
   fChain->SetBranchAddress("std_vector_jet_csvv2ivf", &std_vector_jet_csvv2ivf, &b_std_vector_jet_csvv2ivf);
   fChain->SetBranchAddress("std_vector_jet_eta", &std_vector_jet_eta, &b_std_vector_jet_eta);
   fChain->SetBranchAddress("std_vector_jet_mass", &std_vector_jet_mass, &b_std_vector_jet_mass);
   fChain->SetBranchAddress("std_vector_jet_pfcsv", &std_vector_jet_pfcsv, &b_std_vector_jet_pfcsv);
   fChain->SetBranchAddress("std_vector_jet_phi", &std_vector_jet_phi, &b_std_vector_jet_phi);
   fChain->SetBranchAddress("std_vector_jet_pt", &std_vector_jet_pt, &b_std_vector_jet_pt);
   fChain->SetBranchAddress("std_vector_jet_puid", &std_vector_jet_puid, &b_std_vector_jet_puid);
   fChain->SetBranchAddress("std_vector_jet_softMuD0", &std_vector_jet_softMuD0, &b_std_vector_jet_softMuD0);
   fChain->SetBranchAddress("std_vector_jet_softMuDz", &std_vector_jet_softMuDz, &b_std_vector_jet_softMuDz);
   fChain->SetBranchAddress("std_vector_jet_softMuEta", &std_vector_jet_softMuEta, &b_std_vector_jet_softMuEta);
   fChain->SetBranchAddress("std_vector_jet_softMuIso", &std_vector_jet_softMuIso, &b_std_vector_jet_softMuIso);
   fChain->SetBranchAddress("std_vector_jet_softMuPhi", &std_vector_jet_softMuPhi, &b_std_vector_jet_softMuPhi);
   fChain->SetBranchAddress("std_vector_jet_softMuPt", &std_vector_jet_softMuPt, &b_std_vector_jet_softMuPt);
   fChain->SetBranchAddress("std_vector_jet_ssvhb", &std_vector_jet_ssvhb, &b_std_vector_jet_ssvhb);
   fChain->SetBranchAddress("std_vector_jet_ssvhe", &std_vector_jet_ssvhe, &b_std_vector_jet_ssvhe);
   fChain->SetBranchAddress("std_vector_jet_tche", &std_vector_jet_tche, &b_std_vector_jet_tche);
   fChain->SetBranchAddress("std_vector_jet_tchp", &std_vector_jet_tchp, &b_std_vector_jet_tchp);
   fChain->SetBranchAddress("std_vector_leptonGen_eta", &std_vector_leptonGen_eta, &b_std_vector_leptonGen_eta);
   fChain->SetBranchAddress("std_vector_leptonGen_isDirectPromptTauDecayProduct", &std_vector_leptonGen_isDirectPromptTauDecayProduct, &b_std_vector_leptonGen_isDirectPromptTauDecayProduct);
   fChain->SetBranchAddress("std_vector_leptonGen_isPrompt", &std_vector_leptonGen_isPrompt, &b_std_vector_leptonGen_isPrompt);
   fChain->SetBranchAddress("std_vector_leptonGen_phi", &std_vector_leptonGen_phi, &b_std_vector_leptonGen_phi);
   fChain->SetBranchAddress("std_vector_leptonGen_pid", &std_vector_leptonGen_pid, &b_std_vector_leptonGen_pid);
   fChain->SetBranchAddress("std_vector_leptonGen_pt", &std_vector_leptonGen_pt, &b_std_vector_leptonGen_pt);
   fChain->SetBranchAddress("std_vector_leptonGen_status", &std_vector_leptonGen_status, &b_std_vector_leptonGen_status);
   fChain->SetBranchAddress("std_vector_lepton_PfIsoDeltaBeta", &std_vector_lepton_PfIsoDeltaBeta, &b_std_vector_lepton_PfIsoDeltaBeta);
   fChain->SetBranchAddress("std_vector_lepton_ch", &std_vector_lepton_ch, &b_std_vector_lepton_ch);
   fChain->SetBranchAddress("std_vector_lepton_chargedHadronIso", &std_vector_lepton_chargedHadronIso, &b_std_vector_lepton_chargedHadronIso);
   fChain->SetBranchAddress("std_vector_lepton_chargedParticleIso", &std_vector_lepton_chargedParticleIso, &b_std_vector_lepton_chargedParticleIso);
   fChain->SetBranchAddress("std_vector_lepton_closejet_PartonFlavour", &std_vector_lepton_closejet_PartonFlavour, &b_std_vector_lepton_closejet_PartonFlavour);
   fChain->SetBranchAddress("std_vector_lepton_closejet_drlj", &std_vector_lepton_closejet_drlj, &b_std_vector_lepton_closejet_drlj);
   fChain->SetBranchAddress("std_vector_lepton_closejet_eta", &std_vector_lepton_closejet_eta, &b_std_vector_lepton_closejet_eta);
   fChain->SetBranchAddress("std_vector_lepton_closejet_phi", &std_vector_lepton_closejet_phi, &b_std_vector_lepton_closejet_phi);
   fChain->SetBranchAddress("std_vector_lepton_closejet_pt", &std_vector_lepton_closejet_pt, &b_std_vector_lepton_closejet_pt);
   fChain->SetBranchAddress("std_vector_lepton_d0", &std_vector_lepton_d0, &b_std_vector_lepton_d0);
   fChain->SetBranchAddress("std_vector_lepton_dz", &std_vector_lepton_dz, &b_std_vector_lepton_dz);
   fChain->SetBranchAddress("std_vector_lepton_elSIP3D", &std_vector_lepton_elSIP3D, &b_std_vector_lepton_elSIP3D);
   fChain->SetBranchAddress("std_vector_lepton_eleIdLoose", &std_vector_lepton_eleIdLoose, &b_std_vector_lepton_eleIdLoose);
   fChain->SetBranchAddress("std_vector_lepton_eleIdMedium", &std_vector_lepton_eleIdMedium, &b_std_vector_lepton_eleIdMedium);
   fChain->SetBranchAddress("std_vector_lepton_eleIdTight", &std_vector_lepton_eleIdTight, &b_std_vector_lepton_eleIdTight);
   fChain->SetBranchAddress("std_vector_lepton_eleIdVeto", &std_vector_lepton_eleIdVeto, &b_std_vector_lepton_eleIdVeto);
   fChain->SetBranchAddress("std_vector_lepton_eta", &std_vector_lepton_eta, &b_std_vector_lepton_eta);
   fChain->SetBranchAddress("std_vector_lepton_flavour", &std_vector_lepton_flavour, &b_std_vector_lepton_flavour);
   fChain->SetBranchAddress("std_vector_lepton_isMediumMuon", &std_vector_lepton_isMediumMuon, &b_std_vector_lepton_isMediumMuon);
   fChain->SetBranchAddress("std_vector_lepton_isTightMuon", &std_vector_lepton_isTightMuon, &b_std_vector_lepton_isTightMuon);
   fChain->SetBranchAddress("std_vector_lepton_isTrackerMuon", &std_vector_lepton_isTrackerMuon, &b_std_vector_lepton_isTrackerMuon);
   fChain->SetBranchAddress("std_vector_lepton_muSIP3D", &std_vector_lepton_muSIP3D, &b_std_vector_lepton_muSIP3D);
   fChain->SetBranchAddress("std_vector_lepton_neutralHadronIso", &std_vector_lepton_neutralHadronIso, &b_std_vector_lepton_neutralHadronIso);
   fChain->SetBranchAddress("std_vector_lepton_phi", &std_vector_lepton_phi, &b_std_vector_lepton_phi);
   fChain->SetBranchAddress("std_vector_lepton_photonIso", &std_vector_lepton_photonIso, &b_std_vector_lepton_photonIso);
   fChain->SetBranchAddress("std_vector_lepton_pt", &std_vector_lepton_pt, &b_std_vector_lepton_pt);
   fChain->SetBranchAddress("std_vector_lepton_sumPUPt", &std_vector_lepton_sumPUPt, &b_std_vector_lepton_sumPUPt);
   fChain->SetBranchAddress("std_vector_lepton_trackIso", &std_vector_lepton_trackIso, &b_std_vector_lepton_trackIso);
   fChain->SetBranchAddress("std_vector_muon_Chi2LocalPos", &std_vector_muon_Chi2LocalPos, &b_std_vector_muon_Chi2LocalPos);
   fChain->SetBranchAddress("std_vector_muon_NTkLayers", &std_vector_muon_NTkLayers, &b_std_vector_muon_NTkLayers);
   fChain->SetBranchAddress("std_vector_muon_NValidFractInTrk", &std_vector_muon_NValidFractInTrk, &b_std_vector_muon_NValidFractInTrk);
   fChain->SetBranchAddress("std_vector_muon_NValidHitsInTrk", &std_vector_muon_NValidHitsInTrk, &b_std_vector_muon_NValidHitsInTrk);
   fChain->SetBranchAddress("std_vector_muon_NValidHitsSATrk", &std_vector_muon_NValidHitsSATrk, &b_std_vector_muon_NValidHitsSATrk);
   fChain->SetBranchAddress("std_vector_muon_NValidPixelHitsInTrk", &std_vector_muon_NValidPixelHitsInTrk, &b_std_vector_muon_NValidPixelHitsInTrk);
   fChain->SetBranchAddress("std_vector_muon_NormChi2GTrk", &std_vector_muon_NormChi2GTrk, &b_std_vector_muon_NormChi2GTrk);
   fChain->SetBranchAddress("std_vector_muon_NumOfMatchedStations", &std_vector_muon_NumOfMatchedStations, &b_std_vector_muon_NumOfMatchedStations);
   fChain->SetBranchAddress("std_vector_muon_SegCompatibilty", &std_vector_muon_SegCompatibilty, &b_std_vector_muon_SegCompatibilty);
   fChain->SetBranchAddress("std_vector_muon_TrkKink", &std_vector_muon_TrkKink, &b_std_vector_muon_TrkKink);
   fChain->SetBranchAddress("std_vector_neutrinoGen_eta", &std_vector_neutrinoGen_eta, &b_std_vector_neutrinoGen_eta);
   fChain->SetBranchAddress("std_vector_neutrinoGen_isDirectPromptTauDecayProduct", &std_vector_neutrinoGen_isDirectPromptTauDecayProduct, &b_std_vector_neutrinoGen_isDirectPromptTauDecayProduct);
   fChain->SetBranchAddress("std_vector_neutrinoGen_isPrompt", &std_vector_neutrinoGen_isPrompt, &b_std_vector_neutrinoGen_isPrompt);
   fChain->SetBranchAddress("std_vector_neutrinoGen_phi", &std_vector_neutrinoGen_phi, &b_std_vector_neutrinoGen_phi);
   fChain->SetBranchAddress("std_vector_neutrinoGen_pid", &std_vector_neutrinoGen_pid, &b_std_vector_neutrinoGen_pid);
   fChain->SetBranchAddress("std_vector_neutrinoGen_pt", &std_vector_neutrinoGen_pt, &b_std_vector_neutrinoGen_pt);
   fChain->SetBranchAddress("std_vector_partonGen_eta", &std_vector_partonGen_eta, &b_std_vector_partonGen_eta);
   fChain->SetBranchAddress("std_vector_partonGen_isHardProcess", &std_vector_partonGen_isHardProcess, &b_std_vector_partonGen_isHardProcess);
   fChain->SetBranchAddress("std_vector_partonGen_isPrompt", &std_vector_partonGen_isPrompt, &b_std_vector_partonGen_isPrompt);
   fChain->SetBranchAddress("std_vector_partonGen_phi", &std_vector_partonGen_phi, &b_std_vector_partonGen_phi);
   fChain->SetBranchAddress("std_vector_partonGen_pid", &std_vector_partonGen_pid, &b_std_vector_partonGen_pid);
   fChain->SetBranchAddress("std_vector_partonGen_pt", &std_vector_partonGen_pt, &b_std_vector_partonGen_pt);
   fChain->SetBranchAddress("std_vector_photon_eta", &std_vector_photon_eta, &b_std_vector_photon_eta);
   fChain->SetBranchAddress("std_vector_photon_phi", &std_vector_photon_phi, &b_std_vector_photon_phi);
   fChain->SetBranchAddress("std_vector_photon_pt", &std_vector_photon_pt, &b_std_vector_photon_pt);
   fChain->SetBranchAddress("std_vector_photonid_eta", &std_vector_photonid_eta, &b_std_vector_photonid_eta);
   fChain->SetBranchAddress("std_vector_photonid_phi", &std_vector_photonid_phi, &b_std_vector_photonid_phi);
   fChain->SetBranchAddress("std_vector_photonid_pt", &std_vector_photonid_pt, &b_std_vector_photonid_pt);
   fChain->SetBranchAddress("std_vector_puppijet_eta", &std_vector_puppijet_eta, &b_std_vector_puppijet_eta);
   fChain->SetBranchAddress("std_vector_puppijet_phi", &std_vector_puppijet_phi, &b_std_vector_puppijet_phi);
   fChain->SetBranchAddress("std_vector_puppijet_pt", &std_vector_puppijet_pt, &b_std_vector_puppijet_pt);
   fChain->SetBranchAddress("std_vector_tau_eta", &std_vector_tau_eta, &b_std_vector_tau_eta);
   fChain->SetBranchAddress("std_vector_tau_phi", &std_vector_tau_phi, &b_std_vector_tau_phi);
   fChain->SetBranchAddress("std_vector_tau_pt", &std_vector_tau_pt, &b_std_vector_tau_pt);
   fChain->SetBranchAddress("std_vector_trigger_special", &std_vector_trigger_special, &b_std_vector_trigger_special);
   fChain->SetBranchAddress("tightmu", &tightmu, &b_tightmu);
   fChain->SetBranchAddress("triggW", &triggW, &b_triggW);
   fChain->SetBranchAddress("trigger", &trigger, &b_trigger);
   fChain->SetBranchAddress("triggerFakeRate", &triggerFakeRate, &b_triggerFakeRate);
   fChain->SetBranchAddress("itpu", &itpu, &b_itpu);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("ootpum1", &ootpum1, &b_ootpum1);
   fChain->SetBranchAddress("ootpum2", &ootpum2, &b_ootpum2);
   fChain->SetBranchAddress("ootpum3", &ootpum3, &b_ootpum3);
   fChain->SetBranchAddress("ootpum4", &ootpum4, &b_ootpum4);
   fChain->SetBranchAddress("ootpum5", &ootpum5, &b_ootpum5);
   fChain->SetBranchAddress("ootpup1", &ootpup1, &b_ootpup1);
   fChain->SetBranchAddress("ootpup2", &ootpup2, &b_ootpup2);
   fChain->SetBranchAddress("ootpup3", &ootpup3, &b_ootpup3);
   fChain->SetBranchAddress("trpu", &trpu, &b_trpu);
   fChain->SetBranchAddress("bveto_ip", &bveto_ip, &b_bveto_ip);
   Notify();
}

Bool_t HWWtestClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HWWtestClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HWWtestClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HWWtestClass_cxx
