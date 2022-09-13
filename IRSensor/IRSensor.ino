int ledPin = 8;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int alarm1 = LOW;             // we start, assuming no motion detected
int alarm2 = LOW; 
int val = 0;                    // variable for reading the pin status
 
void setup() {
  Serial.begin(9600);
  //delay(500);
  Serial.println("Start");
  pinMode(A0, INPUT);// Define pin A0 as a input
  pinMode(13, OUTPUT);// Define pin 13 as a output
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(300);
  Serial.println("");
  if (digitalRead(A0) == 0)
  {
    Serial.print("NO Object Found ");
    alarm1 = LOW;
  }
  else {
    Serial.print("Object Found ");
    alarm1 = HIGH;
  }
 
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) { 
    alarm2 = HIGH;
    Serial.println("Motion detected!");
  } else {
    alarm2 = LOW;
    Serial.println("No Motion!");
  }
  if (alarm1 == HIGH && alarm2 == HIGH){
    digitalWrite(ledPin, HIGH);
  }
  
}
