# 03-io-digital-analogica

Leitura e escrita de sinais digitais e analógicos.
Este tópico apresenta como o Arduino lê botões e sensores e controla saídas PWM.

## O que você vai aprender

- Diferença entre sinais digitais e analógicos.
- Como ler um botão com `digitalRead()`.
- Como ler um potenciômetro com `analogRead()`.
- Como controlar um LED com `analogWrite()`.

## O código de exemplo

```ino
const int BUTTON_PIN = 2;
const int POT_PIN = A0;
const int LED_PIN = 9;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int estadoBotao = digitalRead(BUTTON_PIN);
  int valorPot = analogRead(POT_PIN);
  int intensidade = map(valorPot, 0, 1023, 0, 255);

  if (estadoBotao == LOW) {
    analogWrite(LED_PIN, intensidade);
  } else {
    analogWrite(LED_PIN, 0);
  }

  delay(50);
}
```

## O que significa cada parte

- `digitalRead(BUTTON_PIN)` lê o estado do botão.
- `analogRead(POT_PIN)` lê a posição do potenciômetro.
- `map()` converte os valores de 0-1023 para 0-255.
- `analogWrite()` ajusta o brilho do LED.

## Conceitos importantes

- Sinal digital tem apenas `HIGH` ou `LOW`.
- Sinal analógico varia continuamente em um intervalo.
- PWM entrega um sinal digital pulsado que parece analógico.
- `INPUT_PULLUP` evita que o botão fique flutuando.

## PWM e ciclo de trabalho

PWM significa "Pulse Width Modulation".
O sinal é ligado e desligado muito rápido, criando uma média de tensão que o circuito percebe como analógica.

O ciclo de trabalho (`duty cycle`) é a proporção do tempo em que o sinal fica em `HIGH` dentro de um período.

- 0% significa sinal sempre `LOW`.
- 50% significa metade do tempo `HIGH` e metade do tempo `LOW`.
- 100% significa sinal sempre `HIGH`.

No Arduino, `analogWrite(pin, valor)` usa valores de 0 a 255 para representar esse ciclo de trabalho.
Por exemplo:

- `analogWrite(pin, 0)` → 0%
- `analogWrite(pin, 128)` → ~50%
- `analogWrite(pin, 255)` → 100%

A variação do ciclo de trabalho controla o brilho de LEDs e a velocidade de motores.

## Como testar

1. Compile e envie o sketch.
2. Abra o monitor serial se quiser acompanhar valores.
3. Pressione o botão e observe o LED.
4. Gire o potenciômetro e veja a intensidade mudar.

## Observações

- Nem todo pino digital aceita PWM.
- O valor de `analogRead()` depende da tensão de referência.
- Para motores, use um driver de motor, não um LED.
- Use resistores ao ligar LEDs diretamente.

## Exercícios

- Faça o LED acender apenas quando o botão for pressionado.
- Mostre os valores de `analogRead()` no monitor serial.
- Controle dois LEDs com diferentes valores PWM.
