#include "moveRobot.h"

const int trig = 12;
const int echo = 11;

void updateBackdistance(){
  long duration;

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  back_distance = duration / 29 / 2;

  Serial.print(back_distance);
  Serial.print("cm");
  Serial.println();
  delay(50);
}
