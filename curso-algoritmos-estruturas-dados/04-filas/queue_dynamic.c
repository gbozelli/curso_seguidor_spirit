#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode {
  int value;
  struct QueueNode *next;
} QueueNode;

QueueNode *head = NULL;
QueueNode *tail = NULL;

bool is_empty(void) {
  return head == NULL;
}

void enqueue(int value) {
  QueueNode *node = malloc(sizeof(QueueNode));
  if (node == NULL) return;
  node->value = value;
  node->next = NULL;
  if (tail != NULL) {
    tail->next = node;
  }
  tail = node;
  if (head == NULL) {
    head = node;
  }
}

int dequeue(void) {
  if (is_empty()) {
    printf("Erro: fila vazia\n");
    return -1;
  }
  QueueNode *node = head;
  int value = node->value;
  head = head->next;
  if (head == NULL) {
    tail = NULL;
  }
  free(node);
  return value;
}

void free_queue(void) {
  while (!is_empty()) {
    dequeue();
  }
}

int main(void) {
  enqueue(10);
  enqueue(20);
  enqueue(30);

  printf("Removendo: %d\n", dequeue());
  printf("Removendo: %d\n", dequeue());
  printf("Removendo: %d\n", dequeue());

  free_queue();
  return 0;
}
