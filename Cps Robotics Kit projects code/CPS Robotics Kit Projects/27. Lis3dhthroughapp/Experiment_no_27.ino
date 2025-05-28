#include <Wire.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX for Bluetooth module
Adafruit_LIS3DH lis = Adafruit_LIS3DH();  // Create LIS3DH object

void setup() {
    Serial.begin(9600);  // Start Serial Monitor
    BT.begin(9600);      // Start Bluetooth

    if (!lis.begin(0x18)) { // Check if LIS3DH is detected (I2C address: 0x18)
        Serial.println("Couldn't find LIS3DH sensor!");
        while (1);
    }
    Serial.println("LIS3DH sensor found.");
    
    lis.setRange(LIS3DH_RANGE_2_G); // Set accelerometer range to ±2G
}

void loop() {
    lis.read();  // Read LIS3DH accelerometer values

    float x = lis.x / 16384.0;  // Convert raw values to G (assuming ±2G range)
    float y = lis.y / 16384.0;
    float z = lis.z / 16384.0;

    // Print to Serial Monitor
    Serial.print("X: "); Serial.print(x); Serial.print(" G, ");
    Serial.print("Y: "); Serial.print(y); Serial.print(" G, ");
    Serial.print("Z: "); Serial.print(z); Serial.println(" G");

    // Send data via Bluetooth
    BT.print("X: "); BT.print(x); BT.print(" G, ");
    BT.print("Y: "); BT.print(y); BT.print(" G, ");
    BT.print("Z: "); BT.print(z); BT.println(" G");

    delay(500);  // Update every 500ms
}
