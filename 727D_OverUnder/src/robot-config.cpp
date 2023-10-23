#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor frontLeft = motor(PORT11, ratio18_1, true);
motor midLeft = motor(PORT13, ratio18_1, true);
motor rearLeft = motor(PORT12, ratio18_1, true);
motor frontRight = motor(PORT20, ratio18_1, false);
motor midRight = motor(PORT18, ratio18_1, false);
motor rearRight = motor(PORT19, ratio18_1, false);
motor puncher = motor(PORT14, ratio18_1, true);
pneumatics clawOpen = pneumatics(Brain.ThreeWirePort.H);
pneumatics clawDrop = pneumatics(Brain.ThreeWirePort.G);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}