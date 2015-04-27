const int speaker = 9;

const int lower = 1000;
const int higher = 3000;

const float stepsize = 50;

float frequency = lower;
int direct = 1;

void setup() { 
  pinMode(speaker, OUTPUT);
}

void loop () {

  frequency += direct * stepsize;
  
  if (frequency > higher)
    direct = -1;
  if (frequency < lower)
    direct = 1;

  tone(speaker, frequency);

  delay(1);
}



