#include "moveRobot.h"

//ports for the side_distance sensor

int absValue(int val){
  if (val > 0){return val;}
  else if (val < 0) {return -1 * val;}
  else {return 0;}
}

// get distance from the side ultrasound sensor
int getDistance(){
  long duration; int distacne_measure;
  const byte trig = 0;
  const byte echo = 1;

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  distacne_measure = duration / 29 / 2;
  return distacne_measure;
}

void updateDiffDist(){
  int absDifference; int different_speed;
  side_distance1 = getDistance();
  delay(100); //set the dt
  side_distance2 = getDistance();
  diff_distance = side_distance2 - side_distance1;
}

void feedbackSetup(int dist, int kp){
  if (absValue(diff_distance) < 0.05 * side_distance1){diff_speed=0;}
  else if (absValue(diff_distance) < 0.7 * side_distance1){
    int speed_temp; int abs_speed;
    speed_temp = kp*diff_distance; abs_speed = absValue(speed_temp);
    if (abs_speed < 50){diff_speed = speed_temp;}
    else {diff_speed = 50;}
  }
  else {diff_speed = 0;}
}

//this function will set the diff_speed, which is crucial for feedForward function
//refresh rate 0.1s due to updateDiffDist()
void feedbackDiffSpeed(){
  updateDiffDist();
  if (side_distance1 < 40){feedbackSetup(side_distance1, 10);}
  else if (side_distance1 < 80){feedbackSetup(side_distance1, 8);}
  else if (side_distance1 < 120){feedbackSetup(side_distance1, 6);}
  else {feedbackSetup(side_distance1, 4);}
}

void updateBackDistance(){
  long duration; int distacne_measure;
  const byte trig = 3;
  const byte echo = 2;

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
