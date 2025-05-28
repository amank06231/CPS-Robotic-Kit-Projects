#include <Wire.h>
#include <U8g2lib.h>

// Initialize OLED display (Check your OLED address: 0x3C or 0x3D)
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ A5, /* data=*/ A4, /* reset=*/ U8X8_PIN_NONE);  

int sensor_pin = A0;

void setup() {
  u8g2.begin();  // Start OLED
  pinMode(sensor_pin, INPUT);
}

void loop() {
  int sensor_data = analogRead(sensor_pin);

  // Clear OLED screen
  u8g2.clearBuffer();  

  // Set font
  u8g2.setFont(u8g2_font_ncenB08_tr);

  // Display moisture status
  u8g2.setCursor(0, 15);
  if (sensor_data >= 0 && sensor_data < 550) {
    u8g2.print("Good moisture");
  } 
  else if (sensor_data >= 550 && sensor_data < 700) {
    u8g2.print("Low moisture");
  } 
  else {
    u8g2.print("Soil is dry");
  }

  // Display sensor value
  u8g2.setCursor(0, 35);
  u8g2.print("Level: ");
  u8g2.print(sensor_data);

  // Send data to display
  u8g2.sendBuffer();

  delay(1000); // 1-second delay
}
