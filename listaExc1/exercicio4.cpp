int led = 4;
int bot = 6;
int time;
bool m = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(bot, INPUT);
  digitalWrite(led, LOW);
}

void loop() {
    if (m ==0) {
        time = 0;
        for (int i = 0; i < 10; i++) {
            digitalWrite(led, HIGH);
            delay(1000 - time);
            digitalWrite(led, LOW);
            delay(1000 - time);
            time += 50;
        }
        m = 1;
    }
    
    if (m ==1) {
        time = 0;
        for (int i = 0; i < 10; i++) {
            digitalWrite(led, HIGH);
            delay(500 + time);
            digitalWrite(led, LOW);
            delay(500 + time);
            time += 50;
        }
        m = 0;
    }
}