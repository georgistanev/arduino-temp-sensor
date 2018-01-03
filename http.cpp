#include <ESP8266HTTPClient.h>


void httpRequest(const char* url) {
    HTTPClient http;
    http.begin(url);
    // http.addHeader("Content-Type", "application/json");
    // http.addHeader("Accept", "application/json");

    int httpCode = http.GET();
    Serial.println(httpCode);
    Serial.println(http.getString());

    http.end();
}

