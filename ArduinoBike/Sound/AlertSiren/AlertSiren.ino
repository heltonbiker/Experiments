const int falante = 5;

int lowfreq = 600;
int hifreq = 2400;
volatile int freq = lowfreq;
int fstep = 65;

void setup() {
    pinMode(falante, OUTPUT);
}

void loop() {
    freq = 1000;
    int t1 = 10;
    while (t1-- > 0)
        cycle();
    freq = 2500;
    int t2 = 10;
    while (t2-- > 0)
        cycle();
}

void cycle() {
    long microsecs = 1e6 * 1.0/freq;
    digitalWrite(falante, HIGH);
    delayMicroseconds(microsecs);
    digitalWrite(falante, LOW);
    delayMicroseconds(microsecs);    
}