import FWCore.ParameterSet.Config as cms

process = cms.Process("GenCheck")
#process.load("TerraNova.NtupleMaker.wAnalysis_MC_cff")

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.MessageLogger = cms.Service("MessageLogger")
#process.MessageLogger.destinations = ['cout']
#process.MessageLogger.cout = cms.untracked.PSet(
#    threshold = cms.untracked.string('INFO'),
#    FwkReport = cms.untracked.PSet(reportEvery=cms.untracked.int32(1000))
#)
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:../../../../RunIIData/testSample/WGstarToLNu2E_TuneZ2star_8TeV-madgraph-tauola/Summer12_DR53X/2C549E1A-4DDC-E111-97CE-001A9281170E.root'),
    #fileNames = cms.untracked.vstring('file:../../../../RunIIData/testSample/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv1/02137088-4CA0-E511-BA41-002590775158.root'),
    #fileNames = cms.untracked.vstring('file:../../../../RunIIData/testSample/WZJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv1/006DEE0F-A49F-E511-B06C-0CC47A009E26.root'),
    #fileNames = cms.untracked.vstring('file:../../../../RunIIData/testSample/WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8/RunIIFall15MiniAODv1/023B7844-83B4-E511-BDEC-0CC47A78A2EC.root'),
)

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printTree = cms.EDAnalyzer("ParticleListDrawer",
    maxEventsToPrint = cms.untracked.int32(1000),
    printVertex = cms.untracked.bool(False),
    printOnlyHardInteraction = cms.untracked.bool(False), # Print only status=3 particles. This will not work for Pythia8, which does not have any such particles.
    #src = cms.InputTag("prunedGenParticles"),
    src = cms.InputTag("genParticles"),
    )
#process.load("TerraNova.NtupleMaker.Sources.WplusToMuNu_S8_8TeV_AODSIM_PatSkim_local_cff")

process.p = cms.Path(
    process.printTree
)

