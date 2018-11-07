#ifndef move_h
#define move_h
#include "Arduino.h"

class move{
  public:
    move();
    void goForward(); void goBackwards();
    void rotation180(); void rotation90();
    void stopMotor();
};

#endif
