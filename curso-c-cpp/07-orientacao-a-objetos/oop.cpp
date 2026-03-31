#include <iostream>
#include <string>

class Robo
{
public:
  Robo(const std::string &nome, int velocidade)
      : nome(nome), velocidade(velocidade) {}

  void mover() const
  {
    std::cout << nome << " esta em movimento a " << velocidade << "\n";
  }

protected:
  std::string nome;
  int velocidade;
};

class RoboSeguidor : public Robo
{
public:
  RoboSeguidor(const std::string &nome, int velocidade, int ganho)
      : Robo(nome, velocidade), ganho(ganho) {}

  void ajustarPID() const
  {
    std::cout << "Ajuste PID com ganho " << ganho << "\n";
  }

private:
  int ganho;
};

int main()
{
  RoboSeguidor robo("Xerapo", 80, 5);
  robo.mover();
  robo.ajustarPID();
  return 0;
}
