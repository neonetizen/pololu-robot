#include <Pololu3piPlus32U4.h>
#include "my_robot.h"

MyRobot robot; 

void setup() {
  Serial.begin(9600);
  delay(15);
}

void loop(){
    //Sets the speeds for motors 
    //The value of the input is given in mm/s with a maximum value of 400
    //speeds input as m/s, distance input as m, duration input as seconds
    robot.Halt();
    //move forward
    robot.moveForward(0.1, 0.1);
    //move backwards
    robot.moveBackward(1.0, 0.1);
    //turn right(in place)
    robot.turnRight(1.0, 0.1);
    //turn left (in place)
    robot.turnLeft(1.0, 0.1);
    //move forward while turning right
    robot.moveForwardTurningRight(0.5, 0.1);
    //move forward while turning left
    robot.moveForwardTurningLeft(0.5, 0.1);

    //halt
    robot.Halt();
    exit(1);
}

