#include "moveRobot.h"

// expect to rotate 180 degree, adjust motor run time if not
void testleftwheel(){leftforward90();}
void testrightwheel(){rightbackward90();}

void testRotation(){
  Serial.println("the robot should rotation clockwise180 and then anticlockwise180")
  rotation180(); rotation180(); delay(1000);

  Serial.println("then it should run anti180 and clockwise180")
  north == false;
  rotation180(); rotation180();
}

void testmove(){
  Serial.println("this robot will move forward and backward")
  if (time_clock < 5){goForward();time_clock += 1;}
  else if (time_clock < 10){goBackward(); time_clock += 1;}
  else {stopMotor();}
  Serial.println(time_clock);
}

void testfeedForward(){
  Serial.println("feedForward() does not have motor run(RELEASE), this could be a problem")
  diff_speed = 35; Serial.println("the leftMotor should be slower");
  feedForward(); delay(4000);

  diff_speed = -35; Serial.println("the rightMotor should be slower");
  feedForward(); delay(4000);

  stopMotor();
}

void quicktestfeedforward(){
  Serial.println("this test is designed to change the motor speed quickly");
  for (byte i; i < 5; i++){
    diff_speed = 10; feedForward(); delay(300);
    diff_speed = 45; feedForward(); delay(300);
    diff_speed = -30; feedForward(); delay(300);
    diff_speed = 45; feedForward(); delay(300);
    diff_speed = 0; feedForward(); delay(300);
  }
  stopMotor();
}
