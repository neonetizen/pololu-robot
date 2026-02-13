#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

#define S_TO_MS 1000
#define M_TO_MM 1000
#define TURN_SPEED_RATIO 0.5

MyRobot::MyRobot() : state(IDLE), start_time(0), duration_ms(0), left_mms(0), right_mms(0) {
    setSpeeds(0, 0);
}

void MyRobot::Halt() {
    setSpeeds(0, 0);
    state = IDLE;
}

void MyRobot::turnLeft(float duration, float speed) {
    state = TURN_LEFT;
    start_time = millis();
    duration_ms = duration * S_TO_MS;
    left_mms = -speed * M_TO_MM;
    right_mms = speed * M_TO_MM;
}

void MyRobot::turnRight(float duration, float speed) {
    state = TURN_RIGHT;
    start_time = millis();
    duration_ms = duration * S_TO_MS;
    left_mms = speed * M_TO_MM;
    right_mms = -speed * M_TO_MM;
}

void MyRobot::moveForward(float distance, float speed) {
    state = MOVE_FORWARD;
    start_time = millis();
    duration_ms = (distance / speed) * S_TO_MS;
    left_mms = right_mms = speed * M_TO_MM;
}

void MyRobot::moveBackward(float distance, float speed) {
    state = MOVE_BACKWARD;
    start_time = millis();
    duration_ms = (distance / speed) * S_TO_MS;
    left_mms = right_mms = -speed * M_TO_MM;
}

void MyRobot::moveForwardTurningLeft(float distance, float speed) {
    state = MOVE_FORWARD_LEFT;
    start_time = millis();
    duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    left_mms = speed_mms * TURN_SPEED_RATIO;
    right_mms = speed_mms;
}

void MyRobot::moveForwardTurningRight(float distance, float speed) {
    state = MOVE_FORWARD_RIGHT;
    start_time = millis();
    duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    left_mms = speed_mms;
    right_mms = speed_mms * TURN_SPEED_RATIO;
}

void MyRobot::moveBackwardTurningLeft(float distance, float speed) {
    state = MOVE_BACKWARD_LEFT;
    start_time = millis();
    duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    left_mms = -speed_mms * TURN_SPEED_RATIO;
    right_mms = -speed_mms;
}

void MyRobot::moveBackwardTurningRight(float distance, float speed) {
    state = MOVE_BACKWARD_RIGHT;
    start_time = millis();
    duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    left_mms = -speed_mms;
    right_mms = -speed_mms * TURN_SPEED_RATIO;
}

void MyRobot::update() {
    if (state == IDLE) return;
    if ((millis() - start_time) >= duration_ms) {
        Halt();
        return;
    }
    setSpeeds(left_mms, right_mms);
}

bool MyRobot::isBusy() const {
    return state != IDLE;
}
