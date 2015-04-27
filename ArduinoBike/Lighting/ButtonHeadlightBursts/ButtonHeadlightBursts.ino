const int headlight = 3;
const int button1 = 2;

unsigned long lastmillis = 0;
int period = 35;
int state = 0;


void setup()
{
    pinMode(headlight, OUTPUT);
    digitalWrite(headlight, LOW);

    pinMode(button1, INPUT_PULLUP); 
}

void loop()
{
    if (button1Pressed()) {
        burst();
    }
    else {
        analogWrite(headlight, 50);
    }
}

bool button1Pressed() {
    return digitalRead(button1) == LOW;
}

void burst() {
    unsigned long currentmillis = millis();
    if (currentmillis - lastmillis > period) {
        state = 1 - state;
        digitalWrite(headlight, state);
        lastmillis = currentmillis;
    }
}