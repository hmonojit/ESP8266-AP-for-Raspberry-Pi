#include <ESP8266WiFi.h>

const char *ssid = "Raspbian Server";      // Set your desired SSID (WiFi Network Name)
const char *password = "Raspberrypi";  // Set your desired password

void setup() {
  Serial.begin(115200);
  
  // Set up the ESP8266 as an access point
  WiFi.softAP(ssid, password);

  Serial.println("WiFi Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Get the number of connected devices
  int numDevices = WiFi.softAPgetStationNum();
  Serial.print("Number of connected devices: ");
  Serial.println(numDevices);

  // Print information about each connected device
  if (numDevices > 0) {
    Serial.println("Connected Devices:");
    for (int i = 0; i < numDevices; i++) {
      // For simplicity, assume that all devices have IP addresses starting from 192.168.4.2
      IPAddress ipAddress(192, 168, 4, i + 2);

      Serial.print("Device ");
      Serial.print(i + 1);
      Serial.print(" - IP Address: ");
      Serial.println(ipAddress);
    }
  }

  delay(5000);  // Delay for 5 seconds before checking again
}
