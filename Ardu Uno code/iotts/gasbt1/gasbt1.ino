#include <SoftwareSerial.h>
#include <MQ135.h>

SoftwareSerial bluetooth(0, 1); // RX, TX pin for HC-05
const int MQ135_PIN = A0;

void setup() {
  Serial.begin(9600); // Initialize serial communication with Arduino IDE
  bluetooth.begin(9600); // Initialize Bluetooth communication
}
void loop() {
  float gasValue = analogRead(MQ135_PIN);
  // Perform necessary calculations or calibration based on your specific requirements
  // For example, you can convert the analog reading to gas concentration using a formula

  Serial.print("Gas: ");
  Serial.println(gasValue); // Print the gas value to the Serial Monitor

  bluetooth.print("Gas: ");
  bluetooth.println(gasValue); // Send the gas value via Bluetooth

  delay(1000); // Delay for a second before the next readingt
}
