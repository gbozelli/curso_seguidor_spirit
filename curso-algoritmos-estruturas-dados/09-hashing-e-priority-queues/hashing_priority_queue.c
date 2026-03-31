#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 11
#define HEAP_SIZE 20

typedef struct {
  int key;
  int value;
  int used;
} HashEntry;

HashEntry hash_table[HASH_SIZE];

int hash_function(int key) {
  return key % HASH_SIZE;
}

void hash_insert(int key, int value) {
  int index = hash_function(key);
  while (hash_table[index].used) {
    index = (index + 1) % HASH_SIZE;
  }
  hash_table[index].key = key;
  hash_table[index].value = value;
  hash_table[index].used = 1;
}

int hash_search(int key) {
  int index = hash_function(key);
  int start = index;
  while (hash_table[index].used) {
    if (hash_table[index].key == key) {
      return hash_table[index].value;
    }
    index = (index + 1) % HASH_SIZE;
    if (index == start) break;
  }
  return -1;
}

typedef struct {
  int data[HEAP_SIZE];
  int size;
} PriorityQueue;

void pq_init(PriorityQueue *pq) {
  pq->size = 0;
}

void pq_push(PriorityQueue *pq, int value) {
  if (pq->size >= HEAP_SIZE) return;
  int i = pq->size++;
  pq->data[i] = value;
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (pq->data[parent] < pq->data[i]) {
      int tmp = pq->data[parent];
      pq->data[parent] = pq->data[i];
      pq->data[i] = tmp;
      i = parent;
    } else {
      break;
    }
  }
}

int pq_pop(PriorityQueue *pq) {
  if (pq->size == 0) return -1;
  int top = pq->data[0];
  pq->size--;
  pq->data[0] = pq->data[pq->size];
  int i = 0;
  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < pq->size && pq->data[left] > pq->data[largest]) largest = left;
    if (right < pq->size && pq->data[right] > pq->data[largest]) largest = right;
    if (largest != i) {
      int tmp = pq->data[i];
      pq->data[i] = pq->data[largest];
      pq->data[largest] = tmp;
      i = largest;
    } else {
      break;
    }
  }
  return top;
}

int main(void) {
  hash_insert(10, 100);
  hash_insert(21, 210);
  hash_insert(32, 320);

  printf("Hash busca 21: %d\n", hash_search(21));
  printf("Hash busca 99: %d\n", hash_search(99));

  PriorityQueue pq;
  pq_init(&pq);
  pq_push(&pq, 5);
  pq_push(&pq, 20);
  pq_push(&pq, 15);

  printf("Priority queue pop: %d\n", pq_pop(&pq));
  printf("Priority queue pop: %d\n", pq_pop(&pq));
  printf("Priority queue pop: %d\n", pq_pop(&pq));

  return 0;
}
