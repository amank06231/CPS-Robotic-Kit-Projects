#include <Wire.h>
#include <U8g2lib.h>

#define TriggerPin 10
#define EchoPin 12
#define buzzer 4

long Duration;
float Distance;  // Changed to float for better precision

// Initialize OLED display (Assuming SSD1306, I2C address 0x3C)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
    pinMode(TriggerPin, OUTPUT);
    pinMode(EchoPin, INPUT);
    pinMode(buzzer, OUTPUT);
    
    u8g2.begin();  // Start OLED
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    
    // Display startup message
    u8g2.drawStr(10, 20, "Intruder Alert");
    u8g2.drawStr(15, 40, "System Ready");
    u8g2.sendBuffer();
    
    delay(2000);
    u8g2.clearBuffer();
}

void loop() {
    // Trigger ultrasonic sensor
    digitalWrite(TriggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);

    // Read echo signal with timeout
    Duration = pulseIn(EchoPin, HIGH, 30000);
    Distance = (Duration * 0.0343) / 2.0;  // More precise calculation

    u8g2.clearBuffer();  // Clear screen before updating

    if (Duration == 0 || Distance > 400) {  // Out of range
        u8g2.drawStr(20, 20, "Out of Range");
        digitalWrite(buzzer, LOW);
    } 
    else if (Distance >= 4 && Distance <= 6) {  // Buzzer beeps only at 5cm ±1cm
        u8g2.drawStr(30, 20, "INTRUDER!");
        u8g2.setCursor(25, 40);
        u8g2.print("At ");
        u8g2.print(Distance);
        u8g2.print(" cm");
        
        digitalWrite(buzzer, HIGH);
    } 
    else {
        u8g2.drawStr(30, 20, "Monitoring...");
        u8g2.setCursor(25, 40);
        u8g2.print("Distance: ");
        u8g2.print(Distance);
        u8g2.print(" cm");
        
        digitalWrite(buzzer, LOW);
    }

    u8g2.sendBuffer();  // Update display
    delay(500);
}
