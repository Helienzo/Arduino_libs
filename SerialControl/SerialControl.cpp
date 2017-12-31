/*
  SerialControll.h - Library for receiving serial information
  Created by Lucas Wennerholm 2017-08-20
*/

#include "Arduino.h"
#include "SerialControl.h"
#include "Ticker.h"


SerialControl::SerialControl() {
	int dVal = 0;
}

 //******************************** Methods ***************************************
void SerialControl::begin(long baudrate) {
    Serial.begin(baudrate);
}

void SerialControl::print() {
	for (int i; i < 36; i++) {
		Serial.print(characterCount[i]);
		Serial.print(",");
	}
	Serial.println();
}

void SerialControl::reset() {
	for (int i = 0; i<37; i++) {
		characterCount[i] = 0;
	}
}

void SerialControl::setState(int state, int character) {
	characterCount[character] = state;
}

int SerialControl::getState(int states, int character) {
	int stateCount = characterCount[character];
	
	if (stateCount>=states) {
		stateCount = stateCount-(int)(stateCount/states)*states;
	}
	
	return stateCount;
}

int SerialControl::getDirection(int char1,int char2,int weight) {
	int dVal = characterCount[char1]*weight - characterCount[char2]*weight;
	return dVal;
}

int SerialControl::getDirectionS(int char1,int char2,int weight,long speed) {
	speed = speed*10000;
	int count = characterCount[char1]*weight - characterCount[char2]*weight;
	int diff = 0;
	
	if (dVal[char1] == -1) {
		dVal[char1] = count;
	}
	
	if (dVal[char1] != count) {
		diff = dVal[char1] - count;
		if (ticker1.tickMicros(speed) != 0) {
			if (diff > 0) {
				dVal[char1]--;
			}
			if (diff < 0) {
				dVal[char1]++;
			}
		}
	}
	
	return dVal[char1];
}

void SerialControl::setCount(int index,int number) {
	characterCount[index] = number;
	dVal[index] = -1;
}

void SerialControl::nRF24(int inByte) { // Put inside radio.available()
	read(inByte);
}

void SerialControl::readSerial() {
	int inByte;
	if (Serial.available()) {
    	inByte = Serial.read();
    	read(inByte);
    }
}

/*int SerialControl::getCount() {
	return characterCount;
}*/

void SerialControl::read(int inByte) {
	
    	switch (inByte) {
        	
        	case 27:
      			for (int i=0; i<36; i++) {
      				characterCount[i] = 0;
      			}
      		break;
      		
        	case 48:
            	characterCount[0]++; //0
      		break;
      		
      		case 49:
            	characterCount[1]++;
      		break;
      		
      		case 50:
            	characterCount[2]++;
      		break;
      		
      		case 51:
            	characterCount[3]++;
      		break;
      		
      		case 52:
            	characterCount[4]++;
      		break;
      		
      		case 53:
            	characterCount[5]++;
      		break;
      		
      		case 54:
            	characterCount[6]++;
      		break;
      		
      		case 55:
            	characterCount[7]++;
      		break;
      		
      		case 56:
            	characterCount[8]++;
      		break;
      		
      		case 57:
            	characterCount[9]++; //9
      		break;
      		
      		case 97:
            	characterCount[10]++; //a
      		break;
      		
      		case 98:
            	characterCount[11]++; //b
      		break;
      		
      		case 99:
            	characterCount[12]++; //c
      		break;
      		
      		case 100:
            	characterCount[13]++; //d
      		break;
      		
      		case 101:
            	characterCount[14]++; //e
      		break;
      		
      		case 102:
            	characterCount[15]++; //f
      		break;
      		
      		case 103:
            	characterCount[16]++; //g
      		break;
      		
      		case 104:
            	characterCount[17]++; //h
      		break;
      		
      		case 105:
            	characterCount[18]++; //i
      		break;
      		
      		case 106:
            	characterCount[19]++; //j
      		break;
      		
      		case 107:
            	characterCount[20]++; //k
      		break;
      		
      		case 108:
            	characterCount[21]++; //l
      		break;
      		
      		case 109:
            	characterCount[22]++; //m
      		break;
      		
      		case 110:
            	characterCount[23]++; //n
      		break;
      		
      		case 111:
            	characterCount[24]++; //o
      		break;
      		
      		case 112:
            	characterCount[25]++; //p
      		break;
      		
      		case 113:
            	characterCount[26]++; //q
      		break;
      		
      		case 114:
            	characterCount[27]++; //r
      		break;
      		
      		case 115:
            	characterCount[28]++; //s
      		break;
      		
      		case 116:
            	characterCount[29]++; //t
      		break;
      		
      		case 117:
            	characterCount[30]++; //u
      		break;
      		
      		case 118:
            	characterCount[31]++; //v
      		break;
      		
      		case 119:
            	characterCount[32]++; //w
      		break;
      		
      		case 120:
            	characterCount[33]++; //x
      		break;
      		
      		case 121:
            	characterCount[34]++; //y
      		break;
      		
      		case 122:
            	characterCount[35]++; //z
      		break;
      		
      		case 9:
      			characterCount[36]++; //TAB
      		break;
      		
    	}
}