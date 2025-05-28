#include <Wire.h>
#include <U8g2lib.h>

// Define Trigger and Echo pins for distance measurement
const int TriggerPin = 10;
const int EchoPin = 12;
long Duration;

// Initialize OLED Display
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

void setup() {
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600); // Baud rate

  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB10_tr); // Medium size font
  u8g2.drawStr(10, 30, "Hello Kids!"); // Change this text easily
  u8g2.sendBuffer();
  delay(2000);
}

void loop() {
  // Measure distance
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  Duration = pulseIn(EchoPin, HIGH);
  long Distance_cm = (Duration * 0.034) / 2;

  // Clear screen
  u8g2.clearBuffer();

  // Show "Distance:" text
  u8g2.setFont(u8g2_font_ncenB12_tr);
  u8g2.drawStr(15, 30, "Distance:");

  // Show actual distance value
  u8g2.setFont(u8g2_font_ncenB14_tr); // Bigger font for number
  char buffer[10];
  sprintf(buffer, "%ld cm", Distance_cm);
  u8g2.drawStr(10, 50, buffer); // Change position easily

  // Update OLED screen
  u8g2.sendBuffer();

  // Show distance in Serial Monitor
  Serial.print("Distance: ");
  Serial.print(Distance_cm);
  Serial.println(" cm");

  delay(1000); // Wait 1 second
}















// #include <Wire.h>
// #include <U8g2lib.h>

// const int TriggerPin = 10;  // Updated Trigger Pin
// const int EchoPin = 12;     // Updated Echo Pin
// long Duration;

// // Initialize OLED Display (Change if using different hardware)
// U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

// void setup() {
//   pinMode(TriggerPin, OUTPUT);
//   pinMode(EchoPin, INPUT);
//   Serial.begin(9600); // Baud rate

//   u8g2.begin();
//   u8g2.clearBuffer();
//   u8g2.setFont(u8g2_font_ncenB08_tr);  // Set font
//   u8g2.drawStr(20, 20, "Distance Meter");
//   u8g2.sendBuffer();
//   delay(3000);
// }

// void loop() {
//   digitalWrite(TriggerPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(TriggerPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(TriggerPin, LOW);

//   Duration = pulseIn(EchoPin, HIGH);
//   long Distance_cm = Distance(Duration);

//   u8g2.clearBuffer();
//   u8g2.setFont(u8g2_font_ncenB08_tr);  

//   if (Distance_cm > 500) {  // If distance exceeds 500cm
//     u8g2.drawStr(30, 20, "Target:");
//     u8g2.drawStr(15, 40, "Out of Range!");
//   } else {
//     char buffer[20];
//     sprintf(buffer, "Distance: %ld cm", Distance_cm);
//     u8g2.drawStr(30, 20, "Target:");
//     u8g2.drawStr(10, 40, buffer);  // Displays formatted distance
//   }

//   u8g2.sendBuffer();
//   Serial.print("Distance: ");
//   Serial.print(Distance_cm);
//   Serial.println(" cm");

//   delay(1000); // Delay between readings
// }

// long Distance(long time) {
//   return (time * 0.034) / 2;
// }
