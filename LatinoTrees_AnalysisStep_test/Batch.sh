#! /bin/bash 

######### make batch file ########
number=0
while read line 
do 
  echo $line 
  echo "#!/bin/bash" > run_batch_job_$number.sh
  echo "#PBS -o /dev/null" >> run_batch_job_$number.sh
  echo "source /cvmfs/cms.cern.ch/cmsset_default.sh" >> run_batch_job_$number.sh
  echo "cd /u/user/salee/Latino/CMSSW763Moriond/src" >> run_batch_job_$number.sh
  echo "eval \`scramv1 runtime -sh\`" >> run_batch_job_$number.sh
  echo "cd /u/user/salee/Latino/CMSSW763Moriond/src/LatinoTrees/AnalysisStep/test" >> run_batch_job_$number.sh
  echo "sh ./test-run_Batch.sh $number  /d3/scratch/khakim/RunII/miniAODsamples/WZJets_TuneCUETP8M1_13TeV_amcatnloFXFX_pythia8_RunIIFall15MiniAODv2/$line " >> run_batch_job_$number.sh
  chmod u+x run_batch_job_$number.sh
  #qsub -q cms run_batch_job_$number.sh
  qsub -q cms -l walltime=672:00:00,cput=600:00:00 run_batch_job_$number.sh
  number="$(($number+1))"
  #exit 0
  #sleep 3
done < WZJet_List.txt

