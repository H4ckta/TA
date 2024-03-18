const int buttonPin = 2;
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9};

int contador = 0; 
bool buttonState = false;  
bool lastButtonState = false;  
bool direcaoCrescente = true;  
unsigned long ultimoTempo = 0;  // Variável para armazenar o último tempo de mudança de contador
unsigned long intervalo = 1000;  // Intervalo de tempo em milissegundos para mudança automática do contador

void setup() {
  // Configura os LEDs como saída
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Configura o pino do botão como entrada
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Lê o estado atual do botão
  buttonState = digitalRead(buttonPin);

  // Verifica se houve uma transição de pressionado para não pressionado
  if (buttonState == LOW && lastButtonState == HIGH) {
    alterarDirecao();  // Altera a direção do contador
  }

  // Verifica se é hora de mudar automaticamente o contador
  if (millis() - ultimoTempo >= intervalo) {
    if (direcaoCrescente) {
      contador++;  // Incrementa o contador se estiver na direção crescente
      if (contador > 9) {
        contador = 9;  // Limita o contador em 9
        direcaoCrescente = false;  // Muda a direção para decrescente
      }
    } else {
      contador--;  // Decrementa o contador se estiver na direção decrescente
      if (contador < 0) {
        contador = 0;  // Limita o contador em 0
        direcaoCrescente = true;  // Muda a direção para crescente
      }
    }
    atualizarDisplay();  // Atualiza os LEDs com o novo valor do contador
    ultimoTempo = millis();  // Atualiza o último tempo de mudança de contador
  }

  // Atualiza o estado anterior do botão
  lastButtonState = buttonState;
}

void alterarDirecao() {
  direcaoCrescente = !direcaoCrescente;  // Inverte a direção do contador
}

void atualizarDisplay() {
  // Define os padrões de cada LED para os números de 0 a 9
  const bool digitos[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
  };

  // Atualiza cada LED de acordo com o valor do contador
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], digitos[contador][i]);
  }
}
