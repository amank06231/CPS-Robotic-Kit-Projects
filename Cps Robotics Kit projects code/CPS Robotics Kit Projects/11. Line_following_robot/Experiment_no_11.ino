// Define pin connections
#define irSensorLeft  11   // Left IR sensor signal pin
#define irSensorRight 10   // Right IR sensor signal pin

#define leftMotor1 5       // Left motor control pin 1
#define leftMotor2 6       // Left motor control pin 2
#define rightMotor1 8     // Right motor control pin 1
#define rightMotor2 7      // Right motor control pin 2

void setup() {
  pinMode(irSensorLeft, INPUT);    
  pinMode(irSensorRight, INPUT);   

  pinMode(leftMotor1, OUTPUT);    
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  
  Serial.begin(9600);             
}

void loop() {
  int leftValue = digitalRead(irSensorLeft);  
  int rightValue = digitalRead(irSensorRight); 

  Serial.print("Left Sensor: ");
  Serial.print(leftValue);
  Serial.print(" Right Sensor: ");
  Serial.println(rightValue);

  if (leftValue == HIGH && rightValue == HIGH) {  
    stopMotors();  // Both sensors detect white → STOP
  } 
  else if (leftValue == HIGH) {  
    turnRight();  // Left sensor detects white → Turn Left
  } 
  else if (rightValue == HIGH) {  
    turnLeft();  // Right sensor detects white → Turn Right
  } 
  else {  
    moveForward();  // Both sensors detect black → Move Forward
  }
}


// if (leftValue == HIGH && rightValue == HIGH) {  
//     stopMotors();  // Both sensors detect white → STOP
// } 
// else if (leftValue == LOW) {  
//     turnLeft ();  // Left sensor detects black (line) → Turn Left
// } 
// else if (rightValue == LOW) {  
//     turnRight();  // Right sensor detects black (line) → Turn Right
// } 
// else {  
//     moveForward();  // Both sensors detect white → Move Forward
// }
  







// Function to move forward
void moveForward() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

// Function to turn left
void turnLeft() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}

// Function to stop motors
void stopMotors() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}







// // Define pin connections
// #define irSensorLeft  11   // Left IR sensor signal pin
// #define irSensorRight 10   // Right IR sensor signal pin

// // #define leftMotor1 5       // Left motor control pin 1
// // #define leftMotor2 6       // Left motor control pin 2
// // #define rightMotor1 7      // Right motor control pin 1
// // #define rightMotor2 8      // Right motor control pin 2

// #define leftMotor1 5       // Left motor control pin 1
// #define leftMotor2 6       // Left motor control pin 2
// #define rightMotor1 8      // Right motor control pin 1
// #define rightMotor2 7      // Right motor control pin 2

// void setup() {
//   pinMode(irSensorLeft, INPUT);    // Left IR sensor
//   pinMode(irSensorRight, INPUT);   // Right IR sensor

//   pinMode(leftMotor1, OUTPUT);    // Motor control pins
//   pinMode(leftMotor2, OUTPUT);
//   pinMode(rightMotor1, OUTPUT);
//   pinMode(rightMotor2, OUTPUT);
  
//   Serial.begin(9600);             // Begin serial communication
// }

// void loop() {
//   int leftValue = digitalRead(irSensorLeft);  // Read Left IR sensor
//   int rightValue = digitalRead(irSensorRight); // Read Right IR sensor

//   Serial.print("Left Sensor: ");
//   Serial.print(leftValue);
//   Serial.print(" | Right Sensor: ");
//   Serial.println(rightValue);

//   if (leftValue == 1 && rightValue == 1) {  
//     // Both sensors detect white → STOP
//     stopMotors();
//   } 
//   else if (leftValue == 1) {  
//     // Left sensor detects white, right detects black → Turn Left
//     turnLeft();
//   } 
//   else if (rightValue == 1) {  
//     // Right sensor detects white, left detects black → Turn Right
//     turnRight();
//   } 
//   else {  
//     // Both sensors detect black → Move Forward
//     moveForward();
//   }
// }

// // Function to move forward
// void moveForward() {
//   digitalWrite(leftMotor1, HIGH);
//   digitalWrite(leftMotor2, LOW);
//   digitalWrite(rightMotor1, HIGH);
//   digitalWrite(rightMotor2, LOW);
// }

// // Function to turn left
// void turnLeft() {
//   digitalWrite(leftMotor1, LOW);
//   digitalWrite(leftMotor2, HIGH);
//   digitalWrite(rightMotor1, HIGH);
//   digitalWrite(rightMotor2, LOW);
// }

// // Function to turn right
// void turnRight() {
//   digitalWrite(leftMotor1, HIGH);
//   digitalWrite(leftMotor2, LOW);
//   digitalWrite(rightMotor1, LOW);
//   digitalWrite(rightMotor2, HIGH);
// }

// // Function to stop motors
// void stopMotors() {
//   digitalWrite(leftMotor1, LOW);
//   digitalWrite(leftMotor2, LOW);
//   digitalWrite(rightMotor1, LOW);
//   digitalWrite(rightMotor2, LOW);
// }







































// // Define pin connections
// #define irSensorLeft  11   // Left IR sensor signal pin
// #define irSensorRight 10   // Right IR sensor signal pin

// #define leftMotor1 5       // Left motor control pin 1
// #define leftMotor2 6       // Left motor control pin 2
// #define rightMotor1 7      // Right motor control pin 1
// #define rightMotor2 8      // Right motor control pin 2

// void setup() {
//   pinMode(irSensorLeft, INPUT);    // Left IR sensor
//   pinMode(irSensorRight, INPUT);   // Right IR sensor

//   pinMode(leftMotor1, OUTPUT);    // Motor control pins
//   pinMode(leftMotor2, OUTPUT);
//   pinMode(rightMotor1, OUTPUT);
//   pinMode(rightMotor2, OUTPUT);
  
//   Serial.begin(9600);             // Begin serial communication
// }

// void loop() {
//   int leftValue = digitalRead(irSensorLeft);  // Read Left IR sensor
//   int rightValue = digitalRead(irSensorRight); // Read Right IR sensor

//   Serial.print("Left Sensor: ");
//   Serial.print(leftValue);
//   Serial.print(" | Right Sensor: ");
//   Serial.println(rightValue);

//   if (leftValue == 0 && rightValue == 0) {  
//     // Both sensors detect a line → STOP
//     stopMotors();
//   } 
//   else if (leftValue == 0) {  
//     // Left sensor detects line → Turn Right
//     turnRight();
//   } 
//   else if (rightValue == 0) {  
//     // Right sensor detects line → Turn Left
//     turnLeft();
//   } 
//   else {  
//     // No line detected → Move Forward
//     moveForward();
//   }
// }

// // Function to move forward
// void moveForward() {
//   digitalWrite(leftMotor1, HIGH);
//   digitalWrite(leftMotor2, LOW);
//   digitalWrite(rightMotor1, HIGH);
//   digitalWrite(rightMotor2, LOW);
// }

// // Function to turn left
// void turnLeft() {
//   digitalWrite(leftMotor1, LOW);
//   digitalWrite(leftMotor2, HIGH);
//   digitalWrite(rightMotor1, HIGH);
//   digitalWrite(rightMotor2, LOW);
// }

// // Function to turn right
// void turnRight() {
//   digitalWrite(leftMotor1, HIGH);
//   digitalWrite(leftMotor2, LOW);
//   digitalWrite(rightMotor1, LOW);
//   digitalWrite(rightMotor2, HIGH);
// }

// // Function to stop motors
// void stopMotors() {
//   digitalWrite(leftMotor1, LOW);
//   digitalWrite(leftMotor2, LOW);
//   digitalWrite(rightMotor1, LOW);
//   digitalWrite(rightMotor2, LOW);
// }





























// // // Define pin connections
// // #define irAnalogPin 11    // IR sensor analog pin
// // #define irDigitalPin 2    // IR sensor digital pin
// // #define leftMotor1 8      // Left motor control pin 1
// // #define leftMotor2 9      // Left motor control pin 2
// // #define rightMotor1 6     // Right motor control pin 1
// // #define rightMotor2 7    // Right motor control pin 2

// // void setup() {
// //   pinMode(irAnalogPin, INPUT);    // Analog pin for IR sensor
// //   pinMode(irDigitalPin, INPUT);   // Digital pin for IR sensor
// //   pinMode(leftMotor1, OUTPUT);    // Motor control pins
// //   pinMode(leftMotor2, OUTPUT);
// //   pinMode(rightMotor1, OUTPUT);
// //   pinMode(rightMotor2, OUTPUT);
// //   Serial.begin(9600);             // Begin serial communication
// // }

// // void loop() {
// //   int analogValue = analogRead(irAnalogPin);  // Read analog value
// //   int digitalValue = digitalRead(irDigitalPin);  // Read digital value

// //   Serial.print("Analog Value: ");
// //   Serial.print(analogValue);
// //   Serial.print("  |  Digital Value");
// //   Serial.println(digitalValue);

// //   if (analogValue < 500) {  // Line detected by digital pin
// //   // move left to adjust
// //     digitalWrite(leftMotor1, LOW);
// //     digitalWrite(leftMotor2, HIGH);
// //     digitalWrite(rightMotor1, LOW);
// //     digitalWrite(rightMotor2, LOW);
// //     delay(2000);
// //     // move right for 2 second
// //     digitalWrite(leftMotor1, LOW);
// //     digitalWrite(leftMotor2, LOW);
// //     digitalWrite(rightMotor1, HIGH);
// //     digitalWrite(rightMotor2, LOW);
// //     delay(2000);
    
// //   } else {
// //     // Move forward
// //     digitalWrite(leftMotor1, HIGH);
// //     digitalWrite(leftMotor2, LOW);
    
// //     digitalWrite(rightMotor1, LOW);
// //     digitalWrite(rightMotor2, HIGH);
// //   }

// //   delay(100);  // Delay for stability
// // }
