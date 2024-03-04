int vermelho = 3;
int amarelo = 4;
int verde = 5;

void setup(){
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
}   


void loop(){
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, HIGH);
  delay(5000);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, HIGH);
  delay(2000);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);
  delay(5000);
}