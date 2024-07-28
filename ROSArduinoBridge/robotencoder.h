// /*	
// 	Optical Sensor Two Motor Demonstration
// 	DualMotorSpeedDemo.ino
// 	Demonstrates use of Hardware Interrupts
// 	to measure speed from two motors
	
// 	DroneBot Workshop 2017
// 	http://dronebotworkshop.com
// */

// // Include the TimerOne Library from Paul Stoffregen


// // Constants for Interrupt Pins
// // Change values if not using Arduino Uno

// const byte RIGHT_ENCODER = 2;  // RIght Encoder Interrupt Pin - INT 0
// const byte LEFT_ENCODER = 3;  // Left Encoder Interrupt Pin - INT 1

// // Integers for pulse counters
// unsigned int Right_Encoder_counter = 0;
// unsigned int Left_Encoder_counter = 0;

// // Float for number of slots in encoder disk
// float diskslots = 20;  // Change to match value of encoder disk

// // Interrupt Service Routines

// // RIght Encoder pulse count ISR
// void ISR_count1()  
// {
//   Right_Encoder_counter++;  // increment RIght Encoder counter value
// } 

// // Left Encoder pulse count ISR
// void ISR_count2()  
// {
//   Left_Encoder_counter++;  // increment Left Encoder counter value
// } 

// // TimerOne ISR
// void ISR_timerone()
// {
//   Timer1.detachInterrupt();  // Stop the timer
//   //Serial.print("Motor Speed 1: "); 
//   float rotation1 = (Right_Encoder_counter / diskslots) * 60.00;  // calculate RPM for RIght Encoder
//   //Serial.print(rotation1);  
//   //Serial.print(" RPM - "); 
//   Right_Encoder_counter = 0;  //  reset counter to zero
//   //Serial.print("Motor Speed 2: "); 
//   float rotation2 = (Left_Encoder_counter / diskslots) * 60.00;  // calculate RPM for Left Encoder
//   //Serial.print(rotation2);  
//   //Serial.println(" RPM"); 
//   Left_Encoder_counter = 0;  //  reset counter to zero
//   Timer1.attachInterrupt( ISR_timerone );  // Enable the timer
// }
  
//   Timer1.initialize(1000000); // set timer for 1sec
//   attachInterrupt(digitalPinToInterrupt (RIGHT_ENCODER), ISR_count1, RISING);  // Increase Right counter when speed sensor pin goes High
//   attachInterrupt(digitalPinToInterrupt (LEFT_ENCODER), ISR_count2, RISING);  // Increase Left counter when speed sensor pin goes High
//   Timer1.attachInterrupt( ISR_timerone ); // Enable the timer

