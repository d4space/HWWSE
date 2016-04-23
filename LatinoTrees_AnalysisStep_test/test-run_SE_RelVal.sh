### RelVal Settings ###
# 1. need to mount eos : $eosmount ~/eos
# 2. check RelVal sample in eos : /eos/cms/store/relval/CMSSW~~/~~/~~.root
# 3. check data global tag is used  
# 4. run script like : $ ./test-run_SE_RelVal.sh 100 ~/eos/cms/store/relval/CMSSW_7_6_3_patch2/RelValZEE_13/MINIAODSIM/76X_mcRun2_asymptotic_v12_multiCoreTest3-v1/10000/BEA52424-18E0-E511-8852-0025905A6070.root

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

#####
### Data example
#####

rm -rf latino_stepB_data_numEvent${EVENTS}.root

cmsRun stepB.py print                   \
    reportEvery=10                      \
    summary=false                       \
    is50ns=False                        \
    isPromptRecoData=True               \
    globalTag=76X_dataRun2_v15          \
    label=DoubleMuon                    \
    outputFile=stepB_data.root          \
    selection=LooseNoIso                \
    doNoFilter=False                    \
    doMuonIsoId=True                    \
    doEleIsoId=True                     \
    doBTag=True                         \
    runPUPPISequence=True               \
    doPhotonID=True                     \
    maxEvents=${EVENTS}                 \
    inputFiles=${MYFILE}

if [ $# == 2 ]; then
  rm -rf latino_stepB_data_numEvent${EVENTS}.root
  python cmssw2latino.py stepB_data_numEvent${EVENTS}.root
  rm -rf stepB_data_numEvent${EVENTS}.root
else
  rm -rf latino_stepB_data.root
  python cmssw2latino.py stepB_data.root
  rm -rf stepB_data.root
fi

