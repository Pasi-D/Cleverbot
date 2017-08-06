/*Turning the build in LED on and off again in Arduino board
 * 
 */
int ledpin = 13;
void setup() {
  //Initilaize the pins as Output
  pinMode(ledpin,OUTPUT);
}

void loop() {
  digitalWrite(ledpin,HIGH);
  delay(1000);
  digitalWrite(ledpin,LOW);
  delay(1000);
}

