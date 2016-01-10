#include "TCanvas.h"
#include "TFile.h"
#include "THStack.h"
#include "TH1F.h"
#include "TLatex.h"
#include "TSystem.h"
#include "TTree.h"
#include "TString.h"
#include "TLegend.h"

const UInt_t nProcesses = 12;

//enum {iData, iWW, iWZ, iZZ, iWg, itt, itW, iWj, iDY, iDYtau, iZgamma, iH125};
enum {iData, iWW, iH125, iDY, iDYtau, itt, itW, iWZ, iZZ, iWg, iZgamma, iWj};

TFile* input;

TString process[nProcesses];


Color_t color[nProcesses];


Double_t systError[nProcesses];


// syst. / yield for the 0-jet bin. These numbers are for the WW study. We need to calculate systematic uncertainty for the case ggH

// Settings
//------------------------------------------------------------------------------
TString  _channel;
TString  _format;
TString  _output;
Int_t    _njet;
Double_t _luminosity;
Bool_t   _dataDriven;
Bool_t   _setLogy;


// Scale factors
//------------------------------------------------------------------------------
// WW Scale factors
//Double_t ttScale[] = {1.10, 1.10, 1.10, 1.10};
//Double_t tWScale[] = {1.10, 1.10, 1.10, 1.10};
//Double_t WWScale[] = {1.00, 0.92, 1.02, 1.08};
//Double_t ZjScale[] = {3.70, 4.20, 1.80, 4.00};

//ggH Scale factors: 0- and 1-jet bins
//Double_t ttScale[] = {1.11, 1.11}; // from khakim
//Double_t tWScale[] = {1.11, 1.11}; // from khakim
//Double_t ttScale[] = {1.0,  1.0};
//Double_t tWScale[] = {1.0,  1.0};
//
//Double_t ttScale[] = {0.967,  1.055};
//Double_t tWScale[] = {0.967,  1.055};
//Double_t WWScale[] = {1.08, 1.02};
//Double_t ZjScale[] = {4.59, 3.03};
//SangEun Oct13 2015
//Double_t ttScale[] = {0.94,  0.945};//nobveto tche
Double_t ttScale[] = {0.94,  0.975}; //tche
Double_t tWScale[] = {0.96,  0.95};
Double_t WWScale[] = {1.04, 0.95};
Double_t ZjScale[] = {3.43, 2.62};

// Levels
//------------------------------------------------------------------------------
const UInt_t nLevels = 11;

enum {
  Trigger,
  MetCut,
  LowMinv,
  ZVeto,
  pMetCut,
  JetVeto,
  DeltaPhiJet,
  SoftMuVeto,
  ExtraLepton,
  Ptll,
  TopTagging
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
  "Ptll",
  "TopTagging"
};

const TString NM1Label[nLevels] = {
  "",
  "(no loose MET cut) ",
  "(no low m_{#font[12]{ll}} cut) ",
  "(no Z veto) ",
  "(no minmet cut) ",
  "(no jet veto) ",
  "(no #Delta#phi_{#font[12]{ll}} cut) ",
  "(no soft #mu veto) ",
  "(no extra lepton veto) ",
  "(no p_{T}^{#font[12]{ll}} cut) ",
  "(no top veto) "
};


//------------------------------------------------------------------------------
// drawDistributions
//------------------------------------------------------------------------------
void drawDistributions(Int_t    njet       = 0,
		       TString  channel    = "All",
		       Double_t luminosity = 19365,
		       TString  format     = "png",
		       Bool_t   drawRatio  = true,
		       Bool_t   dataDriven = true,
		       Bool_t   setLogy    = false)
{
  _channel    = channel;
  _njet       = njet;
  _luminosity = luminosity;
  _format     = format;
  _dataDriven = dataDriven;
  _setLogy    = setLogy;

  gStyle->SetHatchesLineWidth(1.00);
  gStyle->SetHatchesSpacing  (0.55);


  // Read input files
  //----------------------------------------------------------------------------
  TCanvas* canvas = new TCanvas();
  gStyle      ->SetOptStat  (0);
  input = new TFile("rootfiles/0jet/MuMu/Test.root", "read");
  TH1D* h_metPfType1 = (TH1D*) input->Get("h_metPfType1");
  TH1D* h_metPfType1ElecDn = (TH1D*) input->Get("h_metPfType1ElecDn");
  TH1D* h_metPfType1ElecUp = (TH1D*) input->Get("h_metPfType1ElecUp");
  TH1D* h_metPfType1MuonDn = (TH1D*) input->Get("h_metPfType1MuonDn");
  TH1D* h_metPfType1MuonUp = (TH1D*) input->Get("h_metPfType1MuonUp");
  TH1D* h_metPfType1JetDn = (TH1D*) input->Get("h_metPfType1JetDn");
  TH1D* h_metPfType1JetUp = (TH1D*) input->Get("h_metPfType1JetUp");

  h_metPfType1->SetTitle("");
  h_metPfType1JetUp->SetTitle("");
  //h_metPfType1->SetFillColor(kBlack);
  h_metPfType1->SetLineColor(kBlack);
  h_metPfType1ElecDn->SetLineColor(kRed);
  h_metPfType1ElecUp->SetLineColor(kRed+2);
  h_metPfType1MuonDn->SetLineColor(kBlue);
  h_metPfType1MuonUp->SetLineColor(kBlue+2);
  h_metPfType1JetDn->SetLineColor(kGreen);
  h_metPfType1JetUp->SetLineColor(kGreen+2);

  //h_metPfType1JetUp->SetMaximum(300);
  h_metPfType1JetUp->Draw();
  h_metPfType1->Draw("same");
  h_metPfType1ElecDn->Draw("same");
  h_metPfType1ElecUp->Draw("same");
  h_metPfType1MuonUp->Draw("same");
  h_metPfType1MuonDn->Draw("same");
  h_metPfType1JetDn->Draw("same");

  TLegend *myLeg = new TLegend(0.6,0.6,0.9,0.9);
  myLeg->AddEntry(h_metPfType1,"metPfType1","l");
  myLeg->AddEntry(h_metPfType1ElecDn,"metPfType1ElecDn","l");
  myLeg->AddEntry(h_metPfType1ElecUp,"metPfType1ElecUp","l");
  myLeg->AddEntry(h_metPfType1MuonDn,"metPfType1MuonDn","l");
  myLeg->AddEntry(h_metPfType1MuonUp,"metPfType1MuonUp","l");
  myLeg->AddEntry(h_metPfType1JetDn,"metPfType1JetDn","l");
  myLeg->AddEntry(h_metPfType1JetUp,"metPfType1JetUp","l");
  myLeg->Draw();
  canvas->SaveAs("met.pdf");




}

