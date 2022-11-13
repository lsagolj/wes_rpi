#include <Arduino.h>
#include <Timer.h>

#include "koljenasto/Koljenasto.h"
#include "map/MapSensor.h"
#include "bregasta/bregasta.h"
#include "bobina/Bobina.h"
#include "int/int.h"

const uint8_t PIN_MAP         = A0;  
const uint8_t PIN_KOLJENASTO  = 2;
const uint8_t PIN_BREGASTA    = 3;
const uint8_t PIN_INT         = 7;

Koljenasto* koljenasto;
Bregasta*   bregasta;
MapSensor*  mapSensor;
Bobina*     bobina;
Inter*      inter;

Timer timer;

void setup() {
  koljenasto  = new Koljenasto(PIN_KOLJENASTO);
  bregasta    = new Bregasta(PIN_BREGASTA);
  mapSensor   = new MapSensor(PIN_MAP);
  bobina      = new Bobina();
  inter       = new Inter(PIN_INT);

  Serial.begin(9600);
}

void loop() {

  //Serial.println(koljenasto->getPinDeltaTime());
  
  /*Serial.println(bobina->getAngle(mapSensor->getPressure(), koljenasto->getRPM()));
  Serial.println(mapSensor->getPressure());
  Serial.println(koljenasto->getRPM());

  Serial.print("\n");*/
  //Serial.println(mapSensor->getPressure());

  //Kod koji odreduje koliko ranije krenuti puniti bobinu
  if(timer.state() != RUNNING)
  {
    timer.start();
    digitalWrite(PIN_INT, 1);
  }

  else{
    if(timer.read() == 150)
      {
        timer.stop();
        digitalWrite(PIN_INT, 0);
      }
  }
}