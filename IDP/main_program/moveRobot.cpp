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
  leftMotor->setSpeed(230-diff_speed);  rightMotor->setSpeed(220+diff_speed);
  delay(1);
  }
  else if (north == false) {
    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(223-diff_speed);  rightMotor->setSpeed(220+diff_speed);
  delay(1);
  }
}

// simple moving BACKWARD algorithm
void goBackward(){
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
  delay(100);
  Serial.print("reversing");
  leftMotor->run(BACKWARD); rightMotor->run(BACKWARD);
  leftMotor->setSpeed(235);  rightMotor->setSpeed(235);
  delay(3000);
}

void gentleReverse(){
  delay(100);
  Serial.print("reversing");
  leftMotor->run(BACKWARD); rightMotor->run(BACKWARD);
  leftMotor->setSpeed(100);  rightMotor->setSpeed(100);
  delay(100);
}

void rotation180(){
  if (north == true){
    Serial.print("rotating clockwise180");
    leftMotor->run(FORWARD); rightMotor->run(RELEASE);
    leftMotor->setSpeed(210);
    delay(5350); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);
    north = false; //set the parameter for the next run
  }
  else if (north == false){
    Serial.print("rotating anticlockwise180");
    rightMotor->run(FORWARD); leftMotor->run(RELEASE);
    rightMotor->setSpeed(210);
    delay(5250); //set motor run time
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

void circular_rotation(){
  if (north == true){
    Serial.print("left wheel circulating");
    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
    leftMotor->setSpeed(225); rightMotor->setSpeed(100);
    delay(7000); //set motor run time
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);

    leftMotor->run(FORWARD); rightMotor->run(FORWARD);
    leftMotor->setSpeed(115); rightMotor->setSpeed(215);
    delay(2900);
    leftMotor->run(RELEASE); rightMotor->run(RELEASE);
  }
  else if (north == false){
    Serial.print("right wheel circulating");
    rightMotor->run(FORWARD); leftMotor->run(FORWARD);
    rightMotor->setSpeed(225); leftMotor->setSpeed(85);
    delay(6000); //set motor run time
    rightMotor->run(RELEASE); leftMotor->run(RELEASE);

    rightMotor->run(FORWARD); leftMotor->run(FORWARD);
    rightMotor->setSpeed(115); leftMotor->setSpeed(215);
    delay(2900);
    rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  }

}

void anticlockwise90(){
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
  delay(100);
  Serial.print("anticlockwise90");
  leftMotor->run(BACKWARD); rightMotor->run(BACKWARD);
  leftMotor->setSpeed(175);  rightMotor->setSpeed(175);
  delay(1400);

  leftMotor->run(BACKWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(175);  rightMotor->setSpeed(175);
  delay(1600);
}

void clockwise90(){
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  delay(100);
  Serial.print("clockwise90");
  rightMotor->run(BACKWARD); leftMotor->run(BACKWARD);
  rightMotor->setSpeed(175);  leftMotor->setSpeed(175);
  delay(1400);

  rightMotor->run(BACKWARD); leftMotor->run(FORWARD);
  rightMotor->setSpeed(175);  leftMotor->setSpeed(175);
  delay(1600);
}

void centerrotation180(){
  Serial.print("center rotation 180");
  rightMotor->run(RELEASE); leftMotor->run(RELEASE);
  rightMotor->run(BACKWARD); leftMotor->run(FORWARD);
  rightMotor->setSpeed(175);  leftMotor->setSpeed(175);
  delay(3000);
}

//stop the motor for good
void stopMotor(){
  Serial.print("stop");
  while (true) {leftMotor->run(RELEASE); rightMotor->run(RELEASE);}
}

void startMotor(){
  Serial.println("Adafruit Motorshield v2 - DC Motor starting!");
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}
