const int tempPin = 2;

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  //float temperature = getTemp();
  int temp = digitalRead(tempPin);

  Serial.print("temp: ");
  Serial.println(temp);

  delay(1000);
}
