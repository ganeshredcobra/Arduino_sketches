// You can change the bounding values for the capacitive/touch
// sensor depending on what values work best for your setup
// + environmental factors
#define LOW_T       10    // lower bound for touch sensor
#define HIGH_T      60    // upper bound for touch sensor
#define LED         13    // LED output pin

// These are variables for the low-pass (smoothing) filter.
float prev_capI;    // previous capacitance interval
float filt_capI;    // filtered capacitance interval
float f_val = .07;  // 1 = no filter, 0.001 = max filter
unsigned int capLo; // duration when sensor reads LOW
unsigned int capHi5; // duration when sensor reads HIGH
unsigned int capHi6; // duration when sensor reads HIGH
unsigned int capHi7; // duration when sensor reads HIGH
unsigned int capHi8; // duration when sensor reads HIGH
void setup()
{
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(4, OUTPUT);    // output pin
  pinMode(5, INPUT);     // input pin
  pinMode(6, INPUT);     // input pin
  pinMode(7, INPUT);     // input pin
  pinMode(8, INPUT);     // input pin
}

void loop()
{  
  // clear out the capacitance time interval measures at start
  // of each loop iteration
  capHi5 = 0;
  capHi6 = 0;
  capHi7 = 0;
  capHi8 = 0;
  capLo = 0;

  // average over 4 times to remove jitter
  for (int i=0; i < 4 ; i++ )
  {      
    // LOW-to-HIGH transition
    digitalWrite(4, HIGH);   

    // measure duration while the sense pin is not high
    while (digitalRead(5) != 1)
      capLo++;
    delay(1);

    //  HIGH-to-LOW transition
    digitalWrite(4, LOW);             

    // measure duration while the sense pin is high
    while(digitalRead(5) != 0 )    
     capHi5++; 
    delay(1);
    
  }

 for (int i=0; i < 4 ; i++ )
  {      
    // LOW-to-HIGH transition
    digitalWrite(4, HIGH);   

    // measure duration while the sense pin is not high
    while (digitalRead(6) != 1)
      capLo++;
    delay(1);

    //  HIGH-to-LOW transition
    digitalWrite(4, LOW);             

    // measure duration while the sense pin is high
    while(digitalRead(6) != 0 )    
     capHi6++; 
    delay(1);
    
  }
 for (int i=0; i < 4 ; i++ )
  {      
    // LOW-to-HIGH transition
    digitalWrite(4, HIGH);   

    // measure duration while the sense pin is not high
    while (digitalRead(7) != 1)
      capLo++;
    delay(1);

    //  HIGH-to-LOW transition
    digitalWrite(4, LOW);             

    // measure duration while the sense pin is high
    while(digitalRead(7) != 0 )    
     capHi7++; 
    delay(1);
    
  }
for (int i=0; i < 4 ; i++ )
  {      
    // LOW-to-HIGH transition
    digitalWrite(4, HIGH);   

    // measure duration while the sense pin is not high
    while (digitalRead(8) != 1)
      capLo++;
    delay(1);

    //  HIGH-to-LOW transition
    digitalWrite(4, LOW);             

    // measure duration while the sense pin is high
    while(digitalRead(8) != 0 )    
     capHi8++; 
    delay(1);
    
  }
   // Smoothed Low to High
if(capHi5 > 10)
  Serial.println("A");
else if(capHi6 > 10)
  Serial.println("B");
else if(capHi7 > 10)
  Serial.println("C");
else if(capHi8 > 10)
  Serial.println("D");
else 
  Serial.println(0);
}
