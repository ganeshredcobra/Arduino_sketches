import SimpleOpenNI.*;
import processing.serial.*;


SimpleOpenNI kinect;
Serial port;

void setup()
{
  kinect = new SimpleOpenNI(this);
  kinect.enableDepth();
  kinect.setMirror(true);
  kinect.enableUser(SimpleOpenNI.SKEL_PROFILE_ALL);
  
   port = new Serial(this, Serial.list()[0], 9600);
  
  
  size(640, 480);
  
 
   
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
      
     
      if (convertedRightHand.x > 420 && convertedRightHand.x < 550 && convertedRightHand.y > 35 && convertedRightHand.y < 175)
      {   
         
           //println("Forward");
           port.write(1);
           println("1");
             
      }
      else
      {
        port.write(0);
                   println("0")  ;

                  // println("x is :"+convertedLeftHand.y);

      }
      if (convertedLeftHand.x > 110 && convertedLeftHand.x < 250 && convertedLeftHand.y > 35 && convertedLeftHand.y < 175)
      {   
           port.write(2); 
           println("2")  ;
      }
      else
      {
        port.write(0);
                   println("0")  ;

       
      }
      
     
    }
  }
  
  
    
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

