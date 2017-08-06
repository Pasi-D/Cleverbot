int trigPin = 2;
int echoPin = 4;
int led1 = 8;
int led2 = 9;
int led3 = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);  
}

void loop() {
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.1;

  if(distance <= 14){
    digitalWrite(led1,HIGH);
    }
  else{
    digitalWrite(led1,LOW);
    }
  if(distance < 8){
    digitalWrite(led2,HIGH);
    }
  else{
    digitalWrite(led2,LOW);
    }
  if(distance <= 2){
    digitalWrite(led3,HIGH);
    }
  else{
    digitalWrite(led3,LOW);
    }
  if(distance > 14 || distance <= 0){
    Serial.println("Out Of Range");
    }
    else{
      Serial.print(distance);
      Serial.print(" cm");
      Serial.println();
      }
    delay(15);

}
