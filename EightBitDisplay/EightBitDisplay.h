/*
  EightBitDisplay - Library for controling 8 bit display with four digits
  Created by Lucas Wennerholm 2014-05-08
*/

#ifndef EightBitDisplay_h
#define EightBitDisplay_h

#include "Arduino.h"
#include "Ticker.h"




class EightBitDisplay
{
  public:
    EightBitDisplay(int d1, int d2, int d3, int d4, int dot, int a, int b, int c, int d, int e, int f, int g);
    void writeDisplay(int _time); // writes digits to display
    void  setDigit(int digit1, int digit2, int digit3, int digit4);  // sets digits
    void defineSymbols(int _symbol); // defines symbols
    void setArray(int array1[],int array2[]);
    void setDot(int dot1, int dot2, int dot3, int dot4); // sets dots

  private:

 
 /* Bara för att komma ihåg hur man gör.
  int _value[12];
  int _tick1;
  int _strobeState;
  int _colorChange;
  Ticker tickerColorSweep;
  Ticker tickerColorSweepLR;
  Ticker tickerStrobe;
  */
  Ticker tickerWrite;
  int writeIndex;
  int _digit[8];
  int _digit1[8];
  int _digit2[8];
  int _digit3[8];
  int _digit4[8];
  int _pins[8];
  
  int _d1;
  int _d2;
  int _d3;
  int _d4;
  
  int _dot;
  int _a;
  int _b;
  int _c;
  int _d;
  int _e;
  int _f;
  int _g;
  

  
  int _none[7];// symbol -1
  int _minus[7]; // symbol -2
  
  int _zero[7]; // symbol 0
  int _one[7]; // symbol 1
  int _two[7]; // symbol 2
  int _three[7]; // symbol 3
  int _four[7]; // symbol 4
  int _five[7]; // symbol 5
  int _six[7]; // symbol 6
  int _seven[7]; // symbol 7
  int _eight[7]; // symbol 8
  int _nine[7]; // symbol 9
  
  int _cirkle[7];

/*  int _a[7]; // symbol 10
  int _b[7]; // symbol 11
  int _c[7]; // symbol 12
  int _d[7]; // symbol 13
  int _e[7]; // symbol 14
  int _f[7]; // symbol 15
  int _g[7]; // symbol 16
  int _h[7]; // symbol 17
  int _i[7]; // symbol 18
  int _j[7]; // symbol 19
  int _k[7]; // symbol 20
  int _l[7];  // symbol 21
  int _m[7]; // symbol 22
  int _n[7]; // symbol 23
  int _o[7]; // symbol 24
  int _p[7]; // symbol 25
  int _q[7]; // symbol 26
  int _r[7]; // symbol 27
  int _s[7]; // symbol 28
  int _t[7]; // symbol 29
  int _u[7]; // symbol 30
  int _v[7]; // symbol 31
  int _x[7]; // symbol 32
  int _y[7]; // symbol 33
  int _z[7]; // symbol 34
*/
};

#endif