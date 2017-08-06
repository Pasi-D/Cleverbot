void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}
int t = 100;
void loop() {    
  for(int i = 6; i < 12; i++)
  {
    digitalWrite(i,HIGH);
    delay(t);
    digitalWrite(i,LOW);
    }

  for(int i = 10; i > 5; i--)
  {
    digitalWrite(i,HIGH);
    delay(t);
    digitalWrite(i,LOW);
    }

}
