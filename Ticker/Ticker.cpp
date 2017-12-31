/*
  GreenRain.ccp - Library for analysing sound from microfone
  Created by Lucas Wennerholm 2014-06-04
*/

#include "Arduino.h"
#include "Ticker.h"

Ticker::Ticker()
{
_Etime;
_Stime = 0;
_Ctime;
_tick1 = 0;
 }
//********************************Method rain***************************************
 void Ticker::reset() {
    _Stime = 0;
    _Etime = 0;
    _Ctime = 0;
 }
 
 int Ticker::tickMicros(long _time) {
    if (_Stime == 0) {
      _Stime = micros();
    }
    
    _Ctime = micros();
    _Etime = _Ctime - _Stime;
    
    
   if (_Etime >= _time) {
        _Stime = 0;
    	_Etime = 0;
   		_Ctime = 0;
   		return 1;
   }
	return 0;
}

int Ticker::tick(int _time) {
    if (_Stime == 0) {
      _Stime = millis();
    }
    
    _Ctime = millis();
    _Etime = _Ctime - _Stime;
    
    
   if (_Etime >= _time) {
        _Stime = 0;
    	_Etime = 0;
   		_Ctime = 0;
   		return 1;
   }
	return 0;
}

int Ticker::periodicTick(int _time) {

       if (_Stime == 0) {
      _Stime = millis();
    }
    
    _Ctime = millis();
    _Etime = _Ctime - _Stime;
    
    
   if (_Etime >= _time) {
        _Stime = 0;
    	_Etime = 0;
   		_Ctime = 0;
   		
   		if (_tick1 == 0) {
   				_tick1 = 1;
   		}
   		else {
   				_tick1 = 0;
   		}
   }
	return _tick1;
}

int Ticker::onOffTick(long _ontime,long _offtime){
    if (_Stime == 0) {
      _Stime = micros(); //millis()
    }
    
    _Ctime = micros(); //millis()
    _Etime = _Ctime - _Stime;
    
    
   if (_Etime >= _offtime && _tick1 == 0) {
        _Stime = 0;
    	_Etime = 0;
   		_Ctime = 0;
   		_tick1 = 1;
        
   }
   if (_Etime >= _ontime && _tick1 == 1) {
        _Stime = 0;
    	_Etime = 0;
   		_Ctime = 0;
   		_tick1 = 0;
   }
   
	return _tick1;




}