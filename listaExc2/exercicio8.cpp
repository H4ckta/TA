const int pirPin = 6;
const int ledPin = 4;

bool ledState = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  int motionState = digitalRead(pirPin);
  if (motionState == HIGH && !ledState) {
    digitalWrite(ledPin, HIGH);
    ledState = true;
    delay(4000); 
  } 
  else if (motionState == LOW && ledState) {
    digitalWrite(ledPin, LOW);
    ledState = false;
  }
}
