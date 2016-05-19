from HWWSE.MetXYshift.ConfFile_cfg import *

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 500
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.source.fileNames = cms.untracked.vstring(
    'file:/u/user/salee/Latino/CMSSW805/src/JetMETCorrections/Type1MET/test/histoTest.root'
    )


process.TFileService = cms.Service("TFileService",
    fileName = cms.string('XYshiftNtuple.root')
    )

process.demo.vertices = cms.InputTag("offlineSlimmedPrimaryVertices")
process.demo.slimMets = cms.InputTag("slimmedMETs")
process.demo.slimMetTxys = cms.InputTag("pfMetTxy")
