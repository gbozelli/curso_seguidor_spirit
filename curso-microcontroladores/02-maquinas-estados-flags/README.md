# 02-maquinas-estados-flags

Máquinas de estados e flags.
Este tópico mostra como controlar diferentes modos de operação sem repetir ações desnecessárias.

## O que você vai aprender

- O que é uma máquina de estados.
- Como usar `enum` para representar estados.
- Para que servem flags.
- Como o `loop()` pode ser controlado com estados.

## Conceito de máquina de estados

Uma máquina de estados descreve modos diferentes de comportamento.
Cada estado representa um modo específico.

No exemplo, os estados são:

- `PARADO`
- `ANDANDO`

A transição entre esses estados acontece de forma controlada.

## O exemplo em código

```ino
const int LED_PIN = 13;

enum Estado { PARADO, ANDANDO };
Estado estadoAtual = PARADO;
bool mudou = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (!mudou) {
    if (estadoAtual == PARADO) {
      estadoAtual = ANDANDO;
      mudou = true;
      digitalWrite(LED_PIN, HIGH);
    } else {
      estadoAtual = PARADO;
      mudou = true;
      digitalWrite(LED_PIN, LOW);
    }
  }

  delay(1000);
  mudou = false;
}
```

## O papel da flag

A flag `mudou` impede que a mesma transição ocorra várias vezes em sequência.
Sem a flag, o estado poderia alternar a cada ciclo do `loop()`.

## Por que usar isso

O `loop()` é executado repetidamente.
A máquina de estados ajuda a controlar o fluxo do programa e evitar comandos repetidos.

## Como testar

1. Carregue o sketch na placa.
2. Observe o LED ligado ou desligado.
3. Entenda que o estado muda apenas uma vez por ciclo.

## Observações técnicas

- Em projetos reais, os estados podem ser: `inicializando`, `seguindo`, `parado` e `erro`.
- Flags evitam ação repetida.
- Em lugar de `delay()`, use `millis()` em sistemas mais complexos.
- `enum` deixa o código mais legível que números mágicos.

## Exercícios

- Adicione um estado `RETORNANDO`.
- Use um botão para mudar o estado.
- Faça a transição só ocorrer após cinco ciclos.
