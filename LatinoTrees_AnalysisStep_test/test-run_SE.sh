if [ $# -lt 1 ]; then
    echo "  "
    echo "  ./test-run.sh EVENTS"
    echo "  "
    exit -1
fi

export EVENTS=$1

if [ $# == 2 ]; then
  export MYFILE=file:$2
  echo "file name is $MYFILE"
else
  export MYFILE=file:/afs/cern.ch/work/p/piedra/public/store/data/Run2015D/DoubleMuon/MINIAOD/PromptReco-v4/000/258/159/00000/28A6C3C3-6F6C-E511-94A4-02163E01459B.root
fi

#export MYFILE=root://xrootd.unl.edu//store/data/Run2015D/DoubleMuon/MINIAOD/PromptReco-v4/000/258/159/00000/0C6D4AB0-6F6C-E511-8A64-02163E0133CD.root

#export MYFILE=file:/afs/cern.ch/work/p/piedra/public/store/data/Run2015D/DoubleEG/MINIAOD/PromptReco-v4/000/258/175/00000/FA1AB2EB-436D-E511-8DF2-02163E011E2B.root


rm -rf latino_stepB_numEvent${EVENTS}.root

#    globalTag=74X_mcRun2_asymptotic_v4\
#    globalTag=74X_dataRun2_v5 \

cmsRun stepB.py print         \
    reportEvery=10                      \
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

python cmssw2latino.py stepB_numEvent${EVENTS}.root

rm -rf stepB_numEvent${EVENTS}.root
