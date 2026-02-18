#ifndef Pcontroller_h
#define Pcontroller_h
#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

class Pcontroller{
  public:
    Pcontroller(float kp, double minOutput, double maxOutput);
    double update(double value, double target_value);     
  private:
    //Add private variables here
    //Hint: There should be 6 variables in total
    float _kp; // proportional gain
    double _minOutput; // lower clamp bound
    double _maxOutput; // upper clamp bound
    double _target_value; // target value
    double _value; // sensor value
    double _clampOut; // clamped output value
};

#endif
