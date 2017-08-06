int tcrt;
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  tcrt = analogRead(A0);
  analogWrite(13,tcrt/4);
  Serial.println(tcrt);
  delay(150);

}
