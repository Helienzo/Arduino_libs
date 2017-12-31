/*
  GeneralStep.h - Library for controlling laser
  Created by Lucas Wennerholm 2014-02-20
*/
#ifndef GeneralStep_h
#define GeneralStep_h

#include "Arduino.h"
#include "Ticker.h"

class GeneralStep
{
  public:
    GeneralStep(int pin1, int pin2, int pin3, int pin4);
    void step(int _step1,int _time);
    int _s1;
    int _s2;
    int _ns1;
    int _ns2;
  private:
   int _pin1;
   int _pin2;
   int _pin3;
   int _pin4;


};

#endif