import os

for x in range(0,240):
  range1= x * 0.25 + 0.000001
  range2= x  * 0.25 + 0.25 + 0.000001
  print range1
  print range2
  fileName="WidthBatch_"+str(x)+".sh"
  outF = open(fileName,'w')
########## make batch file ########
  outF.write("#!/bin/bash\n")
  outF.write( "#PBS -o /dev/null\n")
  outF.write( "source /cvmfs/cms.cern.ch/cmsset_default.sh\n")
  outF.write("cd /u/user/salee/Latino/CMSSW611_Xavi/src\n")
  outF.write("eval `scramv1 runtime -sh`\n")
  outF.write("cd /u/user/salee/Latino/CMSSW611_Xavi/src/LimitCombine/HiggsWidth/test\n")
  outF.write("combine -M MultiDimFit Results_WWZZ/model_hww_hzz_NoCustodial.root  --algo=grid --points 1  -m 125.6   -t -1 --expectSignal=1 --saveToys  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=" +str(range1)+","+str(range2)+ "  --name NoCust_"+str(x)+"  --verbose -1\n")
  os.system("chmod u+x "+fileName)
  #os.system("qsub -q cms -l walltime=48:00:00,cput=48:00:00" + fileName)
#  #qsub -q cms WidthBatch_$number.sh
#  #qsub -q cms -l walltime=00:45:00,cput=00:30:00 WidthBatch_$number.sh
   #qsub -q cms -l walltime=48:00:00,cput=48:00:00 WidthBatch_$number.sh
#  #qsub -q cms -l walltime=672:00:00,cput=600:00:00 WidthBatch_$number.sh
#  #number="$(($number+1))"
#  #exit 0
#  #sleep 3

