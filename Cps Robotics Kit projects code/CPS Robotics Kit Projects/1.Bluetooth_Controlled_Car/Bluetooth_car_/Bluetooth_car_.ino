#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3);  // RX, TX (Bluetooth Module)

// Define motor driver pins
int h1 = 4;  // Horn
int m1a = 5;  // Motor 1 Forward (Left side)
int m1b = 6;  // Motor 1 Backward (Left side)
int m2a = 8;  // Motor 2 Forward (Right side)
int m2b = 7;  // Motor 2 Backward (Right side)

char val;

void setup() {
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);

  Serial.begin(9600);  // Debugging in Serial Monitor
  BT.begin(9600);      // Start Bluetooth Communication
}

void loop() {
  if (BT.available()) {
    val = BT.read();      // Read Bluetooth input
    Serial.println(val);  // Debug output
  }

  // Move Forward (U)
  if (val == 'U') {
    digitalWrite(m1a, HIGH);  // Left Wheels Forward
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);  // Right Wheels Forward
    digitalWrite(m2b, LOW);
  }
  // Move Backward (D)
  else if (val == 'D') {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);  // Left Wheels Backward
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);  // Right Wheels Backward
  }
  // // Turn Left (L) - Left wheels move backward, right wheels move forward
  // else if (val == 'L') {
  //   digitalWrite(m1a, LOW);
  //   digitalWrite(m1b, HIGH);  // Left Wheels Backward
  //   digitalWrite(m2a, HIGH);
  //   digitalWrite(m2b, LOW);   // Right Wheels Forward
  // }
  // // Turn Right (R) - Left wheels move forward, right wheels move backward
  // else if (val == 'R') {
  //   digitalWrite(m1a, HIGH);
  //   digitalWrite(m1b, LOW);  // Left Wheels Forward
  //   digitalWrite(m2a, LOW);
  //   digitalWrite(m2b, HIGH); // Right Wheels Backward
  // }



  // Turn Left (L) - Left Forward Wheel forward, Right Forward Wheel backward
  else if (val == 'L') {
    digitalWrite(m1a, HIGH);  // Left Forward Wheel - FORWARD
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);  // Right Forward Wheel - BACKWARD
    digitalWrite(m2b, HIGH);
  }

  // Turn Right (R) - Left Forward Wheel backward, Right Forward Wheel forward
  else if (val == 'R') {
    digitalWrite(m1a, LOW);  // Left Forward Wheel - BACKWARD
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);  // Right Forward Wheel - FORWARD
    digitalWrite(m2b, LOW);
  }
  // Stop (C)
  else if (val == 'C') {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(h1, LOW);
  } 
  // Horn (H)
  else if (val == 'H') {
    digitalWrite(h1, HIGH);
    delay(1000);

  }
}











































