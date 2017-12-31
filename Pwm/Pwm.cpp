/*
  Pwm.ccp - library for creating pwm. 
  Created by Lucas Wennerholm 2014-06-28
*/

#include "Arduino.h"
#include "Ticker.h"
#include "Pwm.h"

Pwm::Pwm(int pin)
{
   //variabler
 _pin = pin;
 }
 
 
  void Pwm::pwm(float _freq, long _ontime) {  //ontime number 0-255
  
  		_tick1 = pwmTick.onOffTick(((1/_freq)*1000000)/255*_ontime,(1/_freq)*1000000 - _ontime);
        if (_tick1 == 1 && _ontime != 0 && _ontime != 255) {
        	digitalWrite(_pin,HIGH);        	
        }
        if ((_tick1 == 0 && _ontime != 0 && _ontime != 255)) {
        	digitalWrite(_pin,LOW);
        }
        
        if (_ontime == 0) {
        	digitalWrite(_pin,LOW);
        }
        
        if (_ontime == 255) {
        	digitalWrite(_pin,HIGH);
        }
        	
  }