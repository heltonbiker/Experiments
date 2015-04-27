const int button = A5;
const int speaker = 9;

const int lower = 500;
const int higher = 1000;

unsigned long lastMicro = 0;

int index = 0;
int freqs[] = {lower, higher};

unsigned long durations[] = {2500, 2500};

void setup() { 
  pinMode(button, INPUT_PULLUP);
  pinMode(speaker, OUTPUT);
}

void loop() {
  if (digitalRead(button) == LOW) {
    playHorn();
  }
  else {
      noTone(speaker);
  }
}

void playHorn() {

  tone(speaker, freqs[index]);
  
  unsigned long current = micros();
  if (current - lastMicro > durations[index]) {
    ++index %= 2;
    lastMicro = current;
}

}


