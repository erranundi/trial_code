/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Speedbot (4-motor Drivetrain, No Gyro)                    */
/*                                                                            */
/*    Name:                                                                   */
/*    Date:                                                                   */
/*    Class:                                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10, 11, 20   
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "../include/vex.h" 
#include "robot-config.cpp"
#include <cmath>

using namespace vex;

competition competition;


void userControl(void){

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Read joystick input for the left joystick (left_x, left_y), and (right_x, right_y)
  int left_x, left_y, right_x, right_y;
  double avg_x, avg_y, speed, angle, left_speed, right_speed,
  curr_speed_left, curr_speed_right, increment_left, increment_right;

  left_x = user_input.Axis3.position();
  left_y = user_input.Axis3.position();
  right_x = user_input.Axis1.position();
  right_y = user_input.Axis2.position();

  // Calculate the average displacement (avg_x, avg_y) of the two joysticks:
  avg_x = (left_x + right_x) / 2;
  avg_y = (left_y + right_y) / 2;

  // Calculate the magnitude (speed) and direction (angle) of the displacement:
  speed = sqrt(pow(avg_x,2) + pow(avg_y, 2));
  angle = atan2(avg_y, avg_x); //not in radians
  angle *= 180.0 / M_PI; // now it is in radians

  // Calculate the individual motor speeds for each wheel:
  left_speed = speed * cos(angle);  // Speed for the left wheels
  right_speed = speed * sin(angle); // Speed for the right wheels

  // Asigning the increments by which the speeds of the motor groups will increase by every gap seconds
  // percent_increment is a value defined in robot-config.cpp and defines by what fraction of left/right_speed will current speed increase every gap seconds
  // gap is defined in robot-config.cpp
  increment_left = left_speed / percent_increment;
  increment_right = right_speed / percent_increment;

  curr_speed_right = curr_speed_left = 0;

  while(curr_speed_left < left_speed){
    curr_speed_right += increment_right;
    curr_speed_left += increment_left;

    wait(gap, seconds);
  }

   while(true){
    wait(0.01, seconds);
   }

}
