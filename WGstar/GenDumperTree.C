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

const Double_t ZMASS = 91.1876;  // GeV


// Member functions
//------------------------------------------------------------------------------
void    FillHistograms(UInt_t level,
		UInt_t check);


// Data members
//------------------------------------------------------------------------------

Float_t totalW;
double M_Muon(0.105);

// Tree variables
//------------------------------------------------------------------------------
   Float_t weightNominalLHE;
   Float_t m2MuFromZorGstar;
   Float_t ZGstarMu1_pt;
   Float_t ZGstarMu1_eta;
   Float_t ZGstarMu1_phi;
   Float_t ZGstarMu2_pt;
   Float_t ZGstarMu2_eta;
   Float_t ZGstarMu2_phi;
   Float_t ZGstarDimu_DelaR;
   //vector<float>   *std_vector_lepton_pt;

//------------------------------------------------------------------------------
// LatinosTreeScript
//------------------------------------------------------------------------------
void GenDumperTree(Float_t luminosity,
		Int_t   jetChannel,
		TString flavorChannel,
		TString theSample,
		Bool_t  GEnStudy,
		Bool_t  verbose)
{
  TH1::SetDefaultSumw2();

  
  TString path = Form("GenDumperRoot/%djet/%s/", jetChannel, flavorChannel.Data());
  
  gSystem->mkdir(path, kTRUE);
  
  TFile* output = new TFile(path + theSample + ".root", "recreate");
  //TString NameFout=path + theSample +".txt";
  //ofstream Fout(NameFout);
  //
  //-------------------------------------------------------------------
  // Histograms
  //----------------------------------------------------------------------------
  
  TH1D*   hMmumu = new TH1D("hMmumu","hMmumu",50,0,15);    ;
  
  
  
  
  TString filesPath = "/u/user/salee/Latino/CMSSW7414_WgStar/src/LatinoTreesGEN/GenDumper/test/BatchJob/";
  
  TChain* tree = new TChain("Analyzer/myTree", "Analyzer/myTree");

  	//tree->Add(filesPath +  "latino_Run2015D_05Oct2015_SingleMuon_0000__part0.root");
        tree->Add(filesPath + "WZJets_13TeV_0.root");
        tree->Add(filesPath + "WZJets_13TeV_100.root");
        tree->Add(filesPath + "WZJets_13TeV_101.root");
        tree->Add(filesPath + "WZJets_13TeV_102.root");
        tree->Add(filesPath + "WZJets_13TeV_103.root");
        tree->Add(filesPath + "WZJets_13TeV_104.root");
        tree->Add(filesPath + "WZJets_13TeV_105.root");
        tree->Add(filesPath + "WZJets_13TeV_106.root");
        tree->Add(filesPath + "WZJets_13TeV_107.root");
        tree->Add(filesPath + "WZJets_13TeV_108.root");
        tree->Add(filesPath + "WZJets_13TeV_109.root");
        tree->Add(filesPath + "WZJets_13TeV_10.root");
        tree->Add(filesPath + "WZJets_13TeV_110.root");
        tree->Add(filesPath + "WZJets_13TeV_111.root");
        tree->Add(filesPath + "WZJets_13TeV_112.root");
        tree->Add(filesPath + "WZJets_13TeV_113.root");
        tree->Add(filesPath + "WZJets_13TeV_114.root");
        tree->Add(filesPath + "WZJets_13TeV_115.root");
        tree->Add(filesPath + "WZJets_13TeV_116.root");
        tree->Add(filesPath + "WZJets_13TeV_117.root");
        tree->Add(filesPath + "WZJets_13TeV_118.root");
        tree->Add(filesPath + "WZJets_13TeV_119.root");
        tree->Add(filesPath + "WZJets_13TeV_11.root");
        tree->Add(filesPath + "WZJets_13TeV_120.root");
        tree->Add(filesPath + "WZJets_13TeV_121.root");
        tree->Add(filesPath + "WZJets_13TeV_122.root");
        tree->Add(filesPath + "WZJets_13TeV_123.root");
        tree->Add(filesPath + "WZJets_13TeV_124.root");
        tree->Add(filesPath + "WZJets_13TeV_125.root");
        tree->Add(filesPath + "WZJets_13TeV_126.root");
        tree->Add(filesPath + "WZJets_13TeV_127.root");
        tree->Add(filesPath + "WZJets_13TeV_128.root");
        tree->Add(filesPath + "WZJets_13TeV_129.root");
        tree->Add(filesPath + "WZJets_13TeV_12.root");
        tree->Add(filesPath + "WZJets_13TeV_130.root");
        tree->Add(filesPath + "WZJets_13TeV_131.root");
        tree->Add(filesPath + "WZJets_13TeV_132.root");
        tree->Add(filesPath + "WZJets_13TeV_133.root");
        tree->Add(filesPath + "WZJets_13TeV_134.root");
        tree->Add(filesPath + "WZJets_13TeV_135.root");
        tree->Add(filesPath + "WZJets_13TeV_136.root");
        tree->Add(filesPath + "WZJets_13TeV_137.root");
        tree->Add(filesPath + "WZJets_13TeV_138.root");
        tree->Add(filesPath + "WZJets_13TeV_139.root");
        tree->Add(filesPath + "WZJets_13TeV_13.root");
        tree->Add(filesPath + "WZJets_13TeV_140.root");
        tree->Add(filesPath + "WZJets_13TeV_141.root");
        tree->Add(filesPath + "WZJets_13TeV_142.root");
        tree->Add(filesPath + "WZJets_13TeV_143.root");
        tree->Add(filesPath + "WZJets_13TeV_144.root");
        tree->Add(filesPath + "WZJets_13TeV_145.root");
        tree->Add(filesPath + "WZJets_13TeV_146.root");
        tree->Add(filesPath + "WZJets_13TeV_147.root");
        tree->Add(filesPath + "WZJets_13TeV_148.root");
        tree->Add(filesPath + "WZJets_13TeV_149.root");
        tree->Add(filesPath + "WZJets_13TeV_14.root");
        tree->Add(filesPath + "WZJets_13TeV_150.root");
        tree->Add(filesPath + "WZJets_13TeV_151.root");
        tree->Add(filesPath + "WZJets_13TeV_152.root");
        tree->Add(filesPath + "WZJets_13TeV_153.root");
        tree->Add(filesPath + "WZJets_13TeV_154.root");
        tree->Add(filesPath + "WZJets_13TeV_155.root");
        tree->Add(filesPath + "WZJets_13TeV_156.root");
        tree->Add(filesPath + "WZJets_13TeV_157.root");
        tree->Add(filesPath + "WZJets_13TeV_158.root");
        tree->Add(filesPath + "WZJets_13TeV_159.root");
        tree->Add(filesPath + "WZJets_13TeV_15.root");
        tree->Add(filesPath + "WZJets_13TeV_160.root");
        tree->Add(filesPath + "WZJets_13TeV_161.root");
        tree->Add(filesPath + "WZJets_13TeV_162.root");
        tree->Add(filesPath + "WZJets_13TeV_163.root");
        tree->Add(filesPath + "WZJets_13TeV_164.root");
        tree->Add(filesPath + "WZJets_13TeV_165.root");
        tree->Add(filesPath + "WZJets_13TeV_166.root");
        tree->Add(filesPath + "WZJets_13TeV_167.root");
        tree->Add(filesPath + "WZJets_13TeV_168.root");
        tree->Add(filesPath + "WZJets_13TeV_169.root");
        tree->Add(filesPath + "WZJets_13TeV_16.root");
        tree->Add(filesPath + "WZJets_13TeV_170.root");
        tree->Add(filesPath + "WZJets_13TeV_171.root");
        tree->Add(filesPath + "WZJets_13TeV_172.root");
        tree->Add(filesPath + "WZJets_13TeV_173.root");
        tree->Add(filesPath + "WZJets_13TeV_174.root");
        tree->Add(filesPath + "WZJets_13TeV_175.root");
        tree->Add(filesPath + "WZJets_13TeV_176.root");
        tree->Add(filesPath + "WZJets_13TeV_177.root");
        tree->Add(filesPath + "WZJets_13TeV_178.root");
        tree->Add(filesPath + "WZJets_13TeV_179.root");
        tree->Add(filesPath + "WZJets_13TeV_17.root");
        tree->Add(filesPath + "WZJets_13TeV_180.root");
        tree->Add(filesPath + "WZJets_13TeV_181.root");
        tree->Add(filesPath + "WZJets_13TeV_182.root");
        tree->Add(filesPath + "WZJets_13TeV_183.root");
        tree->Add(filesPath + "WZJets_13TeV_184.root");
        tree->Add(filesPath + "WZJets_13TeV_185.root");
        tree->Add(filesPath + "WZJets_13TeV_186.root");
        tree->Add(filesPath + "WZJets_13TeV_187.root");
        tree->Add(filesPath + "WZJets_13TeV_188.root");
        tree->Add(filesPath + "WZJets_13TeV_189.root");
        tree->Add(filesPath + "WZJets_13TeV_18.root");
        tree->Add(filesPath + "WZJets_13TeV_190.root");
        tree->Add(filesPath + "WZJets_13TeV_191.root");
        tree->Add(filesPath + "WZJets_13TeV_192.root");
        tree->Add(filesPath + "WZJets_13TeV_193.root");
        tree->Add(filesPath + "WZJets_13TeV_194.root");
        tree->Add(filesPath + "WZJets_13TeV_195.root");
        tree->Add(filesPath + "WZJets_13TeV_196.root");
        tree->Add(filesPath + "WZJets_13TeV_197.root");
        tree->Add(filesPath + "WZJets_13TeV_198.root");
        tree->Add(filesPath + "WZJets_13TeV_199.root");
        tree->Add(filesPath + "WZJets_13TeV_19.root");
        tree->Add(filesPath + "WZJets_13TeV_1.root");
        tree->Add(filesPath + "WZJets_13TeV_200.root");
        tree->Add(filesPath + "WZJets_13TeV_201.root");
        tree->Add(filesPath + "WZJets_13TeV_202.root");
        tree->Add(filesPath + "WZJets_13TeV_203.root");
        tree->Add(filesPath + "WZJets_13TeV_204.root");
        tree->Add(filesPath + "WZJets_13TeV_205.root");
        tree->Add(filesPath + "WZJets_13TeV_206.root");
        tree->Add(filesPath + "WZJets_13TeV_207.root");
        tree->Add(filesPath + "WZJets_13TeV_208.root");
        tree->Add(filesPath + "WZJets_13TeV_209.root");
        tree->Add(filesPath + "WZJets_13TeV_20.root");
        tree->Add(filesPath + "WZJets_13TeV_210.root");
        tree->Add(filesPath + "WZJets_13TeV_211.root");
        tree->Add(filesPath + "WZJets_13TeV_212.root");
        tree->Add(filesPath + "WZJets_13TeV_213.root");
        tree->Add(filesPath + "WZJets_13TeV_214.root");
        tree->Add(filesPath + "WZJets_13TeV_215.root");
        tree->Add(filesPath + "WZJets_13TeV_216.root");
        tree->Add(filesPath + "WZJets_13TeV_217.root");
        tree->Add(filesPath + "WZJets_13TeV_218.root");
        tree->Add(filesPath + "WZJets_13TeV_219.root");
        tree->Add(filesPath + "WZJets_13TeV_21.root");
        tree->Add(filesPath + "WZJets_13TeV_220.root");
        tree->Add(filesPath + "WZJets_13TeV_221.root");
        tree->Add(filesPath + "WZJets_13TeV_222.root");
        tree->Add(filesPath + "WZJets_13TeV_223.root");
        tree->Add(filesPath + "WZJets_13TeV_224.root");
        tree->Add(filesPath + "WZJets_13TeV_225.root");
        tree->Add(filesPath + "WZJets_13TeV_226.root");
        tree->Add(filesPath + "WZJets_13TeV_227.root");
        tree->Add(filesPath + "WZJets_13TeV_228.root");
        tree->Add(filesPath + "WZJets_13TeV_229.root");
        tree->Add(filesPath + "WZJets_13TeV_22.root");
        tree->Add(filesPath + "WZJets_13TeV_230.root");
        tree->Add(filesPath + "WZJets_13TeV_231.root");
        tree->Add(filesPath + "WZJets_13TeV_232.root");
        tree->Add(filesPath + "WZJets_13TeV_233.root");
        tree->Add(filesPath + "WZJets_13TeV_234.root");
        tree->Add(filesPath + "WZJets_13TeV_235.root");
        tree->Add(filesPath + "WZJets_13TeV_236.root");
        tree->Add(filesPath + "WZJets_13TeV_237.root");
        tree->Add(filesPath + "WZJets_13TeV_238.root");
        tree->Add(filesPath + "WZJets_13TeV_239.root");
        tree->Add(filesPath + "WZJets_13TeV_23.root");
        tree->Add(filesPath + "WZJets_13TeV_240.root");
        tree->Add(filesPath + "WZJets_13TeV_241.root");
        tree->Add(filesPath + "WZJets_13TeV_242.root");
        tree->Add(filesPath + "WZJets_13TeV_243.root");
        tree->Add(filesPath + "WZJets_13TeV_244.root");
        tree->Add(filesPath + "WZJets_13TeV_245.root");
        tree->Add(filesPath + "WZJets_13TeV_246.root");
        tree->Add(filesPath + "WZJets_13TeV_247.root");
        tree->Add(filesPath + "WZJets_13TeV_248.root");
        tree->Add(filesPath + "WZJets_13TeV_249.root");
        tree->Add(filesPath + "WZJets_13TeV_24.root");
        tree->Add(filesPath + "WZJets_13TeV_250.root");
        tree->Add(filesPath + "WZJets_13TeV_251.root");
        tree->Add(filesPath + "WZJets_13TeV_252.root");
        tree->Add(filesPath + "WZJets_13TeV_253.root");
        tree->Add(filesPath + "WZJets_13TeV_254.root");
        tree->Add(filesPath + "WZJets_13TeV_255.root");
        tree->Add(filesPath + "WZJets_13TeV_256.root");
        tree->Add(filesPath + "WZJets_13TeV_257.root");
        tree->Add(filesPath + "WZJets_13TeV_258.root");
        tree->Add(filesPath + "WZJets_13TeV_259.root");
        tree->Add(filesPath + "WZJets_13TeV_25.root");
        tree->Add(filesPath + "WZJets_13TeV_260.root");
        tree->Add(filesPath + "WZJets_13TeV_261.root");
        tree->Add(filesPath + "WZJets_13TeV_262.root");
        tree->Add(filesPath + "WZJets_13TeV_263.root");
        tree->Add(filesPath + "WZJets_13TeV_264.root");
        tree->Add(filesPath + "WZJets_13TeV_265.root");
        tree->Add(filesPath + "WZJets_13TeV_266.root");
        tree->Add(filesPath + "WZJets_13TeV_267.root");
        tree->Add(filesPath + "WZJets_13TeV_268.root");
        tree->Add(filesPath + "WZJets_13TeV_269.root");
        tree->Add(filesPath + "WZJets_13TeV_26.root");
        tree->Add(filesPath + "WZJets_13TeV_270.root");
        tree->Add(filesPath + "WZJets_13TeV_271.root");
        tree->Add(filesPath + "WZJets_13TeV_272.root");
        tree->Add(filesPath + "WZJets_13TeV_273.root");
        tree->Add(filesPath + "WZJets_13TeV_274.root");
        tree->Add(filesPath + "WZJets_13TeV_275.root");
        tree->Add(filesPath + "WZJets_13TeV_276.root");
        tree->Add(filesPath + "WZJets_13TeV_277.root");
        tree->Add(filesPath + "WZJets_13TeV_278.root");
        tree->Add(filesPath + "WZJets_13TeV_279.root");
        tree->Add(filesPath + "WZJets_13TeV_27.root");
        tree->Add(filesPath + "WZJets_13TeV_280.root");
        tree->Add(filesPath + "WZJets_13TeV_281.root");
        tree->Add(filesPath + "WZJets_13TeV_282.root");
        tree->Add(filesPath + "WZJets_13TeV_283.root");
        tree->Add(filesPath + "WZJets_13TeV_284.root");
        tree->Add(filesPath + "WZJets_13TeV_285.root");
        tree->Add(filesPath + "WZJets_13TeV_286.root");
        tree->Add(filesPath + "WZJets_13TeV_287.root");
        tree->Add(filesPath + "WZJets_13TeV_288.root");
        tree->Add(filesPath + "WZJets_13TeV_289.root");
        tree->Add(filesPath + "WZJets_13TeV_28.root");
        tree->Add(filesPath + "WZJets_13TeV_290.root");
        tree->Add(filesPath + "WZJets_13TeV_291.root");
        tree->Add(filesPath + "WZJets_13TeV_292.root");
        tree->Add(filesPath + "WZJets_13TeV_293.root");
        tree->Add(filesPath + "WZJets_13TeV_294.root");
        tree->Add(filesPath + "WZJets_13TeV_295.root");
        tree->Add(filesPath + "WZJets_13TeV_296.root");
        tree->Add(filesPath + "WZJets_13TeV_297.root");
        tree->Add(filesPath + "WZJets_13TeV_298.root");
        tree->Add(filesPath + "WZJets_13TeV_299.root");
        tree->Add(filesPath + "WZJets_13TeV_29.root");
        tree->Add(filesPath + "WZJets_13TeV_2.root");
        tree->Add(filesPath + "WZJets_13TeV_300.root");
        tree->Add(filesPath + "WZJets_13TeV_301.root");
        tree->Add(filesPath + "WZJets_13TeV_30.root");
        tree->Add(filesPath + "WZJets_13TeV_31.root");
        tree->Add(filesPath + "WZJets_13TeV_32.root");
        tree->Add(filesPath + "WZJets_13TeV_33.root");
        tree->Add(filesPath + "WZJets_13TeV_34.root");
        tree->Add(filesPath + "WZJets_13TeV_35.root");
        tree->Add(filesPath + "WZJets_13TeV_36.root");
        tree->Add(filesPath + "WZJets_13TeV_37.root");
        tree->Add(filesPath + "WZJets_13TeV_38.root");
        tree->Add(filesPath + "WZJets_13TeV_39.root");
        tree->Add(filesPath + "WZJets_13TeV_3.root");
        tree->Add(filesPath + "WZJets_13TeV_40.root");
        tree->Add(filesPath + "WZJets_13TeV_41.root");
        tree->Add(filesPath + "WZJets_13TeV_42.root");
        tree->Add(filesPath + "WZJets_13TeV_43.root");
        tree->Add(filesPath + "WZJets_13TeV_44.root");
        tree->Add(filesPath + "WZJets_13TeV_45.root");
        tree->Add(filesPath + "WZJets_13TeV_46.root");
        tree->Add(filesPath + "WZJets_13TeV_47.root");
        tree->Add(filesPath + "WZJets_13TeV_48.root");
        tree->Add(filesPath + "WZJets_13TeV_49.root");
        tree->Add(filesPath + "WZJets_13TeV_4.root");
        tree->Add(filesPath + "WZJets_13TeV_50.root");
        tree->Add(filesPath + "WZJets_13TeV_51.root");
        tree->Add(filesPath + "WZJets_13TeV_52.root");
        tree->Add(filesPath + "WZJets_13TeV_53.root");
        tree->Add(filesPath + "WZJets_13TeV_54.root");
        tree->Add(filesPath + "WZJets_13TeV_55.root");
        tree->Add(filesPath + "WZJets_13TeV_56.root");
        tree->Add(filesPath + "WZJets_13TeV_57.root");
        tree->Add(filesPath + "WZJets_13TeV_58.root");
        tree->Add(filesPath + "WZJets_13TeV_59.root");
        tree->Add(filesPath + "WZJets_13TeV_5.root");
        tree->Add(filesPath + "WZJets_13TeV_60.root");
        tree->Add(filesPath + "WZJets_13TeV_61.root");
        tree->Add(filesPath + "WZJets_13TeV_62.root");
        tree->Add(filesPath + "WZJets_13TeV_63.root");
        tree->Add(filesPath + "WZJets_13TeV_64.root");
        tree->Add(filesPath + "WZJets_13TeV_65.root");
        tree->Add(filesPath + "WZJets_13TeV_66.root");
        tree->Add(filesPath + "WZJets_13TeV_67.root");
        tree->Add(filesPath + "WZJets_13TeV_68.root");
        tree->Add(filesPath + "WZJets_13TeV_69.root");
        tree->Add(filesPath + "WZJets_13TeV_6.root");
        tree->Add(filesPath + "WZJets_13TeV_70.root");
        tree->Add(filesPath + "WZJets_13TeV_71.root");
        tree->Add(filesPath + "WZJets_13TeV_72.root");
        tree->Add(filesPath + "WZJets_13TeV_73.root");
        tree->Add(filesPath + "WZJets_13TeV_74.root");
        tree->Add(filesPath + "WZJets_13TeV_75.root");
        tree->Add(filesPath + "WZJets_13TeV_76.root");
        tree->Add(filesPath + "WZJets_13TeV_77.root");
        tree->Add(filesPath + "WZJets_13TeV_78.root");
        tree->Add(filesPath + "WZJets_13TeV_79.root");
        tree->Add(filesPath + "WZJets_13TeV_7.root");
        tree->Add(filesPath + "WZJets_13TeV_80.root");
        tree->Add(filesPath + "WZJets_13TeV_81.root");
        tree->Add(filesPath + "WZJets_13TeV_82.root");
        tree->Add(filesPath + "WZJets_13TeV_83.root");
        tree->Add(filesPath + "WZJets_13TeV_84.root");
        tree->Add(filesPath + "WZJets_13TeV_85.root");
        tree->Add(filesPath + "WZJets_13TeV_86.root");
        tree->Add(filesPath + "WZJets_13TeV_87.root");
        tree->Add(filesPath + "WZJets_13TeV_88.root");
        tree->Add(filesPath + "WZJets_13TeV_89.root");
        tree->Add(filesPath + "WZJets_13TeV_8.root");
        tree->Add(filesPath + "WZJets_13TeV_90.root");
        tree->Add(filesPath + "WZJets_13TeV_91.root");
        tree->Add(filesPath + "WZJets_13TeV_92.root");
        tree->Add(filesPath + "WZJets_13TeV_93.root");
        tree->Add(filesPath + "WZJets_13TeV_94.root");
        tree->Add(filesPath + "WZJets_13TeV_95.root");
        tree->Add(filesPath + "WZJets_13TeV_96.root");
        tree->Add(filesPath + "WZJets_13TeV_97.root");
        tree->Add(filesPath + "WZJets_13TeV_98.root");
        tree->Add(filesPath + "WZJets_13TeV_99.root");
        tree->Add(filesPath + "WZJets_13TeV_9.root");

  // Declaration of leaf types
  //----------------------------------------------------------------------------
  tree->SetBranchAddress("weightNominalLHE",        &weightNominalLHE);
  tree->SetBranchAddress("m2MuFromZorGstar",        &m2MuFromZorGstar);
  tree->SetBranchAddress("ZGstarMu1_pt",        &ZGstarMu1_pt);
  tree->SetBranchAddress("ZGstarMu1_eta",       &ZGstarMu1_eta);
  tree->SetBranchAddress("ZGstarMu1_phi",       &ZGstarMu1_phi);
  tree->SetBranchAddress("ZGstarMu2_pt",        &ZGstarMu2_pt);
  tree->SetBranchAddress("ZGstarMu2_eta",       &ZGstarMu2_eta);
  tree->SetBranchAddress("ZGstarMu2_phi",       &ZGstarMu2_phi);
  tree->SetBranchAddress("ZGstarDimu_DeltaR",   &ZGstarDimu_DeltaR);
 
  //-----------------------------------------------
  // Loop
  //-----------------------------------------------
  int TotNtry=tree->GetEntries();
  //TotNtry=50;
  
  for (int ievent=0; ievent<TotNtry; ievent++) {

    // initialize
    // dump variable
    tree->GetEntry(ievent);
  }

  // Save the histograms
  //----------------------------------------------
}

