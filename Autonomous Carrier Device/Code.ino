#include <AFMotor.h>

#include <Servo.h>; //this includes functions from the Servo.h library. 
Servo myServo; //defines the Servo motor as myServo
int pos = 0;

#include <HCSR04.h>   //this allows the code to include functions from the HCSR04.h library
HCSR04 hc(5, 6);  // defines the sensor as hc. (trigPin,echoPin)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);    //attaches servo to pin 9

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(hc.dist());    //prints the distance measured by the ultrasonic sensor
  delay(60);    //records data every 60 milliseconds


  if (hc.dist() < 5); {

    myServo.write(180);
    delay(500);
    /*for (pos = 0; pos <= 180; pos += 1) {
      myServo.write(pos);
      delay(15);
    }*/
  }
  if (pos == 180) {
    for (pos = 180; pos >= 0; pos -= 1) {
      myServo.write(pos);
      delay(15);
    }
  }

}
