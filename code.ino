#include <WiFi.h>

const char* ssid = "";          // Replace with your WiFi SSID
const char* password = "";  // Replace with your WiFi Password


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(38400);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Print the device's IP address
}

void loop() {
  // put your main code here, to run repeatedly: if (WiFi.status() == WL_CONNECTED) {
  if (WiFi.status() == WL_CONNECTED) {
    int32_t rssi = WiFi.RSSI();  // Get the RSSI value
    Serial.print("RSSI: ");
    Serial.print(rssi);
    Serial.println(" dBm");
  } else {
    Serial.println("Not connected to Wi-Fi");
  }
  delay(5000); 
}
