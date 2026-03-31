# 03-pilhas

Pilhas em C.
Este tópico descreve o conceito de pilha e como implementá-la de forma estática e dinâmica.

## O que você vai aprender

- O que é uma pilha.
- Operações `push`, `pop` e `top`.
- Diferença entre implementação estática e dinâmica.
- Aplicações de pilhas.
- Complexidade de tempo e espaço.

## O que é uma pilha

Uma pilha é uma estrutura de dados LIFO (Last In, First Out).
O último elemento inserido é o primeiro a ser removido.

Aplicações comuns:

- Validação de parênteses.
- Conversão de expressões infixa para pós-fixa.
- Implementação de chamadas recursivas.

## Exemplos nesta pasta

Os exemplos de pilhas estão nos arquivos desta pasta:

- `stack_static.c`
- `stack_dynamic.c`

## Pilha estática

A pilha estática usa um array de tamanho fixo.

Características:

- Capacidade limitada pelo tamanho do array.
- Operações `push` e `pop` são O(1).
- É simples e eficiente em uso de tempo.

## Pilha dinâmica

A pilha dinâmica usa lista ligada para alocar elementos conforme necessário.

Características:

- Cresce conforme a demanda.
- Usa mais memória por nó, devido a ponteiros.
- Permite tamanho ilimitado, dentro da memória disponível.

## Operações

- `push`: adiciona um elemento no topo.
- `pop`: remove o elemento do topo.
- `top` ou `peek`: observa o valor do topo sem remover.
- `isEmpty`: verifica se a pilha está vazia.

## Nuances

- Verifique estouro (`overflow`) em pilhas estáticas.
- Verifique estouro de memória em pilhas dinâmicas.
- Sempre libere memória no final de pilhas dinâmicas.
- Acesso direto ao elemento no meio da pilha não é eficiente.

## Complexidade

- `push`: O(1)
- `pop`: O(1)
- `top`: O(1)
- Espaço: O(n) para n elementos

## Como testar

Compile com `gcc StaticStacks.c -o static_stacks` ou `gcc ListStacks.c -o list_stacks`.
Execute e observe as operações de empilhar e desempilhar.

## Referências

- "Data Structures and Algorithm Analysis in C" - Mark Allen Weiss.
- "Algorithms" - Robert Sedgewick.
