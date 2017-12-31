/*
  GreenRain.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "StepperControl.h"
#include "Laser.h"
#include "Ticker.h"

Laser::Laser() {
}

Laser::Laser(StepperControl step1, StepperControl step2) {
    _step1 = step1;
    _step2 = step2;
    _length = 0;
    /* square
    patern1_1 = {-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 1, 1};
    patern1_2 = {-1,-1, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1};
    //sagtand + square
    patern2_1 = { 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1};
    patern2_2 = { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1, 1, 1, 1,-1,-1,-1, 1, 1, 1,-1,-1,-1, 1, 1, 1,-1,-1,-1, 1, 1, 1,-1,-1,-1, 1, 1, 1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0};
    // konsum              
    patern3_1 = {-1,-1,-1,-1,-1,-1,-1,-1,-1,   -1,-1,-1,    0, 0,-1, 0, 0,-1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,     1, 1, 1,     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1,     0, 0, 1, 0, 0, 1, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0,   -1,-1,-1,   -1,-1,-1,-1,-1,-1,-1,-1,-1 };
    patern3_2 = { 1, 0, 0, 1, 0, 0, 1, 0, 0,    0, 0, 0,   -1, 0, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0,-1,     0, 0, 0,     1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,    0, 0, 0,    -1, 0, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0,-1,    0, 0, 0,    1, 0, 0, 1, 0, 0, 1, 0, 0 };
    */
 }
 //********************************Method pattern***************************************
void Laser::attach(StepperControl step1, StepperControl step2) {
    _step1 = step1;
    _step2 = step2;
}
 
//********************************Method pattern***************************************
int Laser::pattern(int _pattern, long _time) {
    int _numb = 0;
    if(_pattern == 1) {
      _numb = _step1.stepRet(patern1_1[_length],_time);
      _numb = _step2.stepRet(patern1_2[_length],_time);
      if (_numb != 0) {
        _length++;
        Serial.println(_step1.get());
      }
      if(_length > 68) {
         _length = 0;
         return 1;
      }
    }
    if(_pattern == 2) {
      _numb = _step1.stepRet(patern2_1[_length],_time);
      _numb = _step2.stepRet(patern2_2[_length],_time);
      if (_numb != 0) {
        _length++;
        Serial.println(_step1.get());
      }
      if(_length > 86) {
         _length = 0;
         return 1;
      }
    }
    return 0;

}