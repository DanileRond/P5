#include <iostream>
#include "instrument_dumb.h"
#include "seno.h"
#include "chello.h"
#include "keyvalue.h"
/*
  For each new instrument:
  - Add the header in this file
  - Add the call to the constructor in get_instrument() (also in this file)
  - Add the source file to src/meson.build
*/

using namespace std;

namespace upc {
  Instrument * get_instrument(const string &name,
 			      const string &parameters) {
    Instrument * pInst = 0;
    KeyValue("nombre_del_fichero=cellomono.wav");
    //    cout << name << ": " << parameters << endl;
    if (name == "InstrumentDumb") {
      pInst = (Instrument *) new InstrumentDumb(parameters);
    }
    else if (name == "Instrumentseno"){
	pInst = (Instrument *) new Instrumentseno(parameters);
    }
    else if (name == "Instrumentchello"){
//	parameters = "nombre_del_fichero=cellomono.wav";
	pInst = (Instrument *) new Instrumentchello("nombre_del_fichero=cellomono.wav");
    }
    return pInst;
  }
}
