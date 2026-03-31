# 02-algoritmo-pid

Algoritmo PID.
Este tópico mostra como usar controle proporcional e derivativo para seguir a linha.

## O que você vai aprender

- O que é erro no controle.
- Como calcular o termo proporcional.
- Como calcular o termo derivativo.
- Por que o termo integral nem sempre é necessário.

## O conceito de controle

O robô precisa comparar a posição atual da linha com a posição desejada.
Esse desvio é o erro.

O controle PD usa o erro e a variação do erro para ajustar os motores.

## O exemplo em código

No arquivo `pid_exemplo.ino`:

- `KP` define o ganho proporcional.
- `KD` define o ganho derivativo.
- `erroAnterior` é usado para calcular a derivada.

```ino
float erro = position - 2000;
float derivada = erro - erroAnterior;
float saida = KP * erro + KD * derivada;
```

- `position` é a posição da linha.
- `2000` é o ponto médio de referência.
- `saida` ajusta a diferença de velocidade entre os motores.

## O que cada termo faz

- Proporcional (`KP`): corrige o erro atual.
- Derivativo (`KD`): reduz oscilações e melhora a resposta.
- Integral (`KI`): acumula erro ao longo do tempo, mas não está presente neste projeto.

## Por que PD pode ser suficiente

Para um seguidor de linha simples, o termo PD corrige a direção sem acumular erros.
O termo integral pode causar resposta lenta ou oscilações se não for bem ajustado.

## Como testar

1. Abra `pid_exemplo.ino`.
2. Compile e execute o sketch.
3. Mude `KP` e `KD` e observe o comportamento.
4. Anote como a saída muda quando a linha se desloca.

## Observações

- `KP` muito alto causa movimentos bruscos.
- `KD` muito alto torna a resposta lenta.
- A velocidade base deve ser limitada.
- A saída deve ser limitada para não saturar os motores.

## Exercícios

- Ajuste `KP` e `KD` em valores diferentes.
- Adicione o termo `KI` e compare o comportamento.
- Registre o erro em cada ciclo e analise a curva.
