/*
Code by: www.munphurid.com
M.Hashir
Note: All hardware has been purchased from www.munphurid.com
www.munphurid.com, the unique E-store, is an Online Electronic Components Supplier. 
We deliver electronic components, tools, kits and boards at your home. 
We also deliver them at different Universities at a lower shipping rate/free. 
We have variety of boards, controllers, discrete components, ICs etc.
Unique Points:
1. Driver, datasheet and software for many products is available on our website (free of cost).
2. FREE PROJECT TUTORIALS with very easy and complete explanation + code is available (free of cost) on our website.



This is a code for a simple line following robot
It follows line (usually black on a white background)

Hardware:
- Arduino
- L298n module
- 3 wheeler light weight chassis
- 4 IR sensor


Connections:
Motor driver module and Arduino:
Connect IN1 of L298n module to any pin of Arduino from 0 to 13
Connect IN2 of L298n module to any pin of Arduino from 0 to 13
Connect IN3 of L298n module to any pin of Arduino from 0 to 13
Connect IN4 of L298n module to any pin of Arduino from 0 to 13
Connect ENA of L298n module to any pin of Arduino from 0 to 13
Connect ENB of L298n module to any pin of Arduino from 0 to 13
Connect 5V of L298n module to 5V of Arduino
Connect GND of L298n module to GND of Arduino

Battery and all circuits:
Connect +ve wire of battery to 12V of motor driver module
Connect -ve wire of battery to GND of motor driver module

Sensor and Arduino:
Connect 5V of all module to 5V of Arduino
Connect GND of all module to GND of Arduino
Connect OUT of all module from pins 0 to 13 or A0 to A5 of Arduino


*/


int motor1pin1 = 13;        //Connect to IN1 of L298n module
int motor1pin2 = 12;        //Connect to IN2 of L298n module
int motor2pin1 = 11;        //Connect to IN3 of L298n module
int motor2pin2 = 10;        //Connect to IN4 of L298n module
int motor1e = 9;            //Connect to ENA of L298n module
int motor2e = 3;            //Connect to ENB of L298n module

int leftsensor = 2;        //Connect OUT of left sensor to this pin of Arduino
int midleft = 6;           //Connect OUT of middle left sensor to this pin of Arduino
int midright = 4;          //Connect OUT of middle right sensor to this pin of Arduino
int rightsensor = 5;       //Connect OUT of right sensor to this pin of Arduino

int s1, s2, s3, s4;        //will be used later

void setup() {
  //Do not edit the bunch of lines below
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor1e, OUTPUT);
  pinMode(motor2e, OUTPUT);
  pinMode(leftsensor, INPUT);
  pinMode(midleft, INPUT);
  pinMode(midright, INPUT);
  pinMode(rightsensor, INPUT);

}

void loop() {
  
  inputs();

  if ((s1 == x) && (s4 == x)) {
    if ((s2 == y) && (s3 == y))
    {
      forward();
    }
    if ((s2 == x) && (s3 == y))
    {
      turnright();
    }

    if ((s2 == y) && (s3 == x))
    {
      turnright();
    }
  }


  if ((s1 == y) && (s2 == y)) {
    sharpleft();
    delay(100);
    while (s4 == x) {
      inputs();
    }
    stopm();
  }

  if ((s3 == y) && (s4 == y)) {
    sharpright();
    delay(100);
    while (s1 == x) {
      inputs();
    }
    stopm();
  }



}


void forward(void) {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(motor1e, 255);
  analogWrite(motor2e, 255);
}

void turnleft(void) {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(motor1e, 255);
  analogWrite(motor2e, 128);

}


void sharpleft(void) {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  analogWrite(motor1e, 255);
  analogWrite(motor2e, 255);
}


void sharpright(void) {
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(motor1e, 255);
  analogWrite(motor2e, 255);
}


void turnright(void) {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(motor1e, 128);
  analogWrite(motor2e, 255);

}


void stopm(void) {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}


void inputs(void) {
  s1 = digitalRead(leftsensor);
  s2 = digitalRead(midleft);
  s3 = digitalRead(midright);
  s4 = digitalRead(rightsensor);
}
