# 04-bibliotecas-comuns

Bibliotecas principais do Arduino.
Este tópico mostra como incluir e usar código pronto para controlar sensores e atuadores.

## O que você vai aprender

- Como usar `#include`.
- Como importar bibliotecas.
- Como usar a biblioteca Servo.
- Por que bibliotecas tornam o código mais simples.

## O código de exemplo

```ino
#include <Servo.h>

Servo meuServo;
const int PINO_SERVO = 9;

void setup() {
  meuServo.attach(PINO_SERVO);
}

void loop() {
  meuServo.write(0);
  delay(1000);
  meuServo.write(90);
  delay(1000);
  meuServo.write(180);
  delay(1000);
}
```

## O que faz cada parte

- `#include <Servo.h>` traz a biblioteca Servo.
- `Servo meuServo;` cria um objeto Servo.
- `meuServo.attach(PINO_SERVO);` conecta o servo ao pino.
- `meuServo.write(ângulo);` move o servo.

## Como testar

1. Abra `bibliotecas.ino`.
2. Verifique se a biblioteca Servo está instalada.
3. Compile e envie o sketch.
4. Observe o movimento do servo.

## Observações

- Servos aceitam ângulos entre 0 e 180 graus.
- Use o pino correto com capacidade PWM.
- Bibliotecas reduzem a necessidade de escrever código complexo.
- Em projetos maiores, organize o código em arquivos separados.

## Exercícios

- Altere os ângulos para 45 e 135 graus.
- Crie uma função que mova o servo em passos de 30 graus.
- Teste outra biblioteca do Arduino.

## Referências

- Livro: "Getting Started with Arduino" de Massimo Banzi.
