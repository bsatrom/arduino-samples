int datapin = 2;
int clockpin = 3;
int latchpin = 4;

byte data = 0;

void setup() {
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);  
}

void loop() {
  // We're going to use the same functions we played with back
  // in circuit 04, "Multiple LEDs", we've just replaced
  // digitalWrite() with a new function called shiftWrite()
  // (see below). We also have a new function that demonstrates
  // binary counting.

  // To try the different functions below, uncomment the one
  // you want to run, and comment out the remaining ones to
  // disable them from running.
  
  //oneAfterAnother();      // All on, all off
  
  //oneOnAtATime();       // Scroll down the line
  
  //pingPong();           // Like above, but back and forth

  //randomLED();          // Blink random LEDs
  
  //marquee();

  binaryCount();        // Bit patterns from 0 to 255
}

void shiftWrite(int desiredPin, boolean desiredState) {
  bitWrite(data, desiredPin, desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data);
  
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

void oneAfterAnother() {
  int index;
  int delayTime = 100;
  
  for(index = 0; index <= 7; index++) {
    shiftWrite(index, HIGH);
    delay(delayTime);
  }
  
  for(index = 7; index >= 0; index--)
  {
    shiftWrite(index, LOW);
    delay(delayTime);
  }
}

/*
oneOnAtATime()

This function will step through the LEDs, lighting one at at time.
*/

void oneOnAtATime()
{
  int index;
  int delayTime = 100; // Time (milliseconds) to pause between LEDs
                       // Make this smaller for faster switching
  
  // step through the LEDs, from 0 to 7
  
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);	// turn LED on
    delay(delayTime);		// pause to slow down the sequence
    shiftWrite(index, LOW);	// turn LED off
  }
}

 
/*
pingPong()

This function will step through the LEDs, lighting one at at time,
in both directions.
*/

void pingPong()
{
  int index;
  int delayTime = 100; // time (milliseconds) to pause between LEDs
                       // make this smaller for faster switching
  
  // step through the LEDs, from 0 to 7
  
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);	// turn LED on
    delay(delayTime);		// pause to slow down the sequence
    shiftWrite(index, LOW);	// turn LED off
  }

  // step through the LEDs, from 7 to 0
  
  for(index = 7; index >= 0; index--)
  {
    shiftWrite(index, HIGH);	// turn LED on
    delay(delayTime);		// pause to slow down the sequence
    shiftWrite(index, LOW);	// turn LED off
  }
}


/*
randomLED()

This function will turn on random LEDs. Can you modify it so it
also lights them for random times?
*/

void randomLED()
{
  int index;
  int delayTime = 100; // time (milliseconds) to pause between LEDs
                       // make this smaller for faster switching
  
  // The random() function will return a semi-random number each
  // time it is called. See http://arduino.cc/en/Reference/Random
  // for tips on how to make random() more random.
  
  index = random(8);	// pick a random number between 0 and 7
  
  shiftWrite(index, HIGH);	// turn LED on
  delay(delayTime);		// pause to slow down the sequence
  shiftWrite(index, LOW);	// turn LED off
}


/*
marquee()

This function will mimic "chase lights" like those around signs.
*/

void marquee()
{
  int index;
  int delayTime = 200; // Time (milliseconds) to pause between LEDs
                       // Make this smaller for faster switching
  
  // Step through the first four LEDs
  // (We'll light up one in the lower 4 and one in the upper 4)
  
  for(index = 0; index <= 3; index++)
  {
    shiftWrite(index, HIGH);    // Turn a LED on
    shiftWrite(index+4, HIGH);  // Skip four, and turn that LED on
    delay(delayTime);		// Pause to slow down the sequence
    shiftWrite(index, LOW);	// Turn both LEDs off
    shiftWrite(index+4, LOW);
  }
}

void binaryCount() {
  int delayTime = 1000;
  
  shiftOut(datapin, clockpin, MSBFIRST, data);
  
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
  
  data++;
  
  delay(delayTime);
}
