void setup() {
  // put your setup code here, to run once:
  pinMode(30, OUTPUT); // this is the step pulse pin
  pinMode(22, OUTPUT); // using this as the direction pin
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(26, OUTPUT);
  
  digitalWrite(28,HIGH);
  digitalWrite(26,LOW);
  
  int condition = 2;

  // put your main code here, to run repeatedly:

switch (condition) {
  case 1:
    digitalWrite(22,LOW); // choose the direction using the DIR input
    turn(60);
    delay(2000);
    digitalWrite(22,HIGH);
    condition = 0;
    turn(60);
    break;
  case 2:
    digitalWrite(22,HIGH);
    turn(60);
    delay(2000);
    digitalWrite(22,LOW);
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
  digitalWrite(30,HIGH); //pulse the step input to generate movement
  delay(50);
  digitalWrite(30,LOW);
  delay(50);
  }
  


}
