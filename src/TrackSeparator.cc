#include "TrackSeparator.h"
#include <iostream>

#include <EVENT/LCCollection.h>
#include <EVENT/MCParticle.h>
#include <EVENT/LCParameters.h>

// ----- include for verbosity dependend logging ---------
#include "marlin/VerbosityLevels.h"

#ifdef MARLIN_USE_AIDA
#include <marlin/AIDAProcessor.h>
#include <AIDA/IHistogramFactory.h>
#include <AIDA/ICloud1D.h>
//#include <AIDA/IHistogram1D.h>
#endif // MARLIN_USE_AIDA

#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"

using namespace lcio ;
using namespace marlin ;

MyTrackSeparator aTrackSeparator;

MyTrackSeparator::MyTrackSeparator() :
	Processor("TrackSeparator"),
	m_nRun(0),
	m_nEvt(0),
	m_nRunSum(0),
	m_nEvtSum(0),
{

//      modify processor description
_description = "TrackSeparator separates tracks according to the PID and prepares collection for track refitting using the true mass of the particle" ;

//      register steering parameters: name, description, class-variable, default value
	registerInputCollection( 	LCIO::MCPARTICLE,
					"MCParticleCollection" ,
					"Name of the MCParticle collection"  ,
					m_mcParticleCollection,
					std::string("MCParticle")
					);
}
