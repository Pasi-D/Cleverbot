#include <AFMotor.h>

AF_DCMotor RMotor(1, MOTOR12_64KHZ); //Create Motor #1, 64KHz pwm
AF_DCMotor LMotor(2, MOTOR12_64KHZ); //Create Motor #1, 64KHz pwm

void right(){
  //left is right right is left
  
  LMotor.run(BACKWARD);
  LMotor.setSpeed(75);

  RMotor.run(FORWARD);
  RMotor.setSpeed(100);

  delay(1000);

  LMotor.run(BRAKE);
  LMotor.setSpeed(0);

  RMotor.run(BRAKE);
  RMotor.setSpeed(0);

  
  }

void Forward(){
  RMotor.run(FORWARD);
  RMotor.setSpeed(75);

  LMotor.run(FORWARD);
  LMotor.setSpeed(90);
  }


void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  Forward();
  delay(1000);
  

}
