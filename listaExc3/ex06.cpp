#define pot A0 
int potvalor;

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    potvalor = analogRead(A0); 
    Serial.print("Valor do Potenciometro = "); 
    Serial.println(potvalor); 
    delay(250);
}