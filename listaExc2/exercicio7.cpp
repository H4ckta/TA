const int buttonPin = 6;
const int ledPin = 4;

int buttonState = 0;
int lastButtonState = 0;
int clickCount = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    clickCount++;
    for (int i = 0; i < clickCount; i++) {
      digitalWrite(ledPin, HIGH);
      delay(500); 
      digitalWrite(ledPin, LOW);
      delay(500); 
    }
  }
  lastButtonState = buttonState;
}
