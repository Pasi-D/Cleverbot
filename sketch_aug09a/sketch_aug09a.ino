int buttonpin = 4;

void setup() {
  // sets the button as an input
  pinMode(buttonpin,INPUT);

  //Allows us to listen to serial communication from the arduino
  Serial.begin(9600);  

}

void loop() {
  // print the button state to a serial terminal
  Serial.println(digitalRead(buttonpin));
  //delay(1000);
  //wait one second and print again

}
