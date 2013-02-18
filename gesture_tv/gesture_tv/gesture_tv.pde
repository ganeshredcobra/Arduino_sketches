import SimpleOpenNI.*;
import processing.serial.*;


SimpleOpenNI kinect;
Serial port;

int val=0;

int blueX;
int blueY;
int blueWidth;
int blueHeight;
int blueRightX;
int blueBottomY;

int greenX;
int greenY;
int greenWidth;
int greenHeight;
int greenRightX;
int greenBottomY;

int yellowX;
int yellowY;
int yellowWidth;
int yellowHeight;
int yellowRightX;
int yellowBottomY;

int purpleX;
int purpleY;
int purpleWidth;
int purpleHeight;
int purpleRightX;
int purpleBottomY;



void setup()
{
  kinect = new SimpleOpenNI(this);
  kinect.enableDepth();
  kinect.setMirror(true);
  kinect.enableUser(SimpleOpenNI.SKEL_PROFILE_ALL);
  
   port = new Serial(this, Serial.list()[0], 9600);
  
  
  size(640, 480);
  
   // set trigger sizes and locations
  blueX = 100;
  blueY = 200;
  blueWidth = 120;
  blueHeight = 300;
  blueRightX = blueX + blueWidth;
  blueBottomY = blueY + blueHeight;
  
  greenX = 420;
  greenY = 200;
  greenWidth = 120;
  greenHeight = 300;
  greenRightX = greenX + greenWidth;
  greenBottomY = greenY + greenHeight;

  yellowX = 150;
  yellowY = 25;
  yellowWidth = 100;
  yellowHeight = 50;
  yellowRightX = yellowX + yellowWidth;
  yellowBottomY = yellowY + yellowHeight;
  
  purpleX = 400;
  purpleY = 25;
  purpleWidth = 100;
  purpleHeight = 50;
  purpleRightX = purpleX + purpleWidth;
  purpleBottomY = purpleY + purpleHeight;
 
 
   
}// end setup

void draw()
{ 
  kinect.update();
  image(kinect.depthImage(), 0, 0);

  IntVector userList = new IntVector();
  kinect.getUsers(userList);
  
  if (userList.size() > 0)
  {
    int userId = userList.get(0);
    
    if (kinect.isTrackingSkeleton(userId))
    {
      //set up tracking of joints
      PVector leftHand = new PVector();
      PVector rightHand = new PVector();
      
      kinect.getJointPositionSkeleton(userId, SimpleOpenNI.SKEL_LEFT_HAND, leftHand);
      kinect.getJointPositionSkeleton(userId, SimpleOpenNI.SKEL_RIGHT_HAND, rightHand);
      
      PVector convertedLeftHand = new PVector();
      kinect.convertRealWorldToProjective(leftHand, convertedLeftHand);
      fill(255, 0, 0);
      ellipse(convertedLeftHand.x, convertedLeftHand.y, 5, 5);
      
      PVector convertedRightHand = new PVector();
      kinect.convertRealWorldToProjective(rightHand, convertedRightHand);
      ellipse(convertedRightHand.x, convertedRightHand.y, 5, 5);
      
   

     
    /*  if (convertedRightHand.x > 420 && convertedRightHand.x < 550 && convertedRightHand.y > 35 && convertedRightHand.y < 175)
      {   
           val=1;
           //println("Forward");
           port.write(val);
           println("1");
             
      }
      else
      {
        val=0;
        port.write(val);
                   println("0")  ;

                  // println("x is :"+convertedLeftHand.y);

      }
      if (convertedLeftHand.x > 110 && convertedLeftHand.x < 250 && convertedLeftHand.y > 35 && convertedLeftHand.y < 175)
      {   
          val=2;
           port.write(val); 
           println("2")  ;
      }
      else
      {
        val=0;
        port.write(val);
                   println("0")  ;
       
      }*/
      
       if (convertedRightHand.x > blueX && convertedRightHand.x < blueRightX && convertedRightHand.y > blueY && convertedRightHand.y < blueBottomY)
      {  
         //println("ch down");
         val=1;
         port.write(val);
      }
       if (convertedLeftHand.x > greenX && convertedLeftHand.x < greenRightX && convertedLeftHand.y > greenY && convertedLeftHand.y < greenBottomY)
      {  
        // println("ch up");
        val=2;
        port.write(val);
      }
      if (convertedRightHand.x > purpleX && convertedRightHand.x < purpleRightX && convertedRightHand.y > purpleY && convertedRightHand.y < purpleBottomY)
      {  
         //println("vol up");
         val=3;
         port.write(val);
      }
       if (convertedLeftHand.x > yellowX && convertedLeftHand.x < yellowRightX && convertedLeftHand.y > yellowY && convertedLeftHand.y < yellowBottomY)
      {  
        // println("vol dwn");
        val=4;
        port.write(val);
      }
     
    }
  }
  
  fill(0, 0, 255, 150);
  rect(blueX, blueY, blueWidth, blueHeight);
  // green trigger
  fill(0, 255, 0, 150);
  rect(greenX, greenY, greenWidth, greenHeight);
  // yellow trigger
  fill(255, 255, 0, 150);
  rect(yellowX, yellowY, yellowWidth, yellowHeight);
  // purple trigger
  fill(128, 0, 128, 150);
  rect(purpleX, purpleY, purpleWidth, purpleHeight); 
  
    
}// end draw

// user-tracking callbacks!
void onNewUser(int userId) {
  println("start pose detection");
  kinect.startPoseDetection("Psi", userId);
}
void onEndCalibration(int userId, boolean successful) {
  if (successful) {
    println(" User calibrated !!!");
    kinect.startTrackingSkeleton(userId);
  }
  else {
    println(" Failed to calibrate user !!!");
    kinect.startPoseDetection("Psi", userId);
  }
}
void onStartPose(String pose, int userId) {
  println("Started pose for user");
  kinect.stopPoseDetection(userId);
  kinect.requestCalibrationSkeleton(userId, true);
}

