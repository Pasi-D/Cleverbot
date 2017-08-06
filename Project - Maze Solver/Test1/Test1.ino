#include <AFMotor.h>

AF_DCMotor RMotor(1, MOTOR12_64KHZ); //Create Motor #1, 64KHz pwm
AF_DCMotor LMotor(2, MOTOR12_64KHZ); //Create Motor #1, 64KHz pwm

int Max = 5;

int LS = 90;
int RS = 75;

#define C_Trig 32 //Center
#define C_Echo 42

#define L_Trig 30 //Left
#define L_Echo 40 

#define R_Trig 34 //Right
#define R_Echo 44

int maximumRange = 20; // Maximum range needed
//int minimumRange = 0; // Minimum range needed

int Front = 30;
int Sides = 5;

/*bool stateL;
bool stateC;
bool stateR;*/

long CDuration, CDistance;
long LDuration, LDistance;
long RDuration, RDistance;


void setup() {
  
  Serial.begin(9600);

  pinMode(C_Trig,OUTPUT);
  pinMode(C_Echo,INPUT);

  pinMode(L_Trig,OUTPUT);
  pinMode(L_Echo,INPUT);

  pinMode(R_Trig,OUTPUT);
  pinMode(R_Echo,INPUT);

}
/*
bool TrigEcho(int trig,int echo){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

  long duration = pulseIn(echo,HIGH);
  if (duration/29/2 > Max) {
      return true;
      }
    else {
      return false;
      }
  }*/
void loop() {
  //Center Pulse Read
  digitalWrite(C_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(C_Trig, HIGH);
  delayMicroseconds(20);
  CDuration = pulseIn(C_Echo, HIGH);

//Left Pulse Read  
  digitalWrite(L_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(L_Trig, HIGH);
  delayMicroseconds(20);
  LDuration = pulseIn(L_Echo, HIGH);

//Right Pulse Read  
  digitalWrite(R_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(R_Trig, HIGH);
  delayMicroseconds(20);
  RDuration = pulseIn(R_Echo, HIGH);
  
  CDistance = CDuration / 58.2;
  LDistance = LDuration / 58.2;
  RDistance = RDuration / 58.2;

  Serial.print("||");
  Serial.print("Left: ");
  Serial.print(LDistance);
  Serial.print("||");
  Serial.print("Center: ");
  Serial.print(CDistance);
  Serial.print("||");
  Serial.print("Right: ");
  Serial.print(RDistance);
  Serial.print("||");
  Serial.print("\n\n");
  delay(150);

if(CDistance < Front){
  RMotor.setSpeed(0);
  LMotor.setSpeed(0);
  delay(1000);

  if(LDistance > Sides){
    Left();
    delay(1000);
    }
  else if(RDistance > Sides){
    Right();
    delay(1000);
    }
  }else{
    Forward();
    delay(50);
    }

/*  stateL = TrigEcho(L_Trig,L_Echo);
  stateC = TrigEcho(C_Trig,C_Echo);
  stateR = TrigEcho(R_Trig,R_Echo);*/
  
  
  
  

  
}

void Left(){
  LMotor.run(FORWARD);
  LMotor.setSpeed(LS);

  RMotor.run(BACKWARD);
  RMotor.setSpeed(RS);

  delay(1000);

  LMotor.run(BRAKE);
  LMotor.setSpeed(0);

  RMotor.run(BRAKE);
  RMotor.setSpeed(0);
 
  }

void Right(){
  //left is right right is left
  
  LMotor.run(BACKWARD);
  LMotor.setSpeed(LS);

  RMotor.run(FORWARD);
  RMotor.setSpeed(RS);

  delay(1000);

  LMotor.run(BRAKE);
  LMotor.setSpeed(0);

  RMotor.run(BRAKE);
  RMotor.setSpeed(0);
 
  }

void Forward(){
  RMotor.run(FORWARD);
  RMotor.setSpeed(RS);

  LMotor.run(FORWARD);
  LMotor.setSpeed(LS);
  }
