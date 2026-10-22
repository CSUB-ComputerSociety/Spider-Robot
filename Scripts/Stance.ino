#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board1(0x40);

const int PWM_FREQUENCY = 50;
const int SERVOMIN = 205;
const int SERVOMAX = 410;

struct Setservo{
  uint8_t channel;
  int currentAngle;
};
Setservo servos[8] = {{0,90},{1,90}, {2,90},{3,90},{4,90},{5,90},{6,90},{7,90} };
const int STEP_DELAY_MS = 40;

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setServos(Setservo &servos, int angle){
  angle = constrain(angle, 0, 180);
  board1.setPWM(servos.channel, 0, angleToPulse(angle));
  servos.currentAngle = angle;
}

void pushOUT(){
  bool moving;
  do {
    moving = false;
    for (int channel = 4; channel < 8; channel++)
    {
      Setservo &servo = servos[channel];
      if(servo.currentAngle != 180){
        int nextAngle = servo.currentAngle + ((180 > servo.currentAngle) ? 1: -1);
        setServos(servo, nextAngle);
        moving = true;
      }
    }
  if(moving){
    delay(40);
  }
  }while (moving);
}
void pushIN() {
  bool moving;
  do {
    moving = false;
    for (int channel = 4; channel < 8; channel++)
    {
      Setservo &servo = servos[channel];
      if(servo.currentAngle != 70){
        int nextAngle = servo.currentAngle + ((70 > servo.currentAngle) ? 1: -1);
        setServos(servo, nextAngle);
        moving = true;
      }
    }
  if(moving){
    delay(40);
  }
  } while (moving);  
}

void comeIN(){
    bool moving;

  do {
    moving = false;

    for (int channel = 0; channel < 4; channel++) {
      Setservo &servo = servos[channel];

      if (servo.currentAngle != 90) {
        int nextAngle = servo.currentAngle +
            ((90 > servo.currentAngle) ? 1 : -1);

        setServos(servo, nextAngle);
        moving = true;
      }
    }
    for (int channel = 4; channel < 8; channel++) {
      Setservo &servo = servos[channel];

      if (servo.currentAngle != 70) {
        int nextAngle = servo.currentAngle +
            ((70 > servo.currentAngle) ? 1 : -1);

        setServos(servo, nextAngle);
        moving = true;
      }
    }

    // All four channels are updated before waiting.
    if (moving) {
      delay(STEP_DELAY_MS);
    }
  } while (moving);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  board1.begin();
  board1.setPWMFreq(PWM_FREQUENCY);
  delay(100);
  for(int i = 0; i < 8; i++){
    setServos(servos[i],90);
  }
  pushOUT();
  delay(200);
  pushIN();
  delay(200);
  comeIN();
}

void loop() {
  // put your main code here, to run repeatedly:

}
