#ifndef moveRobot_h
#define moveRobot_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// declare constant
#define TOLERANCE 5
#define FULL_DEPTH 212 //cm
#define FULL_WIDTH 200 //cm

// declare global variables
extern int time_clock; extern int back_distance;
extern int side_distance1; extern int side_distance2; extern int diff_distance;
extern float diff_speed;
extern int x_coordinate; extern int y_coordinate;
extern bool mine; extern bool red;
extern bool north;



// function prototypes
//simple movements
void goForward(); // simple moving forward algorithm, used in dodgeRed()

void feedForward();// moving forward algorithm for the feedback control
// need to be used together with updateDiffDist() in navigation
//refresh rate 0.1s

void goBackward(); // simple moving BACKWARD algorithm
void rotation180(); //will update bool north and clockwise_180

void leftforward90(); void rightforward90();
void leftbackward90(); void rightbackward90();
void stopMotor();
void startMotor(); //used in setup() in main_program



//detectMine
void startBlink(); //used in setup() in main_program
void Blink(); //only blink the LED
byte classifyMine(int sensorValue); //for classifyMine()
byte classifyRed(int sensorValue); //for classifyMine()
void confirmMine(); //vital algorithm for complexForward()



//navigation
int absValue(int val); //return the absolute value
int getDistance(); // get distance from the side ultrasound sensor
void updateDiffDist(); //return change of side distance
void feedbackSetup(int kp); //proportional control; speed = kp * diff_distance
void feedbackDiffSpeed();//this function will set the diff_speed, which is crucial for feedForward function
//refresh rate 0.1s due to updateDiffDist()

void updateBackDistance(); //get distance from back ultrasond sensor
void getCoordinate();
void reportCoordinate();



//complex movements
void feedbackForward(); //refresh rate 0.2s, moving forward with feedback
//this code will not stop the motor

void runtimeForward(byte run_time); //run feedForward() for run_time * 0.2s
void yellowReset(); //procedures after detect yellow mine
void dodgeRed();
void redReset(); //procedures after detecting red mine
void complexForward();
void returnBase();

void grandTrip();


//navigation test
void testabsValue(); //purely software
void testgetDistance();
void testupdateDiffDist();
void testfeedbackSetup(); //purely software
void testcoordinate();

//movement test
void testleftwheel(); void testrightwheel();
void testRotation();
void testmove();
void testfeedForward();
void quicktestfeedforward();

//detection test
void testclassifyMine();
void testclassifyRed();
void testconfirmMine();

void PIDSetup();
void PIDloop();
void PIDUpdateSetpoint();



#endif
