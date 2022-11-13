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
Timer timerStartFiring(MICROS);
Timer timerFire(MICROS);



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
    //Serial.println(pinDeltaTime);
    unsigned long angle = bobina->getAngle(mapSensor->getPressure(), koljenasto->getRPM());

    unsigned long timeTillFirstPin = pinDeltaTime * 3 - (currTime - koljenasto->getPinLastPosReadTime());
    unsigned long timeTillGMT = timeTillFirstPin + pinDeltaTime * 9;
    timeThatShouldFire = timeTillGMT - angle * pinDeltaTime  / 15;
    timeThatShouldStartFiring = timeThatShouldFire - 1500;

    Serial.print(timeThatShouldStartFiring);
    Serial.print(" ");
    Serial.println(timeThatShouldFire);

    timerStartFiring.start();
    timerFire.start();
      

    bregasta->s_IsActivated = false;
  }

  if (timerStartFiring.state() == RUNNING && timerStartFiring.read() > timeThatShouldStartFiring) {
    timerStartFiring.stop();
    digitalWrite(PIN_INT, HIGH);
    Serial.println("START FIRING");
  }

  if (timerFire.state() == RUNNING && timerFire.read() > timeThatShouldFire) {
    timerFire.stop();
    digitalWrite(PIN_INT, LOW);
    Serial.println("FIRE");
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