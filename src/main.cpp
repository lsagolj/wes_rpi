#include <Arduino.h>
#include "koljenasto/Koljenasto.h"
#include "map/MapSensor.h"

const uint8_t PIN_MAP = A0;  
const uint8_t PIN_KOLJENASTO = 2;
const uint8_t PIN_BREAGASTA = 3;

Koljenasto* koljenasto;
MapSensor* mapSensor;

void setup() 
{
  		
  pinMode(PIN_BREAGASTA, INPUT);

  koljenasto = new Koljenasto(PIN_KOLJENASTO);
  mapSensor = new MapSensor(PIN_MAP);

  Serial.begin(9600);
}

void loop() {
  Serial.println(koljenasto->getRPM());
  //Serial.println(mapSensor->getPressure());
}