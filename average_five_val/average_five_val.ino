int x, y;  
int sens;

void setup()
{
  Serial.begin(9600);      // sets the serial port to 9600
}

void loop()
{
  x = analogRead(0);       // read analog input pin 0
  y = analogRead(1);       // read analog input pin 1
  //Serial.print("rotational rates are x, y: ");
  //Serial.print(x, DEC);    
  //Serial.print(" ");       // prints a space between the numbers
  //Serial.println(y, DEC);  
  sens = ReadSens_and_Condition();
  Serial.println(sens);
  delay(300);              // wait 100ms for next reading
}

int ReadSens_and_Condition(){
  int i;
  int sval = 0;

  for (i = 0; i < 5; i++){
    sval = sval + analogRead(1);    // sensor on analog pin 0
  }

  sval = sval / 5;    // average
  //sval = sval / 4;    // scale to 8 bits (0 - 255)
  //sval = 255 - sval;  // invert output
  return sval;
}
