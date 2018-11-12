#include "moveRobot.h"

// purely software
void testabsValue(){
  int val = absValue(-10);
  int val2 = absValue(10);
  Serial.println("expect answer of 10 for both, purely software test");
  Serial.println(val); Serial.println(val2);
}

void testgetDistance(){
  Serial.println("chech the port number, side distance sensor");
  for (byte i = 1; i < 20; i++){
    int test_distance = getDistance();
    Serial.println(test_distance);
    delay(250);
  }
}

void testupdateDiffDist(){
  Serial.println("refresh rate of function 0.2s, return the side distance change in 0.2s");
  for (byte i = 1; i < 20; i++){updateDiffDist(); Serial.println(diff_distance); delay(300);}
}

//purely software
void testfeedbackSetup(){
  Serial.println("this test return the diff_speed, purely software test");
  side_distance1 = 200; side_distance2 = 210; diff_distance = 10;
  feedbackSetup(3); Serial.println("expect an answer of 30"); Serial.println(diff_speed);
  feedbackSetup(10); Serial.println("expect an answer of 50, not 100"); Serial.println(diff_speed);

  side_distance1 = 210; side_distance2 = 200; diff_distance = -10;
  feedbackSetup(3); Serial.println("expect an answer of -30"); Serial.println(diff_speed);
}

void testcoordinate(){
  Serial.println("This test will only work with two sensors functioning")
  side_distance1 = getDistance(); updateBackDistance();
  Serial.println("This is the side distance"); Serial.println(side_distance1);
  Serial.println("This is the back distacne"); Serial.println(back_distance);

  reportCoordinate();
}
