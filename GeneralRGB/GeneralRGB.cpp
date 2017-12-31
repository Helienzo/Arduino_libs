/*
  GreenRain.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "GeneralRGB.h"
#include "Pwm.h"
#include "Ticker.h"

Ticker tickerW;

    Pwm pin10(10);
    Pwm pin9(9);
    Pwm pin11(11);
    Pwm pin2(2);

GeneralRGB::GeneralRGB(int led1,int led2,int led3,int gnd1,int gnd2, int gnd3)
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(gnd1, OUTPUT);
  pinMode(gnd2, OUTPUT);
  pinMode(gnd3, OUTPUT);
  pinMode(2,OUTPUT);
  _R = 6;          // the (PWM)pin that the LED is attached to
  _G = 5;          // the (PWM)pin that the LED is attached to
  _B = 3;          // the (PWM)pin that the LED is attached to
  _gndClock = 0;
  _gndCount = 0;
  _gnd = 1;
  _gnd1 = 9;
  _gnd2 = 10;
  _gnd3 = 11;
  _tick1 = 0;        // how many points to fade the LED by
  _a = 0;
  _Etime;
  _Stime = 0;
  _Ctime;
  _tottime = 0;
  _pwmTick = 0;
  freq = 650;
  _wire = 1;
 }
 
  /////////////////////////////// GeneralRGB-reset ///////////////////////////////
 void GeneralRGB::reset() {
    _tick1 = 0;
    _Stime = 0;
    _gndClock = 0;
    _Etime = 0;
    _Ctime = 0;
    _tottime = 0;
 }
 
 /////////////////////////////// GeneralRGB-colorsweep ///////////////////////////////
 int GeneralRGB::colorsweep(int _time) {
 
   digitalWrite(_gnd3,HIGH);
   digitalWrite(_gnd2,HIGH);
   digitalWrite(_gnd1,HIGH);
   
    if (_tick1 == 1530) {
     _tick1 = 0;
     _Stime = 0;
     return 1;
    }
    
    if (_tick1 == 0 && _Stime == 0) {
      _Stime = micros();
    }
    _Ctime = micros();
    _Etime = _Ctime - _Stime;
    
    
  if (_Etime >= _time) {
    _Stime = micros();
    _tick1++;
    //Serial.println(_tick1); 
    
  if (_tick1 >= 0 && _tick1 <= 255) {
    analogWrite(_B,0);
    analogWrite(_R,255);
    analogWrite(_G,_tick1);
  }
  
  if (_tick1 >= 255 && _tick1 <= 510) {
   analogWrite(_G,255);
   analogWrite(_R,510-_tick1);
  }
  
  if (_tick1 >= 510 && _tick1 <= 765) {
   analogWrite(_R,0); 
   analogWrite(_G,255);
   analogWrite(_B,_tick1-510);
  }
  
   if (_tick1 >= 765 && _tick1 <= 1020) {
   analogWrite(_B,255);
   analogWrite(_G,1020-_tick1);
   }
   
   if (_tick1 >= 1020 && _tick1 <= 1275) {
    analogWrite(_G,0); 
    analogWrite(_B,255);
    analogWrite(_R,_tick1-1020);
   }  

   if (_tick1 >= 1275 && _tick1 <= 1530) {
    analogWrite(_G,0); 
    analogWrite(_R,255);
    analogWrite(_B,1530-_tick1);
   }   
   return 0;
}
}


///////////////////////////// GeneralRGB::onecolor ///////////////////

int GeneralRGB::onecolor(int _color, int _gnd, int _time) {
    
    if (_Stime == 0) {
      _Stime = millis();
      //Serial.println(char('g'));
    }
    
    _Ctime = millis();
    _Etime = _Ctime - _Stime;
    
    
   if (_Etime >= _time) {
      return 1;
     }
     
   
    if (_gnd == 1) {
   digitalWrite(_gnd3,LOW);
   digitalWrite(_gnd2,LOW);
   digitalWrite(_gnd1,HIGH);
   }
     if (_gnd == 2) {
   digitalWrite(_gnd3,LOW);
   digitalWrite(_gnd1,LOW);
   digitalWrite(_gnd2,HIGH);
   }
     if (_gnd == 3) {
   digitalWrite(_gnd2,LOW);
   digitalWrite(_gnd1,LOW);
   digitalWrite(_gnd3,HIGH);
   }
   if (_gnd == 4) {
   digitalWrite(_gnd3,HIGH);
   digitalWrite(_gnd2,HIGH);
   digitalWrite(_gnd1,HIGH);
   }
   if (_gnd > 5) { 
     analogWrite(_gnd3,_gnd-5);
     analogWrite(_gnd2,_gnd-5);
     analogWrite(_gnd1,_gnd-5);
   }

  _tick1 = _color;
  
  if (_tick1 >= 0 && _tick1 <= 255) {
    analogWrite(_B,0);
    analogWrite(_R,255);
    analogWrite(_G,_tick1);
  }
  
  if (_tick1 >= 255 && _tick1 <= 510) {
   analogWrite(_G,255);
   analogWrite(_R,510-_tick1);
  }
  
  if (_tick1 >= 510 && _tick1 <= 765) {
   analogWrite(_R,0); 
   analogWrite(_G,255);
   analogWrite(_B,_tick1-510);
  }
  
   if (_tick1 >= 765 && _tick1 <= 1020) {
   analogWrite(_B,255);
   analogWrite(_G,1020-_tick1);
   }
   
   if (_tick1 >= 1020 && _tick1 <= 1275) {
    analogWrite(_G,0); 
    analogWrite(_B,255);
    analogWrite(_R,_tick1-1020);
   }  

   if (_tick1 >= 1275 && _tick1 <= 1530) {
    analogWrite(_G,0); 
    analogWrite(_R,255);
    analogWrite(_B,1530-_tick1);
   } 
   
   return 0;
}
  int GeneralRGB::colorsweepgnd(int _gnd, int _time) {
     if (_gnd == 1 ) {
   digitalWrite(_gnd3,LOW);
   digitalWrite(_gnd2,LOW);
   digitalWrite(_gnd1,HIGH);
   }
     if (_gnd == 2) {
   digitalWrite(_gnd3,LOW);
   digitalWrite(_gnd1,LOW);
   digitalWrite(_gnd2,HIGH);
   }
     if (_gnd == 3) {
   digitalWrite(_gnd2,LOW);
   digitalWrite(_gnd1,LOW);
   digitalWrite(_gnd3,HIGH);
   }
   
     if (_gnd == 4) {
   digitalWrite(_gnd3,HIGH);
   digitalWrite(_gnd2,HIGH);
   digitalWrite(_gnd1,HIGH);
   }
   
        if (_gnd == 5) {

   }
      
    if (_tick1 == 1530) {
     _tick1 = 0;
     _Stime = 0;
     return 1;
    }
    
    if (_tick1 == 0 && _Stime == 0) {
      _Stime = millis();
    }
    _Ctime = millis();
    _Etime = _Ctime - _Stime;
    
    
  if (_Etime >= _time) {
    _Stime = millis();
    _tick1++;
    //Serial.println(_tick1); 
    
  if (_tick1 >= 0 && _tick1 <= 255) {
    analogWrite(_B,0);
    analogWrite(_R,255);
    analogWrite(_G,_tick1);
  }
  
  if (_tick1 >= 255 && _tick1 <= 510) {
   analogWrite(_G,255);
   analogWrite(_R,510-_tick1);
  }
  
  if (_tick1 >= 510 && _tick1 <= 765) {
   analogWrite(_R,0); 
   analogWrite(_G,255);
   analogWrite(_B,_tick1-510);
  }
  
   if (_tick1 >= 765 && _tick1 <= 1020) {
   analogWrite(_B,255);
   analogWrite(_G,1020-_tick1);
   }
   
   if (_tick1 >= 1020 && _tick1 <= 1275) {
    analogWrite(_G,0); 
    analogWrite(_B,255);
    analogWrite(_R,_tick1-1020);
   }  

   if (_tick1 >= 1275 && _tick1 <= 1530) {
    analogWrite(_G,0); 
    analogWrite(_R,255);
    analogWrite(_B,1530-_tick1);
   }   
   return 0;
}
   
   }
        
////////////////////////////// white ////////////////////////    
    
    int GeneralRGB::white(int _gnd, int _time) {
    
    if (_Stime == 0) {
      _Stime = millis();
      //Serial.println(char('w'));
    }
    
    _Ctime = millis();
    _Etime = _Ctime - _Stime;
    
   if (_Etime >= _time) {
      return 1;
     }
      
      if (_gnd == 1) {
   digitalWrite(_gnd3,LOW);
   digitalWrite(_gnd2,LOW);
   digitalWrite(_gnd1,HIGH);
   }
     if (_gnd == 2) {
   digitalWrite(_gnd3,LOW);
   digitalWrite(_gnd1,LOW);
   digitalWrite(_gnd2,HIGH);
   }
     if (_gnd == 3) {
   digitalWrite(_gnd2,LOW);
   digitalWrite(_gnd1,LOW);
   digitalWrite(_gnd3,HIGH);
   }
   
     if (_gnd == 4) {
   digitalWrite(_gnd3,HIGH);
   digitalWrite(_gnd2,HIGH);
   digitalWrite(_gnd1,HIGH);
   }
      
      analogWrite(_R,255); //110
      analogWrite(_G,255);
      analogWrite(_B,255);
    
    return 0;
    
}

/////////////////////////////// rgbwalk/////////////////////////////
    int GeneralRGB::rgbwalk(int _n,int _time) {
    
    if (_tick1 == 0 && _Stime == 0) {
      _Stime = micros();
    }
    _Ctime = micros();
    _Etime = _Ctime - _Stime;
   
   
   
   if (_gnd == 1 ) {
	pin9.pwm(freq,_pwmTick);
	pin10.pwm(freq,0);
	pin11.pwm(freq,0);
	////Serial.println(_pwmTick);
   }
     if (_gnd == 2) {
	pin9.pwm(freq,255-_pwmTick);
	pin10.pwm(freq,0);
	pin11.pwm(freq,0);
   }
     if (_gnd == 3) {
	pin9.pwm(freq,0);
	pin10.pwm(freq,_pwmTick);
	pin11.pwm(freq,0);
   }
   
     if (_gnd == 4) {
	pin9.pwm(freq,0);
	pin10.pwm(freq,255-_pwmTick);
	pin11.pwm(freq,0);
   }
   
   if (_gnd == 5) {
	pin9.pwm(freq,0);
	pin10.pwm(freq,0);
	pin11.pwm(freq,_pwmTick);
   }
   
   if (_gnd == 6) {
	pin9.pwm(freq,0);
	pin10.pwm(freq,0);
	pin11.pwm(freq,255-_pwmTick);
   }
   
   
  if (_tick1 == 1530) {
      _gndClock++;
      _gnd++;
      if (_gnd == 7) {
       _gnd = 1;
      }
      _tick1 = 0;
      _Stime = 0;
      _pwmTick = 0;
  }
  
  if (_gndClock == _n){
     _gnd = 1;
     _gndClock = 0;
     return 1;
  }

if (_Etime >= _time) {
    _Stime = millis();
    _tick1++;
    _gndCount++;
    if (_gndCount == 6) {
      _pwmTick++;
      _gndCount = 0;
    }
    ////Serial.println(_pwmTick);
    
    
  if (_tick1 >= 0 && _tick1 <= 255) {
    analogWrite(_B,0);
    analogWrite(_R,255);
    analogWrite(_G,_tick1);
  }
  
  if (_tick1 >= 255 && _tick1 <= 510) {
   analogWrite(_G,255);
   analogWrite(_R,510-_tick1);
  }
  
  if (_tick1 >= 510 && _tick1 <= 765) {
   analogWrite(_R,0); 
   analogWrite(_G,255);
   analogWrite(_B,_tick1-510);
  }
  
   if (_tick1 >= 765 && _tick1 <= 1020) {
   analogWrite(_B,255);
   analogWrite(_G,1020-_tick1);
   }
   
   if (_tick1 >= 1020 && _tick1 <= 1275) {
    analogWrite(_G,0); 
    analogWrite(_B,255);
    analogWrite(_R,_tick1-1020);
   }  

   if (_tick1 >= 1275 && _tick1 <= 1530) {
    analogWrite(_G,0); 
    analogWrite(_R,255);
    analogWrite(_B,1530-_tick1);
   }   
   return 0;
}

 
    }
       
  void GeneralRGB::fire(int _n,int _time, int _gnd) { 
  
  for (int _nn=0; _nn <= _n; _nn++) {
  for (int _in=0; _in <= 720; _in++) {
    if (_gnd == 1 ) {
   digitalWrite(_gnd3,LOW);
   digitalWrite(_gnd2,LOW);
   digitalWrite(_gnd1,HIGH);
   }
     if (_gnd == 2) {
   digitalWrite(_gnd3,LOW);
   digitalWrite(_gnd1,LOW);
   digitalWrite(_gnd2,HIGH);
   }
     if (_gnd == 3) {
   digitalWrite(_gnd2,LOW);
   digitalWrite(_gnd1,LOW);
   digitalWrite(_gnd3,HIGH);
   }
   
     if (_gnd == 4) {
   digitalWrite(_gnd3,HIGH);
   digitalWrite(_gnd2,HIGH);
   digitalWrite(_gnd1,HIGH);
   }
  
      if (_a == 0) {
    if (_tick1 == 720) {
      _a = 0;
      _gnd++;
      if (_gnd == 5) {
       _gnd = 4;
      }
  _tick1 = 0;
  }

  _tick1++;
  
    if (_tick1 >= 0 && _tick1 <= 255) {
    analogWrite(_B,0);
    analogWrite(_R,255);
    analogWrite(_G,_tick1);
    }
  
   if (_tick1 >= 255 && _tick1 <= 360) {
   analogWrite(_G,255);
   analogWrite(_R,510-_tick1);
   }
   
   if (_tick1 >= 360 && _tick1 <= 465) {
    analogWrite(_B,0);
    analogWrite(_G,255);
    analogWrite(_R,_tick1-210);
    }
    
    if (_tick1 >= 465 && _tick1 <= 720) {
    analogWrite(_B,0);
    analogWrite(_R,255);
    analogWrite(_G,720-_tick1);
    }
   
   
   delayMicroseconds(_time);
  
  }
  }
  }
  }
 /////////////////////////////// strobe /////////////////////////////   
 int GeneralRGB::strobe(int _period, int _n) {
 
    if (_Stime == 0) {
      _Stime = millis();
      //Serial.println(char('s'));
    }
    
    _Ctime = millis();
    _Etime = _Ctime - _Stime;
    
   if (_tottime >= _period*_n ) {
      return 1;
   }
   
   digitalWrite(_gnd3,HIGH);
   digitalWrite(_gnd2,HIGH);
   digitalWrite(_gnd1,HIGH);
   
   if (_Etime >= _period/2 && _tick1 == 1) {
       _tottime = _tottime + _Etime;
       _Etime = 0;
       _Stime = millis();
	   analogWrite(_R,255); //110
	   analogWrite(_G,255);
	   analogWrite(_B,255);
	   digitalWrite(2,HIGH);
	   _tick1 = 0;
	   //Serial.println(1);
	   //Serial.println();
   } 
   
      if (_Etime >= _period/2 && _tick1 == 0) {
       _tottime = _tottime + _Etime;
       _Stime = millis();
       _Etime = 0;
	   analogWrite(_R,0); //110
	   analogWrite(_G,0);
	   analogWrite(_B,0);
	   digitalWrite(2,LOW);
	   _tick1 = 1;
	   //Serial.println(0);
	   //Serial.println();
   }
   
   return 0;
 
 }
 
  /////////////////////////////// wirelight /////////////////////////////   
 
 
 
 void GeneralRGB::wirelight(int on,int beat) {
 // if on is set to 2 the beatfunction will work
 	if (on == 1) {
 		digitalWrite(2,HIGH);
    }
     	if (on == 0) {
 		digitalWrite(2,LOW);
    }
    
    if (on == 2 && beat == 1 && _wire == 1) {
    	 	digitalWrite(2,HIGH);
    	 	_wire = 0; 
    	 	Serial.println(1);
    	 	return;
    }
    
    if (on == 2 && beat == 1 && _wire == 0) {
    	 	digitalWrite(2,LOW);
    	 	_wire = 1;
    	 	Serial.println(0);
    	 	return;
    }
 }