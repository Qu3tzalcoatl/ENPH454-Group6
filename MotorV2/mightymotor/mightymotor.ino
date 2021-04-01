

void setup() {
  //Serial.begin(9600);


  // Define pin connections & motor's steps per revolution
  //const int stepsPerRevolution = 20000;
  
  const int dirPin = 22;
  const int stepPin = 24;
  
  const int dir_alignPin = 26;
  const int step_alignPin = 28;
  
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(dir_alignPin, OUTPUT);
  pinMode(step_alignPin, OUTPUT);

  // Declare pin that monitors for Jinho's signal
  const int pwmPin = 31;
  pinMode(pwmPin, INPUT);

}

const int dirPin = 22;
const int stepPin = 24;

const int dir_alignPin = 26;
const int step_alignPin = 28;
const int pwmPin = 31;
int condition = 0;
int pwmOutput = 0;

void loop(){
  
  pwmOutput = pulseIn(pwmPin, HIGH, 20000)/4;

  //cases
  if (pwmOutput < 12) {
    condition = 0;
  }
  else if (50 < pwmOutput < 100) {
    condition = 1;
  }
  else if (130 < pwmOutput < 180) {
    condition = 2;
  }
  else if (pwmOutput > 220) {
    condition = 3;
  }
  else {
    break;
  }
  
  switch (condition) {
  case 1:
    digitalWrite(dir_alignPin, HIGH); // clockwise rotation
    //digitalWrite(step_alignPin, LOW);
    for(int x = 0; x < 3500; x++)
      {
       digitalWrite(step_alignPin, HIGH);
       delayMicroseconds(700);
       digitalWrite(step_alignPin, LOW);
       delayMicroseconds(700);
       }
    //digitalWrite(dir_alignPin, LOW); // counterclockwise rotation

    
    digitalWrite(dirPin, HIGH); //conveyor direction
    //digitalWrite(stepPin, LOW);
    for(int x = 0; x < 20000; x++)
      {
       digitalWrite(stepPin, HIGH);
       delayMicroseconds(400);
       digitalWrite(stepPin, LOW);
       delayMicroseconds(400);
       }
    //digitalWrite(dirPin, LOW); //conveyor direction

    
    digitalWrite(dir_alignPin, LOW); // counterclockwise rotation
    //digitalWrite(step_alignPin, LOW);
    for(int x = 0; x < 3500; x++)
      {
       digitalWrite(step_alignPin, HIGH);
       delayMicroseconds(700);
       digitalWrite(step_alignPin, LOW);
       delayMicroseconds(700);
       }

    condition = 0;
    
    break;
   case 2:
   
    digitalWrite(dir_alignPin, LOW); // clockwise rotation
    for(int x = 0; x < 3333; x++)
      {
       digitalWrite(step_alignPin, HIGH);
       delayMicroseconds(400);
       digitalWrite(step_alignPin, LOW);
       delayMicroseconds(400);
       }
    
    
    digitalWrite(dirPin, HIGH); //conveyor direction
    for(int x = 0; x < 20000; x++)
      {
       digitalWrite(stepPin, HIGH);
       delayMicroseconds(400);
       digitalWrite(stepPin, LOW);
       delayMicroseconds(400);
       }


    
    digitalWrite(dir_alignPin, HIGH); // counterclockwise rotation
    for(int x = 0; x < 3333; x++)
      {
       digitalWrite(step_alignPin, HIGH);
       delayMicroseconds(400);
       digitalWrite(step_alignPin, LOW);
       delayMicroseconds(400);
       }

    condition = 0;
    
    break;
    
  case 3:
    digitalWrite(dirPin, LOW); //conveyor direction
   
    for(int x = 0; x < 20000; x++) // 40 seconds for a full rotation at 1ms delay
      {
       digitalWrite(stepPin, HIGH);
       delayMicroseconds(400);
       digitalWrite(stepPin, LOW);
       delayMicroseconds(400);
       }

    condition = 0;
    
    break;

  default:
    break;

}

}
