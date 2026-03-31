#include <stdio.h>

int linear_search(int a[], int n, int target) {
  for (int i = 0; i < n; i++) {
    if (a[i] == target) {
      return i;
    }
  }
  return -1;
}

int binary_search(int a[], int n, int target) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (a[middle] == target) {
      return middle;
    } else if (a[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1;
}

int main(void) {
  int data[] = {2, 4, 6, 8, 10, 12};
  int n = sizeof(data) / sizeof(data[0]);

  int target = 8;
  int index_linear = linear_search(data, n, target);
  printf("Busca linear: índice %d\n", index_linear);

  int index_binary = binary_search(data, n, target);
  printf("Busca binária: índice %d\n", index_binary);

  return 0;
}
