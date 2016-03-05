#include "TMath.h"
//#include "RooRealVar.h"

double metPlusSolution(double *x, double *par){
  double lepPt=par[0];
  double WpT=par[1];
  double insideSqrt= lepPt*lepPt*TMath::Cos(x[0])*TMath::Cos(x[0]) + WpT*WpT - lepPt*lepPt;
  if (insideSqrt <0) return 0;

  double value= -lepPt*TMath::Cos( x[0] ) + TMath::Sqrt(insideSqrt);
  return TMath::Max(0., value);
}
double metMinusSolution(double *x, double *par){
  double lepPt=par[0];
  double WpT=par[1];
  double insideSqrt= lepPt*lepPt*TMath::Cos(x[0])*TMath::Cos(x[0]) + WpT*WpT - lepPt*lepPt;
  if (insideSqrt <0) return 0;

  double value= -lepPt*TMath::Cos( x[0] ) - TMath::Sqrt(insideSqrt);
  return TMath::Max(0., value);
}

void MetAtWpT_Toy()
{
  TCanvas *myCan=new TCanvas("myCan","myCan",800, 800);

  // WpT 17_5===================
  TF1 *metFcnPW = new TF1("met vs. theta", metPlusSolution, 0,3.14, 2);
  TF1 *metFcnMW = new TF1("met vs. theta", metMinusSolution, 0,3.14, 2);
  double theta, WpT, LepPt;
  TH1D *hMet=new TH1D("hMet","hMet",100,0,130);
  for(int k(0); k<100;k++)
  {
    WpT = (24-17.5)/100.*k + 17.5;
    metFcnPW->SetParameter(1, WpT);
    metFcnMW->SetParameter(1, WpT);
  for(int j(0); j<100;j++)
  {
    LepPt = (100-25)/100.*j + 25;
    metFcnPW->SetParameter(0,LepPt);
    metFcnMW->SetParameter(0,LepPt);
  for(int i(0); i<100;i++)
  {
    theta = (3.14-1.5)/100*i+1.5;
    hMet->Fill(metFcnPW->Eval(theta));
    hMet->Fill(metFcnMW->Eval(theta));
    //cout<<"theta: "<<i<<" value:"<<metFcnPW17_5Lep25->Eval(double(i))<<endl;
  }
  }
  }
  hMet->SetBinContent(1,0);
  hMet->Draw();
  myCan->SaveAs("MetRangeWpT_Toy.pdf");


}
