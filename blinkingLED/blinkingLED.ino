/*

  Blink
  
  Turns on LED for one second, then off for one second, repeatedly.

*/

void setup() {
  // Initialize the digital pin as an output. 
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH); // Set the LED on
  delay(1000);
  digitalWrite(13, LOW); // Set the LED off
  delay(1000);
}
