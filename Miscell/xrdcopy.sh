#!/bin/bash

# copy file list from DAS system, delete "," at end of file name.
List=(
       '/store/mc/RunIIFall15MiniAODv2/WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/006E0803-DCB8-E511-8B8E-02163E017649.root'
       '/store/mc/RunIIFall15MiniAODv2/WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/042C25F7-DBB8-E511-9178-2C600CAFEF7C.root'
)
for name in ${List[@]};
do
  echo "xrdcp root://xrootd-cms.infn.it/$name"
  xrdcp root://xrootd-cms.infn.it/$name .
done
