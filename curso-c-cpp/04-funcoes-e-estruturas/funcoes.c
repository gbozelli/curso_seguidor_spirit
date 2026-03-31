#include <stdio.h>

int soma(int a, int b)
{
  return a + b;
}

int main(void)
{
  int resultado = soma(7, 5);
  printf("Resultado: %d\n", resultado);
  return 0;
}
