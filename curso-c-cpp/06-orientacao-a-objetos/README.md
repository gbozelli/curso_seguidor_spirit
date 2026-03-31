# 05-orientacao-a-objetos

Orientação a objetos em C++.
Este tópico explica os conceitos centrais da programação orientada a objetos e como aplicá-los em C++.

## O que você vai aprender

- O que é uma classe.
- O que é um objeto.
- Como funcionam construtores.
- Por que usar encapsulamento.
- Como aplicar herança.
- Como usar polimorfismo básico.

## O que é uma classe

Uma classe é o modelo que descreve um tipo de objeto.
Ela define quais dados o objeto guarda e quais ações ele pode executar.

Em C++, uma classe combina:

- atributos: as informações do objeto.
- métodos: as funções que operam sobre essas informações.

## O que é um objeto

Um objeto é uma instância de uma classe.
Quando você cria um objeto, a classe define sua estrutura e comportamento.

Exemplo de classe e objeto:

```cpp
class Robo {
public:
  Robo(const std::string &nome, int velocidade)
      : nome(nome), velocidade(velocidade) {}

  void mover() const {
    std::cout << nome << " está em movimento a " << velocidade << "\n";
  }

private:
  std::string nome;
  int velocidade;
};

int main() {
  Robo robo("Xerapo", 80);
  robo.mover();
  return 0;
}
```

- `Robo` é a classe.
- `robo` é o objeto criado a partir da classe.

## Construtores

O construtor inicializa o objeto.
Ele recebe valores e define o estado inicial.

No exemplo:

```cpp
Robo(const std::string &nome, int velocidade)
    : nome(nome), velocidade(velocidade) {}
```

Essa sintaxe é chamada lista de inicialização.
Ela é eficiente e recomendada para inicializar membros.

## Encapsulamento

Encapsulamento é proteger os detalhes internos da classe.
Ele permite controlar como os dados são acessados.

Em C++, `private` e `public` são usados para isso.

- `private`: os dados só podem ser acessados pela própria classe.
- `public`: os métodos podem ser usados fora da classe.

Exemplo de método para acessar um dado:

```cpp
int getVelocidade() const {
  return velocidade;
}
```

## Herança

Herança é quando uma classe deriva de outra.
A classe derivada recebe atributos e métodos da classe base.

No exemplo:

```cpp
class RoboSeguidor : public Robo {
public:
  RoboSeguidor(const std::string &nome, int velocidade, int ganho)
      : Robo(nome, velocidade), ganho(ganho) {}

  void ajustarPID() const {
    std::cout << "Ajuste PID com ganho " << ganho << "\n";
  }

private:
  int ganho;
};
```

- `RoboSeguidor` herda `Robo`.
- A classe base fornece o comportamento comum.
- A classe derivada adiciona comportamentos específicos.

## Polimorfismo básico

Polimorfismo permite tratar objetos diferentes da mesma forma.
A forma mais simples em C++ é usar métodos virtuais.

Exemplo:

```cpp
class Robo {
public:
  virtual void status() const {
    std::cout << "Robo genérico" << "\n";
  }
  virtual ~Robo() {}
};

class RoboSeguidor : public Robo {
public:
  void status() const override {
    std::cout << "Robo seguidor" << "\n";
  }
};
```

Se você usar um ponteiro para `Robo`, o método correto será chamado de acordo com o objeto real.

## Exemplo completo em C++

```cpp
#include <iostream>
#include <string>

class Robo {
public:
  Robo(const std::string &nome, int velocidade)
      : nome(nome), velocidade(velocidade) {}

  virtual void mover() const {
    std::cout << nome << " está em movimento a " << velocidade << "\n";
  }

  int getVelocidade() const {
    return velocidade;
  }

  virtual ~Robo() {}

protected:
  std::string nome;
  int velocidade;
};

class RoboSeguidor : public Robo {
public:
  RoboSeguidor(const std::string &nome, int velocidade, int ganho)
      : Robo(nome, velocidade), ganho(ganho) {}

  void mover() const override {
    std::cout << nome << " segue a linha a " << velocidade << " com ganho " << ganho << "\n";
  }

  void ajustarPID() const {
    std::cout << "Ajuste PID com ganho " << ganho << "\n";
  }

private:
  int ganho;
};

int main() {
  RoboSeguidor robo("Xerapo", 80, 5);
  robo.mover();
  robo.ajustarPID();
  return 0;
}
```

## Como compilar

1. Abra `oop.cpp`.
2. Compile com:

```bash
g++ oop.cpp -o oop_cpp
./oop_cpp
```

## Por que usar orientação a objetos

- Ajuda a organizar o código em unidades lógicas.
- Permite reaproveitar comportamento.
- Facilita a expansão do programa.
- Torna o código mais fácil de manter.

## Termos importantes

- `class`: define o tipo de objeto.
- `public`: membro acessível fora da classe.
- `protected`: membro acessível por classes derivadas.
- `private`: membro visível apenas dentro da classe.
- `virtual`: permite polimorfismo.
- `override`: indica que o método substitui o da classe base.

## Exercícios

- Adicione o método `frear()` na classe `Robo`.
- Crie uma classe `RoboVelocidade` que herda `Robo`.
- Use um atributo `private` para dados que não devem ser acessados diretamente.
- Modifique `Robo` para incluir `getVelocidade()`.
- Crie outro método virtual e sobrescreva-o em `RoboSeguidor`.

## Referências

- Livro: "A Tour of C++" de Bjarne Stroustrup.
