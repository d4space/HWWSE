#! /bin/bash 

######### make batch file ########
Index=0
FileDir="/u/user/sangilpark/RunIIData/testSample/WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2/"
#FileDir="/u/user/salee/Latino/DataRunII/Fall15MiniAODv2/WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/"
#FileDir="/d3/scratch/khakim/RunII/miniAODsamples/WZJets_TuneCUETP8M1_13TeV_amcatnloFXFX_pythia8_RunIIFall15MiniAODv2/"
SampleName=WgToLNuG
ls ${FileDir}/*.root >& $SampleName.txt
Nevent=1000


CurrentDir=$(pwd)
while read line 
do 
  echo $line 
  echo "#!/bin/bash" > batch_${SampleName}_${Index}.sh
  echo "#PBS -o /dev/null" >> batch_${SampleName}_${Index}.sh
  echo "source /cvmfs/cms.cern.ch/cmsset_default.sh" >> batch_${SampleName}_${Index}.sh
  echo "cd ${CurrentDir}" >> batch_${SampleName}_${Index}.sh
  echo "cd ../../../" >> batch_${SampleName}_${Index}.sh
  echo "eval \`scramv1 runtime -sh\`" >> batch_${SampleName}_${Index}.sh
  echo "cd ${CurrentDir}" >> batch_${SampleName}_${Index}.sh
  echo "sh ./test-run_Batch.sh ${Index} ${Nevent} file:${line} " >> batch_${SampleName}_${Index}.sh
  chmod u+x batch_${SampleName}_${Index}.sh
  #qsub -q cms batch_$SampleName_$Index.sh
  #qsub -q cms -l walltime=672:00:00,cput=600:00:00 batch_$SampleName_$Index.sh
  qsub -q cms -l walltime=00:30:00,cput=00:30:00 batch_${SampleName}_${Index}.sh
  Index="$(($Index+1))"
  #exit 0
  #sleep 3
done < $SampleName.txt

