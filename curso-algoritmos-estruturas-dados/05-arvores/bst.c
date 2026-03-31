#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *left;
  struct Node *right;
} Node;

Node *create_node(int key) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL) return NULL;
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node *insert(Node *root, int key) {
  if (root == NULL) {
    return create_node(key);
  }
  if (key < root->key) {
    root->left = insert(root->left, key);
  } else if (key > root->key) {
    root->right = insert(root->right, key);
  }
  return root;
}

Node *search(Node *root, int key) {
  if (root == NULL || root->key == key) {
    return root;
  }
  if (key < root->key) {
    return search(root->left, key);
  }
  return search(root->right, key);
}

void inorder(Node *root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ", root->key);
  inorder(root->right);
}

void free_tree(Node *root) {
  if (root == NULL) return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main(void) {
  Node *root = NULL;
  int values[] = {20, 10, 30, 5, 15, 25, 35};

  for (int i = 0; i < 7; i++) {
    root = insert(root, values[i]);
  }

  printf("Travessia inorder: ");
  inorder(root);
  printf("\n");

  int target = 15;
  Node *found = search(root, target);
  if (found != NULL) {
    printf("Valor %d encontrado na árvore.\n", target);
  } else {
    printf("Valor %d não encontrado.\n", target);
  }

  free_tree(root);
  return 0;
}
