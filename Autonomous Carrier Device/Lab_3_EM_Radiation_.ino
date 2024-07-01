int sensorPin=0;
int data[100];
int sensorValue;

void setup() {
    
//Set the reference voltage for the analog input to 5V
  analogReference(DEFAULT);
  
//initialise the serial communications
  Serial.begin(9600); 
  
}
void loop() {
    
    Serial.println("Collection data from AnalogPin0");
    
//Read 100 input values into a data array
  for (int i=0; i<100; i++) {
    
//Read the value from the sensor 
sensorValue= analogRead(sensorPin);

//Store the value from the sensor
  data[i]=sensorValue; 
  
//Wait for 1 msec
  delay(1);
  
//Print the data array 
  for (int i=0; i < 100; i++); {

//print the number of each line in the serial printer 
   Serial.print (i+1);

//A gap between the number and value in Pin
   Serial.print("\t");
  
//Print the data to the serial monitor
  Serial.println(data[i], DEC);
 
}

}

}
