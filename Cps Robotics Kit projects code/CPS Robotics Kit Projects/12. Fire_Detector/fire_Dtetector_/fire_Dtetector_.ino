#include <Wire.h>
#include <U8g2lib.h>

// Initialize OLED display using I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int buzzerPin = 4;
const int flamePin =11;
int Flame = LOW;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);

  u8g2.begin();
  showStartupMessage();
}

void loop() {
  Flame = digitalRead(flamePin);
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);  // Set font

  if (Flame == HIGH) {
    u8g2.drawStr(10, 20, "Fire Detected! ");
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  } else {
    u8g2.drawStr(10, 20, "✅ No Fire Detected");
    digitalWrite(buzzerPin, LOW);
  }

  u8g2.sendBuffer();
  delay(1000);
}

void showStartupMessage() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(10, 30, " Fire Detector ");
  u8g2.sendBuffer();
  delay(2000);
}
