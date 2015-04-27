const int falante = 5;

int lowfreq = 600;
int hifreq = 2400;
volatile int freq = lowfreq;
int fstep = 65;

void setup() {
    pinMode(falante, OUTPUT);
}

void loop() {
    while (freq < hifreq) {
        cycle();
        freq += fstep;   
    }
    while (freq > lowfreq) {
        cycle();
        freq -= fstep;
    }
}

void cycle() {
    long microsecs = 1e6 * 1.0/freq;
    digitalWrite(falante, HIGH);
    delayMicroseconds(microsecs);
    digitalWrite(falante, LOW);
    delayMicroseconds(microsecs);    
}