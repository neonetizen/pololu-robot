#ifndef PIDcontroller_h
#define PIDcontroller_h
#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

class PIDcontroller{
  public:
    PIDcontroller(float kp, float ki, float kd, double minOutput, double maxOutput, double clamp_i);
    double update(double value, double target_value);
    
  private:
    /*Add variables from your PDController, then add varaibles for ki, your clamp
    for i component, and accumulated error.*/
    float _kp; // proportional gain
    float _kd; // damping gain
    float _ki;

    double _minOutput; // lower clamp bound
    double _maxOutput; // upper clamp bound
    double _clampOut; // clamped output value
    double _target_value; // target value
    double _value; // sensor value
    double _prev_error;
    double _clamp_i;

    unsigned long _curr_time{ 0 };
    unsigned long _prev_time{ 0 };
    double _error_accum{ 0 };
};

#endif
