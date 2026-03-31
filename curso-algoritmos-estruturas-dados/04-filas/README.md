# 04-filas

Filas em C.
Este tópico apresenta filas e as diferenças entre implementação estática e dinâmica.

## O que você vai aprender

- O que é uma fila.
- Operações `enqueue` e `dequeue`.
- Diferença entre FIFO e LIFO.
- Como representar filas em C.
- Complexidade de tempo e espaço.

## O que é uma fila

Uma fila é uma estrutura de dados FIFO (First In, First Out).
O primeiro elemento inserido é o primeiro a ser removido.

Aplicações comuns:

- Processamento de tarefas em ordem.
- Comunicação entre etapas de um pipeline.
- Filas de impressão e eventos.

## Exemplos nesta pasta

Os exemplos de filas estão nos arquivos desta pasta:

- `queue_static.c`
- `queue_dynamic.c`

## Fila estática

A fila estática usa um array de tamanho fixo.

Características:

- Capacidade limitada.
- Operações podem ser O(1) se houver um índice circular.
- Requer cuidado com overflow.

## Fila dinâmica

A fila dinâmica utiliza nós encadeados.

Características:

- Cresce conforme a demanda.
- Usa memória adicional para ponteiros.
- Não depende de capacidade pré-definida.

## Operações

- `enqueue`: adiciona ao final da fila.
- `dequeue`: remove do início da fila.
- `front`/`peek`: observa o primeiro elemento.
- `isEmpty`: verifica se a fila está vazia.

## Nuances

- Em filas estáticas, use índice circular para evitar deslocamento de dados.
- Em filas dinâmicas, inicialize `head` e `tail` corretamente.
- Remova elementos e libere nós para evitar vazamentos.

## Complexidade

- `enqueue`: O(1)
- `dequeue`: O(1)
- `peek`: O(1)
- Espaço: O(n) para n elementos

## Como testar

Compile com `gcc DinamicQueues.c -o dynamic_queues` ou `gcc StaticQueues.c -o static_queues`.
Execute e observe a ordem de remoção dos elementos.

## Referências

- "Data Structures and Algorithm Analysis in C" - Mark Allen Weiss.
- "Algorithms" - Robert Sedgewick.
