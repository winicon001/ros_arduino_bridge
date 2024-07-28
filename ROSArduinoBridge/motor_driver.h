/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

// #ifdef L298_MOTOR_DRIVER
//   #define RIGHT_MOTOR_BACKWARD 5
//   #define LEFT_MOTOR_BACKWARD  6
//   #define RIGHT_MOTOR_FORWARD  9
//   #define LEFT_MOTOR_FORWARD   10
//   #define RIGHT_MOTOR_ENABLE 12
//   #define LEFT_MOTOR_ENABLE 13
// #endif

#ifdef DRV8833_MOTOR_DRIVER
  #define RIGHT_MOTOR_CTRL 4
  #define RIGHT_MOTOR_PWM 6
  #define LEFT_MOTOR_CTRL  10
  #define LEFT_MOTOR_PWM  5
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
