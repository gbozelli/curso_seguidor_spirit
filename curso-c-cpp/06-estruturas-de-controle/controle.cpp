#include <iostream>

int main() {
  int contador = 0;
  int valor = 1;

  while (valor <= 10) {
    if (valor % 2 != 0) {
      contador++;
    }
    valor++;
  }

  std::cout << "Quantidade de ímpares entre 1 e 10: " << contador << std::endl;
  return 0;
}
