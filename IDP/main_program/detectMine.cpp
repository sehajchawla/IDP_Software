#include "moveRobot.h"

void startBlinkRed(){pinMode(18, OUTPUT);}
void BlinkRed(){
  digitalWrite(19, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(19, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}
void startBlinkYellow(){pinMode(19, OUTPUT);}
void BlinkYellow(){
  digitalWrite(18, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(18, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}

int getColourvalue(){
  int val1 = analogRead(A9); int val2 = analogRead(A10);
  int val3 = analogRead(A11); int val4 = analogRead(A12);
  int val5 = analogRead(A13);
  return val1 + val2 + val3 + val4 + val5;
}

void tic_mine(){minetic = getColourvalue();}

void classifyMine(){
  minetoc = getColourvalue();
  int diff_mine = abs(minetoc - minetic);
  if (diff_mine > 15){Serial.println(diff_mine); Serial.println("Perhaps a mine?"); mine = true; minebase = minetic;}
}

void updateMinemaxdiff(){
  minetoc = getColourvalue();
  int diff_base = abs(minetoc - minebase);
  if (minemaxdiff < diff_base){minemaxdiff = diff_base;}
}

void classifyRed(){
  updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
  updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
  updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
  updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
  updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
  updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
  Serial.println(minemaxdiff);

  if (minemaxdiff > 120) {mine = false; minetic = 0; minetoc = 0; minebase = 0; minemaxdiff = 0; Serial.println("white line");}
  if (minemaxdiff < 50){detection = true; red = true;}
  else if (minemaxdiff > 50) {detection = true; red = false;}
}
