#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1); // RX, TX pin for HC-05

int CO_SENSOR_PIN = A0; // Analog pin for CO sensor


void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600); // Initialize Bluetooth communication
}

void loop() {
  int sensorValue = analogRead(CO_SENSOR_PIN);
  float voltage = (sensorValue / 1024.0) * 5.0; // Convert analog value to voltage
  float ppm = (voltage + 1.22) / 0.11; // Use the sensor's sensitivity characteristics

  // ISPU
  float gasBaik = 4;
  float gasSedang = 8;
  float gasTidakSehat = 15;
  float gasSangatTidakSehat = 30;

  Serial.print(ppm);
  delay(2000); // Delay for 1 second before taking another reading
}