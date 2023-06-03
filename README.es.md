# Control de Temperatura con Arduino Nano

Este programa de Arduino controla la temperatura utilizando un sensor DHT11, control PWM y una pantalla LCD 16x2 i2c. Permite establecer un período de tiempo específico para el control de temperatura y proporciona un menú con tres opciones de tiempo (3 horas, 6 horas, 12 horas).

## Hardware Requerido

- Arduino Nano
- Sensor DHT11
- Pantalla LCD 16x2 i2c
- MOSFET shield (IRF520)/ Relé 5v
- Tres botones (para selección de menú e iniciar/detener)

## Conexiones de Pines

- Sensor DHT11:
  - Pin VCC al pin 5V del Arduino Nano
  - Pin GND al pin GND del Arduino Nano
  - Pin DATA al pin digital 2 del Arduino Nano

- Pantalla LCD 16x2 i2c:
  - Pin SDA al pin A4 (o SDA dedicado) del Arduino Nano
  - Pin SCL al pin A5 (o SCL dedicado) del Arduino Nano
  - Pin VCC al pin 5V del Arduino Nano
  - Pin GND al pin GND del Arduino Nano

- MOSFET/RELÉ:
  - Pin digital 9 del Arduino Nano

- Botones:
  - Botón de subir:
    - Un terminal al pin digital 3 del Arduino Nano
    - El otro terminal a GND
  - Botón de bajar:
    - Un terminal al pin digital 4 del Arduino Nano
    - El otro terminal a GND
  - Botón de iniciar/detener:
    - Un terminal al pin digital 5 del Arduino Nano
    - El otro terminal a GND

## Uso

1. Conecta el Arduino Nano a tu computadora.
2. Sube el programa al Arduino Nano utilizando el IDE de Arduino.
3. Asegúrate de que el sensor DHT11, la pantalla LCD, el MOSFET/RELÉ y los botones estén conectados correctamente según las conexiones de pines mencionadas anteriormente.
4. Enciende el Arduino Nano.
5. Utiliza los botones de subir y bajar para seleccionar la opción de tiempo deseada en la pantalla LCD.
6. Presiona el botón de iniciar/detener para comenzar o detener el control de temperatura.
7. La pantalla LCD mostrará el tiempo restante, temperatura y humedad durante el proceso de control de temperatura.

¡Disfruta del control de temperatura con Arduino Nano!
