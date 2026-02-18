#include <Pololu3piPlus32U4.h>
#include <Servo.h>
#include "printOLED.h"
#include "odometry.h"
#include "my_robot.h"
using namespace Pololu3piPlus32U4;
Motors motors;
Encoders encoders;
MyRobot robot;
PrintOLED oledPrinter;

/*DEFINE VARIBLES FOR PHYSICAL ROBOT PARAMETRS 
BY INSERTING THE PARAMETER VALUES FROM THE ROBOT DOCUMENTATION*/
#define DEAD_RECKONING false // if "false": uses formula from the lecture slides to calculate theta. if "true", uses IMU data to calculate theta.
#define diaL 3.2 //define physical robot parameters (cm)
#define diaR  3.2
#define nL 12
#define nR 12
#define w 9.6 //cm
#define gearRatio 75
#define DURATION_NINETY_DEG_LEFT (PI * diaL)/16

#define BaseSpeed 100  // unit: mm per second

Odometry odometry(diaL, diaR, w, nL, nR, gearRatio, DEAD_RECKONING);

int16_t deltaL=0, deltaR=0;
int16_t encCountsLeft = 0, encCountsRight = 0;
int step = 0;

float x = 0.0, y = 0.0, theta = 0.0;

void setup() {
  Serial.begin(9600);
  delay(20);
}

bool done = false;
bool done2 = false;
bool done3 = false;
bool done4 = false;
bool done5 = false;
bool done6 = false;
bool done7 = false;
bool done8 = false;

void loop() {  
      //(TASK 2.1) Test Encoders while Staying Still 

      //IMPORT FUNCTIONS FROM LAB1 (MOVE FORWARD, TURN LEFT, ...) 
      //TO ENABLE ROBOT TO MOVE ONE METER FORWARD, CLOCKWISE AND COUNTERCLOCKWISE

      //Encoder code should always be before updating and movement
      // Read data from encoders and update robot state
      deltaL = encoders.getCountsAndResetLeft();
      deltaR = encoders.getCountsAndResetRight();
      // Increment total encoder count
      encCountsLeft += deltaL;
      encCountsRight += deltaR;

      robot.update();

      //(TASK 2.2) TEST ENCODERS WHILE MOVING EACH OF THE THREE MOVEMENTS LISTED BELOW (ONE AT A TIME) 
      //(NOTE: YOU SHOULD UPDATE AND USE PRIMITIVE FUNCTIONS FROM LAB1)
      //DO NOT DELETE CODE AFTER EACH TASK, COMMENT OUT INSTEAD
      
      //(2.2a) MOVE FORWARD ON A STRAIGHT LINE FOR ONE METER 
/*
      if(!done) {
        robot.moveForward(1, 0.1);
        //delay(10000);
        done = true;
      }      
*/
      //(2.2b) MOVE BACKWARD ON A STRAIGHT LINE FOR ONE METER
/*
      if(!done) {
        robot.moveBackward(1, 0.1);
        done = true;
      }
*/
/*
      //(2.2c) TURN LEFT FOR 90 DEGREES
      if(!robot.isBusy() && !done) {
        robot.turnLeft(DURATION_NINETY_DEG_LEFT, 0.1);
        done = true;
      }
*/      
      // PRINT THE LEFT AND RIGHT ODOMETRY VALUES ON OLED
      // PRINT THE LEFT AND RIGHT ODOMETRY VALUES ON SERIAL MONITOR

     //oledPrinter.print_encoder(encCountsLeft, encCountsRight);
      Serial.print("Encoder Counts Left: ");
      Serial.println(encCountsLeft);
      Serial.print("Encoder Counts Right: ");
      Serial.println(encCountsRight);

      //(TASK 3.1) IMPLEMENT ODOMETRY 

      /*UNCOMMENT Odometry.update_odom DOWN BELOW*/
      odometry.update_odom(encCountsLeft, encCountsRight, x, y, theta); //calculate robot's position
/*      if(!done) {
        robot.moveForward(0.5, 0.1);
        done = true;
      }
*/
      /*NOW GO TO odometry.cpp file AND COMPLETE THE udate_odom FUNCTION. 
      IN odometry.cpp, ADD CODES TO ENABLE THE ROBOT TO 
      TO CALCULATE x, y, theta, AND
      TO PRINT THE CALCULATED VALUES TO OLED SCREEN AND SERIAL MONITOR*/
    
      

      //TEST ODOMETRY WHILE MOCING EACH OF THE THREE MOVEMENTS LISTED BELOW (ONE AT A TIME)
      //DO NOT DELETE CODE AFTER EACH TASK, COMMENT OUT INSTEAD

      //(3.2a)  15-meter straight line down the hallway
/*      
      if(!done) {
        robot.moveForward(15, 0.1);
        done = true;
      }
*/      
      //(3.2c)  1-meter square clockwise
    
      if(!done2) {
        robot.moveForward(1, 0.1);
        done2 = true;
        done3 = true;
      }
      if(done3 && !done4) {
        robot.turnRight(PI/2, 0.1);
        done4 = true;
      }
      if(done4 && !done5) {
        robot.moveForward(1, 0.1);
        done5 = true;
      }
      if(done5 && !done6) {
        robot.turnRight(PI/2, 0.1);
        done6 = true;
      }
      if(done6 && !done7) {
        robot.moveForward(1, 0.1);
        done7 = true;
      }
      
/*
      //(3.3e)  1-meter square counterclockwise
      if(!done) {
        robot.moveForward(1, 0.1);
        robot.update();
        robot.turnLeft(PI/2, 0.1);
        robot.update();
        robot.moveForward(1, 0.1);
        robot.update();
        robot.turnLeft(PI/2, 0.1);
        robot.update();
        robot.moveForward(1, 0.1);
        robot.update();
        robot.turnLeft(PI/2, 0.1);
        robot.update();
        robot.moveForward(1, 0.1);
        robot.update();
        done = true;
      }
  */
      //while(true) {}
}
