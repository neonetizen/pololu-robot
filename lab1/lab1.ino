#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

Motors motors;
MyRobot robot; 

void setup() {
  Serial.begin(9600);
  delay(15);
}

void loop(){
    //Sets the speeds for motors 
    //The value of the input is given in mm/s with a maximum value of 400
    //speeds input as m/s, distance input as m, duration input as seconds
    robot.Halt();
    //move forward
    robot.moveForward(0.1, 0.1);
    //move backwards
    robot.moveBackward(0.1, 0.1);
    //turn right(in place)
    robot.turnRight(0.1, 0.1);
    //turn left (in place)
    robot.turnLeft(0.1, 0.1);
    //move forward while turning right
    robot.moveForwardTurningRight(0.2, 0.1);
    //move forward while turning left
    robot.moveForwardTurningLeft(0.2, 0.1);
    //move backward while turning right
    robot.moveBackwardTurningRight(0.2, 0.1);
    //move forward while turning left
    robot.moveBackwardTurningLeft(0.2, 0.1);
    //halt
    robot.Halt();
    exit(1);
    
    while(true) {}
}

/*
void Halt() {
  motors.setSpeeds(0, 0);
}

void moveForward(float distance, float speed) {
  float duration_ms = (distance / speed) * 1000;
  short speed_mms = speed * 1000;
  motors.setSpeeds(speed_mms, speed_mms);
  delay(duration_ms);
  Halt();
}

void moveBackward(float distance, float speed) {
  float duration_ms = (distance / speed) * 1000;
  float speed_mms = speed * 1000;
  motors.setSpeeds(-speed_mms, -speed_mms);
  delay(duration_ms);
  Halt();
}

void turnRight(float duration, float speed) {
  float duration_ms = duration * 1000;
  float speed_mms = speed * 1000;
  motors.setSpeeds(speed_mms, -speed_mms);
  delay(duration_ms);
  Halt();
}

void turnLeft(float duration, float speed) {
  float duration_ms = duration * 1000;
  float speed_mms = speed * 1000;
  motors.setSpeeds(-speed_mms, speed_mms);
  delay(duration_ms);
  Halt();
}

void moveForwardTurningRight(float distance, float speed) {
  float duration_ms = (distance / speed) * 1000;
  float speed_mms = speed * 1000;
  motors.setSpeeds(speed_mms, speed_mms * 0.5); 
  delay(duration_ms);
  Halt();
}

void moveForwardTurningLeft(float distance, float speed) {
  float duration_ms = (distance / speed) * 1000;
  float speed_mm = speed * 1000;
  motors.setSpeeds(speed_mm * 0.5, speed_mm); 
  delay(duration_ms);
  Halt();
}

void moveBackwardTurningRight(float distance, float speed) {
  float duration_ms = (distance / speed) * 1000;
  float speed_mms = speed * 1000;
  motors.setSpeeds(-speed_mms, -speed_mms * 0.5); 
  delay(duration_ms);
  Halt();
}

void moveBackwardTurningLeft(float distance, float speed) {
  float duration_ms = (distance / speed) * 1000;
  float speed_mm = speed * 1000;
  motors.setSpeeds(-speed_mm * 0.5, -speed_mm); 
  delay(duration_ms);
  Halt();
}
*/
