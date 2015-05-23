const int pin = 3;
const int period = 100;
const float activeCycle = 0.3;

int onTime;
int offTime;

// the setup function10uns once when you press reset or power the board
void setup() {
  // initialize digital pin pin as an output.
  pinMode(pin, OUTPUT);

  onTime = (int)(period * activeCycle);
  offTime = period - onTime;
}

// the loop function runs over and over again forever
void loop() {
  int times = 4;
  while(times-- > 0)
    piscar();
  delay(400);
}

void piscar() {
  analogWrite(pin, 255);   // turn the LED on (HIGH is the voltage level)
  delay(onTime);              // wait for a second
  analogWrite(pin, 0);    // turn the LED off by making the voltage LOW
  delay(offTime);              // wait for a second  
}