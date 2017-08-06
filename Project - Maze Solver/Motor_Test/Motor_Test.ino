#include <AFMotor.h>

AF_DCMotor RMotor(1, MOTOR12_64KHZ); //Create Motor #1, 64KHz pwm
AF_DCMotor LMotor(2, MOTOR12_64KHZ); //Create Motor #1, 64KHz pwm

int v = 60;
int v1 = 40;

void Forward(){
  RMotor.run(FORWARD);
  RMotor.setSpeed(v);

  LMotor.run(FORWARD);
  LMotor.setSpeed(v);
  }

void Left()
{
  RMotor.run(RELEASE);
  RMotor.setSpeed(0);

  LMotor.run(RELEASE);
  LMotor.setSpeed(0);
  delay(1000);

  RMotor.run(BACKWARD);
  RMotor.setSpeed(100);

  LMotor.run(BACKWARD);
  LMotor.setSpeed(100);
  delay(150);

  RMotor.run(BACKWARD);
  RMotor.setSpeed(160);

  LMotor.run(FORWARD);
  LMotor.setSpeed(160);
  delay(101);
}
  
void setup() {
  //RMotor.setSpeed(60);
  //LMotor.setSpeed(60);
}

void loop() {
  /*RMotor.run(FORWARD);
  LMotor.run(FORWARD);
  delay(1000);
  
  RMotor.run(BACKWARD);
  LMotor.run(BACKWARD);
  delay(1000);

  
  RMotor.run(RELEASE);
  LMotor.run(RELEASE);
  delay(1000);*/

  Left();
  delay(1000);
}
