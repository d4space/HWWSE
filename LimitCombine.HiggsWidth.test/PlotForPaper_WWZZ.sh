
# //---- 1 = 7+8 TeV
# //---- 2 = 8   TeV
# //---- 3 = 7   TeV



## 8 TeV
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel.root \
#           Observed.higgsCombineTest.MultiDimFit.0j.StandardModel.root \
#           HiggsWidth/test/drawExpObs.cxx\(2,\"0j\ \ \ \"\)
#mv cc.png   0j.8TeV.png
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel.root \
#           Observed.higgsCombineTest.MultiDimFit.1j.StandardModel.root \
#           HiggsWidth/test/drawExpObs.cxx\(2,\"1j\ \ \ \"\)
#mv cc.png   1j.8TeV.png
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel.root \
#           Observed.higgsCombineTest.MultiDimFit.2j.StandardModel.root \
#           HiggsWidth/test/drawExpObs.cxx\(2,\"2j\ \ \ \"\)
#mv cc.png   2j.8TeV.png
#                      
#root -l -q Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel.root \
#           Observed.higgsCombineTest.MultiDimFit.01j.StandardModel.root \
#           HiggsWidth/test/drawExpObs.cxx\(2,\"01j\ \ \"\)
#
#mv cc.png   01j.8TeV.png
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel.root \
#           Observed.higgsCombineTest.MultiDimFit.012j.StandardModel.root \
#           HiggsWidth/test/drawExpObs.cxx\(2,\"012j\ \ \"\)
#mv cc.png   012j.8TeV.png
#
#
#
## 7 TeV
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel-7TeV.root \
#           Observed.higgsCombineTest.MultiDimFit.0j.StandardModel-7TeV.root \
#           HiggsWidth/test/drawExpObs.cxx\(3,\"0j\ \ \ \"\)
#mv cc.png   0j.7TeV.png
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV.root \
#           Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV.root \
#           HiggsWidth/test/drawExpObs.cxx\(3,\"1j\ \ \ \"\)
#mv cc.png   1j.7TeV.png
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel-7TeV.root \
#           Observed.higgsCombineTest.MultiDimFit.2j.StandardModel-7TeV.root \
#           HiggsWidth/test/drawExpObs.cxx\(3,\"2j\ \ \ \"\)
#mv cc.png   2j.7TeV.png
#                      
#root -l -q Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel-7TeV.root \
#           Observed.higgsCombineTest.MultiDimFit.01j.StandardModel-7TeV.root \
#           HiggsWidth/test/drawExpObs.cxx\(3,\"01j\ \ \"\)
#mv cc.png   01j.7TeV.png
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV.root \
#           Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV.root \
#           HiggsWidth/test/drawExpObs.cxx\(3,\"012j\ \ \"\)
#mv cc.png   012j.7TeV.png
#
#
#



# 7+8 TeV
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel-7TeV-8TeV.root \
#           Observed.higgsCombineTest.MultiDimFit.0j.StandardModel-7TeV-8TeV.root \
#           HiggsWidth/test/drawExpObs.cxx\(1,\"0j\ \ \ \"\)
#mv cc.png   0j.7and8TeV.png
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV-8TeV.root \
#           Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV-8TeV.root \
#           HiggsWidth/test/drawExpObs.cxx\(1,\"1j\ \ \ \"\)
#mv cc.png   1j.7and8TeV.png
#
#root -l -q Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel-7TeV-8TeV.root \
#           Observed.higgsCombineTest.MultiDimFit.2j.StandardModel-7TeV-8TeV.root \
#           HiggsWidth/test/drawExpObs.cxx\(1,\"2j\ \ \ \"\)
#mv cc.png   2j.7and8TeV.png
#rm Results_WWZZ/Asimov.results.txt
#
#root -l -q BatchScripts_NoCustAsimov/higgsCombineNoCust_All.MultiDimFit.mH125.6.123456.root \
#           drawExpObsWWZZ.cxx\(20\)
#           #drawExpObsResult.cxx\(1,\"012j\ \ \"\)
#mv cc.png   Results_WWZZ/Asimov.NoCustodial.png
#mv cc.pdf   Results_WWZZ/Asimov.NoCustodial.pdf
#mv results.txt Results_WWZZ/Asimov.resultsNoCustodial.txt 

# paper plot
root -l -q Results_WWZZ/Observed.higgsCombineTest.MultiDimFit.ZZ.root \
	drawExpObsWWandZZ.cxx
mv hwidth_All_HiggsWidthLT_HWidthLT_WidthFloatMu.png Results_WWZZ/
mv hwidth_All_HiggsWidthLT_HWidthLT_WidthFloatMu.pdf Results_WWZZ/


