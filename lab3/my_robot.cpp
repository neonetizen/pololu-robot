#include <Pololu3piPlus32U4.h>
#include "my_robot.h"
using namespace Pololu3piPlus32U4;

#define S_TO_MS 1000
#define M_TO_MM 1000
#define TURN_SPEED_RATIO 0.5

MyRobot::MyRobot() : _state(IDLE), _start_time(0), _duration_ms(0), _left_mms(0), _right_mms(0) {
    setSpeeds(0, 0);
}

void MyRobot::Halt() {
    setSpeeds(0, 0);
    _state = IDLE;
}

void MyRobot::turnLeft(float duration, float speed) {
    _state = TURN_LEFT;
    _start_time = millis();
    _duration_ms = duration * S_TO_MS;
    _left_mms = -speed * M_TO_MM;
    _right_mms = speed * M_TO_MM;
    Halt();
}

void MyRobot::turnRight(float duration, float speed) {
    _state = TURN_RIGHT;
    _start_time = millis();
    _duration_ms = duration * S_TO_MS;
    _left_mms = speed * M_TO_MM;
    _right_mms = -speed * M_TO_MM;
    Halt();
}

void MyRobot::moveForward(float distance, float speed) {
    _state = MOVE_FORWARD;
    _start_time = millis();
    _duration_ms = (distance / speed) * S_TO_MS;
    _left_mms = _right_mms = speed * M_TO_MM;
    Halt();
}

void MyRobot::moveBackward(float distance, float speed) {
    _state = MOVE_BACKWARD;
    _start_time = millis();
    _duration_ms = (distance / speed) * S_TO_MS;
    _left_mms = _right_mms = -speed * M_TO_MM;
    Halt();
}

void MyRobot::moveForwardTurningLeft(float distance, float speed) {
    _state = MOVE_FORWARD_LEFT;
    _start_time = millis();
    _duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    _left_mms = speed_mms * TURN_SPEED_RATIO;
    _right_mms = speed_mms;
    Halt();
}

void MyRobot::moveForwardTurningRight(float distance, float speed) {
    _state = MOVE_FORWARD_RIGHT;
    _start_time = millis();
    _duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    _left_mms = speed_mms;
    _right_mms = speed_mms * TURN_SPEED_RATIO;
    Halt();
}

void MyRobot::moveBackwardTurningLeft(float distance, float speed) {
    _state = MOVE_BACKWARD_LEFT;
    _start_time = millis();
    _duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    _left_mms = -speed_mms * TURN_SPEED_RATIO;
    _right_mms = -speed_mms;
    Halt();
}

void MyRobot::moveBackwardTurningRight(float distance, float speed) {
    _state = MOVE_BACKWARD_RIGHT;
    _start_time = millis();
    _duration_ms = (distance / speed) * S_TO_MS;
    int speed_mms = speed * M_TO_MM;
    _left_mms = -speed_mms;
    _right_mms = -speed_mms * TURN_SPEED_RATIO;
    Halt();
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