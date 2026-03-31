# 09-hashing-e-priority-queues

Hashing e filas de prioridade em C.
Este tópico explica o uso de tabelas hash e filas de prioridade.

## O que você vai aprender

- O que é hashing.
- Como tabelas hash mapeiam chaves para posições.
- O que é uma fila de prioridade.
- Diferença entre fila comum e fila de prioridade.
- Complexidade de tempo e espaço.

## Exemplos nesta pasta

- `hashing_priority_queue.c`

## Hashing

Hashing converte uma chave em um índice de array usando uma função de hash.

Principais vantagens:

- Acesso muito rápido em média.
- Busca, inserção e remoção podem ser O(1).

Desafios:

- Colisões quando duas chaves mapeiam para o mesmo índice.
- Escolha de função de hash e tratamento de colisões.

### Complexidade

- Tempo médio: O(1)
- Pior caso: O(n) se muitas colisões ocorrerem
- Espaço: O(n)

## Filas de prioridade

Uma fila de prioridade remove o elemento de maior prioridade primeiro.

Pode ser implementada com um heap.

- Inserção: O(log n)
- Remoção do maior/menor: O(log n)
- Espaço: O(n)

## Nuances

- Em C, a implementação de heaps exige controle manual de índices.
- A função de prioridade deve ser clara e consistente.
- Hashing é excelente para dicionários, mas não preserva ordem.
- Filas de prioridade são úteis em algoritmos de grafos, como Dijkstra.

## Como testar

Compile `Hashing.c` e `PriorityQueues.c` separadamente.
Use dados de exemplo para verificar a inserção, remoção e consulta.

## Referências

- "Introduction to Algorithms" - Cormen et al.
- "Algorithms" - Robert Sedgewick.
