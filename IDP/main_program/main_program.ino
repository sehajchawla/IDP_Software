#include "moveRobot.h"

//side_distance is the reading obtained from the ultrasond sensor
int time_clock = 0;  int back_distance = 0;
int side_distance2 = 0; int side_distance1 = 0; int diff_distance=0;
int set_distance = 0;

int x_coordinate = 0; int y_coordinate = 0;
float diff_speed;

int minetic=0; int minetoc=0;
bool mine=false; bool red=false;
bool north=true;

void sensor_testing(){
//  for (byte i; i < 5; i++) {tic_mine(); goForward250(); toc_mine();}
//  goBackward2(); Serial.println(" ");
//
//  for (byte i; i < 5; i++) {tic_mine(); goForward300(); toc_mine();}
//  goBackward2(); Serial.println(" ");

  for (byte i; i < 15; i++) {tic_mine(); goForward(); toc_mine();}
  goBackward2(); Serial.println(" ");
  
  for (byte i; i < 10; i++) {tic_mine(); goForward200(); toc_mine();}
  goBackward2(); Serial.println(" ");
}

void setup() {
  //Serial.println("01");
  Serial.begin(9600);           // set up Serial library at 9600 bps
  //Serial.println("12");
  startMotor();
  startBlinkRed();
  startBlinkYellow();
  //PIDSetup();
}

void loop() {
//  rotation180();
//  redReset(); delay(5000); north = false; redReset();
//  caliBackdistance();
//  caliSidedistance();

  //navigation test
//  testabsValue(); //purely software
//  testgetDistance();
//  testupdateDiffDist();
//  testfeedbackSetup(); //purely software, remember to turn off updateDiffDist();
//  testcoordinate();
//
//  //movement test
//  testleftwheel();
//  testrightwheel();
//  testRotation();
//  testmove();
//  testfeedForward();
//  quicktestfeedforward();
//  testdodge();
//  testdodgered();
//
//  //detection test
//  testclassifyMine();
//  testclassifyRed();
//  testconfirmMine();

//  getCoordinate(); updateSetdistance(); updateBackDistance();
//  complexForward(); goBackward(); rotation180();
//  getCoordinate(); updateSetdistance(); updateBackDistance();
//  complexForward(); goBackward(); rotation180();
//  getCoordinate(); updateSetdistance(); updateBackDistance();
//  complexForward(); goBackward(); rotation180();
//  redReset();
//  returnBase();
//  stopMotor();
//  int val = analogRead(A8);
//  Serial.println(val);
//  caliBackdistance();
//  caliSidedistance();
  dispLightSensor();

//  goBackward(); // simple moving BACKWARD algorithm
//  gentleReverse();
//  rotation180(); //will update bool north and clockwise_180
//  delay(2000);
//  rotation180();
//  leftforward90(); delay(5000);
//  rightforward90(); delay(5000);
//  leftbackward90(); delay(5000);
//  rightbackward90();
//
//  circular_rotation();
//  anticlockwise90(); delay(5000);
//  clockwise90(); delay(5000);
//  centerrotation180();
//  grandTrip();

//  sensor_testing();
  sensor_testing();
  stopMotor();



}
