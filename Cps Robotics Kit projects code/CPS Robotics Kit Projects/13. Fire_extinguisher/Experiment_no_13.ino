#include <Wire.h>
#include <U8g2lib.h>
#define Pump_pin 5
#define buzzerPin 4
#define flamePin 11

int Flame = HIGH;  
bool fireDetected = false;  

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ A5, /* data=*/ A4, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT_PULLUP);  // Use internal pull-up
  pinMode(Pump_pin, OUTPUT);
  
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(10, 30, "Fire Extinguisher");
  u8g2.sendBuffer();
  delay(3000);
}

void loop() {
  Flame = digitalRead(flamePin);

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  
  if (Flame == LOW && !fireDetected) {  // If fire detected (LOW)
    fireDetected = true;
    u8g2.drawStr(10, 40, "Fire Detected!");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(Pump_pin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  } 
  else if (Flame == HIGH && fireDetected) {  // If no fire
    fireDetected = false;
    u8g2.drawStr(10, 40, "No Fire");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(Pump_pin, LOW);
  }

  u8g2.sendBuffer();
  delay(500);
}