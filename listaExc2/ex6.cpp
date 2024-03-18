
const int ledPinos[] = {3, 4, 5};
const int numLEDs = sizeof(ledPinos) / sizeof(ledPinos[0]);
const int botaoPino = 2;


bool botaoPressionado = false;
int ledAtual = 0; 

void setup() {
  // Configura os pinos dos LEDs como saídas
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPinos[i], OUTPUT);
    digitalWrite(ledPinos[i], LOW); // Desliga todos os LEDs inicialmente
  }

  
  pinMode(botaoPino, INPUT);
}

void loop() {
  // Verifica se o botão foi pressionado
  if (digitalRead(botaoPino) == HIGH && !botaoPressionado) {
    botaoPressionado = true; // Marca o botão como pressionado

    // Alterna o estado do LED atual
    digitalWrite(ledPinos[ledAtual], !digitalRead(ledPinos[ledAtual]));

    // Se o LED atual foi desligado, avança para o próximo LED
    if (digitalRead(ledPinos[ledAtual]) == LOW) {
      ledAtual = (ledAtual + 1) % numLEDs;
    }
  }

  // Verifica se o botão foi solto
  if (digitalRead(botaoPino) == LOW && botaoPressionado) {
    botaoPressionado = false; // Marca o botão como não pressionado
  }
}
