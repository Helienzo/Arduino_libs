/*
  BoxRGB.h - Library for patterns to RGB-LED box
  Created by Lucas Wennerholm 2014-05-08
*/
#ifndef BoxRGB_h
#define BoxRGB_h

#include "Arduino.h"

class BoxRGB
{
  public:
    BoxRGB(int led1,int led2,int led3,int gnd1,int gnd2, int gnd3);
    void colorsweep(int _n,int _time);
    void colorsweepgnd(int _n,int _time, int _gnd);
    void onecolor(int _color, int _gnd);
    void white(int _gnd);
    void rgbwalk(int _n,int _time);
    void rgbwalkall(int _n,int _time);
    void fire(int _n,int _time,int _gnd);
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
};

#endif