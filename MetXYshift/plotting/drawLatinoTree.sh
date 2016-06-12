SAMPLE_DIR=../../../LatinoTrees/AnalysisStep/test/
#SAMPLE_DIR=../test

#
mkdir LatinPlots

root -l drawLatinoTree.C+\(\"$SAMPLE_DIR/latino_MetCorrected_data_numEvent10000.root\"\)
#root -l drawLatinoTree.C+\(\"$SAMPLE_DIR/latino_MetCorrected_mc_numEvent10000.root\"\)
#

mv LatinPlots LatinPlotsData

rm *~ *.d *.so
