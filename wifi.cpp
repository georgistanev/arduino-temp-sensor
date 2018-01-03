#include <ESP8266WiFi.h>

bool initWifi(const char* ssid, const char* password) {
    // Connect to Wifi.
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    // WiFi fix: https://github.com/esp8266/Arduino/issues/2186
    WiFi.persistent(false);
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    unsigned long wifiConnectStart = millis();

    while (WiFi.status() != WL_CONNECTED) {
        // Check to see if
        if (WiFi.status() == WL_CONNECT_FAILED) {
            Serial.println("Failed to connect to WiFi. Please verify credentials: ");
            delay(10000);
        }

        delay(500);
        Serial.println("...");
        // Only try for 5 seconds.
        if (millis() - wifiConnectStart > 15000) {
            Serial.println("Failed to connect to WiFi");
            return false;
        }
    }

    Serial.println("WiFi connected. IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("-------------------------------------");

    return true;
}
