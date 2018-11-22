#include "moveRobot.h"

//side_distance is the reading obtained from the ultrasond sensor
int time_clock = 0;  int back_distance = 0;
int side_distance2 = 0; int side_distance1 = 0; int diff_distance=0;
int set_distance = 0;

int x_coordinate = 0; int y_coordinate = 0;
float diff_speed;

int minetic=0; int minetoc=0; int minebase=0; int minemaxdiff=0;
int maxcolour=0; int smallmaxcolour=0;

bool mine=false; bool red=false; bool detection = false;
bool north=true;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  startMotor();
  startBlinkRed();
  startBlinkYellow();
}

void loop() {
  //navigation test
  // testabsValue(); //purely software
  // testgetDistance();
  // testupdateDiffDist();
  // testfeedbackSetup(); //purely software
  // testcoordinate();

  //movement test
  // testleftwheel();
  // testrightwheel();
  // testRotation();
  // testmove();
  // testfeedForward();
  // quicktestfeedforward();
  // testdodge();
  // testdodgered();

  caliSidedistance();
//  caliBackdistance();
//  dispLightSensor();
//  dispLightSensor();

//  delay(5000);
//  grandTrip();
//  dodgeRed();
//  complexForward();
//  delay(500);
//  classifyRed();
//  stopMotor();



}
