# Waterise
Integrantes:
Giovanna Sayama - RM565901
Ana Luiza Rinaldi - RM564061

# Sistema de monitoramento do nível de água de rios:
O Waterise foi criado com o objetivo de ajudar a informar possíveis enchentes através de um dispositivo de monitoramento do nível da água dos rios. 
Este dispositivo, implantado em postes, analisa a distância entre o nível da água de um rio e o sensor, notificando situações de atenção e risco. Os alertas são emitidos por meio de um buzzer (avisos sonoros) e LEDs (avisos visuais), permitindo que moradores — inclusive aqueles com deficiência auditiva — sejam alertados com segurança, inclusive de dentro de veículos.

# Componentes utilizados:
- Arduíno UNO R3;
- ProtoBoard;
- Buzzer;
- LEDs;
- Resistores;
- Faixa de NeoPixel (8LEDs);
- Sensor de distância ultrassônico(HC-SR04);
- Jumpers
  
# Biblioteca usada:
  - #include <Adafruit_NeoPixel.h>
  
# Como montar e executar o projeto:
  
#  Montar o circuito:
  **Alimentação**
  Conecte o pino 5V do Arduino à linha vermelha da protoboard (positivo).
  Conecte o pino GND do Arduino à linha azul da protoboard (negativo).
  **LEDs (Verde, Amarelo e Vermelho)**
  1. **Alimentação**
  - Conecte o pino 5V do Arduino à linha vermelha da protoboard (positivo).
  - Conecte o pino GND do Arduino à linha azul da protoboard (negativo).
  2. **LEDs (Verde, Amarelo e Vermelho)**
  **LED Verde:**
  Anodo (perna longa) → resistor → pino Digital 2 do Arduino.
  Cátodo (perna curta) → linha azul da protoboard (negativo/GND).
  - Anodo (perna longa) → resistor → pino Digital 2 do Arduino.
  - Cátodo (perna curta) → linha azul da protoboard (negativo/GND).
  **LED Amarelo:**
  Anodo → resistor → pino Digital 3 do Arduino.
  Cátodo → linha azul da protoboard (negativo/GND).
  - Anodo → resistor → pino Digital 3 do Arduino.
  - Cátodo → linha azul da protoboard (negativo/GND).
  **LED Vermelho:**
  Anodo → resistor → pino Digital 4 do Arduino.
  Cátodo → linha azul da protoboard (negativo/GND).
  - Anodo → resistor → pino Digital 4 do Arduino.
  - Cátodo → linha azul da protoboard (negativo/GND).
  **Todos os LEDs compartilham o mesmo GND pela trilha negativa da protoboard.**
  3. **Buzzer**
  - Pino positivo (longo) → pino 7 do Arduino.
  - Pino negativo → GND.
  4. **Sensor Ultrassônico HC-SR04**
  - VCC → linha vermelha da protoboard (positivo/5V do Arduino).
  - GND → GND.
  - Trig → pino 9 do Arduino.
  - Echo → pino 10 do Arduino.
  5. **Faixa de LED NeoPixel**
  - VCC → linha vermelha da protoboard (positivo/5V do Arduino).
  - GND → GND.
  - DIN (entrada de dados) → pino Digital 6 do Arduino.
  
# Configure a IDE do Arduino:
  - Instale as bibliotecas necessárias.
  - Selecione a a placa e a porta corretas.
  - Carregue o código e acompanhe o funcionamento.
  
#Lógica de funcionamento por nível de distância:
  1. Distância maior que 350cm/3.50m(Seguro):
  - Led **verde** acende;
  - Faixa de NeoPixel exibe todos os LEDs na cor **verde**(estático);
  - O buzzer não emite som.
  2. Distância entre 303cm/3.03m e 349cm/3.49m(Atenção):
  - LED **amarelo** acende;
  - Faixa de NeoPixel pisca lentamente na cor **amarela**;
  - O buzzer não emite som.
  3. Distância menor que 303cm/3.03m(Perigo):
  - LED **vermelho** acende;
  - Faixa de NeoPixel pisca rapidamente na cor **vermelha**;
  - O buzzer emite bipes curtos e frequentes.
  
# Efeitos visuais e sonoros:
  - A piscada dos LEDs de NeoPixels varia de acordo com a criticidade da situação(estavel para seguro, piscadas lentas para atenção e rápidas para perigo);
  - O buzzer apenas toca em condições de perigo, com bipes curtos e com pequenas pausas, simulando uma sirene;

