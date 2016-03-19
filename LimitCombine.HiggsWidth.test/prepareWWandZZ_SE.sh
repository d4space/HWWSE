 

# scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/*jetDF8TeV.tgz ./
#     tar -xf 01jetDF8TeV.tgz
#     rm -r datacards-01j/; mv datacards/ datacards-01j/
#     tar -xf 0jetDF8TeV.tgz
#     rm -r datacards-0j/; mv datacards/ datacards-0j/
#     tar -xf 1jetDF8TeV.tgz
#     rm -r datacards-1j/; mv datacards/ datacards-1j/
#     tar -xf 2jetDF8TeV.tgz
#     rm -r datacards-2j/; mv datacards/ datacards-2j/
# 
# 
# 
#     scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/?jetDF8TeVSimple.tgz ./
#     tar -xf 0jetDF8TeVSimple.tgz
#     rm -r datacards-0j-Simple/; mv datacards/ datacards-0j-Simple/
#     tar -xf 1jetDF8TeVSimple.tgz
#     rm -r datacards-1j-Simple/; mv datacards/ datacards-1j-Simple/
# 
#     combineCards.py   of0j=datacards-0j-Simple/hww-19.36fb.mH125.of_0j_shape.txt \
#                       of1j=datacards-1j-Simple/hww-19.36fb.mH125.of_1j_shape.txt \
#                       of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
#                       >   hwidth_012jet_simple.txt
# 
#     combineCards.py   of0j=datacards-0j-Simple/hww-19.36fb.mH125.of_0j_shape.txt \
#                       of1j=datacards-1j-Simple/hww-19.36fb.mH125.of_1j_shape.txt \
#                       >   hwidth_01jet_simple.txt
# 
# 
# 
# 
# 
#     combineCards.py   of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
#                       of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
#                       of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
#                       >   hwidth_012jet.txt
# 
#     combineCards.py   of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
#                       of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
#                       >   hwidth_01jet.txt

    
echo ">>>> only WW is2l2nu"

#     text2workspace.py -m 125.6 datacards-01j/hww-19.36fb.mH125.of_01j_shape.txt -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu  -o      model_hwwlvlv_01j_together.root
#     text2workspace.py -m 125.6 datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu  -o      model_hwwlvlv_0j.root
#     text2workspace.py -m 125.6 datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu  -o      model_hwwlvlv_1j.root
#     text2workspace.py -m 125.6 datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu  -o      model_hwwlvlv_2j.root
#     text2workspace.py -m 125.6 hwidth_012jet.txt                                -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu  -o      model_hwwlvlv_012.root
#     text2workspace.py -m 125.6 hwidth_01jet.txt                                 -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu  -o      model_hwwlvlv_01.root
# 
#     combine -M MultiDimFit model_hwwlvlv_01j_together.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60          --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.01j.together.root
#     
#     combine -M MultiDimFit model_hwwlvlv_0j.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60          --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.0j.root
#     
#     combine -M MultiDimFit model_hwwlvlv_1j.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60     --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.1j.root
# 
#     combine -M MultiDimFit model_hwwlvlv_2j.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60     --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.2j.root
# 
#     combine -M MultiDimFit model_hwwlvlv_012.root --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60     --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.012j.root
#     
#     combine -M MultiDimFit model_hwwlvlv_01.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60     --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.01j.root
    
    

echo ">>>> only WW is2l2nu and mH scaled MHScaleWW"
        
#     text2workspace.py -m 125.6 datacards-01j/hww-19.36fb.mH125.of_01j_shape.txt -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o      model_hwwlvlv_01j_together.root
#     text2workspace.py -m 125.6 datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o      model_hwwlvlv_0j.root
#     text2workspace.py -m 125.6 datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o      model_hwwlvlv_1j.root
#     text2workspace.py -m 125.6 datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o      model_hwwlvlv_2j.root
#     text2workspace.py -m 125.6 hwidth_012jet.txt                                -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o      model_hwwlvlv_012.root
#     text2workspace.py -m 125.6 hwidth_01jet.txt                                 -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o      model_hwwlvlv_01.root
# 
#     combine -M MultiDimFit model_hwwlvlv_01j_together.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60          --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.01j.together.root
#     
#     combine -M MultiDimFit model_hwwlvlv_0j.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60          --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.0j.root
#     
#     combine -M MultiDimFit model_hwwlvlv_1j.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60     --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.1j.root
# 
#     combine -M MultiDimFit model_hwwlvlv_2j.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60     --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.2j.root
# 
#     combine -M MultiDimFit model_hwwlvlv_012.root --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60     --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.012j.root
#     
#     combine -M MultiDimFit model_hwwlvlv_01.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60     --verbose -1
#     mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.01j.root
    
    
    
echo ">>>> WW is2l2nu and mH scaled MHScaleWW in combination with HZZ"
        
#     /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards
#     svn co  svn+ssh://amassiro@svn.cern.ch/reps/cmshcg/trunk/cadi/HIG-14-002/
#     
#     remove from /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz2l2nu/card_combined.dat 
#     the line: CMS_widthH_kbkg
# 

#     combineCards.py   hww=Results/hwidth_012jet-7TeV-8TeV.txt \
#                       hzz4l=/u/user/salee/Latino/datacards/HIG-14-002/hzz4l/hzz4l_all.txt \
#                       hzz2l2v=/u/user/salee/Latino/datacards/HIG-14-002/hzz2l2nu/card_combined.dat \
#                       >   hwidth_hww_hzz.txt
# 
# 
# /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine
# 
# 



#  combineCards.py      hzz4l_7TeV_4mu_onshell_01j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4muS_7TeV_0.txt \
#   hzz4l_8TeV_4mu_onshell_01j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4muS_8TeV_0.txt \
#   hzz4l_7TeV_4mu_onshell_2j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4muS_7TeV_1.txt \
#   hzz4l_8TeV_4mu_onshell_2j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4muS_8TeV_1.txt \
#   hzz4l_7TeV_4mu_offshell=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4muS_7TeV.txt \
#   hzz4l_8TeV_4mu_offshell=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4muS_8TeV.txt \
#   hzz4l_7TeV_4e_onshell_01j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4eS_7TeV_0.txt \
#   hzz4l_8TeV_4e_onshell_01j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4eS_8TeV_0.txt \
#   hzz4l_7TeV_4e_onshell_2j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4eS_7TeV_1.txt \
#   hzz4l_8TeV_4e_onshell_2j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4eS_8TeV_1.txt \
#   hzz4l_7TeV_4e_offshell=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4eS_7TeV.txt \
#   hzz4l_8TeV_4e_offshell=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_4eS_8TeV.txt \
#   hzz4l_7TeV_2e2mu_onshell_01j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_2e2muS_7TeV_0.txt \
#   hzz4l_8TeV_2e2mu_onshell_01j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_2e2muS_8TeV_0.txt \
#   hzz4l_7TeV_2e2mu_onshell_2j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_2e2muS_7TeV_1.txt \
#   hzz4l_8TeV_2e2mu_onshell_2j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_2e2muS_8TeV_1.txt \
#   hzz4l_7TeV_2e2mu_offshell=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_2e2muS_7TeV.txt \
#   hzz4l_8TeV_2e2mu_offshell=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/././hzz4l_2e2muS_8TeV.txt \
#   >   hwidth_hzz4l_mycomb.txt
#   
#   
#    text2workspace.py -m 125.6 hwidth_hzz4l_mycomb.txt          -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth               --PO=MHScaleWW  -o    model_hzz4l.root
#    text2workspace.py -m 125.6 hwidth_hzz4l_mycomb.txt          -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth               --PO=MHScaleWW  -o    model_hzz4l.root
#
#    text2workspace.py -m 125.6 hwidth_012jet.txt  -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth       --PO=is2l2nu         --PO=MHScaleWW  -o    model_hww_newmodel.root
#    text2workspace.py -m 125.6 /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz2l2nu/card_incl.dat   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o    model_hzz2l2v.root
#
#
#    text2workspace.py -m 125.6 /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz2l2nu/card_combined.dat   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o    model_hzz2l2v.root
#   
#   
#   
#    text2workspace.py -m 125.6 /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz4l/hzz4l_all.txt          -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth               --PO=MHScaleWW  -o    model_hzz4l.root
#    text2workspace.py -m 125.6 /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz2l2nu/card_combined.dat   -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o    model_hzz2l2v.root
#    #     text2workspace.py -m 125.6 /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz2l2nu/card_combined.dat   -P LimitCombine.HiggsWidth.testB:higgswidth                               --PO=is2l2nu --PO=MHScaleWW  -o    model_hzz2l2v.root
#    #     text2workspace.py -m 125.6 /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-002/hzz2l2nu/card_incl.dat       -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth               --PO=MHScaleWW  -o    model_hzz2l2v.root
#    text2workspace.py -m 125.6 hwidth_012jet_7TeV_8TeV.txt                                                                       -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o    model_hwwlvlv.root
########## No Custodial
#    text2workspace.py -m 125.6 Results_WWZZ/hwidth_hww_hzz.txt                                                                                -P LimitCombine.HiggsWidth.HiggsWidthKappaNoCustodialMHSscaleWW:higgswidth               --PO=MHScaleWW  -o    model_hww_hzz_NoCustodial.root
#
#
#    combine -M MultiDimFit model_hzz4l.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,30          --verbose -1
#    mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.hzz4l.root
#    
#    combine -M MultiDimFit model_hzz2l2v.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,30          --verbose -1
#    mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.hzz2l2v.root
#    
#    combine -M MultiDimFit model_hww_newmodel.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,30          --verbose -1
#    combine -M MultiDimFit model_hwwlvlv.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,30          --verbose -1
#    mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.hwwlvlv.root


#    
#    combine -M MultiDimFit Results_WWZZ/model_hww_hzz.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,30          --verbose -1
#    mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.hww.hzz.root

#    combine   -M MultiDimFit Results_WWZZ/model_hww_hzz.root  --algo=grid --points 240  -m 125.6         --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#    mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.WWZZ.root

#   NoCustodial
#    combine   -M MultiDimFit Results_WWZZ/model_hww_hzz_NoCustodial.root  --algo=grid --points 240  -m 125.6         --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#    mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.WWZZ.NoCustodial.root

    combine -M MultiDimFit Results_WWZZ/model_hww_hzz_NoCustodial.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,30          --verbose -1
    mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      Asimov.higgsCombineTest.MultiDimFit.WWZZ.NoCustodial.root
#
#    
#    
#    
#    
#    
#    
#    text2workspace.py -m 125.6 datacards-0j-it-should-work/hww-19.36fb.mH125.of_0j_shape.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth  --PO=is2l2nu --PO=MHScaleWW  -o    model_hwwlvlv_0j.root
#    combine -M MaxLikelihoodFit model_hwwlvlv_0j.root
#    python diffNuisances.py -a  mlfit.root -g plots.root   -p CMS_zz4l_GGsm
#    python diffNuisances.py -a  mlfit.root -g plots.root   -p CMS_zz4l_GGsm &> tmp.txt
#    
#    
#    
#    
#    
