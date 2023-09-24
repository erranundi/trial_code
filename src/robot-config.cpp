#include "../include/vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorFront = motor(PORT1, ratio18_1, false);
motor leftMotorBack = motor(PORT10, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorFront, leftMotorBack);

motor rightMotorFront = motor(PORT11, ratio18_1, true); 
motor rightMotorBack = motor(PORT20, ratio18_1, true); 
motor_group RightDriveSmart = motor_group(rightMotorFront, rightMotorBack);

int percent_increment = 20;
double gap = 0.01;

controller user_input = controller();

drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 165, mm, 1);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}