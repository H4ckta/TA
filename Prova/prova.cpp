#include <LiquidCrystal_I2C.h>  // Inclui a biblioteca para o uso do LCD I2C

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);  // Inicializa o objeto do LCD I2C com endereço 0x27, 16 colunas e 2 linhas
int bt_blue_NEXT = 33;  // Define o pino para o botão azul (avançar)
int bt_green_YES = 34;  // Define o pino para o botão verde (sim)
int bt_yellow_BACK = 32;  // Define o pino para o botão amarelo (voltar)
int bt_red_CANCEL = 35;  // Define o pino para o botão vermelho (cancelar)
int h = 0, m = 0, s = 0;  // Variáveis para armazenar horas, minutos e segundos
int time_setup = 1000;  // Tempo de atualização do relógio (em milissegundos)
int count = 0;  // Variável para contar cliques
int layer = 0;  // Variável para controlar o menu

void setup() {
  Serial.begin(115200);  // Inicia a comunicação serial
  for(int i=32;i<36;i++)
    pinMode(i,INPUT);  // Define os pinos de 32 a 35 como entrada
  LCD.init();  // Inicializa o LCD
  LCD.backlight();  // Liga o backlight do LCD
  welcome();  // Exibe a mensagem de boas-vindas
}

void welcome() {
  LCD.clear();  // Limpa o LCD
  LCD.setCursor(1, 0);  // Define o cursor na posição (1, 0)
  LCD.print("SEJA BEM-VINDO!");  // Exibe a mensagem de boas-vindas
  delay(1000);  // Aguarda 1 segundo
  displayMenu();  // Exibe o menu
}

void displayMenu() {
  LCD.clear();  // Limpa o LCD
  LCD.setCursor(0, 0);  // Define o cursor na posição (0, 0)
  switch (layer) {  // Verifica o valor da variável "layer"
    case 0:
      LCD.print("1. Contador");  // Exibe a opção 1 do menu
      break;
    case 1:
      LCD.print("2. Click");  // Exibe a opção 2 do menu
      break;
    case 2:
      LCD.print("3. Clear");  // Exibe a opção 3 do menu
      break;
  }
}

void countClick() {
  LCD.clear();  // Limpa o LCD
  LCD.setCursor(0, 0);  // Define o cursor na posição (0, 0)
  LCD.print("Count Clicks");  // Exibe o título da função de contagem de cliques
  LCD.setCursor(0, 1);  // Define o cursor na posição (0, 1)
  while (true) {  // Loop infinito para contar cliques
    if (digitalRead(bt_blue_NEXT) == HIGH) {  // Verifica se o botão azul foi pressionado
      count++;  // Incrementa o contador de cliques
      LCD.setCursor(0,1);  // Define o cursor na posição (0, 1)
      LCD.print("Clicks: ");  // Exibe a etiqueta "Clicks: "
      LCD.print(count);  // Exibe o valor do contador
      delay(200);  // Aguarda 200 milissegundos
      while (digitalRead(bt_blue_NEXT) == HIGH) {}  // Aguarda o botão ser liberado
    }
    if (digitalRead(bt_yellow_BACK) == HIGH) {  // Verifica se o botão amarelo foi pressionado
      count = 0;  // Zera o contador de cliques
      LCD.setCursor(0, 1);  // Define o cursor na posição (0, 1)
      LCD.print("Clicks: ");  // Exibe a etiqueta "Clicks: "
      LCD.print(count);  // Exibe o valor zerado do contador
      delay(200);  // Aguarda 200 milissegundos
      return;  // Retorna para o menu principal
    }
    if (digitalRead(bt_red_CANCEL) == HIGH) {  // Verifica se o botão vermelho foi pressionado
      exit(0);  // Encerra o programa
      LCD.clear();  // Limpa o LCD (essa linha nunca será alcançada)
      welcome();  // Exibe a mensagem de boas-vindas (essa linha nunca será alcançada)
    }
  }
}

void Clock() {
  LCD.clear();  // Limpa o LCD
  LCD.setCursor(1, 0);  // Define o cursor na posição (1, 0)
  LCD.print("Clock");  // Exibe o título do relógio
  while (true) {  // Loop infinito para atualizar o relógio
    LCD.setCursor(0, 1);  // Define o cursor na posição (0, 1)
    LCD.print(h < 10 ? "0" : "");  // Adiciona um zero à esquerda se necessário para as horas
    LCD.print(h);  // Exibe as horas
    LCD.print(":");  // Exibe dois pontos
    LCD.print(m < 10 ? "0" : "");  // Adiciona um zero à esquerda se necessário para os minutos
    LCD.print(m);  // Exibe os minutos
    LCD.print(":");  // Exibe dois pontos
    LCD.print(s < 10 ? "0" : "");  // Adiciona um zero à esquerda se necessário para os segundos
    LCD.print(s);  // Exibe os segundos
    delay(time_setup);  // Aguarda o tempo de atualização
    s++;  // Incrementa os segundos
    if (s == 60) {  // Se os segundos atingirem 60
      s = 0;  // Reinicia os segundos
      m++;  // Incrementa os minutos
      if (m == 60) {  // Se os minutos atingirem 60
        m = 0;  // Reinicia os minutos
        h++;  // Incrementa as horas
        if (h == 24) {  // Se as horas atingirem 24
          h = 0;  // Reinicia as horas
        }
      }
    }
    if (digitalRead(bt_blue_NEXT) == HIGH) {  // Verifica se o botão azul foi pressionado
      time_setup = 250;  // Reduz o tempo de atualização para 250ms
    }
    if (digitalRead(bt_yellow_BACK) == HIGH) {  // Verifica se o botão amarelo foi pressionado
      time_setup = 1000;  // Retorna o tempo de atualização para 1000ms
    }
    if (digitalRead(bt_red_CANCEL) == HIGH) {  // Verifica se o botão vermelho foi pressionado
      LCD.clear();  // Limpa o LCD
      welcome();  // Exibe a mensagem de boas-vindas
      break;  // Sai do loop
    }
  }
}

void Clear() {
  LCD.clear();  // Limpa o LCD
  LCD.setCursor(0, 0);  // Define o cursor na posição (0, 0)
  LCD.print("Deseja zerar ");  // Exibe a mensagem de confirmação de zerar dados
  LCD.setCursor(0, 1);  // Define o cursor na posição (0, 1)
  LCD.print("todos os dados?");  // Exibe a mensagem de confirmação de zerar dados
  unsigned long startTime = millis();  // Armazena o tempo atual em millisegundos
  while (millis() - startTime <= 3000) {  // Loop por 3 segundos
    if (digitalRead(bt_green_YES) == HIGH) {  // Verifica se o botão verde foi pressionado
      LCD.clear();  // Limpa o LCD
      LCD.print("Dados zerados!");  // Exibe a mensagem de dados zerados
      delay(1000);  // Aguarda 1 segundo
      count = 0;  // Zera o contador de cliques
      h = m = s = 0;  // Zera o relógio
      layer = 0;  // Reinicia o menu para a opção inicial
      displayMenu();  // Exibe o menu
      return;  // Retorna após zerar os dados
    }
    if (digitalRead(bt_red_CANCEL) == HIGH) {  // Verifica se o botão vermelho foi pressionado
      LCD.clear();  // Limpa o LCD
      welcome();  // Exibe a mensagem de boas-vindas
      return;  // Retorna se o botão vermelho for pressionado
    }
  }
}

void loop() {
  while (true) {  // Loop principal
    if (digitalRead(bt_green_YES) == HIGH) {  // Verifica se o botão verde foi pressionado
      delay(100);  // Aguarda 100ms
      if (layer == 2) {  // Se a opção selecionada for "Clear"
        Clear();  // Chama a função Clear()
      } else {
        layer++;  // Incrementa a camada do menu
        if(layer==1){
          Clock();  // Chama a função Clock()
        }else if(layer==2){
          countClick();  // Chama a função countClick()
        }
        displayMenu();  // Exibe o menu
      }
    } else if (digitalRead(bt_yellow_BACK) == HIGH) {  // Verifica se o botão amarelo foi pressionado
      delay(100);  // Aguarda 100ms
      layer--;  // Decrementa a camada do menu
      if (layer < 0) layer = 0;  // Garante que a camada não seja menor que 0
      displayMenu();  // Exibe o menu
    } else if (digitalRead(bt_red_CANCEL) == HIGH) {  // Verifica se o botão vermelho foi pressionado
      delay(100);  // Aguarda 100ms
      layer = 0;  // Reinicia a camada do menu para a opção inicial
      welcome();  // Exibe a mensagem de boas-vindas
    } else if (digitalRead(bt_blue_NEXT) == HIGH) {  // Verifica se o botão azul foi pressionado
      delay(100);  // Aguarda 100ms
      layer++;  // Incrementa a camada do menu
      if (layer > 2) layer = 2;  // Garante que a camada não seja maior que 2
      displayMenu();  // Exibe o menu
    }
  }
}
