/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Engineering                                      */
/*    Created:      Wed Sep 13 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// frontLeft            motor         11              
// midLeft              motor         13              
// rearLeft             motor         12              
// frontRight           motor         20              
// midRight             motor         18              
// rearRight            motor         19              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

void set_spin(motor spin_motor, int Velocity, int Torque, bool fob) {
  spin_motor.setVelocity(Velocity, percent);
  spin_motor.setMaxTorque(Torque, percent);
  if (fob){
    spin_motor.spin(forward);
  } else {
    spin_motor.spin(reverse);
  }
}

void forwardFor(int deg, int speed) {
  frontLeft.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  midLeft.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  rearLeft.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  frontRight.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  midRight.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  rearRight.spinFor(deg, rotationUnits::deg, speed, velocityUnits::pct, false);
}

void reverseFor(int deg, int speed) {
  frontLeft.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  midLeft.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  rearLeft.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  frontRight.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  midRight.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
  rearRight.spinFor(-deg, rotationUnits::deg, speed, velocityUnits::pct, false);
}

void OpenClaw() {
  int num = 0;
  if(num == 0) {
    ClawOpen.open();
    num++;
  } else {
    ClawOpen.close();
    num--;
  }
}

void turn180() {
  set_spin(frontLeft, 75, 100, true);
  set_spin(midLeft, 75, 100, true);
  set_spin(rearLeft, 75, 100, true);
  set_spin(frontRight, 75, 100, false);
  set_spin(midRight, 75, 100, false);
  set_spin(rearRight, 75, 100, false);
  wait(1.5, sec);
  frontLeft.stop();
  midLeft.stop();
  rearLeft.stop();
  frontRight.stop();
  midRight.stop();
  rearRight.stop();
}

void autonomous(void) {

}

void userControl(void) {
  while(1) {
    // Arcade steering using the left stick of the controller
    frontLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent)), velocityUnits::pct);
    midLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent)), velocityUnits::pct);
    rearLeft.spin(fwd, (Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent)), velocityUnits::pct);
    frontRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent)), velocityUnits::pct);
    midRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent)), velocityUnits::pct);
    rearRight.spin(fwd, (Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent)), velocityUnits::pct);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // Calls the OpenClaw function when button 'A' is pressed on the controller
  Controller1.ButtonA.pressed(OpenClaw);
  // Calls the turn180 function when button 'R1' is pressed on the controller
  Controller1.ButtonR1.pressed(turn180);
  // Sets the void autonomous to be run when autonomous mode begins
  Competition.autonomous(autonomous);
  // Sets the void userControl to be run when driver control mode begins
  Competition.drivercontrol(userControl);

  while(true) {
    wait(100, msec);
  }
}