#include <iostream>
#include <string>

struct Robo
{
  std::string nome;
  int velocidade;
};

void mostrarRobo(const Robo &r)
{
  std::cout << "Robo: " << r.nome << "\n";
  std::cout << "Velocidade: " << r.velocidade << "\n";
}

int main()
{
  Robo robo;
  robo.nome = "Xerapo";
  robo.velocidade = 80;
  mostrarRobo(robo);
  return 0;
}
