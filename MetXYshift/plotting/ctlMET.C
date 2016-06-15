#include <iostream>

#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <TVector2.h>
#include <TF1.h>
#include <TMath.h>
#include <TStyle.h>

void ctlMET(const TString inputFileName = "Wenu_p_select.root") {

  //
  // Settings
  //
  gStyle->SetOptStat(0);
  //
  Int_t NVTXBINS = 45; // 70 for Wenu_p, 35 for Wmunu_p
  //
  // Setup input ntuple
  //
  TFile* inputFile = new TFile(inputFileName);
  TTree* inputTree = (TTree*)inputFile->Get("demo/Events");

  //
  // Declare variables to read in ntuple
  //
  Int_t nVtx, nEvents;

  TVector2 *t2_slimMet=0, *t2_slimMetTxy=0;

  inputTree->SetBranchAddress("npv",         &nVtx);        // number of vertices
  inputTree->SetBranchAddress("t2_slimMet",       &t2_slimMet);
  inputTree->SetBranchAddress("t2_slimMetTxy",    &t2_slimMetTxy);
           
  //
  // Declare histograms
  //
  TH1D *hSlimMet  = new TH1D("hSlimMet","",100,0,150);
        hSlimMet->SetStats(0);
        hSlimMet->SetLineColor(1);
  TH1D *hSlimMetTxy  = new TH1D("hSlimMetTxy","",100,0,150);
        hSlimMetTxy->SetStats(0);
        hSlimMetTxy->SetLineColor(2);
  TH1D *hPhi = new TH1D("hPhi","",100,-3.5,3.5);
        hPhi->SetStats(0);
        hPhi->SetLineColor(1);
  TH1D *hPhiTxy  = new TH1D("hPhiTxy","",100,-3.5,3.5);
        hPhiTxy->SetStats(0);
        hPhiTxy->SetLineColor(4);
  TH2D *hMETnVtx_x = new TH2D("hMETnVtx_x","MET_{x} v. Number of Vertices",NVTXBINS,0,NVTXBINS,100,-150,150);
        hMETnVtx_x->GetXaxis()->SetTitle("Number of vertices");
        hMETnVtx_x->GetYaxis()->SetTitle("MET_{x} [GeV]");
  TH2D *hMETnVtx_y = new TH2D("hMETnVtx_y","MET_{y} v. Number of Vertices",NVTXBINS,0,NVTXBINS,100,-150,150);
        hMETnVtx_y->GetXaxis()->SetTitle("Number of vertices");
        hMETnVtx_y->GetYaxis()->SetTitle("MET_{y} [GeV]");
  TH2D *hMETnVtx_Txy_x = new TH2D("hMETnVtx_Txy_x","MET_{x} v. Number of Vertices",NVTXBINS,0,NVTXBINS,100,-150,150);
        hMETnVtx_Txy_x->GetXaxis()->SetTitle("Number of vertices");
        hMETnVtx_Txy_x->GetYaxis()->SetTitle("MET_{x} [GeV]");
  TH2D *hMETnVtx_Txy_y = new TH2D("hMETnVtx_Txy_y","MET_{y} v. Number of Vertices",NVTXBINS,0,NVTXBINS,100,-150,150);
        hMETnVtx_Txy_y->GetXaxis()->SetTitle("Number of vertices");
        hMETnVtx_Txy_y->GetYaxis()->SetTitle("MET_{y} [GeV]");


  Int_t totalEvents=0;

  double phi;
  for(int jentry=0;jentry<inputTree->GetEntries();jentry++) {
    inputTree->GetEntry(jentry);
    totalEvents += nEvents;

    //
    // Fill histograms
    //
    hMETnVtx_x->Fill(nVtx,t2_slimMet->Px());
    hMETnVtx_y->Fill(nVtx,t2_slimMet->Py());
    hMETnVtx_Txy_x->Fill(nVtx,t2_slimMetTxy->Px());
    hMETnVtx_Txy_y->Fill(nVtx,t2_slimMetTxy->Py());

    hSlimMet      ->Fill(t2_slimMet->Mod());
    hSlimMetTxy   ->Fill(t2_slimMetTxy->Mod());

    phi = t2_slimMet->Phi();
    if( phi >TMath::Pi()) phi -= 2*TMath::Pi();
    hPhi->Fill(phi);

    phi = t2_slimMetTxy->Phi();
    if( phi >TMath::Pi()) phi -= 2*TMath::Pi();
    hPhiTxy->Fill(phi);

  }

  cout << "totalEvents is " << totalEvents << endl;

  // Loop through nVtx bins and find the mean value of metx and mety in each bin
  // Plot nVtx v. mean values of metx/mety in a separate histogram (1 for metx and 1 for mety)
  TH1D* hmetx_proj = new TH1D();
  TH1D* hmety_proj = new TH1D();
  Double_t meanmetx, meanmety;

  TH2D* hMEtMeanVtx_x = new TH2D("hMEtMeanVtx_x","MET_{x} v. Number of vertices",NVTXBINS,0,NVTXBINS,100,-25,7);
        hMEtMeanVtx_x->GetXaxis()->SetTitle("Number of vertices");
        hMEtMeanVtx_x->GetYaxis()->SetTitle("<MET_{x}> [GeV]");
  TH2D* hMEtMeanVtx_y = new TH2D("hMEtMeanVtx_y","MET_{y} v. Number of vertices",NVTXBINS,0,NVTXBINS,100,-25,7);
        hMEtMeanVtx_y->GetXaxis()->SetTitle("Number of vertices");
        hMEtMeanVtx_y->GetYaxis()->SetTitle("<MET_{y}> [GeV]");

  TH2D* hMEtMeanVtx_Txy_x = new TH2D("hMEtMeanVtx_Txy_x","MET_{x} v. Number of vertices",NVTXBINS,0,NVTXBINS,100,-25,7);
        hMEtMeanVtx_Txy_x->GetXaxis()->SetTitle("Number of vertices");
        hMEtMeanVtx_Txy_x->GetYaxis()->SetTitle("<MET_{x}> [GeV]");
  TH2D* hMEtMeanVtx_Txy_y = new TH2D("hMEtMeanVtx_Txy_y","MET_{y} v. Number of vertices",NVTXBINS,0,NVTXBINS,100,-25,7);
        hMEtMeanVtx_Txy_y->GetXaxis()->SetTitle("Number of vertices");
        hMEtMeanVtx_Txy_y->GetYaxis()->SetTitle("<MET_{y}> [GeV]");


  for(int jbin=1;jbin<hMEtMeanVtx_x->GetNbinsX()+1;jbin++) {
    hmetx_proj = hMETnVtx_x->ProjectionY("metx_proj",jbin,jbin+1,"");
    hmety_proj = hMETnVtx_y->ProjectionY("mety_proj",jbin,jbin+1,"");
    meanmetx = hmetx_proj->GetMean();
    meanmety = hmety_proj->GetMean();
    hMEtMeanVtx_x->Fill(jbin,meanmetx);
    hMEtMeanVtx_y->Fill(jbin,meanmety);

    hmetx_proj = hMETnVtx_Txy_x->ProjectionY("metx_proj",jbin,jbin+1,"");
    hmety_proj = hMETnVtx_Txy_y->ProjectionY("mety_proj",jbin,jbin+1,"");
    meanmetx = hmetx_proj->GetMean();
    meanmety = hmety_proj->GetMean();
    hMEtMeanVtx_Txy_x->Fill(jbin,meanmetx);
    hMEtMeanVtx_Txy_y->Fill(jbin,meanmety);
  }


  //
  // Save plots
  //
  TLegend *leg_Vtx_x = new TLegend(0.15,0.15,0.4,0.3,NULL,"brNDC");
  leg_Vtx_x->SetTextFont(62);
  leg_Vtx_x->SetTextSize(0.03330866);
  leg_Vtx_x->SetLineColor(1);
  leg_Vtx_x->SetLineStyle(1);
  leg_Vtx_x->SetLineWidth(1);
  leg_Vtx_x->SetFillColor(0);
  leg_Vtx_x->SetFillStyle(1001);
  leg_Vtx_x->SetBorderSize(0);
  leg_Vtx_x->AddEntry(hMEtMeanVtx_x,"Type1PfMet","p");
  leg_Vtx_x->AddEntry(hMEtMeanVtx_Txy_x,"Type1PfMet + Txy","p");


  TCanvas* tc_metVtx_x = new TCanvas();
  tc_metVtx_x->cd();
  hMEtMeanVtx_x->SetMarkerStyle(24);
  hMEtMeanVtx_x->SetMarkerSize(1);
  hMEtMeanVtx_x->SetMarkerColor(kRed);
  hMEtMeanVtx_x->Draw("p0");
  //hSlimMet->Draw("p9");
  hMEtMeanVtx_Txy_x->SetMarkerStyle(26);
  hMEtMeanVtx_Txy_x->SetMarkerSize(1);
  hMEtMeanVtx_Txy_x->SetMarkerColor(kBlue);
  hMEtMeanVtx_Txy_x->Draw("samep0");
  leg_Vtx_x->Draw("same");
  tc_metVtx_x->Print("Plots/MetvsVtx_x.png");
  tc_metVtx_x->Print("Plots/MetvsVtx_x.pdf");


  //-------------------
  // Met vs Vtx y-axis
  //-------------------
  TLegend *leg_Vtx_y = new TLegend(0.15,0.15,0.4,0.3,NULL,"brNDC");
  leg_Vtx_y->SetTextFont(62);
  leg_Vtx_y->SetTextSize(0.03330866);
  leg_Vtx_y->SetLineColor(1);
  leg_Vtx_y->SetLineStyle(1);
  leg_Vtx_y->SetLineWidth(1);
  leg_Vtx_y->SetFillColor(0);
  leg_Vtx_y->SetFillStyle(1001);
  leg_Vtx_y->SetBorderSize(0);
  leg_Vtx_y->AddEntry(hMEtMeanVtx_y,"Type1PfMet","p");
  leg_Vtx_y->AddEntry(hMEtMeanVtx_Txy_y,"Type1PfMet + Txy","p");


  TCanvas* tc_metVtx_y = new TCanvas();
  tc_metVtx_y->cd();
  hMEtMeanVtx_y->SetMarkerStyle(24);
  hMEtMeanVtx_y->SetMarkerSize(1);
  hMEtMeanVtx_y->SetMarkerColor(kRed);
  hMEtMeanVtx_y->Draw("p0");
  //hSlimMet->Draw("p9");
  hMEtMeanVtx_Txy_y->SetMarkerStyle(26);
  hMEtMeanVtx_Txy_y->SetMarkerSize(1);
  hMEtMeanVtx_Txy_y->SetMarkerColor(kBlue);
  hMEtMeanVtx_Txy_y->Draw("same");
  leg_Vtx_y->Draw("same");
  tc_metVtx_y->Print("Plots/MetvsVtx_y.png");
  tc_metVtx_y->Print("Plots/MetvsVtx_y.pdf");

/*********************
  //---------------------
  // phi distribution
  //---------------------
  TCanvas* tc_phi = new TCanvas();
  tc_phi->cd();
  hPhi->SetLineColor(kRed);
  hPhi->Draw("");
  hPhi->SetLineColor(kRed);
  hPhi->Draw("");
  htype1corr->Draw("same");
  leg->Draw("same");
  cmet->Print("met.png");
  cmet->Close();
  TCanvas* cmetphi = new TCanvas();
  cmetphi->cd();
  htype1phi->Draw("same");
  htype1phicorr->Draw("same");
  leg->Draw("same");
  cmetphi->Print("metphi.png");
//  cmetphi->Close();
  TCanvas* cmetx = new TCanvas();
  cmetx->cd();
  hmetx->Draw();
  cmetx->Print("metx.png");
  cmetx->Close();
  TCanvas* cmety = new TCanvas();
  cmety->cd();
  hmety->Draw();
  cmety->Print("mety.png");
  cmety->Close();
  TCanvas* cmetxfit = new TCanvas();
  cmetxfit->cd();
  hmetxfit->Draw();
  cmetxfit->Print("metxfit.png");
  cmetxfit->Close();
  TCanvas* cmetyfit = new TCanvas();
  cmetyfit->cd();
  hmetyfit->Draw();
  cmetyfit->Print("metyfit.png");
  cmetyfit->Close();
  ***************/
}
