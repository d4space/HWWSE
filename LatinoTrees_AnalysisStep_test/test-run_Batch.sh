if [ $# -lt 2 ]; then
    echo "  "
    echo "  ./test-run_Batch.sh index inputFile"
    echo "  "
    exit -1
fi

export Index=$1
export MYFILE=file:$2
echo "file name is $MYFILE"

#####
### MC example
#####


rm -rf latino_stepB_${Index}.root
#rm -rf latino_stepB_${Index}_numEvent${EVENTS}.root

    #maxEvents=3000                      \
cmsRun stepB.py print                   \
    reportEvery=10                      \
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
    inputFiles=${MYFILE}
#   LHEweightSource=externalLHEProducer \
                    
python cmssw2latino.py stepB_${Index}.root
#python cmssw2latino.py stepB_${Index}_numEvent3000.root

#rm -rf stepB_${Index}.root


