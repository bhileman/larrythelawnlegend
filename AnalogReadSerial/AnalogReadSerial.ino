int incomingData;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    //incomingData = Serial.read();
    Serial.println("hey!");
    delay(2000);
  }
}
