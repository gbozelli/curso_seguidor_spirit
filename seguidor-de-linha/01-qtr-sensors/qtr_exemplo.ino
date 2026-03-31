#include <Arduino.h>
#include <QTRSensors.h>

const uint8_t SENSOR_COUNT = 5;
const uint8_t SENSOR_PINS[SENSOR_COUNT] = {2, 3, 4, 5, 6};
QTRSensors qtr;
uint16_t sensorValues[SENSOR_COUNT];

void setup()
{
  Serial.begin(9600);
  qtr.setTypeRC();
  qtr.setSensorPins(SENSOR_PINS, SENSOR_COUNT);

  for (uint16_t i = 0; i < 200; i++)
  {
    qtr.calibrate();
    delay(10);
  }
}

void loop()
{
  qtr.read(sensorValues);
  int position = qtr.readLine(sensorValues);

  Serial.print("posicao: ");
  Serial.println(position);
  for (int i = 0; i < SENSOR_COUNT; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(200);
}
