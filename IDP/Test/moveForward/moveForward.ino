#include <Wire.h>
#include <Adafruit_MotorShield.h>

//side_distance is the reading obtained from the ultrasond sensor
int time_clock = 0; float side_distance = 0; float back_distance = 0;
//length and width of the table, measured in cm
const int tolerance = 5; const int full_depth = 100; const int full_width = 100;
bool mine=false; bool red=false;
bool clockwise_180=true; bool north=true; bool clockwise_90=false;

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
// You can also make another motor on port M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(4);

// moving forward algorithm
void goForward(int run_time=1){
  Serial.print("moving forward");
  leftMotor->run(FORWARD); rightMotor->run(FORWARD);
  leftMotor->setSpeed(200);  rightMotor->setSpeed(200);
  delay(run_time*1000);
}

void goBackwards(int run_time=1){
  Serial.print("reversing");
  leftMotor->run(BACKWARD); rightMotor->run(BACKWARD);
  leftMotor->setSpeed(50);  rightMotor->setSpeed(50);
  delay(run_time*1000);
}

void rotation180(){
  if (clockwise_180 == true){
    Serial.print("rotating clockwise");
    leftMotor->run(FORWARD); leftMotor->setSpeed(50);
    delay(500); //set motor run time
  }
  else if (clockwise_180 == false){
    Serial.print("rotating anticlockwise");
    rightMotor->run(FORWARD); rightMotor->setSpeed(50);
    delay(500); //set motor run time
  }
}

void rotation90(){
  if (clockwise_90 == true){
    Serial.print("rotating clockwise");
    leftMotor->run(FORWARD); leftMotor->setSpeed(50);
    delay(500); //set motor run time
  }
  else if (clockwise_90 == false){
    Serial.print("rotating anticlockwise");
    rightMotor->run(FORWARD); rightMotor->setSpeed(50);
    delay(500); //set motor run time
  }
}

//stop the motor
void stopMotor(){
  Serial.print("stop");
  leftMotor->run(RELEASE); rightMotor->run(RELEASE);
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  Serial.println("1");
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)
  leftMotor->setSpeed(100); rightMotor->setSpeed(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (time_clock < 5){goForward(2);time_clock += 1;}
  else if (time_clock < 10){goBackwards(); time_clock += 1;}
  else {stopMotor();}
  Serial.println(time_clock);
}
