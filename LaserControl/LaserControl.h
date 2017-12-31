/*
  LaserControl.h - Library for controlling laser
  Created by Lucas Wennerholm 2014-02-20
*/
#ifndef LaserControl_h
#define LaserControl_h

#include "Arduino.h"

class LaserControl
{
  public:
    LaserControl();
    void step(int _step1, int _step2);
    int _s1;
    int _s2;
    int _ns1;
    int _ns2;
  private:

};

#endif