#include <SoftwareSerial.h>
#include <NewPing.h>

// Bluetooth module pins (RX, TX)
SoftwareSerial BT(2, 3); 

// Motor control pins
const int m1a = 5;  
const int m1b = 6;  
const int m2a = 7;  
const int m2b = 8;  

// Ultrasonic sensor pins
#define trig_pin 10
#define echo_pin 12
#define max_distance 200

// Buzzer pin
#define buzzer 4 

char val;
NewPing sonar(trig_pin, echo_pin, max_distance);

void setup() {
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  int distance = readPing();

  // Beep the buzzer if an obstacle is close
  if (distance <= 20) {
    digitalWrite(buzzer, HIGH);
    Serial.println("Obstacle detected! Beeping...");
  } else {
    digitalWrite(buzzer, LOW);
  }

  // Read Bluetooth command
  if (BT.available()) {  
    val = BT.read();
    Serial.print("Command: ");
    Serial.println(val);
  }

  // Execute movement commands
  if (val == 'U') {  
    moveForward();
  } 
  else if (val == 'D') {  
    moveBackward();
  } 
  else if (val == 'L') {  
    turnLeft();
  } 
  else if (val == 'R') {  
    turnRight();
  } 
  else if (val == 'C') {  
    moveStop();
  }
}

// Function to measure distance using ultrasonic sensor
int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  return (cm == 0) ? 250 : cm;
}

// Motor control functions
void moveForward() {
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void moveBackward() {
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}

void turnLeft() {
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void turnRight() {
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}

void moveStop() {
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}
