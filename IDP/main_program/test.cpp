#include "moveRobot.h"

// expect to rotate 180 degree, adjust motor run time if not
void testRotation(){rotation180(); stopMotor();}

void testForward(){
  if (time_clock < 5){goForward();time_clock += 1;}
  else if (time_clock < 10){goBackward(); time_clock += 1;}
  else {stopMotor();}
  Serial.println(time_clock);
}

void testFeedbackForward(){
  if (time_clock < 50){feedbackForward();time_clock += 1;}
  else if (time_clock < 60){goBackward(); time_clock += 1;}
  else {stopMotor();}
  Serial.println(time_clock);
}

void testleftforward(){}
