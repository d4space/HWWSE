#! /bin/bash 

######### make batch file ########
SampleName=WGstarToLNuMuMu
Index=0
echo "Check Dir number first : uberftp cluster142.knu.ac.kr \"ls /pnfs/knu.ac.kr/data/cms/store/mc/RunIIFall15MiniAODv2/WGstarToLNuMuMu_012Jets_13TeV-madgraph/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/\" "
FileDirNum=(00000 10000 40000 60000)

rm -f $SampleName.txt

for num in ${FileDirNum[@]};
do
  FileDir="/pnfs/knu.ac.kr/data/cms/store/mc/RunIIFall15MiniAODv2/WGstarToLNuMuMu_012Jets_13TeV-madgraph/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/$num/"
  srmls srm://cluster142.knu.ac.kr:8443/srm/managerv2?SFN=${FileDir}| grep root | awk '{print "dcap://cluster142.knu.ac.kr/" $2}' >> $SampleName.txt
done

#Nevent=1000
Nevent=300


CurrentDir=$(pwd)
while read line 
do 
  echo $line 
  echo "#!/bin/bash" >& batch_${SampleName}_${Index}.sh
  echo "#PBS -o /dev/null" >> batch_${SampleName}_${Index}.sh
  echo "source /cvmfs/cms.cern.ch/cmsset_default.sh" >> batch_${SampleName}_${Index}.sh
  echo "cd ${CurrentDir}" >> batch_${SampleName}_${Index}.sh
  echo "cd ../../../" >> batch_${SampleName}_${Index}.sh
  echo "eval \`scramv1 runtime -sh\`" >> batch_${SampleName}_${Index}.sh
  echo "cd ${CurrentDir}" >> batch_${SampleName}_${Index}.sh
  echo "sh ./test-run_Batch.sh ${Index} ${Nevent} ${line} " >> batch_${SampleName}_${Index}.sh
  chmod u+x batch_${SampleName}_${Index}.sh
  
  qsub -q short batch_${SampleName}_${Index}.sh # cputime limit : 30 min
  #qsub -q cms batch_${SampleName}_${Index}.sh # cputime limit : 48 hour
  #qsub -q long batch_${SampleName}_${Index}.sh # cputime limit : 600 hour


  Index="$(($Index+1))"
  #exit 0
  #sleep 3
done < $SampleName.txt

