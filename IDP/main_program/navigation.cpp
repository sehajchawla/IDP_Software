#include "moveRobot.h"

//ports for the side_distance sensor

int absValue(int val){
  if (val > 0){return val;}
  else if (val < 0) {return -1 * val;}
  else {return 0;}
}

// get distance from the side ultrasound sensor
int getDistance(){
  long duration; int distance_measure;
  const byte trig = 12;
  const byte echo = 11;

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  distance_measure = duration / 29 / 2;
  return distance_measure;
}

void updateDiffDist(){
  side_distance1 = getDistance();
  delay(300); //set the dt
  side_distance2 = getDistance();
  diff_distance = side_distance2 - side_distance1;
}

void feedbackSetup(int kp){
  updateDiffDist();
  if (absValue(diff_distance) < 0){diff_speed=0;}
  else if (absValue(diff_distance) < 15){
    int speed_temp; int abs_speed;
    speed_temp = kp*diff_distance; abs_speed = absValue(speed_temp);
    if (abs_speed < 50){diff_speed = speed_temp;}
    else {diff_speed = 50 * abs_speed / speed_temp;}
  }
  else {diff_speed = 0;}
}

//this function will set the diff_speed, which is crucial for feedForward function
//refresh rate 0.1s due to updateDiffDist()
//void feedbackDiffSpeed(){
//  if (side_distance1 < 40){feedbackSetup(10);}
//  else if (side_distance1 < 80){feedbackSetup(10);}
//  else if (side_distance1 < 120){feedbackSetup(10);}
//  else {feedbackSetup(10);}
//}

void feedbackDiffSpeed(){feedbackSetup(6);}

void updateBackDistance(){
  long duration; int distacne_measure;
  const byte trig = 6;
  const byte echo = 7;

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  distacne_measure = duration / 29 / 2;
  back_distance = distacne_measure;
}

void getCoordinate(){
  side_distance1 = getDistance();
  side_distance2 = getDistance();
  updateBackDistance();
  if (north == true){
    y_coordinate = back_distance;
    x_coordinate = side_distance1;
  }
  else if (north == false){
    y_coordinate = FULL_DEPTH - back_distance;
    x_coordinate = FULL_WIDTH - side_distance1;
}
}

void reportCoordinate(){
  getCoordinate();
  Serial.print("x_coordinate: "); Serial.println(x_coordinate);
  Serial.print("y_coordinate: "); Serial.println(y_coordinate);
}
