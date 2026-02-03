#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

#define S_TO_MS 1000
#define M_TO_MM 1000
#define TURN_SPEED_RATIO 0.5

MyRobot::MyRobot() {
    setSpeeds(0, 0);
}

void MyRobot::turnLeft(float duration, float speed) {
    int duration_ms = duration * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    setSpeeds(-speed_mms, speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::turnRight(float duration, float speed) {
    int duration_ms = duration * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    setSpeeds(speed_mms, -speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::Halt() {
    setSpeeds(0, 0);
}

void MyRobot::moveForward(float distance, float speed) {
    int duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    setSpeeds(speed_mms, speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackward(float distance, float speed) {
    int duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    setSpeeds(-speed_mms, -speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::moveForwardTurningLeft(float distance, float speed) {
    int duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    setSpeeds(speed_mms * TURN_SPEED_RATIO, speed_mms); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveForwardTurningRight(float distance, float speed) {
    int duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    setSpeeds(speed_mms, speed_mms * TURN_SPEED_RATIO); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackwardTurningLeft(float distance, float speed) {
    int duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    int left_mms = -speed_mms * TURN_SPEED_RATIO;
    setSpeeds(left_mms, -speed_mms); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackwardTurningRight(float distance, float speed) {
    int duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    int right_mms = -speed_mms * TURN_SPEED_RATIO;
    setSpeeds(-speed_mms, right_mms); 
    delay(duration_ms);
    Halt();
}
