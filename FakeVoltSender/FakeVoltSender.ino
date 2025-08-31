#include "M5Atom.h"
#include <WiFi.h>
#include <esp_now.h>

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
esp_now_peer_info_t peerInfo;

float voltage = 0.0;  // Initialize voltage to 0.0
bool buttonPressed = false;
bool lastButtonState = false;

void setup() {
  // Initialize M5ATOM with LED matrix enabled
  M5.begin(true, false, true);
  
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("M5ATOM Voltage Monitor");
  Serial.println("Press button to increment voltage by 0.01V");
  Serial.print("Initial voltage: ");
  Serial.print(voltage, 2);  // Print with 2 decimal places
  Serial.println("V");

  // Initialise ESP-NOW
  WiFi.mode(WIFI_MODE_STA);
  esp_now_init();
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  esp_now_add_peer(&peerInfo);
}

void loop() {
  M5.update();  // Update button state
  
  // Get current button state
  bool currentButtonState = M5.Btn.isPressed();
  
  // Detect button press (rising edge)
  if (currentButtonState && !lastButtonState) {
    voltage += 0.01;  // Increment voltage by 0.01
    
    // Broadcast new voltage to ALL ESP-NOW devices
    esp_now_send(broadcastAddress, (uint8_t *) &voltage, sizeof(voltage));

    // Print new voltage value to serial monitor
    Serial.print("Voltage: ");
    Serial.print(voltage, 2);  // Print with 2 decimal places
    Serial.println("V");
    
    // Optional: Flash LED to indicate button press
    M5.dis.drawpix(0, 0x00ff00);  // Green LED
    delay(100);
    M5.dis.drawpix(0, 0x000000);  // Turn off LED
  }
  
  lastButtonState = currentButtonState;
  
  delay(10);  // Small delay for debouncing
}