#include <stdio.h>

int main(void) {
  int valores[5] = {10, 20, 30, 40, 50};
  float temperaturas[4] = {21.5f, 22.0f, 22.7f, 21.9f};
  double distancias[3] = {1.234, 2.345, 3.456};
  char letras[5] = {'S', 'P', 'I', 'R', '\0'};

  valores[2] = 35;

  for (int i = 0; i < 5; i++) {
    printf("valores[%d] = %d\n", i, valores[i]);
  }

  printf("temperaturas[2] = %.1f\n", temperaturas[2]);
  printf("distancias[1] = %.3f\n", distancias[1]);
  printf("letras: %s\n", letras);

  int indice = 5;
  if (indice >= 0 && indice < 5) {
    printf("valores[%d] = %d\n", indice, valores[indice]);
  } else {
    printf("Erro: índice %d fora do limite\n", indice);
  }

  return 0;
}
