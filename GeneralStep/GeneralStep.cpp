/*
  GreenRain.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "GeneralStep.h"
#include "Ticker.h"

GeneralStep::GeneralStep(int pin1, int pin2, int pin3, int pin4)
{
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
_pin1 = pin1;
_pin2 = pin2;
_pin3 = pin3;
_pin4 = pin4;

_s1 = 1;
_ns1 = 0;
 
 }
//********************************Method rain***************************************
void GeneralStep::step(int _step1,int _time) {

int val;

//steper1
if (_step1 == 0) {
    val = 0;
    }
if (_step1 == 1) {
    val = 1;
    }
if (_step1 == -1) {
    val = 2; 
    }
     
if (_ns1 == 0) {
        // this if runs on first loop val is 1 or 2
        _ns1 = val;
}

// -------- stepping

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
 
        digitalWrite(_pin1,1);
        digitalWrite(_pin2,0);
        digitalWrite(_pin3,1);
        digitalWrite(_pin4,0);
        _s1 = 2;
        delay(_time);
        return;
        }
    if (_s1 == 2) {
        digitalWrite(_pin1,1);
        digitalWrite(_pin2,0);
        digitalWrite(_pin3,0);
        digitalWrite(_pin4,1);
        _s1 = 3;
        delay(_time);
        return;
    }
    
    if (_s1 == 3) {
        
        digitalWrite(_pin1,0);
        digitalWrite(_pin2,1);
        digitalWrite(_pin3,0);
        digitalWrite(_pin4,1);
        _s1 = 4;
        delay(_time);
        return;
    }
    if (_s1 == 4) {
        
        digitalWrite(_pin1,0);
        digitalWrite(_pin2,1);
        digitalWrite(_pin3,1);
        digitalWrite(_pin4,0);
        
        _s1 = 1;
        delay(_time);
        return;
    }
    
        
}        
//-----------------------------------------_step1 left
    
    
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
 
        digitalWrite(_pin1,1);
        digitalWrite(_pin2,0);
        digitalWrite(_pin3,1);
        digitalWrite(_pin4,0);
        _s1 = 4;
        delay(_time);
        return;
        }
    if (_s1 == 2) {
        
        digitalWrite(_pin1,1);
        digitalWrite(_pin2,0);
        digitalWrite(_pin3,0);
        digitalWrite(_pin4,1);
        _s1 = 1;
        delay(_time);
        return;
        }
    if (_s1 == 3) {
        
        digitalWrite(_pin1,0);
        digitalWrite(_pin2,1);
        digitalWrite(_pin3,0);
        digitalWrite(_pin4,1);
        _s1 = 2;
        delay(_time);
        return;
        }
    if (_s1 == 4) {
        
        digitalWrite(_pin1,0);
        digitalWrite(_pin2,1);
        digitalWrite(_pin3,1);
        digitalWrite(_pin4,0);
        _s1 = 3; 
        delay(_time);
        return;
    }
}

}





