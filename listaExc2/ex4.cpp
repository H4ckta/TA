const int ledPinos[] = {5, 4, 3};
const int numLEDs = sizeof(ledPinos) / sizeof(ledPinos[0]);

void setup() {
  // Configura os pinos dos LEDs como saídas
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPinos[i], OUTPUT);
  }
}

void loop() {
  int tempo_ms = 5;

  while (tempo_ms <= 5000) {
    for (int i = 0; i < numLEDs; i++) {
      // Liga o LED
      digitalWrite(ledPinos[i], HIGH);
      delay(tempo_ms);

      // Desliga o LED
      digitalWrite(ledPinos[i], LOW);
      delay(tempo_ms);
    }
    tempo_ms = tempo_ms * 1.15;  // Aumenta o tempo em 15% a cada loop
  }
}
