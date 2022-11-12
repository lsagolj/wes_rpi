#include <Arduino.h>
#include "koljenasto/Koljenasto.h"

const uint8_t PIN_MAP = A0;  
const uint8_t PIN_KOLJENASTO = 2;
const uint8_t PIN_BREAGASTA = 3;

Koljenasto* koljenasto;

void setup() 
{
  pinMode(PIN_MAP, INPUT); 		
  pinMode(PIN_BREAGASTA, INPUT);

  koljenasto = new Koljenasto(PIN_KOLJENASTO);

  Serial.begin(9600);
}

void loop() {
  Serial.println(koljenasto->getRPM());
}