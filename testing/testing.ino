#include <Pololu3piPlus32U4.h>
#include "printOLED.h"
#include "PIDcontroller.h"
using namespace Pololu3piPlus32U4;

/*===== OTHER PARAMS =====*/
#define diaL 3.2
#define diaR  3.2
#define nL 12
#define nR 12
#define w 9.6
#define gearRatio 75

/*===== TUNEABLES =====*/
#define minOutput -20.0f
#define maxOutput 20.0f
#define kp 6.0f
#define kd 2.0f
/* keep ki * clampi ~(10% - 30%) of maxOutput */
#define ki 0.05f
#define clamp_i 50.0
/*                                            */
#define base_speed 200

Motors motors;
Servo servo;
Sonar sonar(4);

PIDcontroller pidcontroller(kp, ki, kd, minOutput, maxOutput, clamp_i);

static constexpr double distFromWall = 10.0;

double PIDout; 

void setup() {
  Serial.begin(9600);
  servo.attach(5);
  delay(40);
  servo.write(150);
}

void loop() {
  wallDist = sonar.readDist();

  PIDout = PIDcontroller.update(wallDist, distFromWall);

  int16_t left = constrain(calculateLeft(PIDout), -400, 400);
  int16_t right = constrain(calculateRight(PIDout), -400, 400);

  motors.setSpeeds(left, right);

  Serial.println("dist: ");
  Serial.print(wallDist);
  Serial.println("Left: ");
  Serial.print(left);
  Serial.println("Right: ");
  Serial.print(right);  
}

static inline double calculateRight(double angV) {
  return base_speed + (w * angV / 2);
}

static inline double calculateLeft(double angV) {
  return base_speed - (w * angV / 2);
}
