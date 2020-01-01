#ifndef INSTRUMENT_SENO
#define INSTRUMENT_SENO

#include <vector>
#include <string>
#include "instrument.h"
#include "envelope_adsr.h"

namespace upc {
  class Instrumentseno: public upc::Instrument {
    EnvelopeADSR adsr;
    unsigned int index;
	float A;
    std::vector<float> tbl;
    float f0, increment;
  public:
    Instrumentseno(const std::string &param = "");
    void command(long cmd, long note, long velocity=1000); 
    const std::vector<float> & synthesize();
    bool is_active() const {return bActive;} 
  };
}

#endif
