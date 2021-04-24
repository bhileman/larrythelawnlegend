void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.print ("ready");
    String data = Serial.readStringUntil('Z');
    delay(5000);
  }
}
