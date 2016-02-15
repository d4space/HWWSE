         
         
#combineCards.py       hww_of0j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_0j_shape.txt \
#                      >   Results/hwidth_0jet.txt
#combineCards.py       hww_of1j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_1j_shape.txt \
#                      >   Results/hwidth_1jet.txt
#combineCards.py       hww_of2j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_2j_shape.txt \
#                      >   Results/hwidth_2jet.txt
#
#combineCards.py       hww_of0j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_0j_shape.txt \
#                      hww_of1j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_1j_shape.txt \
#                      hww_of2j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_2j_shape.txt \
#                      >   Results/hwidth_012jet.txt
#
#combineCards.py       hww_of0j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_0j_shape.txt \
#                      hww_of1j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_1j_shape.txt \
#                      >   Results/hwidth_01jet.txt
#
#
#                      
#                      
#combineCards.py       hww_of0j=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_0j_shape.txt \
#                      >   Results/hwidth_0jet-7TeV.txt
#combineCards.py       hww_of1j=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_1j_shape.txt \
#                      >   Results/hwidth_1jet-7TeV.txt
#combineCards.py       hww_of2j=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_2j_shape.txt \
#                      >   Results/hwidth_2jet-7TeV.txt
#
#
#combineCards.py       hww_of0j=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_0j_shape.txt \
#                      hww_of1j=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_1j_shape.txt \
#                      hww_of2j=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_2j_shape.txt \
#                      >   Results/hwidth_012jet-7TeV.txt
#
#combineCards.py       hww_of0j=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_0j_shape.txt \
#                      hww_of1j=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_1j_shape.txt \
#                      >   Results/hwidth_01jet-7TeV.txt
#        
#         
#combineCards.py       hww_of0j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_0j_shape.txt \
#                      hww_of1j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_1j_shape.txt \
#                      hww_of2j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_2j_shape.txt \
#                      hww_of0j7TeV=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_0j_shape.txt \
#                      hww_of1j7TeV=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_1j_shape.txt \
#                      hww_of2j7TeV=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_2j_shape.txt \
#                      >   Results/hwidth_012jet-7TeV-8TeV.txt
#         
#
#combineCards.py       hww_of0j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_0j_shape.txt \
#                      hww_of0j7TeV=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_0j_shape.txt \
#                      >   Results/hwidth_0jet-7TeV-8TeV.txt
#
#combineCards.py       hww_of1j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_1j_shape.txt \
#                      hww_of1j7TeV=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_1j_shape.txt \
#                      >   Results/hwidth_1jet-7TeV-8TeV.txt
#
#combineCards.py       hww_of2j=../../../../../datacards/HIG-14-032/125/hww-19.36fb.mH125.of_2j_shape.txt \
#                      hww_of2j7TeV=../../../../../datacards/HIG-14-032/125/hww-4.94fb.mH125.of_2j_shape.txt \
#                      >   Results/hwidth_2jet-7TeV-8TeV.txt
#         
#         
#text2workspace.py -m 125.6 Results/hwidth_0jet.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_0j.root
#text2workspace.py -m 125.6 Results/hwidth_1jet.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_1j.root
#text2workspace.py -m 125.6 Results/hwidth_2jet.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_2j.root
#text2workspace.py -m 125.6 Results/hwidth_012jet.txt      -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_012j.root
#text2workspace.py -m 125.6 Results/hwidth_01jet.txt       -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_01j.root
#
#
#text2workspace.py -m 125.6 Results/hwidth_0jet-7TeV.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_0j-7TeV.root
#text2workspace.py -m 125.6 Results/hwidth_1jet-7TeV.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_1j-7TeV.root
#text2workspace.py -m 125.6 Results/hwidth_2jet-7TeV.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_2j-7TeV.root
#text2workspace.py -m 125.6 Results/hwidth_012jet-7TeV.txt      -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_012j-7TeV.root
#text2workspace.py -m 125.6 Results/hwidth_01jet-7TeV.txt       -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_01j-7TeV.root
#
text2workspace.py -m 125.6 Results/hwidth_012jet-7TeV-8TeV.txt       -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_012j-7TeV-8TeV.root
#
#text2workspace.py -m 125.6 Results/hwidth_0jet-7TeV-8TeV.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_0j-7TeV-8TeV.root
#text2workspace.py -m 125.6 Results/hwidth_1jet-7TeV-8TeV.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_1j-7TeV-8TeV.root
#text2workspace.py -m 125.6 Results/hwidth_2jet-7TeV-8TeV.txt        -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWOriginal:higgswidth   --PO=is2l2nu --PO=MHScaleWW  -o    Results/model_hwwlvlv_2j-7TeV-8TeV.root
#
## 8 TeV
#combine   -M MultiDimFit model_hwwlvlv_0j.root  --algo=grid --points 240  -m 125.6                  --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.0j.StandardModel.root
#combine   -M MultiDimFit model_hwwlvlv_0j.root  --algo=grid --points 240  -t -1 -m 125.6            --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel.root
#
#combine   -M MultiDimFit model_hwwlvlv_1j.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.1j.StandardModel.root
#combine   -M MultiDimFit model_hwwlvlv_1j.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel.root
#
#combine   -M MultiDimFit model_hwwlvlv_2j.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.2j.StandardModel.root
#combine   -M MultiDimFit model_hwwlvlv_2j.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel.root
#
## combine   -M MultiDimFit model_hwwlvlv_012j.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#combine   -M MultiDimFit model_hwwlvlv_012j.root  --algo=grid --points 240  -m 125.6        --setPhysicsModelParameterRanges kV=0.01,20:kgluon=0.01,20          --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.012j.StandardModel.root
#combine   -M MultiDimFit model_hwwlvlv_012j.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel.root
#
## combine -M MultiDimFit model_hwwlvlv_01j.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.09 --minimizerToleranceForMinos=0.001 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
## combine -M MultiDimFit model_hwwlvlv_01j.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=2 --minimizerTolerance=0.0001 --minimizerToleranceForMinos=0.0001 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
## combine -M MultiDimFit model_hwwlvlv_01j.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=2 --minimizerTolerance=0.0001 --minimizerToleranceForMinos=0.0001                                  --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#combine   -M MultiDimFit model_hwwlvlv_01j.root  --algo=grid --points 240  -m 125.6        --setPhysicsModelParameterRanges kV=0.01,20:kgluon=0.01,20        --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.01j.StandardModel.root
#combine   -M MultiDimFit model_hwwlvlv_01j.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel.root
#
#
#
## 7 TeV
#combine   -M MultiDimFit model_hwwlvlv_0j-7TeV.root  --algo=grid --points 240  -m 125.6                  --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.0j.StandardModel-7TeV.root
#combine   -M MultiDimFit model_hwwlvlv_0j-7TeV.root  --algo=grid --points 240  -t -1 -m 125.6            --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel-7TeV.root
#
#combine   -M MultiDimFit model_hwwlvlv_1j-7TeV.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV.root
#combine   -M MultiDimFit model_hwwlvlv_1j-7TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV.root
#
#
#combine   -M MultiDimFit model_hwwlvlv_2j-7TeV.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.2j.StandardModel-7TeV.root
#combine   -M MultiDimFit model_hwwlvlv_2j-7TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel-7TeV.root
#
#
#combine   -M MultiDimFit model_hwwlvlv_012j-7TeV.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV.root
#combine   -M MultiDimFit model_hwwlvlv_012j-7TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV.root
#
#
#combine   -M MultiDimFit model_hwwlvlv_01j-7TeV.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.01j.StandardModel-7TeV.root
#combine   -M MultiDimFit model_hwwlvlv_01j-7TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel-7TeV.root
#
#
#
#
#
#
# 7 + 8 TeV

combine   -M MultiDimFit Results/model_hwwlvlv_012j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6     --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineTest.MultiDimFit.mH125.6.root      Results/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV-8TeV.root
#combine   -M MultiDimFit Results/model_hwwlvlv_012j-7TeV-8TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Results/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV-8TeV.root

#combine   -M MultiDimFit model_hwwlvlv_0j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.0j.StandardModel-7TeV-8TeV.root
#combine   -M MultiDimFit model_hwwlvlv_0j-7TeV-8TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel-7TeV-8TeV.root
#
## combine   -M MultiDimFit model_hwwlvlv_1j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
## mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV-8TeV.root
## combine   -M MultiDimFit model_hwwlvlv_1j-7TeV-8TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
## mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV-8TeV.root
#
#combine   -M MultiDimFit model_hwwlvlv_1j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6   --setPhysicsModelParameterRanges kV=0.01,20:kgluon=0.01,20              --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV-8TeV.root
#combine   -M MultiDimFit model_hwwlvlv_1j-7TeV-8TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-7TeV-8TeV.root
#
#
#combine   -M MultiDimFit model_hwwlvlv_2j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6                 --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Observed.higgsCombineTest.MultiDimFit.2j.StandardModel-7TeV-8TeV.root
#combine   -M MultiDimFit model_hwwlvlv_2j-7TeV-8TeV.root  --algo=grid --points 240  -t -1 -m 125.6           --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#mv higgsCombineTest.MultiDimFit.mH125.6.root      Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel-7TeV-8TeV.root
#


         



