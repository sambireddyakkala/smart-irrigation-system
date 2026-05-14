int sensorPin = A0;
int relay = 8;

void setup() {
  pinMode(relay, OUTPUT);
}

void loop() {
  int moisture = analogRead(sensorPin);

  if(moisture > 700) {
    digitalWrite(relay, HIGH);
  }
  else {
    digitalWrite(relay, LOW);
  }
}