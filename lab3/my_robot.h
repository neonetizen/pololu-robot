#ifndef my_robot_h
#define my_robot_h

#include <Pololu3piPlus32U4.h>

enum RobotState {
    IDLE = 1,
    TURN_LEFT = 2,
    TURN_RIGHT = 3,
    MOVE_FORWARD = 4,
    MOVE_BACKWARD = 5,
    MOVE_FORWARD_LEFT = 6,
    MOVE_FORWARD_RIGHT = 7,
    MOVE_BACKWARD_LEFT = 8,
    MOVE_BACKWARD_RIGHT = 9
};

class MyRobot : public Pololu3piPlus32U4::Motors {
public:
    MyRobot();

    /**
     * @brief Stops the robot.
     *
     * Makes the robot stay still (until another primitive function is 
     * called again), and sets the state to IDLE.
     */
    void Halt();
    /**
     * @brief Stops the robot.
     *
     * Makes the robot stay still (until another primitive function is 
     * called again), and sets the state to IDLE.
     */
    RobotState getState();

    void update();
    /**
     * @brief Updates the robot state and sets the speeds.
     *
     * Updates the robot state and sets the speeds based on the current state.
     * If the robot is in the IDLE state, it does nothing.
     * If the robot is not in the IDLE state, it checks if the duration has elapsed.
     * If the duration has elapsed, it sets the speeds to 0 and sets the state to IDLE.
     * If the duration has not elapsed, it sets the speeds based on the current state.
     * The speeds are set based on the current state.
     *
     */

    bool isBusy() const;

    /**
     * @brief Turns robot left in place.
     *
     * Makes the robot turn in place to the left for a specified duration
     * at a specified speed.
     *
     * @param duration Float controlling duration in seconds
     * @param speed Float controlling speed in m/s
     */
    void turnLeft(float duration, float speed);

    /**
     * @brief Turns robot right in place.
     *
     * Makes the robot turn in place to the right for a specified duration
     * at a specified speed.
     *
     * @param duration Float controlling duration in seconds
     * @param speed Float controlling speed in m/s
     */
    void turnRight(float duration, float speed);

    /**
     * @brief Moves robot forward.
     *
     * Makes the robot move straight forward for a specified distance at 
     * a specified speed.
     *
     * @param distance Float controlling distance in m
     * @param speed Float controlling speed in m/s
     */
    void moveForward(float distance, float speed);

    /**
     * @brief Moves robot backward.
     *
     * Makes the robot move straight backward for a specified distance at 
     * a specified speed.
     *
     * @param distance Float controlling distance in m
     * @param speed Float controlling speed in m/s
     */
    void moveBackward(float distance, float speed);

    /**
     * @brief Moves robot forward and left.
     *
     * Makes the robot move forward while turning left for a specified
     * distance at a specified speed.
     *
     * @param distance Float controlling distance in m
     * @param speed Float controlling speed in m/s
     */
    void moveForwardTurningLeft(float distance, float speed);

    /**
     * @brief Moves robot forward and right.
     *
     * Makes the robot move forward while turning right for a specified
     * distance at a specified speed.
     *
     * @param distance Float controlling distance in m
     * @param speed Float controlling speed in m/s
     */
    void moveForwardTurningRight(float distance, float speed);

    /**
     * @brief Moves robot backward and left.
     *
     * Makes the robot move backward while turning left for a specified
     * distance at a specified speed.
     *
     * @param distance Float controlling distance in m
     * @param speed Float controlling speed in m/s
     */
    void moveBackwardTurningLeft(float distance, float speed);

    /**
     * @brief Moves robot backward and right.
     *
     * Makes the robot move backward while turning right for a specified
     * distance at a specified speed.
     *
     * @param distance Float controlling distance in m
     * @param speed Float controlling speed in m/s
     */
    void moveBackwardTurningRight(float distance, float speed);

private:
    RobotState _state = IDLE;
    unsigned long _start_time;
    unsigned long _duration_ms;
    int _left_mms;
    int _right_mms;
};

#endif