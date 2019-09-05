#ifndef TrackSeparator_h
#define TrackSeparator_h 1

#include "EVENT/LCStrVec.h"
#include "marlin/Processor.h"
#include "IMPL/LCCollectionVec.h"
#include "lcio.h"
#include <string>
#include <vector>
#include <math.h>

#include <set>
#include <vector>

class TFile;
class TH1F;
class TTree;

using namespace lcio ;
using namespace marlin ;

class TrackSeparator : public Processor {

 public:

  virtual Processor*  newProcessor() { return new TrackSeparator ; }


  TrackSeparator() ;

  virtual void init() ;

  virtual void processRunHeader( lcio::LCRunHeader *pLCRunHeader ) ;

  virtual void processEvent( EVENT::LCEvent *pLCEvent ) ;


  virtual void check( EVENT::LCEvent *pLCEvent ) ;

private:

  void Clear();

  void ExtractCollections(EVENT::LCEvent *pLCEvent);

  virtual void end() ;


 protected:

	int					m_nRun{};
	int					m_nEvt{} ;
	int					m_nRunSum{};
	int					m_nEvtSum{};

} ;

#endif
