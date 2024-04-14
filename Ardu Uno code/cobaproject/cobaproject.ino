#include <SoftwareSerial.h>
#include <MQ135.h>

SoftwareSerial bluetooth(0, 1); // RX, TX pin for HC-05
// const int MQ135_PIN = A0;
int pinMQ135 = A0;

float gasamann =4;
float gasamannn =8;
float gasamannnn =15;
float gasperhatian= 30;


void setup() {
  Serial.begin(9600); // Initialize serial communication with Arduino IDE
  bluetooth.begin(9600); // Initialize Bluetooth communication
}
void loop() {
  float gasValue = analogRead(pinMQ135);
  // Perform necessary calculations or calibration based on your specific requirements
  // For example, you can convert the analog reading to gas concentration using a formula

  Serial.print("Gas CO : ");
  Serial.print(gasValue); // Print the gas value to the Serial Monitor
  Serial.println(" PPM");



  if (gasValue < gasamann){
    Serial.println("Udara BAIK");
    delay(2000);
    bluetooth.println("Udara BAIK");
    bluetooth.print("Gas CO : ");
    bluetooth.print(gasValue); // Send the gas value via Bluetooth
    bluetooth.println(" PPM");
  }
  else if (gasValue >= gasamann && gasValue <= gasamannn){
    Serial.println("Udara SEDANG");
    bluetooth.println("Udara SEDANG");
    delay(2000);
    bluetooth.print("Gas CO : ");
    bluetooth.print(gasValue); // Send the gas value via Bluetooth
   bluetooth.println(" PPM");
  }
  else if (gasValue >= gasamannn && gasValue <= gasamannnn){
    Serial.println("Udara TIDAK SEHAT");
    bluetooth.println("Udara TIDAK SEHAT");
    delay(2000);
    bluetooth.print("Gas CO : ");
    bluetooth.print(gasValue); // Send the gas value via Bluetooth
   bluetooth.println(" PPM");
  } 
    else if (gasValue >= gasamannnn && gasValue <= gasperhatian){
    Serial.println("Udara SANGAT TIDAK SEHAT");
    bluetooth.println("Udara SANGAT TIDAK SEHAT");
    delay(2000);
    bluetooth.print("Gas CO : ");
    bluetooth.print(gasValue); // Send the gas value via Bluetooth
   bluetooth.println(" PPM");
  }  
 else if (gasValue > gasperhatian){
  for (int z=0; z < 10; z++){
   Serial.println("Udara BERBAHAYA");
   delay(2000);
   bluetooth.println("Udara BERBAHAYA");
   bluetooth.print("Gas CO : ");
   bluetooth.print(gasValue); // Send the gas value via Bluetooth
   bluetooth.println(" PPM");



  }
 }}
