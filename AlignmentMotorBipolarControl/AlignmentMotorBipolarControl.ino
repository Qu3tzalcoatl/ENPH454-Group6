void setup() {
  // put your setup code here, to run once:
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  int condition = 2;

  // put your main code here, to run repeatedly:

switch (condition) {
  case 1:
    turnCCW(60);
    delay(2000);
    condition = 0;
    turnCW(60);
    break;
  case 2:
    turnCW(60);
    delay(2000);
    condition = 0;
    turnCCW(60);
    break;

  case 0:
    break;

  default:
    break;
}
}

void loop() {
  


}

void turnCCW(float num_rotations) { // put input in degrees
  float step_size = 0.703; // step size in degrees 
  float rot_number = num_rotations; // number of rotations to execute
  int loop_count = floor(rot_number/step_size);

  for (int i = 0; i< loop_count; i++) {
  digitalWrite(34,HIGH);
  delay(5);
  digitalWrite(34,LOW);
  digitalWrite(32,HIGH);
  delay(5);
  digitalWrite(32,LOW);
  digitalWrite(30,HIGH);
  delay(5);
  digitalWrite(30,LOW);
  digitalWrite(28,HIGH);
  delay(5);
  digitalWrite(28,LOW);
  }
  


}


void turnCW(float num_rotations) { // put input in degrees
  float step_size = 0.703; // step size in degrees 
  float rot_number = num_rotations; // number of rotations to execute
  int loop_count = floor(rot_number/step_size);

  for (int i = 0; i< loop_count; i++) {
  digitalWrite(28,HIGH);
  delay(5);
  digitalWrite(28,LOW);
  digitalWrite(30,HIGH);
  delay(5);
  digitalWrite(30,LOW);
  digitalWrite(32,HIGH);
  delay(5);
  digitalWrite(32,LOW);
  digitalWrite(34,HIGH);
  delay(5);
  digitalWrite(34,LOW);
  }
  


}
