#include <Arduino.h>

const uint8_t PIN_MAP = A0;  
const uint8_t PIN_KOLJENASTO = 2;
const uint8_t PIN_BREAGASTA = 3;

unsigned long l_time = 0;
unsigned long kolj_time;
uint32_t kolj_counter = -1;

unsigned long kolj_last_time;

void printaj() {
  Serial.print(kolj_counter);
  Serial.print(" ");
  Serial.println(kolj_time);
}

void interrupt_citaj_koljenasto() {
  if (kolj_counter % 22 == 10) {
    kolj_time = micros() - l_time;
    l_time = micros();
  }
  kolj_counter++;
}

void setup() 
{
  pinMode(PIN_MAP, INPUT); 	
  pinMode(PIN_KOLJENASTO, INPUT); 	
  pinMode(PIN_BREAGASTA, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_KOLJENASTO), interrupt_citaj_koljenasto, RISING);

  Serial.begin(9600);
}

void loop() {
  Serial.println(kolj_time);
}