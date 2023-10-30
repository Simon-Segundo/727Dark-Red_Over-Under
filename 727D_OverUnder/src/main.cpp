/*-------------------------- 727D_OverUnder INFO -----------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Authors:      Alex, Elissa, Jack, Luca, Simon                           */
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
// Controller1          controller             //     
// --------------------------------------------//

// Allows the library "vex.h" to be used
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

int numf = 0;
int numc = 0;

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

// Opens/Closes the claw on the front of the robot
void clawCtrl() {
  if(numc == 0) {
    clawOpen.open();
    numc++;
  } else {
    clawOpen.close();
    numc--;
  }
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

// Punches tri-ball forward when tri-ball is placed on top of robot
void falconPunch() {
  if(numf == 0) {
    puncher.spin(reverse, 15, velocityUnits::pct);
    numf++;
  } else {
    puncher.stop();
    numf--;
  }
}

// Code for autonomous period goes in this void
void autonomous(void) {

}

// Code for drivercontrol period goes in this void
void userControl(void) {
  while(1) {
    // Arcade steering using the left stick of the controller
    frontLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent)), velocityUnits::pct);
    midLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent)), velocityUnits::pct);
    rearLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent)), velocityUnits::pct);
    frontRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent)), velocityUnits::pct);
    midRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent)), velocityUnits::pct);
    rearRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent)), velocityUnits::pct);

    // Calls the openClaw function when button 'A' is pressed on the controller
    Controller1.ButtonA.pressed(clawCtrl);

    // Calls the terminator function when button 'R1' is pressed on the controller
    Controller1.ButtonR1.pressed(terminator);

    // Calls the falconPunch function when button 'B' is pressed on the controller
    Controller1.ButtonB.pressed(falconPunch);
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