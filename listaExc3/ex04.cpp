#define CHAVE 2 
void setup()
{

 pinMode(CHAVE, INPUT); 
 Serial.begin(9600); 
}
void loop()
{

    if(digitalRead(CHAVE)) 
    {
        Serial.println("Botao Pressionado\n"); 
    }

    else //Senão
    {
        Serial.println("Botao Despressionado\n"); 
    }

    delay(250); 
}