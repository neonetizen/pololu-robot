#include <Pololu3piPlus32U4.h>
#include <Servo.h>
#include "sonar.h"
#include "Pcontroller.h"
using namespace Pololu3piPlus32U4;

#define MM_TO_CM 10

#define diaL 3.2
#define diaR 3.2
#define w 9.6
#define nL 12
#define nR 12
#define gearRatio 75

#define minOutput -20
#define maxOutput 20
#define kp 6
#define kd 2
#define base_speed 400

const double distFromWall=10.0; // Goal distance from wall (cm)

Motors motors;
Servo servo;
Sonar sonar(4);
Pcontroller Pcontroller(kp, kd, minOutput, maxOutput);

double wallDist;
double Pout;
double left_overflow{ 0.0 };
double right_overflow{ 0.0 };

void setup() {
  Serial.begin(9600);
  servo.attach(5);
  delay(40);
  //Move Sonar to desired direction using Servo
  servo.write(150);
}

void loop() {
  //DO NOTE DELETE CODE AFTER EACH TASK, COMMENT OUT INSTEAD
  wallDist = sonar.readDist();

  //UNCOMMENT AFTER IMPLEMENTING Pcontroller
  Pout = Pcontroller.update(wallDist, distFromWall); //uncomment if using Pcontroller 

  //(LAB 4 - TASK 3.1) IMPLEMENT PCONTROLLER 
  
  /*FIRST GO TO Pcontroller.h AND ADD PRIVATE VARIABLES NEEDED.
    THEN GO TO Pcontroller.cpp AND COMPLETE THE update FUNCTION.
    ONCE YOU IMPLEMENT update, UNCOMMENT CODE ABOVE TO USE CONTROLLER.*/

  //(LAB 4 - TASK 3.2) PCONTROLLER WALL FOLLOWING

  /*NOW THAT YOU HAVE IMPLEMENTED PCONTROLLER, TAKE THE OUTPUT FROM Pout
  AND SET THE MOTOR SPEEDS. CHANGE THE KP AND CLAMPING VALUES AT THE TOP
  TO TEST (B-D).
  Hint: Also use baseSpeed when setting motor speeds*/
  int16_t left = constrain(calculateLeft(Pout / MM_TO_CM) - right_overflow, -400, 400);
  int16_t right = constrain(calculateRight(Pout / MM_TO_CM) - left_overflow, -400, 400);

  Serial.println("Left: ");
  Serial.print(left);
  Serial.println("Right: ");
  Serial.print(right);

  motors.setSpeeds(left, right);
}

int16_t calculateRight(double angV) {
  double v = base_speed + (w * angV / 2);
  right_overflow = v - constrain(v, -400., 400.);
  return (int16_t)v;
}

int16_t calculateLeft(double angV) {
  double v = base_speed - (w * angV / 2);
  left_overflow = v - constrain(v, -400., 400.);
  return (int16_t)v;
}