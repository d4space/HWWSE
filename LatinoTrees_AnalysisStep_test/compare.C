#include <boost/lexical_cast.hpp>
#include <sstream>
#include <string>

void compare(){

  TCanvas *myCan = new TCanvas("myCan");
  myCan->cd();
  TFile *f_WZTo3LNu   = new TFile("Gen_ZGstar_massPlot/WZTo3LNu.root");
  TFile *f_WZTo3LNu01 = new TFile("Gen_ZGstar_massPlot/WZTo3LNu_mllmin01.root");
  TH1F* h_WZ = (TH1F*)f_WZTo3LNu->Get("h_0");
  TH1F* h_01 = (TH1F*)f_WZTo3LNu01->Get("h_0");

  TH1F* h_WZ_scaleCalc = (TH1F*)h_WZ->Clone("h_WZ_scaleCalc");
  TH1F* h_01_scaleCalc = (TH1F*)h_01->Clone("h_01_scaleCalc");
  // Scale calculation
  double lumi_WZ = 2000000/4.42965/1000; //fb
  double lumi_01 = 989340 /4.42965/1000; //fb
  h_WZ_scaleCalc->Scale(1./lumi_WZ);
  h_01_scaleCalc->Scale(1./lumi_01);
  h_WZ_scaleCalc->SetLineColor(kRed);
  h_01_scaleCalc->SetLineColor(kBlue);
  double binWidth=120./150.;
  int bin1= 60/binWidth;
  int bin2= 120/binWidth;
  cout<<bin1<<"  bins  "<<bin2<<endl;
  double eventN_WZ=h_WZ_scaleCalc->Integral(bin1,bin2);
  double eventN_01=h_01_scaleCalc->Integral(bin1,bin2);
  double scaleWZov01 = eventN_WZ/eventN_01;
  cout<<"scale is "<<scaleWZov01<<endl;
  TPaveText *pt = new TPaveText(.3,.5,.85,.8,"NDC");
  //NDC sets  coords relative to pad
  std::ostringstream os;
  os << scaleWZov01;
  std::string str = os.str();
  TString ts_scaleWZov01=str;
  TString result= "scale(WZTo3LNu/WZTo3LNu01): "+ts_scaleWZov01+" at Z-peak";
  ///TString *reskult= "scale(WZTo3LNu/WZTo3LNu01): "+str.c_str();
  pt->AddText("Assuming the same cross section to WZTo3LNu(4.42965)");
  pt->AddText("Normalize to be 1/fb");
  TText *txt1 = pt->AddText(result);
  txt1->SetTextSize(0.03);

  // Draw
  h_01_scaleCalc->Draw();
  h_WZ_scaleCalc->Draw("same");
  pt->Draw();

  myCan->SaveAs("WZTo3LNuOvWZTo3LNu01_xsecSame.pdf");
  myCan->SaveAs("WZTo3LNuOvWZTo3LNu01_xsecSame.png");

  lumi_WZ = 2000000/4.42965/1000; //fb
  lumi_01 = 989340 /4.42965/scaleWZov01/1000; //fb
  h_WZ->Scale(1./lumi_WZ);
  h_01->Scale(1./lumi_01);
  h_WZ->SetLineColor(kRed);
  h_01->SetLineColor(kBlue);
  myCan->SetLogy();
  h_01->Draw();
  h_WZ->Draw("same");
  TPaveText *pt2 = new TPaveText(.3,.6,.85,.8,"NDC");
  double x_secWZ =4.42965;
  double x_sec01 =4.42965*scaleWZov01;
  std::ostringstream os1;
  os1 << x_secWZ;
  std::string st_x_secWZ = os1.str();
  std::ostringstream os2;
  os2 << x_sec01;
  std::string st_x_sec01 = os2.str();
  TString ts_x_secWZ = st_x_secWZ;
  TString ts_x_sec01 = st_x_sec01;
  TString res_xSecWZ= "x-sec of WZTo3LNu: "+ts_x_secWZ;
  TString res_xSec01= "x-sec of WZTo3LNu_mllmin01: "+ts_x_sec01;
  pt2->AddText(res_xSecWZ);
  pt2->AddText(res_xSec01);
  pt2->Draw();
  myCan->SaveAs("WZTo3LNuOvWZTo3LNu01.pdf");
  myCan->SaveAs("WZTo3LNuOvWZTo3LNu01.png");



}
