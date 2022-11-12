#include <Arduino.h>

void setup() 
{
   Serial.begin(9600);
}

void loop() 
{
  Serial.print("Test");

  delay(100);
}