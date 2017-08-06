#define IR1 38
#define IR2 40
#define IR3 42
#define IR4 44
#define IR5 46
#define IR6 48
#define Switch 52
#define LED 50
#define LED2 51
#define CTrig 25
#define CEcho 24
#define LTrig 23
#define LEcho 22
#define RTrig 27
#define REcho 26

#include <AFMotor.h>

AF_DCMotor leftMotor(4, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor rightMotor(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

int left = HIGH;
int right = HIGH;
int Rcenter = HIGH;
int Lcenter = HIGH;
int BRcenter = HIGH;
int BLcenter = HIGH;
int t = 100;
int state;
int SwitchState;


void setup() {

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);

  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  leftMotor.setSpeed(200);
  rightMotor.setSpeed(200);
  pinMode(Switch, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);


}
void loop() {
  right = digitalRead(IR4);
  Rcenter = digitalRead(IR3);
  Lcenter = digitalRead(IR2);
  BRcenter = digitalRead(IR6);
  BLcenter = digitalRead(IR5);
  left = digitalRead(IR1);
  SwitchState = digitalRead(Switch);

  if (SwitchState == HIGH) {//switching system
    delay(1000);
    if (state == 0) {
      state = 1;
    }
    else {
      if (state == 1) {
        state = 0;
      }
    }

  }


  if (state == 1) {
    digitalWrite(LED, LOW);
    digitalWrite(LED2, HIGH);

  }
  if (state == 0) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED, HIGH);

  }





  if (state == 1) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED, LOW);



    if ((BRcenter == HIGH || BLcenter == HIGH) && right == HIGH && left == HIGH) {
      leftMotor.run(RELEASE);
      rightMotor.run(RELEASE);
    }
    else {

      if (BRcenter == HIGH || BLcenter == HIGH) {
        leftMotor.run(BACKWARD);
        rightMotor.run(BACKWARD);
        delay(t);
        leftMotor.run(RELEASE);
        rightMotor.run(RELEASE);


      }
      else {
        if (left == HIGH) {
          rightMotor.run(BACKWARD);
          delay(t);
          rightMotor.run(RELEASE);
        }
        else {
          if (right == HIGH) {
            leftMotor.run(BACKWARD);
            delay(t);
            leftMotor.run(RELEASE);
          }
          else {
            leftMotor.run(BACKWARD);
            rightMotor.run(FORWARD);
            delay(t);
            leftMotor.run(RELEASE);
            rightMotor.run(RELEASE);

          }
        }
      }
    }
  }
  else {
    digitalWrite(LED, HIGH);
    digitalWrite(LED2, LOW);
  }
}
