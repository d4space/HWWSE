if [ $# -lt 1 ] || [ $# -gt 2 ]; then
    echo "  "
    echo "  ./test-run.sh [EVENTS] inputFileName"
    echo "  "
    exit -1
fi

if [ $# == 1 ]; then
  export MYFILE=file:$1
  export EVENTS=-1
elif [ $# == 2 ]; then
  export EVENTS=$1
  export MYFILE=file:$2
fi

#if [ $# == 2 ]; then
#  export MYFILE=file:$2
#  echo "file name is $MYFILE"
#else
#  export MYFILE=file:/afs/cern.ch/work/p/piedra/public/store/data/Run2015D/DoubleMuon/MINIAOD/PromptReco-v4/000/258/159/00000/28A6C3C3-6F6C-E511-94A4-02163E01459B.root
#fi

#export MYFILE=root://xrootd.unl.edu//store/data/Run2015D/DoubleMuon/MINIAOD/PromptReco-v4/000/258/159/00000/0C6D4AB0-6F6C-E511-8A64-02163E0133CD.root

#export MYFILE=file:/afs/cern.ch/work/p/piedra/public/store/data/Run2015D/DoubleEG/MINIAOD/PromptReco-v4/000/258/175/00000/FA1AB2EB-436D-E511-8DF2-02163E011E2B.root

if [ $# == 2 ]; then
  rm -rf latino_stepB_numEvent${EVENTS}.root
else
  rm -rf latino_stepB.root
fi

#    globalTag=74X_mcRun2_asymptotic_v4\
#    globalTag=74X_dataRun2_v5 \

cmsRun stepB.py print         \
    reportEvery=100                      \
    summary=false                       \
    is50ns=False                        \
    isPromptRecoData=True               \
    globalTag=76X_mcRun2_asymptotic_v12 \
    label=ggH                           \
    outputFile=stepB.root               \
    selection=LooseNoIso                \
    doNoFilter=False                    \
    doMuonIsoId=True                    \
    doEleIsoId=True                     \
    doPhotonID=True                     \
    doGen=True                          \
    doBTag=True                         \
    doFatJet=True                       \
    doLHE=True                          \
    doMCweights=True                    \
    maxEvents=${EVENTS}                 \
    inputFiles=${MYFILE}
#   LHEweightSource=externalLHEProducer \

if [ $# == 2 ]; then
  rm -rf latino_stepB_numEvent${EVENTS}.root
  python cmssw2latino.py stepB_numEvent${EVENTS}.root
  rm -rf stepB_numEvent${EVENTS}.root
else
  rm -rf latino_stepB.root
  python cmssw2latino.py stepB.root
  rm -rf stepB.root
fi

