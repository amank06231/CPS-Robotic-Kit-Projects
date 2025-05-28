// Define pins for ultrasonic and buzzer
int const trigPin = 10;  //using ULS1
int const echoPin = 12;
int const buzzPin = 4;  
void setup()
{
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
Serial.begin(9600);
}
void loop()
{
int duration, distance;// Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
digitalWrite(trigPin, HIGH);// Output pulse with 1ms width on trigPin
delay(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);// Measure the pulse input in echo pin
distance = (duration*0.034) / 2;// Distance is half the duration
Serial.print("Distance: ");
Serial.println(distance);
if (distance <= 50 && distance >= 0) // if distance less than 0.5 meter and more than 0 (0 or less means over range)
{
digitalWrite(buzzPin, LOW);// Buzz
}
else 
{
digitalWrite(buzzPin, HIGH);// Don't buzz
}

delay(60);// Waiting 60 ms won't hurt any one
}

























// // Define pins for ultrasonic sensor and buzzer
// const int trigPin = 10;  // Using ULS1
// const int echoPin = 12;
// const int buzzPin = 4;

// void setup() {
//     pinMode(trigPin, OUTPUT);  // Trig pin will send pulses
//     pinMode(echoPin, INPUT);   // Echo pin will receive reflected signal
//     pinMode(buzzPin, OUTPUT);  // Buzzer output
//     Serial.begin(9600);
// }

// void loop() {
//     long duration;
//     int distance;

//     // Send a 10µs pulse to trigger pin
//     digitalWrite(trigPin, LOW);
//     delayMicroseconds(2);
//     digitalWrite(trigPin, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(trigPin, LOW);

//     // Read the echo pin, return the duration (timeout: 30ms)
//     duration = pulseIn(echoPin, HIGH, 30000);

//     // If timeout occurred, print an error message and exit loop
//     if (duration == 0) {  
//         Serial.println("No Echo Received! Out of range.");
//         return;  
//     }

//     // Convert duration to distance in cm (speed of sound = 343 m/s)
//     distance = (duration * 0.0343) / 2;

//     // Print distance value
//     Serial.print("Distance: ");
//     Serial.print(distance);
//     Serial.println(" cm");


//      // Buzzer beeps only if distance is around 5 cm (between 4 and 6 cm)
//     if (distance >= 4 && distance <= 6) {
//         digitalWrite(buzzPin, HIGH);
//     } else {
//         digitalWrite(buzzPin, LOW);
//     }

//     delay(100); // Small delay before next reading
// }



//    // Buzzer logic: Turn ON if object is within 50 cm
//    if (distance > 0 && distance <= 50) {
//        digitalWrite(buzzPin, HIGH);
//    } else {
//        digitalWrite(buzzPin, LOW);
//    }
//
//    delay(100);  // Small delay before next reading
//}






























//// Define pins for ultrasonic and buzzer
//int const trigPin = 10;  //using ULS1
//int const echoPin = 12;
//int const buzzPin = 4;  
//void setup()
//{
//pinMode(trigPin, OUTPUT); // trig pin will have pulses output
//pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
//pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
//Serial.begin(9600);
//}
//void loop()
//{
//int duration, distance;// Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
//digitalWrite(trigPin, HIGH);// Output pulse with 1ms width on trigPin
//delay(1);
//digitalWrite(trigPin, LOW);
//duration = pulseIn(echoPin, HIGH);// Measure the pulse input in echo pin
//distance = (duration*0.034) / 2;// Distance is half the duration
//Serial.print("Distance: ");
//Serial.println(distance);
//if (distance <= 50 && distance >= 0) // if distance less than 0.5 meter and more than 0 (0 or less means over range)
//{
//digitalWrite(buzzPin, HIGH);// Buzz
//}
//else 
//{
//digitalWrite(buzzPin, LOW);// Don't buzz
//}
//
//delay(60);// Waiting 60 ms won't hurt any one
//}
