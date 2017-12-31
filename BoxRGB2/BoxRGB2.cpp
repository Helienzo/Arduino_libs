/*
  BoxRGB2.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
//[11, 12, 13] LED strip 1
//[10, 9, 8] LED strip 2
//[7, 6, 5] LED strip 3
//[4, 3, 2] LED strip 4
*/
#include "Arduino.h"
#include "BoxRGB2.h"
#include "Ticker.h"
#include "LjudAnalys.h"

BoxRGB2::BoxRGB2()
{ 
//LED strip 1
   _R1 = 13;
   _G1 = 12;
   _B1 = 11;
//LED strip 2   
   _R2 = 10;
   _G2 = 9; 
   _B2 = 8;
//LED strip 3  
   _R3 = 7;
   _G3 = 6;
   _B3 = 5;
//LED strip 4   
   _R4 = 4;
   _G4 = 3;
   _B4 = 2;
   
//LED strip 1
  pinMode(_R1, OUTPUT);
  pinMode(_G1, OUTPUT);
  pinMode(_B1, OUTPUT);
//LED strip 2  
  pinMode(_R2, OUTPUT);
  pinMode(_G2, OUTPUT);
  pinMode(_B2, OUTPUT);
//LED strip 3  
  pinMode(_R3, OUTPUT);
  pinMode(_G3, OUTPUT);
  pinMode(_B3, OUTPUT);
//LED strip 4  
  pinMode(_R4, OUTPUT);
  pinMode(_G4, OUTPUT);
  pinMode(_B4, OUTPUT);

 _tick1 = 0;
 _strobeState = 0;
 LjudAnalys sound(2);
  
  


 }
 /////////////////////////////// BoxRGB2-colorsweep ///////////////////////////////
void BoxRGB2::initialValue() {
	_value[0] = 25; //R1
	_value[1] = 25; //G1
	_value[2] = 25; //B1
	
	_value[3] = 25; //R2
	_value[4] = 25; //G2
	_value[5] = 25; //B2
	
	_value[6] = 25; //R3
	_value[7] = 25; //G3
	_value[8] = 25; //B3
	
	_value[9] = 25;  //R4
	_value[10] = 25; //G4
	_value[11] = 25; //B4

}
void BoxRGB2::colorDEF() {
	white[0]  = 255;
	white[1]  = 255;
	white[2]  = 255;
	
	black[0]  = 0;
	black[1]  = 0;
	black[2]  = 0;
	
	red[0]    = 255;
	red[1]    = 0; 
	red[2]    = 0;
	
	green[0]  = 0;
	green[1]  = 255;
	green[2]  = 0;
	
	blue[0]   = 0;
	blue[1]   = 0; 
	blue[2]   = 255;
	
	purple[0] = 255;
	purple[1] = 0;
	purple[2] = 255;
	
	turkos[0] = 0;
	turkos[1] = 255;
	turkos[2] = 255;
	
	yellow[0] = 255;
	yellow[1] = 255;
	yellow[2] = 0;
	
	pink[0]   = 255;
	pink[1]   = 20; 
	pink[2]   = 100;
}
void BoxRGB2::setColor(int _color[],int _strip) {
  int _R = 0;
  int _G = 0;
  int _B = 0;
  if (_strip == 1 || _strip == 0) {
  	 _R = 0;
  	 _G = 1;
  	 _B = 2;
  }
  if (_strip == 2) {
  	 _R = 3;
  	 _G = 4;
  	 _B = 5;
  }
  if (_strip == 3) {
  	 _R = 6;
  	 _G = 7;
  	 _B = 8;
  }
  if (_strip == 4) {
  	 _R = 9;
  	 _G = 10;
  	 _B = 11;
  }
  _value[_R] = _color[0];
  _value[_G] = _color[1];
  _value[_B] = _color[2];
  if (_strip == 0) {
	allFollow1();
  }
  

}
void BoxRGB2::allFollow1() {

	_value[3] =_value[0];
	_value[4] =_value[1];
	_value[5] =_value[2];
	
	_value[6] = _value[0];
	_value[7] = _value[1];
	_value[8] = _value[2];
	
	_value[9] = _value[0];
	_value[10] =_value[1];
	_value[11] =_value[2];
	
}

int BoxRGB2::colorSweep(int _time,int _strip) {   // Function that goes trough all colors

   int eTime = tickerColorSweep.tickMicros(_time); // time in microseconds
    if (_tick1 == 1530) {
     _tick1 = 0;
     return 1;
    }
        
  if (eTime == 1) {
    _tick1++;
   oneColor(_tick1,_strip);
   return 0;
}
}

int BoxRGB2::colorSweepLR(int _time, int _dist) { // Function that uses all 4 strips
	int eTime = tickerColorSweepLR.tickMicros(_time); // time in microseconds
    if (_tick1 == 1530) {
     _tick1 = 0;
     return 1;
    }
	if (eTime == 1) {
	   
	  int _tick2 = _tick1;
	  int _tick3 = _tick1 + _dist;
	  int _tick4 = _tick1 + 2*_dist;
	  int _tick5 = _tick1 + 3*_dist;
	  _tick1++;

	 if (_tick3 > 1530) {
	   _tick3 = _tick3 -1530;
	 }
	 if (_tick4 > 1530) {
	   _tick4 = _tick4 -1530;
	 }
	 if (_tick5 > 1530) {
	   _tick5 = _tick5 -1530;
	 }
	  
	  
	  oneColor(_tick2,1);
	  oneColor(_tick3,2);
	  oneColor(_tick4,3);
	  oneColor(_tick5,4);
	  printValue(_value);
	}
	return 0;
}

int BoxRGB2::oneColor(int _tick,int _strip) {     // Function that sets all strips to one color. If _tick1 = -1 the collor is black
// denna funktion måste efterföljas av en printValue();
  int _R = 0;
  int _G = 0;
  int _B = 0;
  
  if (_strip == 1 || _strip == 0) {
  	 _R = 0;
  	 _G = 1;
  	 _B = 2;
  }
  if (_strip == 2) {
  	 _R = 3;
  	 _G = 4;
  	 _B = 5;
  }
  if (_strip == 3) {
  	 _R = 6;
  	 _G = 7;
  	 _B = 8;
  }
  if (_strip == 4) {
  	 _R = 9;
  	 _G = 10;
  	 _B = 11;
  }
  

  if (_tick >= 0 && _tick <= 255) {
    _value[_B] = 0;
    _value[_R] = 255;
    _value[_G] = _tick;
  }
  
  if (_tick >= 255 && _tick <= 510) {
   _value[_G] = 255;
   _value[_R] = 510-_tick;
  }
  
  if (_tick >= 510 && _tick <= 765) {
   _value[_R] = 0; 
   _value[_G] = 255;
   _value[_B] = _tick-510;
  }
  
   if (_tick >= 765 && _tick <= 1020) {
   _value[_B] = 255;
   _value[_G] = 1020-_tick;
   }
   
   if (_tick >= 1020 && _tick <= 1275) {
    _value[_G] = 0; 
    _value[_B] = 255;
    _value[_R] = _tick-1020;
   }  

   if (_tick >= 1275 && _tick <= 1530) {
    _value[_G] = 0; 
    _value[_R] = 255;
    _value[_B] = 1530-_tick;
   }
   
   if (_tick == -1) {
   		setColor(black,_strip);
   }
  if (_strip == 0) {
	allFollow1();
  }   
  return 0;
}

int BoxRGB2::strobe() {       // Function that strobes all strips
	int _state = tickerStrobe.onOffTick(50000, 50000);
	
	if (_state == 1) {
		_value[0] = 255; //R1
		_value[1] = 255; //G1
		_value[2] = 255; //B1
	}
	
	if (_state == 0) {
		_value[0] = 0; //R1
		_value[1] = 0; //G1
		_value[2] = 0; //B1
	}
	
	if (_strobeState != _state) {
		allFollow1();
		printValue(_value);
		_strobeState = _state;
	}
	
	
	
	return 0;
}
int BoxRGB2::musicFade(int _val,int _color,int _strip) {    // function that fades one color with music
 Serial.println(_val);
musicColorDamper(_color,_val,_strip);
allFollow1();
	return 0;
}

int BoxRGB2::musicColorChange(int _beat,int _strip,int _print) { // Function that changes the color with music
	
	if (_colorChange == 1) {
		setColor(white,_strip);
	}
	if (_colorChange == 2) {
		setColor(green,_strip);
	}
	if (_colorChange == 3) {
		setColor(blue,_strip);
	}
	if (_colorChange == 4) {
		setColor(turkos,_strip);
	}
	if (_colorChange == 5) {
		setColor(pink,_strip);
	}
	if (_colorChange == 6) {
		setColor(red,_strip);
	}
	if (_colorChange == 7) {
		setColor(yellow,_strip);
	}
	if (_colorChange == 8) {
		setColor(purple,_strip);
	}
	if (_beat == 1) {		
		_colorChange++;
		if (_colorChange == 9) {
			_colorChange = 1;
		}
		if (_print == 1) {
		allFollow1();
		printValue(_value);
		}
		
	}
	return 0;
}
int BoxRGB2::musicFadeColorchange(int _volume,int _beat,int _strip) { // Function that both change and fade color to music
	
	musicColorChange(_beat,_strip,0);
	musicColorDamper(-1,_volume,_strip);
	
	return 0;
}
int BoxRGB2::musicFadeColorChangeLR() { // Function that both change and fade color to music and switches beetween strips
	return 0;
}
void BoxRGB2::printValue(int value[]) {// This is the function that actually changes the values.
	
	analogWrite(_R1,value[0]);
	analogWrite(_G1,value[1]);
	analogWrite(_B1,value[2]);
	
	analogWrite(_R2,value[3]);
	analogWrite(_G2,value[4]);
	analogWrite(_B2,value[5]);
	
	analogWrite(_R3,value[6]);
	analogWrite(_G3,value[7]);
	analogWrite(_B3,value[8]);
	
	analogWrite(_R4,value[9]);
	analogWrite(_G4,value[10]);
	analogWrite(_B4,value[11]);

}

void BoxRGB2::printValue(int _strip1, int _strip2,int _strip3, int _strip4) {
	if (_strip1 == 1) {
		analogWrite(_R1,_value[0]);
		analogWrite(_G1,_value[1]);
		analogWrite(_B1,_value[2]);
	}
	if (_strip2 == 1) {
	 analogWrite(_R2,_value[3]);
	 analogWrite(_G2,_value[4]);
	 analogWrite(_B2,_value[5]);
	}
	if (_strip3 == 1) {
	 analogWrite(_R3,_value[6]);
	 analogWrite(_G3,_value[7]);
	 analogWrite(_B3,_value[8]);
	}
	if (_strip4 == 1) {
	 analogWrite(_R4,_value[9]);
	 analogWrite(_G4,_value[10]);
	 analogWrite(_B4,_value[11]);
	}
}

void BoxRGB2::musicColorDamper(int _color, int _damping, int _strip) {
	
	if (_color != -1) { // -1 är om färgen redan är satt;
	  oneColor(_color, _strip); // denna funktion sätter färgen
	}
	
	int _R;
	int _G;
	int _B;
	
  if (_strip == 1 || _strip == 0) {
  	 _R = 0;
  	 _G = 1;
  	 _B = 2;
  }
  if (_strip == 2) {
  	 _R = 3;
  	 _G = 4;
  	 _B = 5;
  }
  if (_strip == 3) {
  	 _R = 6;
  	 _G = 7;
  	 _B = 8;
  }
  if (_strip == 4) {
  	 _R = 9;
  	 _G = 10;
  	 _B = 11;
  }
  
 int _r = _value[_R]; 
 int _g = _value[_G];
 int _b = _value[_B];
 _r = _r*_damping/255;
 _g = _g*_damping/255;
 _b = _b*_damping/255;
 _value[_R] =_r;
 _value[_G] =_g;
 _value[_B] =_b;
  if (_strip == 0) {
	allFollow1();
  }
 

}
 
 
 
 
 
 