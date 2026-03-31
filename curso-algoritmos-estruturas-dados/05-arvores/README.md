# 05-arvores

Árvores em C.
Este tópico apresenta árvores binárias, árvores de busca, B-trees e red-black trees.

## O que você vai aprender

- O que é uma árvore.
- Como funciona uma árvore binária.
- O que é uma árvore de busca binária (BST).
- Diferença entre B-tree e red-black tree.
- Complexidade de tempo e espaço.

## O que é uma árvore

Uma árvore é uma estrutura hierárquica de nós.
Cada nó pode ter filhos, e há um nó raiz que começa a estrutura.

Em árvores binárias, cada nó tem no máximo dois filhos: esquerdo e direito.

## Exemplos nesta pasta

Os exemplos de árvore estão nos arquivos desta pasta:

- `bst.c`

## Árvore de busca binária (BST)

Uma BST mantém os valores em ordem.
Para cada nó:

- todos os valores à esquerda são menores.
- todos os valores à direita são maiores.

Isso permite busca, inserção e remoção mais rápidas do que em listas não ordenadas.

### Operações da BST

- Busca: O(h) onde h é a altura da árvore.
- Inserção: O(h)
- Remoção: O(h)

Se a árvore ficar degenerada (como uma lista), o tempo pode chegar a O(n).

## B-tree

B-tree é uma árvore balanceada usada em bancos de dados e sistemas de arquivo.
Ela permite nós com múltiplos valores, reduzindo o número de acessos em disco.

### Características

- Cada nó pode ter várias chaves.
- As chaves permanecem ordenadas dentro do nó.
- A árvore permanece balanceada durante inserções e remoções.

### Complexidade

- Busca: O(log n)
- Inserção: O(log n)
- Espaço: O(n)

## Red-black tree

Red-black tree é uma árvore balanceada com regras de cor para garantir altura limitada.
Ela mantém a árvore aproximadamente balanceada sem necessidade de rotações complexas.

### Propriedades principais

- Cada nó é vermelho ou preto.
- A raiz é sempre preta.
- Folhas nulas são pretas.
- Um nó vermelho não pode ter filho vermelho.
- Todos os caminhos da raiz às folhas têm o mesmo número de nós pretos.

### Complexidade

- Busca: O(log n)
- Inserção: O(log n)
- Remoção: O(log n)
- Espaço: O(n)

## Nuances

- Sempre libere memória dos nós com `free()`.
- Cuidado ao implementar remoção: existem casos especiais para nós com dois filhos.
- Em C, a manipulação de ponteiros deve ser precisa para evitar corrupção de memória.
- A altura da árvore é o fator chave para desempenho.

## Como testar

Compile `BinarySeachTree.c` ou `BTrees.c` e execute para ver inserção, busca e travessias.

## Referências

- "Introduction to Algorithms" - Cormen et al.
- "Data Structures and Algorithm Analysis in C" - Mark Allen Weiss.
