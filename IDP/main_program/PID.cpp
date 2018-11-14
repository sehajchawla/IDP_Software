#include "moveRobot.h"

#include <PID_v1.h>

#define PIN_INPUT 0
#define RELAY_PIN 6

//Define Variables we'll be connecting to
double PIDSetpoint, Input, Output;

//Define the aggressive and conservative Tuning Parameters
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &PIDSetpoint, consKp, consKi, consKd, DIRECT);


void PIDSetup(){
  PIDSetpoint = getDistance();
  Input = getDistance();
  myPID.SetOutputLimits(-45, 45);
  myPID.SetMode(AUTOMATIC);
}

void PIDloop(){
  Input = getDistance();
  double gap = abs(PIDSetpoint-Input); //distance away from setpoint
  if (gap < 10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID.SetTunings(consKp, consKi, consKd);
  }
  else
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID.SetTunings(aggKp, aggKi, aggKd);
  }

  myPID.Compute();
  diff_speed = Output;
}

void PIDUpdateSetpoint(){PIDSetpoint = getDistance();}
