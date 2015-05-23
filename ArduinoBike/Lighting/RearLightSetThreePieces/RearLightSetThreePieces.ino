# define left 2
# define brake 3
# define right 4
# define brakeSensor A5

# define PWM_LOW 10
# define PWM_MAX 255

# define TURN_ON_MILLIS 300
# define TURN_OFF_MILLIS 300

bool tailOn = false;
int turnStatus = LOW;


///////////////////////


void setup() {
  pinMode(brake, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);

  pinMode(brakeSensor, INPUT_PULLUP);

  turnAll();

  Serial.begin(9600);  
}




void loop(){
  if (brakeSensorOn()){
    analogWrite(brake, PWM_MAX);
  }
  else{
    runTailLight();
  }

  blinkRight();
}


////////////////////////


void turnAll() {
  turnTailLightOn();
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
}

void turnTailLightOn(){
  tailOn = true;
}

void turnTailLightOff(){
  tailOn = false;
}

bool brakeSensorOn() {
  return digitalRead(brakeSensor) == LOW;
}

void runTailLight(){
  if (tailOn){
    analogWrite(brake, PWM_LOW);  
  }
  else{
    analogWrite(brake, 0);
  }
}

void blinkLeft() {
  static unsigned long previousLeftMillis = 0;
  unsigned long currentMillis = millis();
  unsigned long elapsedMillis = currentMillis - previousLeftMillis;

  if((turnStatus == HIGH && elapsedMillis > TURN_ON_MILLIS) ||
     (turnStatus == LOW  && elapsedMillis > TURN_OFF_MILLIS)) {

    leftStatus = 1 - leftStatus;
    digitalWrite(left, leftStatus);
    
    previousLeftMillis = currentMillis;
  }
}


void blinkRight() {
  static int rightStatus = LOW;
  static unsigned long previousRightMillis = 0;
  unsigned long currentMillis = millis();
  unsigned long elapsedMillis = currentMillis - previousRightMillis;

  // Serial.println(elapsedMillis);


  if((turnStatus == HIGH && elapsedMillis > TURN_ON_MILLIS) ||
     (turnStatus == LOW  && elapsedMillis > TURN_OFF_MILLIS)) {

    rightStatus = 1 - rightStatus;
    digitalWrite(right, rightStatus);

    previousRightMillis = currentMillis;
  }
}