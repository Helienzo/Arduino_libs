/*
  Pwm.h - library for creating pwm. 
  Created by Lucas Wennerholm 2014-06-28
*/
#ifndef Pwm_h
#define Pwm_h

#include "Arduino.h"
#include "Ticker.h"

class Pwm
{
  public:
    Pwm(int pin);
    void pwm(float _freq, long _ontime);
    
  private:
    Ticker pwmTick;
	int _tick1;
    int _pin;
};

#endif