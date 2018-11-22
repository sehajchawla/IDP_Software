#include "moveRobot.h"

void caliSidedistance(){
  for (byte i; i < 5; i++){
    int side_dist = getDistance();
    //Serial.println("here is the side distance: ");
    Serial.println(side_dist);
  }
}

void caliBackdistance(){
  for (byte i; i < 5; i++){
    updateBackDistance();
    //Serial.println("Here is the back distance: ");
    Serial.println(back_distance);
  }
}

void dispLightSensor(){
//for (byte i; i < 10000; i++)
//  while (true){}
  int val1 = analogRead(A9); int val2 = analogRead(A10);
  int val3 = analogRead(A11); int val4 = analogRead(A12);
  int val5 = analogRead(A13);
  int sum_all = val1 + val2 + val3 + val4 + val5;
  Serial.print(val1); Serial.print(" ");
  Serial.print(val2); Serial.print(" ");
  Serial.print(val3); Serial.print(" ");
  Serial.print(val4); Serial.print(" ");
  Serial.print(val5); Serial.print("   ");
  Serial.println(sum_all);
  delay(200);
}

void caliLightRange(){
  int val = analogRead(A0);
  int min1 = val - 3; int max1 = val + 3;

  for (byte i; i < 200; i++){
    val = analogRead(A0);

    if (val < min1 * 0.2) {delay(1);}
    else if (val > max1 * 3) {delay(1);}
    else if (val < min1){min1 = val;}
    else if (val > max1) {max1 = val;}
    else {delay(1);}
  }

  Serial.println("Here is the min value :");
  Serial.println(min1);
  Serial.println("Here is the max value: ");
  Serial.println(max1);
}
