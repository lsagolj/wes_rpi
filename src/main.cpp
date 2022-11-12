#include <Arduino.h>
#include <Timer.h>

const int A = A0;  
const int koljeno = 2;

int ulaz = 0;
int koljeno_val;
int last_val = 0;
float f_min;
float napon = 0;
uint32_t proslo_vrijeme = 0;

Timer timer(MICROS);

void rpm();

void setup() 
{
  pinMode(koljeno, INPUT); 	
  pinMode(A, INPUT); 	

  attachInterrupt(digitalPinToInterrupt(koljeno), rpm, RISING);


  Serial.begin(9600);
}

void loop() 
{
  /*ulaz = analogRead(A);
  napon = ((float)ulaz / 1023.f) * 5.f;*/
  //koljeno_val = digitalRead(koljeno);

  //Serial.print("a");
}

void rpm()
{
  if(timer.state() != RUNNING)
  {
    timer.start();
  }
  else
  {
    timer.stop();
    uint32_t x = (timer.read() * 1000 *1000 * 60);
    f_min = 60.f / (float)x;

    Serial.println(f_min);



    proslo_vrijeme = timer.read();
  }
  //Serial.print("n");
}