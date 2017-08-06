int switchpin = 3;
int Ledpin = 12;
boolean lastbutton = LOW;
boolean currentbutton = LOW;
boolean ledOn = false;

void setup() {
 pinMode(switchpin, INPUT);
 pinMode(Ledpin, OUTPUT);

}

boolean debounce(boolean last){
  boolean current = digitalRead(switchpin);
  if(last != current){
    delay(5);
    current = digitalRead(switchpin);
    }
    return current;
  }

void loop() {
  currentbutton = debounce(lastbutton);
  if(lastbutton==LOW && currentbutton == HIGH){    
    ledOn = !ledOn;    
    }
    lastbutton = currentbutton;
    digitalWrite(Ledpin, ledOn);
}
