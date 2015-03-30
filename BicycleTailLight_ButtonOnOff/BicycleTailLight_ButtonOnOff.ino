/*

Flashing bike tail light.

Single LED used here as example (you could use more leds driven by transistor and external power source).

Using button debouncing.

Single-mode blinking, frequency and active cycle hard-coded;

You are free to use, modify and distribute.

*/

const int timeLedOn = 20;
const int timeLedOff = 7 * timeLedOn;


const int ledPin =  8;

int buttonLevel = LOW;
int previousButtonLevel = LOW;

int ledState = LOW;

bool blinkingTurnedOn = false;

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;

volatile unsigned long lastMicros;
long debouncingTime = 1000 * 200;


void setup() {
  // use interrupt 0 (pin 2) for 
  attachInterrupt(0, debounceInterrupt, RISING);

  pinMode(ledPin, OUTPUT);  

  // disable onboard led
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);    

  // turn led off
  digitalWrite(ledPin, LOW);
}



void loop() {
  currentMillis = millis();

  if (blinkingTurnedOn) {
    performBlinking();
  }
  else {
    digitalWrite(ledPin, LOW);
  }

}

void debounceInterrupt() {
  if ((long)(micros() - lastMicros) > debouncingTime) {
    toggleBlinking();
  }
  lastMicros = micros();

}

void toggleBlinking() {
    blinkingTurnedOn = !blinkingTurnedOn;  
}

void performBlinking() {
    int timeDelta = currentMillis - previousMillis;
    
    // check if time "off" elapsed
    bool elapsedOff = ledState == LOW && timeDelta > timeLedOff;

    // check if time "on" elapsed
    bool elapsedOn = ledState == HIGH && timeDelta > timeLedOn;
    
    // blinking itself
    if (elapsedOff || elapsedOn) {
      toggleLedState();
    }  
}

void toggleLedState() {  
  ledState = 1 - ledState;
  digitalWrite(ledPin, ledState);
  resetMillis();  
}

void resetMillis(){
  previousMillis = currentMillis; 
}
