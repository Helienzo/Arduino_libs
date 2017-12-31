/*
  Button.h - Library for reading buttons on arduino
  Created by Lucas Wennerholm 2014-06-03
*/

#include "Arduino.h"
#include "Button.h"

Button::Button(int pin)
{
pinMode(pin, INPUT); // sets the pin conected to a physical buton to input
 _pin = pin;
 _turn = 1;
 _value = 0;
 _count = 0;
 _numb = 30;
 _Stime = 0;
 _Ctime = 0;
 _Etime = 0;
 _change = 0;
 }
//********************************Method rain***************************************
int Button::buttoncheck(int funks,int _accuracy) { // accuracy should be 10 times per seconds
 
  if (_Stime == 0) {
    _Stime = millis();
  }  
  
  _Ctime = millis();
  _Etime = _Ctime - _Stime;
  
  if (_Etime >= _accuracy) {
	  _Stime = millis();        
	  _value = digitalRead(_pin);
	  
	  if (_value == 1) {
		_count++;
		if (_count == _numb && _change == 0){
			_count = 0;
			_turn++;
			_change = 1;
			if (_turn == funks+1) {
				_turn = 1;
			}
		}
	  }
	  
	  if (_value == 0 && _count > 0) {
		_count = 0;
	  }
	  
	  if (_change == 1 && _value == 1) { // detta if statment gör att turn inte bytar om man inte släpper knappen.
	    _count = 0;
	  }
	  else {
	    _change = 0;
	  }
	  
   }
	  return _turn;
}

