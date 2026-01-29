#ifndef my_robot_h
#define my_robot_h
#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

class MyRobot{
  public:
    MyRobot();

    /**
     * @brief Turns robot left in place.
     *
     * Makes the robot turn in place to the left for a specified duration
     * at a specified speed.
     *
     * @param duration Short integer controlling duration in ms
     * @param speed Short integer controlling speed in mm/s
     */
    void turnLeft(short duration, short speed);

    /**
     * @brief Turns robot right in place.
     *
     * Makes the robot turn in place to the right for a specified duration
     * at a specified speed.
     *
     * @param duration Short integer controlling duration in ms
     * @param speed Short integer controlling speed in mm/s
     */
    void turnRight(short duration, short speed);

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
     * @param distance Short integer controlling distance in m
     * @param speed Short integer controlling speed in mm/s
     */
    void moveForward(short distance, short speed);

    /**
     * @brief Moves robot backward.
     *
     * Makes the robot move straight backward for a specified distance at 
     * a specified speed.
     *
     * @param distance Short integer controlling distance in m
     * @param speed Short integer controlling speed in mm/s
     */
    void moveBackward(short distance, short speed);

    /**
     * @brief Moves robot forward and left.
     *
     * Makes the robot move forward while turning left for a specified
     * distance at a specified speed.
     *
     * @param distance Short integer controlling distance in m
     * @param speed Short integer controlling speed in mm/s
     */
    void moveForwardTurningLeft(short distance, short speed);

    /**
     * @brief Moves robot forward and right.
     *
     * Makes the robot move forward while turning right for a specified
     * distance at a specified speed.
     *
     * @param distance Short integer controlling distance in m
     * @param speed Short integer controlling speed in mm/s
     */
    void moveForwardTurningRight(short distance, short speed);

    /**
     * @brief Moves robot backward and left.
     *
     * Makes the robot move backward while turning left for a specified
     * distance at a specified speed.
     *
     * @param distance Short integer controlling distance in m
     * @param speed Short integer controlling speed in mm/s
     */
    void moveBackwardTurningLeft(short distance, short speed);

    /**
     * @brief Moves robot backward and right.
     *
     * Makes the robot move backward while turning right for a specified
     * distance at a specified speed.
     *
     * @param distance Short integer controlling distance in m
     * @param speed Short integer controlling speed in mm/s
     */
    void moveBackwardTurningRight(short distance, short speed);

  private:
    
};

#endif
