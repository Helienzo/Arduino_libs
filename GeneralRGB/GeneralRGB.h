/*
  GeneralRGB.h - Library for patterns to RGB-LED belt
  Created by Lucas Wennerholm 2014-05-08
*/
#ifndef GeneralRGB_h
#define GeneralRGB_h
#include "Pwm.h"
#include "Arduino.h"



class GeneralRGB
{
  public:
    GeneralRGB(int led1,int led2,int led3,int gnd1,int gnd2, int gnd3);
    void reset();
    int colorsweep(int _time);
    int colorsweepgnd(int _gnd, int _time);
    int onecolor(int _color, int _gnd, int _time);
    int white(int _gnd,int _time);
    int rgbwalk(int _n,int _time);
    int strobe(int _period, int _n);
    void fire(int _n,int _time,int _gnd);
    void wirelight(int on,int beat);
    //void firstSecond();
    //void greenIdiot();
    //void greenOff();
    //void greenOn();
  private:
    int _R;
    int _G;
    int _B;
    int _gnd1;
    int _gnd2;
    int _gnd3;
    int _tick1;
    int _a;
    int _gnd;
    int _pwmTick;
    int _gndCount;
    long _Etime;
    long _Stime;
    long _Ctime;
    int _gndClock;
    long _tottime;
    int freq;
    int _wire;
};

#endif