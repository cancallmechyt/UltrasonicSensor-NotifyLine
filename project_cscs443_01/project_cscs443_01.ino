// Define pin numbers
const int trigPin = 2;
const int echoPin = 4;
const int buzzerPin = 13;
int ledPin1 = 14;
int ledPin2 = 12;

// Define variables
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

  // Measure duration of echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Output distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn on buzzer if distance is less than 30 cm
  if (distance < 30) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin1, HIGH); 
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin2, HIGH); 
  }

  // Wait for a moment before measuring again
  delay(100);
}