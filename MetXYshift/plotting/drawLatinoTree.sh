#SAMPLE_DIR=../../../LatinoTrees/AnalysisStep/test/
#SAMPLE_DIR=../test

SAMPLE_DIR=/u/user/salee/Latino/CMSSW809/src/PlotsConfigurations/Configurations/ControlRegions/Met/XYshift
#
mkdir LatinPlots

#root -l drawLatinoTree.C+\(\"$SAMPLE_DIR/latino_DYJetsToLL_M-50_0000__part0.root\"\)
root -l drawLatinoTree.C+\(\"$SAMPLE_DIR/latino_Run2016B_PromptReco_SingleMuon.root\"\)
#root -l drawLatinoTree.C+\(\"$SAMPLE_DIR/latino_DYJetsToLL_M-10to50.root\"\)
#root -l drawLatinoTree.C+\(\"$SAMPLE_DIR/latino_MetCorrected_mc_numEvent10000.root\"\)
#

mv LatinPlots Plots80XRun2016BSingleMuon_Cuts
#mv LatinPlots Plots80XDYm50_Cuts
#mv LatinPlots Plots80XDYm50
#mv LatinPlots Plots80XDYm50_MetCut20
#mv LatinPlots Plots80XDYm10_50_MetCut20
#mv LatinPlots Plots80XRun2016BSgleMu

rm *~ *.d *.so
