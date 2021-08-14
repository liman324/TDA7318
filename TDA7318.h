// liman324@yandex.ru rcl-radio.ru


#ifndef TDA7318_H
#define TDA7318_H

#define TDA7318_address 0x44 // адрес 0b10001000


#include <Arduino.h>
class TDA7318
{
  public:
    TDA7318();
        void setVolume(int vol); //   0...63     
	void setAttLR(int att_lr); // 0..31       
	void setAttRR(int att_rr); // 0..31     
        void setAttLF(int att_lf); // 0..31         
        void setAttRF(int att_rf); // 0..31 
        void setSwitch(int input, int gain); // 0..3 ,  0...3 (0...18.75dB)
        void setBass(int bass); // -7...+7
        void setTreble(int treb); //  -7...+7
	
  private:
	void writeWire(char a);
};
	
#endif //TDA7318_H
