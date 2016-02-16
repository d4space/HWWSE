
#include "tools.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#define Gamma  1

//---- alsoSevenTeV
//---- 1 = 7+8 TeV
//---- 2 = 8   TeV
//---- 3 = 7   TeV

void drawExpObsKvbf(  float maxX = 15.0) {
 
  std::ofstream myfile;
  myfile.open ("results.txt",std::ofstream::out | std::ofstream::app);
  TCanvas *cc = new TCanvas("cc", "cc",0,0,700,700); // Paper Style
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  cc->SetHighLightColor(2);
  cc->Range(-11.89024,-1.625,79.57317,10.875);
  cc->SetFillColor(0);
  cc->SetBorderMode(0);
  cc->SetBorderSize(2);
  cc->SetTickx(1);
  cc->SetTicky(1);
  cc->SetLeftMargin(0.13);
  cc->SetRightMargin(0.05);
  cc->SetTopMargin(0.07);
  //cc->SetBottomMargin(0.13);
  cc->SetBottomMargin(0.155);
  cc->SetFrameFillStyle(0);
  cc->SetFrameBorderMode(0);
  cc->SetFrameFillStyle(0);
  cc->SetFrameBorderMode(0);

  //cc->SetTicks();

  TH1F *Frame = new TH1F("Frame","Frame",5,0,100);
  //TH1F *Frame = new TH1F("Frame","Frame",5,0,75);
  Frame->SetMinimum(0);
  Frame->SetMaximum(14);
  Frame->SetFillColor(63);
  Frame->SetLineStyle(0);
  Frame->SetMarkerStyle(20);
  Frame->GetXaxis()->SetTitle("#mu_{VBF}^{off-shell}");
  Frame->GetXaxis()->SetNdivisions(505);
  Frame->GetXaxis()->SetLabelFont(42);
  Frame->GetXaxis()->SetLabelOffset(0.007);
  Frame->GetXaxis()->SetLabelSize(0.05);
  Frame->GetXaxis()->SetTitleSize(0.06);
  //Frame->GetXaxis()->SetTitleOffset(0.9);
  Frame->GetXaxis()->SetTitleOffset(1.1);
  Frame->GetXaxis()->SetTitleFont(42);
  Frame->GetYaxis()->SetTitle("-2 #Delta ln L");
  Frame->GetYaxis()->SetNdivisions(507);
  Frame->GetYaxis()->SetLabelFont(42);
  Frame->GetYaxis()->SetLabelOffset(0.007);
  Frame->GetYaxis()->SetLabelSize(0.05);
  Frame->GetYaxis()->SetTitleSize(0.06);
  Frame->GetYaxis()->SetTitleOffset(1.05);
  Frame->GetYaxis()->SetTitleFont(42);
  Frame->GetZaxis()->SetLabelFont(42);
  Frame->GetZaxis()->SetLabelOffset(0.007);
  Frame->GetZaxis()->SetLabelSize(0.05);
  Frame->GetZaxis()->SetTitleSize(0.06);
  Frame->GetZaxis()->SetTitleFont(42);
  Frame->Draw("");
 
  TTree* Obs_0     = (TTree*) _file0->Get("limit");
  TTree* Asi_0     = (TTree*) _file1->Get("limit");
  TTree* Obs_1     = (TTree*) _file2->Get("limit");
  TTree* Asi_1     = (TTree*) _file3->Get("limit");
  TTree* Obs_2     = (TTree*) _file4->Get("limit");
  TTree* Asi_2     = (TTree*) _file5->Get("limit");
  TTree* Obs_012   = (TTree*) _file6->Get("limit");
  TTree* Asi_012   = (TTree*) _file7->Get("limit");

  int n = 0;

  // 0+1+2 jet==================
  
  n = Obs_012->Draw("2*deltaNLL:kV_off","deltaNLL<100","goff");
  cout<<"the number of points: "<<n<<endl;


  TGraph *gr_Obs012 = new TGraph(n,Obs_012->GetV2(),Obs_012->GetV1());
  gr_Obs012->RemovePoint(0);
  moveTGraph(gr_Obs012);
  gr_Obs012->SetTitle("");
  gr_Obs012->SetMarkerStyle(21);
  gr_Obs012->SetLineWidth(2);
  gr_Obs012->SetMarkerColor(kRed);
  gr_Obs012->SetLineColor(kRed);
  std::cout << " n = " << n << std::endl;
  TH1F *h_Obs012 = new TH1F("h_Obs012","Graph",243,0,maxX);
  h_Obs012->SetMinimum(0);
  h_Obs012->SetMaximum(9.181659);
  h_Obs012->SetDirectory(0);
  h_Obs012->SetStats(0);
  h_Obs012->SetFillColor(63);
  h_Obs012->SetLineStyle(0);
  h_Obs012->SetMarkerStyle(20);
  h_Obs012->GetXaxis()->SetTitle("#Gamma_{H} (MeV)");
  h_Obs012->GetXaxis()->SetLabelFont(42);
  h_Obs012->GetXaxis()->SetLabelOffset(0.007);
  h_Obs012->GetXaxis()->SetLabelSize(0.05);
  h_Obs012->GetXaxis()->SetTitleSize(0.06);
  h_Obs012->GetXaxis()->SetTitleOffset(0.9);
  h_Obs012->GetXaxis()->SetTitleFont(42);
  h_Obs012->GetYaxis()->SetTitle("-2 #Delta ln L");
  h_Obs012->GetYaxis()->SetLabelFont(42);
  h_Obs012->GetYaxis()->SetLabelOffset(0.007);
  h_Obs012->GetYaxis()->SetLabelSize(0.05);
  h_Obs012->GetYaxis()->SetTitleSize(0.06);
  h_Obs012->GetYaxis()->SetTitleOffset(1.05);
  h_Obs012->GetYaxis()->SetTitleFont(42);
  h_Obs012->GetZaxis()->SetLabelFont(42);
  h_Obs012->GetZaxis()->SetLabelOffset(0.007);
  h_Obs012->GetZaxis()->SetLabelSize(0.05);
  h_Obs012->GetZaxis()->SetTitleSize(0.06);
  h_Obs012->GetZaxis()->SetTitleFont(42);
  gr_Obs012->SetHistogram(h_Obs012);
  gr_Obs012->Draw("l");
 
 //  2deltaLogL = 1.00
 //  2deltaLogL = 3.84

   // Check the 95 % CL
 
 double value_x_1sigma = findCrossingOfScan1D(*gr_Obs012, 1.00);
 double value_x_2sigma = findCrossingOfScan1D(*gr_Obs012, 3.84);
 std::cout << " 012-jet Observed " << std::endl;
 std::cout << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 std::cout << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 myfile    << " 012-jet Observed " << std::endl;
 myfile    << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 myfile    << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 // Asimov 0+1+2 jet==================
 n = Asi_012->Draw("2*deltaNLL:kV_off","deltaNLL<100","goff");

 std::cout << " n = " << n << std::endl;
 TGraph *gr_Asi012 = new TGraph(n,Asi_012->GetV2(),Asi_012->GetV1());
 gr_Asi012->RemovePoint(0);
 moveTGraph(gr_Asi012);
 gr_Asi012->SetTitle("");
 gr_Asi012->SetMarkerStyle(21);
 gr_Asi012->SetLineStyle(2);
 gr_Asi012->SetLineWidth(2);
 gr_Asi012->SetMarkerColor(kRed);
 gr_Asi012->SetLineColor(kRed);

   TH1F *h_Asi012 = new TH1F("h_Asi012","Graph",243,0,maxX);
   h_Asi012->SetMinimum(0);
   h_Asi012->SetMaximum(9.170711);
   h_Asi012->SetDirectory(0);
   h_Asi012->SetStats(0);
   h_Asi012->SetFillColor(63);
   h_Asi012->SetLineStyle(0);
   h_Asi012->SetMarkerStyle(20);
   h_Asi012->GetXaxis()->SetTitle("#Gamma_{H} (MeV)");
   h_Asi012->GetXaxis()->SetLabelFont(42);
   h_Asi012->GetXaxis()->SetLabelOffset(0.007);
   h_Asi012->GetXaxis()->SetLabelSize(0.05);
   h_Asi012->GetXaxis()->SetTitleSize(0.06);
   h_Asi012->GetXaxis()->SetTitleOffset(0.9);
   h_Asi012->GetXaxis()->SetTitleFont(42);
   h_Asi012->GetYaxis()->SetTitle("-2 #Delta ln L");
   h_Asi012->GetYaxis()->SetLabelFont(42);
   h_Asi012->GetYaxis()->SetLabelOffset(0.007);
   h_Asi012->GetYaxis()->SetLabelSize(0.05);
   h_Asi012->GetYaxis()->SetTitleSize(0.06);
   h_Asi012->GetYaxis()->SetTitleOffset(1.05);
   h_Asi012->GetYaxis()->SetTitleFont(42);
   h_Asi012->GetZaxis()->SetLabelFont(42);
   h_Asi012->GetZaxis()->SetLabelOffset(0.007);
   h_Asi012->GetZaxis()->SetLabelSize(0.05);
   h_Asi012->GetZaxis()->SetTitleSize(0.06);
   h_Asi012->GetZaxis()->SetTitleFont(42);
  gr_Asi012->SetHistogram(h_Asi012);
  gr_Asi012->Draw("lsame");

 value_x_1sigma = findCrossingOfScan1D(*gr_Asi012, 1.00);
 value_x_2sigma = findCrossingOfScan1D(*gr_Asi012, 3.84);
 std::cout << " 012-jet Expected " << std::endl;
 std::cout << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 std::cout << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 myfile    << " 012-jet Expected " << std::endl;
 myfile    << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 myfile    << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;

  // 0 jet==================
  
  n = Obs_0->Draw("2*deltaNLL:kV_off","deltaNLL<100","goff");
  cout<<"the number of points: "<<n<<endl;


  TGraph *gr_Obs0 = new TGraph(n,Obs_0->GetV2(),Obs_0->GetV1());
  gr_Obs0->RemovePoint(0);
  moveTGraph(gr_Obs0);
  gr_Obs0->SetTitle("");
  gr_Obs0->SetMarkerStyle(21);
  gr_Obs0->SetLineWidth(2);
  gr_Obs0->SetMarkerColor(kBlue);
  gr_Obs0->SetLineColor(kBlue);
  std::cout << " n = " << n << std::endl;
  TH1F *h_Obs0 = new TH1F("h_Obs0","Graph",243,0,maxX);
  h_Obs0->SetMinimum(0);
  h_Obs0->SetMaximum(9.181659);
  h_Obs0->SetDirectory(0);
  h_Obs0->SetStats(0);
  h_Obs0->SetFillColor(63);
  h_Obs0->SetLineStyle(0);
  h_Obs0->SetMarkerStyle(20);
  h_Obs0->GetXaxis()->SetTitle("#Gamma_{H} (MeV)");
  h_Obs0->GetXaxis()->SetLabelFont(42);
  h_Obs0->GetXaxis()->SetLabelOffset(0.007);
  h_Obs0->GetXaxis()->SetLabelSize(0.05);
  h_Obs0->GetXaxis()->SetTitleSize(0.06);
  h_Obs0->GetXaxis()->SetTitleOffset(0.9);
  h_Obs0->GetXaxis()->SetTitleFont(42);
  h_Obs0->GetYaxis()->SetTitle("-2 #Delta ln L");
  h_Obs0->GetYaxis()->SetLabelFont(42);
  h_Obs0->GetYaxis()->SetLabelOffset(0.007);
  h_Obs0->GetYaxis()->SetLabelSize(0.05);
  h_Obs0->GetYaxis()->SetTitleSize(0.06);
  h_Obs0->GetYaxis()->SetTitleOffset(1.05);
  h_Obs0->GetYaxis()->SetTitleFont(42);
  h_Obs0->GetZaxis()->SetLabelFont(42);
  h_Obs0->GetZaxis()->SetLabelOffset(0.007);
  h_Obs0->GetZaxis()->SetLabelSize(0.05);
  h_Obs0->GetZaxis()->SetTitleSize(0.06);
  h_Obs0->GetZaxis()->SetTitleFont(42);
  gr_Obs0->SetHistogram(h_Obs0);
  gr_Obs0->Draw("l");
 
 //  2deltaLogL = 1.00
 //  2deltaLogL = 3.84

   // Check the 95 % CL
 
 value_x_1sigma = findCrossingOfScan1D(*gr_Obs0, 1.00);
 value_x_2sigma = findCrossingOfScan1D(*gr_Obs0, 3.84);
 std::cout << " 0-jet Observed " << std::endl;
 std::cout << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 std::cout << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 myfile    << " 0-jet Observed " << std::endl;
 myfile    << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 myfile    << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 // Asimov 0+1+2 jet==================
 n = Asi_0->Draw("2*deltaNLL:kV_off","deltaNLL<100","goff");

 std::cout << " n = " << n << std::endl;
 TGraph *gr_Asi0 = new TGraph(n,Asi_0->GetV2(),Asi_0->GetV1());
 gr_Asi0->RemovePoint(0);
 moveTGraph(gr_Asi0);
 gr_Asi0->SetTitle("");
 gr_Asi0->SetMarkerStyle(21);
 gr_Asi0->SetLineStyle(2);
 gr_Asi0->SetLineWidth(2);
 gr_Asi0->SetMarkerColor(kBlue);
 gr_Asi0->SetLineColor(kBlue);

   TH1F *h_Asi0 = new TH1F("h_Asi0","Graph",243,0,maxX);
   h_Asi0->SetMinimum(0);
   h_Asi0->SetMaximum(9.170711);
   h_Asi0->SetDirectory(0);
   h_Asi0->SetStats(0);
   h_Asi0->SetFillColor(63);
   h_Asi0->SetLineStyle(0);
   h_Asi0->SetMarkerStyle(20);
   h_Asi0->GetXaxis()->SetTitle("#Gamma_{H} (MeV)");
   h_Asi0->GetXaxis()->SetLabelFont(42);
   h_Asi0->GetXaxis()->SetLabelOffset(0.007);
   h_Asi0->GetXaxis()->SetLabelSize(0.05);
   h_Asi0->GetXaxis()->SetTitleSize(0.06);
   h_Asi0->GetXaxis()->SetTitleOffset(0.9);
   h_Asi0->GetXaxis()->SetTitleFont(42);
   h_Asi0->GetYaxis()->SetTitle("-2 #Delta ln L");
   h_Asi0->GetYaxis()->SetLabelFont(42);
   h_Asi0->GetYaxis()->SetLabelOffset(0.007);
   h_Asi0->GetYaxis()->SetLabelSize(0.05);
   h_Asi0->GetYaxis()->SetTitleSize(0.06);
   h_Asi0->GetYaxis()->SetTitleOffset(1.05);
   h_Asi0->GetYaxis()->SetTitleFont(42);
   h_Asi0->GetZaxis()->SetLabelFont(42);
   h_Asi0->GetZaxis()->SetLabelOffset(0.007);
   h_Asi0->GetZaxis()->SetLabelSize(0.05);
   h_Asi0->GetZaxis()->SetTitleSize(0.06);
   h_Asi0->GetZaxis()->SetTitleFont(42);
  gr_Asi0->SetHistogram(h_Asi0);
  gr_Asi0->Draw("lsame");

 value_x_1sigma = findCrossingOfScan1D(*gr_Asi0, 1.00);
 value_x_2sigma = findCrossingOfScan1D(*gr_Asi0, 3.84);
 std::cout << " 0-jet Expected " << std::endl;
 std::cout << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 std::cout << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 myfile    << " 0-jet Expected " << std::endl;
 myfile    << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 myfile    << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;

  // 1 jet==================
  
  n = Obs_1->Draw("2*deltaNLL:kV_off","deltaNLL<100","goff");
  cout<<"the number of points: "<<n<<endl;


  TGraph *gr_Obs1 = new TGraph(n,Obs_1->GetV2(),Obs_1->GetV1());
  gr_Obs1->RemovePoint(0);
  moveTGraph(gr_Obs1);
  gr_Obs1->SetTitle("");
  gr_Obs1->SetMarkerStyle(21);
  gr_Obs1->SetLineWidth(2);
  gr_Obs1->SetMarkerColor(kBlack);
  gr_Obs1->SetLineColor(kBlack);
  std::cout << " n = " << n << std::endl;
  TH1F *h_Obs1 = new TH1F("h_Obs1","Graph",243,0,maxX);
  h_Obs1->SetMinimum(0);
  h_Obs1->SetMaximum(9.181659);
  h_Obs1->SetDirectory(0);
  h_Obs1->SetStats(0);
  h_Obs1->SetFillColor(63);
  h_Obs1->SetLineStyle(0);
  h_Obs1->SetMarkerStyle(20);
  h_Obs1->GetXaxis()->SetTitle("#Gamma_{H} (MeV)");
  h_Obs1->GetXaxis()->SetLabelFont(42);
  h_Obs1->GetXaxis()->SetLabelOffset(0.007);
  h_Obs1->GetXaxis()->SetLabelSize(0.05);
  h_Obs1->GetXaxis()->SetTitleSize(0.06);
  h_Obs1->GetXaxis()->SetTitleOffset(0.9);
  h_Obs1->GetXaxis()->SetTitleFont(42);
  h_Obs1->GetYaxis()->SetTitle("-2 #Delta ln L");
  h_Obs1->GetYaxis()->SetLabelFont(42);
  h_Obs1->GetYaxis()->SetLabelOffset(0.007);
  h_Obs1->GetYaxis()->SetLabelSize(0.05);
  h_Obs1->GetYaxis()->SetTitleSize(0.06);
  h_Obs1->GetYaxis()->SetTitleOffset(1.05);
  h_Obs1->GetYaxis()->SetTitleFont(42);
  h_Obs1->GetZaxis()->SetLabelFont(42);
  h_Obs1->GetZaxis()->SetLabelOffset(0.007);
  h_Obs1->GetZaxis()->SetLabelSize(0.05);
  h_Obs1->GetZaxis()->SetTitleSize(0.06);
  h_Obs1->GetZaxis()->SetTitleFont(42);
  gr_Obs1->SetHistogram(h_Obs1);
  gr_Obs1->Draw("l");
 
 //  2deltaLogL = 1.00
 //  2deltaLogL = 3.84

   // Check the 95 % CL
 
 value_x_1sigma = findCrossingOfScan1D(*gr_Obs1, 1.00);
 value_x_2sigma = findCrossingOfScan1D(*gr_Obs1, 3.84);
 std::cout << " 1-jet Observed " << std::endl;
 std::cout << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 std::cout << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 myfile    << " 1-jet Observed " << std::endl;
 myfile    << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 myfile    << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 // Asimov 0+1+2 jet==================
 n = Asi_1->Draw("2*deltaNLL:kV_off","deltaNLL<100","goff");

 std::cout << " n = " << n << std::endl;
 TGraph *gr_Asi1 = new TGraph(n,Asi_1->GetV2(),Asi_1->GetV1());
 gr_Asi1->RemovePoint(0);
 moveTGraph(gr_Asi1);
 gr_Asi1->SetTitle("");
 gr_Asi1->SetMarkerStyle(21);
 gr_Asi1->SetLineStyle(2);
 gr_Asi1->SetLineWidth(2);
 gr_Asi1->SetMarkerColor(kBlack);
 gr_Asi1->SetLineColor(kBlack);

   TH1F *h_Asi1 = new TH1F("h_Asi1","Graph",243,0,maxX);
   h_Asi1->SetMinimum(0);
   h_Asi1->SetMaximum(9.170711);
   h_Asi1->SetDirectory(0);
   h_Asi1->SetStats(0);
   h_Asi1->SetFillColor(63);
   h_Asi1->SetLineStyle(0);
   h_Asi1->SetMarkerStyle(20);
   h_Asi1->GetXaxis()->SetTitle("#Gamma_{H} (MeV)");
   h_Asi1->GetXaxis()->SetLabelFont(42);
   h_Asi1->GetXaxis()->SetLabelOffset(0.007);
   h_Asi1->GetXaxis()->SetLabelSize(0.05);
   h_Asi1->GetXaxis()->SetTitleSize(0.06);
   h_Asi1->GetXaxis()->SetTitleOffset(0.9);
   h_Asi1->GetXaxis()->SetTitleFont(42);
   h_Asi1->GetYaxis()->SetTitle("-2 #Delta ln L");
   h_Asi1->GetYaxis()->SetLabelFont(42);
   h_Asi1->GetYaxis()->SetLabelOffset(0.007);
   h_Asi1->GetYaxis()->SetLabelSize(0.05);
   h_Asi1->GetYaxis()->SetTitleSize(0.06);
   h_Asi1->GetYaxis()->SetTitleOffset(1.05);
   h_Asi1->GetYaxis()->SetTitleFont(42);
   h_Asi1->GetZaxis()->SetLabelFont(42);
   h_Asi1->GetZaxis()->SetLabelOffset(0.007);
   h_Asi1->GetZaxis()->SetLabelSize(0.05);
   h_Asi1->GetZaxis()->SetTitleSize(0.06);
   h_Asi1->GetZaxis()->SetTitleFont(42);
  gr_Asi1->SetHistogram(h_Asi1);
  gr_Asi1->Draw("lsame");

 value_x_1sigma = findCrossingOfScan1D(*gr_Asi1, 1.00);
 value_x_2sigma = findCrossingOfScan1D(*gr_Asi1, 3.84);
 std::cout << " 1-jet Expected " << std::endl;
 std::cout << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 std::cout << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 myfile    << " 1-jet Expected " << std::endl;
 myfile    << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 myfile    << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
  // 2 jet==================
  
  n = Obs_2->Draw("2*deltaNLL:kV_off","deltaNLL<100","goff");
  cout<<"the number of points: "<<n<<endl;


  TGraph *gr_Obs2 = new TGraph(n,Obs_2->GetV2(),Obs_2->GetV1());
  gr_Obs2->RemovePoint(0);
  moveTGraph(gr_Obs2);
  gr_Obs2->SetTitle("");
  gr_Obs2->SetMarkerStyle(21);
  gr_Obs2->SetLineWidth(2);
  gr_Obs2->SetMarkerColor(kGreen);
  gr_Obs2->SetLineColor(kGreen);
  std::cout << " n = " << n << std::endl;
  TH1F *h_Obs2 = new TH1F("h_Obs2","Graph",243,0,maxX);
  h_Obs2->SetMinimum(0);
  h_Obs2->SetMaximum(9.181659);
  h_Obs2->SetDirectory(0);
  h_Obs2->SetStats(0);
  h_Obs2->SetFillColor(63);
  h_Obs2->SetLineStyle(0);
  h_Obs2->SetMarkerStyle(20);
  h_Obs2->GetXaxis()->SetTitle("#Gamma_{H} (MeV)");
  h_Obs2->GetXaxis()->SetLabelFont(42);
  h_Obs2->GetXaxis()->SetLabelOffset(0.007);
  h_Obs2->GetXaxis()->SetLabelSize(0.05);
  h_Obs2->GetXaxis()->SetTitleSize(0.06);
  h_Obs2->GetXaxis()->SetTitleOffset(0.9);
  h_Obs2->GetXaxis()->SetTitleFont(42);
  h_Obs2->GetYaxis()->SetTitle("-2 #Delta ln L");
  h_Obs2->GetYaxis()->SetLabelFont(42);
  h_Obs2->GetYaxis()->SetLabelOffset(0.007);
  h_Obs2->GetYaxis()->SetLabelSize(0.05);
  h_Obs2->GetYaxis()->SetTitleSize(0.06);
  h_Obs2->GetYaxis()->SetTitleOffset(1.05);
  h_Obs2->GetYaxis()->SetTitleFont(42);
  h_Obs2->GetZaxis()->SetLabelFont(42);
  h_Obs2->GetZaxis()->SetLabelOffset(0.007);
  h_Obs2->GetZaxis()->SetLabelSize(0.05);
  h_Obs2->GetZaxis()->SetTitleSize(0.06);
  h_Obs2->GetZaxis()->SetTitleFont(42);
  gr_Obs2->SetHistogram(h_Obs2);
  gr_Obs2->Draw("l");
 
 //  2deltaLogL = 1.00
 //  2deltaLogL = 3.84

   // Check the 95 % CL
 
 value_x_1sigma = findCrossingOfScan1D(*gr_Obs2, 1.00);
 value_x_2sigma = findCrossingOfScan1D(*gr_Obs2, 3.84);
 std::cout << " 2-jet Observed " << std::endl;
 std::cout << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 std::cout << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 myfile    << " 2-jet Observed " << std::endl;
 myfile    << " value_x_1sigma_obs = " << value_x_1sigma << std::endl;
 myfile    << " value_x_2sigma_obs = " << value_x_2sigma << std::endl;
 // Asimov 2 jet==================
 n = Asi_2->Draw("2*deltaNLL:kV_off","deltaNLL<100","goff");

 std::cout << " n = " << n << std::endl;
 TGraph *gr_Asi2 = new TGraph(n,Asi_2->GetV2(),Asi_2->GetV1());
 gr_Asi2->RemovePoint(0);
 moveTGraph(gr_Asi2);
 gr_Asi2->SetTitle("");
 gr_Asi2->SetMarkerStyle(21);
 gr_Asi2->SetLineStyle(2);
 gr_Asi2->SetLineWidth(2);
 gr_Asi2->SetMarkerColor(kGreen);
 gr_Asi2->SetLineColor(kGreen);

   TH1F *h_Asi2 = new TH1F("h_Asi2","Graph",243,0,maxX);
   h_Asi2->SetMinimum(0);
   h_Asi2->SetMaximum(9.170711);
   h_Asi2->SetDirectory(0);
   h_Asi2->SetStats(0);
   h_Asi2->SetFillColor(63);
   h_Asi2->SetLineStyle(0);
   h_Asi2->SetMarkerStyle(20);
   h_Asi2->GetXaxis()->SetTitle("#Gamma_{H} (MeV)");
   h_Asi2->GetXaxis()->SetLabelFont(42);
   h_Asi2->GetXaxis()->SetLabelOffset(0.007);
   h_Asi2->GetXaxis()->SetLabelSize(0.05);
   h_Asi2->GetXaxis()->SetTitleSize(0.06);
   h_Asi2->GetXaxis()->SetTitleOffset(0.9);
   h_Asi2->GetXaxis()->SetTitleFont(42);
   h_Asi2->GetYaxis()->SetTitle("-2 #Delta ln L");
   h_Asi2->GetYaxis()->SetLabelFont(42);
   h_Asi2->GetYaxis()->SetLabelOffset(0.007);
   h_Asi2->GetYaxis()->SetLabelSize(0.05);
   h_Asi2->GetYaxis()->SetTitleSize(0.06);
   h_Asi2->GetYaxis()->SetTitleOffset(1.05);
   h_Asi2->GetYaxis()->SetTitleFont(42);
   h_Asi2->GetZaxis()->SetLabelFont(42);
   h_Asi2->GetZaxis()->SetLabelOffset(0.007);
   h_Asi2->GetZaxis()->SetLabelSize(0.05);
   h_Asi2->GetZaxis()->SetTitleSize(0.06);
   h_Asi2->GetZaxis()->SetTitleFont(42);
  gr_Asi2->SetHistogram(h_Asi2);
  gr_Asi2->Draw("lsame");

 value_x_1sigma = findCrossingOfScan1D(*gr_Asi2, 1.00);
 value_x_2sigma = findCrossingOfScan1D(*gr_Asi2, 3.84);
 std::cout << " 2-jet Expected " << std::endl;
 std::cout << " value_x_1sigma = " << value_x_1sigma << std::endl;
 std::cout << " value_x_2sigma = " << value_x_2sigma << std::endl;
 myfile    << " 2-jet Expected " << std::endl;
 myfile    << " value_x_1sigma = " << value_x_1sigma << std::endl;
 myfile    << " value_x_2sigma = " << value_x_2sigma << std::endl;



 //gPad->SetGrid();

   graph = new TGraph(2);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineStyle(9);
   graph->SetMarkerStyle(0);
   graph->SetMarkerSize(0);
   graph->SetPoint(0,0,1);
   graph->SetPoint(1,100,1);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,0,100);
   Graph_Graph3->SetMinimum(0.9);
   Graph_Graph3->SetMaximum(2.1);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);
   Graph_Graph3->SetFillColor(63);
   Graph_Graph3->SetLineStyle(0);
   Graph_Graph3->SetMarkerStyle(20);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetYaxis()->SetTitleOffset(1.05);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   graph->Draw("lp");



   
   graph = new TGraph(2);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineStyle(9);
   graph->SetMarkerStyle(0);
   graph->SetMarkerSize(0);
   graph->SetPoint(0,0,3.84);
   graph->SetPoint(1,100,3.84);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Graph",100,0,100);
   Graph_Graph4->SetMinimum(3.74);
   Graph_Graph4->SetMaximum(4.94);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);
   Graph_Graph4->SetFillColor(63);
   Graph_Graph4->SetLineStyle(0);
   Graph_Graph4->SetMarkerStyle(20);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph4->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph4->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetYaxis()->SetTitleOffset(1.05);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph4->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   graph->Draw("lp");
   
   TLegend *leg = new TLegend(0.13,0.701,0.95,0.929,NULL,"brNDC");
   leg-> SetNColumns(2);
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(kWhite);
   leg->SetFillStyle(1001);

   TLegendEntry *entry=leg->AddEntry("NULL","H #rightarrow WW","h");
   entry=leg->AddEntry("gr_Obs0","0-jet (observed)","l");
   entry=leg->AddEntry("gr_Asi0","0-jet (expected)","l");
   entry=leg->AddEntry("gr_Obs1","1-jet (observed)","l");
   entry=leg->AddEntry("gr_Asi1","1-jet (expected)","l");
   entry=leg->AddEntry("gr_Obs2","2-jet (observed)","l");
   entry=leg->AddEntry("gr_Asi2","2-jet (expected)","l");
   entry=leg->AddEntry(gr_Obs012,"0 + 1 + 2 jet (observed)","l");
   entry=leg->AddEntry(gr_Asi012,"0 + 1 + 2 jet (expected)","l");
   leg->Draw();

   
   TPaveText *pt = new TPaveText(0.09,0.9,0.99,0.98,"brtlNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetLineStyle(0);
   pt->SetLineWidth(0);
   pt->SetTextAlign(11);
   pt->SetTextFont(61);
   pt->SetTextSize(0.0429);
   TText *text = pt->AddText("CMS");
   pt->Draw();
   
   //pt = new TPaveText(0.189,0.909,0.99,0.98,"brtlNDC");
   //pt->SetBorderSize(0);
   //pt->SetFillColor(0);
   //pt->SetFillStyle(0);
   //pt->SetLineStyle(0);
   //pt->SetLineWidth(0);
   //pt->SetTextAlign(11);
   //pt->SetTextFont(52);
   //pt->SetTextSize(0.033);
   //text = pt->AddText("Preliminary");
   //pt->Draw();
   
   pt = new TPaveText(0.09,0.909,0.99,0.98,"brtlNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetLineStyle(0);
   pt->SetLineWidth(0);
   pt->SetTextAlign(31);
   pt->SetTextFont(42);
   pt->SetTextSize(0.033);
   text = pt->AddText("19.4 fb^{-1} (8 TeV) + 4.9 fb^{-1} (7 TeV)");
   pt->Draw();
   
   pt = new TPaveText(3,1.05,9,1.5,"br");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt->SetTextSize(0.025);
   text = pt->AddText("68% CL");
   pt->Draw();
   
   pt = new TPaveText(3,3.94,9,4.3,"br");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt->SetTextSize(0.025);
   text = pt->AddText("95% CL");
   pt->Draw();
   cc->Modified();
   cc->cd();
   cc->SetSelected(cc);
 cc->SaveAs("cc.png");
 cc->SaveAs("cc.pdf");
 

 
 myfile.close(); 
 
}


