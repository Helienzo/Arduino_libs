/*
  Button.h - Library for reading buttons on arduino
  Created by Lucas Wennerholm 2014-06-03
*/
#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int pin);
    int buttoncheck(int funks,int _accuracy);
    
  private:
    int _pin;
    int  _turn;
	int _value;
	int _count;
	int _numb;
	int _Stime;
	int _Ctime;
	int _Etime;
	int _change;
};

#endif