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
  double lumi_WZ = 2000000/4.42965/1000; //fb
  double lumi_01 = 989340 /4.42965/1000; //fb
  h_WZ->Scale(1./lumi_WZ);
  h_01->Scale(1./lumi_01);
  h_WZ->SetLineColor(kRed);
  h_01->SetLineColor(kBlue);
  h_01->Draw();
  h_WZ->Draw("same");
  double binWidth=120./150.;
  int bin1= 80/binWidth;
  int bin2= 100/binWidth;
  cout<<bin1<<"  bins  "<<bin2<<endl;
  double eventN_WZ=h_WZ->Integral(bin1,bin2);
  double eventN_01=h_01->Integral(bin1,bin2);
  double scaleWZov01 = eventN_WZ/eventN_01;
  cout<<scaleWZov01<<endl;
  TPaveText *pt = new TPaveText(.3,.5,.85,.8,"NDC");
  //NDC sets  coords relative to pad
  std::ostringstream os;
  os << scaleWZov01;
  std::string str = os.str();
  string ha="hahaha";
  TString result= "scale(WZTo3LNu/WZTo3LNu01): 7.9 at Z-peak";
  ///TString *reskult= "scale(WZTo3LNu/WZTo3LNu01): "+str.c_str();
  pt->AddText("Assuming the same cross section to WZTo3LNu(4.42965)");
  pt->AddText("Normalize to be 1/fb");
  TText *txt1 = pt->AddText(result);
  txt1->SetTextSize(0.03);
  pt->Draw();

  myCan->SaveAs("WZTo3LNuOvWZTo3LNu01.pdf");
  myCan->SaveAs("WZTo3LNuOvWZTo3LNu01.png");



}
