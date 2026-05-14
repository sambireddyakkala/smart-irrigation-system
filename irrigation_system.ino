int sensorPin = A0;
int relay = 8;

void setup() {
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(sensorPin);

  Serial.println(moisture);

  if(moisture > 700) {
    digitalWrite(relay, HIGH);
  }
  else {
    digitalWrite(relay, LOW);
  }

  delay(1000);
}