#define TRIG_PIN 10   // Updated Trig Pin to 10
#define ECHO_PIN 12   // Updated Echo Pin to 12
#define PUMP_PIN 5    // Updated Pump Control Pin to 5

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);  // Make sure pump is off initially
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the time it takes to receive the echo
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;

  // Print the distance for debugging purposes
  Serial.print("Distance: ");
  Serial.println(distance);

  // If hand is within 10 cm, activate the pump
  if (distance > 0 && distance < 10) {
    digitalWrite(PUMP_PIN, HIGH);
  } else {
    digitalWrite(PUMP_PIN, LOW);
  }

  // Small delay to prevent continuous triggering
  delay(100);
}
