

int compareWZ3LNuVsWgammaStarLMM()
{
  TCanvas *myCan= new TCanvas();
  TFile *WZ3LNu = new TFile("../MakeHisto/rootfiles/0jet/MuMu/WZ3LNu.root");
  TFile *WgSLMM = new TFile("../MakeHisto/rootfiles/0jet/MuMu/WgammaStarToLNuMuMu.root");

  TH1F* hWZGenMu1_pt = (TH1F*)WZ3LNu->Get("hGen_mu1_pt");
  TH1F* hWgGenMu1_pt = (TH1F*)WgSLMM->Get("hGen_mu1_pt");

  TH1F* hWZGen_ZgSMu1_pt = (TH1F*)WZ3LNu->Get("hGen_ZGstar_mu1_pt");
  TH1F* hWgGen_ZgSMu1_pt = (TH1F*)WgSLMM->Get("hGen_ZGstar_mu1_pt");
  TH1F* hWZGen_ZgSMu2_pt = (TH1F*)WZ3LNu->Get("hGen_ZGstar_mu2_pt");
  TH1F* hWgGen_ZgSMu2_pt = (TH1F*)WgSLMM->Get("hGen_ZGstar_mu2_pt");

  TH1F* hWZGen_ZgS_InvDimu = (TH1F*)WZ3LNu->Get("hZGstar_Gen_InvDimu");
  TH1F* hWgGen_ZgS_InvDimu = (TH1F*)WgSLMM->Get("hZGstar_Gen_InvDimu");


  // Leading muon pt
  hWZGenMu1_pt->SetLineColor(kRed);
  hWZGenMu1_pt->Draw("histo");
  hWgGenMu1_pt->Draw("same");
  myCan->SaveAs("pdf/0jet/MuMu/GenMu1_pt.pdf");

  // muon pt1 from Zg* 
  hWZGen_ZgSMu1_pt->SetLineColor(kRed);
  hWZGen_ZgSMu1_pt->Draw("histo");
  hWgGen_ZgSMu1_pt->Draw("histo");
  myCan->SaveAs("pdf/0jet/MuMu/Gen_ZgSMu1_pt.pdf");
  // muon pt2 from Zg* 
  hWZGen_ZgSMu2_pt->SetLineColor(kRed);
  hWZGen_ZgSMu2_pt->Draw("histo");
  hWgGen_ZgSMu2_pt->Draw("histo");
  myCan->SaveAs("pdf/0jet/MuMu/Gen_ZgSMu2_pt.pdf");

  hWZGen_ZgS_InvDimu->SetLineColor(kRed);
  hWgGen_ZgS_InvDimu->SetLineColor(kBlue);
  TH1F* hWgGen_ZgS_InvDimu_norScale = (TH1F*)hWgGen_ZgS_InvDimu->Clone("hWgGen_ZgS_InvDimu_norScale");
  hWgGen_ZgS_InvDimu_norScale->Scale(3);

  //myCan->SetLogy();
  hWZGen_ZgS_InvDimu->SetMaximum(20);
  hWZGen_ZgS_InvDimu->Draw("histo");
  hWgGen_ZgS_InvDimu_norScale->Draw("samehisto");
  hWZGen_ZgS_InvDimu->Draw("samehisto");
  hWgGen_ZgS_InvDimu->Draw("samehisto");


  return 0;
}
