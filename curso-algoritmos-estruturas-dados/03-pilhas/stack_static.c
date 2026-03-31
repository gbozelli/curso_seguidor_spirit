#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK 10

int stack[MAX_STACK];
int top = -1;

bool is_empty(void) {
  return top == -1;
}

bool is_full(void) {
  return top == MAX_STACK - 1;
}

void push(int value) {
  if (is_full()) {
    printf("Erro: pilha cheia\n");
    return;
  }
  stack[++top] = value;
}

int pop(void) {
  if (is_empty()) {
    printf("Erro: pilha vazia\n");
    return -1;
  }
  return stack[top--];
}

int peek(void) {
  if (is_empty()) {
    printf("Erro: pilha vazia\n");
    return -1;
  }
  return stack[top];
}

int main(void) {
  push(10);
  push(20);
  push(30);

  printf("Topo da pilha: %d\n", peek());
  printf("Removendo: %d\n", pop());
  printf("Topo agora: %d\n", peek());

  while (!is_empty()) {
    printf("Pop: %d\n", pop());
  }

  return 0;
}
