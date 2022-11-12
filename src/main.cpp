#include <Arduino.h>


  const int A = A0;  
  const int koljeno = 5;

  int ulaz = 0;
  int koljeno_val;
  int last_val;
  float napon = 0;

void setup() 
{
  pinMode(koljeno, INPUT); 	
  pinMode(A, INPUT); 	
  Serial.begin(9600);
}

void loop() 
{
  ulaz = analogRead(A);
  napon = ((float)ulaz / 1023.f) * 5.f;
  koljeno_val = digitalRead(koljeno);


  /*Serial.print(ulaz); //Printanje pina 9 (pwm)
  Serial.print("\n");
  Serial.print("Napon: ");
  Serial.print(napon);
  Serial.print("\n");

  Serial.print("Koljeno: ");  //Printanje pina 5 
  Serial.print(koljeno_val);
  Serial.print("\n");*/

  if(koljeno_val == 1)
  {
    if(last_val == 1)
  }

}