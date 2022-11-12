#include <Arduino.h>
#include "koljenasto/Koljenasto.h"

#include "map/MapSensor.h"
#include "bregasta/bregasta.h"


const uint8_t PIN_MAP = A0;  
const uint8_t PIN_KOLJENASTO = 2;
const uint8_t PIN_BREGASTA = 3;

Koljenasto* koljenasto;

Bregasta* bregasta;
MapSensor* mapSensor;

void setup() 
{
  pinMode(PIN_MAP, INPUT); 			
  pinMode(PIN_BREAGASTA, INPUT);

  koljenasto = new Koljenasto(PIN_KOLJENASTO);
  bregasta = new Bregasta(PIN_BREGASTA);
  mapSensor = new MapSensor(PIN_MAP);


  Serial.begin(9600);
}

void loop() {
  Serial.println(koljenasto->getRPM());
  Serial.println(bregasta->getRPM());
  Serial.println(mapSensor->getPressure());
}