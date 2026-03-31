#include <Servo.h>

Servo meuServo;
const int PINO_SERVO = 9;

void setup()
{
  meuServo.attach(PINO_SERVO);
}

void loop()
{
  meuServo.write(0);
  delay(1000);
  meuServo.write(90);
  delay(1000);
  meuServo.write(180);
  delay(1000);
}
