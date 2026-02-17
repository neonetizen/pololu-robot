#include <Pololu3piPlus32U4.h>
#include <Pololu3piPlus32U4IMU.h>
#include "odometry.h"
#include "printOLED.h"
using namespace Pololu3piPlus32U4;

#define PI 3.14159

PrintOLED printOLED;

Odometry::Odometry(float diaL, float diaR, float w, int nL, int nR, int gearRatio, bool dead_reckoning){
  _diaL = diaL;
  _diaR = diaR;
  _w = w;
  _nL = nL;
  _nR = nR;
  _gearRatio = gearRatio;
  _deadreckoning = dead_reckoning;

  _x = 0;
  _y = 0;
  _theta = 0;

  _left_encoder_counts_prev = 0;
  _right_encoder_counts_prev = 0;
  _lastUpdateTime = millis();

  if(_deadreckoning){ // if using dead reckoning, initialize and calibrate IMU
    Wire.begin();
    _imu.init();
    _imu.enableDefault();

    //calibrate IMU
    int total = 0;
    for (int i = 0; i < 100; i++)
    {
      _imu.readGyro();
      total += _imu.g.z;
      delay(1);
    }
    _IMUavg_error = total / 100;  
  }
}

// USE ODOMETRY FORMULAS TO CALCULATE ROBOT'S NEW POSITION AND ORIENTATION
void Odometry::update_odom(int left_encoder_counts, int right_encoder_counts, float &x, float &y, float &theta){
  int delta_L = left_encoder_counts - _left_encoder_counts_prev;
  int delta_R = right_encoder_counts - _right_encoder_counts_prev;

  float dist_per_count_L = (PI * _diaL) / ((float)(_nL * _gearRatio));
  float dist_per_count_R = (PI * _diaR) / ((float)(_nR * _gearRatio));
  float delta_s_L = delta_L * dist_per_count_L;
  float delta_s_R = delta_R * dist_per_count_R;

  float delta_theta;
  // IF USING dead reckoning, GET THE ANGLE _theta FROM IMU
  if (_deadreckoning) {
    _imu.readGyro();
    unsigned long now = millis();
    float dt = (now - _lastUpdateTime) / 1000.0f;
    _lastUpdateTime = now;
    float angleRate_rads = (_imu.g.z - _IMUavg_error) * 0.001f * (PI / 180.0f);
    delta_theta = angleRate_rads * dt;
  } else {
    // OTHERWISE, CALCULATE THE ANGLE _theta FROM ENCODERS DATA BASED ON THE FORMULA FROM THE LECTURES
    delta_theta = (delta_s_R - delta_s_L) / _w;
  }

  _theta += delta_theta;

  float delta_s = (delta_s_L + delta_s_R) / 2.0f;
  // CALCULATE _x BASED ON THE FORMULA FROM THE LECTURES
  _x += delta_s * cos(_theta);
  // CALCULATE _y BASED ON THE FORMULA FROM THE LECTURES
  _y += delta_s * sin(_theta);

  // CALCULATE CUMULATIVE x, AND CUMULATIVE y. 
  //AKA UPDATE THE VALUE OF &x AND &y (THE PARAMETERS OF THE update_odom FUNCTIONS, WHICH ARE PASSED BY REFERENCE)
  //REMINDER: CUMULATIVE theta IS EQUAL TO _theta.
  x = _x;
  y = _y;
  // PRINT THE x, y, theta VALUES ON OLED
  theta = _theta;
  // PRINT THE x, y, theta VALUES ON SERIAL MONITOR
  Serial.print(" x:  ");
  Serial.println(x);
  Serial.println(" y:  ");
  Serial.println(y);
  Serial.print(" theta:  ");
  Serial.println(theta);

  // Save the current encoder values as the "previous" values, so you can use it in the next iteration
  _left_encoder_counts_prev = left_encoder_counts;
  _right_encoder_counts_prev = right_encoder_counts;
}
