using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor frontLeft;
extern motor midLeft;
extern motor rearLeft;
extern motor frontRight;
extern motor midRight;
extern motor rearRight;
extern motor puncher;
extern motor intake;
extern motor_group leftDrivetrain;
extern motor_group rightDrivetrain;
extern pneumatics rightWing;
extern pneumatics leftWing;
extern controller Controller1;
extern vex::triport ThreeWire = vex::triport(vex::PORT22);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );