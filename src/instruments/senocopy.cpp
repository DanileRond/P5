#include <iostream>
#include <math.h>
#include "seno.h"
#include "keyvalue.h"

#include <stdlib.h>

using namespace upc;
using namespace std;

Instrumentseno::Instrumentseno(const std::string &param) 
  : adsr(SamplingRate, param) {
  bActive = false;
  x.resize(BSIZE);
  /*
    You can use the class keyvalue to parse "param" and configure your instrument.
    Take a Look at keyvalue.h    
  */
//  KeyValue kv(param);
  int N;
std::string file_name;
static string kv_null;
if ((file_name = kv("../../work/ringtones-old-telephone.mp3")) == kv_null) {
cerr << "Error: no se ha encontrado el campo con el fichero de la señal para uninstrumento FicTabla" << endl;
throw -1;
}
unsigned int fm;
if (readwav_mono(../../work/ringtones-old-telephone.mp3, fm, tbl) < 0) {
cerr << "Error: no se puede leer el fichero " << file_name << " para un instrumento FicTabla" << endl;
throw -1;
}

//  if (!kv.to_int("../../work/ringtones-old-telephone.mp3",N))
    
}


void Instrumentseno::command(long cmd, long note, long vel) {

f0 = 440*pow(2,(note - 69.)/12);
fprintf(stdout,"f0-->%f\n",f0);
  if (cmd == 9) {		//'Key' pressed: attack begins
    bActive = true;
    adsr.start();
    index = 0;
	phas = 0;
//	increment = 10*(f0/(SamplingRate/tbl.size()));
//	increment = 2 * M_PI * (f0/SamplingRate);
	increment = ((f0 / SamplingRate) * tbl.size());
//	increment = SamplingRate / (f0) ;
	fprintf(stdout,"increment-->%d\n",increment);
	fprintf(stdout,"tblsize-->%d\n",tbl.size());
	A = vel / 127.;
	phas = 0;
  }
  else if (cmd == 8) {	//'Key' released: sustain ends, release begins
    adsr.stop();
  }
  else if (cmd == 0) {	//Sound extinguished without waiting for release to end
    adsr.end();
  }
}


const vector<float> & Instrumentseno::synthesize() {
  if (not adsr.active()) {
    x.assign(x.size(), 0);
    bActive = false;
    return x;
  }
  else if (not bActive)
    return x;

  for (unsigned int i=0; i<x.size(); ++i) {

  //fprintf(stdout,"index--->%d\n",index); 
// 	x[i] = A * sin(phas);
	phas = phas + increment;
	x[i] = A * tbl[round(phas)];


	 while(phas >= tbl.size()) phas = phas - tbl.size();

  }
  adsr(x); //apply envelope to x and update internal status of ADSR

  return x;
}
