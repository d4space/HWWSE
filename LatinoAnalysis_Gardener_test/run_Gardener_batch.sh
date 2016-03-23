#!/bin/sh

# isWgsLepton --kind 3 \ 
#gardener.py l2selfiller \
#		--kind 3 --cmssw 763\
#		latino_stepB_numEvent1000.root \
#		latino_stepB_numEvent1000_garden.root
if [ -z $CMSSW_BASE ]; then
  echo " No CMS environment detected; stopping... " 
  exit 1
fi

if [ $# -lt 1 ]; then
  echo "Usage : ./run_Gardener_batch.sh [InputDir]"
  exit -1
fi

num=0
InputDir=$1
PostDir=PostGardener
PWD=$(pwd)

if [ ! -e $PostDir ]; then
  mkdir $PostDir
fi

for file in `ls $InputDir/ | grep root`;
do
  echo "$file is going to be post-processed"
  echo "#!/bin/sh" >& Gardener_batch_$num.sh
  echo "export SCRAM_ARCH=slc6_amd64_gcc493" >> Gardener_batch_$num.sh
  echo "export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch" >> Gardener_batch_$num.sh
  echo "if [ -f $VO_CMS_SW_DIR/cmsset_default.sh ]; then" >> Gardener_batch_$num.sh
  echo "  source $VO_CMS_SW_DIR/cmsset_default.sh">> Gardener_batch_$num.sh
  echo "fi">> Gardener_batch_$num.sh
  echo "cd $CMSSW_BASE/src" >> Gardener_batch_$num.sh
  echo "cmsenv" >> Gardener_batch_$num.sh
  echo "" >> Gardener_batch_$num.sh
  echo "cd $PWD" >> Gardener_batch_$num.sh
  echo "gardener.py genvariablesfiller \ $InputDir$file \ $PostDir/$file" >> Gardener_batch_$num.sh
  chmod u+x Gardener_batch_$num.sh

  qsub -q short Gardener_batch_$num.sh
  num="$(($num+1))"
done
