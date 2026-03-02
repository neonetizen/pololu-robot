#include <Pololu3piPlus32U4.h>
#include "PIDcontroller.h"
using namespace Pololu3piPlus32U4;

PIDcontroller::PIDcontroller(float kp, float ki, float kd, double minOutput, double maxOutput, double clamp_i) {
  /*Initialize values by copying and pasting from PD controller, then declaring for
  the three new variables.*/
  _kp = kp;
  _kd = kd;
  _ki = ki;

  _minOutput = minOutput;
  _maxOutput = maxOutput;
  
  _clamp_i = clamp_i;
}

double PIDcontroller::update(double value, double target_value){
  /*Now copy and paste your PD controller. To implement I component,
  keep track of accumulated error, use your accumulated error in the constrain
  function for the integral, multiply ki by your integral, then add your p, d,
  and i components.
  
  Note: Do not just put all of the integral code at the end of PD component. Think
  about step by step how you can integrate these parts into your PDController
  code.*/
  double error = target_value - value;
  double dTerm = 0;
  double pTerm = 0;

  _curr_time = millis();
  if (_prev_time) {
    unsigned long delta_time = _curr_time - _prev_time;
    double delta_error = error - _prev_error;
    double derivative = delta_error/delta_time;
    
    dTerm = _kd * derivative;
  }

  pTerm = _kp * error;

  double totalOutput = dTerm + pTerm;

  _clampOut = constrain(totalOutput, _minOutput, _maxOutput);
  _prev_time = _curr_time;
  _prev_error = error;

  return _clampOut;
}
