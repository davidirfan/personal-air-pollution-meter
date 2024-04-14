#include <MQ135.h>

MQ135 gasSensor = MQ135(A0);

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  float gasConcentration = gasSensor.getPPM();  // Read gas concentration in PPM
  Serial.print("Gas Concentration: ");
  Serial.print(gasConcentration);
  Serial.print(" PPM");

  delay(1000);  // Delay for a second before the next reading
}
