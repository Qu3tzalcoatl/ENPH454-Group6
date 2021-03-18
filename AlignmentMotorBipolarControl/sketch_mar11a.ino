

void setup()
{

  // Define pin connections & motor's steps per revolution
  const int dirPin = 22;
  const int stepPin = 24;
  int stepsPerRevolution;
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  int condition = 2;

  switch (condition) {
  case 1:
    digitalWrite(dirPin, HIGH); // clockwise rotation
    stepsPerRevolution = 20000;
    break;
  case 2:
    digitalWrite(dirPin, LOW); // counterclockwise rotation
    stepsPerRevolution = 20000;
    break;
  case 0:
    stepsPerRevolution = 0;
    break;

  default:
    break;

}

for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
}
//void loop()
//{

  // Spin motor slowly
  //for(int x = 0; x < stepsPerRevolution; x++)
  //{
  //  digitalWrite(stepPin, HIGH);
  //  delayMicroseconds(2000);
  //  digitalWrite(stepPin, LOW);
  //  delayMicroseconds(2000);
  //}
  //delay(1000); // Wait a second

  // Spin motor quickly
  //delayMicroseconds(1000); // Wait a second
//}
