

void setup()
{

  // Define pin connections & motor's steps per revolution
  const int dirPin = 22;
  const int stepPin = 24;
  const int stepsPerRevolution = 20000;
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  int condition = 0;

  switch (condition) {
  case 1:
    digitalWrite(dirPin, HIGH); // clockwise rotation
    break;
  case 2:
    break;
    digitalWrite(dirPin, LOW); // counterclockwise rotation
  case 0:
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
