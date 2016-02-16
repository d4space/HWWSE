
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

  TH1F *Frame = new TH1F("Frame","Frame",5,0,85);
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
 
 double value_x_1sigma_obs = findCrossingOfScan1D(*gr_Obs012, 1.00);
 double value_x_2sigma_obs = findCrossingOfScan1D(*gr_Obs012, 3.84);
 std::cout << " 012-jet Observed " << std::endl;
 std::cout << " value_x_1sigma_obs = " << value_x_1sigma_obs << std::endl;
 std::cout << " value_x_2sigma_obs = " << value_x_2sigma_obs << std::endl;
 myfile    << " 012-jet Observed " << std::endl;
 myfile    << " value_x_1sigma_obs = " << value_x_1sigma_obs << std::endl;
 myfile    << " value_x_2sigma_obs = " << value_x_2sigma_obs << std::endl;
 
 //gPad->SetGrid();

   graph = new TGraph(2);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineStyle(9);
   graph->SetMarkerStyle(0);
   graph->SetMarkerSize(0);
   graph->SetPoint(0,0,1);
   graph->SetPoint(1,75,1);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,0,82.5);
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
   graph->SetPoint(1,75,3.84);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Graph",100,0,82.5);
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
   entry=leg->AddEntry(gr_Obs012,"WW+ZZ (Observed)","l");
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


