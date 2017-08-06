
#define IR 40   
int detection = HIGH;    // no obstacle
void setup() {
  Serial.begin(9600);   
  pinMode(IR, INPUT); 
}
void loop() {  
  detection = digitalRead(IR);
  if(detection == LOW){
    Serial.print(IR);
    Serial.print("\n");
  }
  else{ 
    Serial.print(IR);
    Serial.print("\n");
  }
  delay(500);    // in ms
}
