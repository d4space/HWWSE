#! /bin/bash 

python HiggsWidthBatch.py

number=0
while [ $number -lt 240 ]
do
  echo "number is $number"
#range1=`expr $number \\* 0.25 + 0.000001`
#range2=`expr $number  \\* 0.25 + 0.25 + 0.000001`
######### make batch file ########
#  echo "#!/bin/bash" > WidthBatch_$number.sh
#  echo "#PBS -o /dev/null" >> WidthBatch_$number.sh
#  echo "source /cvmfs/cms.cern.ch/cmsset_default.sh" >> WidthBatch_$number.sh
#  echo "cd /u/user/salee/Latino/CMSSW611_Xavi/src" >> WidthBatch_$number.sh
#  echo "eval \`scramv1 runtime -sh\`" >> WidthBatch_$number.sh
#  echo "cd /u/user/salee/Latino/CMSSW611_Xavi/src/LimitCombine/HiggsWidth/test" >> WidthBatch_$number.sh
#  echo "combine -M MultiDimFit Results_WWZZ/model_hww_hzz_NoCustodial.root  --algo=grid --points 1  -m 125.6   -t -1 --expectSignal=1 --saveToys  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=$range1,$range2    --name NoCust_$number   --verbose -1 " >> WidthBatch_$number.sh
#  chmod u+x WidthBatch_$number.sh
  #qsub -q cms WidthBatch_$number.sh
  #qsub -q cms -l walltime=00:45:00,cput=00:30:00 WidthBatch_$number.sh
  qsub -q cms -l walltime=48:00:00,cput=48:00:00 WidthBatch_$number.sh
  #qsub -q cms -l walltime=672:00:00,cput=600:00:00 WidthBatch_$number.sh
  number="$(($number+1))"
done
  #exit 0
  #sleep 3

