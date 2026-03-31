# 03-mapeamento-pista

Mapeamento de pista.
Este tópico mostra como identificar curvas, paradas e outros pontos importantes na pista.

## O que você vai aprender

- Como detectar pontos especiais com sensores.
- Como contar paradas.
- Como interpretar curvas.
- Como planejar uma resposta quando a linha é perdida.

## Como o código funciona

O arquivo `mapa_pista.ino` usa dois sensores:

- `SENSOR_PARADA` para detectar uma parada.
- `SENSOR_CURVA` para detectar uma curva.

Ele conta as paradas e acende um LED quando a curva é detectada.

## O exemplo em código

No sketch, a rotina principal faz:

- ler o estado dos sensores.
- aumentar `stop_count` quando o sensor de parada é acionado.
- usar uma flag para contar cada parada apenas uma vez.
- sinalizar a curva com um LED.

## Por que isso importa

Um seguidor de linha precisa saber quando a pista muda.
Curvas e paradas exigem ações diferentes do robô.
O mapeamento transforma leituras de hardware em decisões.

## Como testar

1. Abra `mapa_pista.ino`.
2. Envie o código para a placa.
3. Acione o sensor de parada e observe a contagem.
4. Acione o sensor de curva e observe o LED.

## Observações técnicas

- A flag evita que uma mesma parada seja contada várias vezes.
- O valor `LOW` pode indicar sensor ativo, dependendo do projeto.
- Em sistemas reais, prefira temporizadores a `while(true)`.
- O debounce é importante para sensores mecânicos.

## Exercícios

- Adicione recuperação de linha quando todos os sensores detectarem branco.
- Use um segundo LED para diferenciar curvas e paradas.
- Diminua a velocidade ao entrar em curvas.

## Próximo passo

Depois deste tópico, você terá uma base para unir controle de linha e mapeamento de pista no robô.
