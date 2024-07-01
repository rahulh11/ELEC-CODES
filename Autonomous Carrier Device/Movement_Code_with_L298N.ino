#include <L298N.h>
//Motor A connections
int enA=9;
int in1=8;
int in2=7; 

//Motor B connections
int enB=3;
int in3=5;
int in4=4;

int i=0; 
//initialise both motors
L298N motorA(enA, in1, in2);
L298N motorB(enB, in3, in4);



#include <HCSR04.h>
//Define trig pin and echo pin hc(trig pin, echo pin)
HCSR04 hc(11,10);

void setup() {
  // put your setup code here, to run once:

Serial. begin(9600);

motorA.setSpeed(80);
motorB.setSpeed(80); 

}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println(hc.dist()); 
delay(60); 



if (hc.dist() > hc.dist(50)) {
  for (int i=80; i<255; i++){
    motorA.setSpeed(i); 
    motorB.setSpeed(i);
    delay(10);
  }
}

if (hc.dist() < hc.dist(50)){
  for (int i=255; i=0; i--)
  motorA.setSpeed(i);
  motorB.setSpeed(i); 
  delay(10); 

if (hc.dist() < hc.dist(15)){
  motorA.stop(); 
  motorB.stop();
  delay(10); 
  }
}


}
