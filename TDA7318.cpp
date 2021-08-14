#include <Arduino.h>
#include <Wire.h>
#include "TDA7318.h"

TDA7318::TDA7318(){
	Wire.begin();
}

void TDA7318::setVolume(int vol){
  writeWire(vol);
}

void TDA7318::setAttLF(int att_lf){
  att_lf = 0b10000000 + att_lf;
  writeWire(att_lf);
}

void TDA7318::setAttRF(int att_rf){
  att_rf = 0b10100000 + att_rf;
  writeWire(att_rf);
}

void TDA7318::setAttLR(int att_lr){
  att_lr = 0b11000000 + att_lr;
  writeWire(att_lr);
}

void TDA7318::setAttRR(int att_rr){
  att_rr = 0b11100000 + att_rr;
  writeWire(att_rr);
}

void TDA7318::setSwitch(int input, int gain){
  switch (input){
    case 0:input = 0b00000000;break;
    case 1:input = 0b00000001;break;
    case 2:input = 0b00000010;break;
    case 3:input = 0b00000011;break;
  }
  switch (gain){
    case 0:gain = 0b00011000;break;
    case 1:gain = 0b00010000;break;
    case 2:gain = 0b00001000;break;
    case 3:gain = 0b00000000;break; 
  }
  int sw = 0b01000000 + input + gain;
  writeWire(sw);
}

void TDA7318::setBass(int bass){
  switch (bass){
    case -7: bass = 0b01100000;break;
    case -6: bass = 0b01100001;break;
    case -5: bass = 0b01100010;break;
    case -4: bass = 0b01100011;break; 
    case -3: bass = 0b01100100;break;
    case -2: bass = 0b01100101;break;
    case -1: bass = 0b01100110;break;
    case 0:  bass = 0b01100111;break;
    case 1:  bass = 0b01101110;break;
    case 2:  bass = 0b01101101;break;
    case 3:  bass = 0b01101100;break;
    case 4:  bass = 0b01101011;break;
    case 5:  bass = 0b01101010;break;
    case 6:  bass = 0b01101001;break;
    case 7:  bass = 0b01101000;break;
  }
  writeWire(bass);
}

void TDA7318::setTreble(int treb){
  switch (treb){
    case -7: treb = 0b01110000;break;
    case -6: treb = 0b01110001;break;
    case -5: treb = 0b01110010;break;
    case -4: treb = 0b01110011;break; 
    case -3: treb = 0b01110100;break;
    case -2: treb = 0b01110101;break;
    case -1: treb = 0b01110110;break;
    case 0:  treb = 0b01111111;break;
    case 1:  treb = 0b01111110;break;
    case 2:  treb = 0b01111101;break;
    case 3:  treb = 0b01111100;break;
    case 4:  treb = 0b01111011;break;
    case 5:  treb = 0b01111010;break;
    case 6:  treb = 0b01111001;break;
    case 7:  treb = 0b01111000;break;
  }
  writeWire(treb);
}

void TDA7318::writeWire(char a){
  Wire.beginTransmission(TDA7318_address);
  Wire.write (a);
  Wire.endTransmission();
}
