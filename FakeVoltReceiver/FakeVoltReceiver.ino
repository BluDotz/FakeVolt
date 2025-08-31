#include "M5Atom.h"
#include <WiFi.h>
#include <esp_now.h>

float voltage = 0.0;  // Initialize voltage to 0.0

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&voltage, incomingData, sizeof(voltage));
  Serial.print("Voltage: ");
  Serial.print(voltage, 2);  // Print with 2 decimal places
  Serial.println("V");

  // Flash LED to indicate button press
  M5.dis.drawpix(0, 0x00ff00);  // Green LED
  delay(100);
  M5.dis.drawpix(0, 0x000000);  // Turn off LED
}

void setup() {
  // Initialize M5ATOM with LED matrix enabled
  M5.begin(true, false, true);
  
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("M5ATOM Voltage Monitor");
  Serial.print("Initial voltage: ");
  Serial.print(voltage, 2);  // Print with 2 decimal places
  Serial.println("V");

  // Initialise ESP-NOW
  WiFi.mode(WIFI_MODE_STA);
  esp_now_init();
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
}