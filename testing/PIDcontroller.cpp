#include <Pololu3piPlus32U4.h>
#include "PIDcontroller.h"
using namespace Pololu3piPlus32U4;

PIDcontroller::PIDcontroller(float kp, float ki, float kd, double minOutput, double maxOutput, double clamp_i) {
  _kp = kp;
  _kd = kd;
  _ki = ki;

  _minOutput = minOutput;
  _maxOutput = maxOutput;
  
  _clamp_i = clamp_i;
}

double PIDcontroller::update(double value, double target_value){
  double error = target_value - value;
  double pTerm = _kp * error;
  double dTerm = 0;
  double iTerm = 0;

  _curr_time = millis();

  if (_prev_time) {
    // calculating delta time
    unsigned long dt = _curr_time - _prev_time;

    if (dt > 0) {
      // calculating delta error
      double de = error - _prev_error;

      double derivative = de / dt;
      // error per millisecond
      dTerm = _kd * derivative;

      // error * change in milliseconds
      _error_accum += error * (double)dt;
      _error_accum = constrain(_error_accum, -_clamp_i, _clamp_i);
      iTerm = _ki * _error_accum;
    }
  } 

  double totalOutput = dTerm + iTerm + pTerm;
  _clampOut = constrain(totalOutput, _minOutput, _maxOutput);

  _prev_time = _curr_time;
  _prev_error = error;

  return _clampOut;
}
