#include <Arduino.h>
#include "koljenasto/Koljenasto.h"
#include "map/MapSensor.h"
#include "bregasta/bregasta.h"
#include "bobina/Bobina.h"

const uint8_t PIN_MAP = A0;  
const uint8_t PIN_KOLJENASTO = 2;
const uint8_t PIN_BREGASTA = 3;

Koljenasto* koljenasto;
Bregasta* bregasta;
MapSensor* mapSensor;
Bobina* bobina;

void setup() {
  cli();
  koljenasto = new Koljenasto(PIN_KOLJENASTO);
  bregasta = new Bregasta(PIN_BREGASTA);
  mapSensor = new MapSensor(PIN_MAP);
  bobina = new Bobina();
  Serial.begin(9600);
  sei();
}

void loop() {
  //Serial.println(koljenasto->getPinDeltaTime());
  
  /*Serial.println(bobina->getAngle(mapSensor->getPressure(), koljenasto->getRPM()));
  Serial.println(mapSensor->getPressure());
  Serial.println(koljenasto->getRPM());

  Serial.print("\n");*/
  //Serial.println(mapSensor->getPressure());

  if(bregasta->s_BregastaCounter == 3 || bregasta->s_BregastaCounter == 6)
    bobina->sendPulse();

}