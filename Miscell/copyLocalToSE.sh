#!/bin/bash

echo "Activate grid authentication"
voms-proxy-init --voms cms

# Storage Element location
# Need to change spak->your user ID on SE
location=/pnfs/knu.ac.kr/data/cms/store/user/spak

# check SE directory
echo "UberFTP"
echo "Check the location : $location "
echo "You need to change location to your own"
uberftp cluster142.knu.ac.kr "ls $location"


# Put folder name you want to copy
YOURFOLDER=hahaha
echo "copy folder($YOURFOLDER) from T2 to SE"
uberftp cluster142.knu.ac.kr "put -r $YOURFOLDER $location"


