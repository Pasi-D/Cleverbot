void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorval = analogRead(A0);
  Serial.println(sensorval);
  if(sensorval < 1000){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);  
  }
  delay(10);

}
