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
  delay(2500);                       // wait for a second
  digitalWrite(18, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}

void resetMinedetect(){
  mine = false; detection = false; red = false;
  minetic = 0; minetoc = 0; minebase = 0; minemaxdiff = 0;
  maxcolour = 0; smallmaxcolour = 0;
  Serial.println("reset all parameters");
}

int getColourvalue(){
  if (side_distance1 < 33){return 0;}
  else if (side_distance1 < 41) {
    int val4 = analogRead(A12); int val5 = analogRead(A13);
    return val4 + val5;
  }
  else {
    int val1 = analogRead(A9); int val2 = analogRead(A10);
    int val3 = analogRead(A11); int val4 = analogRead(A12);
    int val5 = analogRead(A13);
    return val1 + val2 + val3 + val4 + val5;
  }
}

void updateMaxcolour(){
  if (side_distance1 < 33) {maxcolour = 0; }
  else if (side_distance1 < 41){
    int val4 = analogRead(A12);
    int val5 = analogRead(A13);

    if (val4 > maxcolour) {maxcolour = val4;}
    if (val5 > maxcolour) {maxcolour = val5;}
  }
  else {
    int val1 = analogRead(A9); int val2 = analogRead(A10);
    int val3 = analogRead(A11); int val4 = analogRead(A12);
    int val5 = analogRead(A13);

    if (val1 > maxcolour) {maxcolour = val1;}
    if (val2 > maxcolour) {maxcolour = val2;}
    if (val3 > maxcolour) {maxcolour = val3;}
    if (val4 > maxcolour) {maxcolour = val4;}
    if (val5 > maxcolour) {maxcolour = val5;}
  }
}

void tic_mine(){minetic = getColourvalue();}

void classifyMine(){
  minetoc = getColourvalue();
  int diff_mine = abs(minetoc - minetic);
  if (diff_mine > 25 && diff_mine < 100){minebase = minetic; classifyRed();}
}

void updateMinemaxdiff(){
  minetoc = getColourvalue();
  int diff_base = abs(minetoc - minebase);
  if (minemaxdiff < diff_base){minemaxdiff = diff_base;}
}

void classifyRed(){
  tempStopmotor();
  for (byte i=0; i < 80; i++) {detection_rotation1(); updateMaxcolour(); updateMinemaxdiff();}
  tempStopmotor(); delay(100);
  for (byte i=0; i < 160; i++) {detection_rotation2(); updateMaxcolour(); updateMinemaxdiff();}
  tempStopmotor(); delay(100);
  for (byte i=0; i < 60; i++) {detection_rotation1(); updateMaxcolour(); updateMinemaxdiff();}
  Serial.print("max value: "); Serial.println(maxcolour);
  //Serial.print("minemaxdiff: "); Serial.println(minemaxdiff);

  if (minemaxdiff > 200) {resetMinedetect(); runtimeForward(5);}
  else {
    if (maxcolour < 100 && maxcolour > 40) {detection = true; mine = true; red = true; Serial.println("mine true");}
    else if (maxcolour > 100 && maxcolour < 200) {detection = true;mine = true; red = false;Serial.println("mine true");}
    else {resetMinedetect(); }
  }

}

// void classifyRed(){
//   updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
//   updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
//   updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
//   updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
// //  updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
// //  updateMinemaxdiff(); updateBackDistance(); feedbackForward2();
//   Serial.print("minemaxdiff ");
//   Serial.println(minemaxdiff);
//
//   if (minemaxdiff > 100) {mine = false; detection = false; minetic = 0; minetoc = 0; minebase = 0; minemaxdiff = 0; Serial.println("white line");}
//   if (minemaxdiff < 40){detection = true; red = true;}
//   else if (minemaxdiff > 40) {detection = true; red = false;}
// }
