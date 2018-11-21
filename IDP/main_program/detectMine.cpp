#include "moveRobot.h"

void startBlinkRed(){pinMode(18, OUTPUT);}
void BlinkRed(){
  digitalWrite(18, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(18, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}
void startBlinkYellow(){pinMode(19, OUTPUT);}
void BlinkYellow(){
  digitalWrite(19, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(19, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}

//note this function does not classify the colour of the mine
byte classifyMine(int sensorValue){
  //this line is for the color red
  if (sensorValue > 100 && sensorValue < 200){return 1;}

  //this line is for color yellow
  else if (sensorValue > 300 && sensorValue < 400){return 1;}
  else {return 0;}
}

byte classifyRed(int sensorValue){
  if (sensorValue > 100 && sensorValue < 200){return 1;}
  else if (sensorValue > 300 && sensorValue < 400){return 0;}
  else {return 0;}
}

void tic_mine(){
  int val1 = analogRead(A9); int val2 = analogRead(A10);
  int val3 = analogRead(A11); int val4 = analogRead(A12);
  int val5 = analogRead(A13);
  minetic = val1 + val2 + val3 + val4 + val5;
}

void toc_mine(){
  // int val1 = analogRead(A0); int val2 = analogRead(A1);
  // int val3 = analogRead(A2); int val4 = analogRead(A3);
  // int val5 = analogRead(A4);
  //
  // byte mine1 = classifyMine(val1); byte mine2 = classifyMine(val2);
  // byte mine3 = classifyMine(val3); byte mine4 = classifyMine(val4);
  // byte mine5 = classifyMine(val5);
  // byte mine_sum; mine_sum = mine1 + mine2 + mine3 + mine4 + mine5;
  int val1 = analogRead(A9); int val2 = analogRead(A10);
  int val3 = analogRead(A11); int val4 = analogRead(A12);
  int val5 = analogRead(A13);
  minetoc = val1 + val2 + val3 + val4 + val5;

  int diff_mine = minetic - minetoc;
  if (abs(diff_mine) > 9){Serial.println(diff_mine);}


  // if (mine_sum > 0 && mine_sum < 3){mine  = true;}
  // else {mine = false;}
  //
  // if (mine == true){
  //   byte red1 = classifyRed(val1); byte red2 = classifyRed(val2);
  //   byte red3 = classifyRed(val3); byte red4 = classifyRed(val4);
  //   byte red5 = classifyRed(val5);
  //   byte red_sum; red_sum = red1 + red2 + red3 + red4 + red5;
  //   if (red_sum > 0 && red_sum < 3) {red = true;}
  //   else {red = false;}
  // }
}
