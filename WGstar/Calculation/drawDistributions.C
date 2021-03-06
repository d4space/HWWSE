#include "TCanvas.h"
#include "TFile.h"
#include "THStack.h"
#include "TH1F.h"
#include "TLatex.h"
#include "TSystem.h"
#include "TTree.h"
#include "TString.h"
#include "draw/draw.h"

const UInt_t nProcesses = 14;

//enum {iData, iWW, iWZ, iZZ, iWg, itt, itW, iWj, iDY, iDYtau, iZgamma, iH125};
enum {iData, iWW, iH125, iDY, iDYtau, itt, itW, iWZ, iZZ, iWg,iWgSMu, iWgSEl, iZgamma, iWj};

TFile* input[nProcesses];

TString process[nProcesses];



Color_t color[nProcesses];



Double_t systError[nProcesses];




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
Double_t ttScale[] = {1, 1}; //tche
Double_t tWScale[] = {1, 1};
Double_t WWScale[] = {1, 1};
Double_t ZjScale[] = {1, 1};

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

void MakeDirectory();
void DrawHistogram(TString  hname,TString xtitle,Int_t ngroup,Int_t precision, TString units,Double_t xmin, Double_t xmax,Bool_t moveOverflow);
void MoveOverflowBins(TH1* h, Double_t xmin,Double_t xmax);
void ZeroOutOfRangeBins(TH1* h, Double_t xmin, Double_t xmax);
Float_t GetMaximumIncludingErrors(TH1F*    h,Double_t xmin,Double_t xmax);
Double_t Yield(TH1* h);
void DrawTLatex(Double_t x,Double_t y,Double_t tsize,Short_t align,const char* text,Bool_t setndc);
void SetAxis(TH1* hist,TString xtitle,TString ytitle,Float_t size,Float_t offset);

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

  process[iData]   = "DataRun2015";
  process[itt]     = "TTbar";
  process[itW]     = "TW";
  process[iWW]     = "WWTo2L2Nu";
  process[iWZ]     = "WZ3LNu";
  //process[iWZ]     = "WZ";
  process[iZZ]     = "ZZ";
  process[iWg]     = "WgammaNoStar";
  process[iWgSMu]  = "WgammaStarToLNuMuMu";
  process[iWgSEl]  = "WgammaStarToLNuEE";
  process[iWj]     = "WJetsLNu";
  process[iDY]     = "DY";
  process[iDYtau]  = "DYtautau";
  process[iZgamma] = "Zgamma";
  process[iH125]   = "HWW125";


  color[iData]   = kBlack;
  color[itt]     = kYellow;
  color[itW]     = kYellow-2;
  color[iWW]     = kAzure-9;
  color[iWZ]     = kAzure;
  color[iZZ]     = kBlack;
  color[iWg]     = kViolet;
  color[iWgSMu]  = kAzure-2;
  color[iWgSEl]  = kPink;
  color[iWj]     = kGray+1;
  color[iDY]     = kGreen+3;
  color[iDYtau]  = kGreen-4;
  color[iZgamma] = kGreen-6;
  color[iH125]   = kRed;

  systError[iData] = 0.0;
// syst. / yield for the 0-jet bin. These numbers are for the WW study. We need to calculate systematic uncertainty for the case ggH
  systError[itt]     = 21.7 / 166.0;
  systError[itW]     = 21.7 / 166.0;
  systError[iWW]     = 67.7 / 939.5;
  systError[iWZ]     =  3.3 /  41.2;
  systError[iZZ]     =  3.3 /  41.2;
  systError[iWg]     =  6.1 /  19.3;
  systError[iWj]     = 36.9 / 102.5;
  systError[iDY]     =  9.8 /  58.2;
  systError[iDYtau]  =  9.8 /  58.2;
  systError[iZgamma] =  2.7 /  36.1;
  systError[iH125]   =  2.7 /  36.1;

  MakeDirectory();

  gStyle->SetHatchesLineWidth(1.00);
  gStyle->SetHatchesSpacing  (0.55);


  // Read input files
  //----------------------------------------------------------------------------
  TString path_MC   = Form("../MakeHisto/rootfiles/%djet/%s/", _njet, _channel.Data());
  TString path_Data = Form("../MakeHisto/rootfiles/%djet/%s/", _njet, _channel.Data());
  //TString path_MC   = Form("rootfiles_WgIso_mll_110_met25pt30103/%djet/%s/", _njet, _channel.Data());
  //TString path_Data = Form("rootfiles_WgIso_mll_110_met25pt30103/%djet/%s/", _njet, _channel.Data());
  //TString path_MC   = Form("rootfiles_LeptIDbyGstar_mll_110_met25pt30tight103/%djet/%s/", _njet, _channel.Data());
  //TString path_Data = Form("rootfiles_LeptIDbyGstar_mll_110_met25pt30tight103/%djet/%s/", _njet, _channel.Data());
  //TString path_MC   = Form("rootfiles_LeptIDbyGstar_mll_110_met25pt30103/%djet/%s/", _njet, _channel.Data());
  //TString path_Data = Form("rootfiles_LeptIDbyGstar_mll_110_met25pt30103/%djet/%s/", _njet, _channel.Data());
  //TString path_MC   = Form("rootfiles_MC/%djet/%s/", _njet, _channel.Data());
  //TString path_Data = Form("rootfiles/%djet/%s/", _njet, _channel.Data());

  for (UInt_t ip=0; ip<nProcesses; ip++)
  {
    if(ip == iData){
      input[ip] = new TFile(path_Data + process[ip] + ".root", "read");
    }else{
      input[ip] = new TFile(path_MC + process[ip] + ".root", "read");
    }
  }


  DrawHistogram("hInvDimu_Recon",  "m_{#font[12]{ll}}", 1, 0, "GeV",0, 110,false);


}


//------------------------------------------------------------------------------
// MakeDirectory
//------------------------------------------------------------------------------
void MakeDirectory()
{
  if( _njet == 10){
    _output = Form("%s/0plus1jet/%s", _format.Data(), _channel.Data());
  }else  _output = Form("%s/%djet/%s", _format.Data(), _njet, _channel.Data());

  gSystem->Exec(Form("rm -rf %s", _output.Data()));

  gSystem->mkdir(_output, kTRUE);

  //gSystem->Exec(Form("cp index.php %s/.", _format.Data()));

  //gSystem->Exec(Form("cp index.php %s/%djet/.", _format.Data(), _njet));

  //gSystem->Exec(Form("cp index.php %s/.", _output.Data()));
}


//------------------------------------------------------------------------------
// DrawNM1
//------------------------------------------------------------------------------
void DrawNM1(TString  hname,
	     TString  xtitle,
	     Int_t    ngroup       = -1,
	     Int_t    precision    = 1,
	     TString  units        = "NULL",
	     Double_t xmin         = -999,
	     Double_t xmax         =  999)
{
  for (UInt_t i=0; i<nLevels; i++)
    {
      if (hname.Contains("PtDiLepton") && !sLevel[i].Contains("Ptll"))    continue;
      if (hname.Contains("NJetsPF30")  && !sLevel[i].Contains("JetVeto")) continue;

      DrawHistogram(hname + sLevel[i] + "_NM1",
		    NM1Label[i] + xtitle,
		    ngroup,
		    precision,
		    units,
		    xmin,
		    xmax,
		    "");
    }
} 


//------------------------------------------------------------------------------
// DrawHistogram
//------------------------------------------------------------------------------
void DrawHistogram(TString  hname,
		   TString  xtitle,
		   Int_t    ngroup       = -1,
		   Int_t    precision    = 1,
		   TString  units        = "NULL",
		   Double_t xmin         = -999,
		   Double_t xmax         =  999,
		   Bool_t   moveOverflow = true)
{
  //TCanvas* canvas = new TCanvas(hname, hname, 550, 720);
  TCanvas* canvas = new TCanvas(hname, hname, 800, 800);

  TPad* pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  TPad* pad2 = new TPad("pad2", "pad2", 0, 0.0, 1, 0.3); 

  pad1->SetTopMargin   (0.08);
  pad1->SetBottomMargin(0.02);
  pad1->Draw();
      
  pad2->SetTopMargin   (0.08);
  pad2->SetBottomMargin(0.35);
  pad2->Draw();


  //----------------------------------------------------------------------------
  // pad1
  //----------------------------------------------------------------------------
  pad1->cd();

  pad1->SetLogy(_setLogy);

  THStack* hstack = new THStack(hname, hname);

  TH1F* hist[nProcesses];

  //Save histograms to root file
  TFile* outfile;
  //TString fname = Form("files/%s_%djet.root", hname.Data(),_njet);
  TString fname = "files/0jet_"+hname+".root";
  if(_njet==1) fname = "files/1jet_"+hname+".root";
  outfile = new TFile(fname, "create");
  
  TH1F* data;
  TH1F* top;
  TH1F* tW;
  TH1F* WW;
  TH1F* WZ;
  TH1F* ZZ;
  TH1F* Wg;
  TH1F* WgSMu;
  TH1F* WgSEl;
  TH1F* Wjets;
  TH1F* Zjets;
  TH1F* DYtau;
  TH1F* Zgamma;
  TH1F* ggH;



  
  for (UInt_t ip=0; ip<nProcesses; ip++) {

    hist[ip] = (TH1F*)input[ip]->Get(hname);
    hist[ip]->SetName(hname + process[ip]);
    hist[ip]->SetTitle("");

    if(ip == iData)   data   = (TH1F*)hist[iData]->Clone("Data");     //data   -> Sumw2();
    if(ip == itt)     top    = (TH1F*)hist[itt]->Clone("top");        //top    -> Sumw2();
    if(ip == itW)     tW     = (TH1F*)hist[itW]->Clone("tW");         //tW     -> Sumw2();
    if(ip == iWW)     WW     = (TH1F*)hist[iWW]->Clone("WW");         //WW     -> Sumw2();
    if(ip == iWZ)     WZ     = (TH1F*)hist[iWZ]->Clone("WZ");   //VV     -> Sumw2();
    if(ip == iZZ)     ZZ     = (TH1F*)hist[iZZ]->Clone("ZZ");         //ZZ     -> Sumw2();
    if(ip == iWg)     Wg     = (TH1F*)hist[iWg]->Clone("Wg");         //Wg     -> Sumw2();
    if(ip == iWgSMu){
      WgSMu  = (TH1F*)hist[iWgSMu]->Clone("WgSMu");         //WgSMu     -> Sumw2();
      hist[iWgSMu]->Scale(1.5);
    }
    if(ip == iWgSEl){
      WgSEl  = (TH1F*)hist[iWgSEl]->Clone("WgSEl");         //WgSel     -> Sumw2();
      hist[iWgSEl]->Scale(1.5);         //WgSel     -> Sumw2();
    }
    if(ip == iWj)     Wjets  = (TH1F*)hist[iWj]->Clone("W+jets");     //Wjets  -> Sumw2();
    if(ip == iDY)     Zjets  = (TH1F*)hist[iDY]->Clone("Z+jets");     //Zjets  -> Sumw2();
    if(ip == iDYtau)  DYtau  = (TH1F*)hist[iDYtau]->Clone("DYtau");   //DYtau  -> Sumw2();
    if(ip == iZgamma) Zgamma = (TH1F*)hist[iZgamma]->Clone("Zgamma"); //Zgamma -> Sumw2();
    if(ip == iH125)   ggH    = (TH1F*)hist[iH125]->Clone("ggH");      //ggH    -> Sumw2();
    
    if (moveOverflow) MoveOverflowBins  (hist[ip], xmin, xmax);
    else              ZeroOutOfRangeBins(hist[ip], xmin, xmax);

    if (ngroup > 0) hist[ip]->Rebin(ngroup);

    if (ip == iWg) {
      //hist[ip]->Scale(0.01);
    }
    
    if (ip == iData) {
      hist[ip]->SetMarkerStyle(kFullCircle);
    }
    else {
      hist[ip]->SetFillColor(color[ip]);
      hist[ip]->SetFillStyle(1001);
      hist[ip]->SetLineColor(color[ip]);

      if (_dataDriven && ip == itt)    hist[ip]->Scale(ttScale[_njet]);
      if (_dataDriven && ip == itW)    hist[ip]->Scale(tWScale[_njet]);
      if (_dataDriven && ip == iWW)    hist[ip]->Scale(WWScale[_njet]);
      if (_dataDriven && ip == iDY)    hist[ip]->Scale(ZjScale[_njet]);
      if (_dataDriven && ip == iDYtau) hist[ip]->Scale(ZjScale[_njet]);

      if( ip != iZZ ) hstack->Add(hist[ip]);//TODO something wrong with ZZ
      
    }
  }

  if (_dataDriven)
  {
    top->Scale(ttScale[_njet]);
    tW->Scale(tWScale[_njet]);
    WW->Scale(WWScale[_njet]);
    Zjets->Scale(ZjScale[_njet]);
    DYtau->Scale(ZjScale[_njet]);
  }
  
  top  ->Add(tW);
  //VV   ->Add(ZZ);
  //VV   ->Add(Wg);  
  //Zjets->Add(DYtau);
  //Zjets->Add(Zgamma);

  data  -> Write();
  top   -> Write();
  WW    -> Write();
  //VV    -> Write();
  //Wjets -> Write();
  //Zjets -> Write();
  ggH   -> Write();
  
  outfile->Close();


  // All MC
  //----------------------------------------------------------------------------
  TH1F* allmc = (TH1F*)hist[iData]->Clone("allmc");

  allmc->SetFillColor  (kGray+2);
  allmc->SetFillStyle  (   3345);
  allmc->SetLineColor  (kGray+2);
  allmc->SetMarkerColor(kGray+2);
  allmc->SetMarkerSize (      0);

  for (UInt_t ibin=1; ibin<=allmc->GetNbinsX(); ibin++) {

    Double_t binValue = 0;
    Double_t binError = 0;

    for (UInt_t ip=0; ip<nProcesses; ip++) {

      if (ip == iData) continue;
      if (ip == iZZ) continue;

      Double_t binContent = hist[ip]->GetBinContent(ibin);
      
      binValue += binContent;
      binError += (hist[ip]->GetBinError(ibin) * hist[ip]->GetBinError(ibin));

      //We need to calculate systematic uncertainty for ggH case
//      if (_dataDriven)
//	binError += (systError[ip]*binContent * systError[ip]*binContent);
    }
    
    binError = sqrt(binError);

    allmc->SetBinContent(ibin, binValue);
    allmc->SetBinError  (ibin, binError);
  }


  // Axis labels
  //------------------------------------------------------------------
  TAxis* xaxis = hist[iData]->GetXaxis();
  TAxis* yaxis = hist[iData]->GetYaxis();

  TString ytitle = Form("entries / %s.%df", "%", precision);

  xaxis->SetTitle(xtitle);
  yaxis->SetTitle(Form(ytitle.Data(), hist[iData]->GetBinWidth(0)));
  yaxis->SetTitleOffset(1.6);

  if (!units.Contains("NULL")) {
    
    xaxis->SetTitle(Form("%s [%s]", xaxis->GetTitle(), units.Data()));
    yaxis->SetTitle(Form("%s %s",   yaxis->GetTitle(), units.Data()));
  }


  // Draw
  //--------------------------------------------------------------------
  xaxis->SetRangeUser(xmin, xmax);

  hist[iData]->Draw("ep");
  hstack     ->Draw("hist,same");
  allmc      ->Draw("e2,same");
  hist[iData]->Draw("ep,same");

  // Adjust scale
  //----------------------------------------------------------------------------
  Float_t theMax   = GetMaximumIncludingErrors(hist[iData], xmin, xmax);
  Float_t theMaxMC = GetMaximumIncludingErrors(allmc,       xmin, xmax);

  if (theMaxMC > theMax) theMax = theMaxMC;

  if (pad1->GetLogy()) {

    theMax = TMath::Power(10, TMath::Log10(theMax) + 2.7);

    hist[iData]->SetMinimum(0.05);
  }
  else theMax *= 1.55;

  hist[iData]->SetMaximum(theMax);


  // Legend
  //----------------------------------------------------------------------
  Double_t x0      = 0.720; 
  Double_t y0      = 0.834; 
  Double_t yoffset = 0.048;
  Double_t delta   = yoffset + 0.001;
  Double_t ndelta  = 0;

  Double_t YieldTop   = Yield(hist[itt]) + Yield(hist[itW]);
  Double_t YieldWZ    = Yield(hist[iWZ]);
  Double_t YieldVV    = Yield(hist[iWZ]) + Yield(hist[iZZ]) + Yield(hist[iWg]);
  //Double_t YieldZJets = Yield(hist[iDY]) + Yield(hist[iDYtau]);
  Double_t YieldZJets = Yield(hist[iDY]) + Yield(hist[iDYtau]) + Yield(hist[iZgamma]);

  DrawLegend(x0 - 0.49, y0 - ndelta, hist[iData],  Form(" data (%.0f)", Yield(hist[iData])), "lp", 0.03, 0.2, yoffset); ndelta += delta;
  //DrawLegend(x0 - 0.23, y0 - ndelta, hist[itt],    Form(" tt (%.0f)",  Yield(hist[itt])),   "f",  0.03, 0.2, yoffset); ndelta += delta;
  //DrawLegend(x0 - 0.23, y0 - ndelta, hist[itW],    Form(" tW (%.0f)",  Yield(hist[itW])),   "f",  0.03, 0.2, yoffset); ndelta += delta;
  //DrawLegend(x0 - 0.49, y0 - ndelta, allmc,        Form(" all (%.0f)",  Yield(allmc)),       "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.49, y0 - ndelta, hist[iWW],    Form(" WW (%.0f)",   Yield(hist[iWW])),   "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.49, y0 - ndelta, hist[iWZ],    Form(" WZ (%.0f)",   Yield(hist[iWZ])),  "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.49, y0 - ndelta, hist[iWg],    Form(" Wg (%.0f)",    Yield(hist[iWg])),   "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.49, y0 - ndelta, hist[iWgSMu], Form(" Wg*Mu (%.0f)",    Yield(hist[iWgSMu])),   "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.49, y0 - ndelta, hist[iWgSEl], Form(" Wg*El (%.0f)",    Yield(hist[iWgSEl])),   "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.49, y0 - ndelta, hist[iWj],    Form(" W+jets (%.0f)",Yield(hist[iWj])),   "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.49, y0 - ndelta, hist[iZZ],    Form(" ZZ (%.0f)",    Yield(hist[iZZ])),   "f",  0.03, 0.2, yoffset); ndelta += delta;


  ndelta = 0;
  DrawLegend(x0 - 0.23, y0 - ndelta, hist[iDY],    Form(" DY (%.0f)",    Yield(hist[iDY])),   "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.23, y0 - ndelta, hist[iDYtau], Form(" DYtau (%.0f)", Yield(hist[iDYtau])),"f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.23, y0 - ndelta, hist[iZgamma],Form(" Zg (%.0f)",   Yield(hist[iZgamma])),"f",  0.03, 0.2, yoffset); ndelta += delta;
  //DrawLegend(x0 - 0.23, y0 - ndelta, hist[iDY],   Form(" Z+jets (%.0f)", YieldZJets),         "f",  0.03, 0.2, yoffset); ndelta += delta;
  //DrawLegend(x0 - 0.23, y0 - ndelta, hist[iH125], Form(" Higgs (%.0f)",  Yield(hist[iH125])), "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.23, y0 - ndelta, hist[iH125],  Form(" ggH (%.0f)",  Yield(hist[iH125])), "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.23, y0 - ndelta, hist[itt],  Form(" tt (%.0f)",  Yield(hist[itt])), "f",  0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.23, y0 - ndelta, hist[itW],  Form(" tW (%.0f)",  Yield(hist[itW])), "f",  0.03, 0.2, yoffset); ndelta += delta;


  // Additional titles
  //----------------------------------------------------------------------------
  //TString channelLabel = "ee/#mu#mu/e#mu/#mue";
  TString channelLabel = "";

  //if (_channel == "EE")   channelLabel = "ee";
  //if (_channel == "MuMu") channelLabel = "#mu#mu";
  //if (_channel == "EMu")  channelLabel = "e#mu";
  //if (_channel == "MuE")  channelLabel = "#mue";
  //if (_channel == "SF")   channelLabel = "ee/#mu#mu";
  //if (_channel == "OF")   channelLabel = "e#mu/#mue";

  channelLabel += Form(" %d", _njet);

  if (_njet == 0) channelLabel += "-jets";
  if (_njet == 1) channelLabel += "-jet";
  if (_njet >= 2) channelLabel += "-jets";

  double nBin;
  double binWidth;
  nBin = allmc->GetSize();
  nBin -=2;
  binWidth = allmc->GetBinWidth(2);

  int Z1bin=70/binWidth;
  int Z2bin=110/binWidth;

  cout<<"number of bin: "<<nBin<<endl;
  cout<<"Z bin1: "<<Z1bin<<" Z bin2: "<<Z2bin<<endl;
  double nMcZ, nDataZ;
  nMcZ   = allmc->Integral(Z1bin,Z2bin);
  nDataZ = hist[iData]->Integral(Z1bin,Z2bin);
  double effiCorr;
  effiCorr=nDataZ/nMcZ;
  cout<<"efficiency correction factor: "<<effiCorr<<endl;
  double nMcGstar, nDataGstar, nMcGamma;
  nMcGstar   = hist[iWgSMu]->Integral(1,2);
  nMcGamma   = hist[iWg]->Integral(1,2);
  //nMcGstar   = allmc->Integral(1,2);
  nMcGstar *= effiCorr;
  nMcGamma *= effiCorr;
  nDataGstar = hist[iData]->Integral(1,2);
  double Kfactor;
  double KfactorErr;
  nDataGstar -= nMcGamma;
  Kfactor = nDataGstar/nMcGstar;
  KfactorErr =Kfactor* TMath::Sqrt(nDataGstar/nDataGstar/nDataGstar + nMcGstar/nMcGstar/nMcGstar);
  KfactorErr += 0.1;
  cout<<"Kfactor: "<<Kfactor<<"+"<<KfactorErr<<endl;

  //DrawTLatex(0.185, 0.975, 0.05, 13, channelLabel.Data(),"");
  DrawTLatex(0.940, 0.983, 0.05, 33, Form("L = %.1f fb^{-1}", _luminosity/1e3),"");
  DrawTLatex(0.45, 0.48, 0.04, 13, Form("K factor (Data/Wg*) = %.2f #pm %.2f", Kfactor, KfactorErr ),"");
  DrawTLatex(0.45, 0.43, 0.04, 13, Form("0< InvM(#mu^{+}#mu^{-}) <4 GeV"),"");

  //----------------------------------------------------------------------------
  // pad2
  //----------------------------------------------------------------------------
  pad2->cd();
    
  TH1F* ratio       = (TH1F*)hist[iData]->Clone("ratio");
  TH1F* uncertainty = (TH1F*)allmc->Clone("uncertainty");
    
  for (UInt_t ibin=1; ibin<=ratio->GetNbinsX(); ibin++) {

    Double_t mcValue = allmc->GetBinContent(ibin);
    Double_t mcError = allmc->GetBinError  (ibin);
    
    Double_t dtValue = ratio->GetBinContent(ibin);
    Double_t dtError = ratio->GetBinError  (ibin);

    Double_t ratioValue       = (mcValue > 0) ? dtValue/mcValue : 0.0;
    Double_t ratioError       = (mcValue > 0) ? dtError/mcValue : 0.0;
    Double_t uncertaintyError = (mcValue > 0) ? mcError/mcValue : 0.0;

    ratio->SetBinContent(ibin, ratioValue);
    ratio->SetBinError  (ibin, ratioError);

    uncertainty->SetBinContent(ibin, 1.0);
    uncertainty->SetBinError  (ibin, uncertaintyError);
  }


  TAxis* uaxis = (TAxis*)uncertainty->GetXaxis();
    
  uaxis->SetRangeUser(xmin, xmax);
    
    
  uncertainty->Draw("e2");
  ratio      ->Draw("ep,same");

  uncertainty->GetYaxis()->SetRangeUser(0, 2.5);


  // Save
  //----------------------------------------------------------------------
  pad2->cd(); SetAxis(uncertainty, hist[iData]->GetXaxis()->GetTitle(), "data / prediction", 0.10, 0.8);
  pad1->cd(); SetAxis(hist[iData], "", hist[iData]->GetYaxis()->GetTitle(),                  0.05, 1.6);

  canvas->cd();

  TString suffixLogy = (_setLogy) ? "_Log" : "_Lin";

  canvas->SaveAs(Form("%s/%s%s.%s",
		      _output.Data(),
		      hname.Data(),
		      suffixLogy.Data(),
		      _format.Data()));
}


//------------------------------------------------------------------------------
// GetMaximumIncludingErrors
//------------------------------------------------------------------------------
Float_t GetMaximumIncludingErrors(TH1F*    h,
				  Double_t xmin,
				  Double_t xmax)
{
  UInt_t nbins = h->GetNbinsX();

  TAxis* axis = (TAxis*)h->GetXaxis();
  
  Int_t firstBin = (xmin != -999) ? axis->FindBin(xmin) : 1;
  Int_t lastBin  = (xmax !=  999) ? axis->FindBin(xmax) : nbins;

  Float_t maxWithErrors = 0;

  for (Int_t i=firstBin; i<=lastBin; i++) {

    Float_t binHeight = h->GetBinContent(i) + h->GetBinError(i);

    if (binHeight > maxWithErrors) maxWithErrors = binHeight;
  }

  return maxWithErrors;
}


//------------------------------------------------------------------------------
// MoveOverflowBins
//------------------------------------------------------------------------------
void MoveOverflowBins(TH1* h,
		      Double_t xmin,
		      Double_t xmax)
{
  UInt_t nbins = h->GetNbinsX();

  TAxis* axis = (TAxis*)h->GetXaxis();
  
  Int_t firstBin = (xmin != -999) ? axis->FindBin(xmin) : 1;
  Int_t lastBin  = (xmax !=  999) ? axis->FindBin(xmax) : nbins;

  Double_t firstVal = 0;
  Double_t firstErr = 0;

  Double_t lastVal = 0;
  Double_t lastErr = 0;

  for (UInt_t i=0; i<=nbins+1; i++) {

    if (i <= firstBin) {
      firstVal += h->GetBinContent(i);
      firstErr += (h->GetBinError(i)*h->GetBinError(i));
    }

    if (i >= lastBin) {
      lastVal += h->GetBinContent(i);
      lastErr += (h->GetBinError(i)*h->GetBinError(i));
    }

    if (i < firstBin || i > lastBin) {
      h->SetBinContent(i, 0);
      h->SetBinError  (i, 0);
    }
  }

  firstErr = sqrt(firstErr);
  lastErr  = sqrt(lastErr);

  h->SetBinContent(firstBin, firstVal);
  h->SetBinError  (firstBin, firstErr);

  h->SetBinContent(lastBin, lastVal);
  h->SetBinError  (lastBin, lastErr);
}


//------------------------------------------------------------------------------
// ZeroOutOfRangeBins
//------------------------------------------------------------------------------
void ZeroOutOfRangeBins(TH1* h, Double_t xmin, Double_t xmax)
{
  UInt_t nbins = h->GetNbinsX();

  TAxis* axis = (TAxis*)h->GetXaxis();
  
  Int_t firstBin = (xmin != -999) ? axis->FindBin(xmin) : 1;
  Int_t lastBin  = (xmax !=  999) ? axis->FindBin(xmax) : nbins;

  for (UInt_t i=0; i<=nbins+1; i++) {

    if (i < firstBin || i > lastBin) {
      h->SetBinContent(i, 0);
      h->SetBinError  (i, 0);
    }
  }
}


//------------------------------------------------------------------------------
// DrawTLatex
//------------------------------------------------------------------------------
void DrawTLatex(Double_t    x,
		Double_t    y,
		Double_t    tsize,
		Short_t     align,
		const char* text,
		Bool_t      setndc = true)
{
  TLatex* tl = new TLatex(x, y, text);

  tl->SetNDC      (setndc);
  tl->SetTextAlign( align);
  tl->SetTextFont (    42);
  tl->SetTextSize ( tsize);

  tl->Draw("same");
}


//------------------------------------------------------------------------------
// SetAxis
//------------------------------------------------------------------------------
void SetAxis(TH1*    hist,
	     TString xtitle,
	     TString ytitle,
	     Float_t size,
	     Float_t offset)
{
  TAxis* xaxis = (TAxis*)hist->GetXaxis();
  TAxis* yaxis = (TAxis*)hist->GetYaxis();

  xaxis->SetLabelFont(42);
  yaxis->SetLabelFont(42);
  xaxis->SetTitleFont(42);
  yaxis->SetTitleFont(42);

  xaxis->SetLabelOffset(0.025);
  yaxis->SetLabelOffset(0.025);
  xaxis->SetTitleOffset(1.4);
  yaxis->SetTitleOffset(offset);

  xaxis->SetLabelSize(size);
  yaxis->SetLabelSize(size);
  xaxis->SetTitleSize(size);
  yaxis->SetTitleSize(size);

  xaxis->SetTitle(xtitle);
  yaxis->SetTitle(ytitle);

  xaxis->SetNdivisions(505);
  yaxis->SetNdivisions(505);

  yaxis->CenterTitle();

  gPad->GetFrame()->DrawClone();
  gPad->RedrawAxis();
}


//------------------------------------------------------------------------------
// Yield
//------------------------------------------------------------------------------
Double_t Yield(TH1* h)
{
  Int_t nbins = h->GetNbinsX();

  return h->Integral(0, nbins+1);
}

//------------------------------------------------------------------------------
//Subtraction 
//------------------------------------------------------------------------------
void Subtraction(TString  hname,
		   TString  xtitle,
		   Int_t    ngroup       = -1,
		   Int_t    precision    = 1,
		   TString  units        = "NULL",
		   Double_t xmin         = -999,
		   Double_t xmax         =  999,
		   Bool_t   moveOverflow = true)
{
  TCanvas* canvas = new TCanvas(hname, hname, 800, 800);

  TPad* pad1 = new TPad("pad1", "pad1", 0, 0.0, 1, 1.0);

  pad1->SetTopMargin   (0.08);
  //pad1->SetBottomMargin(0.02);
  pad1->Draw();
      

  //----------------------------------------------------------------------------
  // pad1
  //----------------------------------------------------------------------------
  pad1->cd();

  pad1->SetLogy(_setLogy);

  TH1F* hist[nProcesses];

  for (UInt_t ip=0; ip<nProcesses; ip++) {

    hist[ip] = (TH1F*)input[ip]->Get(hname);
    hist[ip]->SetName(hname + process[ip]);

    if (moveOverflow) MoveOverflowBins  (hist[ip], xmin, xmax);
    else              ZeroOutOfRangeBins(hist[ip], xmin, xmax);

	if (ngroup > 0) hist[ip]->Rebin(ngroup);

	if (_dataDriven && ip == iWW)    hist[ip]->Scale(WWScale[_njet]);
	if (_dataDriven && ip == iDY)    hist[ip]->Scale(ZjScale[_njet]);
	if (_dataDriven && ip == iDYtau) hist[ip]->Scale(ZjScale[_njet]);

  }

  // Data subtraction for Top background estimation
  //----------------------------------------------------------------------------
  TH1F* subData = (TH1F*)hist[iData]->Clone("subData");
  for (UInt_t ip=0; ip<nProcesses; ip++) {
	  if (ip == itt) continue;
	  if (ip == itW) continue;
	  if (ip == iData ) continue;
	  subData->Add(hist[ip],-1);
  }
  subData->SetLineColor(kRed+1);
  Double_t subData_Yield = subData->Integral();
  //subData->SetLineColor();

  // Top background
  //----------------------------------------------------------------------------
  TH1F* Top = (TH1F*)hist[itt]->Clone("Top");
  Top->Add(hist[itW]);
  Top->SetLineColor(kBlue+1);
  Double_t Top_Yield = Top->Integral();

  // Axis labels
  //----------------------------------------------------------------------------
  TAxis* xaxis = subData->GetXaxis();
  TAxis* yaxis = subData->GetYaxis();

  TString ytitle = Form("entries / %s.%df", "%", precision);

  xaxis->SetTitle(xtitle);
  yaxis->SetTitle(Form(ytitle.Data(), subData->GetBinWidth(0)));
  yaxis->SetTitleOffset(1.6);

  if (!units.Contains("NULL")) {
    
    xaxis->SetTitle(Form("%s [%s]", xaxis->GetTitle(), units.Data()));
    yaxis->SetTitle(Form("%s %s",   yaxis->GetTitle(), units.Data()));
  }


  // Draw
  //----------------------------------------------------------------------------
  xaxis->SetRangeUser(xmin, xmax);

  subData->Draw("hist");
  Top->Draw("hist same");

  // Adjust scale
  //----------------------------------------------------------------------------
  subData->SetMinimum(0.0);
  
  Float_t theMax   = GetMaximumIncludingErrors(subData, xmin, xmax);
  Float_t theMaxMC = GetMaximumIncludingErrors(Top,       xmin, xmax);

  if (theMaxMC > theMax) theMax = theMaxMC;

  if (pad1->GetLogy()) {

    theMax = TMath::Power(10, TMath::Log10(theMax) + 2.7);

    subData->SetMinimum(0.05);
  }
  else theMax *= 1.55;

  subData->SetMaximum(theMax);

  // Legend
  //----------------------------------------------------------------------------
  Double_t x0      = 0.720; 
  Double_t y0      = 0.834; 
  Double_t yoffset = 0.048;
  Double_t delta   = yoffset + 0.001;
  Double_t ndelta  = 0;

  DrawLegend(x0 - 0.49, y0 - ndelta, subData, Form(" Data Subtraction (MC without Top) (%.0f)", Yield(subData)), "l", 0.03, 0.2, yoffset); ndelta += delta;
  DrawLegend(x0 - 0.49, y0 - ndelta, Top,     Form(" Top (%.0f)",  Yield(Top)),     "l", 0.03, 0.2, yoffset); ndelta += delta;

  // Additional titles
  //----------------------------------------------------------------------------
  //TString channelLabel = "ee/#mu#mu/e#mu/#mue";
  TString channelLabel = "";

  //if (_channel == "EE")   channelLabel = "ee";
  //if (_channel == "MuMu") channelLabel = "#mu#mu";
  //if (_channel == "EMu")  channelLabel = "e#mu";
  //if (_channel == "MuE")  channelLabel = "#mue";
  //if (_channel == "SF")   channelLabel = "ee/#mu#mu";
  //if (_channel == "OF")   channelLabel = "e#mu/#mue";

  channelLabel += Form(" %d", _njet);

  if (_njet == 0) channelLabel += "-jets";
  if (_njet == 1) channelLabel += "-jet";
  if (_njet >= 2) channelLabel += "-jets";

  DrawTLatex(0.185, 0.975, 0.05, 13, channelLabel.Data(),"");
  DrawTLatex(0.940, 0.983, 0.05, 33, Form("L = %.1f fb^{-1}", _luminosity/1e3),"");
  
  if (Top_Yield!=0){ 
	  cout << "subData_Yield = "<<subData_Yield<<", Top_Yield = "<<Top_Yield<<", Ratio = "<< subData_Yield/Top_Yield <<endl;
	  TLatex *tex3 = new TLatex(0.250, 0.75, "Scale Factor");
	  tex3->SetNDC();
	  tex3->SetTextSize(0.035);
	  tex3->Draw();
	  TLatex *tex4 = new TLatex(0.250, 0.7, Form("%.0f / %.0f = %3.3f",subData_Yield ,Top_Yield ,subData_Yield/Top_Yield));
	  tex4->SetNDC();
	  tex4->SetTextSize(0.035);
	  tex4->Draw();
  }


  // Save
  //----------------------------------------------------------------------------
  pad1->cd(); 
  //SetAxis(subData, "", subData->GetYaxis()->GetTitle(),                  0.05, 1.6);

  canvas->cd();

  TString suffixLogy = (_setLogy) ? "_Log" : "_Lin";

  canvas->SaveAs(Form("%s/%s%s_sub.%s",
		      _output.Data(),
		      hname.Data(),
		      suffixLogy.Data(),
		      _format.Data()));
  
}

