/*
  GreenRain.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "GreenRain.h"

GreenRain::GreenRain(int pin1,int pin2,int pin3,int pin4)
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  _led1 = 3;          // the (PWM)pin that the LED is attached to
  _led2 = 5;          // the (PWM)pin that the LED is attached to
  _led3 = 6;          // the (PWM)pin that the LED is attached to
  _led4 = 9;          // the (PWM)pin that the LED is attached to  
  _tick1 = 85;        // how many points to fade the LED by
 
 }
//********************************Method rain***************************************
void GreenRain::rain(int _n,int _time) {
for (int _in=0; _in <= _n; _in++) {
 
  for (int _i=0; _i <= 3570; _i++) {
  _tick1 = _tick1 + 1;
  
  if (_tick1 == 1785) {
  _tick1 = 84;
  }
  
  // LED 1
  if (_tick1 >= 85 && _tick1 <= 255) {
   analogWrite(_led1,_tick1); 
  }
  if (_tick1 >= 255 && _tick1 <= 510) {
    
   analogWrite(_led1,510-_tick1); 
  }
  
  
  
      // LED 1 loop 2;
  if (_tick1 >= 1700 && _tick1 <= 1785) {
   analogWrite(_led1,_tick1-1700); 
  }




  // LED 2
  if (_tick1 >= 425 && _tick1 <= 680) {
    
   analogWrite(_led2,_tick1-170); 
  }
  if (_tick1 >= 680 && _tick1 <= 935) {
    
   analogWrite(_led2,935-_tick1); 
  }



  // LED 3
  if (_tick1 >= 850 && _tick1 <= 1105) {
    
   analogWrite(_led3,_tick1-850); 
  }
  if (_tick1 >= 1105 && _tick1 <= 1360) {
    
   analogWrite(_led3,1360-_tick1); 
  }
  
  

  // LED 4
  if (_tick1 >= 1275 && _tick1 <= 1530) {
    
   analogWrite(_led4,_tick1-1275); 
  }
  if (_tick1 >= 1530 && _tick1 <= 1785) {
    
   analogWrite(_led4,1529-_tick1); 
  } 
  
    
delayMicroseconds(_time);
}
}
}

//********************************Method backwardRain***************************************

void GreenRain::backwardRain(int _n,int _time) {
for (int _in=0; _in <= _n; _in++) {
for (int _i=0; _i <= 3570; _i++) {
 _tick1 = _tick1 + 1;
 
 if (_tick1 == 1785) {
  _tick1 = 84;
  }
  
  // LED 4
  if (_tick1 >= 85 && _tick1 <= 255) {
   analogWrite(_led4,_tick1); 
  }
  if (_tick1 >= 255 && _tick1 <= 510) {
    
   analogWrite(_led4,510-_tick1); 
  }
  
  
  
      // LED 4 loop 2;
  if (_tick1 >= 1700 && _tick1 <= 1785) {
   analogWrite(_led4,_tick1-1700); 
  }




  // LED 3
  if (_tick1 >= 425 && _tick1 <= 680) {
    
   analogWrite(_led3,_tick1-170); 
  }
  if (_tick1 >= 680 && _tick1 <= 935) {
    
   analogWrite(_led3,935-_tick1); 
  }



  // LED 2
  if (_tick1 >= 850 && _tick1 <= 1105) {
    
   analogWrite(_led2,_tick1-850); 
  }
  if (_tick1 >= 1105 && _tick1 <= 1360) {
    
   analogWrite(_led2,1360-_tick1); 
  }
  
  

  // LED 1
  if (_tick1 >= 1275 && _tick1 <= 1530) {
    
   analogWrite(_led1,_tick1-1275); 
  }
  if (_tick1 >= 1530 && _tick1 <= 1785) {
    
   analogWrite(_led1,1529-_tick1); 
  } 
  
    
delayMicroseconds(_time);
}
}
}
//********************************Method rainBaseUp***************************************
void GreenRain::rainBaseUp(int _n,int _time) {
// This method increases the base level over _n*3570 iterations.
int _baseLev = 1; 
int _tick2 = 0;
  for (int _i=0; _i <= 3570*_n; _i++) {
  _tick1 = _tick1 + 1;
  _tick2++;

  if (_tick2 == 14*_n) {
    _baseLev++;
    _tick2 = 0;
  }
  
  if (_tick1 == 1785) {
  _tick1 = 84;
  }
  
  // LED 1
  if (_tick1 >= 85 && _tick1 <= 255) {
  
   if (_tick1<=_baseLev) {
      analogWrite(_led1,_baseLev); 
   }
   else {
      analogWrite(_led1,_tick1); 
   }
  }
  if (_tick1 >= 255 && _tick1 <= 510) {
    
    if (510-_tick1 <= _baseLev) {
      analogWrite(_led1,_baseLev);
    }
    else {
      analogWrite(_led1,510-_tick1);
    }
    
  }
  
  
  
      // LED 1 loop 2; Fixa (Sen)
  if (_tick1 >= 1700 && _tick1 <= 1785) {
     if (_tick1-1700 <= _baseLev) {
       analogWrite(_led1,_baseLev); 
     }
     else {
       analogWrite(_led1,_tick1-1700); 
     }
  }

/*
   if (_tick1-170 <= _baseLev) {
  
  }
  else {
  
  }
*/
  // LED 2
  if (_tick1 >= 425 && _tick1 <= 680) {
   
   if (_tick1-170 <= _baseLev) {
     analogWrite(_led2,_baseLev); 
  }
  else {
     analogWrite(_led2,_tick1-170); 
  }
  }
  
  if (_tick1 >= 680 && _tick1 <= 935) {
      if (935-_tick1 <= _baseLev) {
         analogWrite(_led2,_baseLev); 
      }
      else {
         analogWrite(_led2,935-_tick1); 
      } 
  }



  // LED 3
  if (_tick1 >= 850 && _tick1 <= 1105) {
     if (_tick1-850 <= _baseLev) {
       analogWrite(_led3,_baseLev); 
  }
     else {
       analogWrite(_led3,_tick1-850); 
     }
  }
  
  if (_tick1 >= 1105 && _tick1 <= 1360) {
    if (1360-_tick1 <= _baseLev) {
     analogWrite(_led3,_baseLev); 
    }
    else {
       analogWrite(_led3,1360-_tick1); 
    } 
  }
  
  

  // LED 4
  if (_tick1 >= 1275 && _tick1 <= 1530) {
      if (_tick1-1275 <= _baseLev) {
        analogWrite(_led4,_baseLev); 
      }
      else {
        analogWrite(_led4,_tick1-1275); 
      } 
  }
  
  if (_tick1 >= 1530 && _tick1 <= 1785) {
      if (1529-_tick1 <= _baseLev) {
         analogWrite(_led4,_baseLev); 
      }
      else {
         analogWrite(_led4,1529-_tick1); 
      } 
   
  } 
  
    
delayMicroseconds(_time);
}
}

//********************************Method BaseDown***************************************
void GreenRain::rainBaseDown() {
}

//********************************Method greenPulseUp***************************************
void GreenRain::greenPulseUp(int _time) {
	for(int i = 0; i <= 255; i++) {
		analogWrite(_led1,i);
		analogWrite(_led2,i);
		analogWrite(_led3,i);
		analogWrite(_led4,i);
		delayMicroseconds(_time);
	}
}

//********************************Method greenPulseDown***************************************
void GreenRain::greenPulseDown(int _time) {
	for(int i = 0; i <= 255; i++) {
		analogWrite(_led1,255-i);
		analogWrite(_led2,255-i);
		analogWrite(_led3,255-i);
		analogWrite(_led4,255-i);
		delayMicroseconds(_time);
	}
}

//********************************Method firstSecond***************************************
void GreenRain::firstSecond() {
}

//********************************Method greenIdiot***************************************
void GreenRain::greenIdiot() {
rain(1,500);
backwardRain(1,500);
}

//********************************Method greenOff***************************************
void GreenRain::greenOff() {
analogWrite(_led1,0);
analogWrite(_led2,0);
analogWrite(_led3,0);
analogWrite(_led4,0);
}
//********************************Method greenOn***************************************
void GreenRain::greenOn() {
analogWrite(_led1,255);
analogWrite(_led2,255);
analogWrite(_led3,255);
analogWrite(_led4,255);
}
