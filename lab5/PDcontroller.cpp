#include <Pololu3piPlus32U4.h>
#include "PDcontroller.h"
using namespace Pololu3piPlus32U4;

PDcontroller::PDcontroller(float kp, float kd, double minOutput, double maxOutput) {
  // initialize the private varaibles from Pcontroller.h here
  _kp = kp;
  _kd = kd;
  _minOutput = minOutput;
  _maxOutput = maxOutput;
  _curr_time = nullptr;
  _prev_time = nullptr;
}

double PDcontroller::update(double value, double target_value){
  //Controller math here
  /*Hints: To add damping (derivative), you must have something to
           keep track of time for the rate of change.
           
           Also note that the first time PD controller is ran, we only have
           the P component, so consider using an if-else statement.

           Again, you need to return actuator controller value (_clampOut)
  */
  _curr_time = millis();
  double error = target_value - value;
  double dTerm = 0;
  double pTerm = 0;

  // TODO: finish PD calculation
  if (_prev_time > 0) {
    double delta_error = error - _prev_error;
    unsigned long delta_time = _curr_time - _prev_time;

    if(delta_time > 0) {
      double derivative = delta_error/delta_time;
      dTerm = _kd * derivative;
    }
  } else {
    pTerm = _kp * error;
  }

  double totalOutput = dTerm + pTerm;
  _clampOut(totalOutput, _minOutput, _maxOutput);

  _prev_time = _curr_time;
  _prev_error = error;

  return _clampOut;
}