         
         
#         
#
echo "rm -f Results_Mu/model_hwwlvlv_012j-7TeV-8TeV.root"
rm -f Results_Mu/model_hwwlvlv_012j-7TeV-8TeV.root
text2workspace.py -m 125.6 Results/hwidth_012jet-7TeV-8TeV.txt  -P LimitCombine.HiggsWidth.HiggsWidthKappaCustodialMHSscaleWWkvkfgammaModel_SE:higgswidth  --PO=MHScaleWW --PO=is2l2nuGGsmfixed -o  Results_Mu/model_hwwlvlv_012j-7TeV-8TeV.root
#
# 7 + 8 TeV

combine   -M MultiDimFit Results_Mu/model_hwwlvlv_012j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6 --name ObserveWWkV012j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
#combine   -M MultiDimFit Results_Mu/model_hwwlvlv_012j-7TeV-8TeV.root  --algo=grid --points 240  -m 125.6 --setPhysicsModelParameterRanges kV=0,100 --name ObserveWWkV012j7.8TeV   --minimizerAlgo=Minuit2 --minimizerAlgoForMinos=Minuit2 --minimizerStrategy=1 --minimizerTolerance=0.009 --minimizerToleranceForMinos=0.01 --cminFallbackAlgo Minuit,0.001  --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND      --verbose -1
mv higgsCombineObserveWWkV012j7.8TeV.MultiDimFit.mH125.6.root    Results_Mu/
