#ifndef my_robot_h
#define my_robot_h

#include <Pololu3piPlus32U4.h>

enum RobotState {
    IDLE,
    TURN_LEFT,
    TURN_RIGHT,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_FORWARD_LEFT,
    MOVE_FORWARD_RIGHT,
    MOVE_BACKWARD_LEFT,
    MOVE_BACKWARD_RIGHT
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
     * @brief Turns robot left in place.
     *
     * Makes the robot turn in place to the left for a specified duration.
     *
     * @param duration Float controlling duration in seconds
     */
    void turnLeft(const float duration);

    /**
     * @brief Turns robot right in place.
     *
     * Makes the robot turn in place to the right for a specified duration.
     *
     * @param duration Float controlling duration in seconds
     */
    void turnRight(const float duration);

    /**
     * @brief Moves robot forward.
     *
     * Makes the robot move straight forward for a specified distance.
     *
     * @param distance Float controlling distance in m
     */
    void moveForward(const float distance);

    /**
     * @brief Moves robot backward.
     *
     * Makes the robot move straight backward for a specified distance.
     *
     * @param distance Float controlling distance in m
     */
    void moveBackward(const float distance);

    /**
     * @brief Moves robot forward and left.
     *
     * Makes the robot move forward while turning left for a specified
     * distance.
     *
     * @param distance Float controlling distance in m
     */
    void moveForwardTurningLeft(const float distance);

    /**
     * @brief Moves robot forward and right.
     *
     * Makes the robot move forward while turning right for a specified
     * distance.
     *
     * @param distance Float controlling distance in m
     */
    void moveForwardTurningRight(const float distance);

    /**
     * @brief Moves robot backward and left.
     *
     * Makes the robot move backward while turning left for a specified
     * distance.
     *
     * @param distance Float controlling distance in m
     */
    void moveBackwardTurningLeft(const float distance);

    /**
     * @brief Moves robot backward and right.
     *
     * Makes the robot move backward while turning right for a specified
     * distance.
     *
     * @param distance Float controlling distance in m
     */
    void moveBackwardTurningRight(const float distance);

    /**
     * @brief Updates the robot state and sets the speeds.
     *
     * Updates the robot state and sets the speeds based on the current state.
     * If the robot is in the IDLE state, it does nothing.
     * If the robot is not in the IDLE state, it checks if the duration has elapsed.
     * If the duration has elapsed, it sets the speeds to 0 and sets the state to IDLE.
     * If the duration has not elapsed, it sets the speeds based on the current state.
     * Call this every loop iteration for non-blocking movement.
     */
    void update();

    /**
     * @brief Checks if robot is busy
     *
     * Checks if the robot is busy
     *
     * @return True if the robot is busy, false otherwise
     */
    bool isBusy() const;

    /**
     * @brief Gets state of the robot
     *
     * Gets the state of the robot
     *
     * @return The RobotState of the robot
     */
    RobotState getState() const;

private:
    static constexpr float _TURN_SPEED_RATIO = 0.5f;
    static constexpr float _BASE_SPEED = 0.1f; // Speed in meters

    unsigned long _start_time = 0; // Time since new motion in milliseconds
    unsigned long _duration_ms = 0; // Desired time of most recent motion in milliseconds
    int16_t _left_mms = 0; // Desired speed of left motor in millimeters per second
    int16_t _right_mms = 0; // Desired speed of left motor in millimeters per second

    RobotState _state; // State of robot; IDLE when idle, corresponding motion when not
};

#endif