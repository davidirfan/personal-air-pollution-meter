#include <MQ135.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1); // RX, TX pin for HC-05
MQ135 gasSensor = MQ135(A0);

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  bluetooth.begin(9600); // Initialize Bluetooth communication
}

void loop() {
  float gasConcentration = gasSensor.getPPM();  // Read gas concentration in PPM
  Serial.print("Gas Concentration: ");
  Serial.println(gasConcentration);
  Serial.print(" PPM");

  bluetooth.print("Gas Concentration: ");
  bluetooth.println(gasConcentration); // Send the gas value via Bluetooth
  bluetooth.print(" PPM");

  delay(10000);  // Delay for a second before the next reading
}
