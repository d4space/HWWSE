if [ $# -lt 2 ] || [ $# -gt 3 ]; then
    echo "  "
    echo "  ./test-run_Batch.sh index [EVENTS] inputFile"
    echo "  "
    exit -1
fi

if [ $# == 2 ]; then
  export Index=$1
  export EVENTS=-1
  export MYFILE=$2
elif [ $# == 3 ]; then
  export Index=$1
  export EVENTS=$2
  export MYFILE=$3
fi
echo "file name is $MYFILE"

#####
### MC example
#####

if [ $# == 3 ]; then
  rm -rf latino_stepB_${Index}_numEvent${EVENTS}.root
else
  rm -rf latino_stepB_${Index}.root
fi

    #maxEvents=3000                      \
cmsRun stepB.py print                   \
    reportEvery=500                      \
    summary=false                       \
    is50ns=False                        \
    isPromptRecoData=True               \
    globalTag=76X_mcRun2_asymptotic_v12 \
    label=ggH                           \
    outputFile=stepB_${Index}.root      \
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
                    
if [ $# == 3 ]; then
  rm -rf latino_stepB_${Index}_numEvent${EVENTS}.root
  python cmssw2latino.py stepB_${Index}_numEvent${EVENTS}.root
  rm -rf stepB_${Index}_numEvent${EVENTS}.root
else
  rm -rf latino_stepB_${Index}.root
  python cmssw2latino.py stepB_${Index}.root
  rm -rf stepB_${Index}.root
fi


