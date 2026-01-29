#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

MyRobot::MyRobot() {
    setSpeeds(0, 0);
}

void MyRobot::turnLeft(short duration, short speed) {
    short duration_ms = duration * 1000;
    short speed_mms = speed * 1000;
    setSpeeds(-speed_mms, speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::turnRight(short duration, short speed) {
    short duration_ms = duration * 1000;
    short speed_mms = speed * 1000;
    setSpeeds(speed_mms, -speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::Halt() {
    setSpeeds(0, 0);
}

void MyRobot::moveForward(short distance, short speed) {
    short duration_ms = (distance / speed) * 1000;
    short speed_mms = speed * 1000;
    setSpeeds(speed_mms, speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackward(short distance, short speed) {
    short duration_ms = (distance / speed) * 1000;
    short speed_mms = speed * 1000;
    setSpeeds(-speed_mms, -speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::moveForwardTurningLeft(short distance, short speed) {
    short duration_ms = (distance / speed) * 1000;
    short speed_mms = speed * 1000;
    setSpeeds(speed_mms * 0.5, speed_mms); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveForwardTurningRight(short distance, short speed) {
    short duration_ms = (distance / speed) * 1000;
    short speed_mms = speed * 1000;
    setSpeeds(speed_mms, speed_mms * 0.5); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackwardTurningLeft(short distance, short speed) {
    short duration_ms = (distance / speed) * 1000;
    short speed_mms = speed * 1000;
    setSpeeds(-speed_mms * 0.5, -speed_mms); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackwardTurningRight(short distance, short speed) {
    short duration_ms = (distance / speed) * 1000;
    short speed_mms = speed * 1000;
    setSpeeds(-speed_mms, -speed_mms * 0.5); 
    delay(duration_ms);
    Halt();
}
