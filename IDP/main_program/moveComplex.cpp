#include "moveRobot.h"

//refresh rate 0.25s, each function has 0.1s refresh rate
void feedbackForward(){feedbackDiffSpeed(); feedForward();}
void feedbackForward2(){feedbackDiffSpeed(); feedForward2();}
//void feedbackForward(){PIDloop(); feedForward();}


//last for 0.25*run_time
void runtimeForward(byte run_time){
  for (byte i = 1; i < run_time; i++){feedbackForward();}
}

void yellowReset() {
  Serial.println("yellow mine detected");
  tempStopmotor();
  BlinkYellow(); delay(500); runtimeForward(5);
  resetMinedetect();
}

void dodgeRed(){
  if (north == true){rotation_reverse(); anticlockwise90(); circular_rotation(); anticlockwise90();}
  else if (north == false){rotation_reverse(); clockwise90(); circular_rotation(); clockwise90();}
}

void redReset(){
  Serial.println("red mine detected");
  tempStopmotor();
  BlinkRed();
  reportCoordinate();
  delay(2000);
  dodgeRed();
  resetMinedetect();
}


void complexForward(){
  updateBackDistance();
  while (back_distance < 170){
  if (mine == false){tic_mine();feedbackForward();classifyMine();updateBackDistance(); Serial.print("a");} //no mine
  else if (mine == true && red == false ){yellowReset(); updateBackDistance();}//yellow mine
  else {redReset(); updateBackDistance();} //red mine
  }
  while (back_distance < 206){feedbackForward(); updateBackDistance();}
}

void returnBase(){
  if (north == true){
    //north = false; //make the robot do a anticlockwise180
    centerrotation180(); north = false;
    //while (back_distance < 169) {updateBackDistance(); feedbackForward();}
    getCoordinate(); updateSetdistance();
    while (back_distance < 203){feedbackForward(); updateBackDistance();}
    goBackward();
  }
  rightbackward90(); updateBackDistance(); getCoordinate(); updateSetdistance();
  while (back_distance < 190){updateBackDistance(); feedbackForward();}

  rightbackward90(); updateBackDistance();
  while (back_distance > 17) {gentleReverse();updateBackDistance();}

  stopMotor();
}


void grandTrip(){
  getCoordinate(); updateSetdistance(); runtimeForward(10); complexForward(); goBackward(); getCoordinate();
  while (x_coordinate < 171){rotation180(); getCoordinate(); updateSetdistance(); complexForward(); goBackward();getCoordinate();}
  returnBase(); stopMotor();
}
