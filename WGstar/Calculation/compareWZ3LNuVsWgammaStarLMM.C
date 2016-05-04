#define Color_WZ kRed
#define Color_WgSt kBlue
#define Color_WgNoSt kGreen
int compareWZ3LNuVsWgammaStarLMM()
{
  TCanvas *myCan= new TCanvas();
  TFile *WZ3LNu = new TFile("../MakeHisto/rootfiles/0jet/MuMu/WZ3LNu.root");
  TFile *WgSLMM = new TFile("../MakeHisto/rootfiles/0jet/MuMu/WgammaStarToLNuMuMu.root");
  TFile *WgNoSt = new TFile("../MakeHisto/rootfiles/0jet/MuMu/WgammaNoStar.root");

  TH1F* hGen_WZ_Mu1_pt     = (TH1F*)WZ3LNu->Get("hGen_mu1_pt");
  TH1F* hGen_WgSt_Mu1_pt   = (TH1F*)WgSLMM->Get("hGen_mu1_pt");
  TH1F* hGen_WgNoSt_Mu1_pt = (TH1F*)WgNoSt->Get("hGen_mu1_pt");

  TH1F* hGen_WZ_ZgSMu1_pt    = (TH1F*)WZ3LNu->Get("hGen_ZGstar_mu1_pt");
  TH1F* hGen_WgSt_ZgSMu1_pt  = (TH1F*)WgSLMM->Get("hGen_ZGstar_mu1_pt");
  TH1F* hGen_WgNoSt_ZgSMu1_pt= (TH1F*)WgNoSt->Get("hGen_ZGstar_mu1_pt");

  TH1F* hGen_WZ_ZgSMu2_pt    = (TH1F*)WZ3LNu->Get("hGen_ZGstar_mu2_pt");
  TH1F* hGen_WgSt_ZgSMu2_pt  = (TH1F*)WgSLMM->Get("hGen_ZGstar_mu2_pt");
  TH1F* hGen_WgNoSt_ZgSMu2_pt= (TH1F*)WgNoSt->Get("hGen_ZGstar_mu2_pt");

  //TH1F* hGen_WZ_ZgS_InvDimu = (TH1F*)WZ3LNu->Get("hInvDimu_Gen");
  //TH1F* hGen_WgSt_ZgS_InvDimu = (TH1F*)WgSLMM->Get("hInvDimu_Gen");
  TH1F* hGen_WZ_ZgS_InvDimu     = (TH1F*)WZ3LNu->Get("hZGstar_Gen_InvDimu");
  TH1F* hGen_WgSt_ZgS_InvDimu   = (TH1F*)WgSLMM->Get("hZGstar_Gen_InvDimu");
  TH1F* hGen_WgNoSt_ZgS_InvDimu = (TH1F*)WgNoSt->Get("hZGstar_Gen_InvDimu");

  TH1F* hRec_WZ_ZgS_InvDimu     = (TH1F*)WZ3LNu->Get("hInvDimu_Recon_SmallWindow");
  TH1F* hRec_WgSt_ZgS_InvDimu   = (TH1F*)WgSLMM->Get("hInvDimu_Recon_SmallWindow");
  TH1F* hRec_WgNoSt_ZgS_InvDimu = (TH1F*)WgNoSt->Get("hInvDimu_Recon_SmallWindow");

  TH1F*    hRec_WZ_Nmuon  = (TH1F*)WZ3LNu->Get("hNmuons");
  TH1F* hRec_WgSt_Nmuon   = (TH1F*)WgSLMM->Get("hNmuons");
  TH1F* hRec_WgNoSt_Nmuon = (TH1F*)WgNoSt->Get("hNmuons");

  // Leading muon pt
  hGen_WZ_Mu1_pt->SetLineColor(kRed);
  hGen_WZ_Mu1_pt->Draw("histo");
  hGen_WgSt_Mu1_pt->Draw("same");
  myCan->SaveAs("pdf/0jet/MuMu/GenMu1_pt.pdf");

  // muon pt1 from Zg* 
  hGen_WgNoSt_ZgSMu1_pt->SetLineColor(Color_WgNoSt);
  hGen_WgSt_ZgSMu1_pt  ->SetLineColor(Color_WgSt);
  hGen_WgNoSt_ZgSMu1_pt->SetLineWidth(2);
  hGen_WgSt_ZgSMu1_pt  ->SetLineWidth(2);
  TLegend *Lg_ZgSMu1_Pt  = new TLegend(0.7,0.7,0.9,0.9);
  Lg_ZgSMu1_Pt->AddEntry(hGen_WgNoSt_ZgSMu1_pt,"WgNoSt","l");
  Lg_ZgSMu1_Pt->AddEntry(hGen_WgSt_ZgSMu1_pt,"WgSt","l");
  hGen_WgNoSt_ZgSMu1_pt->Draw("histo");
  hGen_WgSt_ZgSMu1_pt  ->Draw("histosame");
  Lg_ZgSMu1_Pt->Draw();
  myCan->SaveAs("pdf/0jet/MuMu/Gen_ZgSMu1_pt.pdf");
  // muon pt2 from Zg* 
  hGen_WgNoSt_ZgSMu2_pt->SetLineColor(Color_WgNoSt);
  hGen_WgSt_ZgSMu2_pt  ->SetLineColor(Color_WgSt);
  hGen_WgNoSt_ZgSMu2_pt->SetLineWidth(2);
  hGen_WgSt_ZgSMu2_pt  ->SetLineWidth(2);
  TLegend *Lg_ZgSMu2_Pt  = new TLegend(0.7,0.7,0.9,0.9);
  Lg_ZgSMu2_Pt->AddEntry(hGen_WgNoSt_ZgSMu2_pt,"WgNoSt","l");
  Lg_ZgSMu2_Pt->AddEntry(hGen_WgSt_ZgSMu2_pt,"WgSt","l");
  hGen_WgNoSt_ZgSMu2_pt->Draw("histo");
  hGen_WgSt_ZgSMu2_pt  ->Draw("histosame");
  Lg_ZgSMu2_Pt->Draw();
  myCan->SaveAs("pdf/0jet/MuMu/Gen_ZgSMu2_pt.pdf");

  // InvDimu from Gen g*
  double _scale(1.0);
  TH1F* hGen_WgSt_ZgS_InvDimu_norScale = (TH1F*)hGen_WgSt_ZgS_InvDimu->Clone("hGen_WgSt_ZgS_InvDimu_norScale");
  hGen_WgSt_ZgS_InvDimu_norScale->Scale(_scale);
  hGen_WZ_ZgS_InvDimu    ->SetLineColor(Color_WZ);
  hGen_WgSt_ZgS_InvDimu  ->SetLineColor(Color_WgSt);
  hGen_WgNoSt_ZgS_InvDimu->SetLineColor(Color_WgNoSt);
  hGen_WZ_ZgS_InvDimu    ->SetLineWidth(2);
  hGen_WgSt_ZgS_InvDimu  ->SetLineWidth(2);
  hGen_WgNoSt_ZgS_InvDimu->SetLineWidth(2);
  //myCan->SetLogy();
  //hGen_WZ_ZgS_InvDimu->SetMaximum(40);
  TLegend *Lg_Gen_ZgS_InvDimu = new TLegend(0.7,0.7,0.9,0.9);
  Lg_Gen_ZgS_InvDimu->AddEntry(hGen_WZ_ZgS_InvDimu,"WZ","l");
  Lg_Gen_ZgS_InvDimu->AddEntry(hGen_WgNoSt_ZgS_InvDimu,"WgNoSt","l");
  Lg_Gen_ZgS_InvDimu->AddEntry(hGen_WgSt_ZgS_InvDimu,"WgSt","l");
  hGen_WgNoSt_ZgS_InvDimu->SetMaximum(30);
  hGen_WgNoSt_ZgS_InvDimu->Draw("histo");
  hGen_WZ_ZgS_InvDimu    ->Draw("samehisto");
  hGen_WgSt_ZgS_InvDimu  ->Draw("samehisto");
  Lg_Gen_ZgS_InvDimu->Draw();
  myCan->SaveAs("pdf/0jet/MuMu/hZGstar_Gen_InvDimu.pdf");


  // Recon ZgS InvDimu
  hRec_WgNoSt_ZgS_InvDimu->SetLineColor(Color_WgNoSt);
  hRec_WgSt_ZgS_InvDimu  ->SetLineColor(Color_WgSt);
  hRec_WZ_ZgS_InvDimu    ->SetLineColor(Color_WZ);
  hRec_WgNoSt_ZgS_InvDimu->SetLineWidth(2);
  hRec_WgSt_ZgS_InvDimu  ->SetLineWidth(2);
  hRec_WZ_ZgS_InvDimu    ->SetLineWidth(2);
  TLegend *Lg_Rec_ZgS_InvDimu  = new TLegend(0.7,0.7,0.9,0.9);
  Lg_Rec_ZgS_InvDimu->AddEntry(hRec_WZ_ZgS_InvDimu,"WZ","l");
  Lg_Rec_ZgS_InvDimu->AddEntry(hRec_WgNoSt_ZgS_InvDimu,"WgNoSt","l");
  Lg_Rec_ZgS_InvDimu->AddEntry(hRec_WgSt_ZgS_InvDimu,"WgSt","l");
  hRec_WgNoSt_ZgS_InvDimu->Draw("histo");
  //hRec_WgSt_ZgS_InvDimu->Scale(_scale);
  hRec_WgSt_ZgS_InvDimu  ->Draw("samehisto");
  hRec_WZ_ZgS_InvDimu    ->Draw("samehisto");
  myCan->SaveAs("pdf/0jet/MuMu/hInvDimu_Recon_SmallWindow.pdf");

  // Nmuon before cuts 
     hRec_WZ_Nmuon  = (TH1F*)WZ3LNu->Get("hNmuons");
  hRec_WgSt_Nmuon   = (TH1F*)WgSLMM->Get("hNmuons");
  hRec_WgNoSt_Nmuon = (TH1F*)WgNoSt->Get("hNmuons");
     hRec_WZ_Nmuon  ->SetLineColor(Color_WZ);
  hRec_WgSt_Nmuon   ->SetLineColor(Color_WgSt);
  hRec_WgNoSt_Nmuon ->SetLineColor(Color_WgNoSt);
     hRec_WZ_Nmuon  ->SetLineWidth(2);
  hRec_WgSt_Nmuon   ->SetLineWidth(2);
  hRec_WgNoSt_Nmuon ->SetLineWidth(2);
  TLegend *Lg_Nmuon  = new TLegend(0.7,0.7,0.9,0.9);
  Lg_Nmuon->AddEntry(hRec_WZ_Nmuon,"WZ","l");
  Lg_Nmuon->AddEntry(hRec_WgSt_Nmuon,"WgSt","l");
  Lg_Nmuon->AddEntry(hRec_WgNoSt_Nmuon,"WgNoSt","l");
  //myCan->SetLogy();
  //hRec_WgNoSt_Nmuon ->SetMaximum(900);
  hRec_WgNoSt_Nmuon ->Draw("histo");
     hRec_WZ_Nmuon  ->Draw("histosame");
  hRec_WgSt_Nmuon   ->Draw("histosame");
  Lg_Nmuon->Draw();
  myCan->SaveAs("pdf/0jet/MuMu/hNmuon.pdf");

  // RecNmuons_forGenDiMu before cuts 
     hRec_WZ_RecNmuons_forGenDiMu  = (TH1F*)WZ3LNu->Get("hRecNmuons_forGenDiMu");
  hRec_WgSt_RecNmuons_forGenDiMu   = (TH1F*)WgSLMM->Get("hRecNmuons_forGenDiMu");
  hRec_WgNoSt_RecNmuons_forGenDiMu = (TH1F*)WgNoSt->Get("hRecNmuons_forGenDiMu");
     hRec_WZ_RecNmuons_forGenDiMu  ->SetLineColor(Color_WZ);
  hRec_WgSt_RecNmuons_forGenDiMu   ->SetLineColor(Color_WgSt);
  hRec_WgNoSt_RecNmuons_forGenDiMu ->SetLineColor(Color_WgNoSt);
     hRec_WZ_RecNmuons_forGenDiMu  ->SetLineWidth(2);
  hRec_WgSt_RecNmuons_forGenDiMu   ->SetLineWidth(2);
  hRec_WgNoSt_RecNmuons_forGenDiMu ->SetLineWidth(2);
  TLegend *Lg_RecNmuons_forGenDiMu  = new TLegend(0.7,0.7,0.9,0.9);
  Lg_RecNmuons_forGenDiMu->AddEntry(hRec_WZ_RecNmuons_forGenDiMu,"WZ","l");
  Lg_RecNmuons_forGenDiMu->AddEntry(hRec_WgSt_RecNmuons_forGenDiMu,"WgSt","l");
  Lg_RecNmuons_forGenDiMu->AddEntry(hRec_WgNoSt_RecNmuons_forGenDiMu,"WgNoSt","l");
  //myCan->SetLogy();
  //hRec_WgNoSt_RecNmuons_forGenDiMu ->SetMaximum(900);
  hRec_WgNoSt_RecNmuons_forGenDiMu ->Draw("histo");
     hRec_WZ_RecNmuons_forGenDiMu  ->Draw("histosame");
  hRec_WgSt_RecNmuons_forGenDiMu   ->Draw("histosame");
  Lg_RecNmuons_forGenDiMu->Draw();
  myCan->SaveAs("pdf/0jet/MuMu/hRecNmuons_forGenDiMu.pdf");

  return 0;
}
