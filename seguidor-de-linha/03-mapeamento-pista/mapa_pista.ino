#include <Arduino.h>

const int SENSOR_PARADA = 23;
const int SENSOR_CURVA = 20;
const int LED_PIN = 22;

bool flagParadaJaContada = false;
int stop_count = 0;
int num_stops = 2;

void setup()
{
  pinMode(SENSOR_PARADA, INPUT_PULLUP);
  pinMode(SENSOR_CURVA, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
}

void loop()
{
  int estadoParada = digitalRead(SENSOR_PARADA);
  int estadoCurva = digitalRead(SENSOR_CURVA);

  if (estadoParada == LOW && !flagParadaJaContada)
  {
    stop_count++;
    flagParadaJaContada = true;
    Serial.print("Parada detectada: ");
    Serial.println(stop_count);
  }

  if (estadoParada == HIGH)
  {
    flagParadaJaContada = false;
  }

  if (estadoCurva == LOW)
  {
    Serial.println("Curva ativa");
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }

  if (stop_count >= num_stops)
  {
    Serial.println("Percurso finalizado");
    while (true)
    {
      digitalWrite(LED_PIN, LOW);
      delay(1000);
    }
  }

  delay(100);
}
