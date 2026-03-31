# 07-ordenacao

Algoritmos de ordenação em C.
Este tópico apresenta seis algoritmos clássicos e suas características.

## O que você vai aprender

- Como cada algoritmo ordena uma sequência.
- Diferenças de desempenho em conjuntos grandes.
- Estabilidade e uso de memória.
- Quando escolher cada algoritmo.

## Exemplos nesta pasta

Os exemplos de ordenação estão nos arquivos desta pasta:

- `sorting_examples.c`

## Bubble Sort

Bubble Sort compara pares adjacentes e troca-os se estiverem fora de ordem.

- Complexidade de tempo: O(n²)
- Espaço: O(1)
- Estável: sim

É simples, mas ineficiente em grandes volumes.

## Selection Sort

Selection Sort procura o menor elemento e troca com a posição atual.

- Complexidade de tempo: O(n²)
- Espaço: O(1)
- Estável: não, a menos que seja adaptado

É útil em ambientes de memória limitada.

## Insertion Sort

Insertion Sort constrói a ordenação elemento a elemento, inserindo cada valor em sua posição correta.

- Complexidade de tempo: O(n²) no pior caso, O(n) no melhor caso com dados quase ordenados
- Espaço: O(1)
- Estável: sim

É eficiente para vetores pequenos ou quase ordenados.

## Merge Sort

Merge Sort usa divisão e conquista para dividir o vetor em duas metades, ordenar e mesclar.

- Complexidade de tempo: O(n log n)
- Espaço: O(n)
- Estável: sim

É uma escolha sólida para grandes conjuntos quando há memória extra disponível.

## Quick Sort

Quick Sort escolhe um pivô e particiona o vetor em elementos menores e maiores.

- Complexidade de tempo: O(n log n) em média, O(n²) no pior caso
- Espaço: O(log n) para pilha de recursão
- Estável: não

É muito rápido na prática, mas depende da escolha de pivô.

## Heap Sort

Heap Sort transforma o vetor em um heap e extrai o maior elemento repetidamente.

- Complexidade de tempo: O(n log n)
- Espaço: O(1)
- Estável: não

É útil quando memória extra deve ser mínima.

## Como escolher

- Use `BubbleSort` e `InsertionSort` apenas para ensino ou entradas pequenas.
- Use `MergeSort` quando precisar de estabilidade e tempo garantido.
- Use `QuickSort` quando desempenho prático for prioridade.
- Use `HeapSort` quando não for possível alocar memória extra.

## Referências

- "Introduction to Algorithms" - Cormen et al.
- "Algorithms" - Robert Sedgewick.
