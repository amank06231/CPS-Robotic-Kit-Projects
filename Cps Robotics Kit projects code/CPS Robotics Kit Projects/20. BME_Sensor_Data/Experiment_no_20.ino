#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() {
    Serial.begin(9600);
    Wire.begin(); // Initialize I2C
    
    Serial.println("Initializing BMP180 at 0x77...");
    
    if (!bmp.begin()) {
        Serial.println("ERROR: BMP180 not found! Check wiring.");
        while (1);
    }

    Serial.println("BMP180 successfully detected!");
}

void loop() {
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" °C");

    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.println("--------------------------");
    delay(2000);
}




