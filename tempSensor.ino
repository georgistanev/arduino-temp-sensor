#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

DHT dht(D2, DHT22);

#include "serial.h"
#include "wifi.h"
#include "http.h"
#include "credentials.h"

void setup() {
  	initSerial();
	  initWifi(WIFI_SSID, WIFI_PASS);

    dht.begin();
}

void loop() {
    float humidity = dht.readHumidity();
    float temp = dht.readTemperature();
    
    Serial.println("Read data:");
    Serial.println(temp);
    Serial.println(humidity);
  
    delay(1000);
}
