#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);   // Initialize the DHT sensor

const int pwmPin = 9;   // PWM pin connected to the MOSFET
const int upPin = 3;    // Button for increasing the time
const int downPin = 4;  // Button for decreasing the time
const int startPin = 5; // Button to start/stop temperature control

int timeOptions[] = {3, 6, 12};  // Available time options in hours
int selectedTimeIndex = 0;       // Index of the selected time option
int selectedTime = timeOptions[selectedTimeIndex];  // Selected time in hours
unsigned long startTime = 0;     // Variable to store the start time
unsigned long elapsedTime = 0;   // Variable to store the elapsed time

bool heating = false;            // Flag to indicate if heating is active
float temperature = 0.0;         // Variable to store temperature
float humidity = 0.0;            // Variable to store humidity

LiquidCrystal_I2C lcd(0x27, 16, 2);   // Initialize the LCD

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(upPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(startPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(upPin), increaseTime, FALLING);
  attachInterrupt(digitalPinToInterrupt(downPin), decreaseTime, FALLING);
  attachInterrupt(digitalPinToInterrupt(startPin), startStopControl, FALLING);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.setCursor(0, 1);
  lcd.print("Temp:    Humidity:");
  
  dht.begin();
}

void loop() {
  // Read temperature and humidity from DHT sensor
  float newTemperature = dht.readTemperature();
  float newHumidity = dht.readHumidity();

  // Check if temperature reading is valid
  if (!isnan(newTemperature)) {
    temperature = newTemperature;
  }

  // Check if humidity reading is valid
  if (!isnan(newHumidity)) {
    humidity = newHumidity;
  }

  // Display temperature, humidity, and remaining time on LCD
  lcd.setCursor(6, 1);
  lcd.print(temperature);
  lcd.setCursor(14, 1);
  lcd.print(humidity);
  lcd.setCursor(6, 0);
  
  // Calculate remaining time
  unsigned long remainingTime = (selectedTime * 60 * 60 * 1000) - elapsedTime;
  int hours = remainingTime / (60 * 60 * 1000);
  int minutes = (remainingTime % (60 * 60 * 1000)) / (60 * 1000);
  int seconds = (remainingTime % (60 * 1000)) / 1000;
  
  // Display remaining time on LCD
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) {
    lcd.print("0");
  }
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) {
    lcd.print("0");
  }
  lcd.print(seconds);

  // Check if heating is active and temperature exceeds 50°C
  if (heating && temperature > 50) {
    analogWrite(pwmPin, 0);  // Turn off heating
  }

  // Check if time has elapsed
  if (elapsedTime >= selectedTime * 60 * 60 * 1000) {
    heating = false;          // Stop heating
    analogWrite(pwmPin, 0);   // Turn off heating
  }

  // Update elapsed time
  if (heating) {
    unsigned long currentTime = millis();
    elapsedTime = currentTime - startTime;
  }
}

// Interrupt service routine for increasing the time
void increaseTime() {
  if (!heating) {
    selectedTimeIndex = (selectedTimeIndex + 1) % 3;
    selectedTime = timeOptions[selectedTimeIndex];
    lcd.setCursor(5, 0);
    lcd.print(" ");
    lcd.setCursor(6, 0);
    lcd.print(selectedTime);
  }
}

// Interrupt service routine for decreasing the time
void decreaseTime() {
  if (!heating) {
    selectedTimeIndex = (selectedTimeIndex + 2) % 3;
    selectedTime = timeOptions[selectedTimeIndex];
    lcd.setCursor(5, 0);
    lcd.print(" ");
    lcd.setCursor(6, 0);
    lcd.print(selectedTime);
  }
}

// Interrupt service routine for starting/stopping temperature control
void startStopControl() {
  if (!heating) {
    heating = true;
    startTime = millis();
    elapsedTime = 0;
    analogWrite(pwmPin, 255);   // Turn on heating at full power
  } else {
    heating = false;
    analogWrite(pwmPin, 0);     // Turn off heating
  }
}
