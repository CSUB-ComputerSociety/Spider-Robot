# Guide to Build Folder

## File Names
- Current Bottom Body.stl
    - This stl was made to mount the electrical components of the Spider, which includes the battery, PCA965 Servo Driver Board, and the Arduino Uno R3. The UBEC convertor does not have a mount as we thought the best way was to use velcro to attach the ubec on the cover of the STL.
- Current Connector.stl
    - This file reflects the connector piece of the Cross connectors, You screw this piece onto the Cross Connector.
- Current Cross Connector.stl
    - This file contains the design for the "joints" of the spider. It connects to the servo on the body, and the legs of the servo.
- Current Leg.stl
    - This file is connecting the leg servo to the joint.
- Current Top Body.stl
  - This file is the cover. This one specifically is a work in progress.
 

## Prints
- (1) Lower Body
- (4) Joints
- (4) Legs
- (8) 4.8 mm Connector Pieces
- (8) 5 mm Connector Pieces
- (1) Cover
Print settings. Ensure Normal Supports is applied and abide by your 

## Build Equipment
- Screw Driver
- 2.5 mm Screws
- Allen Wrench
- USB to USB Type B

## How to Build
After printing out all the pieces for this project, make sure to clean any supports used on these prints. 
Once parts are cleaned, begin by mounting the electrical components on the bottom plate piece, which consists of the Arduino Uno, PCA9685 servo board, and velcro the battery to the board.
Then screw in the 4 bottom servos into the slot of the bottom board. The screw horns should be facing out of the board meaning the servo head should be near the outside of the body. 
Once Screwed in, test the servos position and calibrate the servos by determining where your 90 degrees is (refer to the calibration script in Scripts). For the scripts in the scripts folder, they are under the impression that 90 degrees is the center or facing straight out from the body. Use the 5 mm connectors for this.
After calibrating, attach the joints from the bottom fake servo mount on the bottom of the body, and connect the connector piece already set to 90 to the joint.
Once the joints are attach, screw the servos to the leg pieces and again calibrate these servos as well. and determine where your 90 degrees is, which for the scripts is in an upright standing position.

## Updates
Images will be attached soon to provide visualizations for these steps. The Top Body is not included in the instructions since that portion is still in development.
    
