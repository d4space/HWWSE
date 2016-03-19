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
  srmls srm://cluster142.knu.ac.kr:8443/srm/managerv2?SFN=${FileDir}| grep root | awk '{print$2  " "}' |sed 's/\/pnfs\/knu.ac.kr\/data\/cms/    dcap:\/\/cluster142.knu.ac.kr\//' >> $SampleName.txt
done

Nevent=1000


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
  #qsub -q cms batch_$SampleName_$Index.sh
  #qsub -q cms -l walltime=672:00:00,cput=600:00:00 batch_$SampleName_$Index.sh
  #qsub -q cms -l walltime=00:30:00,cput=00:30:00 batch_${SampleName}_${Index}.sh
  Index="$(($Index+1))"
  #exit 0
  #sleep 3
done < $SampleName.txt

