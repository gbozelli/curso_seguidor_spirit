#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int **adj;
  int n;
} Graph;

Graph *create_graph(int n) {
  Graph *g = malloc(sizeof(Graph));
  g->n = n;
  g->adj = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    g->adj[i] = calloc(n, sizeof(int));
  }
  return g;
}

void add_edge(Graph *g, int u, int v) {
  if (u < 0 || u >= g->n || v < 0 || v >= g->n) return;
  g->adj[u][v] = 1;
  g->adj[v][u] = 1;
}

bool dfs(Graph *g, int current, int target, int *visited) {
  if (current == target) return true;
  visited[current] = 1;
  for (int i = 0; i < g->n; i++) {
    if (g->adj[current][i] && !visited[i]) {
      if (dfs(g, i, target, visited)) {
        return true;
      }
    }
  }
  return false;
}

bool path_exists(Graph *g, int start, int end) {
  int *visited = calloc(g->n, sizeof(int));
  bool found = dfs(g, start, end, visited);
  free(visited);
  return found;
}

void free_graph(Graph *g) {
  for (int i = 0; i < g->n; i++) {
    free(g->adj[i]);
  }
  free(g->adj);
  free(g);
}

int main(void) {
  Graph *g = create_graph(5);
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 4);

  printf("Caminho entre 0 e 4: %s\n", path_exists(g, 0, 4) ? "sim" : "não");
  printf("Caminho entre 3 e 4: %s\n", path_exists(g, 3, 4) ? "sim" : "não");

  free_graph(g);
  return 0;
}
