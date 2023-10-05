using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor frontLeft;
extern motor midLeft;
extern motor rearLeft;
extern motor frontRight;
extern motor midRight;
extern motor rearRight;
extern pneumatics ClawOpen1;
extern pneumatics ClawOpen2;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );