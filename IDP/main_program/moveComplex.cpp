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
  BlinkYellow(); delay(2000); runtimeForward(15); mine = false; detection = false;
  minetic = 0; minetoc = 0; minebase = 0; minemaxdiff = 0;
}

void dodgeRed(){
  if (north == true){rotation_reverse(); anticlockwise90(); circular_rotation(); anticlockwise90();}
  else if (north == false){rotation_reverse(); clockwise90(); circular_rotation(); clockwise90();}
}

void redReset(){
  Serial.println("red mine detected");
  tempStopmotor();
  BlinkRed(); reportCoordinate(); delay(2000);
  dodgeRed();
  mine = false; red = false; detection = false;
  minetic = 0; minetoc = 0; minebase = 0; minemaxdiff = 0;
  //updateSetdistance();
}


void complexForward(){
  updateBackDistance();
  while (back_distance < 100){
//    feedbackForward(); updateBackDistance();
  if (mine == false){tic_mine();feedbackForward();classifyMine();updateBackDistance();} //no mine
  else if (mine == true && detection == false){classifyRed();}
  else if (mine == true && red == false && detection == true){yellowReset(); updateBackDistance();}//yellow mine
  else if (mine == true && red == true && detection == true){redReset(); updateBackDistance();} //red mine


}
}

void returnBase(){
  BlinkYellow(); BlinkRed();
  if (north == true){
    //north = false; //make the robot do a anticlockwise180
    centerrotation180(); north = false;
    //while (back_distance < 169) {updateBackDistance(); feedbackForward();}
    getCoordinate(); updateSetdistance(); complexForward(); goBackward();
  }
  rightbackward90(); updateBackDistance(); getCoordinate(); updateSetdistance();
  while (back_distance < 197){updateBackDistance(); feedbackForward();}

  rightbackward90(); updateBackDistance();
  while (back_distance > 17) {gentleReverse();updateBackDistance();}

  stopMotor();
}


void grandTrip(){
  getCoordinate(); updateSetdistance(); complexForward(); goBackward(); getCoordinate();
  while (x_coordinate < 171){rotation180(); complexForward(); goBackward();getCoordinate();}
  returnBase(); stopMotor();
}
