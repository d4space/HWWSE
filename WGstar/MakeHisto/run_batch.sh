#!/bin/sh
LUMINOSITY=2.264 #16Dec2015 RECO of 2015C and 2015D datasets, available in 76x latinos
NJETS=(0)
CHANNELS="MuMu"


#SAMPLES="          \
#WZ3LNu         \
#WgammaStarToLNuMuMu       \
#"


#WJetsLNu_HT  \
SAMPLES="          \
DataRun2015     \
WJetsLNu  \
ggWWto2L           \
WWTo2L2Nu          \
WZ                 \
WZ2Q                 \
WZ3LNu         \
ZZ                 \
TTbar                 \
TW                 \
DY           \
DYtautau           \
WgammaNoStar       \
WgammaStarToLNuMuMu       \
WgammaStarToLNuEE       \
HWW125             \
Zgamma             \
"

PWD=`pwd`

#Loop
for CHANNEL in $CHANNELS; do
  for SAMPLE in $SAMPLES; do
    for NJET in ${NJETS[@]}; do
      echo "#!/bin/sh" >& run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      #echo "export SCRAM_ARCH=slc6_amd64_gcc493" >> run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      #echo "if [ -f /cvmfs/cms.cern.ch/cmsset_default.sh ]; then" >> run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      echo "  source /cvmfs/cms.cern.ch/cmsset_default.sh" >> run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      #echo "fi" >> run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      echo "cd $PWD" >> run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      echo "cmsenv" >> run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      #echo "root -l -b -q LatinosTreeScript.C\+\($LUMINOSITY,$NJET,\\\"$CHANNEL\\\",\\\"$SAMPLE\\\",\\\"GenStudy\\\",\\\"true\\\"\)" >> run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      echo "root -l -b -q LatinosTreeScript.C\+\($LUMINOSITY,$NJET,\\\"$CHANNEL\\\",\\\"$SAMPLE\\\",\\\"Nominal\\\",\\\"true\\\"\)" >> run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      chmod u+x run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      #qsub -q short run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh
      qsub -q cms run_${CHANNEL}_${SAMPLE}_${NJET}jet.sh

    done
  done
done
