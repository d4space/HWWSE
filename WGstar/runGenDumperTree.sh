if [ $# -lt 1 ]; then
    echo "  "
    echo "  ./runGenDumper.sh NJETS"
    echo "  "
    exit -1
fi


LUMINOSITY=0.553 #Run2015D_05Oct2015 (553.150 pb-1) 

NJETS=$1

#CHANNELS="SSEMuPlus SSEMuMinus SSMuEPlus SSMuEMinus"
#CHANNELS="EE MuMu EMu MuE SSEMuPlus SSEMuMinus SSMuEPlus SSMuEMinus"
CHANNELS="MuMuMu"

SAMPLES="          \
WZ                 \
"
#SAMPLES="          \
#ggWWto2L           \
#WWTo2L2Nu          \
#WZ                 \
#ZZ                 \
#TTbar              \
#TW                 \
#DY                 \
#WgammaStar         \
#WgammaNoStar       \
#WJetsFakes\_Total  \
#DataRun2015\_D     \
#DYtautau           \
#HWW125             \
#Zgamma             \
#"

rm -rf GenDumperRoot/${NJETS}jet


# Loop
for CHANNEL in $CHANNELS; do

    for SAMPLE in $SAMPLES; do 
	
	root -l -b -q "GenDumperTree.C+($LUMINOSITY,$NJETS,\"$CHANNEL\",\"$SAMPLE\",\"true\",\"true\")"
	#root -l -b -q "runLatinosTreeScript.C($LUMINOSITY,$NJETS,\"$CHANNEL\",\"$SAMPLE\")"
  
    done

    OUTPATH=GenDumperRoot/${NJETS}jet/${CHANNEL}

    # Merge some MC files
    #hadd ${OUTPATH}/WW.root     ${OUTPATH}/ggWWto2L.root     ${OUTPATH}/WWTo2L2Nu.root 
    #hadd ${OUTPATH}/Wgamma.root ${OUTPATH}/WgammaNoStar.root ${OUTPATH}/WgammaStar.root

done

