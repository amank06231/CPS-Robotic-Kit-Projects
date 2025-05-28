const int buzzer = 4;
const int rainSensor = A5;
const int led = 6; // LED indicator

void setup() {
  Serial.begin(9600); // Enable serial monitor
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int level = analogRead(rainSensor); // Read rain sensor value
  Serial.print("Rain Sensor Level: ");
  Serial.println(level);

  if (level < 400) {  // **Heavy Rain**
    digitalWrite(led, HIGH);
    Serial.println("Heavy Rain! Buzzer Fast Beeping");

    for (int i = 0; i < 5; i++) { // Rapid beep 5 times
      tone(buzzer, 1000);
      delay(300);
      noTone(buzzer);
      delay(200);
    }
  } 
  else if (level < 600) {  // **Light Rain**
    digitalWrite(led, HIGH);
    Serial.println("Light Rain! Buzzer Slow Beeping");

    tone(buzzer, 1000);
    delay(500); 
    noTone(buzzer);
    delay(1000);
  } 
  else {  // **No Rain**
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("No Rain");
  }

  delay(1000); // Wait before next reading
}
