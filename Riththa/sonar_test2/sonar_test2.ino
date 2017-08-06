#define CTrig 25    /*C*/
#define CEcho 24

#define LTrig 23  /*L*/
#define LEcho 22

#define RTrig 27 /*R*/
#define REcho 26


#define RLEDPin 50
#define LLEDPin 51

int maximumRange = 10; // Maximum range needed
int minimumRange = 0; // Minimum range needed

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

  pinMode(RLEDPin, OUTPUT);
  pinMode(LLEDPin, OUTPUT);
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

  if (Cdistance >= maximumRange || Cdistance <= minimumRange) {
    Serial.print("FRONT OK +++");
    digitalWrite(RLEDPin, LOW);
    digitalWrite(LLEDPin, LOW);
  }
  else {
    Serial.print("FRONT shit +++");
    digitalWrite(RLEDPin, HIGH);
    digitalWrite(LLEDPin, HIGH);
  }



  if (Rdistance >= maximumRange || Rdistance <= minimumRange) {

    Serial.print("RIGHT OK +++");
    digitalWrite(RLEDPin, LOW);
  }
  else {
    Serial.print("RIGHT shit +++");
    digitalWrite(RLEDPin, HIGH);
  }



  if (Ldistance >= maximumRange || Ldistance <= minimumRange) {
    Serial.print("LEFT OK +++");
    digitalWrite(LLEDPin, LOW);
  }
  else {
    /* Send the distance to the computer using Serial protocol, and
      turn LED OFF to indicate successful reading. */
    Serial.print("LEFT shit +++");
    digitalWrite(LLEDPin, HIGH);
  }


  Serial.print("\n\n");
  delay(50);
}
