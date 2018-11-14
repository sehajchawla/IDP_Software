#include "moveRobot.h"

//side_distance is the reading obtained from the ultrasond sensor
int time_clock = 0;  int back_distance = 0;
int side_distance2 = 0; int side_distance1 = 0; int diff_distance=0;
int x_coordinate = 0; int y_coordinate = 0;
float diff_speed;

bool mine=false; bool red=false;
bool north=true;

void setup() {
  //Serial.println("01");
  Serial.begin(9600);           // set up Serial library at 9600 bps
  //Serial.println("12");
  startMotor();
  startBlink();
  PIDSetup();
}

void loop() {
//  rotation180();
  //navigation test
//  testabsValue(); //purely software
//  testgetDistance();
//  testupdateDiffDist();
//  testfeedbackSetup(); //purely software
//  testcoordinate();
//
//  //movement test
//  testleftwheel();
//  testrightwheel();
//  testRotation();
//  testmove();
//  testfeedForward();
//  quicktestfeedforward();
//
//  //detection test
//  testclassifyMine();
//  testclassifyRed();
//  testconfirmMine();
//  PIDUpdateSetpoint();

  getCoordinate();
  complexForward(); goBackward(); rotation180();
  getCoordinate();
  complexForward(); goBackward(); rotation180();
  getCoordinate(); 
  complexForward(); goBackward(); rotation180();
//  redReset();

  stopMotor();
}
