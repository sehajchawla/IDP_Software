#include "moveRobot.h"

//refresh rate 0.2s, each function has 0.1s refresh rate
void feedbackForward(){feedbackDiffSpeed(); feedForward();}

//last for 0.2*run_time
void runtimeForward(byte run_time){
  for (byte i = 1, i < run_time, i++){feedbackForward();}
}

void yellowReset() {runtimeForward(5); mine = false;}

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
  delay(1000); Blink(); reportCoordinate(); delay(2000);
  dodgeRed();
  mine = false; red = false;
}


void complexForward(){
while (FULL_DEPTH - back_distance < TOLERANCE){
  if (mine == false){classifyMine(); feedbackForward();} //no mine
  else if (mine == true && red == falsefeedbackForward();){delay(3000); yellowReset();} //yellow mine
  else if (mine == true && red == true){redReset();} //red mine
}
}
