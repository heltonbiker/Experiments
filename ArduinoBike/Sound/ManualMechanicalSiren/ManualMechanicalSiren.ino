const int button = A5;
const int speaker = 9;

const int lower = 100;
const int higher = 3000;

const float increment = 1;
const float decrement = 0.0005;

float frequency = lower;

void setup() { 
  pinMode(button, INPUT_PULLUP);
  pinMode(speaker, OUTPUT);
}

void loop() {
  if (digitalRead(button) == LOW and frequency < higher) {
    increaseFrequency();
  }
  else if (frequency > lower) {
    decreaseFrequency();
  }

  if (frequency > lower) {
    tone(speaker, frequency);
  }
  else {
    noTone(speaker);
  }

  delay(1);
}

void increaseFrequency() {
  frequency += 1;
}

void decreaseFrequency() {
  frequency = frequency * (1 - decrement);
}





