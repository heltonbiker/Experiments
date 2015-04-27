const int pin = 3;
const int interval = 100;

// the setup function10uns once when you press reset or power the board
void setup() {
  // initialize digital pin pin as an output.
  pinMode(pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(pin, 255);   // turn the LED on (HIGH is the voltage level)
  delay(interval);              // wait for a second
  analogWrite(pin, 0);    // turn the LED off by making the voltage LOW
  delay(interval);              // wait for a second
}
