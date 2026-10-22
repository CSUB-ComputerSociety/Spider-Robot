#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board1(0x40); //what does 0x40 mean

const int PWM_FREQ = 50;
const int SERVOMIN = 205;
const int SERVOMAX = 410;

struct Setservo{
  uint8_t channel;
  int currentAngle;
};
Setservo servos[8] = {{0,90},{1,90}, {2,90},{3,90},{4,90},{5,90},{6,90},{7,90} };
const int STEP_DELAY_MS = 40;

int angleToPulst(int angle) {
  return map(angle, 0, 180, SERVOMIN,SERVOMAX);
}

void setServos(Setservo &servos, int angle) {
  angle = constrain(angle, 0, 180);

  board1.setPWM(servos.channel, 0, angleToPulst(angle));
  servos.currentAngle = angle;
}

void onemoveSlowlyTo(Setservo &servos, int targetAngle) {
  targetAngle = constrain(targetAngle, 0, 180);
  while(servos.currentAngle != targetAngle) {
    int nextAngle = servos.currentAngle;
    if(targetAngle > servos.currentAngle) {
      nextAngle++;
    }
    else{
      nextAngle--;
    }
    setServos(servos, nextAngle);
  }
}
void twoMove(Setservo &servoA, int targetA, Setservo &servoB, int targetB)
{
  targetA = constrain(targetA, 0, 180);
  targetB = constrain(targetB, 0, 180);
  while(servoA.currentAngle != targetA || servoB.currentAngle != targetB){
    if(servoA.currentAngle!=targetA){
      int nextA = servoA.currentAngle + ((targetA > servoA.currentAngle) ? 1: -1);
      setServos(servoA, nextA);
    }
    if(servoB.currentAngle!=targetB){
      int nextB = servoB.currentAngle + ((targetB > servoB.currentAngle) ? 1: -1);
      setServos(servoB, nextB);
    }
    delay(STEP_DELAY_MS);
  }
}
void pushTogether() {
  bool moving;

  do {
    moving = false;

    for (int channel = 0; channel < 2; channel++) {
      Setservo &servo = servos[channel];

      if (servo.currentAngle != 0) {
        int nextAngle = servo.currentAngle +
            ((0 > servo.currentAngle) ? 1 : -1);

        setServos(servo, nextAngle);
        moving = true;
      }
    }
    for (int channel = 2; channel < 4; channel++) {
      Setservo &servo = servos[channel];

      if (servo.currentAngle != 180) {
        int nextAngle = servo.currentAngle +
            ((180 > servo.currentAngle) ? 1 : -1);

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
  board1.setPWMFreq(PWM_FREQ);
  delay(100);

  for(int i = 0; i<8; i++){
    setServos(servos[i], 90);
  }
for(int i = 0; i < 2; i++)
{
  delay(200);
  onemoveSlowlyTo(servos[5], 180);
  delay(200);
  onemoveSlowlyTo(servos[2], 30);
  delay(200);
  onemoveSlowlyTo(servos[5], 70);
  delay(200);
  onemoveSlowlyTo(servos[7], 180);
  delay(200);
  onemoveSlowlyTo(servos[0], 130);
  delay(200);
  onemoveSlowlyTo(servos[7], 70);
  delay(200);
  onemoveSlowlyTo(servos[4], 180);
  delay(200);
  onemoveSlowlyTo(servos[1], 130);
  delay(200);
  onemoveSlowlyTo(servos[4], 70);
  delay(200);
  onemoveSlowlyTo(servos[6], 180);
  delay(200);
  onemoveSlowlyTo(servos[3], 30);
  delay(200);
  onemoveSlowlyTo(servos[6], 70);
  delay(200);
  pushTogether();
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
