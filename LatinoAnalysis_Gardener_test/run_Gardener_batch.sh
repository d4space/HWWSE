#!/bin/sh

# login : cms02.knu.ac.kr , lxplus.cern.ch
# Andrea's pre-process ntuple location : /eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/22Jan/MC/25ns/LatinoTrees/
# eos mount for Cernbox, /afs/cern.ch/project/eos/installation/0.3.84-aquamarine.user/bin/eos.select -b fuse mount ~/eos_cernbox
# Sangil Cernbox location : /eos/user/s/spak/HWW2015/

# isWgsLepton --kind 3 \ 
#gardener.py l2selfiller \
#		--kind 3 --cmssw 763\
#		latino_stepB_numEvent1000.root \
#		latino_stepB_numEvent1000_garden.root

echo "eosmount and mount cernbox eos first... " 

if [ -z $CMSSW_BASE ]; then
  echo " No CMS environment detected; stopping... " 
  exit 1
fi

#if [ $# -lt 1 ]; then
#  echo "Usage : ./run_Gardener_batch.sh [InputDir]"
#  exit 1
#fi

num=0
InputDir=~/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/22Jan/MC/25ns/LatinoTrees/	#input file location
PostDir=~/eos_cernbox/user/s/spak/HWW2015/PostGardener	# output save location
#PostDir=PostGardener
PWD=$(pwd)

if [ ! -e $PostDir ]; then
  mkdir $PostDir
fi
#for file in `ls $InputDir/ | grep root`;
for file in `ls $InputDir/ | grep latino_ZZTo4L__part`;
do
  if [ -z $file ]; then
    echo "No files detected"
    exit 1
  else 
    echo "$file is going to be post-processed"
    #echo "${file%%.root}"
    #echo "${file#latino_}"
    tmpString=${file%%.root}
    SampleName=${tmpString#latino_}
    echo "$SampleName"
  fi
  
  echo "#!/bin/sh" >& Gardener_batch_$SampleName.sh
  echo "export SCRAM_ARCH=slc6_amd64_gcc493" >> Gardener_batch_$SampleName.sh
  echo "if [ -f /cvmfs/cms.cern.ch/cmsset_default.sh ]; then" >> Gardener_batch_$SampleName.sh
  echo "  source /cvmfs/cms.cern.ch/cmsset_default.sh">> Gardener_batch_$SampleName.sh
  echo "fi">> Gardener_batch_$SampleName.sh
  echo "" >> Gardener_batch_$SampleName.sh

  echo "cd $CMSSW_BASE/src" >> Gardener_batch_$SampleName.sh
  echo "cmsenv" >> Gardener_batch_$SampleName.sh
  echo "" >> Gardener_batch_$SampleName.sh
  echo "eosmount ~/eos">> Gardener_batch_$SampleName.sh # eos mount to read andrea's folder
  echo "/afs/cern.ch/project/eos/installation/0.3.84-aquamarine.user/bin/eos.select -b fuse mount ~/eos_cernbox">> Gardener_batch_$SampleName.sh # cernbox access
  echo "" >> Gardener_batch_$SampleName.sh
  echo "cd $PWD" >> Gardener_batch_$SampleName.sh
  echo "gardener.py genvariablesfiller \ $InputDir$file \ $PostDir/$file" >> Gardener_batch_$SampleName.sh
  chmod u+x Gardener_batch_$SampleName.sh

  #qsub -q short Gardener_batch_$SampleName.sh # cms02.knu.ac.kr
  #bsub -q 1nd -J Gardener_$SampleName < Gardener_batch_$SampleName.sh # -q 1nd (1 day), -J job1(job name) 
  num="$(($num+1))"
done
