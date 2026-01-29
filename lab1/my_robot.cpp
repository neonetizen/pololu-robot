#include <Pololu3piPlus32U4.h>
#include "my_robot.h"

MyRobot::MyRobot() {
    setSpeeds(0, 0);
}

void MyRobot::turnLeft(float duration, float speed) {
    int duration_ms = duration * s_to_ms;
    int speed_mms = speed * m_to_mm;
    setSpeeds(-speed_mms, speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::turnRight(float duration, float speed) {
    int duration_ms = duration * s_to_ms;
    int speed_mms = speed * m_to_mm;
    setSpeeds(speed_mms, -speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::Halt() {
    setSpeeds(0, 0);
}

void MyRobot::moveForward(float distance, float speed) {
    int duration_ms = (distance / speed) * s_to_ms;
    int speed_mms = speed * m_to_mm;
    setSpeeds(speed_mms, speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackward(float distance, float speed) {
    int duration_ms = (distance / speed) * s_to_ms;
    int speed_mms = speed * m_to_mm;
    setSpeeds(-speed_mms, -speed_mms);
    delay(duration_ms);
    Halt();
}

void MyRobot::moveForwardTurningLeft(float distance, float speed) {
    int duration_ms = (distance / speed) * s_to_ms;
    int speed_mms = speed * m_to_mm;
    setSpeeds(speed_mms * turn_speed_ratio, speed_mms); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveForwardTurningRight(float distance, float speed) {
    int duration_ms = (distance / speed) * s_to_ms;
    int speed_mms = speed * m_to_mm;
    setSpeeds(speed_mms, speed_mms * turn_speed_ratio); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackwardTurningLeft(float distance, float speed) {
    int duration_ms = (distance / speed) * s_to_ms;
    int speed_mms = speed * m_to_mm;
    setSpeeds(-speed_mms * turn_speed_ratio, -speed_mms); 
    delay(duration_ms);
    Halt();
}

void MyRobot::moveBackwardTurningRight(float distance, float speed) {
    int duration_ms = (distance / speed) * s_to_ms;
    int speed_mms = speed * m_to_mm;
    setSpeeds(-speed_mms, -speed_mms * turn_speed_ratio); 
    delay(duration_ms);
    Halt();
}
