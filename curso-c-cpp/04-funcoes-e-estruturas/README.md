# 04-funcoes-e-estruturas

Funções e estruturas em C e C++.
Este tópico mostra como dividir o programa em partes menores e como agrupar dados relacionados.

## O que você vai aprender

- Como criar funções em C.
- O que são parâmetros e valores de retorno.
- Como usar `struct` para agrupar informações.
- Como passar estruturas para funções.

## Funções em C

Uma função é um bloco de código que executa uma tarefa específica.
Elas tornam o programa mais organizado e facilitam a reutilização.

Exemplo em C:

```c
#include <stdio.h>

int soma(int a, int b) {
  return a + b;
}

int main(void) {
  int resultado = soma(7, 5);
  printf("Resultado: %d\n", resultado);
  return 0;
}
```

- `int soma(int a, int b)` declara uma função que recebe dois inteiros.
- `return a + b;` devolve o resultado.
- `main()` chama a função `soma`.

## Estruturas em C++

Em C++, `struct` organiza dados relacionados em um único tipo.

Exemplo:

```cpp
#include <iostream>
#include <string>

struct Robo {
  std::string nome;
  int velocidade;
};

void mostrarRobo(const Robo &r) {
  std::cout << "Robo: " << r.nome << "\n";
  std::cout << "Velocidade: " << r.velocidade << "\n";
}

int main() {
  Robo robo;
  robo.nome = "Xerapo";
  robo.velocidade = 80;
  mostrarRobo(robo);
  return 0;
}
```

- `struct Robo` define um tipo com dois campos.
- `mostrarRobo` recebe o `Robo` por referência constante.
- Isso evita cópias desnecessárias.

## Como testar

1. Compile o exemplo em C:

```bash
gcc funcoes.c -o funcoes_c
./funcoes_c
```

2. Compile o exemplo de recursão em C:

```bash
gcc recursao.c -o recursao_c
./recursao_c
```

3. Compile o exemplo em C++:

```bash
g++ estruturas.cpp -o estruturas_cpp
./estruturas_cpp
```

## Funções recursivas

Recursão é quando uma função chama a si mesma para resolver um problema menor.
Cada chamada cria um novo quadro de execução na pilha de chamadas.

O ponto mais importante é o caso base: a condição que encerra a recursão.

```mermaid
flowchart TD
  A[main()] --> B[fatorial(4)]
  B --> C[fatorial(3)]
  C --> D[fatorial(2)]
  D --> E[fatorial(1)]
```

Exemplo em C:

```c
#include <stdio.h>

int fatorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * fatorial(n - 1);
}

int main(void) {
  int valor = 5;
  printf("Fatorial de %d = %d\n", valor, fatorial(valor));
  return 0;
}
```

Recursão é útil para problemas como:

- cálculo de séries matemáticas.
- travessia de árvores.
- divisão e conquista.

## Boa prática

- Cada função deve fazer uma única tarefa.
- Use nomes claros para funções e parâmetros.
- Agrupe dados relacionados em `struct`.
- Evite duplicação de código.

## Exercícios

- Adicione uma função `subtrai` em `funcoes.c`.
- Acrescente o campo `autonomia` em `Robo`.
- Crie uma função que altere a velocidade do robo.

## Referências

- Livro: "The C Programming Language" de Kernighan e Ritchie.
- Livro: "A Tour of C++" de Bjarne Stroustrup.
