#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE 10

int queue[MAX_QUEUE];
int front = 0;
int rear = 0;
int count = 0;

bool is_empty(void) {
  return count == 0;
}

bool is_full(void) {
  return count == MAX_QUEUE;
}

void enqueue(int value) {
  if (is_full()) {
    printf("Erro: fila cheia\n");
    return;
  }
  queue[rear] = value;
  rear = (rear + 1) % MAX_QUEUE;
  count++;
}

int dequeue(void) {
  if (is_empty()) {
    printf("Erro: fila vazia\n");
    return -1;
  }
  int value = queue[front];
  front = (front + 1) % MAX_QUEUE;
  count--;
  return value;
}

int main(void) {
  enqueue(1);
  enqueue(2);
  enqueue(3);

  printf("Removendo: %d\n", dequeue());
  printf("Removendo: %d\n", dequeue());
  printf("Removendo: %d\n", dequeue());

  return 0;
}
