/* *************************************************************
   Encoder definitions
   
   Add an "#ifdef" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */
#include "TimerOne.h"

#ifdef USE_BASE

#ifdef ROBOGAIA
  /* The Robogaia Mega Encoder shield */
  #include "MegaEncoderCounter.h"

  /* Create the encoder shield object */
  MegaEncoderCounter encoders = MegaEncoderCounter(4); // Initializes the Mega Encoder Counter in the 4X Count mode
  
  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return encoders.YAxisGetCount();
    else return encoders.XAxisGetCount();
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT) return encoders.YAxisReset();
    else return encoders.XAxisReset();
  }


#elif defined(ARDUINO_ENC_COUNTER)
  volatile long left_enc_pos = 0L;
  volatile long right_enc_pos = 0L;
  static const int8_t ENC_STATES [] = {0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};  //encoder lookup table
    
  /* Interrupt routine for LEFT encoder, taking care of actual counting */
  ISR (PCINT2_vect){
  	static uint8_t enc_last=0;
        
	enc_last <<=2; //shift previous state two places
	enc_last |= (PIND & (3 << 2)) >> 2; //read the current state into lowest 2 bits
  
  	left_enc_pos += ENC_STATES[(enc_last & 0x0f)];
  }
  
  /* Interrupt routine for RIGHT encoder, taking care of actual counting */
  ISR (PCINT1_vect){
        static uint8_t enc_last=0;
          	
	enc_last <<=2; //shift previous state two places
	enc_last |= (PINC & (3 << 4)) >> 4; //read the current state into lowest 2 bits
  
  	right_enc_pos += ENC_STATES[(enc_last & 0x0f)];
  }
  
  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return left_enc_pos;
    else return right_enc_pos;
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT){
      left_enc_pos=0L;
      return;
    } else { 
      right_enc_pos=0L;
      return;
    }
  }

// ################################################################
// ################################################################

#elif defined(ARDUINO_ENC_COUNTER_2)
//     /* My Encoder */
//     #include "TimerOne.h"



//   // Constants for Interrupt Pins
//   // Change values if not using Arduino Uno

//   const byte RIGHT_ENCODER = 2;  // RIght Encoder Interrupt Pin - INT 0
//   const byte LEFT_ENCODER = 3;  // Left Encoder Interrupt Pin - INT 1

//   // Integers for pulse counters
//   unsigned int Right_Encoder_counter = 0;
//   unsigned int Left_Encoder_counter = 0;

//   // Float for number of slots in encoder disk
//   float diskslots = 20;  // Change to match value of encoder disk

//   // Interrupt Service Routines

//   // RIght Encoder pulse count ISR
//   void ISR_count1()  
//   {
//     Right_Encoder_counter++;  // increment RIght Encoder counter value
//   } 

//   // Left Encoder pulse count ISR
//   void ISR_count2()  
//   {
//     Left_Encoder_counter++;  // increment Left Encoder counter value
//   } 

    
//   //Timer1.initialize(1000000); // set timer for 1sec
//   // attachInterrupt(digitalPinToInterrupt (RIGHT_ENCODER), ISR_count1, RISING);  // Increase Right counter when speed sensor pin goes High
//   // attachInterrupt(digitalPinToInterrupt (LEFT_ENCODER), ISR_count2, RISING);  // Increase Left counter when speed sensor pin goes High
//   //Timer1.attachInterrupt( ISR_timerone ); // Enable the timer


//  /* Wrap the encoder reading function */
//   /* Wrap the encoder reading function */
//   long readEncoder(int i) {
//     if (i == LEFT) return Left_Encoder_counter;
//     else return Right_Encoder_counter;
//   }

//   /* Wrap the encoder reading function */
//   // long readEncoder(int i) {
//   //   if (i == RIGHT) return Right_Encoder_counter;
//   //   else return Left_Encoder_counter;
//   // }



  // ################################################################################
  // ################################################################################


#else
  #error A encoder driver must be selected!
#endif

void resetEncoder(int i) {
    if (i == LEFT){
      Left_Encoder_counter=0L;
      return;
    } else { 
      Right_Encoder_counter=0L;
      return;
    }
  }

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif

