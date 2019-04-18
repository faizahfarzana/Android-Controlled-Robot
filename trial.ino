const int motorA1  =   5;  
const int motorA2  =   6;  
const int motorB1  =   10; 
const int motorB2  =   11;

const int BTState   =   2;  

int state;
  
void setup() {
  pinMode(BTState,  INPUT);
  
  pinMode(motorA1, OUTPUT);   
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);   
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if  (digitalRead(BTState) == LOW) state = 'S';
  if  (Serial.available() > 0)      state = Serial.read();

  if      (state == 'F')  forward();
  else if (state == 'B')  backward();
  else if (state == 'L')  left();
  else if (state == 'R')  right();
  else if (state == 'S')  stop_bot();
//  else if (state == 'G')  forwardleft();
//  else if (state == 'I')  forwardRight();
//  else if (state == 'H')  backwardLeft();
//  else if (state == 'J')  backwardRight();
//  else if (state == 'S')  stop_bot();
}

void forward(){
  analogWrite(motorA1, 80);   analogWrite(motorA2,   0); 
  analogWrite(motorB1, 80);   analogWrite(motorB2,   0); 
  
  Serial.println("Forward");
}

void backward(){
  analogWrite(motorA1,   0);   analogWrite(motorA2, 80);
  analogWrite(motorB1,   0);   analogWrite(motorB2, 80); 

  Serial.println("Backward");
}

void left(){
  analogWrite(motorA1, 80);   analogWrite(motorA2,   0); 
  analogWrite(motorB1,   0);   analogWrite(motorB2,   0); 

  Serial.println("Left");
}

void right(){
  analogWrite(motorA1,   0);   analogWrite(motorA2,   0); 
  analogWrite(motorB1, 80);   analogWrite(motorB2,   0); 

  Serial.println("Right");
}

void forwardleft(){
  analogWrite(motorA1, 100);   analogWrite(motorA2,   0);  
  analogWrite(motorB1, 200);   analogWrite(motorB2,   0); 
}

void forwardRight(){
  analogWrite(motorA1, 200);   analogWrite(motorA2,   0); 
 analogWrite(motorB1, 100);   analogWrite(motorB2,   0);
}

void backwardLeft(){
  analogWrite(motorA1,  0);    analogWrite(motorA2, 100); 
  analogWrite(motorB1,  0);    analogWrite(motorB2, 200); 
}

void backwardRight(){
  analogWrite(motorA1,  0);    analogWrite(motorA2, 200); 
  analogWrite(motorB1,  0);    analogWrite(motorB2, 100); 
}

void stop_bot(){
  analogWrite(motorA1,   0);   analogWrite(motorA2,   0); 
  analogWrite(motorB1,   0);   analogWrite(motorB2,   0);
}
