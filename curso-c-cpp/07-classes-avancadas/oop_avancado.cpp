#include <iostream>
#include <string>

class Robo
{
public:
  Robo(const std::string &nome)
      : nome(nome) {}

  virtual void status() const
  {
    std::cout << nome << " é um robô genérico" << "\n";
  }

  virtual ~Robo() {}

protected:
  std::string nome;
};

class RoboSeguidor : public Robo
{
public:
  RoboSeguidor(const std::string &nome, int ganho)
      : Robo(nome), ganho(ganho) {}

  void status() const override
  {
    std::cout << nome << " é um robô seguidor com ganho " << ganho << "\n";
  }

private:
  int ganho;
};

void relatorio(const Robo &rob)
{
  rob.status();
}

int main()
{
  Robo roboGenerico("Genérico");
  RoboSeguidor roboSeguidor("Seguidor", 7);

  relatorio(roboGenerico);
  relatorio(roboSeguidor);

  return 0;
}
