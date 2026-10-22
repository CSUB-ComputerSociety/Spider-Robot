#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board1(0x40);

const uint8_t SERVO_CHANNEL = 0;
const int PWM_FREQUENCY = 50;

// Counts at 50 Hz:
// 205 ≈ 1001 us
// 307 ≈ 1499 us
// 410 ≈ 2002 us
const int SERVOMIN = 205;
const int SERVOMAX = 410;

// Larger number = slower commanded movement.
const int STEP_DELAY_MS = 40;

int currentAngle = 90;

int angleToPulse(int angle) {
  angle = constrain(angle, 0, 180);
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void moveSlowlyTo(int targetAngle) {
  targetAngle = constrain(targetAngle, 0, 180);

  while (currentAngle != targetAngle) {
    currentAngle += (targetAngle > currentAngle) ? 1 : -1;

    int pulse = angleToPulse(currentAngle);
    board1.setPWM(SERVO_CHANNEL, 0, pulse);

    // Print occasionally to avoid excessive serial output.
    if (currentAngle % 10 == 0) {
      Serial.print("Commanded angle: ");
      Serial.print(currentAngle);
      Serial.print(" | PWM count: ");
      Serial.println(pulse);
    }

    delay(STEP_DELAY_MS);
  }
}

void setup() {
  Serial.begin(115200);

  board1.begin();
  board1.setPWMFreq(PWM_FREQUENCY);
  delay(100);

  // Initial centering may be fast:
  // the Arduino does not know the starting shaft position.
  board1.setPWM(SERVO_CHANNEL, 0, angleToPulse(90));
  delay(1500);

  moveSlowlyTo(0);
  delay(1000);

  moveSlowlyTo(180);
  delay(1000);

  moveSlowlyTo(90);
}

void loop() {
  // Run once and hold center.
  // Press reset to repeat.
}