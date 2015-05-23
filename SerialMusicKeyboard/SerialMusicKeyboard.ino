#include <notes.h>

#define BACK_SLASH 92
#define A 97
#define Z 122
#define S 115
#define X 120
#define C 99
#define F 102
#define V 118
#define G 103
#define B 98
#define H 104
#define N 110
#define M 109

#define speaker 8

int inByte = 0;

void setup() {
  Serial.begin(9600);
  establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  if (Serial.available() > 0) {

    inByte = Serial.read();

    switch (inByte) {
        case 0:            noTone(speaker);           break;
        case BACK_SLASH:   tone(speaker, NOTE_C4);    break;
        case A:            tone(speaker, NOTE_CS4);   break;
        case Z:            tone(speaker, NOTE_D4);    break;
        case S:            tone(speaker, NOTE_DS4);   break;
        case X:            tone(speaker, NOTE_E4);    break;
        case C:            tone(speaker, NOTE_F4);    break;
        case F:            tone(speaker, NOTE_FS4);   break;
        case V:            tone(speaker, NOTE_G4);    break;
        case G:            tone(speaker, NOTE_GS4);   break;
        case B:            tone(speaker, NOTE_A4);    break;
        case H:            tone(speaker, NOTE_AS4);   break;
        case N:            tone(speaker, NOTE_B4);    break;
        case M:            tone(speaker, NOTE_C5);    break;
    }

    //Serial.print(inByte);
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("Awaiting input...");
    delay(1000);
  }
}


