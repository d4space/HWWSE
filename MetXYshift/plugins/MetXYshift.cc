// -*- C++ -*-
//
// Package:    HWWSE/MetXYshift
// Class:      MetXYshift
// 
/**\class MetXYshift MetXYshift.cc HWWSE/MetXYshift/plugins/MetXYshift.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  SangEun Lee
//         Created:  Wed, 18 May 2016 07:53:32 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

#include "TTree.h"
#include "TVector2.h"
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class MetXYshift : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit MetXYshift(const edm::ParameterSet&);
      ~MetXYshift();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
      edm::Service<TFileService> fs;
      TTree* OutTree;

      edm::EDGetTokenT<pat::METCollection> slimMetToken_;
      edm::EDGetTokenT<pat::METCollection> slimMetTxyToken_;
      edm::EDGetTokenT<reco::VertexCollection> vtxToken_;
      TVector2 t2_slimMet;
      TVector2 t2_slimMetTxy;
      Int_t  npv;
};

//
// constants, enums and typedefs
//
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> > LorentzVector;

//
// static data member definitions
//

//
// constructors and destructor
//
MetXYshift::MetXYshift(const edm::ParameterSet& iConfig):
  slimMetToken_(consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("slimMets"))),
  slimMetTxyToken_(consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("slimMetTxys"))),
  vtxToken_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices")))

{
   //now do what ever initialization is needed
   usesResource("TFileService");

}


MetXYshift::~MetXYshift()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
MetXYshift::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   Handle<pat::METCollection> slimMets;
   Handle<pat::METCollection> slimMetTxys;
   Handle<reco::VertexCollection> vertices;

   iEvent.getByToken(slimMetToken_   , slimMets);
   iEvent.getByToken(slimMetTxyToken_, slimMetTxys);
   iEvent.getByToken(vtxToken_, vertices);

   // good vertex requirement
   if (vertices->empty()) return; // skip the event if no PV found
   const reco::Vertex &PV = vertices->front();
   npv = vertices->size();

   const pat::MET &slimMet       = slimMets->front();
   const pat::MET &slimMetTxy   = slimMetTxys->front();

   t2_slimMet    = TVector2(slimMet.px(),       slimMet.py());
   t2_slimMetTxy = TVector2(slimMetTxy.px(),    slimMetTxy.py());

   // Fill Tree
   OutTree->Fill();

}


// ------------ method called once each job just before starting event loop  ------------
void 
MetXYshift::beginJob()
{
  OutTree = fs->make<TTree>("Events", "Events");
  OutTree->Branch("t2_slimMet",    &t2_slimMet); // Type-1 corrected PF MET
  OutTree->Branch("t2_slimMetTxy", &t2_slimMetTxy);// Type-1 corrected PF MET
  OutTree->Branch("npv",           &npv,         "npv/I");          // number of primary vertices

}

// ------------ method called once each job just after ending the event loop  ------------
void 
MetXYshift::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MetXYshift::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MetXYshift);
