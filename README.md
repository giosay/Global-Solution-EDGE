# Waterise
Integrantes:
Ana Luiza Rinaldi - RM564061; 
Giovanna Sayama – RM564061;
# Sistema de monitoramento do nível de água de rios:
O Waterise foi criado com o objetivo de ajudar a informar possíveis enchentes através de um dispositivo de monitoramento do nível da água dos rios. 

Este dispositivo, implantado em postes, analisa a distância entre o nível da água e o sensor, notificando situações de atenção e risco. Os alertas são emitidos por meio de um buzzer (avisos sonoros) e LEDs (avisos visuais), permitindo que moradores — inclusive aqueles com deficiência auditiva — sejam alertados com segurança, inclusive de dentro de veículos.
# Componentes utilizados:
- Arduíno UNO R3;
- ProtoBoard;
- Buzzer;
- LEDs;
- Resistores;
- Faixa de NeoPixel (10LEDs);
- Sensor de distância ultrssônico(HC-SR04);
- Jumpers
  # Biblioteca usada:
  - #include <Adafruit_NeoPixel.h>
  # Como montar e executar o projeto:
  #  Montar o circuito:
  - **Alimentação**
   Conecte o pino 5V do Arduino à linha vermelha da protoboard (positivo);
   Conecte o pino GND do Arduino à linha azul da protoboard (negativo);
  **LEDs (Verde, Amarelo e Vermelho)**
  - **LED Verde:**
   Anodo (perna longa) → resistor → pino Digital 2 do Arduino;
   Cátodo (perna curta) → linha azul da protoboard (negativo/GND);
  - **LED Amarelo:**
   Anodo → resistor → pino Digital 3 do Arduino;
   Cátodo → linha azul da protoboard (negativo/GND);
  - **LED Vermelho:**
   Anodo → resistor → pino Digital 4 do Arduino;
   Cátodo → linha azul da protoboard (negativo/GND);
  **Todos os LEDs compartilham o mesmo GND pela trilha negativa da protoboard.**
  - **Buzzer**
   Pino positivo (longo) → pino 7 do Arduino;
   Pino negativo → GND;
  - **Sensor Ultrassônico HC-SR04**
   VCC → linha vermelha da protoboard (positivo/5V do Arduino);
   GND → GND;
   Trig → pino 9 do Arduino;
   Echo → pino 10 do Arduino;
  - **Faixa de LED NeoPixel**
   VCC → linha vermelha da protoboard (positivo/5V do Arduino);
   GND → GND;
   DIN (entrada de dados) → pino Digital 6 do Arduino;
  # Configure a IDE do Arduino:
   Instale as bibliotecas necessárias;
   Selecione a a placa e a porta corretas;
   Carregue o código e acompanhe o funcionamento:
  


