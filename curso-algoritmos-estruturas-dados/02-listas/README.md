# 02-listas

Listas ligadas em C.
Este tópico explica como funciona uma lista ligada e quais são as operações básicas.

## O que você vai aprender

- O que é um nó.
- Como uma lista ligada armazena dados.
- Como inserir, remover e buscar elementos.
- Diferença entre lista simples, circular e duplamente ligada.
- Complexidade de tempo e espaço.

## O que é uma lista ligada

Uma lista ligada é uma coleção de nós em que cada nó aponta para o próximo.
Cada nó contém um valor e um ponteiro para o próximo item.

Vantagens:

- Tamanho dinâmico, não depende de capacidade fixa.
- Inserção e remoção no meio da lista podem ser mais eficientes que arrays.

Desvantagens:

- Acesso sequencial: não é possível pular diretamente para um elemento pelo índice.
- Uso extra de memória para ponteiros.

## Exemplos nesta pasta

Os exemplos de listas estão nos arquivos desta pasta:

- `linked_list.c`

## Operações principais

### Inserção

- Em uma lista simples, inserir no início é O(1).
- Inserir no final exige percorrer a lista se não houver ponteiro para o último elemento, O(n).

### Remoção

- Remover o primeiro nó é O(1).
- Remover um nó específico geralmente é O(n), pois é preciso encontrar o predecessor.

### Busca

- A busca linear em lista ligada é O(n).
- Não há busca por índice em tempo constante.

## Variantes

### Lista ligadas simples

Cada nó tem um ponteiro para o próximo.

### Lista circular

O último nó aponta de volta para o primeiro.
Isso simplifica alguns ciclos e operações que precisam voltar ao início.

### Lista duplamente ligada

Cada nó tem ponteiros para o próximo e para o anterior.
Isso facilita remoções e percursos reversos, mas consome mais memória.

## Nuances

- Sempre inicialize o ponteiro `next` ou `prev`.
- Verifique `NULL` antes de acessar o próximo nó.
- Liberar memória com `free()` evita vazamentos.
- O nó cabeça (`head`) é a porta de entrada para a lista.

## Complexidade

- Inserção no início: O(1)
- Inserção no final: O(n) se não há ponteiro tail
- Remoção no início: O(1)
- Remoção de valor específico: O(n)
- Busca: O(n)
- Espaço: O(n) para n nós

## Como testar

Compile o arquivo com `gcc linkedLists.c -o linkedLists` e execute.
A implementação costuma incluir uma função `main()` com exemplos de inserção e listagem.

## Referências

- "Data Structures and Algorithm Analysis in C" - Mark Allen Weiss.
- "Algorithms" - Robert Sedgewick.
