/*
  BoxRGB2.h - Library for patterns to RGB-LED box
  Created by Lucas Wennerholm 2014-05-08
*/

#ifndef BoxRGB2_h
#define BoxRGB2_h

#include "Arduino.h"
#include "Ticker.h"
#include "LjudAnalys.h"



class BoxRGB2
{
  public:
    BoxRGB2();
    int colorSweep(int _time,int _strip);   // Function that goes trough all colors
    int colorSweepLR(int _time, int _dist); // Function that uses all 4 strips, pulsing colors
    int oneColor(int _tick1,int _strip);     // Function that sets all strips to one color
    int strobe();       // Function that strobes all strips
    int musicFade(int _val, int _color, int _strip);    // function that fades one color with music
    int musicColorChange(int _beat,int _strip,int _print); // Function that changes the color with music
    int musicFadeColorchange(int _volume,int _beat,int _strip); // Function that both change and fade color to music
    int musicFadeColorChangeLR(); // Function that both change and fade color to music and switches beetween strips
    void printValue(int value[]);  // This is the function that actually changes the values.
    void initialValue();			// sets initial values
    void allFollow1(); 			// This function gives all strips the same value as strip 1.
    void musicColorDamper(int _color, int _damping, int _strip);    // An internal function that damps the brightness while trying to maintain color
    void colorDEF(); 												// Function that defines colors
    void setColor(int _color[],int _strip); // sets color
    void printValue(int _strip1, int _strip2,int _strip3, int _strip4); // strips [1,2,3,4] 1 = print, 0 no print.
  private:
  int _R1;
  int _G1;
  int _B1;
  int _R2;
  int _G2;
  int _B2;
  int _R3;
  int _G3;
  int _B3;
  int _R4;
  int _G4;
  int _B4;
  
  int _value[12];
  int _tick1;
  int _strobeState;
  int _colorChange;
  Ticker tickerColorSweep;
  Ticker tickerColorSweepLR;
  Ticker tickerStrobe;
  
  // Colors
	int white[3]; 
	int black[3]; 
	int red[3];   
	int green[3]; 
	int blue[3];  
	int purple[3];
	int turkos[3];
	int yellow[3];
	int pink[3];  


};

#endif