const int BUTTON_PIN = 2;
const int POT_PIN = A0;
const int LED_PIN = 9;

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int estadoBotao = digitalRead(BUTTON_PIN);
  int valorPot = analogRead(POT_PIN);
  int intensidade = map(valorPot, 0, 1023, 0, 255);

  if (estadoBotao == LOW)
  {
    analogWrite(LED_PIN, intensidade);
  }
  else
  {
    analogWrite(LED_PIN, 0);
  }

  delay(50);
}
