#define Switch 52

#define CTrig 32    /*C*/
#define CEcho 42

#define LTrig 30  /*L*/
#define LEcho 40

#define RTrig 34 /*R*/
#define REcho 44


#define RLEDPin 50
#define LLEDPin 51

#include <AFMotor.h>

AF_DCMotor leftMotor(4, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor rightMotor(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

int maximumRange = 20; // Maximum range needed
int minimumRange = 0; // Minimum range needed

long Cduration, Cdistance;
long Rduration, Rdistance;
long Lduration, Ldistance;

int t = 500;
int state;
int SwitchState;


void setup() {
  pinMode(CTrig, OUTPUT);
  pinMode(CEcho, INPUT);

  pinMode(LTrig, OUTPUT);
  pinMode(LEcho, INPUT);

  pinMode(RTrig, OUTPUT);
  pinMode(REcho, INPUT);

  pinMode(RLEDPin, OUTPUT);
  pinMode(LLEDPin, OUTPUT);

  leftMotor.setSpeed(500);
  rightMotor.setSpeed(500);
  //pinMode(Switch, INPUT);
}

void loop() {
  /*SwitchState = digitalRead(Switch);

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
*/


    digitalWrite(CTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(CTrig, HIGH);
    delayMicroseconds(10);
    Cduration = pulseIn(CEcho, HIGH);

    digitalWrite(LTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(LTrig, HIGH);
    delayMicroseconds(10);
    Lduration = pulseIn(LEcho, HIGH);

    digitalWrite(RTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(RTrig, HIGH);
    delayMicroseconds(10);
    Rduration = pulseIn(REcho, HIGH);

    Cdistance = Cduration / 58.2;
    Ldistance = Lduration / 58.2;
    Rdistance = Rduration / 58.2;

    if (Ldistance >= maximumRange && Ldistance >= maximumRange && Ldistance >= maximumRange) {
      /*left right front free*/
      leftMotor.run(RELEASE);
      rightMotor.run(RELEASE);
    }
    else {

      if (Ldistance >= maximumRange) {
        /*LEFT FREE*/
        digitalWrite(LLEDPin, HIGH);
        digitalWrite(RLEDPin, LOW);

        rightMotor.run(BACKWARD);
        delay(t);
        rightMotor.run(RELEASE);
      }
      else {
        if (Cdistance >= maximumRange) {
          /*LEFT SHIT FRONT FREE*/
          digitalWrite(RLEDPin, HIGH);
          digitalWrite(LLEDPin, HIGH);

          leftMotor.run(BACKWARD);
          rightMotor.run(BACKWARD);
          delay(t);
          leftMotor.run(RELEASE);
          rightMotor.run(RELEASE);
        }
        else {

          if (Rdistance >= maximumRange) {
            /*LEFT,FRONT SHIT RIGHT FREE*/
            digitalWrite(RLEDPin, HIGH);
            digitalWrite(LLEDPin, LOW);

            leftMotor.run(BACKWARD);
            delay(t);
            leftMotor.run(RELEASE);
          }
          else {
            /*LEFT,FRONT,RIGHT SHIT*/
            digitalWrite(RLEDPin, LOW);
            digitalWrite(LLEDPin, LOW);

            leftMotor.run(BACKWARD);
            rightMotor.run(FORWARD);
            delay(t);
            leftMotor.run(RELEASE);
            rightMotor.run(RELEASE);
          }
        }
      }
      delay(50);
    }
  


  
}
