#include "TCanvas.h"
#include "TFile.h"
#include "THStack.h"
#include "TH1F.h"
#include "TLatex.h"
#include "TSystem.h"
#include "TTree.h"
#include "TString.h"

// Settings
//------------------------------------------------------------------------------
TString  _channel;
TString  _format;
TString  _output;
Int_t    _njet;
Double_t _luminosity;
Bool_t   _dataDriven;
Bool_t   _setLogy;

const UInt_t nProcesses = 12;
enum {iData, iWW, iH125, iDY, iDYtau, itt, itW, iWZ, iZZ, iWg, iZgamma, iWj};




//------------------------------------------------------------------------------
// drawDistributions
//------------------------------------------------------------------------------
void drawGenRecon(Int_t    njet       = 0,
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

  //MakeDirectory();

  gStyle->SetHatchesLineWidth(1.00);
  gStyle->SetHatchesSpacing  (0.55);


  // Read input files
  //----------------------------------------------------------------------------
  TString path = Form("rootfiles/%djet/%s/", _njet, _channel.Data());

  TFile* input = new TFile("rootfiles/0jet/MuMu/WZ.root","read");
  TH1F* hist1;
  TH1F* hist2;
    hist1 = (TH1F*)input->Get("hInvDimu_Recon");
    hist2 = (TH1F*)input->Get("hInvDimu_Gen");
    hist1->SetName("WZJet");

  //TCanvas* canvas = new TCanvas(hname, hname, 550, 720);
  TCanvas* canvas = new TCanvas("InvDimu", "InvDimu", 800, 800);

    
    
      //hist[ip]->SetFillColor(color[ip]);
      //hist[ip]->SetFillStyle(1001);
      hist1->SetLineColor(kBlue);
      hist2->SetLineColor(kRed);




  hist1->Draw("");
  hist2->Draw("histsame");

  TLegend *myLeg= new TLegend(0.6,0.7,0.9,0.9);
  myLeg->AddEntry(hist1,"recon","l");
  myLeg->AddEntry(hist2,"gen","l");
  myLeg->Draw();

  // Legend
  //----------------------------------------------------------------------------
  Double_t x0      = 0.720; 
  Double_t y0      = 0.834; 
  Double_t yoffset = 0.048;
  Double_t delta   = yoffset + 0.001;
  Double_t ndelta  = 0;

  ndelta = 0;

  //DrawLegend(x0 - 0.23, y0 - ndelta, hist1,   Form("Recon"),         "f",  0.03, 0.2, yoffset); ndelta += delta;
  //DrawLegend(x0 - 0.23, y0 - ndelta, hist2,   Form("Gen"),   "f",  0.03, 0.2, yoffset); ndelta += delta;

  canvas->SaveAs("WZJetDimu.pdf");


    //_setLogy    = false;

	
  //DrawNM1("hDeltaPhiLeptons", "#Delta#phi_{#font[12]{ll}}", -1, 1, "rad");
}

