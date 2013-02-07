import processing.serial.*;
import ddf.minim.* ;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
Minim minim;
AudioPlayer au_player1,au_player2;

Serial myPort;  // The serial port:



void setup() {
  minim = new Minim(this) ;
  au_player1 = minim.loadFile("a57.mp3");
  au_player2 = minim.loadFile("a69.mp3");

  // List all the available serial ports:
  println(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);

}

void draw() {
  while (myPort.available() > 0) {
    char inByte = myPort.readChar();
    println(inByte);
    if(inByte=='A'){      
      au_player1.play(); 
       au_player1.rewind();
      //au_player1.loop();    
    }
    else if(inByte=='B'){      
      au_player2.play();
      au_player2.rewind();
    }   
    
  }
}
/*void stop()
{
  // always close Minim audio classes when you are done with them
  au_player1.close();
  au_player2.close();
  minim.stop();

  super.stop();
}*/
