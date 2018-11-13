#include "moveRobot.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
// You can also make another motor on port M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);

// moving forward algorithm
void goForward(){
  Serial.print("moving forward");
  leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(200);  rightMotor->setSpeed(200);
  delay(1000);
}

// moving forward algorithm for the feedback control
// need to be used together with updateDiffDist() in navigation
//refresh rate 0.1s
void feedForward(){
  Serial.println("moving forward with feedback");
  // leftMotor->run(RELEASE); rightMotor->run(RELEASE); //this line is used to refresh the motor
  if (north == true){
    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(205-diff_speed);  rightMotor->setSpeed(200+diff_speed);
  delay(1);
  }
  else if (north == false) {
    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(212-diff_speed);  rightMotor->setSpeed(200+diff_speed);
  delay(1);
  }
}

// simple moving BACKWARD algorithm
void goBackward(){
  Serial.print("reversing");
  leftMotor->run(BACKWARD); rightMotor->run(BACKWARD);
  leftMotor->setSpeed(150);  rightMotor->setSpeed(150);
  delay(4000);
}

void rotation180(){
  if (north == true){
    Serial.print("rotating clockwise180");
    leftMotor->run(FORWARD); rightMotor->run(RELEASE);
    leftMotor->setSpeed(175);
    delay(6500); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);
    north = false; //set the parameter for the next run
  }
  else if (north == false){
    Serial.print("rotating anticlockwise180");
    rightMotor->run(FORWARD); leftMotor->run(RELEASE);
    rightMotor->setSpeed(175);
    delay(6500); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);
    north = true;
  }
}

void leftforward90(){
  Serial.print("left wheel advancing 90");
  leftMotor->run(FORWARD); rightMotor->run(RELEASE);
  leftMotor->setSpeed(150);
  delay(3900); //set motor run time
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
  delay(3900); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}

void rightbackward90(){
  Serial.print("right wheel advancing 90");
  rightMotor->run(BACKWARD); leftMotor->run(RELEASE);
  rightMotor->setSpeed(150);
  delay(3900); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}


//stop the motor for good
void stopMotor(){
  Serial.print("stop");
  while (true) {leftMotor->run(RELEASE); rightMotor->run(RELEASE);}
}

void startMotor(){
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}
