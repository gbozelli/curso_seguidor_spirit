#include <iostream>
#include <string>

int main() {
  char nome_c[10] = "Spirit";
  char apresentacao[20] = "Curso C++";

  std::string nome = "Spirit";
  std::string saudacao = "Ola, ";

  std::cout << apresentacao << std::endl;
  std::cout << "Nome em char[]: " << nome_c << std::endl;
  std::cout << saudacao + nome << std::endl;
  std::cout << "Tamanho de std::string: " << nome.size() << std::endl;
  std::cout << "Tamanho do array char: " << sizeof(nome_c) << std::endl;
  return 0;
}
