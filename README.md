[Português-Brasil](README.pt-br.md.md)
[Español](README.pt-br.md.md)

# Temperature Control with Arduino Nano

This Arduino program controls the temperature using a DHT11 sensor, PWM control, and an LCD 16x2 i2c display. It allows you to set a specific time period for temperature control and provides a menu with three time options (3 hours, 6 hours, 12 hours).

## Hardware Required

- Arduino Nano
- DHT11 sensor
- LCD 16x2 i2c display
- MOSFET shield (IRF520) OR 5V RELAY
- Three buttons (for menu selection and start/stop)

## Pin Connections

- DHT11 sensor:
  - VCC pin to Arduino Nano 5V pin
  - GND pin to Arduino Nano GND pin
  - DATA pin to Arduino Nano digital pin 2

- LCD 16x2 i2c display:
  - SDA pin to Arduino Nano A4 (or dedicated SDA) pin
  - SCL pin to Arduino Nano A5 (or dedicated SCL) pin
  - VCC pin to Arduino Nano 5V pin
  - GND pin to Arduino Nano GND pin

- MOSFET/RELAY:
  - Arduino Nano digital pin 9
 

- Buttons:
  - Up button:
    - One terminal to Arduino Nano digital pin 3
    - The other terminal to GND
  - Down button:
    - One terminal to Arduino Nano digital pin 4
    - The other terminal to GND
  - Start/Stop button:
    - One terminal to Arduino Nano digital pin 5
    - The other terminal to GND

## Usage

1. Connect the Arduino Nano to your computer.
2. Upload the program to the Arduino Nano using the Arduino IDE.
3. Ensure that the DHT11 sensor, LCD display, MOSFET/RELAY, and buttons are properly connected as per the pin connections mentioned above.
4. Power on the Arduino Nano.
5. Use the up and down buttons to select the desired time option on the LCD display.
6. Press the start/stop button to start or stop the temperature control.
7. The LCD display will show the remaining time, temperature, and humidity during the temperature control process.

Enjoy your temperature control with Arduino Nano!
