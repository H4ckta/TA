int pot = A0;    // Pino analógico conectado ao potenciômetro
int led = 3;     // Pino digital conectado ao LED
int bits = 0;         // Valor do potenciômetro
int tempo = 0;      // Tempo de respiração em ms

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
   bits = analogRead(pot);  // Ler o valor do potenciômetro (0-1023)

  // Mapear o valor do potenciômetro para o tempo de respiração (0-4000ms)
  tempo = map(bits, 0, 1023, 4000, 0);

  if (bits == 0) {
    digitalWrite(led, LOW);  // Desligar o LED se o potenciômetro estiver em zero
  } else {
    digitalWrite(led, HIGH); // Ligando o LED para iniciar a respiração

    // Ajustar a velocidade da respiração de acordo com o tempo definido
    delay(tempo);
    digitalWrite(led, LOW); // Desligar o LED após o tempo de respiração
    delay(tempo); // Tempo de pausa antes da próxima respiração
  }
}