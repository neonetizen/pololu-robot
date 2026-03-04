#include <Pololu3piPlus32U4.h>
#include "printOLED.h"
#include "PIDcontroller.h"
#include "odometry.h" //If using odometry, import odometry.h and odometry.cpp
#include "PDcontroller.h" //Import your PDcontroller.h and PDcontroller.cpp then uncomment
using namespace Pololu3piPlus32U4;

Motors motors;
Encoders encoders;
PrintOLED oledPrinter;

//Odometry Parameters
#define diaL 3.2
#define diaR  3.2
#define nL 12
#define nR 12
#define w 9.6
#define gearRatio 75
#define DEAD_RECKONING false

//Update kp, kd, and ki based on your testing
#define minOutput -20.0f
#define maxOutput 20.0f
#define kp 6.0f //Tune Kp here
#define kd 2.0f //Tune Kd here
#define ki 0.05f //Tune Ki here
#define clamp_i 50.0 //Tune ki integral clamp here
#define base_speed 200

Odometry odometry(diaL, diaR, w, nL, nR, gearRatio, DEAD_RECKONING); //Uncomment if using odometry class
PDcontroller pdcontroller(kp, kd, minOutput, maxOutput); //Uncomment when using PDController
PIDcontroller pidcontroller(kp, ki, kd, minOutput, maxOutput, clamp_i); //Uncomment after you implement PIDController

//Feel free to use this in your PD/PID controller for target values
// Given goals in cm and radians
const float goal_theta = 0;// Must put in radians

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
/*
  int16_t left = constrain(calculateLeft(PDout), -400, 400);
  int16_t right = constrain(calculateRight(PDout), -400, 400);

  motors.setSpeeds(left, right);

  Serial.println("dist: ");
  //Serial.print(wallDist);
  Serial.println("Left: ");
  Serial.print(left);
  Serial.println("Right: ");
  Serial.print(right);  
*/
  /*TASK 2.2
  Utilize your PDController to go to angles PI, PI/2, and PI/2.
  Write your code below and comment out when moving to next task.*/

  /*TASK 3.1
  Implement PID controller to use for task 3.2.*/

  /*TASK 3.2
  Utilize your PIDController to go to angles PI, PI/2, and PI/2.
  Write your code below.*/
}

static inline double calculateRight(double angV) {
  return base_speed + (w * angV / 2);
}

static inline double calculateLeft(double angV) {
  return base_speed - (w * angV / 2);
}
