/*
  EightBitDisplay.ccp - Library for patterns to LED stips
  Created by Lucas Wennerholm 2014-02-05
*/

#include "Arduino.h"
#include "EightBitDisplay.h"
#include "Ticker.h"


EightBitDisplay::EightBitDisplay(int d1, int d2, int d3, int d4, int dot, int a, int b, int c, int d, int e, int f, int g)
{
//set pins
  pinMode(d1, OUTPUT); // 
  pinMode(d2, OUTPUT); //
  pinMode(d3, OUTPUT); //
  pinMode(d4, OUTPUT); //
  pinMode(dot, OUTPUT); //
  pinMode(a, OUTPUT); //
  pinMode(b, OUTPUT); //
  pinMode(c, OUTPUT); //
  pinMode(d, OUTPUT); //
  pinMode(e, OUTPUT); //
  pinMode(f, OUTPUT); //
  pinMode(g, OUTPUT); //
  
 // define variables
  writeIndex = 0;
  
 _d1 = d4;
 _d2 = d3;
 _d3 = d2;
 _d4 = d1;

 _dot = dot;
 _a = a;
 _b = b;
 _c = c;
 _d = d;
 _e = e;
 _f = f;
 _g = g;


 }
 
  /////////////////////////////// EightBitDisplay-reset ///////////////////////////////
 void EightBitDisplay::defineSymbols(int _symbol) {
 	_pins[0] = _a;
 	_pins[1] = _b;
 	_pins[2] = _c;
 	_pins[3] = _d;
 	_pins[4] = _e;
 	_pins[5] = _f;
 	_pins[6] = _g;
 	_pins[7] = _dot;
 
 	if (_symbol == -1) {
 		_digit[0] = 0;
 		_digit[1] = 0;
 		_digit[2] = 0;
 		_digit[3] = 0;
 		_digit[4] = 0;
 		_digit[5] = 0;
 		_digit[6] = 0;
 	}
	if (_symbol == 0) {
	 	_digit[0] = 0;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 1;
 		_digit[4] = 1;
 		_digit[5] = 1;
 		_digit[6] = 1;
	}
	if (_symbol == 1) {
	 	_digit[0] = 0;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 0;
 		_digit[4] = 0;
 		_digit[5] = 0;
 		_digit[6] = 0;
	}
	if (_symbol == 2) {
	 	_digit[0] = 1;
 		_digit[1] = 0;
 		_digit[2] = 1;
 		_digit[3] = 1;
 		_digit[4] = 0;
 		_digit[5] = 1;
 		_digit[6] = 1;
	}
	if (_symbol == 3) {
	 	_digit[0] = 1;
 		_digit[1] = 0;
 		_digit[2] = 0;
 		_digit[3] = 1;
 		_digit[4] = 1;
 		_digit[5] = 1;
 		_digit[6] = 1;
 		}
	if (_symbol == 4) {
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 0;
 		_digit[3] = 0;
 		_digit[4] = 1;
 		_digit[5] = 1;
 		_digit[6] = 0;
	}
	if (_symbol == 5) {
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 0;
 		_digit[3] = 1;
 		_digit[4] = 1;
 		_digit[5] = 0;
 		_digit[6] = 1;
	}
	if (_symbol == 6) {
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 1;
 		_digit[4] = 1;
 		_digit[5] = 0;
 		_digit[6] = 1;
	}
	if (_symbol == 7) {
	 	_digit[0] = 0;
 		_digit[1] = 0;
 		_digit[2] = 0;
 		_digit[3] = 0;
 		_digit[4] = 1;
 		_digit[5] = 1;
 		_digit[6] = 1;
	}
	if (_symbol == 8) {
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 1;
 		_digit[4] = 1;
 		_digit[5] = 1;
 		_digit[6] = 1;
	}
	if (_symbol == 9) {
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 0;
 		_digit[3] = 0;
 		_digit[4] = 1;
 		_digit[5] = 1;
 		_digit[6] = 1;
	}
	if (_symbol == 10) { //a
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 0;
 		_digit[4] = 1;
 		_digit[5] = 1;
 		_digit[6] = 1;
	}
	if (_symbol == 11) { //b
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 1;
 		_digit[4] = 1;
 		_digit[5] = 0;
 		_digit[6] = 0;
	}
	/*
	if (_symbol == 12) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 13) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}*/
	if (_symbol == 14) { //e
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 1;
 		_digit[4] = 0;
 		_digit[5] = 0;
 		_digit[6] = 1;
	}
	if (_symbol == 15) { // f
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 0;
 		_digit[4] = 0;
 		_digit[5] = 0;
 		_digit[6] = 1;
	}/*
	if (_symbol == 16) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 17) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 18) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 19) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 20) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 21) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 22) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 23) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}*/
	if (_symbol == 24) {
	 	_digit[0] = 1;
 		_digit[1] = 0;
 		_digit[2] = 1;
 		_digit[3] = 1;
 		_digit[4] = 1;
 		_digit[5] = 0;
 		_digit[6] = 0;
	}
	/*
	if (_symbol == 25) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 26) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	*/
	if (_symbol == 27) { //r
	 	_digit[0] = 1;
 		_digit[1] = 0;
 		_digit[2] = 1;
 		_digit[3] = 0;
 		_digit[4] = 0;
 		_digit[5] = 0;
 		_digit[6] = 0;
	}
	if (_symbol == 28) { //s
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 0;
 		_digit[3] = 1;
 		_digit[4] = 1;
 		_digit[5] = 0;
 		_digit[6] = 1;
	}
	if (_symbol == 29) { //t
	 	_digit[0] = 1;
 		_digit[1] = 1;
 		_digit[2] = 1;
 		_digit[3] = 1;
 		_digit[4] = 0;
 		_digit[5] = 0;
 		_digit[6] = 0;
	}
	/*
	if (_symbol == 30) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 31) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 32) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 33) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
	if (_symbol == 34) {
	 		_digit[0] = ;
 		_digit[1] = ;
 		_digit[2] = ;
 		_digit[3] = ;
 		_digit[4] = ;
 		_digit[5] = ;
 		_digit[6] = ;
	}
*/
 	
 }
 
 void EightBitDisplay::writeDisplay(int _time) {
 	
 	if (tickerWrite.tick(_time) == 1) {
 		writeIndex++;
 		if (writeIndex == 5) {
 			writeIndex = 1;
 		}
 		
 		if (writeIndex == 1) {
 			digitalWrite(_d1,HIGH);
 			digitalWrite(_d2,LOW);
 			digitalWrite(_d3,LOW);
 			digitalWrite(_d4,LOW);
 			setArray(_digit,_digit1);
 			
 			if (_digit[0] == 1){
 				digitalWrite(_pins[0],LOW);
 			}
 			else {
 				digitalWrite(_pins[0],HIGH);
 			}
 			
 			if (_digit[1] == 1){
 				digitalWrite(_pins[1],LOW);
 			}
 			else {
 				digitalWrite(_pins[1],HIGH);
 			}
 			
 			if (_digit[2] == 1){
 				digitalWrite(_pins[2],LOW);
 			}
 			else {
 				digitalWrite(_pins[2],HIGH);
 			}
 			
 			if (_digit[3] == 1){
 				digitalWrite(_pins[3],LOW);
 			}
 			else {
 				digitalWrite(_pins[3],HIGH);
 			}
 			
 			if (_digit[4] == 1){
 				digitalWrite(_pins[4],LOW);
 			}
 			else {
 				digitalWrite(_pins[4],HIGH);
 			}
 			
 			if (_digit[5] == 1){
 				digitalWrite(_pins[5],LOW);
 			}
 			else {
 				digitalWrite(_pins[5],HIGH);
 			}
 			
 			if (_digit[6] == 1){
 				digitalWrite(_pins[6],LOW);
 			}
 			else {
 				digitalWrite(_pins[6],HIGH);
 			}
 			
 			if (_digit[7] == 1){
 				digitalWrite(_pins[7],LOW);
 			}
 			else {
 				digitalWrite(_pins[7],HIGH);
 			}
 			
 			
 		}
 		if (writeIndex == 2) {
 		 	digitalWrite(_d1,LOW);
 			digitalWrite(_d2,HIGH);
 			digitalWrite(_d3,LOW);
 			digitalWrite(_d4,LOW);
 			setArray(_digit,_digit2);
 			
 			if (_digit[0] == 1){
 				digitalWrite(_pins[0],LOW);
 			}
 			else {
 				digitalWrite(_pins[0],HIGH);
 			}
 			
 			if (_digit[1] == 1){
 				digitalWrite(_pins[1],LOW);
 			}
 			else {
 				digitalWrite(_pins[1],HIGH);
 			}
 			
 			if (_digit[2] == 1){
 				digitalWrite(_pins[2],LOW);
 			}
 			else {
 				digitalWrite(_pins[2],HIGH);
 			}
 			
 			if (_digit[3] == 1){
 				digitalWrite(_pins[3],LOW);
 			}
 			else {
 				digitalWrite(_pins[3],HIGH);
 			}
 			
 			if (_digit[4] == 1){
 				digitalWrite(_pins[4],LOW);
 			}
 			else {
 				digitalWrite(_pins[4],HIGH);
 			}
 			
 			if (_digit[5] == 1){
 				digitalWrite(_pins[5],LOW);
 			}
 			else {
 				digitalWrite(_pins[5],HIGH);
 			}
 			
 			if (_digit[6] == 1){
 				digitalWrite(_pins[6],LOW);
 			}
 			else {
 				digitalWrite(_pins[6],HIGH);
 			}
 			
 			if (_digit[7] == 1){
 				digitalWrite(_pins[7],LOW);
 			}
 			else {
 				digitalWrite(_pins[7],HIGH);
 			}
 			
 		}
 		if (writeIndex == 3) {
 		 	digitalWrite(_d1,LOW);
 			digitalWrite(_d2,LOW);
 			digitalWrite(_d3,HIGH);
 			digitalWrite(_d4,LOW);
 			setArray(_digit,_digit3);
 			
 			if (_digit[0] == 1){
 				digitalWrite(_pins[0],LOW);
 			}
 			else {
 				digitalWrite(_pins[0],HIGH);
 			}
 			
 			if (_digit[1] == 1){
 				digitalWrite(_pins[1],LOW);
 			}
 			else {
 				digitalWrite(_pins[1],HIGH);
 			}
 			
 			if (_digit[2] == 1){
 				digitalWrite(_pins[2],LOW);
 			}
 			else {
 				digitalWrite(_pins[2],HIGH);
 			}
 			
 			if (_digit[3] == 1){
 				digitalWrite(_pins[3],LOW);
 			}
 			else {
 				digitalWrite(_pins[3],HIGH);
 			}
 			
 			if (_digit[4] == 1){
 				digitalWrite(_pins[4],LOW);
 			}
 			else {
 				digitalWrite(_pins[4],HIGH);
 			}
 			
 			if (_digit[5] == 1){
 				digitalWrite(_pins[5],LOW);
 			}
 			else {
 				digitalWrite(_pins[5],HIGH);
 			}
 			
 			if (_digit[6] == 1){
 				digitalWrite(_pins[6],LOW);
 			}
 			else {
 				digitalWrite(_pins[6],HIGH);
 			}
 			
 			if (_digit[7] == 1){
 				digitalWrite(_pins[7],LOW);
 			}
 			else {
 				digitalWrite(_pins[7],HIGH);
 			}
 			

 		}
 		if (writeIndex == 4) {
 		 	digitalWrite(_d1,LOW);
 			digitalWrite(_d2,LOW);
 			digitalWrite(_d3,LOW);
 			digitalWrite(_d4,HIGH);
 			setArray(_digit,_digit4);
 			
 			if (_digit[0] == 1){
 				digitalWrite(_pins[0],LOW);
 			}
 			else {
 				digitalWrite(_pins[0],HIGH);
 			}
 			
 			if (_digit[1] == 1){
 				digitalWrite(_pins[1],LOW);
 			}
 			else {
 				digitalWrite(_pins[1],HIGH);
 			}
 			
 			if (_digit[2] == 1){
 				digitalWrite(_pins[2],LOW);
 			}
 			else {
 				digitalWrite(_pins[2],HIGH);
 			}
 			
 			if (_digit[3] == 1){
 				digitalWrite(_pins[3],LOW);
 			}
 			else {
 				digitalWrite(_pins[3],HIGH);
 			}
 			
 			if (_digit[4] == 1){
 				digitalWrite(_pins[4],LOW);
 			}
 			else {
 				digitalWrite(_pins[4],HIGH);
 			}
 			
 			if (_digit[5] == 1){
 				digitalWrite(_pins[5],LOW);
 			}
 			else {
 				digitalWrite(_pins[5],HIGH);
 			}
 			
 			if (_digit[6] == 1){
 				digitalWrite(_pins[6],LOW);
 			}
 			else {
 				digitalWrite(_pins[6],HIGH);
 			}
 			
 			if (_digit[7] == 1){
 				digitalWrite(_pins[7],LOW);
 			}
 			else {
 				digitalWrite(_pins[7],HIGH);
 			}
 			
 		}
 	}
 }
 
 void  EightBitDisplay::setDigit(int digit1, int digit2, int digit3, int digit4) {
 	defineSymbols(digit1);
 	setArray(_digit1,_digit);
 	defineSymbols(digit2);
 	setArray(_digit2,_digit);
 	defineSymbols(digit3);
 	setArray(_digit3,_digit);
 	defineSymbols(digit4);
 	setArray(_digit4,_digit);
 
 }
 
 void EightBitDisplay::setArray(int array1[],int array2[]) {
 		array1[0] = array2[0];
 		array1[1] = array2[1];
 		array1[2] = array2[2];
 		array1[3] = array2[3];
 		array1[4] = array2[4];
 		array1[5] = array2[5];
 		array1[6] = array2[6];
 		array1[7] = array2[7];
 }
 
 void EightBitDisplay::setDot(int dot1, int dot2, int dot3, int dot4) {
 	if (dot1 == 1) {
 		_digit1[7] = 1;
 	}
 	else {
 		_digit1[7] = 0;
 	}
 	
 	if (dot2 == 1) {
 		_digit2[7] = 1;
 	}
 	else {
 		_digit2[7] = 0;
 	}
 	
 	if (dot3 == 1) {
 		_digit3[7] = 1;
 	}
 	else {
 		_digit3[7] = 0;
 	}
 	
 	if (dot4 == 1) {
 		_digit4[7] = 1;
 	}
 	else {
 		_digit4[7] = 0;
 	}
 	
 }