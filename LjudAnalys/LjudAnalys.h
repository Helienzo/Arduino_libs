/*
  GreenRain.ccp - Library for analysing sound from microfone
  Created by Lucas Wennerholm 2014-06-04
*/
#ifndef LjudAnalys_h
#define LjudAnalys_h

#include "Arduino.h"
#include "Ticker.h"

class LjudAnalys
{
  public:
    LjudAnalys(int Apin);
    int beats(int _mtime);
    int dropVolume(int _mtime);
    int mean(int _time);
    void reset();
    void mreset();
    int vmax(int _time);
    
    

  private:
    long _mvalsum;
    int _val;
    int _Etime;
	int _Stime;
	int _Ctime;
	long _tottime;
	int _tick1;
	long _mStime;
    long _mEtime;
    long _mCtime;
    long _mtottime;
    int _Apin;
	int _mantal;
	int _mean;
	int _maxval;
	int _bval;
	int _ok;
	float _height;
	Ticker ticker1;
	Ticker ticker2;
	Ticker ticker3;
	Ticker ticker4;
	Ticker ticker5;
	Ticker ticker6;
	float _max;
};

#endif