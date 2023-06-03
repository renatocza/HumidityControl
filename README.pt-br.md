# Controle de Temperatura com Arduino Nano

Este programa Arduino controla a temperatura utilizando um sensor DHT11, controle PWM e um display LCD 16x2 i2c. Ele permite definir um período de tempo específico para o controle de temperatura e oferece um menu com três opções de tempo (3 horas, 6 horas, 12 horas).

## Hardware Necessário

- Arduino Nano
- Sensor DHT11
- Display LCD 16x2 i2c
- MOSFET shield (IRF520)/ Relé 5v
- Três botões (para seleção de menu e iniciar/parar)

## Conexões de Pinos

- Sensor DHT11:
  - Pino VCC ao pino 5V do Arduino Nano
  - Pino GND ao pino GND do Arduino Nano
  - Pino DATA ao pino digital 2 do Arduino Nano

- Display LCD 16x2 i2c:
  - Pino SDA ao pino A4 (ou SDA dedicado) do Arduino Nano
  - Pino SCL ao pino A5 (ou SCL dedicado) do Arduino Nano
  - Pino VCC ao pino 5V do Arduino Nano
  - Pino GND ao pino GND do Arduino Nano

- MOSFET/RELÉ:
  - Pino digital 9 do Arduino Nano

- Botões:
  - Botão de subir:
    - Um terminal ao pino digital 3 do Arduino Nano
    - O outro terminal ao GND
  - Botão de descer:
    - Um terminal ao pino digital 4 do Arduino Nano
    - O outro terminal ao GND
  - Botão de iniciar/parar:
    - Um terminal ao pino digital 5 do Arduino Nano
    - O outro terminal ao GND

## Uso

1. Conecte o Arduino Nano ao seu computador.
2. Faça o upload do programa para o Arduino Nano usando a IDE do Arduino.
3. Certifique-se de que o sensor DHT11, o display LCD, o MOSFET/RELÉ e os botões estejam conectados corretamente de acordo com as conexões de pinos mencionadas acima.
4. Ligue o Arduino Nano.
5. Use os botões de subir e descer para selecionar a opção de tempo desejada no display LCD.
6. Pressione o botão de iniciar/parar para começar ou parar o controle de temperatura.
7. O display LCD mostrará o tempo restante, temperatura e umidade durante o processo de controle de temperatura.

Aproveite o controle de temperatura com Arduino Nano!
