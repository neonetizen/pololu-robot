#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

Motors motors;

void setup() {
  Serial.begin(9600);
  delay(15);
}

void loop(){
    //Sets the speeds for motors 
    //The value of the input is given in mm/s with a maximum value of 400
    motors.setSpeeds(100, 100);
    //move forward
    moveForward(0.1, 0.1);
    //move backwards
    moveBackward(0.5, 100);
    //turn right(in place)
    turnRight(100, 100);
    //turn left (in place)
    turnRight(100, 100);
    //move forward while turning right
    moveForwardTurningRight(0.5, 100);
    //move forward while turning left
    moveForwardTurningLeft(0.5, 100);

    //halt
    Halt();
    exit(1);
}

//Duration in ms = (distance/speed) * 1000
//Speed in mm/s = speed in m/s * 1000
//Distance in m

void Halt() {
  motors.setSpeeds(0, 0);
}

void moveForward(short distance, short speed) {
  short duration_ms = (distance / speed) * 1000;
  short speed_mms = speed * 1000;
  motors.setSpeeds(speed_mms, speed_mms);
  delay(duration_ms);
  Halt();
}

void moveBackward(short distance, short speed) {
  short duration_ms = (distance / speed) * 1000;
  short speed_mms = speed * 1000;
  motors.setSpeeds(-speed_mms, -speed_mms);
  delay(duration_ms);
  Halt();
}

void turnRight(short duration, short speed) {
  short duration_ms = duration * 1000;
  short speed_mms = speed * 1000;
  motors.setSpeeds(speed_mms, -speed_mms);
  delay(duration_ms);
  Halt();
}

void turnLeft(short duration, short speed) {
  short duration_ms = duration * 1000;
  short speed_mms = speed * 1000;
  motors.setSpeeds(-speed_mms, speed_mms);
  delay(duration_ms);
  Halt();
}

void moveForwardTurningRight(short distance, short speed) {
  short duration_ms = (distance / speed) * 1000;
  short speed_mms = speed * 1000;
  motors.setSpeeds(speed_mms, speed_mms * 0.5); 
  delay(duration_ms);
  Halt();
}

void moveForwardTurningLeft(short distance, short speed) {
  short duration_ms = (distance / speed) * 1000;
  short speed_mm = speed * 1000;
  motors.setSpeeds(speed_mm * 0.5, speed_mm); 
  delay(duration_ms);
  Halt();
}
