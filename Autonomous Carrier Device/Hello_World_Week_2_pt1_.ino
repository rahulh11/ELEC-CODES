// ===========================================
// DESN1000 - Computing Technical Streamn
// Excercise 2
// Written by Rahul Hosakere Ravishankara 
// Adapted from course notes
//============================================
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  //print "Hello World" on every line 
  Serial.println("Hello World"); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World"); 
  // print one line every second. 
  delay(1000);
  
 
}
