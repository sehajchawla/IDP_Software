#include "moveRobot.h"

//refresh rate 0.2s, each function has 0.1s refresh rate
void feedbackForward(){feedbackDiffSpeed(); feedForward();}
//void feedbackForward(){PIDloop(); feedForward();}



//last for 0.2*run_time
void runtimeForward(byte run_time){
  for (byte i = 1; i < run_time; i++){feedbackForward();}
}

void yellowReset() {
  Serial.println("yellow mine detected");
  delay(3000); runtimeForward(15); mine = false;}

// void dodgeRed(){
//   if (north == true){
//     leftbackward90(); runtimeForward(10); leftforward90();
//     runtimeForward(15);
//     leftforward90(); rightforward90();
//   }
//   else if (north == false){
//     rightbackward90(); runtimeForward(10); rightforward90();
//     runtimeForward(15); //note 10 is crucial here
//     rightforward90(); leftforward90();
//   }
// }

void dodgeRed(){
  if (north == true){anticlockwise90();}
  else if (north == false){clockwise90();}
  circular_rotation();
}

void redReset(){
  Serial.println("red mine detected");
  delay(1000); Blink(); reportCoordinate(); delay(2000);
  dodgeRed();
  mine = false; red = false;
  //updateSetdistance();
}


void complexForward(){
while (back_distance < 209){
  feedbackForward(); updateBackDistance();
//  if (mine == false){confirmMine(); feedbackForward();updateBackDistance();} //no mine
//  else if (mine == true && red == false){yellowReset(); updateBackDistance();}//yellow mine
//  else if (mine == true && red == true){redReset(); updateBackDistance();} //red mine
}
}

void returnBase(){
  Blink();
  if (north == true){
    //north = false; //make the robot do a anticlockwise180
    centerrotation180(); north = false;
    //while (back_distance < 169) {updateBackDistance(); feedbackForward();}
    getCoordinate(); updateSetdistance(); complexForward(); goBackward();
  }
  rightbackward90(); updateBackDistance(); getCoordinate(); updateSetdistance();
  while (back_distance < 191){updateBackDistance(); feedbackForward();}

  rightbackward90(); updateBackDistance();
  while (back_distance > 23) {gentleReverse();updateBackDistance();}

  stopMotor();
}


void grandTrip(){
  getCoordinate(); updateSetdistance(); complexForward(); goBackward();
  if (x_coordinate < FULL_WIDTH - 15){rotation180(); complexForward(); goBackward();}
  else {returnBase();}
}
