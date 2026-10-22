# Explanation of Scripts
## Overview
- Servo_Calibration.ino: Main priority script used to make sure and set servos to designated points
- Forward.ino: Script to make spider move forward. Currently Work in Progress
- Rising.ino: Script to cause the spider to rise to 90 degrees in a standing position
- Stance.ino: Script to cause Spider to go into 'sleep mode' from the Aliexpress video

## Servo Calibration Instructions
This script is designed for choosing where you would like the position of 0, 90, and 180 degrees to be at for the spider. In the spider that we built,
90 degrees is the standing position of servo channels 4-7 and the middle point of the channels 0-3. At first building the parts, which you can find more 
in depth in the Design folder, the script ends in the 90 degree position fixed. While the arduino is still on ensuring that the mount will not move, screw
in the connector piece to the joint, to establish that point to be 90 degrees. Run the script again and make sure that it goes there for 90 degrees. After
creating that option, figure out which direction is 0 and 180 for the board. In the scripts provided, 0 is the outward stance where it points up the leg, 
and 0 is the right of 90 degrees for servo channels 0-3. Make sure you know which direction is 0 and 180 so that when designing specific movement scripts, 
you can visualize what it is supposed to do.

## Forward Instructions
To move your spider forward. 

