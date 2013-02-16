/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

IRsend irsend;
const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  3; 
int buttonState = 0;         // variable for reading the pushbutton status
void setup()
{
 // pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
  Serial.begin(9600);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
     irsend.sendNEC(0x80BFA15E, 32);  
  } 
  else {
    // turn LED off:
    //digitalWrite(ledPin, LOW); 
  }
  
/*  if (Serial.read() != -1) {
    for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x80BFA15E, 38); // Sony TV power code
      delay(40);
    }
  }*/
}
