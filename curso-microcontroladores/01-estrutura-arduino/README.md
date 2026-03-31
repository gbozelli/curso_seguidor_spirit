# 01-estrutura-arduino

Estrutura básica do Arduino.
Este tópico mostra a base de um sketch e como o microcontrolador executa código repetidas vezes.

## O que você vai aprender

- A função `setup()` e seu propósito.
- A função `loop()` e como ela se repete.
- Como definir pinos com `pinMode()`.
- Como acender e apagar um LED.

## Como um sketch funciona

O programa Arduino roda em dois blocos principais:

1. `setup()`: executado uma única vez após a placa ser ligada.
2. `loop()`: executado repetidamente até a placa ser desligada.

Exemplo:

```ino
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
```

## O que faz cada linha

- `const int LED_PIN = 13;` define o pino do LED.
- `pinMode(LED_PIN, OUTPUT);` configura o pino como saída.
- `digitalWrite(LED_PIN, HIGH);` liga o LED.
- `digitalWrite(LED_PIN, LOW);` desliga o LED.
- `delay(500);` pausa por 500 milissegundos.

## Por que isso importa

O `loop()` é chamado muitas vezes por segundo.
Sem controle, o programa poderia repetir ações indevidas.
Entender essa estrutura é essencial para qualquer projeto Arduino.

## Como testar

1. Abra `estrutura.ino` no Arduino IDE.
2. Conecte a placa ao computador.
3. Selecione a placa e a porta correta.
4. Envie o sketch para a placa.
5. Observe o LED piscando.

## Observações técnicas

- `delay()` bloqueia a execução do programa.
- Em projetos maiores, é melhor evitar `delay()` excessivo.
- O pino 13 é tradicional para um LED de exemplo.
- Use um resistor em série com o LED para proteger o componente.

## Exercícios

- Altere `delay(500);` para `delay(200);`.
- Adicione outro LED em um pino diferente.
- Faça os LEDs piscarem alternadamente.

## Próximo passo

No próximo tópico você verá máquinas de estado e flags para controlar o comportamento sem travar o loop.
