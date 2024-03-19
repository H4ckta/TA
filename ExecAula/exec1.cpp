int pot = A0;  // Pino analógico conectado ao potenciômetro
int bits = 0;       // Valor do potenciômetro
int led = 3;         // Pino digital conectado ao LED

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  pot = analogRead(pot);  // Ler o valor do potenciômetro (0-1023)

  // Mapear o valor do potenciômetro para a faixa de brilho do LED (0-255)
  int brightness = map(pot, 0, 1023, 0, 255);

  // Aumentar a intensidade de 0% para 100%
  for (int i = 0; i <= brightness; i++) {
    analogWrite(led, i);
    delay(10); // Ajuste o tempo de processo conforme necessário
  }

  // Diminuir a intensidade de 100% para 0%
  for (int i = brightness; i >= 0; i--) {
    analogWrite(led, i);
    delay(10); // Ajuste o tempo de processo conforme necessário
  }
}