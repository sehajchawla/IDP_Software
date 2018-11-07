#ifndef moveRobot_h
#define moveRobot_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// declare constant
#define TOLERANCE 5;
#define FULL_DEPTH 100; //cm
#define FULL_WIDTH 100; //cm

// declare global variables
extern int time_clock; extern float side_distance; extern float back_distance;
extern bool mine; extern bool red;
extern bool clockwise_180; extern bool north; extern bool clockwise_90;

// function prototypes
void goForward(int run_time=1);
void goBackward(int run_time=1);
void rotation180();
void rotation90();
void stopMotor();
void startMotor();

#endif
