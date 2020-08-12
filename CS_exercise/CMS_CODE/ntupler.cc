// -*- C++ -*-
//
// Package:    ntuple_generator/ntupler
// Class:      ntupler
// 
/**\class ntupler ntupler.cc ntuple_generator/ntupler/plugins/ntupler.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  ZHENG-GANG CHEN
//         Created:  Fri, 07 Aug 2020 08:50:01 GMT
//
//


// system include files
#include <memory>
#include <iostream>

// user include files
//////////////////
//-- Frame Works//
//////////////////
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSetfwd.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DataFormats/Common/interface/Handle.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/Utilities/interface/RegexMatch.h"

////////////////
// -- Else -- //
////////////////
#include "DataFormats/Math/interface/LorentzVector.h"
////////////////
// -- ROOT --///
///////////////
#include <vector>
#include <cmath>
#include <TTree.h>
#include <TSystem.h>
#include <TFile.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TFrame.h>
#include <TMath.h>
#include <TF1.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <boost/foreach.hpp>
///////////////////////
// -- GenParticle -- //
///////////////////////
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.
using namespace std;

class ntupler : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit ntupler(const edm::ParameterSet&);
      ~ntupler();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
      edm::EDGetTokenT<vector<reco::GenParticle>> GenParticlesToken_;
      
//      edm::EDGetTokenT<vector<reco::CaloJet>> CaloJetsToken_;
      vector<double> *GenParticle_energy = nullptr;
      
      TTree *mytree = new TTree("Mytree","Mytree");
    
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
ntupler::ntupler(const edm::ParameterSet& iConfig):
GenParticlesToken_(consumes<vector<reco::GenParticle>>(edm::InputTag("genParticles")))
{
   //now do what ever initialization is needed
   usesResource("TFileService");
   edm::Service<TFileService> fs;
}


ntupler::~ntupler()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  -----------void
void
ntupler::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   Handle<vector<reco::GenParticle>> GenParticles;
   iEvent.getByToken( GenParticlesToken_ , GenParticles );
 //  Handle<vector<reco::CaloJet>> calojets;
 //  iEvent.getByToken( CaloJetsToken_ , genparticles );
   GenParticle_energy->clear();
   for(vector<reco::GenParticle>::const_iterator g = GenParticles->begin(); g != GenParticles->end(); ++g)
   {
    GenParticle_energy->push_back( g->energy() );      
   }


#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
   mytree->Fill();
}


// ------------ method called once each job just before starting event loop  ------------
void 
ntupler::beginJob()
{
    mytree->Branch("GenParticle_energy",&GenParticle_energy,"GenParticle_energy/D");
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ntupler::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
ntupler::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ntupler);
