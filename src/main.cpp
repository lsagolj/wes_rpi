#include <Arduino.h>
#include <Timer.h>

  const int A = A0;  
  const int koljeno = 5;

  int ulaz = 0;
  int koljeno_val;
  int last_val = 0;
  float napon = 0;
  long int proslo_vrijeme = 0;

Timer timer(MICROS);

void rpm();

void setup() 
{
   Serial.begin(9600);
}

void loop() 
{
  Serial.print("Test");

  delay(100);
}