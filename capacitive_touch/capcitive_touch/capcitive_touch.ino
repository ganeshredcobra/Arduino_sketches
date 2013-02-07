/*This code turns the LED on while the sensor is in contact
with a conductive material (e.g. when someone touches it
with their bare skin/fingers)

Setup:
Attach a high value resistor (1-10M Ohm) between an output
pin 4 and input pin 5. Also connect a short bare copper or
aluminum wire/foil to the input pin5. Connect an LED to
output pin13 and GND.

By: Naureen Mahmood.

*/

#define LED        13
#define THRESHOLD   3

int capI;      // interval when sensor pin 5 returns LOW
int capJ;
int capK;
int capL;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(4, OUTPUT);     // output pin
  pinMode(8, OUTPUT);      // input pin
  pinMode(5, INPUT);      // input pin
  pinMode(6, INPUT);      // input pin
  pinMode(9, INPUT);      // input pin
  pinMode(10, INPUT);      // input pin
}

void loop()
{
  capI = 0;      // clear out capacitance measure at each loop
  capJ = 0;
  capK = 0;
  capL = 0;
  // transition output pin4 LOW-to-HIGH  to 'activate' sensor pin5
  digitalWrite(4, HIGH); 
  digitalWrite(8, HIGH);       

  // On activation, value of pin 5 stays LOW for a time interval T = R*C.
  // C is big if the sensor is touched with a conductive object.
  // Increment capI for the interval while pin5 is LOW
  int val = digitalRead(5);  // read the input to be checked
  int val1 = digitalRead(6);  // read the input to be checked
  int val2 = digitalRead(9);  // read the input to be checked
  int val3 = digitalRead(10);  // read the input to be checked
  while (val!= HIGH){   
    capI++;   
    val = digitalRead(5);    // re-read the input to be checked
    //val1 = digitalRead(6);    // re-read the input to be checked
    
  }
  while (val1!= HIGH){   
    capJ++;   
    //val = digitalRead(5);    // re-read the input to be checked
    val1 = digitalRead(6);    // re-read the input to be checked
    
  }
  //delay(1);
 while (val2!= HIGH){   
    capK++;   
    //val = digitalRead(5);    // re-read the input to be checked
    val1 = digitalRead(9);    // re-read the input to be checked
    
  }
 /*delay(1);
  while (val3!= HIGH){   
    capL++;   
    //val = digitalRead(5);    // re-read the input to be checked
    val1 = digitalRead(10);    // re-read the input to be checked
    
  }
  delay(1);*/
  // transition output pin4 HIGH-to-LOW to 'deactivate' sensor pin5
  digitalWrite(4, LOW); 
  digitalWrite(8, LOW);       
  Serial.println(capI, DEC);  // print out interval

  if (capI > THRESHOLD){       // Turn LED on if capI is above threshold
    //digitalWrite(LED, HIGH);
    Serial.println("A");
  }
  else if(capJ > THRESHOLD){
    //digitalWrite(LED,  LOW);
    Serial.println("B");
  }
  else if(capK > THRESHOLD){
    //digitalWrite(LED,  LOW);
    Serial.println("C");
  }
  else if(capL > THRESHOLD){
    //digitalWrite(LED,  LOW);
    Serial.println("D");
  }
}
