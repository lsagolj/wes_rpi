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

  /*if(koljeno_val == 1)
  {
    if(last_val != 1)
      {
        if(timer.state() != RUNNING)
          {
            timer.start();
          }
          else{
            rpm();
            timer.stop();
            last_val = 0;
          }


        
      }
  }*/

}

void rpm()
{
  int ciklus = timer.read() - proslo_vrijeme;
  float frekvencija = 1 / (ciklus * 1000000);

  proslo_vrijeme = timer.read();

  Serial.print(frekvencija);

}