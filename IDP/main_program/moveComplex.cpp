#include "moveRobot.h"

//refresh rate 0.2s, each function has 0.1s refresh rate
void feedbackForward(){feedbackDiffSpeed(); feedForward();}

//last for 0.2*run_time
void runtimeForward(byte run_time){
  for (byte i = 1; i < run_time; i++){feedbackForward();}
}

void yellowReset() {
  Serial.println("yellow mine detected");
  delay(3000); runtimeForward(5); mine = false;}

void dodgeRed(){
  if (north == true){
    leftbackward90(); runtimeForward(5); leftforward90();
    runtimeForward(10);
    leftforward90(); rightforward90();
  }
  else if (north == false){
    rightbackward90(); runtimeForward(5); rightforward90();
    runtimeForward(10); //note 10 is crucial here
    rightforward90(); leftforward90();
  }
}

void redReset(){
  Serial.println("red mine detected");
  delay(1000); Blink(); reportCoordinate(); delay(2000);
  dodgeRed();
  mine = false; red = false;
}


void complexForward(){
while (FULL_DEPTH - back_distance < TOLERANCE){
  if (mine == false){confirmMine(); feedbackForward();updateBackDistance();} //no mine
  else if (mine == true && red == false){yellowReset(); updateBackDistance();}//yellow mine
  else if (mine == true && red == true){redReset(); updateBackDistance();} //red mine
}
}

void returnBase(){
  Blink();
  if (north == true){
    north = false; rotation180(); complexForward();
    rightbackward90(); complexForward(); rightbackward90();
  }
  else {rightbackward90(); complexForward(); rightbackward90();}
}


void grandTrip(){
  getCoordinate();
  if (x_coordinate < FULL_WIDTH - 15){complexForward(); goBackward(); rotation180();}
  else {returnBase(); stopMotor();}
}
