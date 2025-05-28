#define BUZZER 4
const int SENSOR_PIN = A0;

void setup() {
    Serial.begin(9600);
    pinMode(SENSOR_PIN, INPUT);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
    int sensor_data = analogRead(SENSOR_PIN);  // Read analog sensor value
    Serial.print("Sensor Data: ");
    Serial.println(sensor_data);

    if (sensor_data >= 600) {
        Serial.println("Buzzer ON");
        digitalWrite(BUZZER, HIGH);
        delay(1000);  // Buzzer stays ON for 1 second
    } else {
        Serial.println("Buzzer OFF");
        digitalWrite(BUZZER, LOW);
    }

    delay(500); // Short delay before next reading
}




