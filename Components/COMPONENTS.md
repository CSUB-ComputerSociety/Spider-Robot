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

## Calculations

