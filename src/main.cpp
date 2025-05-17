#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(27, OUTPUT);
  Serial.begin(921600);
  Serial.println("Hello, World!");
}

void loop() {
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(27, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(27, LOW);
  Serial.println("Hello from the loop");
}
