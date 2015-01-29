const int sensorPin = 0;
const int ledPin = 9;

int lightLevel, high = 1, low = 1023;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightLevel = analogRead(sensorPin);
  //Serial.println(lightLevel);
  //delay(500);
  
  //manualTune();
  
  autoTune();
 
  //analogWrite(ledPin, lightLevel); // regular light
  analogWrite(ledPin, 255 - lightLevel); // night light
}

void manualTune() {
  lightLevel = map(lightLevel, 0, 750, 0, 300);
  lightLevel = constrain(lightLevel, 0, 255);
}

void autoTune() {
  if (lightLevel < low) {
    low = lightLevel;
    Serial.println(low);
  }
  
  if (lightLevel > high) {
    high = lightLevel;
    Serial.println(high);
  }
  
  lightLevel = map(lightLevel, low+30, high-30, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}
