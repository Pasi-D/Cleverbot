#define C_Trig 32 //Center
#define C_Echo 42

#define L_Trig 30 //Left
#define L_Echo 40 

#define R_Trig 34 //Right
#define R_Echo 44

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

void loop() {

//Center Pulse Read
  digitalWrite(C_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(C_Trig, HIGH);
  delayMicroseconds(10);
  CDuration = pulseIn(C_Echo, HIGH);

//Left Pulse Read  
  digitalWrite(L_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(L_Trig, HIGH);
  delayMicroseconds(10);
  LDuration = pulseIn(L_Echo, HIGH);

//Right Pulse Read  
  digitalWrite(R_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(R_Trig, HIGH);
  delayMicroseconds(10);
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

}
