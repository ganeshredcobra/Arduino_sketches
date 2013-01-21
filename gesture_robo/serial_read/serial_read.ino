const int Forward = 12;      // the pin that the LED is attached to
const int Reverse = 11;
void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(Forward, OUTPUT);
    pinMode(Reverse, OUTPUT);
}

void loop() {
  byte brightness;

  // check if data has been sent from the computer:
  if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    brightness = Serial.read();
    // set the brightness of the LED:
    if(brightness==1){
      digitalWrite(Reverse,LOW);
      digitalWrite(Forward,HIGH);

    }
    else if(brightness==2){
      digitalWrite(Forward,LOW);
      digitalWrite(Reverse,HIGH);
    }
    else{
       digitalWrite(Forward,LOW);
       digitalWrite(Reverse,LOW);
    }
  }
}
