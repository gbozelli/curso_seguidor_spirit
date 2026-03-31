#include <Arduino.h>

const int PWM_ESQ = 5;
const int PWM_DIR = 6;
const int SENSOR_COUNT = 5;
int sensorValues[SENSOR_COUNT] = {0, 0, 0, 0, 0};

float KP = 0.6;
float KD = 0.3;
float erroAnterior = 0;

int lerPosicaoLinha()
{
  int position = 2000; // valor central de exemplo
  return position;
}

void moverMotores(int esquerda, int direita)
{
  esquerda = constrain(esquerda, 0, 255);
  direita = constrain(direita, 0, 255);
  analogWrite(PWM_ESQ, esquerda);
  analogWrite(PWM_DIR, direita);
}

void setup()
{
  pinMode(PWM_ESQ, OUTPUT);
  pinMode(PWM_DIR, OUTPUT);
}

void loop()
{
  int position = lerPosicaoLinha();
  float erro = position - 2000;
  float derivada = erro - erroAnterior;
  erroAnterior = erro;

  float saida = KP * erro + KD * derivada;
  int base = 150;
  int velEsq = base - saida;
  int velDir = base + saida;

  moverMotores(velEsq, velDir);
  delay(30);
}
