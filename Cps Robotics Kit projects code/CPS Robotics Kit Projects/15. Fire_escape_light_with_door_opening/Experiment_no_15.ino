#include <Servo.h>

Servo doorServo;  // Servo motor for door
int flameSensorPin = 11;  // Flame sensor input pin
int ledPin = 5;  // LED (flashlight) pin
int buzzerPin = 4;  // Buzzer pin (optional)

void setup() {
  // Initialize pin modes
  pinMode(flameSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Attach servo motor to pin 4
  doorServo.attach(4);
  doorServo.write(0);  // Start with door closed (0 degrees)
  
  // Turn off LED and buzzer at the start
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
  Serial.begin(9600);  // Start serial monitor for debugging
}

void loop() {
  int flame = digitalRead(flameSensorPin);  // Read flame sensor value
  
  Serial.print("Flame value: ");
  Serial.println(flame);  // For monitoring
  
  if (flame == LOW) {
    // Fire detected
    doorServo.write(150);  // Open the door (150 degrees)
    digitalWrite(ledPin, HIGH);  // Turn on the LED (flashlight)
    digitalWrite(buzzerPin, HIGH);  // Activate the buzzer (optional)
    Serial.println("Fire detected! Door opened, flashlight ON.");
  } else {
    // No fire
    doorServo.write(0);  // Keep the door closed
    digitalWrite(ledPin, LOW);  // Turn off the LED
    digitalWrite(buzzerPin, LOW);  // Deactivate the buzzer
    Serial.println("No fire detected. Door closed, flashlight OFF.");
  }

  delay(1000);  // Short delay for stability
}  // <-- This closing brace was missing, now it's fixed!
