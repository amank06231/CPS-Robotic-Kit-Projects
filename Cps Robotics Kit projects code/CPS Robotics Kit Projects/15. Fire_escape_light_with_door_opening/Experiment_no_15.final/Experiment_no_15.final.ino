#include <Servo.h>

Servo doorServo;  // Servo motor for door
int flameSensorPin = 11;  // Flame sensor input pin
int ledPin = 5;  // LED (flashlight) pin
// int buzzerPin = 6;  // Buzzer pin (optional)

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  // pinMode(buzzerPin, OUTPUT);  // If using a buzzer, uncomment this line
  
  doorServo.attach(4);  // Servo connected to pin 4
  doorServo.write(0);  // Start with door closed
  
  digitalWrite(ledPin, LOW);
  // digitalWrite(buzzerPin, LOW);  // Prevent errors if using a buzzer

  Serial.begin(9600);  
}

void loop() {
  int flame = digitalRead(flameSensorPin);  // Read flame sensor

  Serial.print("Flame value: ");
  Serial.println(flame);
  
  if (flame == LOW) {  
    // Fire detected
    doorServo.write(90);  // Open door at 90 degrees
    digitalWrite(ledPin, HIGH);  
    // digitalWrite(buzzerPin, HIGH);  // Uncomment if using a buzzer
    Serial.println("Fire detected! Door opened, flashlight ON.");
  } else {
    // No fire
    doorServo.write(0);  // Keep door closed
    digitalWrite(ledPin, LOW);
    // digitalWrite(buzzerPin, LOW);  // Uncomment if using a buzzer
    
    Serial.println(" No fire. Door closed, flashlight OFF.");
  }

  delay(1000);
}
