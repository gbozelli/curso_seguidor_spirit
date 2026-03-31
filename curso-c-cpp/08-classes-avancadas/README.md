# 06-classes-avancadas

Classes avançadas e OOP em C++.
Este tópico aprofunda o uso de encapsulamento, construtores, herança e polimorfismo.

## O que você vai aprender

- Como proteger dados com `private` e `protected`.
- Como definir construtores e destrutores.
- Como criar métodos acessores (`get`/`set`).
- Como usar herança e especialização de classes.
- Como ativar polimorfismo com métodos virtuais.
- Como escrever classes mais reutilizáveis.

## Encapsulamento detalhado

Em C++, você deve manter os dados internos escondidos.
Isso evita que outras partes do programa dependam diretamente de variáveis internas.

Use `private` para membros que não podem ser acessados de fora.
Use `protected` para permitir acesso em classes derivadas.
Use `public` para expor apenas o comportamento necessário.

Exemplo:

```cpp
class Motor {
public:
  Motor(int velocidadeInicial)
      : velocidade(velocidadeInicial) {}

  int getVelocidade() const {
    return velocidade;
  }

  void setVelocidade(int valor) {
    if (valor >= 0) {
      velocidade = valor;
    }
  }

private:
  int velocidade;
};
```

## Construtores e destrutores

Construtores inicializam o objeto quando ele é criado.
Destrutores liberam recursos quando o objeto é destruído.

```cpp
class Sensor {
public:
  Sensor(int canal)
      : canal(canal) {
    std::cout << "Sensor criado no canal " << canal << "\n";
  }

  ~Sensor() {
    std::cout << "Sensor destruido\n";
  }

private:
  int canal;
};
```

## Herança e especialização

Herança permite criar classes mais específicas a partir de classes gerais.
Ao herdar com `public`, a classe derivada mantém a interface pública da base.

```cpp
class Robo {
public:
  Robo(const std::string &nome)
      : nome(nome) {}

  virtual void status() const {
    std::cout << nome << " é um robô genérico" << "\n";
  }

protected:
  std::string nome;
};

class RoboSeguidor : public Robo {
public:
  RoboSeguidor(const std::string &nome, int ganho)
      : Robo(nome), ganho(ganho) {}

  void status() const override {
    std::cout << nome << " é um robô seguidor com ganho " << ganho << "\n";
  }

private:
  int ganho;
};
```

## Polimorfismo com métodos virtuais

Polimorfismo permite tratar diferentes objetos como se fossem do mesmo tipo.
Um método `virtual` garante que a versão apropriada do método seja chamada em tempo de execução.

```cpp
void relatorio(const Robo &rob) {
  rob.status();
}
```

Se `rob` for um `RoboSeguidor`, o método `status()` sobrescrito será executado.

## Exemplo completo

```cpp
#include <iostream>
#include <string>

class Robo {
public:
  Robo(const std::string &nome)
      : nome(nome) {}

  virtual void status() const {
    std::cout << nome << " é um robô genérico" << "\n";
  }

  virtual ~Robo() {}

protected:
  std::string nome;
};

class RoboSeguidor : public Robo {
public:
  RoboSeguidor(const std::string &nome, int ganho)
      : Robo(nome), ganho(ganho) {}

  void status() const override {
    std::cout << nome << " é um robô seguidor com ganho " << ganho << "\n";
  }

private:
  int ganho;
};

void relatorio(const Robo &rob) {
  rob.status();
}

int main() {
  Robo roboGenerico("Genérico");
  RoboSeguidor roboSeguidor("Seguidor", 7);

  relatorio(roboGenerico);
  relatorio(roboSeguidor);

  return 0;
}
```

## Como compilar

1. Abra `oop_avancado.cpp`.
2. Compile com:

```bash
g++ oop_avancado.cpp -o oop_avancado
./oop_avancado
```

## Exercícios sugeridos

- Adicione uma classe `RoboExplorador` que herda `Robo`.
- Implemente um método `diagnostico()` virtual na classe base.
- Crie apenas getters públicos, mantendo os atributos privados.
- Experimente trocar `protected` por `private` e veja como isso afeta as classes derivadas.

## Referências

- Livro: "A Tour of C++" de Bjarne Stroustrup.
- Materiais sobre polimorfismo e encapsulamento em C++.
