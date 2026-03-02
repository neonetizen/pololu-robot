#include <Pololu3piPlus32U4.h>
#include "printOLED.h"
#include "PIDcontroller.h"
//#include "odometry.h" //If using odometry, import odometry.h and odometry.cpp
#include "PDcontroller.h" //Import your PDcontroller.h and PDcontroller.cpp then uncomment
using namespace Pololu3piPlus32U4;

Motors motors;
Encoders encoders;

//Odometry Parameters
#define diaL 3.2
#define diaR  3.2
#define nL 12
#define nR 12
#define w 9.6
#define gearRatio 75
#define DEAD_RECKONING false

//Update kp, kd, and ki based on your testing
#define minOutput -100
#define maxOutput 100
#define kp ... //Tune Kp here
#define kd ... //Tune Kd here
#define ki ... //Tune Ki here
#define clamp_i ... //Tune ki integral clamp here
#define base_speed 50

//Odometry odometry(diaL, diaR, w, nL, nR, gearRatio, DEAD_RECKONING); //Uncomment if using odometry class
//PDcontroller pdcontroller(kp, kd, minOutput, maxOutput); //Uncomment when using PDController
//PIDcontroller pidcontroller(kp, ki, kd, minOutput, maxOutput, clamp_i); //Uncomment after you implement PIDController

//Feel free to use this in your PD/PID controller for target values
// Given goals in cm and radians
const float goal_theta = ... // Must put in radians

//odometry
int16_t deltaL=0, deltaR=0;
int16_t encCountsLeft = 0, encCountsRight = 0;
float x, y, theta;

//controller 
//Lab 6
//Note: Here are some suggested variables to use for your code.
double PDout, PIDout; //Output variables for your controllers

void setup() {
  Serial.begin(9600);
}

void loop() {

  //Use this code if you are using odometry. Comment out if you are not.
  //If using, consider turning this into its own function for repeated use.
  // Read data from encoders
  deltaL = encoders.getCountsAndResetLeft();
  deltaR = encoders.getCountsAndResetRight();

  // Increment total encoder cound
  encCountsLeft += deltaL;
  encCountsRight += deltaR;  

  odometry.update_odom(encCountsLeft,encCountsRight, x, y, theta); //calculate robot's position




  //Lab 6
  //Note: To help with testing, print the theta and PD/PID outputs to serial monitor.

  /*TASK 2.1
  Move your PDController.h and PDController.cpp files here to use for task 2.2.
  Also move your odometry.h and odometry.cpp if you decide to use it for 
  measuring the angle of your robot.*/
  int16_t left = constrain(calculateLeft(PDout / MM_TO_CM) - right_overflow, -400, 400);
  int16_t right = constrain(calculateRight(PDout / MM_TO_CM) - left_overflow, -400, 400);

  Serial.println("Left: ");
  Serial.print(left);
  Serial.println("Right: ");
  Serial.print(right);

  motors.setSpeeds(left, right);
  
  /*TASK 2.2
  Utilize your PDController to go to angles PI, PI/2, and PI/2.
  Write your code below and comment out when moving to next task.*/

  /*TASK 3.1
  Implement PID controller to use for task 3.2.*/

  /*TASK 3.2
  Utilize your PIDController to go to angles PI, PI/2, and PI/2.
  Write your code below.*/
}
int16_t calculateRight(double angV) {
  double v = base_speed + (w * angV / 2);
  right_overflow = v - constrain(v, -400, 400);
  return (int16_t)v;
}

int16_t calculateLeft(double angV) {
  double v = base_speed - (w * angV / 2);
  left_overflow = v - constrain(v, -400, 400);
  return (int16_t)v;
}
