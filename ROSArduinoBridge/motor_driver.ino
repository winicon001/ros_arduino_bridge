/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   
#ifdef POLOLU_VNH5019
  /* Include the Pololu library */
  #include "DualVNH5019MotorShield.h"

  /* Create the motor driver object */
  DualVNH5019MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined POLOLU_MC33926
  /* Include the Pololu library */
  #include "DualMC33926MotorShield.h"

  /* Create the motor driver object */
  DualMC33926MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined L298_MOTOR_DRIVER

  void initMotorController() {
    digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
    digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    
    if (i == LEFT) { 
      if      //(reverse == 0) { analogWrite(LEFT_MOTOR_FORWARD, spd); analogWrite(LEFT_MOTOR_BACKWARD, 0); }
      else if //(reverse == 1) { analogWrite(LEFT_MOTOR_BACKWARD, spd); analogWrite(LEFT_MOTOR_FORWARD, 0); }
    }
    else /*if (i == RIGHT) //no need for condition*/ {
      if      //(reverse == 0) { analogWrite(RIGHT_MOTOR_FORWARD, spd); analogWrite(RIGHT_MOTOR_BACKWARD, 0); }
      else if //(reverse == 1) { analogWrite(RIGHT_MOTOR_BACKWARD, spd); analogWrite(RIGHT_MOTOR_FORWARD, 0); }
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }



// ####################################################
// ## MY DRIVER - DRV8833 MOTOR DRIVER
// ####################################################

#elif defined DRV8833_MOTOR_DRIVER

// Initialise Motor Control to stop position by default
  void initMotorController() {
    digitalWrite(RIGHT_MOTOR_CTRL, LOW);
    digitalWrite(LEFT_MOTOR_CTRL, LOW);
    analogWrite(RIGHT_MOTOR_PWM, 0);
    analogWrite(LEFT_MOTOR_PWM, 0);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    
    if (i == LEFT) { 
      // Right Wheel Reverse if Reverse Bit == 1
      if      (reverse == 1) {digitalWrite(LEFT_MOTOR_CTRL, LOW); analogWrite(LEFT_MOTOR_PWM, spd);} // Right Wheels = Motor 1 on Test Code
      // Right Wheel Forward if Reverse Bit == 1
      else if (reverse == 0) {digitalWrite(LEFT_MOTOR_CTRL, HIGH); analogWrite(LEFT_MOTOR_PWM, spd);} // Right Wheels = Motor 1 on Test Code

      //digitalWrite(RIGHT_MOTOR_CTRL, HIGH); analogWrite(RIGHT_MOTOR_PWM, 0); // Left Weels = Motor 2 on Test Code
    }
    else /*if (i == RIGHT) //no need for condition*/ {
      // Left Wheel Reverse if Reverse Bit == 1
      if      (reverse == 1) {digitalWrite(RIGHT_MOTOR_CTRL, LOW); analogWrite(RIGHT_MOTOR_PWM, spd);} // Left Wheels = Motor 1 on Test Code
      // Left Wheel Forward if Reverse Bit == 1
      else if (reverse == 0) {digitalWrite(RIGHT_MOTOR_CTRL, HIGH); analogWrite(RIGHT_MOTOR_PWM, spd);} // Left Wheels = Motor 1 on Test Code
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#else
  #error A motor driver must be selected!
#endif

#endif
