int ledPin = 3;

float rising;
float on;
float falling;
float off;

float proportions[] = {1,3,2,2};

const int cycleDuration = 1000; // milliseconds  


void setup() {
  pinMode(ledPin, OUTPUT);
  calculateTimes();
}

void loop() {
  rise();
  keepOn();
  fall();
  keepOff();
}

////////////////////////////////////////////////////

void calculateTimes() {
  float sum = 0;
  for (int i = 0; i < 4; i++) {
    sum += proportions[i];    
  }
  rising  = proportions[0] * cycleDuration / sum;
  on      = proportions[1] * cycleDuration / sum;
  falling = proportions[2] * cycleDuration / sum;
  off     = proportions[3] * cycleDuration / sum;
}

////////////////////////////////////////////////////

void rise() {
  for (int t = 0; t < rising; t++) {
    writeIntensity(t, rising);
  }
}

void keepOn() {
  digitalWrite(ledPin, HIGH);
  delay((int)on);
}

void fall() {
  for (int t = falling; t > 0; t--) {
    writeIntensity(t, falling);
  }
}

void keepOff() {
  digitalWrite(ledPin, LOW);
  delay((int)off);
}

void writeIntensity(float value, float reference) {
  long intensity = map(value, 0, reference, 0, 255);
  analogWrite(ledPin, intensity);
  delay(1);
}