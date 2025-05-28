#define Pump_pin 5

void setup() {
  pinMode(Pump_pin, OUTPUT);
  Serial.begin(9600);

  Serial.println("Plant Watering System ON");
  delay(2000);
}

void loop() {
  int value = analogRead(A5);
  Serial.print("Moisture Level: ");
  Serial.println(value);

  if (value < 500) {
    Serial.println("Good moisture, Pump OFF");
    digitalWrite(Pump_pin, LOW);
  } 
  else if (value >= 500 && value < 600) {
    Serial.println("Low moisture! Pump OFF");
    digitalWrite(Pump_pin, LOW);
  } 
  else {
    Serial.println("Soil Dry! Starting Pump...");
    digitalWrite(Pump_pin, HIGH);
    
    delay(5000); // Pump runs for 5 sec

    while (analogRead(A5) > 600) {
      Serial.println("Watering...");
      delay(2000);
    }

    Serial.println("Stopping Pump.");
    digitalWrite(Pump_pin, LOW);
  }

  delay(1000);
}
