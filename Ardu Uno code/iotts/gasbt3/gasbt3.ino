#include <SoftwareSerial.h>
#include <MQ135.h>

SoftwareSerial bluetooth(0, 1); // RX, TX pin for HC-05
MQ135 gasSensor = MQ135(A0);
double gas;
SoftwareSerial bt_serial(11,10);


void setup() {
  Serial.begin(9600); // Initialize serial communication with Arduino IDE
  bluetooth.begin(9600); // Initialize Bluetooth communication
  bt_serial.begin(9600);
	Serial.begin(9600);
	Serial.flush();
	while(Serial.available()>0)Serial.read();

}
void loop() {
  gas = analogRead(A0);
  	bt_serial.println(String("Gas Value:")+String(gas));
  	Serial.println(String("Gas Value:")+String(gas));

  delay(10000); // Delay for a second before the next reading
}
