#include <Servo.h>

const int trigPin = 10;
const int echoPin = 12;
Servo myServo;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  myServo.attach(4);

  Serial.println("Angle, Distance(cm)");
}

void loop() {
  // Move servo from 15° to 165° and scan distance
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();

    Serial.print(i);
    Serial.print(", ");
    Serial.println(distance);
  }

  // Move servo back from 165° to 15° and scan distance
  for (int i = 165; i >= 15; i--) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();

    Serial.print(i);
    Serial.print(", ");
    Serial.println(distance);
  }
}

// Function to measure distance using Ultrasonic Sensor
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);  // 30ms timeout
  distance = (duration * 0.034) / 2;

  // Limit distance readings to a reasonable range
  if (distance == 0 || distance > 400) {
    return -1;  // Return -1 if out of range
  }
  return distance;
}