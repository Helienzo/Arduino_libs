/*
  GreenRain.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "LaserControl.h"

LaserControl::LaserControl()
{
pinMode(3, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);

pinMode(2, OUTPUT);
pinMode(4, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);


pinMode(5,OUTPUT); // pin 5 goes to green laser
pinMode(9,OUTPUT); // pin nine goes to the laser mirror

_s1 = 1;
_s2 = 1;
_ns1 = 0;
_ns2 = 0;
 
 }
//********************************Method rain***************************************
void LaserControl::step(int _step1, int _step2) {

// function [_s1,_s2,_ns1,_ns2] = step(ans,_step1,_step2,_s1,_s2,_ns1,_ns2)
int val;
int _time = 20;

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
 
        digitalWrite(3,1);
        digitalWrite(10,0);
        digitalWrite(11,1);
        digitalWrite(12,0);
        _s1 = 2;
        }
    if (_s1 == 2) {
        digitalWrite(3,0);
        digitalWrite(10,1);
        digitalWrite(11,1);
        digitalWrite(12,0);
        _s1 = 3;
    }
    
    if (_s1 == 3) {
        
        digitalWrite(3,0);
        digitalWrite(10,1);
        digitalWrite(11,0);
        digitalWrite(12,1);
        _s1 = 4;
    }
    
    if (_s1 == 4) {
        
        digitalWrite(3,1);
        digitalWrite(10,0);
        digitalWrite(11,0);
        digitalWrite(12,1);
        
        _s1 = 1; 
    }
    
        delay(_time);
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
 
        digitalWrite(3,1);
        digitalWrite(10,0);
        digitalWrite(11,1);
        digitalWrite(12,0);
        _s1 = 4;
        }
    if (_s1 == 2) {
        
        digitalWrite(3,0);
        digitalWrite(10,1);
        digitalWrite(11,1);
        digitalWrite(12,0);
        _s1 = 1;
        }
    if (_s1 == 3) {
        
        digitalWrite(3,0);
        digitalWrite(10,1);
        digitalWrite(11,0);
        digitalWrite(12,1);
        _s1 = 2;
        }
    if (_s1 == 4) {
        
        digitalWrite(3,1);
        digitalWrite(10,0);
        digitalWrite(11,0);
        digitalWrite(12,1);
        _s1 = 3; 

    }
        delay(_time);
}
//-----------------------------------------_step2 down
if (_step2 == 0) {
    val = 0;
}
if (_step2 == 1) {
    val = 4;
    }
if (_step2 == -1) {
    val = 3;    
}
    
if (_ns2 == 0) {
        //this if loop runs on first loop val is 3 or 4
        _ns2 = val;  
} 
    
 if (val == 3) {
     
     if (_ns2 == 4) {
         
         if (_s2 == 1) {
         _s2 = 3;
         }
         if (_s2 == 2) {
         _s2 = 4;   
         }
         if (_s2 == 3) {
         _s2 = 1; 
         }
         if (_s2 == 4) {
         _s2= 2;  
         }
      _ns2 = val;   
    }
  
     if (_s2 == 1) {
     digitalWrite(4,0);
     digitalWrite(8,0);
     digitalWrite(2,1);
     digitalWrite(7,0); 
     _s2 = 2;
     }
     if (_s2 == 2) {
     digitalWrite(2,0);
     digitalWrite(7,0);
     digitalWrite(4,1);
     digitalWrite(8,0);
     _s2 = 3;
     }
     if (_s2 == 3) {
     digitalWrite(4,0);
     digitalWrite(7,0);
     digitalWrite(2,1);
     digitalWrite(8,0);
     _s2 = 4;
     }
     if (_s2 == 4) {
      
     digitalWrite(2,0);
     digitalWrite(8,0);
     digitalWrite(4,1);
     digitalWrite(7,0);
     _s2 = 1;
     }
     delay(_time);
 
     digitalWrite(2,0);
     digitalWrite(7,0);
     digitalWrite(4,0);
     digitalWrite(8,0);
 
 }
 //-----------------------------------------_step2 up
 
 if (val == 4) {
     
     if (_ns2 == 3) {
         
         if (_s2 == 1) {
         _s2 = 3;
         }
         if (_s2 == 2) {
         _s2 = 4;
         }
         if (_s2 == 3) {
         _s2 = 1;   
         }
         if (_s2 == 4) {
         _s2= 2;  
         }
      _ns2 = val;   
    }
     
     if (_s2 == 1) {
         
     digitalWrite(4,0);
     digitalWrite(8,0);
     digitalWrite(2,0);
     digitalWrite(7,1); 
     _s2 = 4;
     }
     if (_s2 == 2) {
         
     digitalWrite(2,0);
     digitalWrite(7,0);
     digitalWrite(4,0);
     digitalWrite(8,1);
     _s2 = 1;
     }
     if (_s2 == 3) {
         
     digitalWrite(4,0);
     digitalWrite(8,0);
     digitalWrite(2,0);
     digitalWrite(7,1);
     _s2 = 2;
     }
     if (_s2 == 4) {
      
     digitalWrite(2,0);
     digitalWrite(7,0);
     digitalWrite(4,0);
     digitalWrite(8,1);
     _s2 = 3;
     }
     delay(_time);
     digitalWrite(2,0);
     digitalWrite(4,0);
     digitalWrite(7,0);
     digitalWrite(8,0);
    
 }


}





