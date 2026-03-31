#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void bubble_sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}

void selection_sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min_index]) {
        min_index = j;
      }
    }
    int tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
  }
}

void insertion_sort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

void merge(int a[], int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int *L = malloc(n1 * sizeof(int));
  int *R = malloc(n2 * sizeof(int));

  for (int i = 0; i < n1; i++) L[i] = a[left + i];
  for (int j = 0; j < n2; j++) R[j] = a[middle + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k++] = L[i++];
    } else {
      a[k++] = R[j++];
    }
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];

  free(L);
  free(R);
}

void merge_sort(int a[], int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;
    merge_sort(a, left, middle);
    merge_sort(a, middle + 1, right);
    merge(a, left, middle, right);
  }
}

int partition(int a[], int left, int right) {
  int pivot = a[right];
  int i = left - 1;
  for (int j = left; j < right; j++) {
    if (a[j] <= pivot) {
      i++;
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }
  int tmp = a[i + 1];
  a[i + 1] = a[right];
  a[right] = tmp;
  return i + 1;
}

void quick_sort(int a[], int left, int right) {
  if (left < right) {
    int pivot_index = partition(a, left, right);
    quick_sort(a, left, pivot_index - 1);
    quick_sort(a, pivot_index + 1, right);
  }
}

void heapify(int a[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && a[left] > a[largest]) largest = left;
  if (right < n && a[right] > a[largest]) largest = right;
  if (largest != i) {
    int tmp = a[i];
    a[i] = a[largest];
    a[largest] = tmp;
    heapify(a, n, largest);
  }
}

void heap_sort(int a[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    int tmp = a[0];
    a[0] = a[i];
    a[i] = tmp;
    heapify(a, i, 0);
  }
}

int main(void) {
  int data[] = {9, 5, 2, 7, 1, 3};
  int n = sizeof(data) / sizeof(data[0]);

  int arr1[] = {9, 5, 2, 7, 1, 3};
  bubble_sort(arr1, n);
  printf("Bubble sort: "); print_array(arr1, n);

  int arr2[] = {9, 5, 2, 7, 1, 3};
  selection_sort(arr2, n);
  printf("Selection sort: "); print_array(arr2, n);

  int arr3[] = {9, 5, 2, 7, 1, 3};
  insertion_sort(arr3, n);
  printf("Insertion sort: "); print_array(arr3, n);

  int arr4[] = {9, 5, 2, 7, 1, 3};
  merge_sort(arr4, 0, n - 1);
  printf("Merge sort: "); print_array(arr4, n);

  int arr5[] = {9, 5, 2, 7, 1, 3};
  quick_sort(arr5, 0, n - 1);
  printf("Quick sort: "); print_array(arr5, n);

  int arr6[] = {9, 5, 2, 7, 1, 3};
  heap_sort(arr6, n);
  printf("Heap sort: "); print_array(arr6, n);

  return 0;
}
