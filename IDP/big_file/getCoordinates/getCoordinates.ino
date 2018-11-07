#include "header.h";
void getCoordinates() {
  // put your setup code here, to run once:
  bool north = false;
  float L = 0;
  float B = 0;
  float coordinates[1]; //defines array for coordinates
  if(north == True) {
    coordinates[0] = getUltrasound()[0];
    coordinates[1] = getUltrasound()[1];
  } else {
    coordinates[0] = L - getUltrasound()[0];
    coordinates[1] = B - getUltrasound()[1];
  }
  
  
  return 

}
