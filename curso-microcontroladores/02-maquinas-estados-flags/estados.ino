const int LED_PIN = 13;

enum Estado
{
  PARADO,
  ANDANDO
};
Estado estadoAtual = PARADO;
bool mudou = false;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop()
{
  if (!mudou)
  {
    if (estadoAtual == PARADO)
    {
      estadoAtual = ANDANDO;
      mudou = true;
      digitalWrite(LED_PIN, HIGH);
    }
    else
    {
      estadoAtual = PARADO;
      mudou = true;
      digitalWrite(LED_PIN, LOW);
    }
  }

  delay(1000);
  mudou = false;
}
