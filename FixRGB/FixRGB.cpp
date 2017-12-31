/*
  GreenRain.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "FixRGB.h"

FixRGB::FixRGB(int led1,int led2,int led3,int gnd1,int gnd2, int gnd3)
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(gnd1, OUTPUT);
  pinMode(gnd2, OUTPUT);
  pinMode(gnd3, OUTPUT);
  _R = 6;          // the (PWM)pin that the LED is attached to
  _G = 5;          // the (PWM)pin that the LED is attached to
  _B = 3;          // the (PWM)pin that the LED is attached to
  _gnd;
  _gnd1 = 9;
  _gnd2 = 10;
  _gnd3 = 11;
  _tick1 = 0;        // how many points to fade the LED by
  _a = 0;
 }
 /////////////////////////////// FixRGB-colorsweep ///////////////////////////////
 void FixRGB::colorsweep(int _n,int _time) {
 for (int _nn=0; _nn <= _n; _nn++) {
 for (int _in = 0; _in <= 1530; _in++) {    
     
   digitalWrite(_gnd3,HIGH);
   digitalWrite(_gnd2,HIGH);
   digitalWrite(_gnd1,HIGH);
   
   if (_a == 0) {
    if (_tick1 == 1530) {
      _a = 0;
  _tick1 = 0;
  }

  _tick1++;
  
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
   delayMicroseconds(_time);
}
} 
} 
}

///////////////////////////// FixRGB::onecolor ///////////////////

void FixRGB::onecolor(int _color, int _gnd) {

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
}

    void FixRGB::colorsweepgnd(int _n,int _time, int _gnd) {
 
  for (int _nn=0; _nn <= _n; _nn++) {
  for (int _in = 0; _in <= 1530; _in++) {
   
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
    if (_tick1 == 1530) {
      _a = 0;
  _tick1 = 0;
  }

  _tick1++;
  
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
   delayMicroseconds(_time);
}
  
} 
}  
    }
    
    
    
////////////////////////////// white ////////////////////////    
    
    void FixRGB::white(int _gnd) {
      
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
    
    }

/////////////////////////////// rgbwalk/////////////////////////////
    void FixRGB::rgbwalk(int _n,int _time) {
      for (int _nn=0; _nn <= _n; _nn++) {
      for (int _in = 0; _in <= 1530; _in++) {
   
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
    if (_tick1 == 1530) {
      _a = 0;
      _gnd++;
      if (_gnd == 4) {
       _gnd = 1;
      }
  _tick1 = 0;
  }

  _tick1++;
  
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
   delayMicroseconds(_time);
}
  
} 
 } 
    }
    
     void FixRGB::rgbwalkall(int _n,int _time) {
      for (int _nn=0; _nn <= _n; _nn++) {
      for (int _in = 0; _in <= 1530; _in++) {
   
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
    if (_tick1 == 1530) {
      _a = 0;
      _gnd++;
      if (_gnd == 5) {
       _gnd = 1;
      }
  _tick1 = 0;
  }

  _tick1++;
  
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
   delayMicroseconds(_time);
}
  
} 
}
}
    
  void FixRGB::fire(int _n,int _time, int _gnd) { 
  
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
    
 