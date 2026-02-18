#include <Pololu3piPlus32U4.h>
#include "Pcontroller.h"
using namespace Pololu3piPlus32U4;

Pcontroller::Pcontroller(float kp, double minOutput, double maxOutput) {
  // initialize the private varaibles from Pcontroller.h here
  _kp = kp;
  _minOutput = minOutput;
  _maxOutput = maxOutput;
  _error = 0;
  _target_value = 0;
  _value = 0;
}

double Pcontroller::update(double value, double target_value){
  //Controller math here
  //Hint: Need to return actuator controller value (_clampOut)
  _error = target_value - value;
  _clampOut = _kp * _error;
  if (_clampOut > _maxOutput) {
    _clampOut = _maxOutput;
  } else if (_clampOut < _minOutput) {
    _clampOut = _minOutput;
  }
  return _clampOut;
}
