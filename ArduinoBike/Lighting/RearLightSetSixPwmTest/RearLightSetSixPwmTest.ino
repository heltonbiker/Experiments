# define left 2
# define right 4
# define brakeSensor A5

# define PWM_LOW 10
# define PWM_MAX 255

# define TURN_ON_MILLIS 300
# define TURN_OFF_MILLIS 300

bool tailOn = false;
int turnStatus = LOW;

int rear[] = {3,5,6,9,10,11};

///////////////////////


void setup() {
  
  for (int i = 0; i < 6; i++) {
    pinMode(rear[i], OUTPUT);
  }

  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);

  pinMode(brakeSensor, INPUT_PULLUP);

  turnAll();

  Serial.begin(9600);  
}




void loop(){
  if (brakeSensorOn()){
    setBrakePwm(PWM_MAX);
  }
  else{
    runTailLight();
  }

  //blinkRight();
}

void setBrakePwm(byte val) {
  for (int i = 0; i < 6; i++) {
    analogWrite(rear[i], val);
  }  
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
    setBrakePwm(PWM_LOW);
  }
  else{
    setBrakePwm(0);
  }
}

// void blinkLeft() {
//   static unsigned long previousLeftMillis = 0;
//   unsigned long currentMillis = millis();
//   unsigned long elapsedMillis = currentMillis - previousLeftMillis;

//   if((turnStatus == HIGH && elapsedMillis > TURN_ON_MILLIS) ||
//      (turnStatus == LOW  && elapsedMillis > TURN_OFF_MILLIS)) {

//     leftStatus = 1 - leftStatus;
//     digitalWrite(left, leftStatus);
    
//     previousLeftMillis = currentMillis;
//   }
// }


// void blinkRight() {
//   static int rightStatus = LOW;
//   static unsigned long previousRightMillis = 0;
//   unsigned long currentMillis = millis();
//   unsigned long elapsedMillis = currentMillis - previousRightMillis;

//   // Serial.println(elapsedMillis);


//   if((turnStatus == HIGH && elapsedMillis > TURN_ON_MILLIS) ||
//      (turnStatus == LOW  && elapsedMillis > TURN_OFF_MILLIS)) {

//     rightStatus = 1 - rightStatus;
//     digitalWrite(right, rightStatus);

//     previousRightMillis = currentMillis;
//   }
// }