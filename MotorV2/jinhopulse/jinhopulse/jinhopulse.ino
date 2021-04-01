void setup() {
  // put your setup code here, to run once:
  #define pulsePin 13
  #define readPin 22
  #define blueLED 2
  #define greenLED 3
  #define redLED 4
  
  pinMode(readPin,INPUT);
  pinMode(pulsePin,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);

  delay(8000);
  Serial.begin(74880);
  analogWrite(pulsePin, 240);
  int pwmin = pulseIn(readPin, HIGH, 20000)/4;
  Serial.println(pwmin);
  delay(2000);
}

int pwmin = 0;
int calibrate = 4;

void loop() {
  
  analogWrite(pulsePin, 0);
  pwmin = pulseIn(readPin, HIGH, 20000)/4;
  Serial.println(pwmin);
  Serial.print('\t');
  
  if (pwmin < 12) {
    analogWrite(blueLED, 0);
    analogWrite(greenLED, 0);
    analogWrite(redLED, 0);
  }
  else if (50 < pwmin < 100) {
    analogWrite(redLED, 255);;
  }
  else if (130 < pwmin < 180) {
    analogWrite(greenLED, 255);;
  }
  else if (pwmin > 220) {
    analogWrite(blueLED, 255);;
  }
  delay(2000);
  
  analogWrite(pulsePin, 0);
  pwmin = pulseIn(readPin, HIGH, 20000)/4;
  Serial.println(pwmin);
  Serial.print('\t');
  
  if (pwmin < 12) {
    analogWrite(blueLED, 0);
    analogWrite(greenLED, 0);
    analogWrite(redLED, 0);
  }
  else if (50 < pwmin < 100) {
    analogWrite(redLED, 255);;
  }
  else if (130 < pwmin < 180) {
    analogWrite(greenLED, 255);;
  }
  else if (pwmin > 220) {
    analogWrite(blueLED, 255);;
  }
  delay(2000);
  
  //Serial.print(42);
  
  //analogWrite(pulsePin, 0);
  //pwmin = pulseIn(readPin, HIGH, 20000);
  
  //Serial.print(constant);

}
