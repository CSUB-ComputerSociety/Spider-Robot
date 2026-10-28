# Components Guideline

## Overview
This markdown folder will explain the entire calculation process and reasoning behind why we chose certain electrical parts for this project.

## About
The purpose of this project was to design a fun and creative workshop to celebrate Halloween, while also utilizing our skills of engineering to design a robotic spider. 
The overall goals of this project is to be beginner friendly, inexpensive for a mass purchase of six groups, and understand the calculations when designing a robot.

## Component list
- Arduino Uno R3 
	- This inexpensive board is easy to program using the Arduino IDE software. It will provide the main logic in controlling 8 servos.
- PCA9685 Servo Driver Board
	- When powering multiple SG90 servos, we cannot power them using the Arduino Uno board, and there are not enough outlets to use the amount of servos needed on an arduino board.
	- That is why this board provides a good communication link between the SG90 servos and the arduino board
- SG90 Servo
	- Inexpensive servo that is very compact and simple to use
- SoloGood Ubec Convertor
	- When discussing power, you cannot power the servos using the Arduino 5V pin, and the current needed is definitely higher. Applying a 
- UGENEX 1000 mA 7.4V Battery
	- Inexpensive option to buying a two pack of RC batteries
	- More in depth explanation in power section
- Barrel Jack Convertor
	- Soldering portion includes soldering the Barrel Jack ground and power wires to the batteries ground and wire cable
- JST Connector
	- Connector to easily turn of the battery

## Calculations Summary 
This robot uses eight SG90 servos, with two servos controlling each leg. Assuming each servo draws 0.65 A under heavy load, the combined current is 5.2 A, requiring 26 W at 5 V (P = VI). Adding a 25% margin gives a minimum servo-supply rating of 6.5 A, making a verified 5 V, 8 A continuous buck converter a suitable candidate. The PCA9685 chip adds approximately 0.05 W, while the Arduino’s consumption and converter losses must also be included in the overall power budget. The 7.4 V, 1000 mAh battery stores approximately 7.4 Wh; assuming 90% converter efficiency and 80% usable battery energy, the estimated runtime is about 12 minutes at the assumed heavy load. The SG90 servos were selected due to the Aliexpress also using the same servos.

## Calculations:
To calculate the power needed for the servos, the datasheet for the sg90 micro servo show that the micro servo has a stall torque of 1.8 kgfcm at 4 volts.

From arduino dataforms, it states that the maximum current for a micro servo under heavy load is 650 mA, which is 0.65 A. 
https://www.kpower.com/insight_gearbox/7515.html
https://forum.arduino.cc/t/servo-external-power-calculation/680352
https://friendlywire.com/projects/ne555-servo-safe/SG90-datasheet.pdf
From there, since we are powering 8 servos, we would need 5.2 A of current. A safety margin was suggested in some documents of a 25% safety margin so if we multiply that by 1.25, we get the approximate 6.25 A of current. 

For the PCA9685 board, the maximum operating supply current is 10 mA. The voltage needed is 5V to power the board. In total, the power needed for this board would be 5V(0.01A) = 0.05 W for just the board, not including the servos. 
https://learn.adafruit.com/16-channel-pwm-servo-driver/pinouts?utm_source=chatgpt.com

From the datasheets, it states that voltage for servos range from 4-6V so at 5V, the power needed for one micro servo is 5(0.65 A) = 3.25W. For eight servos, this means 26W in total for the servos. 

If we add the power needed for the PCA9685 board and the servos combined, we get 26.05W for power. 

The power needed for the arduino when powered through the barrel jack ranges from 7-12V and 1 A. A portable usb 5V 1A charger was an option but if we want a compact form, one power supply is preferred. https://docs.arduino.cc/learn/electronics/power-pins/?utm_source=chatgpt.com


Battery:
Given what we calculated there, we need a battery that can provide 26W of power, and 6.25A of current. There are two batteries that we looked into. One is a 1000mA battery with 7.4 V. It is a 2S lipo battery with a rating of 35C continuous and 70C burst. 

This battery has a maximum capacity current of 35A which is ample supply. 

Power = (Volts)(Current) = 7.4 x 35 = 259W when fully charged

This is ample enough power for this project. 

## Future Works
This was used for the current spider. As the project grows, more calculations will be provided and information. If anything seems wrong in regards to the calculations or in the setup, let us know as this is a learning and work in progress project.

