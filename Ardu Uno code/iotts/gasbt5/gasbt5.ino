#include <SoftwareSerial.h>
#include <MQ135.h>

SoftwareSerial bluetooth(0, 1); // RX, TX pin for HC-05
// const int MQ135_PIN = A0;
MQ135 gasSensor = MQ135(A0);

void setup() {
  Serial.begin(9600); // Initialize serial communication with Arduino IDE
  bluetooth.begin(9600); // Initialize Bluetooth communication
}
void loop() {
  float gasValue = gasSensor.getPPM();
  // Perform necessary calculations or calibration based on your specific requirements
  // For example, you can convert the analog reading to gas concentration using a formula

  Serial.print("Gas CO : ");
  Serial.print(gasValue); // Print the gas value to the Serial Monitor
  Serial.println(" PPM");

  bluetooth.print("Gas CO : ");
  bluetooth.print(gasValue); // Send the gas value via Bluetooth
  bluetooth.println(" PPM");

  if (gasValue <= 2){
    Serial.println("Udara BAIK");
    bluetooth.println("Udara BAIK");
  }
  else if (gasValue <= 3){
    Serial.println("Udara BURUK");
    bluetooth.println("Udara BURUK");
  }

  delay(5000); // Delay for a second before the next readingt
}
