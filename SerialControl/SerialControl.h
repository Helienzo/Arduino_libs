/*
  SerialControll.h - Library for receiving serial information
  Created by Lucas Wennerholm 2017-08-20
  
  The library counts the number times a specific character has been recived
*/
#ifndef SerialControl_h
#define SerialControl_h

#include "Arduino.h"
#include "Ticker.h"

class SerialControl
{
  public:
    SerialControl();
    void begin(long baudrate);
    void readSerial();
    void nRF24(int inByte);
 	void print();
 	void reset();
 	int getDirection(int char1,int char2,int weight);
 	int getDirectionS(int char1,int char2,int weight,long speed);
 	void setState(int state, int character);
 	int getState(int states, int character);
 	void setCount(int index, int number);
 	//void getByte();
 	int getCount(); //Returns count array
  private:
    Ticker ticker1;
    int dVal[37] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  	void read(int inByte);
  	/* characterCount [0:9] - numbers 0-9, [10:35] - letters a-z*/
  	int characterCount[37] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
};

#endif