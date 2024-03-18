
const int ledPinos[] = {3, 4, 5};
const int numLEDs = sizeof(ledPinos) / sizeof(ledPinos[0]);

void setup() {
 
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPinos[i], OUTPUT);
  }
}

void loop() {
  int tempo_ms = 5000; // Tempo inicial em milissegundos

  while (tempo_ms >= 5) { // Condição de parada do loop
    for (int i = 0; i < numLEDs; i++) {
      // Liga o LED
      digitalWrite(ledPinos[i], HIGH);
      delay(tempo_ms);

      // Desliga o LED
      digitalWrite(ledPinos[i], LOW);
      delay(tempo_ms);
    }
    tempo_ms = tempo_ms * 0.8;  // Diminui o tempo em 20% a cada loop
  }
}
