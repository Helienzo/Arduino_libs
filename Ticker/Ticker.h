/*
  GreenRain.ccp - Library for analysing sound from microfone
  Created by Lucas Wennerholm 2014-06-04
*/
#ifndef Ticker_h
#define Ticker_h

#include "Arduino.h"

class Ticker
{
  public:
    Ticker();
    int tick(int _time);
    int tickMicros(long _time);
    int periodicTick(int _time);
    int onOffTick(long _ontime,long _offtime);
    void reset();
    
  private:
    long _Etime;
	long _Stime;
	long _Ctime;
	int _tick1;

};

#endif