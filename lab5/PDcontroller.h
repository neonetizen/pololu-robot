#ifndef PDcontroller_h
#define PDcontroller_h
#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

class PDcontroller{
  public:
    PDcontroller(float kp, float kd, double minOutput, double maxOutput);
    double update(double value, double target_value); //may need to update with additional variables passed in this function
    
  private:
    //Add private variables here
    //Hint: You are adding 4 more variables to the
    //      ones from Pcontroller
    float _kp; // proportional gain
    float _kd; // damping gain (new)

    double _minOutput; // lower clamp bound
    double _maxOutput; // upper clamp bound
    double _target_value; // target value
    double _value; // sensor value
    double _clampOut; // clamped output value
    double _prev_error;

    unsigned long _curr_time; // (new)
    unsigned long _prev_time; // (new)
    
};

#endif
