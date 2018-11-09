#include "moveRobot.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
// You can also make another motor on port M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(4);

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
  Serial.print("moving forward with feedback");
  leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(200-diff_speed);  rightMotor->setSpeed(200+diff_speed);
  delay(100);
}

// simple moving BACKWARD algorithm
void goBackward(){
  Serial.print("reversing");
  leftMotor->run(BACKWARD); rightMotor->run(BACKWARD);
  leftMotor->setSpeed(100);  rightMotor->setSpeed(100);
  delay(1000);
}

void rotation180(){
  if (north == true){
    Serial.print("rotating clockwise180");
    leftMotor->run(FORWARD); rightMotor->run(RELEASE);
    leftMotor->setSpeed(50);
    delay(500); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);
    north == false; //set the parameter for the next run
  }
  else if (north == false){
    Serial.print("rotating anticlockwise180");
    rightMotor->run(FORWARD); leftMotor->run(RELEASE);
    rightMotor->setSpeed(50);
    delay(500); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);
    north == true;
  }
}

void leftforward90(){
  Serial.print("left wheel advancing 90");
  leftMotor->run(FORWARD); rightMotor->run(RELEASE);
  leftMotor->setSpeed(50);
  delay(250); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}

void rightforward90(){
  Serial.print("right wheel advancing 90");
  rightMotor->run(FORWARD); leftMotor->run(RELEASE);
  rightMotor->setSpeed(50);
  delay(250); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}

void leftbackward90(){
  Serial.print("left wheel reversing 90");
  leftMotor->run(BACKWARD); rightMotor->run(RELEASE);
  leftMotor->setSpeed(50);
  delay(250); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}

void rightbackward90(){
  Serial.print("right wheel advancing 90");
  rightMotor->run(BACKWARD); leftMotor->run(RELEASE);
  rightMotor->setSpeed(50);
  delay(250); //set motor run time
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
}


//stop the motor
void stopMotor(){
  Serial.print("stop");
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
  delay(1000);
}

void startMotor(){
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}
