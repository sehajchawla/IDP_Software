#include "moveRobot.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);

// moving forward algorithm
void goForward(){
  leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(200);  rightMotor->setSpeed(200);
  delay(200);
}

// moving forward algorithm for the feedback control
// need to be used together with updateDiffDist() in navigation
//refresh rate 0.1s
void feedForward(){
  // leftMotor->run(RELEASE); rightMotor->run(RELEASE); //this line is used to refresh the motor
  if (north == true){
    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
    leftMotor->setSpeed(200-diff_speed);  rightMotor->setSpeed(200+diff_speed);
    delay(1);
  }
  else if (north == false) {
    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
    leftMotor->setSpeed(200-diff_speed);  rightMotor->setSpeed(200+diff_speed);
    delay(1);
  }
}

// simple moving BACKWARD algorithm
void goBackward(){
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
  //Serial.print("reversing");
  leftMotor->run(BACKWARD); rightMotor->run(BACKWARD);
  leftMotor->setSpeed(235);  rightMotor->setSpeed(235);
  delay(2000);
}

void gentleReverse(){
  delay(50);
  leftMotor->run(BACKWARD); rightMotor->run(BACKWARD);
  leftMotor->setSpeed(100);  rightMotor->setSpeed(100);
  delay(50);
}

void rotation180(){
  if (north == true){
    //Serial.print("rotating clockwise180");
    leftMotor->run(FORWARD); rightMotor->run(RELEASE);
    leftMotor->setSpeed(210);
    delay(5000); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);
    north = false; //set the parameter for the next run
  }
  else if (north == false){
    //Serial.print("rotating anticlockwise180");
    rightMotor->run(FORWARD); leftMotor->run(RELEASE);
    rightMotor->setSpeed(210);
    delay(5100); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);
    north = true;
  }
}

void leftforward90(){
  Serial.print("left wheel advancing 90");
  leftMotor->run(FORWARD); rightMotor->run(RELEASE);
  leftMotor->setSpeed(150);
  delay(3600); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}

void rightforward90(){
  Serial.print("right wheel advancing 90");
  rightMotor->run(FORWARD); leftMotor->run(RELEASE);
  rightMotor->setSpeed(150);
  delay(3900); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}

void leftbackward90(){
  Serial.print("left wheel reversing 90");
  leftMotor->run(BACKWARD); rightMotor->run(RELEASE);
  leftMotor->setSpeed(150);
  delay(3700); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}

void rightbackward90(){
  Serial.print("right wheel advancing 90");
  rightMotor->run(BACKWARD); leftMotor->run(RELEASE);
  rightMotor->setSpeed(150);
  delay(3700); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}

void rotation_reverse(){
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  delay(100);
  //Serial.print("clockwise90");
  rightMotor->run(BACKWARD); leftMotor->run(BACKWARD);
  rightMotor->setSpeed(175);  leftMotor->setSpeed(175);
  delay(1400);
}

//for dodgeRed()
void anticlockwise90(){
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  leftMotor->run(BACKWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(175);  rightMotor->setSpeed(175);
  delay(1600);
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
}

void clockwise90(){
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  rightMotor->run(BACKWARD); leftMotor->run(FORWARD);
  rightMotor->setSpeed(175);  leftMotor->setSpeed(175);
  delay(1600);
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
}

void circular_rotation(){
  if (north == true){
    //Serial.print("left wheel circulating");
    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
    leftMotor->setSpeed(225); rightMotor->setSpeed(100);
    delay(7600); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);

    // leftMotor->run(FORWARD); rightMotor->run(FORWARD);
    // leftMotor->setSpeed(115); rightMotor->setSpeed(215);
    // delay(2900);
    // leftMotor->run(RELEASE); rightMotor->run(RELEASE);
  }
  else if (north == false){
    //Serial.print("right wheel circulating");
    rightMotor->run(FORWARD); leftMotor->run(FORWARD);
    rightMotor->setSpeed(225); leftMotor->setSpeed(85);
    delay(7600); //set motor run time
    rightMotor->run(RELEASE); leftMotor->run(RELEASE);

    // rightMotor->run(FORWARD); leftMotor->run(FORWARD);
    // rightMotor->setSpeed(115); leftMotor->setSpeed(215);
    // delay(3000);
    // rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  }

}

void centerrotation180(){
  //Serial.print("center rotation 180");
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  rightMotor->run(BACKWARD); leftMotor->run(FORWARD);
  rightMotor->setSpeed(175);  leftMotor->setSpeed(175);
  delay(3000);
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
}

void detection_rotation1(){
  //rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  rightMotor->run(BACKWARD); leftMotor->run(FORWARD);
  rightMotor->setSpeed(100);  leftMotor->setSpeed(100);
  delay(5);
}

void detection_rotation2(){
  //rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  leftMotor->run(BACKWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(100);  rightMotor->setSpeed(100);
  delay(5);
}

//stop the motor for good
void stopMotor(){
  Serial.print("stop");
  while (true) {leftMotor->run(RELEASE); rightMotor->run(RELEASE);}
}

void tempStopmotor(){leftMotor->run(RELEASE); rightMotor->run(RELEASE);}

void startMotor(){
  Serial.println("Adafruit Motorshield v2 - DC Motor starting!");
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}

void feedForward2(){
  //Serial.println("moving forward with feedback");
  // leftMotor->run(RELEASE); rightMotor->run(RELEASE); //this line is used to refresh the motor
  if (north == true){
    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(112-diff_speed);  rightMotor->setSpeed(100+diff_speed);
  delay(1);
  }
  else if (north == false) {
  leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(125-diff_speed);  rightMotor->setSpeed(120+diff_speed);
  delay(1);
  }
}
