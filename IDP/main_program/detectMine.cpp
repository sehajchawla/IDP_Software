#include "moveRobot.h"

void startBlink(){pinMode(LED_BUILTIN, OUTPUT);}
void Blink(){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
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
  if (sensorValue > 100 && sensorValue < 200){return true;}
  else if (sensorValue > 300 && sensorValue < 400){return false;}
}


void confirmMine(){
  int val1 = analogRead(A0); int val2 = analogRead(A1);
  int val3 = analogRead(A2); int val4 = analogRead(A3);
  int val5 = analogRead(A4);

  byte mine1 = classifyMine(val1); byte mine2 = classifyMine(val2);
  byte mine3 = classifyMine(val3); byte mine4 = classifyMine(val4);
  byte mine5 = classifyMine(val5);
  byte mine_sum; mine_sum = mine1 + mine2 + mine3 + mine4 + mine5;

  if (mine_sum > 0 && mine_sum < 3){mine  = true;}
  else {mine = false;}

  if (mine == true){
    byte red1 = classifyRed(val1); byte red2 = classifyRed(val2);
    byte red3 = classifyRed(val3); byte red4 = classifyRed(val4);
    byte red5 = classifyRed(val5);
    byte red_sum; red_sum = red1 + red2 + red3 + red4 + red5;
    if (red_sum > 0 && red_sum < 3) {red = true;}
    else {red = false;}
  }
}
