#define PIR_PIN 2    // PIR sensor connected to pin 2
#define LED_PIN 3   // LED connected to pin 13

void setup() {
  pinMode(PIR_PIN, INPUT);  // Set PIR sensor pin as input
  pinMode(LED_PIN, OUTPUT); // Set LED pin as output
  Serial.begin(9600);       // Start Serial Monitor for debugging
}

void loop() {
  int motion = digitalRead(PIR_PIN); // Read PIR sensor state

  if (motion == HIGH) { 
    digitalWrite(LED_PIN, HIGH);  // Turn LED ON
    Serial.println("Motion detected! LED ON");
  } 
  else {
    digitalWrite(LED_PIN, LOW);   // Turn LED OFF
    Serial.println("No motion. LED OFF");
  }

  delay(500); // Small delay to avoid flickering
}
