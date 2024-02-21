int vermelho = 3;
int amarelo = 4;
int verde = 5;
int vermelho2 = 7;
int verde2 = 6;
int tempo_intermitente = 1000;
int botao = 2;
int memoria = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho2, OUTPUT);
  pinMode(verde2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  time1 = millis();

  if (memoria == 0) {
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH);
    delay(1000);
    digitalWrite(vermelho2, LOW);
    digitalWrite(verde2, HIGH);
    delay(4000);
    
    for (int i = 0; i < 3; i++) {
      digitalWrite(verde2, LOW);
      delay(250);
      digitalWrite(verde2, HIGH);
      delay(250);
    }

    delay(500);
    digitalWrite(verde2, LOW);
    digitalWrite(vermelho2, HIGH);
    delay(1000);
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);
    time1 = millis();
    time2 = time1;
    memoria = 1;
  }  
    
  if ((memoria == 1 && digitalRead(botao) == 1) || memoria == 2) {
    memoria = 2;
    delay(1000);
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);
    delay(2000);
    time2 = time1;
    memoria = 0;
  }

  if ((time1 - time2) >= 5000 && memoria == 1) {
    Serial.println("Entrou aqui");
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);
    delay(2000);
    time2 = time1;
    memoria = 0;
  }
}