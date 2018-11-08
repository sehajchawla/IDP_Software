#include "moveRobot.h"

//side_distance is the reading obtained from the ultrasond sensor
int time_clock = 0; float side_distance = 0; float back_distance = 0;
bool mine=false; bool red=false;
bool clockwise_180=true; bool north=true; bool clockwise_90=false;

void moveForward(){
 while (FULL_DEPTH - back_distance < TOLERANCE){
   if (mine == false){goForward();}
   else if (red == false){delay(1000); goForward();}
   else {delay(1000); delay(1000); goForward();}
 }
}

void testMovement(){
  if (time_clock < 5){goForward(2);time_clock += 1;}
  else if (time_clock < 10){goBackward(); time_clock += 1;}
  else {stopMotor();}
  Serial.println(time_clock);
}

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  startMotor();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (time_clock < 1){rotation180();time_clock += 1;}
  else {stopMotor();}
  Serial.println(time_clock);
}
