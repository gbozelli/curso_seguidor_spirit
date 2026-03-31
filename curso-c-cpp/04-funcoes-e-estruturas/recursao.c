#include <stdio.h>

int fatorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * fatorial(n - 1);
}

int main(void) {
  int valor = 5;
  printf("Fatorial de %d = %d\n", valor, fatorial(valor));
  return 0;
}
