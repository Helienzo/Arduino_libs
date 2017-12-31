/*
  GreenRain.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "StepperControl.h"
#include "Ticker.h"


StepperControl::StepperControl() {
	_pin1 = 0;
	_pin2 = 0;
	_pin3 = 0;
	_pin4 = 0;
	_length = 0;
	_time = 0;
	_s1 = 1;
	_next = 1;
	_ns1 = 0;
	_angle = 0;
}

StepperControl::StepperControl(int pin1, int pin2, int pin3, int pin4,int length)
{
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
_pin1 = pin1;
_pin2 = pin2;
_pin3 = pin3;
_pin4 = pin4;
_length = length;
_time = 0;

_s1 = 1;
_next = 1;
_ns1 = 0;
_angle = 0;
 
 }
//********************************Method attach***************************************
void StepperControl::attach(int pin1, int pin2, int pin3, int pin4,int length) {
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
_pin1 = pin1;
_pin2 = pin2;
_pin3 = pin3;
_pin4 = pin4;
_length = length;
_time = 0;

_s1 = 1;
_next = 1;
_ns1 = 0;
_angle = 0;
}

//********************************Method step***************************************
void StepperControl::step(int _step1,long _time) {

int val;

//steper1
if (_step1 == 0) {
    val = 0;
    }
if (_step1 == 1) {
    val = 1;
    _s1 = _next;
    //ticker2.reset();
    }
if (_step1 == -1) {
    val = 2; 
    _s1 = _next;
    //ticker1.reset();
    }
     
if (_ns1 == 0) {
        // this if runs on first loop val is 1 or 2
        _ns1 = val;
}

// -------- stepping
if (ticker1.tickMicros(_time) != 0) {
	if (val == 1) {
		
		if (_ns1 == 2) {
			 if (_s1 == 1) {
			 _s1 = 3;
			 }
			 if (_s1 == 2) {
			 _s1 = 4;  
			 }
			 if (_s1 == 3) {
			 _s1 = 1;   
			 }
			 if (_s1 == 4) {
			 _s1= 2;  
			 }
		  _ns1 = val;   
		}
	 
		if (_s1 == 1) {
	 
			digitalWrite(_pin1,HIGH);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,HIGH);
			digitalWrite(_pin4,LOW);
			_next = 2;
			}
		if (_s1 == 2) {
			digitalWrite(_pin1,HIGH);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,HIGH);
			_next = 3;
		}
		
		if (_s1 == 3) {
			
			digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,HIGH);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,HIGH);
			_next = 4;
		}
		if (_s1 == 4) {
			
			digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,HIGH);
			digitalWrite(_pin3,HIGH);
			digitalWrite(_pin4,LOW);
			
			_next = 1;
		}
			
	}
}
//-----------------------------------------_step1 left
    
if (ticker2.tickMicros(_time) != 0) {
	if (val == 2) {
		
		 if (_ns1 == 1) {
			 
			 if (_s1 == 1) {
			 _s1 = 3;
			 }
			 if (_s1 == 2) {
			 _s1 = 4;
			 }
			 if (_s1 == 3) {
			 _s1 = 1;  
			 }
			 if (_s1 == 4) {
			 _s1= 2;  
			 }
		  _ns1 = val;   
		}
		
		
		if (_s1 == 1) {
	 
			digitalWrite(_pin1,HIGH);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,HIGH);
			digitalWrite(_pin4,LOW);
			_next = 4;
			}
		if (_s1 == 2) {
			
			digitalWrite(_pin1,HIGH);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,HIGH);
			_next = 1;
			}
		if (_s1 == 3) {
			
			digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,HIGH);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,HIGH);
			_next = 2;
			}
		if (_s1 == 4) {
			
			digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,HIGH);
			digitalWrite(_pin3,HIGH);
			digitalWrite(_pin4,LOW);
			_next = 3; 
		}
	 }
	}
}



//********************************Method stepRet***************************************
int StepperControl::stepRet(int _step1,long _time) {

int val;

//steper1
if (_step1 == 0) {
    val = 0;
    }
if (_step1 == 1) {
    val = 1;
    _s1 = _next;
    ticker2.reset();
    }
if (_step1 == -1) {
    val = 2; 
    _s1 = _next;
    ticker1.reset();
    }
     
if (_ns1 == 0) {
        // this if runs on first loop val is 1 or 2
        _ns1 = val;
}

// -------- stepping
if (ticker1.tickMicros(_time) != 0) {
	if (val == 1) {
		
		if (_ns1 == 2) {
			 if (_s1 == 1) {
			 _s1 = 3;
			 }
			 if (_s1 == 2) {
			 _s1 = 4;  
			 }
			 if (_s1 == 3) {
			 _s1 = 1;   
			 }
			 if (_s1 == 4) {
			 _s1= 2;  
			 }
		  _ns1 = val;   
		}
	 
		if (_s1 == 1) {
	 
			digitalWrite(_pin1,HIGH);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,HIGH);
			digitalWrite(_pin4,LOW);
			_next = 2;
			}
		if (_s1 == 2) {
			digitalWrite(_pin1,HIGH);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,HIGH);
			_next = 3;
		}
		
		if (_s1 == 3) {
			
			digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,HIGH);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,HIGH);
			_next = 4;
		}
		if (_s1 == 4) {
			
			digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,HIGH);
			digitalWrite(_pin3,HIGH);
			digitalWrite(_pin4,LOW);
			
			_next = 1;
		}
			
	}
	_angle = _angle + 1;
	return 1;
}
//-----------------------------------------_step1 left
    
if (ticker2.tickMicros(_time) != 0) {
	if (val == 2) {
		
		 if (_ns1 == 1) {
			 
			 if (_s1 == 1) {
			 _s1 = 3;
			 }
			 if (_s1 == 2) {
			 _s1 = 4;
			 }
			 if (_s1 == 3) {
			 _s1 = 1;  
			 }
			 if (_s1 == 4) {
			 _s1= 2;  
			 }
		  _ns1 = val;   
		}
		
		
		if (_s1 == 1) {
	 
			digitalWrite(_pin1,HIGH);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,HIGH);
			digitalWrite(_pin4,LOW);
			_next = 4;
			}
		if (_s1 == 2) {
			
			digitalWrite(_pin1,HIGH);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,HIGH);
			_next = 1;
			}
		if (_s1 == 3) {
			
			digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,HIGH);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,HIGH);
			_next = 2;
			}
		if (_s1 == 4) {
			
			digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,HIGH);
			digitalWrite(_pin3,HIGH);
			digitalWrite(_pin4,LOW);
			_next = 3; 
		}
	 }
	 _angle = _angle - 1;
	 return 1;
	}
	return 0;
}

//********************************Method goTo***************************************
int StepperControl::goTo(int step,long _minTime, long _maxTime) {
    long st = step;
    long an = _angle;
    if (_angle < step) {
        _time = _minTime + (_maxTime/(st-an+1)) ;
        stepRet(1,_time);
    }
    
    if (_angle > step ) {
    _time = _minTime + (_maxTime/(an-st+1)) ;
        stepRet(-1,_time);
    }
    //Serial.println(_time);
    return _angle;
}
void StepperControl::writeZero() {
    	    digitalWrite(_pin1,LOW);
			digitalWrite(_pin2,LOW);
			digitalWrite(_pin3,LOW);
			digitalWrite(_pin4,LOW);
}

int StepperControl::goTo_NoHold(int step,long _minTime, long _maxTime) {
    long st = step;
    long an = _angle;
    if (_angle < step) {
        _time = _minTime + (_maxTime/(st-an+1)) ;
        stepRet(1,_time);
    }
    
    if (_angle > step ) {
    _time = _minTime + (_maxTime/(an-st+1)) ;
        stepRet(-1,_time);
    }
    
     if (_angle == step ) {
       writeZero();
    }
    
    //Serial.println(_time);
    return _angle;
}

//********************************Method goToPotIn***************************************
int StepperControl::goToPotIn(int step,long _minTime, long _maxTime,int angleIn) {
    long st = step;
    long an = angleIn;
    if (angleIn < step) {
        _time = _minTime + (_maxTime/(st-an+1)) ;
        stepRet(1,_time);
    }
    
    if (angleIn > step ) {
    _time = _minTime + (_maxTime/(an-st+1)) ;
        stepRet(-1,_time);
    }
    //Serial.println(_time);
    return step;
}

//********************************Method defZero***************************************
void StepperControl::defZero() {
    _angle = 0;
}

//********************************Method get***************************************
int StepperControl::get() {
    return _pin1;
}
