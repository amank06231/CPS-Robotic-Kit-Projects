// #include <Wire.h>
// #include "Adafruit_SHT4x.h"
// #include <SoftwareSerial.h>

// SoftwareSerial BT(2, 3); // RX, TX for Bluetooth
// Adafruit_SHT4x sht4;  // Create an SHT40 object

// void setup() {
//     Serial.begin(9600);  // Serial Monitor
//     BT.begin(9600);      // Bluetooth module baud rate

//     if (!sht4.begin()) {
//         Serial.println("Couldn't find SHT4x sensor!");
//         while (1);
//     }
//     Serial.println("SHT40 sensor found.");
// }

// void loop() {
//     sensors_event_t humidity, temp;

//     // Read temperature and humidity
//     sht4.getEvent(&humidity, &temp);

//     float temperature = temp.temperature;
//     float humidityVal = humidity.relative_humidity;

//     // Print to Serial Monitor
//     Serial.print("Temp: "); Serial.print(temperature); Serial.print(" °C, ");
//     Serial.print("Humidity: "); Serial.print(humidityVal); Serial.println(" %");

//     // Send data via Bluetooth
//     BT.print("Temperature: "); BT.print(temperature); BT.print(" °C, ");
//     BT.print("Humidity: "); BT.print(humidityVal); BT.println(" %");

//     delay(2000);  // Update every 2 seconds
// }


#include <Wire.h>
#include "Adafruit_SHT4x.h"
#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX for Bluetooth
Adafruit_SHT4x sht4;     // Create an SHT40 object

float sensorData[2];     // [0] = temperature, [1] = humidity

void setup() {
    Serial.begin(9600);
    BT.begin(9600);

    if (!sht4.begin()) {
        Serial.println("Couldn't find SHT4x sensor!");
        while (1);
    }
    Serial.println("SHT40 sensor found.");
}

void loop() {
    sensors_event_t humidity, temp;

    sht4.getEvent(&humidity, &temp);

    sensorData[0] = temp.temperature;
    sensorData[1] = humidity.relative_humidity;

    Serial.print("Temp: "); Serial.print(sensorData[0]); Serial.print(" °C, ");
    Serial.print("Humidity: "); Serial.print(sensorData[1]); Serial.println(" %");

    // Convert floats to strings using dtostrf()
    char tempStr[10];
    char humidStr[10];
    dtostrf(sensorData[0], 5, 2, tempStr);  // width=5, precision=2
    dtostrf(sensorData[1], 5, 2, humidStr);

    // Format string to send via Bluetooth
    char dataBuffer[30];
    snprintf(dataBuffer, sizeof(dataBuffer), "[%s,%s]", tempStr, humidStr);

    BT.println(dataBuffer);

    delay(2000);
}




























// #include <Wire.h>
// #include "Adafruit_SHT4x.h"
// #include <SoftwareSerial.h>

// SoftwareSerial BT(2, 3);  // RX, TX for Bluetooth
// Adafruit_SHT4x sht4;      // Create an SHT40 object

// float sensorData[2];  // [0] = temperature, [1] = humidity

// void setup() {
//   Serial.begin(9600);
//   BT.begin(9600);

//   if (!sht4.begin()) {
//     Serial.println("Couldn't find SHT4x sensor!");
//     while (1)
//       ;
//   }
//   Serial.println("SHT40 sensor found.");
// }

// void loop() {
//   sensors_event_t humidity, temp;

//   sht4.getEvent(&humidity, &temp);

//   sensorData[0] = temp.temperature;
//   sensorData[1] = humidity.relative_humidity;

//   // Split temperature
//   uint8_t temp_value1 = (uint8_t)sensorData[0];                          // Integer part
//   uint8_t temp_value2 = (uint8_t)((sensorData[0] - temp_value1) * 100);  // Decimal part * 100

//   // Split humidity
//   uint8_t hum_value1 = (uint8_t)sensorData[1];
//   uint8_t hum_value2 = (uint8_t)((sensorData[1] - hum_value1) * 100);

//   // Optional: Store in a byte array
//   uint8_t mfg_data[10];
//   mfg_data[3] = temp_value1;
//   mfg_data[4] = temp_value2;
//   mfg_data[5] = hum_value1;
//   mfg_data[6] = hum_value2;

//   // Serial debug
//   Serial.print("Temp: ");
//   Serial.print(temp_value1);
//   Serial.print(".");
//   Serial.print(temp_value2);
//   Serial.print(" °C, Humidity: ");
//   Serial.print(hum_value1);
//   Serial.print(".");
//   Serial.print(hum_value2);
//   Serial.println(" %");


//   // Convert floats to strings using dtostrf()
//   // char tempStr[10];
//   // char humidStr[10];
//   // dtostrf(sensorData[0], 5, 2, tempStr);  // width=5, precision=2
//   // dtostrf(sensorData[1], 5, 2, humidStr);


//   // Format string to send via Bluetooth
//   char dataBuffer[30];
//   // snprintf(dataBuffer, sizeof(dataBuffer), "[%s,%s]", tempStr, humidStr);
//   snprintf(dataBuffer, sizeof(dataBuffer), "[%d.%02d,%d.%02d]", temp_value1, temp_value2, hum_value1, hum_value2);
//   BT.println(dataBuffer);

//   delay(2000);
// }
