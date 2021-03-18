

void setup()
{

  // Define pin connections & motor's steps per revolution
  const int dirPin = 22;
  const int stepPin = 24;
  const int stepsPerRevolution = 20000;

  const int dir_alignPin = 26;
  const int step_alignPin = 28;
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  int condition = 0;

  switch (condition) {
  case 1:
    digitalWrite(dir_alignPin, LOW); // clockwise rotation
    turn(step_alignPin, 60);
    turn(stepPin, 360);
    digitalWrite(dir_alignPin, HIGH); // counterclockwise rotation
    turn(step_alignPin, 60);
    break;
  case 2:
    break;
    digitalWrite(dirPin, LOW); // counterclockwise rotation
  case 0:
    break;

  default:
    break;

}

}

void turn(int pin, int angle) 
{
  int stepsPerRevolution = 20000;
  int  stepPin = pin;
  int iterations = floor(angle*stepsPerRevolution/360);

for(int x = 0; x < iterations; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
}
