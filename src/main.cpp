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
//Inter*      inter;

//Timer timer;

unsigned long timeThatShouldFire = 0;
unsigned long timeThatShouldStartFiring = 0;

void setup() {
  koljenasto  = new Koljenasto(PIN_KOLJENASTO);
  bregasta    = new Bregasta(PIN_BREGASTA);
  mapSensor   = new MapSensor(PIN_MAP);
  bobina      = new Bobina();
  //inter       = new Inter(PIN_INT);
  pinMode(PIN_INT, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  unsigned long currTime = micros();
  //Serial.println(koljenasto->getPinDeltaTime());
  
  /*Serial.println(bobina->getAngle(mapSensor->getPressure(), koljenasto->getRPM()));
  Serial.println(mapSensor->getPressure());
  Serial.println(koljenasto->getRPM());

  Serial.print("\n");*/
  //Serial.println(mapSensor->getPressure());
  if (bregasta->s_IsActivated) {
    unsigned long pinDeltaTime = koljenasto->getPinDeltaTime();
    unsigned long angle = bobina->getAngle(mapSensor->getPressure(), koljenasto->getRPM());

    unsigned long timeTillFirstPin = pinDeltaTime * 3 - (currTime - koljenasto->getPinLastPosReadTime());
    unsigned long timeTillGMT = timeTillFirstPin + pinDeltaTime * 9;
    timeThatShouldFire = timeTillGMT - pinDeltaTime * ((double)angle / 15.0);
    timeThatShouldStartFiring = timeThatShouldFire - 1500;

    timeThatShouldFire += currTime;
    timeThatShouldStartFiring += currTime;

    bregasta->s_IsActivated = false;
  }

  if (currTime > timeThatShouldStartFiring) {
    timeThatShouldStartFiring = 0;
    digitalWrite(PIN_INT, HIGH);
  }

  if (currTime > timeThatShouldFire) {
    timeThatShouldFire = 0;
    digitalWrite(PIN_INT, LOW);
  }


  //Kod koji odreduje koliko ranije krenuti puniti bobinu
  /*if(timer.state() != RUNNING)    //Ovo je samo simulacija inputa
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
  }*/
}