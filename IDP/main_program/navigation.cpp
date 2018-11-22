#include "moveRobot.h"

//ports for the side_distance sensor

int absValue(int val){
  if (val > 0){return val;}
  else if (val < 0) {return -1 * val;}
  else {return 0;}
}

int getSidedistance(){
  long duration; int distance_measure;
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
  distance_measure = duration / 29 / 2;
  return distance_measure;
}

int sidenoiseFilter(){
  int temp_dist = getSidedistance();
  while (temp_dist > 250){temp_dist = getSidedistance();}
  return temp_dist;
}

// get distance from the side ultrasound sensor
int getDistance(){
  int temp_dist1 = sidenoiseFilter();
  int temp_dist2 = sidenoiseFilter();
  int temp_dist3 = sidenoiseFilter();
    return (temp_dist1 + temp_dist2 + temp_dist3) / 3;
}

void updateSetdistance(){set_distance = getDistance();}

void updateDiffDist(){
  side_distance1 = getDistance();
  delay(300); //set the dt
  side_distance2 = getDistance();
  diff_distance = side_distance2 - side_distance1;
}

void feedbackSetup(int kp, int kd){
  updateDiffDist();
  if (absValue(diff_distance) < 0){diff_speed=0;}
  else if (absValue(diff_distance) < 15){
    int speed_temp; int abs_speed;int error;
    if (abs(diff_distance) < 3){
      error = side_distance2 - set_distance;
      speed_temp = kd*diff_distance + kp * error;
      abs_speed = absValue(speed_temp);
    }
    else{
      error = side_distance2 - set_distance;
      speed_temp = 0.5*kd*diff_distance + 2*kp * error;
      abs_speed = absValue(speed_temp);
    }
    if (abs_speed < 25){diff_speed = speed_temp;}
    else {diff_speed = 25 * abs_speed / speed_temp;}
  }
  else {diff_speed = 0;}
}

void feedbackDiffSpeed(){feedbackSetup(1, 6);}

int returnBackdistance(){
  long duration; int distance_measure;
  const byte trig = 5;
  const byte echo = 4;

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  distance_measure = duration / 29 / 2;
  back_distance = distance_measure;
  return distance_measure;
}

int noiseFilter(){
  int temp_dist = returnBackdistance();
  while (temp_dist > 230){temp_dist = returnBackdistance();}
  return temp_dist;
}

void updateBackDistance(){
  int temp_dist1 = noiseFilter();
  int temp_dist2 = noiseFilter();
  int temp_dist3 = noiseFilter();
  back_distance = (temp_dist1 + temp_dist2 + temp_dist3) / 3;
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
