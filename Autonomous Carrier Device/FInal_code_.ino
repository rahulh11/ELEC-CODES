#include <AFMotor.h>
 
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


int i = 0;
 
#include <HCSR04.h>;
HCSR04 hc1(A3, A4);
 
void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600);
 
  //Set initial speed of the motor & stop
 
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0); 
  motor4.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
 
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
  //Print the distance detected by sensor every 60 ms.
 
  Serial.println(hc1.dist());
 
   
   //Turn on motors
 
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1000);
 
 
  //Accelerate from zero to maximum speed.
 
  for (i = 0; i < 250; i++) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);
    delay(1000);
  }
 
  //If distance detected by sensor1 is 10 cm, motors will turn off for 5 seconds.
 
  if (hc1.dist() < hc1.dist(10)) {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);q
    delay(3000);
 
  }
 

 
 
    }
 
