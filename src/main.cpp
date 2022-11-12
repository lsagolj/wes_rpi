#include <Arduino.h>
#include "koljenasto/Koljenasto.h"
#include "bregasta/bregasta.h"

const uint8_t PIN_MAP = A0;  
const uint8_t PIN_KOLJENASTO = 2;
const uint8_t PIN_BREGASTA = 3;

Koljenasto* koljenasto;
Bregasta* bregasta;

void setup() 
{
  pinMode(PIN_MAP, INPUT); 		
  pinMode(PIN_BREGASTA, INPUT);

  koljenasto = new Koljenasto(PIN_KOLJENASTO);
  bregasta = new Bregasta(PIN_BREGASTA);
  Serial.begin(9600);
}

void loop() {
  //Serial.println(koljenasto->getRPM());
  Serial.println(bregasta->getRPM());
}