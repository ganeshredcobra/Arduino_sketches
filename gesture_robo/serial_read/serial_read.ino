int incomingByte;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

        // send data only when you receive data:
        //if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                  int val=(incomingByte,DEC);
                // say what you got:
               // Serial.print("I received: ");
                Serial.println(val);
                if(incomingByte==65){
                  digitalWrite(12, LOW);
                  digitalWrite(13, HIGH);
                }
                else if(incomingByte==66){
                  digitalWrite(13, LOW);
                  digitalWrite(12, HIGH);

                }
                /*else{
                   digitalWrite(12, LOW);
                   digitalWrite(13, LOW);
                }*/
        //}
}
