#include <TDA7318.h>  
TDA7318 tda;

void setup() {
  tda.setVolume(15); // громкость 0...63
  tda.setAttLR(0);   // аттенюатор LR 0...31
  tda.setAttRR(0);   // аттенюатор RR 0...31
  tda.setAttLF(0);   // аттенюатор LF 0...31
  tda.setAttRF(0);   // аттенюатор RF 0...31
  tda.setSwitch(0,0); // вход 0...3, усиление 0...3
  tda.setBass(0);    // тембр НЧ -7...+7
  tda.setTreble(0);  // тембр ВЧ -7...+7
}

void loop() {}

