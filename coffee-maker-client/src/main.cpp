#include <Arduino.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#define WIFI_SSID "456 Harold"
#define WIFI_PASSWORD "shizzledizzle"

WiFiMulti wifiMulti;
HTTPClient http;
String serverUrl = "http://192.168.8.135:3000";

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(27, OUTPUT);
  Serial.begin(921600);
  Serial.println("Hello, World!");

  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting...");
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("Connected!");

  Serial.println(WiFi.localIP()); 

  
}

void loop() {
  digitalWrite(LED_BUILTIN, WiFi.status() == WL_CONNECTED);
  if (WiFi.status() == WL_CONNECTED) {

    http.begin(serverUrl);
    int httpCode = http.GET();

    if(httpCode > 0) {
      Serial.printf("HTTP GET Code: %d\n", httpCode);
      String payload = http.getString();
      Serial.println("Response: ");
      Serial.println(payload);
      if (payload == "1") {
        digitalWrite(27, HIGH);
      } else {
        digitalWrite(27, LOW);
      }
    } else {
      Serial.printf("GET request failed: %s\n", http.errorToString(httpCode).c_str());
    }
  }
}
