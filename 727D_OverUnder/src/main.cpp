/*-------------------------- 727D_OverUnder INFO -----------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Authors:      Simon, Alex, Elissa, Jack, Luca                           */
/*    Created:      Wed Sep 13 2023                                           */
/*    Description:  727D Drive and Autonomous Code                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// -------- VEXCODE CONFIGURED DEVICES --------//
// Robot Configuration:                        //
// [Name]               [Type]        [Port(s)]//
// frontLeft            motor         11       //     
// midLeft              motor         13       //     
// rearLeft             motor         12       //     
// frontRight           motor         20       //     
// midRight             motor         18       //     
// rearRight            motor         19       // 
// Puncher              motor         17       //
// Intake               motor         16       //   
// rightWing            pneumatics    A        //
// leftWing             pneumatics    B        // 
// Controller1          controller             //     
// --------------------------------------------//

// Allows the library "vex.h" to be used
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

int numf = 0;
int numRW = 0;
int numLW = 0;
int switchDrive = 0;

// Sets the velocity, torque, and the direction of the motor
void set_spin(motor spin_motor, int Velocity, int Torque, bool fob) {
  spin_motor.setVelocity(Velocity, percent);
  spin_motor.setMaxTorque(Torque, percent);
  if (fob){
    spin_motor.spin(forward);
  } else {
    spin_motor.spin(reverse);
  }
}

// Code for autonomous period to move the robot forward for a specific amount of time at a specific amount of velocity
void forwardFor(int deg, int speed) {
  frontLeft.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  midLeft.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  rearLeft.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  frontRight.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  midRight.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  rearRight.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
}

// Code for autonomous period to move the robot in reverse for a specific amount of time at a specific amount of velocity
void reverseFor(int deg, int speed) {
  frontLeft.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  midLeft.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  rearLeft.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  frontRight.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  midRight.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  rearRight.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
}

// Stops all motors
void stopAllMotors() {
  frontLeft.stop();
  midLeft.stop();
  rearLeft.stop();
  frontRight.stop();
  midRight.stop();
  rearRight.stop();
}

// Turns the robot 180 degrees
void terminator() {
  frontLeft.spinFor(3, timeUnits::sec, 75, velocityUnits::pct);
  midLeft.spinFor(3, timeUnits::sec, 75, velocityUnits::pct);
  rearLeft.spinFor(3, timeUnits::sec, 75, velocityUnits::pct);
  frontRight.spinFor(3, timeUnits::sec, 75, velocityUnits::pct);
  midRight.spinFor(3, timeUnits::sec, 75, velocityUnits::pct);
  rearRight.spinFor(3, timeUnits::sec, 75, velocityUnits::pct);
}

// Right Wing Code
void rightWingDown() {
  if(numRW == 0) {
    rightWing.open();
    numRW++;
  } else if(numRW == 1) {
    rightWing.close();
    numRW--;
  }
}

// Left Wing Code
void leftWingDown() {
  if(numLW == 0) {
    leftWing.open();
    numLW++;
  } else if(numLW == 1) {
    leftWing.close();
    numLW--;
  }
}

// Punches tri-ball forward when tri-ball is placed on top of robot
void falconPunch() {
  if(numf == 0) {
    puncher.spin(fwd, 30, velocityUnits::pct);
    numf++;
  } else {
    puncher.stop();
    numf--;
  }
}

// Switches the way the drive code works
// void switchDriving() {
//   if(switchDrive == 0) {
//     frontLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     midLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     rearLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     frontRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     midRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     rearRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent))/2, velocityUnits::pct);

//   } else if(switchDrive == 1){
//     frontLeft.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     midLeft.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     rearLeft.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     frontRight.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     midRight.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//     rearRight.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
//   }
// }

// Code for autonomous period goes in this void
void autonomous(void) {
  puncher.spinFor(fwd, 180, rotationUnits::deg);
}

// Code for drivercontrol period goes in this void
void userControl(void) {
  // Calls the falconPunch function when button 'B' is pressed on the controller
  Controller1.ButtonB.pressed(falconPunch);

  // Calls the rightWingDown function when button 'R1' is pressed on the controller
  Controller1.ButtonR1.pressed(rightWingDown);

  // Calls the leftWingDown function when button 'L1' is pressed on the controller
  Controller1.ButtonL1.pressed(leftWingDown);

  // Calls the switchDriving function when button 'Down' is pressed on the controller
  // Controller1.ButtonDown.pressed(switchDriving);

  while(1) {
    // Arcade steering using the left stick of the controller
    frontLeft.spin(fwd, (Controller1.Axis3.position(percent)*2 + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
    midLeft.spin(fwd, (Controller1.Axis3.position(percent)*2 + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
    rearLeft.spin(fwd, (Controller1.Axis3.position(percent)*2 + Controller1.Axis1.position(percent))/2, velocityUnits::pct);
    frontRight.spin(fwd, (Controller1.Axis3.position(percent)*2 - Controller1.Axis1.position(percent))/2, velocityUnits::pct);
    midRight.spin(fwd, (Controller1.Axis3.position(percent)*2 - Controller1.Axis1.position(percent))/2, velocityUnits::pct);
    rearRight.spin(fwd, (Controller1.Axis3.position(percent)*2 - Controller1.Axis1.position(percent))/2, velocityUnits::pct);

    // Allows the use of the intake using the 'R2' and 'L2' buttons
    if(Controller1.ButtonL2.pressing()) {
      intake.spin(fwd, 100, percentUnits::pct);
    } else if(Controller1.ButtonR2.pressing()) {
      intake.spin(reverse, 100, percentUnits::pct);
    } else {
      intake.stop();
    }

  }
}

int main() {
  // Initializing Robot Configuration.
  vexcodeInit();

  // Sets the void autonomous to be run when autonomous mode begins
  Competition.autonomous(autonomous);

  // Sets the void userControl to be run when driver control mode begins
  Competition.drivercontrol(userControl);

  // Keeps the code running forever until stopped
  while(true) {
    wait(100, msec);
  }
}