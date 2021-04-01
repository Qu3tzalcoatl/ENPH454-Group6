void setup() {
  // put your setup code here, to run once:
  #define pulsePin 3
  #define readPin 31
  pinMode(readPin,INPUT);
  pinMode(pulsePin,OUTPUT);
  Serial.begin(74880);
}

int pwmin = 0;

void loop() {
  analogWrite(pulsePin, 0);
  pwmin = pulseIn(readPin, HIGH, 20000);
  Serial.println(pwmin);
  Serial.print('\t');
  //delay(2000);
  
  analogWrite(pulsePin, 2);
  pwmin = pulseIn(readPin, HIGH, 20000);
  Serial.println(pwmin);
  Serial.print('\t');
  //delay(2000);
  
  //Serial.print(42);
  
  //analogWrite(pulsePin, 0);
  //pwmin = pulseIn(readPin, HIGH, 20000);
  
  //Serial.print(constant);

}
