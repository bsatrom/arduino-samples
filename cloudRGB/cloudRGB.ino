#define BLED A3
#define GLED A2
#define RLED A1
const int BUTTON = 6;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;
char ledColor[6] = "none";

void setup() {
  Serial.begin(9600);

  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(BUTTON, INPUT);

  // Expose a cloud function for setting the color
  Spark.function("colorBlink", colorBlink);
  // Expose a cloud function for reading the color
  Spark.variable("color", ledColor, STRING);
}

int colorBlink(String args) {
  int mode = args.toInt();

  setMode(mode);
  Serial.println(mode);
  delay(2000);

  return 0;
}

boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);
  if (last != current) {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

void setMode(int mode) {
  // RED
  if (mode == 1) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
    strcpy(ledColor, "red");
  }

  // GREEN
  if (mode == 2) {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
    strcpy(ledColor, "green");
  }

  // BLUE
  if (mode == 3) {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
    strcpy(ledColor, "blue");
  }

  // PURPLE (RED+BLUE)
  if (mode == 4) {
    analogWrite(RLED, 127);
    analogWrite(GLED, 0);
    analogWrite(BLED, 127);
    strcpy(ledColor, "purple");
  }

  // TEAL (BLUE+GREEN)
  if (mode == 5) {
    analogWrite(RLED, 0);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
    strcpy(ledColor, "teal");
  }

  // ORANGE (GREEN+RED)
  if (mode == 6) {
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 0);
    strcpy(ledColor, "orange");
  }

  // WHITE (GREEN+RED+BLUE)
  if (mode == 7) {
    analogWrite(RLED, 85);
    analogWrite(GLED, 85);
    analogWrite(BLED, 85);
    strcpy(ledColor, "white");
  }

  if (mode == 0) {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
    strcpy(ledColor, "off");
  }

  Spark.publish("cp_button_pressed", "true", 21600);
}

void loop() {
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {
    ledMode++;
  }
  lastButton = currentButton;
  if (ledMode == 8) ledMode = 0;
  setMode(ledMode);
}
