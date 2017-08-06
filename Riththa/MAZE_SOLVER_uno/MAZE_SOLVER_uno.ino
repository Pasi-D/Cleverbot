#define Switch 52

#define CTrig 25    /*C*/
#define CEcho 24

#define LTrig 23  /*L*/
#define LEcho 22

#define RTrig 27 /*R*/
#define REcho 26



#include <AFMotor.h>

AF_DCMotor leftMotor(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor rightMotor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

int maximumRange = 15; // Maximum range needed
int minimumRange = 0; // Minimum range needed

long Cduration, Cdistance;
long Rduration, Rdistance;
long Lduration, Ldistance;

int t = 10;
int state;
int SwitchState;


void setup() {
  pinMode(CTrig, OUTPUT);
  pinMode(CEcho, INPUT);

  pinMode(LTrig, OUTPUT);
  pinMode(LEcho, INPUT);

  pinMode(RTrig, OUTPUT);
  pinMode(REcho, INPUT);



  leftMotor.setSpeed(250);
  rightMotor.setSpeed(250);
  pinMode(Switch, INPUT);


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

    } */
  state = 1;
  if (state == 1) {



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
    //
    //    if (Ldistance >= maximumRange && Ldistance >= maximumRange && Ldistance >= maximumRange) {
    //      /*left right front free*/
    //      leftMotor.run(RELEASE);
    //      rightMotor.run(RELEASE);
    //    }
    //    else {

    if (Ldistance >= maximumRange) {
      leftMotor.run(FORWARD);
      delay(t);
      leftMotor.run(RELEASE);
    }
    else {
      if (Ldistance <= maximumRange && Cdistance >= maximumRange) {
        /*LEFT SHIT FRONT FREE*/


        leftMotor.run(BACKWARD);
        rightMotor.run(BACKWARD);
        delay(t);
        leftMotor.run(RELEASE);
        rightMotor.run(RELEASE);
      }
      else {

        if (Ldistance <= maximumRange && Cdistance <= maximumRange && Rdistance >= maximumRange) {
          /*LEFT,FRONT SHIT RIGHT FREE*/


          rightMotor.run(FORWARD);
          delay(t);
          rightMotor.run(RELEASE);
        }
        else {
          /*LEFT,FRONT,RIGHT SHIT*/


          leftMotor.run(BACKWARD);
          rightMotor.run(FORWARD);
          delay(t);
          leftMotor.run(RELEASE);
          rightMotor.run(RELEASE);
        }
      }
    }

  }
  //  }


  else {


  }
}
