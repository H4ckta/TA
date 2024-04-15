#define potPin 0 
#define ledPin 9 
int valPot = 0; 

void setup() 
{
    pinMode(ledPin,OUTPUT);
}

void loop() {
    valPot = analogRead(potPin); 
    esta ligado
    valPot = map(valPot,0,1023,0,255); 
    escala de 0-1023 em uma escala 0 a 255
    analogWrite(ledPin,valPot ); 
    analógica
}