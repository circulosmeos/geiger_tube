/*
 *  ------Geiger Tube board (Raspberry Pi + arduPi library Code) Example------
 *
 *  Explanation: This example shows how to get the signal from the Geiger Tube
 *  in Arduino, we use one of the Arduino interrupt pins (PIN2).
 *  We count the time (ms) between two pulses of the Geiger tube.
 *
 *  Copyright (C) 2011 Libelium Comunicaciones Distribuidas S.L.
 *  http://www.libelium.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see .
 *
 *  Version:		0.1
 *  Implementation:	Anartz Nuin Jiménez
 *  Version:		0.2 
 *                  20140420 by circulosmeos (circulosmeos.wordpress.com)
 *                  arduPi v1.5 adapted and safe loop
 */

#include "arduPi.h"

// Not needed since arduPi v1.5
//SerialPi Serial;
//WirePi Wire;
//SPIPi SPI;

// Conversion factor - CPM to uSV/h
#define CONV_FACTOR 0.00812

int geiger_input = 2;
long count = 0;
long timePreviousMeassure = 0;
long countPerMinute = 0;
float radiationValue = 0.0;

void countPulse();

void setup(){
	pinMode(geiger_input, INPUT);
	digitalWrite(geiger_input,HIGH);
	attachInterrupt(2,countPulse, FALLING);
}

void loop(){

  if (millis()-timePreviousMeassure > 10000){

    timePreviousMeassure = millis();

	//detachInterrupt for accesing securely to count variable
	detachInterrupt(2);

	countPerMinute = 6*count;
	radiationValue = countPerMinute * CONV_FACTOR;

	fprintf(stderr,"CPM=");
	fprintf(stderr,"%d\n",countPerMinute);
	fprintf(stderr,"%f",radiationValue);
	fprintf(stderr," uSv/h\n");

	count = 0;

	attachInterrupt(2,countPulse,FALLING);
	
	delay(10000);
  }
}

void countPulse(){
  count++;
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}
