int ldrPin = A3;  // Use an Analog pin
int led = A2;
int threshold = 500;  // Adjust threshold value as needed

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue > threshold) {
    digitalWrite(led, HIGH);  // Turn ON LED in dark
  } else {
    digitalWrite(led, LOW);   // Turn OFF LED in light
  }

  delay(500);
}
