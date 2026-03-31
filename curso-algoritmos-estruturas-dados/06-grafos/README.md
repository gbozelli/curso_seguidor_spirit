# 06-grafos

Grafos em C.
Este tópico descreve a representação de grafos e as buscas básicas.

## O que você vai aprender

- O que é um grafo.
- Diferença entre grafo dirigido e não dirigido.
- Representação por matriz de adjacência.
- Busca em profundidade (DFS) e existência de caminho.
- Complexidade de tempo e espaço.

## O que é um grafo

Um grafo é um conjunto de vértices conectados por arestas.
Grafos são usados para representar redes, mapas, recomendações e relacionamentos.

Tipos de grafos:

- Não dirigido: as conexões não têm direção.
- Dirigido: cada aresta tem direção.

## Exemplos nesta pasta

Os exemplos de grafos estão nos arquivos desta pasta:

- `graph_matrix.c`

## Representação por matriz de adjacência

A matriz de adjacência usa uma matriz `n x n` para representar conexões.
Cada célula indica se há aresta entre dois nós.

Vantagens:

- Busca de conexão direta é O(1).
- Código simples de implementar.

Desvantagens:

- O espaço é O(n²), caro para grafos esparsos.

## Operações importantes

- Inserir aresta: O(1)
- Remover aresta: O(1)
- Verificar conexão: O(1)

## Busca em profundidade e caminho existente

A busca em profundidade percorre um caminho até não haver mais vértices não visitados.
É usada para detectar conectividade e ciclos.

### Complexidade

- Tempo: O(V + E)
- Espaço: O(V) para vetores de visitados e pilha recursiva

## Nuances

- Sempre inicialize a matriz de adjacência com zeros.
- Libere cada linha e a própria matriz com `free()`.
- Em grafos muito grandes, prefira representação por listas de adjacência.
- O método `path_exists` demonstra como usar recursão para encontrar caminho.

## Como testar

Compile `Graphs.c` e execute para ver inserção de arestas, impressão de conexões e busca de caminho.

## Referências

- "Introduction to Algorithms" - Cormen et al.
- "Algorithms" - Robert Sedgewick.
