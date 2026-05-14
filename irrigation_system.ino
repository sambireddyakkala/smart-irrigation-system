// Smart Irrigation System using Arduino
// Components:
// Soil Moisture Sensor -> A0
// Relay Module -> Pin 8
// Buzzer -> Pin 7
// LED -> Pin 13

int sensorPin = A0;
int relayPin = 8;
int buzzerPin = 7;
int ledPin = 13;

int moistureValue = 0;
int threshold = 700;

void setup() {

  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  Serial.println("Smart Irrigation System Started");
}

void loop() {

  // Read soil moisture value
  moistureValue = analogRead(sensorPin);

  // Print value in Serial Monitor
  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  // Check soil condition
  if (moistureValue > threshold) {

    // Soil is dry
    digitalWrite(relayPin, HIGH);   // Pump ON
    digitalWrite(buzzerPin, HIGH);  // Buzzer ON
    digitalWrite(ledPin, HIGH);     // LED ON

    Serial.println("Soil Dry - Pump ON");

  } 
  else {

    // Soil is wet
    digitalWrite(relayPin, LOW);    // Pump OFF
    digitalWrite(buzzerPin, LOW);   // Buzzer OFF
    digitalWrite(ledPin, LOW);      // LED OFF

    Serial.println("Soil Wet - Pump OFF");
  }

  delay(1000);
}