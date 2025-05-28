#define HALL_SENSOR 2  // Hall effect sensor connected to D2
#define BUZZER 4      // Buzzer connected to D8

void setup() {
    pinMode(HALL_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int state = digitalRead(HALL_SENSOR);

    if (state == LOW) { // Magnet is NEAR
        Serial.println(" Magnet detected! Buzzer OFF");
        digitalWrite(BUZZER, LOW);
    } else { // Magnet is REMOVED
        Serial.println(" Magnet removed! Buzzer Beeping!");
        digitalWrite(BUZZER, HIGH);
        delay(1000);  // Beep for 1 second
        digitalWrite(BUZZER, LOW); // Turn off the buzzer
    }

    delay(500); // Delay to slow down readings
}
