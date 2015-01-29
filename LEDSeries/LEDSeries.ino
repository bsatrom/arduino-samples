int ledPins[] = {2,3,4,5,6,7,8,9};

void setup() {
  int index;
  
  for(index = 0; index <= 7; index++) {
    pinMode(ledPins[index],OUTPUT);
  }
}

void loop() {
  // This loop() calls functions that we've written further below.
  // We've disabled some of these by commenting them out (putting
  // "//" in front of them). To try different LED displays, remove
  // the "//" in front of the ones you'd like to run, and add "//"
  // in front of those you don't to comment out (and disable) those
  // lines.

  //oneAfterAnotherNoLoop();  // Light up all the LEDs in turn
  
  //oneAfterAnotherLoop();  // Same as oneAfterAnotherNoLoop,
                            // but with much less typing
  
  //oneOnAtATime();         // Turn on one LED at a time,
                            // scrolling down the line
  
  //pingPong();             // Light the LEDs middle to the edges

  //marquee();              // Chase lights like you see on signs

  randomLED();            // Blink LEDs randomly
}

void oneAfterAnotherNoLoop() {
  int delayTime = 100;
  
  digitalWrite(ledPins[0], HIGH);  //Turns on LED #0 (pin 2)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[1], HIGH);  //Turns on LED #1 (pin 3)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[2], HIGH);  //Turns on LED #2 (pin 4)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[3], HIGH);  //Turns on LED #3 (pin 5)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[4], HIGH);  //Turns on LED #4 (pin 6)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[5], HIGH);  //Turns on LED #5 (pin 7)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[6], HIGH);  //Turns on LED #6 (pin 8)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[7], HIGH);  //Turns on LED #7 (pin 9)
  delay(delayTime);                //wait delayTime milliseconds  
 
  // turn all the LEDs off:
  
  digitalWrite(ledPins[7], LOW);   //Turn off LED #7 (pin 9)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[6], LOW);   //Turn off LED #6 (pin 8)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[5], LOW);   //Turn off LED #5 (pin 7)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[4], LOW);   //Turn off LED #4 (pin 6)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[3], LOW);   //Turn off LED #3 (pin 5)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[2], LOW);   //Turn off LED #2 (pin 4)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[1], LOW);   //Turn off LED #1 (pin 3)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[0], LOW);   //Turn off LED #0 (pin 2)
  delay(delayTime);                //wait delayTime milliseconds  
}

void oneAfterAnotherLoop() {
  int index;
  int delayTime = 100;
  
  for(index = 0; index <= 7; index++) {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);
  }
  
  for(index = 7; index >= 0; index--) {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);
  }
}

void oneOnAtATime() {
  int index;
  int delayTime = 100;
  
  for(index = 0; index <= 7; index++) {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[index], LOW);
  }
}

void pingPong() {
  int index;
  int delayTime = 100;
  
  for(index = 0; index <= 7; index++) {
    onOff(ledPins[index], delayTime);
  }
  
  for(index = 7; index >= 0; index--) {
    onOff(ledPins[index], delayTime);
  }
}

void onOff(int pin, int delayTime) {
  digitalWrite(pin, HIGH);
  delay(delayTime);
  digitalWrite(pin, LOW);
}

void marquee() {
  int index;
  int delayTime = 100;
  
  for(index = 0; index <= 3; index++) {
    digitalWrite(ledPins[index], HIGH);
    digitalWrite(ledPins[index+4], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[index], LOW);
    digitalWrite(ledPins[index+4], LOW);
  }
}

void randomLED() {
  int index;
  int delayTime;
  
  index = random(8);
  delayTime = 100;
  
  digitalWrite(ledPins[index], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[index], LOW);
}

