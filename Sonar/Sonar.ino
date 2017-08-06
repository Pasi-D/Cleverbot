#define CTrig 30    /*C*/
#define CEcho 42

#define LTrig 28  /*L*/
#define LEcho 40

#define RTrig 32 /*R*/
#define REcho 44


long Cduration, Cdistance;
long Rduration, Rdistance;
long Lduration, Ldistance;

void setup() {
  Serial.begin (9600);

  pinMode(CTrig, OUTPUT);
  pinMode(CEcho, INPUT);

  pinMode(LTrig, OUTPUT);
  pinMode(LEcho, INPUT);

  pinMode(RTrig, OUTPUT);
  pinMode(REcho, INPUT);
}

void loop() {

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

  Serial.print(Cduration);
  Serial.print("    ");

  Serial.print(Lduration);
  Serial.print("    ");

  Serial.println(Rduration);

  Serial.print(Cdistance);
  Serial.print("    ");

  Serial.print(Ldistance);
  Serial.print("    ");

  Serial.println(Rdistance);


  Serial.print("\n\n");
  delay(150);

}
