#ifndef moveRobot_h
#define moveRobot_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// declare constant
#define TOLERANCE 5
#define FULL_DEPTH 210 //cm
#define FULL_WIDTH 225 //cm

// declare global variables
extern int time_clock; extern int back_distance;
extern int side_distance1; extern int side_distance2; extern int diff_distance;
extern int set_distance;
extern float diff_speed;
extern int x_coordinate; extern int y_coordinate;
extern bool mine; extern bool red; extern bool detection;
extern bool north;
extern int minetic; extern int minetoc; extern int minebase; extern int minemaxdiff;
extern int maxcolour; extern int smallmaxcolour;



// function prototypes

//calibration
void caliSidedistance();
void caliBackdistance();
void dispLightSensor();
void caliLightRange();

//simple movements
void goForward(); // simple moving forward algorithm, used in dodgeRed()

void feedForward();// moving forward algorithm for the feedback control
// need to be used together with updateDiffDist() in navigation
//refresh rate 0.1s

void goBackward(); // simple moving BACKWARD algorithm
void gentleReverse();
void rotation180(); //will update bool north and clockwise_180
void leftforward90(); void rightforward90();
void leftbackward90(); void rightbackward90();

void circular_rotation(); void rotation_reverse();
void anticlockwise90(); void clockwise90();

void centerrotation180();
void detection_rotation1(); void detection_rotation2();
void stopMotor();
void tempStopmotor();
void startMotor(); //used in setup() in main_program
void feedForward2();



//detectMine
void startBlinkRed(); //used in setup() in main_program
void BlinkRed(); //only blink the LED
void startBlinkYellow(); //used in setup() in main_program
void BlinkYellow(); //only blink the LED
void resetMinedetect();
int getColourvalue();
void updateMaxcolour();
void tic_mine();
void classifyMine();
void updateMinemaxdiff();
void classifyRed();



//navigation
int absValue(int val); //return the absolute value
int getSidedistance();
int sidenoiseFilter();
int getDistance(); // get distance from the side ultrasound sensor
void updateSetdistance();
void updateDiffDist(); //return change of side distance
void feedbackSetup(int kp, int kd); //proportional control; speed = kp * diff_distance
void feedbackDiffSpeed();//this function will set the diff_speed, which is crucial for feedForward function
//refresh rate 0.1s due to updateDiffDist()

int returnBackdistance();
int noiseFilter(); //filter out large noise that is not correct
void updateBackDistance(); //get distance from back ultrasond sensor
void getCoordinate();
void reportCoordinate();



//complex movements
void feedbackForward(); //refresh rate 0.2s, moving forward with feedback
void feedbackForward2();
//this code will not stop the motor

void runtimeForward(byte run_time); //run feedForward() for run_time * 0.2s
void yellowReset(); //procedures after detect yellow mine
void dodgeRed();
void redReset(); //procedures after detecting red mine
void complexForward();
void complexForward2();
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
void testdodge();
void testdodgered();



#endif
