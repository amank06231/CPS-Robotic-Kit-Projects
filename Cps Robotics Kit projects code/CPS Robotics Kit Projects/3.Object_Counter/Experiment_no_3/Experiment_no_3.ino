#include <Wire.h>
#include <U8g2lib.h>

// IR Sensor and Buzzer Pin Configuration
const int IRPin = 11;
const int buzzerPin = 4;

int n = 0;
int oldValue = 1;

// Initialize OLED
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

void setup() {
  pinMode(IRPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
  
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB10_tr);
  u8g2.drawStr(10, 30, "Object Counter");
  u8g2.sendBuffer();
  delay(3000);
  updateDisplay();
}

void loop() {
  if (digitalRead(IRPin) == 0 && oldValue == 1) {
    oldValue = 0;
    n++; // Increase count

    Serial.print(F("Count: "));
    Serial.println(n);
    
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    
    updateDisplay();
  } 
  else if (digitalRead(IRPin) == 1 && oldValue == 0) {
    oldValue = 1;
  }

  delay(100);
}

void updateDisplay() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB12_tr);
  u8g2.drawStr(10, 30, "Count:  ");
  
  char countStr[6];
  sprintf(countStr, "%d", n); // Convert number to string
  u8g2.drawStr(80, 30, countStr);
  
  u8g2.sendBuffer();
}



















