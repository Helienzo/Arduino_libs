/*
  GreenRain.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "AsciiToVal.h"

AsciiToVal::AsciiToVal()
{

 
 }
//***********************************************************************
int AsciiToVal::aToV(int intIn) {
    if (intIn == 49 ) {
          return 1;
    }
        if (intIn == 50 ) {
          return 2;
    }
        if (intIn == 51 ) {
          return 3;
    }
        if (intIn == 52 ) {
          return 4;
    }
        if (intIn == 53 ) {
          return 5;
    }
        if (intIn == 54 ) {
          return 6;
    }
        if (intIn == 55 ) {
          return 7;
    }
        if (intIn == 56 ) {
          return 8;
    }
        if (intIn == 57 ) {
          return 9;
    }
        if (intIn == 48 ) {
      return 0;
    }
}





