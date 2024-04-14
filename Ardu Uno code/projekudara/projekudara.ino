#include <SoftwareSerial.h>
#include <MQ135.h>

SoftwareSerial bluetooth(0, 1); // RX, TX pin for HC-05
// const int MQ135_PIN = A0;
int pinMQ135 = A0;
float gasaman =30;
float gasperhatian= 40;


void setup() {
  Serial.begin(9600); // Initialize serial communication with Arduino IDE
  bluetooth.begin(9600); // Initialize Bluetooth communication
}
void loop() {
  float gasValue = analogRead(pinMQ135);
  hitung (int gasValue  )
  // Perform necessary calculations or calibration based on your specific requirements
  // For example, you can convert the analog reading to gas concentration using a formula

  Serial.print("Gas CO : ");
  Serial.print(gasValue); // Print the gas value to the Serial Monitor
  Serial.println(" PPM");



  if (gasValue < gasaman){
    Serial.println("Udara BAIK");
    delay(200);
    bluetooth.println("Udara BAIK");
    bluetooth.print("Gas CO : ");
    bluetooth.print(gasValue); // Send the gas value via Bluetooth
    bluetooth.println(" PPM");
  }
  else if (gasValue >= gasaman && gasValue <= gasperhatian){
    Serial.println("Udara HATI HATI");
    bluetooth.println("Udara HATI HATI");
    delay(2000);
    bluetooth.print("Gas CO : ");
    bluetooth.print(gasValue); // Send the gas value via Bluetooth
   bluetooth.println(" PPM");
  }
 else if (gasValue > gasperhatian){
  for (int z=0; z < 10; z++){
   Serial.println("Udara BERBAHAYA");
   delay(200);
   bluetooth.println("Udara BERBAHAYA");
   bluetooth.print("Gas CO : ");
   bluetooth.print(gasValue); // Send the gas value via Bluetooth
   bluetooth.println(" PPM");



  }
 }}
