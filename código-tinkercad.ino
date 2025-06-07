#include <Adafruit_NeoPixel.h>

// Pinos do sensor ultrassônico
const int trigPin = 9;
const int echoPin = 10;

// LEDs
const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;

// Buzzer
const int buzzer = 7;

// Definições da faixa NeoPixel
const int neoPixelPin = 6;
const int numPixels = 10;
Adafruit_NeoPixel pixels(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

// Variáveis para controle de piscada
unsigned long previousMillis = 0;
const long intervalLento = 1000;
const long intervalRapido = 200;
bool ledState = false;
int piscadaEstado = 0;

// Variáveis para os apitos
unsigned long previousBeepMillis = 0;
const long beepDuration = 125; // Duração do apito (ms)
const long beepPause = 150;    // Pausa entre apitos (ms)
bool beepState = false;         // Estado do apito (ligado/desligado)

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pixels.begin();
  pixels.setBrightness(50);
  pixels.clear();
  pixels.show();
}

// Função para tocar apitos rápidos
void playBeeps() {
  unsigned long currentMillis = millis();
  if (beepState && currentMillis - previousBeepMillis >= beepDuration) {
    noTone(buzzer); // Desliga o buzzer
    beepState = false;
    previousBeepMillis = currentMillis;
  } else if (!beepState && currentMillis - previousBeepMillis >= beepPause) {
    tone(buzzer, 1000); // Toca apito a 1000 Hz
    beepState = true;
    previousBeepMillis = currentMillis;
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Envia pulso ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calcula tempo de retorno
  long duracao = pulseIn(echoPin, HIGH);
  int distancia = duracao * 0.034 / 2;

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Reseta LEDs, buzzer e NeoPixel
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  noTone(buzzer); // Desliga o buzzer por padrão
  pixels.clear();

  // Lógica de nível e piscada
  if (distancia > 350) {
    digitalWrite(ledVerde, HIGH); // Tudo ok
    for (int i = 0; i < numPixels; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Verde
    }
    piscadaEstado = 0; // Sem piscada
  }
  else if (distancia > 303 && distancia <= 349) {
    digitalWrite(ledAmarelo, HIGH); // Atenção
    piscadaEstado = 1; // Piscada lenta
  }
  else if (distancia < 303) {
    digitalWrite(ledVermelho, HIGH); // Risco
    playBeeps(); // Toca apitos rápidos
    piscadaEstado = 2; // Piscada rápida
  }

  // Controle da piscada dos NeoPixels
  if (piscadaEstado > 0) {
    if (currentMillis - previousMillis >= (piscadaEstado == 1 ? intervalLento : intervalRapido)) {
      previousMillis = currentMillis;
      ledState = !ledState;

      if (ledState) {
        if (piscadaEstado == 1) {
          for (int i = 0; i < numPixels; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 255, 0)); // Amarelo
          }
        } else if (piscadaEstado == 2) {
          for (int i = 0; i < numPixels; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Vermelho
          }
        }
      } else {
        pixels.clear();
      }
      pixels.show();
    }
  } else {
    if (distancia > 350) {
      for (int i = 0; i < numPixels; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Verde
      }
    }
    pixels.show();
  }

  delay(100); // Pequeno delay para estabilizar a leitura
}
