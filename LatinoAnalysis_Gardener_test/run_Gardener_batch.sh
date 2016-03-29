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

echo "eosmount ~/eos ; do this first... " 
eosmount ~/eos

if [ -z $CMSSW_BASE ]; then
  echo " No CMS environment detected; stopping... " 
  exit 1
fi

#if [ $# -lt 1 ]; then
#  echo "Usage : ./run_Gardener_batch.sh [InputDir]"
#  exit 1
#fi

num=0
InputDir=~/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/22Jan/MC/25ns/LatinoTrees/
PostDir=~/eos_cernbox/user/s/spak/HWW2015/PostGardener
#PostDir=PostGardener
PWD=$(pwd)

if [ ! -e $PostDir ]; then
  mkdir $PostDir
fi
#for file in `ls $InputDir/ | grep root`;
for file in `ls $InputDir/ | grep latino_ZZTo4L__part`;
do
  echo "#!/bin/sh" >& Gardener_batch_$num.sh
  echo "export SCRAM_ARCH=slc6_amd64_gcc493" >> Gardener_batch_$num.sh
  echo "if [ -f /cvmfs/cms.cern.ch/cmsset_default.sh ]; then" >> Gardener_batch_$num.sh
  echo "  source /cvmfs/cms.cern.ch/cmsset_default.sh">> Gardener_batch_$num.sh
  echo "fi">> Gardener_batch_$num.sh
  echo "" >> Gardener_batch_$num.sh

  echo "cd $CMSSW_BASE/src" >> Gardener_batch_$num.sh
  echo "cmsenv" >> Gardener_batch_$num.sh
  echo "" >> Gardener_batch_$num.sh
  echo "eosmount ~/eos">> Gardener_batch_$num.sh # eos mount to read andrea's folder
  echo "/afs/cern.ch/project/eos/installation/0.3.84-aquamarine.user/bin/eos.select -b fuse mount ~/eos_cernbox">> Gardener_batch_$num.sh # cernbox access
  echo "" >> Gardener_batch_$num.sh
  echo "cd $PWD" >> Gardener_batch_$num.sh
  echo "gardener.py genvariablesfiller \ $InputDir$file \ $PostDir/$file" >> Gardener_batch_$num.sh
  chmod u+x Gardener_batch_$num.sh

  if [ -z $file ]; then
    echo "No files detected"
    exit 1
  else 
    echo "$file is going to be post-processed"
  fi
  #qsub -q short Gardener_batch_$num.sh # cms02.knu.ac.kr
  #bsub -q 1nd -J Gardener_$num < Gardener_batch_$num.sh # -q 1nd (1 day), -J job1(job name) 
  num="$(($num+1))"
done
