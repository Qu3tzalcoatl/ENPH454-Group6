const int dirPin = 22;
const int stepPin = 24;
const int dir_alignPin = 26;
const int step_alignPin = 28;
const int case1 = 31;
const int case2 = 33;
const int case3 = 35;
const int driver1 = 41;
const int driver2 = 43;
int condition = 0;

void setup() {
  
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(dir_alignPin, OUTPUT);
  pinMode(step_alignPin, OUTPUT);

  // Declare pin that monitors for Jinho's signal
  pinMode(case1, INPUT);
  pinMode(case2, INPUT);
  pinMode(case3, INPUT);

  digitalWrite(stepPin, LOW);
  digitalWrite(dirPin, LOW);
  digitalWrite(dir_alignPin, LOW);
  digitalWrite(step_alignPin, LOW);

  pinMode(driver1, OUTPUT);
  pinMode(driver2, OUTPUT);


  Serial.begin(74880);
  delay(2000);

}



void loop() {
  
  //Serial.println(digitalRead(case1));
  //cases
  if (digitalRead(case1)==HIGH) {
    Serial.print("case1");
    Serial.print('\n');
    condition = 1;
  }
  else if (digitalRead(case2)==HIGH) {
    condition = 2;
    Serial.print("case2");
    Serial.print('\n');
  }
  else if (digitalRead(case3)==HIGH) {
    condition = 3;
    Serial.print("case3");
    Serial.print('\n');
  }
  else {
    Serial.print("Default");
    Serial.print('\n');
    condition=0;
  }
  
  switch (condition) {
  case 1:
    digitalWrite(driver1, HIGH);
    digitalWrite(dir_alignPin, HIGH); // clockwise rotation
    //digitalWrite(step_alignPin, LOW);
    for(int x = 0; x < 3500; x++)
      {
       digitalWrite(step_alignPin, HIGH);
       delayMicroseconds(700);
       digitalWrite(step_alignPin, LOW);
       delayMicroseconds(700);
       }
    digitalWrite(dir_alignPin, LOW); // counterclockwise rotation
    digitalWrite(driver1, LOW);

    digitalWrite(driver2, HIGH);
    digitalWrite(dirPin, LOW); //conveyor direction
    //digitalWrite(stepPin, LOW);
    for(int x = 0; x < 20000; x++)
      {
       digitalWrite(stepPin, HIGH);
       delayMicroseconds(400);
       digitalWrite(stepPin, LOW);
       delayMicroseconds(400);
       }
    digitalWrite(dirPin, LOW); //conveyor direction
    digitalWrite(driver2, LOW);

    digitalWrite(driver1, HIGH);
    digitalWrite(dir_alignPin, LOW); // counterclockwise rotation
    //digitalWrite(step_alignPin, LOW);
    for(int x = 0; x < 3500; x++)
      {
       digitalWrite(step_alignPin, HIGH);
       delayMicroseconds(700);
       digitalWrite(step_alignPin, LOW);
       delayMicroseconds(700);
       }
    digitalWrite(driver1, LOW);
    condition = 0;
    
    break;
   case 2:
    digitalWrite(driver1, HIGH);
    digitalWrite(dir_alignPin, LOW); // clockwise rotation
    for(int x = 0; x < 3333; x++)
      {
       digitalWrite(step_alignPin, HIGH);
       delayMicroseconds(1000);
       digitalWrite(step_alignPin, LOW);
       delayMicroseconds(1000);
       }
    digitalWrite(driver1, LOW);

    digitalWrite(driver2, HIGH);
    digitalWrite(dirPin, LOW); //conveyor direction
    for(int x = 0; x < 20000; x++)
      {
       digitalWrite(stepPin, HIGH);
       delayMicroseconds(400);
       digitalWrite(stepPin, LOW);
       delayMicroseconds(400);
       }
    digitalWrite(dirPin, LOW);
    digitalWrite(driver2, LOW);
    
    digitalWrite(driver1, HIGH);
    digitalWrite(dir_alignPin, HIGH); // counterclockwise rotation
    for(int x = 0; x < 3333; x++)
      {
       digitalWrite(step_alignPin, HIGH);
       delayMicroseconds(1000);
       digitalWrite(step_alignPin, LOW);
       delayMicroseconds(1000);
       }
    digitalWrite(dir_alignPin, LOW);
    digitalWrite(driver1, LOW);
    
    condition = 0;
    
    break;
    
  case 3:
    digitalWrite(driver2, HIGH);
    digitalWrite(dirPin, HIGH); //conveyor direction
    for(int x = 0; x < 20000; x++) // 40 seconds for a full rotation at 1ms delay
      {
       digitalWrite(stepPin, HIGH);
       delayMicroseconds(400);
       digitalWrite(stepPin, LOW);
       delayMicroseconds(400);
       }
    digitalWrite(driver2, LOW);
    condition = 0;
    
    break;

  default:
    delay(2000);
    break;
  }
}
