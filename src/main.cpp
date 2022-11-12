#include <Arduino.h>


  const int A = A0;  
  int ulaz = 0;
  float napon;

void setup() 
{

  pinMode(A, INPUT); 	
   Serial.begin(9600);
}

void loop() 
{
  ulaz = analogRead(A);
  napon = ulaz / 1023 * 5;

  Serial.print(ulaz);
  Serial.print("\n");
  Serial.print("Napon: ");
  Serial.print(napon);
  Serial.print("\n");

  delay(100);
}