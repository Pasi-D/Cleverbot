#include <AFMotor.h>

AF_DCMotor LMotor(1, MOTOR12_64KHZ); //Create Motor #1, 64KHz pwm
AF_DCMotor RMotor(2, MOTOR12_64KHZ); //Create Motor #1, 64KHz pwm


// Defining Sonars 

#define F_Trig 32 //Front
#define F_Echo 42

#define L_Trig 30 //Left
#define L_Echo 40 

#define R_Trig 34 //Right
#define R_Echo 44

int maximumRange = 17 ; // Maximum range needed. | Change the values if required
int minimumRange = 0; // Minimum range needed | Change the values if required

long FDuration, FDistance;
long LDuration, LDistance;
long RDuration, RDistance;
void setup() {
    
    Serial.begin(9600);

    pinMode(F_Trig,OUTPUT);
    pinMode(F_Echo,INPUT);
  
    pinMode(L_Trig,OUTPUT);
    pinMode(L_Echo,INPUT);
  
    pinMode(R_Trig,OUTPUT);
    pinMode(R_Echo,INPUT);

    RMotor.setSpeed(200); //Change the Speed as required
    LMotor.setSpeed(100); 


}

void loop() {
  // put your main code here, to run repeatedly:

}
