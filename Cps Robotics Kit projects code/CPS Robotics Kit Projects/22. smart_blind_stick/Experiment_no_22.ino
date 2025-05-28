// Defines pin numbers
const int trigPin = 10;
const int echoPin = 12;
const int buzzer = 4;  // You need a different pin for the buzzer if echoPin is also 12

// Defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);  // Set trigPin as Output
  pinMode(echoPin, INPUT);   // Set echoPin as Input
  pinMode(buzzer, OUTPUT);   // Set buzzer as Output

  Serial.begin(9600);  // Start Serial Monitor
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo signal (timeout 30ms to avoid hanging)
  duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.034 / 2;  // Calculate distance

  // Print distance on Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check distance and activate buzzer
  if (distance > 0 && distance <= 10) {  // Ignore invalid values
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(200);  // Reduced delay for faster detection
}
