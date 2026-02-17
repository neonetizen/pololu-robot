#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

#define S_TO_MS 1000.0f
#define M_TO_MM 1000.0f
#define TURN_SPEED_RATIO 0.5f

MyRobot::MyRobot() : _state(IDLE), _start_time(0), _duration_ms(0), _left_mms(0), _right_mms(0) {
    setSpeeds(0, 0);
}

void MyRobot::Halt() {
    setSpeeds(0, 0);
    _state = IDLE;
}

void MyRobot::turnLeft(const float duration, const float speed) {
    _state = TURN_LEFT;
    _start_time = millis();
    _duration_ms = (unsigned long)(duration * S_TO_MS);
    _left_mms = (int)(-speed * M_TO_MM);
    _right_mms = (int)(speed * M_TO_MM);
}

void MyRobot::turnRight(const float duration, const float speed) {
    _state = TURN_RIGHT;
    _start_time = millis();
    _duration_ms = (unsigned long)(duration * S_TO_MS);
    _left_mms = (int)(speed * M_TO_MM);
    _right_mms = (int)(-speed * M_TO_MM);
}

void MyRobot::moveForward(const float distance, const float speed) {
    _state = MOVE_FORWARD;
    _start_time = millis();
    _duration_ms = (unsigned long)((distance / speed) * S_TO_MS);
    _left_mms = _right_mms = (int)(speed * M_TO_MM);
}

void MyRobot::moveBackward(const float distance, const float speed) {
    _state = MOVE_BACKWARD;
    _start_time = millis();
    _duration_ms = (unsigned long)((distance / speed) * S_TO_MS);
    _left_mms = _right_mms = (int)(-speed * M_TO_MM);
}

void MyRobot::moveForwardTurningRight(const float distance, const float speed) {
    _state = MOVE_FORWARD_RIGHT;
    _start_time = millis();
    _duration_ms = (unsigned long)((distance / speed) * S_TO_MS);
    _left_mms = (int)(speed * M_TO_MM);
    _right_mms = (int)(speed * M_TO_MM * TURN_SPEED_RATIO);
}

void MyRobot::moveForwardTurningLeft(const float distance, const float speed) {
    _state = MOVE_FORWARD_LEFT;
    _start_time = millis();
    _duration_ms = (unsigned long)((distance / speed) * S_TO_MS);
    _left_mms = (int)(speed * M_TO_MM * TURN_SPEED_RATIO);
    _right_mms = (int)(speed * M_TO_MM);
}

void MyRobot::moveBackwardTurningLeft(const float distance, const float speed) {
    _state = MOVE_BACKWARD_LEFT;
    _start_time = millis();
    _duration_ms = (unsigned long)((distance / speed) * S_TO_MS);
    _left_mms = (int)(-speed * M_TO_MM * TURN_SPEED_RATIO);
    _right_mms = (int)(-speed * M_TO_MM);
}

void MyRobot::moveBackwardTurningRight(const float distance, const float speed) {
    _state = MOVE_BACKWARD_RIGHT;
    _start_time = millis();
    _duration_ms = (unsigned long)((distance / speed) * S_TO_MS);
    _left_mms = (int)(-speed * M_TO_MM);
    _right_mms = (int)(-speed * M_TO_MM * TURN_SPEED_RATIO);
}

void MyRobot::update() {
    if (_state == IDLE) return;
    if ((millis() - _start_time) >= _duration_ms) {
        Halt();
        return;
    }
    setSpeeds(_left_mms, _right_mms);
}

bool MyRobot::isBusy() const {
    return _state != IDLE;
}

RobotState MyRobot::getState() const {
    return _state;
}