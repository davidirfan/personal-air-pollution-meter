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
  float ppm = (voltage - 0.22) / 0.11; // Use the sensor's sensitivity characteristics

  // ISPU
  float gasBaik = 4;
  float gasSedang = 8;
  float gasTidakSehat = 15;
  float gasSangatTidakSehat = 30;

  if (ppm <= gasBaik){

    Serial.println(ppm);
    Serial.println("Kadar CO di udara : BAIK");
    bluetooth.print("CO Concentration (PPM): ");
    bluetooth.println(ppm);
    bluetooth.println("Kadar CO di udara : BAIK");
  }
  
  else if (ppm > gasBaik && ppm <= gasSedang){
    Serial.print("CO Concentration (PPM): ");
    Serial.println(ppm);
    Serial.println("Kadar CO di udara : SEDANG");
    bluetooth.print("CO Concentration (PPM): ");
    bluetooth.println(ppm);
    bluetooth.println("Kadar CO di udara : SEDANG");
  }

    else if (ppm > gasSedang && ppm <= gasTidakSehat){
    Serial.print("CO Concentration (PPM): ");
    Serial.println(ppm);
    Serial.println("Kadar CO di udara : TIDAK SEHAT");
    bluetooth.print("CO Concentration (PPM): ");
    bluetooth.println(ppm);
    bluetooth.println("Kadar CO di udara : TIDAK SEHAT");
  }

    else if (ppm > gasTidakSehat && ppm <= gasSangatTidakSehat){
    Serial.print("CO Concentration (PPM): ");
    Serial.println(ppm);
    Serial.println("Kadar CO di udara : SANGAT TIDAK SEHAT");
    bluetooth.print("CO Concentration (PPM): ");
    bluetooth.println(ppm);
    bluetooth.println("Kadar CO di udara : SANGAT TIDAK SEHAT");
  }

    else if (ppm > gasSangatTidakSehat){
    Serial.print("CO Concentration (PPM): ");
    Serial.println(ppm);
    Serial.println("Kadar CO di udara : BERBAHAYA");
    bluetooth.print("CO Concentration (PPM): ");
    bluetooth.println(ppm);
    bluetooth.println("Kadar CO di udara : BERBAHAYA");
  }
  delay(400); // Delay for 1 second before taking another reading
}
