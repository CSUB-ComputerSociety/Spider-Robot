#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board1(0x40);

// Provisional channel pair; the tester should confirm these.
const uint8_t SWING_CHANNEL = 0;
const uint8_t LIFT_CHANNEL = 4;

const int PWM_FREQUENCY = 50;
const int SERVOMIN = 205;
const int SERVOMAX = 410;
const int STEP_DELAY_MS = 40;

 

int angleToPulse(int angle) {
  angle = constrain(angle, 0, 180);
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setServoAngle(uint8_t channel, int angle) {
  int pulse = angleToPulse(angle);
  board1.setPWM(channel, 0, pulse);
}

void wave() {
  // lift the leg
  // raise lef from starting to 0 degrees
  setServoAngle(LIFT_CHANNEL, 0);
  delay(300);
  
  // swing it side to side
  setServoAngle(SWING_CHANNEL, 80); // swing away
  delay(300);

  setServoAngle(SWING_CHANNEL, 100); // swing the other way 
  delay(300);
  
  setServoAngle(SWING_CHANNEL, 90); // return to center
  delay(300);

  // lower the leg to standing position
  setServoAngle(LIFT_CHANNEL,90);

}

void setup() {
  Serial.begin(115200);
  board1.begin();
  board1.setPWMFreq(PWM_FREQUENCY);
  wave();
}

void loop() {

}