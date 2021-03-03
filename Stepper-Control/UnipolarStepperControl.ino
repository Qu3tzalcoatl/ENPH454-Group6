void setup() {
  // put your setup code here, to run once:
  pinMode(28, OUTPUT); // this is the step pulse pin
  pinMode(30, OUTPUT); // using this as the direction pin
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  int condition = 2;

  // put your main code here, to run repeatedly:

switch (condition) {
  case 1:
    digitalWrite(30,LOW); // choose the direction using the DIR input
    turn(60);
    delay(2000);
    digitalWrite(30,HIGH);
    condition = 0;
    turn(60);
    break;
  case 2:
    digitalWrite(30,HIGH);
    turn(60);
    delay(2000);
    digitalWrite(30,LOW);
    condition = 0;
    turn(60);
    break;

  case 0:
    break;

  default:
    break;
}
}

void loop() {
  


}


void turn(float num_rotations) { // put input in degrees
  float step_size = 0.703; // step size in degrees 
  float rot_number = num_rotations; // number of rotations to execute
  int loop_count = floor(rot_number/step_size);

  for (int i = 0; i< loop_count; i++) {
  digitalWrite(28,HIGH); //pulse the step input to generate movement
  delay(5);
  digitalWrite(28,LOW);
  delay(5)
  }
  


}
