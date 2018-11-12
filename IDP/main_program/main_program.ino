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
}

void loop() {
  //navigation test
  void testabsValue(); //purely software
  void testgetDistance();
  void testupdateDiffDist();
  void testfeedbackSetup(); //purely software
  void testcoordinate();

  //movement test
  void testleftwheel();
  void testrightwheel();
  void testmove();
  void testfeedForward();
  void quicktestfeedforward();

  //detection test
  void testclassifyMine();
  void testclassifyRed();
  void testconfirmMine();
}
