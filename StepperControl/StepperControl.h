/*
  StepperControl.h - Library for controlling laser
  Created by Lucas Wennerholm 2014-02-20
*/
#ifndef StepperControl_h
#define StepperControl_h

#include "Arduino.h"
#include "Ticker.h"

class StepperControl
{
  public:
    StepperControl(int pin1, int pin2, int pin3, int pin4, int length);
    StepperControl();
    void attach(int pin1, int pin2, int pin3, int pin4, int length);
    void step(int _step1,long _time);
    void writeZero();
    int goTo(int step,long _minTime, long _maxTime);
    int goTo_NoHold(int step,long _minTime, long _maxTime);
    int goToPotIn(int step,long _minTime, long _maxTime, int angleIn);
    int stepRet(int _step1,long _time);
    int get();
    void defZero();
    
 
  private:
   Ticker ticker1;
   Ticker ticker2;
   int _length;
   int _pin1;
   int _pin2;
   int _pin3;
   int _pin4;
   int _s1;
   int _next;
   int _ns1;
   int _angle;
   long _time;



};

#endif