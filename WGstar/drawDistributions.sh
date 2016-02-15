#!/bin/bash


#void drawDistributions(Int_t    njet       = 1,
#		       TString  channel    = "All",
#		       Double_t luminosity = 19365,
#		       TString  format     = "png",
#		       Bool_t   drawRatio  = true,
#		       Bool_t   dataDriven = true,
#		       Bool_t   setLogy    = false)
#{

##CHANNEL=\"All\"
#CHANNEL=\"OF\"
#NJET=0
#root -l -b -q drawDistributions.C\($NJET,$CHANNEL,19365,\"pdf\",true,true,false\)
#root -l -q drawDistributions.C\($NJET,$CHANNEL,19365,\"png\",true,true,false\)

#NJET=1
#root -l -b -q drawDistributions.C\($NJET,$CHANNEL,19365,\"pdf\",true,true,false\)

# For the same sign 0, 1, 2 jet
CHANNEL=\"MuMu\"
NJET=0
#                                njet,channel ,lumi,pdf  ,ratio,,dataDriven, setlogy
rm -f files/0jet_hInvDimu_Recon.root
rm -f pdf/0jet/MuMu/hInvDimu_Recon_Lin.pdf

root -l -b -q drawDistributions.C\($NJET,$CHANNEL,553,\"pdf\",true,false,false\)

open pdf/0jet/MuMu/hInvDimu_Recon_Lin.pdf
