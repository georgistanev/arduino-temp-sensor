#include <ESP8266WiFi.h>tials
#include <ESP8266HTTPClient.h>
#include "serial.h"
#include "wifi.h"
#include "http.h"
#include "credentials.h"

void setup() {
	initSerial();
	initWifi(WIFI_SSID, WIFI_PASS);
}

void loop() {
  httpRequest("http://google.com");
  delay(10000);
}
