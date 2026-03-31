# 08-busca

Algoritmos de busca em C.
Este tópico mostra como encontrar dados em listas e árvores.

## O que você vai aprender

- O que é busca linear.
- Como a busca em árvore funciona.
- Diferença entre busca sequencial e busca binária.
- Complexidade de tempo e espaço.

## O que é busca linear

Busca linear percorre os elementos um a um até encontrar o item.

- Complexidade de tempo: O(n)
- Espaço: O(1)

A busca linear é usada quando não há estrutura ordenada ou índice.

## Busca em listas

As listas ligadas do repositório (`linkedLists.c`) fazem busca sequencial.
Elas ilustram como a busca depende da travessia de ponteiros.

## Busca em árvore binária

A busca em árvore binária explora a ordenação dos nós.
Em cada nó, ela decide se deve ir para o filho esquerdo ou direito.

Exemplo nesta pasta:

- `search_examples.c`

### Complexidade em BST

- Melhor caso: O(log n)
- Pior caso: O(n) se a árvore estiver degenerada
- Espaço: O(h) de recursão, onde h é a altura

## Busca em B-tree

B-tree mantém nós balanceados com múltiplas chaves.
A busca percorre nós em tempo logarítmico e é eficiente em sistemas de arquivo.

- Complexidade de tempo: O(log n)
- Espaço: O(log n) para a pilha de chamadas

## Nuances

- A busca binária exige dados ordenados.
- A busca linear funciona em qualquer estrutura, mas pode ser lenta.
- Em árvores balanceadas, a altura limitada garante desempenho previsível.
- Verifique ponteiros nulos em implementações em C.

## Como testar

Compile `BinarySeachTree.c` ou `BTrees.c` e observe a função `search` em execução.

## Referências

- "Introduction to Algorithms" - Cormen et al.
- "Algorithms" - Robert Sedgewick.
