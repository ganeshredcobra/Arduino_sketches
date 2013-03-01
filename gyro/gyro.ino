int HP = 12;
//int PD = 10;
//int ST = 9;



void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(HP, OUTPUT);
  //pinMode(PD, OUTPUT);
  //pinMode(ST, OUTPUT);

  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(HP, HIGH);
  /*digitalWrite(PD, LOW);
  digitalWrite(ST, LOW);*/
  // read the input on analog pin 0:
  int x = analogRead(A0);
  int y = analogRead(A1);

Serial.print("Angular velocities for\n x: ");  
  Serial.print(x, DEC);    // print the angular velocity in the axis
 /* Serial.print(" \t y: ");       // prints a space between the numbers  
  Serial.println(y, DEC);  // print the angular velocity in the Y axis  
*/
  if(x>242)
    Serial.println("X is higher");
  else if (x<239)
    Serial.println("X is lower");
  else
    Serial.println("zero level");
 /* if(y>234)
    Serial.println("Y is greater");
  else if(y<229)
    Serial.println("Y is lower");
 */
  delay(250);        // delay in between reads for stability
}
