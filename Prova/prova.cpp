#include <LiquidCrystal_I2C.h> // Inclui a biblioteca para comunicação com o display LCD via I2C

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2); // Inicializa o objeto do display LCD com endereço 0x27, 16 colunas e 2 linhas

int botaoAmarelo = 32; // Define o pino do botão amarelo
int botaoAzul = 33;    // Define o pino do botão azul
int botaoVerde = 34;   // Define o pino do botão verde
int botaoVermelho = 35; // Define o pino do botão vermelho

int etapa = 1; // Variável de controle da etapa do programa
int etapaSelecionada = 1; // Variável de controle da opção selecionada
int contador = 0; // Variável de contador

int hora = 0;    // Variável de horas
int minuto = 0;  // Variável de minutos
int segundo = 0; // Variável de segundos

int relogioDelay = 1000; // Delay do relógio em milissegundos
bool dadosZerados = false; // Flag para indicar se os dados foram zerados

void setup()
{
    Serial.begin(9600); // Inicia a comunicação serial
    LCD.init();          // Inicializa o display LCD
    LCD.backlight();     // Ativa o backlight do display LCD

    pinMode(botaoAmarelo, INPUT); // Configura o pino do botão amarelo como entrada
    pinMode(botaoAzul, INPUT);    // Configura o pino do botão azul como entrada
    pinMode(botaoVerde, INPUT);   // Configura o pino do botão verde como entrada
    pinMode(botaoVermelho, INPUT); // Configura o pino do botão vermelho como entrada

    LCD.setCursor(0,0); // Define a posição do cursor no display LCD
    LCD.print("Bem Vindo!"); // Exibe uma mensagem de boas-vindas no display LCD
    delay(5000); // Aguarda 5 segundos
    LCD.clear(); // Limpa o conteúdo do display LCD
}

void loop()
{
    // Função principal do loop, onde são chamadas as funções correspondentes a cada etapa do programa
    if (etapa == 1) // Se a etapa for igual a 1
        selecionar(); // Chama a função para selecionar a opção
    else if (etapa == 2) // Se a etapa for igual a 2
        contarAoClicar(); // Chama a função para contar ao clicar
    else if (etapa == 3) // Se a etapa for igual a 3
        mostrarRelogio(); // Chama a função para mostrar o relógio
    else if (etapa == 4) // Se a etapa for igual a 4
        limparDados(); // Chama a função para limpar os dados
}

void selecionar()
{
    // Função para selecionar uma das opções do programa
    switch (etapaSelecionada)
    {
    case 1: // Se a opção selecionada for 1
        LCD.setCursor(0, 0); // Define a posição do cursor no display LCD
        LCD.print("OPCAO - 1"); // Exibe a opção no display LCD
        LCD.setCursor(0, 1); // Define a posição do cursor no display LCD
        LCD.print("Contador d'Clicks"); // Exibe a opção no display LCD
        break;

    case 2: // Se a opção selecionada for 2
        LCD.setCursor(0, 0); // Define a posição do cursor no display LCD
        LCD.print("OPCAO - 2"); // Exibe a opção no display LCD
        LCD.setCursor(0, 1); // Define a posição do cursor no display LCD
        LCD.print("Contador de Hora"); // Exibe a opção no display LCD
        break;

    case 3: // Se a opção selecionada for 3
        LCD.setCursor(0, 0); // Define a posição do cursor no display LCD
        LCD.print("OPCAO - 3"); // Exibe a opção no display LCD
        LCD.setCursor(0, 1); // Define a posição do cursor no display LCD
        LCD.print("Limpar Dados"); // Exibe a opção no display LCD
        break;

    default: // Se nenhuma das opções anteriores
        LCD.clear(); // Limpa o conteúdo do display LCD
        break;
    }

    // Lógica para navegar entre as opções utilizando os botões
    if (digitalRead(botaoAzul) == HIGH)
    {
        if (etapaSelecionada < 3)
        {
            etapaSelecionada++;
        }
        else if (etapaSelecionada == 3)
        {
            etapaSelecionada = 1;
        }
        LCD.clear(); // Limpa o conteúdo do display LCD
        delay(120); // Aguarda 120 milissegundos
    }

    if (digitalRead(botaoVerde) == HIGH)
    {
        if (etapa < 4)
        {
            LCD.clear(); // Limpa o conteúdo do display LCD
            etapa = etapaSelecionada + 1; // Avança para a próxima etapa
            delay(120); // Aguarda 120 milissegundos
        }
    }

    if (digitalRead(botaoAmarelo) == HIGH)
    {
        if (etapaSelecionada > 1)
        {
            etapaSelecionada--;
        }
        else if (etapaSelecionada == 1)
        {
            etapaSelecionada = 3;
        }
        LCD.clear(); // Limpa o conteúdo do display LCD
        delay(120); // Aguarda 120 milissegundos
    }
}

void contarAoClicar()
{
    // Função para contar os cliques no botão azul e permitir reiniciar o contador ou voltar para a etapa 1
    LCD.setCursor(0, 0); // Define a posição do cursor no display LCD
    LCD.print("Contador d'Clicks"); // Exibe uma mensagem no display LCD
    LCD.setCursor(0, 1); // Define a posição do cursor no display LCD
    LCD.print("Contador: "); // Exibe uma mensagem no display LCD
    LCD.print(contador); // Exibe o valor do contador no display LCD

    if (digitalRead(botaoAzul) == HIGH) // Se o botão azul for pressionado
    {
        contador++; // Incrementa o contador
        LCD.setCursor(10, 1); // Define a posição do cursor no display LCD
        LCD.print(contador); // Exibe o valor do contador no display LCD
        delay(120); // Aguarda 120 milissegundos
    }

    if (digitalRead(botaoAmarelo) == HIGH) // Se o botão amarelo for pressionado
    {
        if (etapa > 0) // Se a etapa for maior que 0
        {
            contador = 0; // Reinicia o contador
            LCD.clear(); // Limpa o conteúdo do display LCD
            LCD.setCursor(0, 0); // Define a posição do cursor no display LCD
            LCD.print("Contador d'Clicks"); // Exibe uma mensagem no display LCD
            LCD.setCursor(0, 1); // Define a posição do cursor no display LCD
            LCD.print("Contador: "); // Exibe uma mensagem no display LCD
            LCD.print(contador); // Exibe o valor do contador no display LCD
        }
    }

    if (digitalRead(botaoVermelho) == HIGH) // Se o botão vermelho for pressionado
    {
        if (etapa > 0) // Se a etapa for maior que 0
        {
            LCD.clear(); // Limpa o conteúdo do display LCD
            etapa = 1; // Volta para a etapa 1
            delay(120); // Aguarda 120 milissegundos
        }
    }
}

void mostrarRelogio()
{
    // Função para mostrar o relógio no display LCD e permitir ajustar o delay do relógio ou voltar para a etapa 1
    LCD.setCursor(0, 0); // Define a posição do cursor no display LCD
    LCD.print("Contador de Horas"); // Exibe uma mensagem no display LCD

    // Loop infinito para atualizar o relógio
    for (;;)
    {
        LCD.setCursor(0, 1); // Define a posição do cursor no display LCD
        LCD.print("0"); // Exibe um zero no display LCD
        LCD.print(hora); // Exibe a hora no display LCD
        LCD.print(":"); // Exibe dois pontos no display LCD
        if (minuto < 10) // Se o minuto for menor que 10
        {
            LCD.print("0"); // Exibe um zero no display LCD
        }
        LCD.print(minuto); // Exibe o minuto no display LCD
        LCD.print(":"); // Exibe dois pontos no display LCD
        if (segundo < 10) // Se o segundo for menor que 10
        {
            LCD.print("0"); // Exibe um zero no display LCD
        }
        LCD.print(segundo); // Exibe o segundo no display LCD

        delay(relogioDelay); // Aguarda o delay do relógio

        segundo++; // Incrementa os segundos

        if (segundo == 60) // Se os segundos atingirem 60
        {
            segundo = 0; // Reinicia os segundos
            minuto++; // Incrementa os minutos

            if (minuto == 60) // Se os minutos atingirem 60
            {
                minuto = 0; // Reinicia os minutos
                hora++; // Incrementa as horas

                if (hora == 24) // Se as horas atingirem 24
                {
                    hora = 0; // Reinicia as horas
                }
            }
        }

        if (digitalRead(botaoAzul) == HIGH) // Se o botão azul for pressionado
        {
            relogioDelay = 250; // Define um novo delay para o relógio
        }

        if (digitalRead(botaoAmarelo) == HIGH) // Se o botão amarelo for pressionado
        {
            relogioDelay = 1000; // Define um novo delay para o relógio
        }

        if (digitalRead(botaoVermelho) == HIGH) // Se o botão vermelho for pressionado
        {
            LCD.clear(); // Limpa o conteúdo do display LCD
            etapa = 1; // Volta para a etapa 1
            break; // Sai do loop
        }
    }
}

void limparDados()
{
    // Função para limpar os dados e permitir voltar para a etapa 1
    LCD.setCursor(0, 0); // Define a posição do cursor no display LCD
    if (!dadosZerados) // Se os dados não estiverem zerados
    {
        LCD.print("Limpar Dados?"); // Exibe uma mensagem no display LCD
    }
    else // Se os dados estiverem zerados
    {
        LCD.print("Dados Zerados"); // Exibe uma mensagem no display LCD
    }

    if (digitalRead(botaoVerde) == HIGH) // Se o botão verde for pressionado
    {
        if (!dadosZerados) // Se os dados não estiverem zerados
        {
            relogioDelay = 1000; // Define o delay do relógio para 1000 milissegundos
            contador = 0; // Zera o contador
            hora = 0; // Zera as horas
            minuto = 0; // Zera os minutos
            segundo = 0; // Zera os segundos
            dadosZerados = true; // Define a flag como verdadeira indicando que os dados foram zerados
            LCD.clear(); // Limpa o conteúdo do display LCD
            LCD.setCursor(0, 0); // Define a posição do cursor no display LCD
            LCD.print("Dados Zerados"); // Exibe uma mensagem no display LCD
        }
    }

    if (digitalRead(botaoVermelho) == HIGH) // Se o botão vermelho for pressionado
    {
        LCD.clear(); // Limpa o conteúdo do display LCD
        etapa = 1; // Volta para a etapa 1
    }
}
