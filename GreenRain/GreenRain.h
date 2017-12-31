/*
  GreenRain.h - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/
#ifndef GreenRain_h
#define GreenRain_h

#include "Arduino.h"

class GreenRain
{
  public:
    GreenRain(int pin1,int pin2,int pin3,int pin4);
    void rain(int _n,int _time);
    void backwardRain(int _n,int _time);
    void rainBaseUp(int _n,int _time);
    void rainBaseDown();
    void greenPulseUp(int _time);
    void greenPulseDown(int _time);
    void firstSecond();
    void greenIdiot();
    void greenOff();
    void greenOn();
  private:
    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
    int _led1;
    int _led2;
    int _led3;
    int _led4;
    int _tick1;
};

#endif