// =======================================================
// DESN 1000 - Computing Technical Stream
// Motor Controller
// Written by Rahul Hosakere Ravishankara in Collaboration with Thai An Dang March 31/03/22
// Controls motors via an H Bridge 
// ======================================================= 

//--------------------------------------------------------
//Include Library
//--------------------------------------------------------
#include <L298NX2.h>

//--------------------------------------------------------
// Global Variables
// -------------------------------------------------------
int rightMotorLogicPin1 = 3;    
int rightMotorLogicPin2 = 4;  
int rightMotorEnable = 5;  
int leftMotorLogicPin1 = 6;    
int leftMotorLogicPin2 = 7; 
int leftMotorEnable = 8;  

L298N rightMotor(rightMotorEnable, rightMotorLogicPin1, rightMotorLogicPin2);
L298N leftMotor(leftMotorEnable, leftMotorLogicPin1, leftMotorLogicPin2);

//--------------------------------------------------------
//Function: Recieve Byte
//--------------------------------------------------------
char recieveCommand(){
char incomingByte = 0;
char command= incomingByte;

  // See if there's incoming serial data:
  if (Serial.available() > 0) {

    // Read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    command=incomingByte;

    return command;
  }
}
//--------------------------------------------------------
//Function" Update Direction
//--------------------------------------------------------
char updateDirection(char command, char currentDirection){
 // Is this a direction; 'f' 'b' 'l' 'r'
    if (command == 'f') {
      Serial.println("Forwards");
      currentDirection = 'f';
    }
    if (command == 'b') {
      Serial.println("Backwards");
      currentDirection = 'b';
    }
    if (command == 'l') {
      Serial.println("Turn Left");
      currentDirection = 'l';
    }
    if (command == 'r') {
      Serial.println("Turn Right");
      currentDirection = 'r';
    }
}


//-------------------------------------------------------
// Function: Update Speed
//-------------------------------------------------------
int updateSpeed(char command, int setSpeed){
  // Is this a motor speed 0 - 5
    if (command == '0') {
      Serial.println("Stop");
      setSpeed = 0;
    }
    if (command == '1') {
      Serial.println("Speed = 10%");
      setSpeed= 26;
    }
    if (command == '2') {
      Serial.println("Speed = 20%");
      setSpeed = 51;
    }
    if (command== '3') {
     Serial.println("Speed = 30%");
     setSpeed = 77;
    }
    if (command == '4') {
      Serial.println("Speed = 40%");
      setSpeed = 102;
    }
   if (command == '5') {
    Serial.println("Speed=40%"); 
    setSpeed = 128;
    }

}

//--------------------------------------------------------
//Subroutine: Run Motors
//--------------------------------------------------------
void runMotors(int currentDirection, int pwmDutyCycle){
    
    // Pin1  Pin2  Motor
    //  0     0    Idle
    //  0     5v   Forward
    //  5v    0    Reverse
    //  5v    5v   Idle
    
    // ReftMotor  LeftMotor  Direction
    //    For        For      Forward
    //    For        Rev      Turn Left
    //    Rev        For      Turn Right
    //    Rev        Rev      Backwards

    if (currentDirection == 'f') {  
     leftMotor.setSpeed(pwmDutyCycle);
     rightMotor.setSpeed(pwmDutyCycle);
    }
    if (currentDirection == 'l') {  
  leftMotor.setSpeed(0);
  rightMotor.setSpeed(pwmDutyCycle);
    }
    if (currentDirection == 'r') {  
  leftMotor.setSpeed(pwmDutyCycle);
  rightMotor.setSpeed(0);
    }
    if (currentDirection == 'b') {  
  leftMotor.setSpeed(0);
  rightMotor.setSpeed(pwmDutyCycle);
    }
    
  }
  


// -------------------------------------------------------
// The setup() method runs once, when the sketch starts
// -------------------------------------------------------
void setup(){ 
 
  // Initialize the serial communications
  Serial.begin(9600);

  // Print the program details
  Serial.println("-------------------------------------");
  Serial.println("Program: Name"); 
  Serial.println("Initializing ...");

  // Configuration the motor pins
  pinMode(rightMotorLogicPin1, OUTPUT);   
  pinMode(rightMotorLogicPin2, OUTPUT);   
  pinMode(leftMotorLogicPin1, OUTPUT);   
  pinMode(leftMotorLogicPin2, OUTPUT);   

  // Print the motor pin configuration for wiring
  Serial.println("Right Motor Pin 1 = 4 ");
  Serial.println("Right Motor Pin 2 = 5");
  Serial.println("Right Motor Enable = 6 ");
  Serial.println("Left Motor Pin 1 = 9 ");
  Serial.println("Left Motor Pin 2 = 10 ");
  Serial.println("Left Motor Enable = 11 ");

  // Initialization completed successfully
  Serial.println("Initialization complete");
  
}

// -------------------------------------------------------
// The loop() method runs over and over again
// -------------------------------------------------------
void loop(){
  
  int pwmDutyCycle = 0;
  char currentDirection = 'x';
  char command = 0;
  bool keyboardControl = true;
  
  // Control the motors from the keyboard
  while (keyboardControl) {
    
    // Wait for a command from the keyboard
    char receiveCommand;
    
    // Update the direction of the robot
    currentDirection = updateDirection(command, currentDirection);
    
    // Update the speed of the robot
    pwmDutyCycle = updateSpeed(command, pwmDutyCycle);
    
    // Set the motor pins according to speed and direction
    runMotors(currentDirection, pwmDutyCycle);
    
    // Was this an exit command
    if (command == 'x') keyboardControl = false;

    // Wait for a character to arrive
  delay(10);
    
  }

  
}
