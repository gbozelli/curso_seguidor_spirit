#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode {
  int value;
  struct StackNode *next;
} StackNode;

StackNode *top = NULL;

bool is_empty(void) {
  return top == NULL;
}

void push(int value) {
  StackNode *node = malloc(sizeof(StackNode));
  if (node == NULL) return;
  node->value = value;
  node->next = top;
  top = node;
}

int pop(void) {
  if (is_empty()) {
    printf("Erro: pilha vazia\n");
    return -1;
  }
  StackNode *node = top;
  int value = node->value;
  top = top->next;
  free(node);
  return value;
}

int peek(void) {
  if (is_empty()) {
    printf("Erro: pilha vazia\n");
    return -1;
  }
  return top->value;
}

void free_stack(void) {
  while (!is_empty()) {
    pop();
  }
}

int main(void) {
  push(5);
  push(15);
  push(25);

  printf("Topo da pilha dinâmica: %d\n", peek());
  printf("Removendo: %d\n", pop());

  free_stack();
  return 0;
}
