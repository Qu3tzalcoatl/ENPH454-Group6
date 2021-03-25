

void setup() {
  Serial.begin(9600);


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

}

const int dirPin = 22;
const int stepPin = 24;
  
const int dir_alignPin = 26;
const int step_alignPin = 28;


int condition = 0;
char rx_byte = 0;


void loop(){
  if (Serial.available() > 0) { // is a character available?
    rx_byte = Serial.read();       // get the character

    // check if a number was received
    if ((rx_byte >= '0') && (rx_byte <= '9')) {
      Serial.print("Number received: ");
      Serial.println(rx_byte);
      int condition = (int)rx_byte - 48;
    }
    else {
      Serial.println("Not a number.");
    }
  } // end: if (Serial.available() > 0)


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
    break;

  default:
    break;

}

}
