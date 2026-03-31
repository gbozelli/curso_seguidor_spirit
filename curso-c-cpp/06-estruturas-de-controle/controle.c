#include <stdio.h>

int main(void) {
  int soma = 0;

  for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
      soma += i;
    }
  }

  printf("Soma dos pares de 1 a 10: %d\n", soma);
  return 0;
}
