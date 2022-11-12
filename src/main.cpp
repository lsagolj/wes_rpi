#include <Arduino.h>

const int INPUT_KOLJ = 5;

int counter = 0;
int prev = -1;

unsigned long prev_time = micros();

void setup()  {
  pinMode(INPUT_KOLJ, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(INPUT_KOLJ);
  if (val == 1 && prev == 0) {
    unsigned long speed = micros() - prev_time;
    //Serial.println(speed);
    prev_time = micros();
  }
  Serial.println(val);
  prev = val;
}