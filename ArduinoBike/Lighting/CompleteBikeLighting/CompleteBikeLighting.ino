const int headLow = 11;
const int headHigh = 10;

const int frontRightSign = 2;
int frontRightSignState = 0;

const int frontLeftSign = 4;
int frontLeftSignState = 0;

const int rearRightSign = 7;
int rearRightSignState = 0;


const int tailHigh = 5;
const int tailLow = 3;

const int headFlashSwitch = 2;
const int brakeSwitch = 7;


void setup() {
    pinMode(headLow, OUTPUT);
    pinMode(headHigh, OUTPUT);

    pinMode(frontRightSign, OUTPUT);
    pinMode(frontLeftSign, OUTPUT);

    pinMode(tailHigh, OUTPUT);
    pinMode(tailLow, OUTPUT);

    pinMode(headFlashSwitch, INPUT);
    pinMode(brakeSwitch, INPUT);


    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);

    //Serial.begin(9600);

    turnAllOn();
}

void turnAllOn() {
    analogWrite(headHigh, 5);

    digitalWrite(frontRightSign, LOW);
    digitalWrite(frontLeftSign, LOW);

    digitalWrite(rearRightSign, HIGH);
}

void loop() {
    // operateHeadHigh();
    // operateHeadLow();

    // operateLeftSign();
    // operateRightSign();

    // operateTailHigh();
    // operateTailLow();

    piscaDuas();
}

void piscaDuas() {
    frontRightSignState = !frontRightSignState;
    digitalWrite(frontRightSign, frontRightSignState);

    rearRightSignState = !rearRightSignState;
    digitalWrite(rearRightSign, rearRightSignState);

    delay(300);
}

void inverter(int pino) {
    int val = 1 - digitalRead(pino);
    digitalWrite(pino, val);
}

void operateHeadHigh() {
    //blinkHeadHigh();
}

void operateHeadLow() {
    if (digitalRead(headFlashSwitch)) {
        digitalWrite(headLow, HIGH);
    }
    else {
        analogWrite(headLow, 1);
    }
}


void operateLeftSign() {

}

void operateRightSign() {

}


void operateTailHigh() {
    if (digitalRead(brakeSwitch)) {
        digitalWrite(tailHigh, HIGH);
    }
    else {
        analogWrite(tailHigh, 20);  
    }
}

void operateTailLow() {
    //blinkTailLow();
}





void blinkHeadHigh() {
    static long elapsed;
    static long lastElapsed = 0;

    static const int intensity = 10;
    static int currentIntensity = 0;

    elapsed = millis();
    if (elapsed - lastElapsed > 70)
    {
        currentIntensity = intensity - currentIntensity;
        analogWrite(headHigh, currentIntensity);

        lastElapsed = elapsed;
    }    
}

void blinkTailLow() {
    static long elapsed;
    static long lastElapsed = 0;

    elapsed = millis();
    if (elapsed - lastElapsed > 100)
    {
        digitalWrite(tailLow, 1 - digitalRead(tailLow));
        lastElapsed = elapsed;
    }    
}