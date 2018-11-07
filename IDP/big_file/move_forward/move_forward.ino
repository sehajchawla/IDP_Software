#include <Wire.h>
#include <Adafruit_MotorShield.h>

//distance measured in cm
int time_clock = 0; side_distance = 0; back_distance = 0;
const tolerance = 5;
bool mine; red; clockwise_180; north;

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *rightMotor2 = AFMS.getMotor(2);

// moving forward algorithm
void forward(){
  uint8_t i;
  Serial.print("moving forward");

  leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(100);  rightMotor->setSpeed(100);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)
  leftMotor->setSpeed(150); rightMotor2->setSpeed(150);
}

void loop() {
  // put your main code here, to run repeatedly:

}
