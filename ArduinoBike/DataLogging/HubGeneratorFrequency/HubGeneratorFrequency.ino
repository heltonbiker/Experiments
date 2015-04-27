const int ledOut = 13;

volatile unsigned long time = 0;
volatile unsigned long lastTime = 0; 

void setup() {
	pinMode(ledOut, OUTPUT);
	pinMode(3, INPUT);

	//attachInterrupt(2, flashLed, RISING);

	digitalWrite(ledOut, LOW);

	Serial.begin(9600);
}

void loop() {
	Serial.println(pulseIn(3, HIGH));
}

// void flashLed() {
// 	Serial.println(pulseIn(pin, value, timeout););
// }