int ledPin = 6;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  Spark.function("blink", blink);
}

void loop() {
  // Nothing to see here
}

int blink(String args) {
  int blinkCount = args.toInt();

  Serial.println(blinkCount);

  blinkLoop(blinkCount);

  return 0;
}

void blinkLoop(int blinkCount) {
  for(int i = 0; i < blinkCount; i++) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}
