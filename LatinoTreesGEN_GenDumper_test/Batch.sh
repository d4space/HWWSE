#! /bin/bash 

######### make batch file ########
number=0
while read line 
do 
  echo $line 
  echo "#!/bin/bash" > run_batch_job_$number.sh
  echo "#PBS -o /dev/null" >> run_batch_job_$number.sh
  echo "source /cvmfs/cms.cern.ch/cmsset_default.sh" >> run_batch_job_$number.sh
  echo "cd /u/user/salee/Latino/CMSSW7414_WgStar/src" >> run_batch_job_$number.sh
  echo "eval \`scramv1 runtime -sh\`" >> run_batch_job_$number.sh
  echo "cd /u/user/salee/Latino/CMSSW7414_WgStar/src/LatinoTreesGEN/GenDumper/test" >> run_batch_job_$number.sh
  echo "cmsRun gendumper_cfg.py isMiniAod=True  maxEvents=-1 debug=False inputFiles=file:/d3/scratch/khakim/RunII/miniAODsamples/WZJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15MiniAODv2/$line       outputFile=WZJets_13TeV_$number.root" >> run_batch_job_$number.sh
  chmod u+x run_batch_job_$number.sh
  #qsub -q cms run_batch_job_$number.sh
  qsub -q cms -l walltime=672:00:00,cput=500:00:00 run_batch_job_$number.sh
  number="$(($number+1))"
done < WZJet_List.txt

