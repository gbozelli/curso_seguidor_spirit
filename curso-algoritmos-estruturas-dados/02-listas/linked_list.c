#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *create_node(int value) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL) return NULL;
  node->value = value;
  node->next = NULL;
  return node;
}

void push_front(Node **head, int value) {
  Node *node = create_node(value);
  node->next = *head;
  *head = node;
}

void remove_value(Node **head, int value) {
  Node *current = *head;
  Node *previous = NULL;

  while (current != NULL) {
    if (current->value == value) {
      if (previous == NULL) {
        *head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void print_list(Node *head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }
  printf("NULL\n");
}

void free_list(Node *head) {
  while (head != NULL) {
    Node *next = head->next;
    free(head);
    head = next;
  }
}

int main(void) {
  Node *head = NULL;

  // Inserção de valores na lista ligada
  push_front(&head, 5);
  push_front(&head, 10);
  push_front(&head, 20);
  printf("Lista após inserções:\n");
  print_list(head);

  // Remover um valor específico
  remove_value(&head, 10);
  printf("Lista após remover 10:\n");
  print_list(head);

  free_list(head);
  return 0;
}
