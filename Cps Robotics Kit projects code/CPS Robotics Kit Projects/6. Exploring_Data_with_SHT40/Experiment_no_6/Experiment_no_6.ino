// #include <Wire.h>
// #include <Adafruit_SHT4x.h>

// // Initialize SHT40 sensor
// Adafruit_SHT4x sht4 = Adafruit_SHT4x();

// void setup() {
//   Serial.begin(9600);
  
//   if (!sht4.begin()) {  // Check if sensor is detected
//     Serial.println("SHT40 not found! Check connections.");
//     while (1); // Halt execution
//   }

//   Serial.println("SHT40 Found!");

//   // Set the precision mode (default is high)
//   sht4.setPrecision(SHT4X_HIGH_PRECISION);
  
//   // Enable heater (optional)
//   sht4.setHeater(SHT4X_NO_HEATER); // SHT4X_HIGH_HEATER_1S for heating
// }

// void loop() {
//   sensors_event_t humidity, temp;
//   sht4.getEvent(&humidity, &temp); // Read temperature and humidity

//   Serial.print("Temperature: ");
//   Serial.print(temp.temperature);
//   Serial.println(" °C");

//   Serial.print("Humidity: ");
//   Serial.print(humidity.relative_humidity);
//   Serial.println(" %");

//   Serial.println("----------------------");

//   delay(1000); // 1-second delay
// }


// #include <Wire.h>
// #include <Adafruit_SHT4x.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// // Initialize SHT40 sensor
// Adafruit_SHT4x sht4 = Adafruit_SHT4x();

// // OLED display width and height (for 0.96" OLED, usually 128x64)
// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64

// // Create display object (I2C address is usually 0x3C)
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// void setup() {
//   Serial.begin(9600);
  
//   // Initialize OLED
//   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
//     Serial.println(F("SSD1306 allocation failed"));
//     while(1);
//   }
//   display.clearDisplay();
//   display.setTextSize(1);      // Normal 1:1 pixel scale
//   display.setTextColor(SSD1306_WHITE); // Draw white text
//   display.setCursor(0,0);      // Start at top-left corner
//   display.display();
  
//   // Initialize sensor
//   if (!sht4.begin()) {  
//     Serial.println("SHT40 not found! Check connections.");
//     while (1); // Halt execution
//   }

//   Serial.println("SHT40 Found!");

//   sht4.setPrecision(SHT4X_HIGH_PRECISION);
//   sht4.setHeater(SHT4X_NO_HEATER);
// }

// void loop() {
//   sensors_event_t humidity, temp;
//   sht4.getEvent(&humidity, &temp);

//   // Print to Serial Monitor (optional)
//   Serial.print("Temperature: ");
//   Serial.print(temp.temperature);
//   Serial.println(" °C");

//   Serial.print("Humidity: ");
//   Serial.print(humidity.relative_humidity);
//   Serial.println(" %");

//   Serial.println("----------------------");

//   // Print to OLED
//   display.clearDisplay(); // Clear previous values
  
//   display.setCursor(10, 30);
//   display.print("Temp: ");
//   display.print(temp.temperature, 1); // 1 decimal place
//   display.print(" C");

//   display.setCursor(10, 40);
//   display.print("Humidity: ");
//   display.print(humidity.relative_humidity, 1); // 1 decimal place
//   display.print(" %");

//   display.display(); // Update the display with new data

//   delay(1000);
// }




#include <Wire.h>
#include <Adafruit_SHT4x.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SHT4x sht4 = Adafruit_SHT4x();

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while(1);
  }
  display.clearDisplay();
  
  if (!sht4.begin()) {  
    Serial.println("SHT40 not found! Check connections.");
    while (1);
  }
  Serial.println("SHT40 Found!");

  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  sht4.setHeater(SHT4X_NO_HEATER);
}

void loop() {
  sensors_event_t humidity, temp;
  sht4.getEvent(&humidity, &temp);

  display.clearDisplay();
  
  display.setTextSize(3);   // Bigger text for bigger screen
  display.setTextColor(SSD1306_WHITE);

  // Centering text manually
  // First line: Temperature
  display.setCursor(5, 5); // (x=5, y=5)
  display.print("T:");
  display.print(temp.temperature, 1); 
  display.print((char)247); // Degree symbol
  display.print("C");

  // Second line: Humidity
  display.setCursor(5, 40); // (x=5, y=40)
  display.print("H:");
  display.print(humidity.relative_humidity, 1);
  display.print("%");

  display.display();

  delay(1000);
}


