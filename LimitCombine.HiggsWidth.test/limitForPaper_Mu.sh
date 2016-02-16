         
         
#         
#
text2workspace.py -m 125.6 Results/hwidth_0jet-7TeV-8TeV.txt  -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW_muFV_SE:higgswidth  --PO=MHScaleWW --PO=is2l2nuGGsmfixed -o  Results_Mu/model_hwwlvlv_0j-7TeV-8TeV.root
text2workspace.py -m 125.6 Results/hwidth_1jet-7TeV-8TeV.txt  -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW_muFV_SE:higgswidth  --PO=MHScaleWW --PO=is2l2nuGGsmfixed -o  Results_Mu/model_hwwlvlv_1j-7TeV-8TeV.root
text2workspace.py -m 125.6 Results/hwidth_2jet-7TeV-8TeV.txt  -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW_muFV_SE:higgswidth  --PO=MHScaleWW --PO=is2l2nuGGsmfixed -o  Results_Mu/model_hwwlvlv_2j-7TeV-8TeV.root
text2workspace.py -m 125.6 Results/hwidth_012jet-7TeV-8TeV.txt  -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWW_muFV_SE:higgswidth  --PO=MHScaleWW --PO=is2l2nuGGsmfixed -o  Results_Mu/model_hwwlvlv_012j-7TeV-8TeV.root
#
# 7 + 8 TeV

# 0-jet
combine   -M MultiDimFit Results_Mu/model_hwwlvlv_0j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV_off=0,100 --name ObserveWWkV0j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineObserveWWkV0j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/

combine   -M MultiDimFit Results_Mu/model_hwwlvlv_0j-7TeV-8TeV.root -t -1 --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV_off=0,100 --name AsimovWWkV0j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineAsimovWWkV0j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/
# 1-jet
combine   -M MultiDimFit Results_Mu/model_hwwlvlv_1j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV_off=0,100 --name ObserveWWkV1j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineObserveWWkV1j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/

combine   -M MultiDimFit Results_Mu/model_hwwlvlv_1j-7TeV-8TeV.root -t -1 --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV_off=0,100 --name AsimovWWkV1j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineAsimovWWkV1j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/
# 2-jet
combine   -M MultiDimFit Results_Mu/model_hwwlvlv_2j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV_off=0,100 --name ObserveWWkV2j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineObserveWWkV2j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/

combine   -M MultiDimFit Results_Mu/model_hwwlvlv_2j-7TeV-8TeV.root -t -1 --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV_off=0,100 --name AsimovWWkV2j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineAsimovWWkV2j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/


#012-jet
combine   -M MultiDimFit Results_Mu/model_hwwlvlv_012j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV_off=0,100 --name ObserveWWkV012j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineObserveWWkV012j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/

combine   -M MultiDimFit Results_Mu/model_hwwlvlv_012j-7TeV-8TeV.root -t -1 --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV_off=0,100 --name AsimovWWkV012j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineAsimovWWkV012j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/
