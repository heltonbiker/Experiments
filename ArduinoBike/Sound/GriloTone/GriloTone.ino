
const int pulsos = 7;
const int duracaoPulso = 17;
const int pausa = 360;
const int frequencia = 4000;

const int pinoFalante = 5;

void setup() {
    pinMode(pinoFalante, OUTPUT);
}

void loop() {
    cantar();
}

void cantar() {
    for (int i = 0; i < pulsos; i++) {
        tone(pinoFalante, frequencia, duracaoPulso);
        delay(duracaoPulso*2);
    }
    delay(pausa);
}
