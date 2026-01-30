#ifndef my_robot_h
#define my_robot_h

#include <Pololu3piPlus32U4.h>

class MyRobot : public Pololu3piPlus32U4::Motors {
public:
    MyRobot();

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
     * @brief Stops the robot.
     *
     * Makes the robot stay still (until another primitive function is 
     * called again).
     */
    void Halt();

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
};

#endif
