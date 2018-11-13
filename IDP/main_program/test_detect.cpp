#include "moveRobot.h"

void testclassifyMine(){
  Serial.println("it should return 1");
  Serial.println(classifyMine(150));
  Serial.println(classifyMine(350));

  Serial.println("it should return 0");
  Serial.println(classifyMine(50));
}

void testclassifyRed(){
  Serial.println("it should return 1; saying a red is detected");
  Serial.println(classifyRed(150));
  Serial.println("should be 0");
  Serial.println(classifyRed(350));
}

void testconfirmMine(){
  int val1 = 150; int val2 = 150;
  int val3 = 0; int val4 = 0; int val5 = 0;

  byte mine1 = classifyMine(val1); byte mine2 = classifyMine(val2);
  byte mine3 = classifyMine(val3); byte mine4 = classifyMine(val4);
  byte mine5 = classifyMine(val5);
  byte mine_sum; mine_sum = mine1 + mine2 + mine3 + mine4 + mine5;

  if (mine_sum > 0 && mine_sum < 3){mine  = true;}
  else {mine = false;}

  if (mine == true){
    byte red1 = classifyRed(val1); byte red2 = classifyRed(val2);
    byte red3 = classifyRed(val3); byte red4 = classifyRed(val4);
    byte red5 = classifyRed(val5);
    byte red_sum; red_sum = red1 + red2 + red3 + red4 + red5;
    if (red_sum > 0 && red_sum < 3) {red = true;}
    else {red = false;}
  }

  Serial.println("expect both mine and red to be true");
  Serial.println(mine); Serial.println(red);
}
