#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board1(0x40);

const int PWM_FREQUENCY = 50;
const int SERVOMIN = 205;
const int SERVOMAX = 410;

// Increase for slower movement.
const int STEP_DELAY_MS = 40;

int currentAngle = 0;

int angleToPulse(int angle) {
  angle = constrain(angle, 0, 180);
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setAllServos(int angle) {
  int pulse = angleToPulse(angle);

  // Update channels 4, 5, 6, and 7.
  for (int channel = 0; channel < 4; channel++) {
    board1.setPWM(channel, 0, pulse);
  }
}

void moveSlowlyTo(int targetAngle) {
  targetAngle = constrain(targetAngle, 0, 180);

  while (currentAngle != targetAngle) {
    currentAngle += (targetAngle > currentAngle) ? 1 : -1;

    setAllServos(currentAngle);

    if (currentAngle % 10 == 0) {
      Serial.print("Channels 4–7 | Commanded angle: ");
      Serial.println(currentAngle);
    }

    delay(STEP_DELAY_MS);
  }
}

void setup() {
  Serial.begin(115200);

  board1.begin();
  board1.setPWMFreq(PWM_FREQUENCY);
  delay(100);

  // Initial move to 180 may be fast.
  setAllServos(90);
  delay(500);

//  moveSlowlyTo(180);
//  delay(1000);

  moveSlowlyTo(0);
  delay(500);
  moveSlowlyTo(90);

  Serial.println("Finished. Channels 4–7 holding at 90.");
}

void loop() {
  // Run once. Press reset to repeat.
}
