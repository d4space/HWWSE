#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TProfile.h>
#include <TLegend.h>

#include <iostream>

#define PtlIdx 0 // 13 hHFPlus
#define PtlTT 16
void ctlMetXY()
{
  gStyle->SetOptStat(0);
  int metBin(6);
  int vtxBin(5);
   TChain * fChain = new TChain("metPhiCorrInfoWriter/Events","");
   //fChain->Add("histo_data.root/metPhiCorrInfoWriter/Events");
   fChain->Add("~/WorkDir/MetPhiCorrection/CMSSW_8_0_9/src/MetTools/MetPhiCorrections/test/histo_Run2016B_noMetcut.root/metPhiCorrInfoWriter/Events");

   if (fChain == 0) return;

   // Declaration of leaf types
   vector<int>     *Count_catagory;
   vector<int>     *Count_counts;
   vector<double>  *Count_MetX;
   vector<double>  *Count_MetY;
   vector<double>  *Count_pfMetT;
   vector<double>  *Count_pfMetX;
   vector<double>  *Count_pfMetY;
   vector<int>     *nVtx_catagory;
   vector<int>     *nVtx_nVtx;
   vector<double>  *nVtx_MetX;
   vector<double>  *nVtx_MetY;
   vector<double>  *nVtx_pfMetT;
   vector<double>  *nVtx_pfMetX;
   vector<double>  *nVtx_pfMetY;
   vector<int>     *sumPt_catagory;
   vector<double>  *sumPt_sumPt;
   vector<double>  *sumPt_MetX;
   vector<double>  *sumPt_MetY;
   vector<double>  *sumPt_pfMetT;
   vector<double>  *sumPt_pfMetX;
   vector<double>  *sumPt_pfMetY;

   // List of branches
   TBranch        *b_Count_catagory;   //!
   TBranch        *b_Count_counts;   //!
   TBranch        *b_Count_MetX;   //!
   TBranch        *b_Count_MetY;   //!
   TBranch        *b_Count_pfMetT;   //!
   TBranch        *b_Count_pfMetX;   //!
   TBranch        *b_Count_pfMetY;   //!
   TBranch        *b_nVtx_catagory;   //!
   TBranch        *b_nVtx_nVtx;   //!
   TBranch        *b_nVtx_MetX;   //!
   TBranch        *b_nVtx_MetY;   //!
   TBranch        *b_nVtx_pfMetT;   //!
   TBranch        *b_nVtx_pfMetX;   //!
   TBranch        *b_nVtx_pfMetY;   //!
   TBranch        *b_sumPt_catagory;   //!
   TBranch        *b_sumPt_sumPt;   //!
   TBranch        *b_sumPt_MetX;   //!
   TBranch        *b_sumPt_MetY;   //!
   TBranch        *b_sumPt_pfMetT;   //!
   TBranch        *b_sumPt_pfMetX;   //!
   TBranch        *b_sumPt_pfMetY;   //!

   // Set object pointer
   Count_catagory = 0;
   Count_counts = 0;
   Count_MetX = 0;
   Count_MetY = 0;
   Count_pfMetT = 0;
   Count_pfMetX = 0;
   Count_pfMetY = 0;
   nVtx_catagory = 0;
   nVtx_nVtx = 0;
   nVtx_MetX = 0;
   nVtx_MetY = 0;
   nVtx_pfMetT = 0;
   nVtx_pfMetX = 0;
   nVtx_pfMetY = 0;
   sumPt_catagory = 0;
   sumPt_sumPt = 0;
   sumPt_MetX = 0;
   sumPt_MetY = 0;
   sumPt_pfMetT = 0;
   sumPt_pfMetX = 0;
   sumPt_pfMetY = 0;

   fChain->SetBranchAddress("Count_catagory", &Count_catagory, &b_Count_catagory);
   fChain->SetBranchAddress("Count_counts", &Count_counts, &b_Count_counts);
   fChain->SetBranchAddress("Count_MetX", &Count_MetX, &b_Count_MetX);
   fChain->SetBranchAddress("Count_MetY", &Count_MetY, &b_Count_MetY);
   fChain->SetBranchAddress("Count_pfMetT", &Count_pfMetT, &b_Count_pfMetT);
   fChain->SetBranchAddress("Count_pfMetX", &Count_pfMetX, &b_Count_pfMetX);
   fChain->SetBranchAddress("Count_pfMetY", &Count_pfMetY, &b_Count_pfMetY);
   fChain->SetBranchAddress("nVtx_catagory", &nVtx_catagory, &b_nVtx_catagory);
   fChain->SetBranchAddress("nVtx_nVtx", &nVtx_nVtx, &b_nVtx_nVtx);
   fChain->SetBranchAddress("nVtx_MetX", &nVtx_MetX, &b_nVtx_MetX);
   fChain->SetBranchAddress("nVtx_MetY", &nVtx_MetY, &b_nVtx_MetY);
   fChain->SetBranchAddress("nVtx_pfMetT", &nVtx_pfMetT, &b_nVtx_pfMetT);
   fChain->SetBranchAddress("nVtx_pfMetX", &nVtx_pfMetX, &b_nVtx_pfMetX);
   fChain->SetBranchAddress("nVtx_pfMetY", &nVtx_pfMetY, &b_nVtx_pfMetY);
   fChain->SetBranchAddress("sumPt_catagory", &sumPt_catagory, &b_sumPt_catagory);
   fChain->SetBranchAddress("sumPt_sumPt", &sumPt_sumPt, &b_sumPt_sumPt);
   fChain->SetBranchAddress("sumPt_MetX", &sumPt_MetX, &b_sumPt_MetX);
   fChain->SetBranchAddress("sumPt_MetY", &sumPt_MetY, &b_sumPt_MetY);
   fChain->SetBranchAddress("sumPt_pfMetT", &sumPt_pfMetT, &b_sumPt_pfMetT);
   fChain->SetBranchAddress("sumPt_pfMetX", &sumPt_pfMetX, &b_sumPt_pfMetX);
   fChain->SetBranchAddress("sumPt_pfMetY", &sumPt_pfMetY, &b_sumPt_pfMetY);

   Long64_t nentries = fChain->GetEntriesFast();
   //nentries = 30;

   Long64_t nbytes = 0, nb = 0;

   TCanvas *myCan = new TCanvas("myCan","myCan");
   TProfile *pr_MEx_vtx         = new TProfile("pr_MEx_vtx","pr_MEx_vtx",20,0,40);
   TProfile *pr_MEy_vtx         = new TProfile("pr_MEy_vtx","pr_MEy_vtx",20,0,40);
   TProfile *pr_MEx_pfMetT_vtx[vtxBin];
   TProfile *pr_MEx_vtx_pfMetT[metBin];
   TProfile *pr_MEy_vtx_pfMetT[metBin];
   TProfile *pr_MEx_pfMetT = new TProfile("pr_MEx_pfMetT","pr_MEx_pfMetT",30,0,90);
   TString name;
   for(int i(0);i<vtxBin;i++){
     name = Form("pr_MEx_pfMetT_vtx%d", (i+1)*metBin);
     pr_MEx_pfMetT_vtx[i]  = new TProfile(name,name,30,0,90);
   }
   for(int i(0); i<metBin;i++){
     name = Form("pr_MEx_vtx_pfMetT%d", (i+1)*metBin);
     pr_MEx_vtx_pfMetT[i]  = new TProfile(name,name,20,0,40);
     pr_MEx_vtx_pfMetT[i]->SetMaximum(5);
     pr_MEx_vtx_pfMetT[i]->SetMinimum(-3);

     name = Form("pr_MEy_vtx_pfMetT%d", (i+1)*metBin);
     pr_MEy_vtx_pfMetT[i]  = new TProfile(name,name,20,0,40);
     pr_MEy_vtx_pfMetT[i]->SetMaximum(5);
     pr_MEy_vtx_pfMetT[i]->SetMinimum(-3);
   }
   TH1D *h_pfMetT                = new TH1D("h_pfMetT","h_pfMetT",50,0,100);

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = fChain->LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //cout<<"size catagory: "<<nVtx_catagory->size()<<endl; // size 16
      for(unsigned i(0); i < nVtx_catagory->size(); i++){
	if( (*nVtx_catagory)[i] % PtlTT == PtlIdx){ // 12(hHFMinus)
	  h_pfMetT->Fill((*nVtx_pfMetT)[i]);
	  pr_MEx_vtx->Fill((*nVtx_nVtx)[i],(*nVtx_MetX)[i]);
	  pr_MEy_vtx->Fill((*nVtx_nVtx)[i],(*nVtx_MetY)[i]);
	  pr_MEx_pfMetT->Fill((*nVtx_pfMetT)[i], (*nVtx_MetX)[i]);
	  for(int j(0); j<vtxBin;j++){ // As a ftn of MET
	    if((*nVtx_nVtx)[i] > j*5 && (*nVtx_nVtx)[i] <=(j+1)*5){
	      pr_MEx_pfMetT_vtx[j]->Fill((*nVtx_pfMetT)[i], (*nVtx_MetX)[i]);
	    }
	  }

	  for( int j(0); j<metBin; j++) // As a ftn of vtx
	  {
	    if(j==metBin-1){
	      if( (*nVtx_pfMetT)[i] > j*10 )
	      {
	        pr_MEx_vtx_pfMetT[j]->Fill((*nVtx_nVtx)[i], (*nVtx_MetX)[i]);
	        pr_MEy_vtx_pfMetT[j]->Fill((*nVtx_nVtx)[i], (*nVtx_MetY)[i]);
	      }
	    }else{
	      if( (*nVtx_pfMetT)[i] > j*10 && (*nVtx_pfMetT)[i] < (j+1)*10 )
	      {
	        pr_MEx_vtx_pfMetT[j]->Fill((*nVtx_nVtx)[i], (*nVtx_MetX)[i]);
	        pr_MEy_vtx_pfMetT[j]->Fill((*nVtx_nVtx)[i], (*nVtx_MetY)[i]);
	      }
	    }
	  }
	}
        //cout<<"nVtx_catagory: "<<(*nVtx_catagory)[i]<<endl;
      }
      // if (Cut(ientry) < 0) continue;
   }
   pr_MEx_vtx->Draw();
   myCan->SaveAs("prTest_MEx_vtx.png");
   h_pfMetT->Draw();
   myCan->SaveAs("h_pfMetT.png");
   pr_MEx_pfMetT->Draw();
   myCan->SaveAs("pr_MEx_pfMetT.png");

   TLegend *leg = new TLegend(0.5373563,0.7097458,0.8577586,0.8474576,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetTextSize(0.03330866);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->SetBorderSize(0);

   for(int i(0);i<vtxBin;i++)
   {
     pr_MEx_pfMetT_vtx[i]->SetLineColor(i+1);
     if(i == 0) pr_MEx_pfMetT_vtx[i]->Draw();
     else pr_MEx_pfMetT_vtx[i]->Draw("same");
     name = Form("pr_MEx_pfMetT_vtx_%d_%d",i*metBin, (i+1)*metBin);
     leg->AddEntry(pr_MEx_pfMetT_vtx[i],name,"lp");
   }

   leg->Draw("same");
   name = Form("pr_MEx_pfMetT_vtxes.png");
   myCan->SaveAs(name);

   TLegend *l_MEx_vtx = new TLegend(0.2373563,0.6097458,0.5577586,0.8474576,NULL,"brNDC");
   l_MEx_vtx->SetTextFont(62);
   l_MEx_vtx->SetTextSize(0.03330866);
   l_MEx_vtx->SetLineColor(1);
   l_MEx_vtx->SetLineStyle(1);
   l_MEx_vtx->SetLineWidth(1);
   l_MEx_vtx->SetFillColor(0);
   l_MEx_vtx->SetFillStyle(1001);
   l_MEx_vtx->SetBorderSize(0);

   for(int i(0);i<metBin;i++)
   {
     pr_MEx_vtx_pfMetT[i]->SetLineColor(i+1);
     pr_MEx_vtx_pfMetT[i]->SetMarkerColor(i+1);
     pr_MEx_vtx_pfMetT[i]->SetMarkerStyle(22);
     pr_MEx_vtx_pfMetT[i]->SetMarkerSize(1);

     if(i == 0){
       pr_MEx_vtx_pfMetT[i]->SetTitle("<MetX> vs vtx");
       pr_MEx_vtx_pfMetT[i]->Draw();
     }else pr_MEx_vtx_pfMetT[i]->Draw("same");

     if(i == metBin-1){
       name = Form("pfMetT_%d_%d",i*10, 100);
       l_MEx_vtx->AddEntry(pr_MEx_vtx_pfMetT[i],name,"lp");
     }else{
       name = Form("pfMetT_%d_%d",i*10, (i+1)*10);
       l_MEx_vtx->AddEntry(pr_MEx_vtx_pfMetT[i],name,"lp");
     }

   }
   pr_MEx_vtx->SetMarkerStyle(20);
   pr_MEx_vtx->Draw("same");
   l_MEx_vtx->AddEntry(pr_MEx_vtx,"all","lp");

   l_MEx_vtx->Draw("same");
   name = Form("pr_MEx_vtx_pfMetTes.png");
   myCan->SaveAs(name);

   TLegend *l_MEy_vtx = new TLegend(0.2373563,0.6097458,0.5577586,0.8474576,NULL,"brNDC");
   l_MEy_vtx->SetTextFont(62);
   l_MEy_vtx->SetTextSize(0.03330866);
   l_MEy_vtx->SetLineColor(1);
   l_MEy_vtx->SetLineStyle(1);
   l_MEy_vtx->SetLineWidth(1);
   l_MEy_vtx->SetFillColor(0);
   l_MEy_vtx->SetFillStyle(1001);
   l_MEy_vtx->SetBorderSize(0);

   for(int i(0);i<metBin;i++)
   {
     pr_MEy_vtx_pfMetT[i]->SetLineColor(i+1);
     pr_MEy_vtx_pfMetT[i]->SetMarkerColor(i+1);
     pr_MEy_vtx_pfMetT[i]->SetMarkerStyle(22);
     pr_MEy_vtx_pfMetT[i]->SetMarkerSize(1);

     if(i == 0){
       pr_MEy_vtx_pfMetT[i]->SetTitle("<MetY> vs vtx");
       pr_MEy_vtx_pfMetT[i]->Draw();
     }else pr_MEy_vtx_pfMetT[i]->Draw("same");

     if(i == metBin-1){
       name = Form("pfMetT_%d_%d",i*10, 100);
       l_MEy_vtx->AddEntry(pr_MEy_vtx_pfMetT[i],name,"lp");
     }else{
       name = Form("pfMetT_%d_%d",i*10, (i+1)*10);
       l_MEy_vtx->AddEntry(pr_MEy_vtx_pfMetT[i],name,"lp");
     }
   }
   pr_MEy_vtx->SetMarkerStyle(20);
   pr_MEy_vtx->Draw("same");
   l_MEy_vtx->AddEntry(pr_MEy_vtx,"all","lp");

   l_MEy_vtx->Draw("same");
   name = Form("pr_MEy_vtx_pfMetTes.png");
   myCan->SaveAs(name);
   
}
