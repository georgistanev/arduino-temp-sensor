#include <ESP8266WiFi.h>

void initSerial() {
  Serial.begin(115200);
  Serial.setTimeout(2000);

  // Wait for serial to initialize.
  while (!Serial) { }

  Serial.println("Serial initialized");
  Serial.println("-------------------------------------");
}
