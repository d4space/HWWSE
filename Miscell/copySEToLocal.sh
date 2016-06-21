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
echo "copy folder in location from SE to T2"
FOLDER=hahaha
uberftp cluster142.knu.ac.kr "get -r ${location}/${FOLDER} ."


