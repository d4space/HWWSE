if [ $# -lt 1 ]; then
    echo "  "
    echo "  ./run.sh NJETS"
    echo "  "
    exit -1
fi


LUMINOSITY=2.6 #Run2016B_Promptreco 
#LUMINOSITY=0.805 #Run2015D_05Oct2015 (553.150 pb-1) 
#LUMINOSITY=0.553 #Run2015D_05Oct2015 (553.150 pb-1) 
#LUMINOSITY=2.264 #16Dec2015 RECO of 2015C and 2015D datasets, available in 76x latinos

NJETS=$1

#CHANNELS="SSEMuPlus SSEMuMinus SSMuEPlus SSMuEMinus"
#CHANNELS="EE MuMu EMu MuE SSEMuPlus SSEMuMinus SSMuEPlus SSMuEMinus"
CHANNELS="MuMu"

SAMPLES="          \
DataRun2016_B	\
WJetsLNu	\
WJetsLNu_HT	\
ggWWto2L	\
WWTo2L2Nu	\
WZ		\
WZ2Q       \
WZ3LNu       \
ZZ       \
TTbar       \
TW       \
DY       \
DY_HT       \
WgammaNoStar       \
WgammaStarToLNuMuMu       \
WgammaStarToLNuEE       \
HWW125       \
Zgamma       \
QCD       \
TTWJetsLNu	\
TTWJets2Q	\
TTZjet		\
WWW	\
WWZ	\
WZZ	\
ZZZ	\	
WW	\
WpWpJJ	\
bbHWWTo2L2Nu_M125	\
ST	\
ggHToTauTau_M125	\
"

# Loop
for CHANNEL in $CHANNELS; do

    for SAMPLE in $SAMPLES; do 
	
	root -l -b -q "LatinosTreeScript.C+($LUMINOSITY,$NJETS,\"$CHANNEL\",\"$SAMPLE\",\"Nominal\",\"true\")"
	#root -l -b -q "LatinosTreeScript.C+($LUMINOSITY,$NJETS,\"$CHANNEL\",\"$SAMPLE\",\"GenStudy\",\"true\")"
	#root -l -b -q "LatinosTreeScript.C+(luminosity, jetChannel, flavorChannel, theSample, TYPeSTUDY, verbose)"
	#root -l -b -q "runLatinosTreeScript.C($LUMINOSITY,$NJETS,\"$CHANNEL\",\"$SAMPLE\")"
  
    done

    OUTPATH=rootfiles/${NJETS}jet/${CHANNEL}

    # Merge some MC files
    #hadd ${OUTPATH}/WW.root     ${OUTPATH}/ggWWto2L.root     ${OUTPATH}/WWTo2L2Nu.root 
    #hadd ${OUTPATH}/Wgamma.root ${OUTPATH}/WgammaNoStar.root ${OUTPATH}/WgammaStar.root

done


# Make the SF, OF and All directories
#PATHSF=rootfiles/${NJETS}jet/SF
#PATHOF=rootfiles/${NJETS}jet/OF
#PATHAll=rootfiles/${NJETS}jet/All
#PATHSS=rootfiles/${NJETS}jet/SS
#
#mkdir ${PATHSF}
#mkdir ${PATHOF}
#mkdir ${PATHAll}
#mkdir ${PATHSS}
#    
#PATHEMu=rootfiles/${NJETS}jet/EMu
#PATHSSEMuPlus=rootfiles/${NJETS}jet/SSEMuPlus
#PATHSSEMuMinus=rootfiles/${NJETS}jet/SSEMuMinus
#PATHMuE=rootfiles/${NJETS}jet/MuE
#PATHSSMuEPlus=rootfiles/${NJETS}jet/SSMuEPlus
#PATHSSMuEMinus=rootfiles/${NJETS}jet/SSMuEMinus
#PATHMuMu=rootfiles/${NJETS}jet/MuMu
#PATHEE=rootfiles/${NJETS}jet/EE
#
#ALLSAMPLES="       \
#ggWWto2L           \
#WWTo2L2Nu          \
#WZ                 \
#ZZ                 \
#TTbar              \
#TW                 \
#DY                 \
#WgammaStar         \
#WgammaNoStar       \
#WJetsFakes_Total   \
#DataRun2012_Total  \
#DYtautau           \
#HWW125             \
#WW                 \
#Wgamma             \
#Zgamma             \
#"
#
#for SAMPLE in $ALLSAMPLES; do 
# 
#    #hadd ${PATHSF}/${SAMPLE}.root  ${PATHMuMu}/${SAMPLE}.root ${PATHEE}/${SAMPLE}.root
#    #hadd ${PATHOF}/${SAMPLE}.root  ${PATHMuE}/${SAMPLE}.root  ${PATHEMu}/${SAMPLE}.root
#    #hadd ${PATHAll}/${SAMPLE}.root ${PATHOF}/${SAMPLE}.root   ${PATHSF}/${SAMPLE}.root
#    hadd ${PATHSS}/${SAMPLE}.root  ${PATHSSEMuPlus}/${SAMPLE}.root ${PATHSSEMuMinus}/${SAMPLE}.root ${PATHSSMuEPlus}/${SAMPLE}.root ${PATHSSMuEMinus}/${SAMPLE}.root
# 
#done
