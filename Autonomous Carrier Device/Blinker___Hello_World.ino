

// ===========================================
// DESN1000 - Computing Technical Streamn
// Excercise 1
// Written by Rahul Hosakere Ravishankara 
// Adapted from course notes
//============================================

void setup() {
  // pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(1500); // Wait for 1500 milliseconds(s)
  digitalWrite(LED_BUILTIN, LOW); 
  delay(1500); // Wait for 1500 milliseconds(s)
  Serial.print ("Hello World"); 
}
