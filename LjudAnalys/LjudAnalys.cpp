/*
  GreenRain.ccp - Library for analysing sound from microfone
  Created by Lucas Wennerholm 2014-06-04
*/

#include "Arduino.h"
#include "LjudAnalys.h"
#include "Ticker.h"

LjudAnalys::LjudAnalys(int Apin)
{
_mantal = 0;
_mvalsum = 0;
_val = 0;
_Etime;
_Stime = 0;
_Ctime;
_tottime = 0;
_tick1 = 0;
_Apin = Apin;
_mStime = 0;
_mCtime = 0;
_mEtime = 0;
_mtottime = 0;
_mean = 160;
_height;
_maxval;
_max = 100;
_bval;
_ok = 1;
 
 }
//********************************Method***************************************
 void LjudAnalys::reset() {
    _tick1 = 0;
    _Stime = 0;
    _Etime = 0;
    _Ctime = 0;
    _tottime = 0;

 } 
 void LjudAnalys::mreset() {
    _mStime = 0;
    _mEtime = 0;
    _mCtime = 0;
    _mtottime = 0;
    }

int LjudAnalys::beats(int _mtime) {
// beats levererar en 1'a om volymen når en given gräns skalad med mean.
vmax(5000);
int _go;
if (ticker1.periodicTick(_mtime + _mtime/10) == 1) {
	 mean(_mtime);
}

if (ticker5.tickMicros(1000) == 1) {
	_bval = analogRead(_Apin)-_mean;
	if (_bval > 0.4*_max) {
		 _go = 1;
	} else {
		 _go = 0;
	}
}

if (_go == 1 && _ok == 1) {
	_ok = 0;
	
	return 1;
}

if (_go == 0 && _ok == 0) {
	if (ticker6.tick(300) == 1 ) {
		_ok = 1;
	}
	}


return 0;
  
}

int LjudAnalys::vmax(int _time) {
	
	if (ticker4.periodicTick(_time + _time/10) == 1) {
	 
	  if (ticker3.tickMicros(1000) == 1) {
	  	
	  	int _temp = analogRead(_Apin)-_mean;
	  	if (_maxval < analogRead(_Apin)-_mean){
	  		_maxval = _temp;
	  		
	  	}
	  }
    }
    
    if(ticker4.periodicTick(_time + _time/10) == 0 && _maxval > 0) {
     int _temp = _maxval;
     if (_maxval > 70) {
     _max = _maxval;
     }
     else {
     _max = 70;
     }
     _maxval = 0;
     return _temp;
    }
    
	return 0;
}

int LjudAnalys::mean(int _time) {
// 1000 read's per second.
    if (_mStime == 0) {
      _mStime = micros();
      _mantal = 0;
      _mvalsum = 0;
    }
    
    _mCtime = micros();
    _mEtime = _mCtime - _mStime;
    
    
   if (_mEtime >= 1000) {
   		_mStime = micros();
   		_mtottime = _mtottime + _mEtime/1000;
   		_mvalsum += analogRead(_Apin);
   		_mantal++;
   }
   
   if (_mtottime >= _time) {
		mreset();
		_mean = _mvalsum/_mantal;
   		return _mean;
   }
   return 0;
  

}


int LjudAnalys::dropVolume(int _mtime) {
// dropVolume levererar ett tall mellan 1-255 som anger "volymen" på ljudet skalad med mean.

	 vmax(5000); // Hur läng/ofta vi får en maxvolym;

if (ticker1.periodicTick(_mtime + _mtime/10) == 1) {
	 mean(_mtime);
}

if (ticker2.tickMicros(1000) == 1) {
	//float _max = 100;
	float _dspeed = 0.5; // denna varibal avgör hur snabbt styrkan minskar efter topp.
	_val = analogRead(_Apin)-_mean;
	//Serial.println(_val);
	if (_val < 0) {
		_val = -_val;
	}
	if (_val > _max) {
	   _val = _max;
	}
	
	if (_val>0.1*_max && _val>_height) {
		_height = _val;
	}
	else {
		_height += -_dspeed;
		if (_height<0.1*_max) {
			_height = 0.1*_max;
		}
	}
	
	_val = 255*(_height/_max);
	//Serial.println(_val);
    
}
 return _val;
}




