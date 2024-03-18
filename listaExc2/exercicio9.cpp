const int buttonPin1 = 6;
const int buttonPin2 = 4;
const int ledPin = 3;

int buttonState1 = 0;
int buttonState2 = 0;
bool ledState = false;
bool flashing = false;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 == HIGH) {
    ledState = true;
    flashing = false;
  }
  if (buttonState2 == HIGH) {
    ledState = false;
    flashing = false;
  }
  if (buttonState1 == HIGH && buttonState2 == HIGH) {
    flashing = true;
  }
  digitalWrite(ledPin, ledState);
  if (flashing) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    delay(500);
  }
}
