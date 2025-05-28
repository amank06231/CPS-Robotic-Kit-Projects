#include <Servo.h>

#define RAIN_SENSOR_PIN 11  // Digital pin for rain sensor
#define SERVO_PIN 4      // Servo motor pin

Servo myServo;
bool isClosed = false; // Track the state of the stick

void setup() {
    pinMode(RAIN_SENSOR_PIN, INPUT);
    myServo.attach(SERVO_PIN);
    myServo.write(0); // Start position (open)
    Serial.begin(9600);
}

void loop() {
    int rainDetected = digitalRead(RAIN_SENSOR_PIN);
    
    if (rainDetected == LOW && !isClosed) { // If rain is detected
        Serial.println("Rain detected! Closing stick.");
        myServo.write(90); // Move servo to close stick
        isClosed = true;
    } 
    else if (rainDetected == HIGH && isClosed) { // If no rain
        Serial.println("No rain! Opening stick.");
        myServo.write(0); // Move servo back
        isClosed = false;
    }
    
    delay(5000); // Check every second
}
