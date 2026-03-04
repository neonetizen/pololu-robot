#ifndef PIDcontroller_h
#define PIDcontroller_h
#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

class PIDcontroller{
  public:
    PIDcontroller(float kp, float ki, float kd, double minOutput, double maxOutput, double clamp_i);
    double update(double value, double target_value);
    
  private:
    float _kp; // proportional gain (output per error)
    float _kd; // derivative gain (output per error per ms)
    float _ki; // integral gain (output per error * millisecond)

    double _minOutput; // lower clamp bound
    double _maxOutput; // upper clamp bound
    double _clampOut; // final clampped output
    double _target_value; // desired setpoint
    double _value; // measured process variable
    double _prev_error; // error from previous update cycle
    double _clamp_i; // maximum magnitude for integral accumulation

    unsigned long _curr_time{ 0 }; // current timestamp in ms
    unsigned long _prev_time{ 0 }; // previous timestamp in ms
    double _error_accum{ 0 }; // accumulated integral term (error * ms)
};

#endif
