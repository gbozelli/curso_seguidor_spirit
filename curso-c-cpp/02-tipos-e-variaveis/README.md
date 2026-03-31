# 02-tipos-e-variaveis

Tipos e variáveis em C e C++.
Neste tópico mostramos como representar informações na memória usando os principais tipos de dados.

## O que você vai aprender

- Tipos básicos em C e C++.
- Como declarar variáveis.
- Como usar constantes.
- Diferença entre números inteiros e números de ponto flutuante.

## Tipos de dados básicos

Em C e C++, cada variável precisa ter um tipo.
Os tipos comuns são:

- `int`: números inteiros, sem casas decimais.
- `float`: números com casas decimais, precisão simples.
- `double`: números com casas decimais, precisão maior.
- `char`: um único caractere.
- `const`: valor fixo que não muda.

## Exemplo em C

```c
#include <stdio.h>

int main(void) {
  int idade = 20;
  float peso = 70.5f;
  char letra = 'A';

  printf("Idade: %d\n", idade);
  printf("Peso: %.1f\n", peso);
  printf("Letra: %c\n", letra);
  return 0;
}
```

- A declaração `int idade` cria uma variável inteira chamada `idade`.
- `peso` é um float.
- `letra` é um caractere entre aspas simples.
- `printf` imprime cada valor no terminal.

## Exemplo em C++

```cpp
#include <iostream>

int main() {
  int idade = 20;
  double peso = 70.5;
  char letra = 'A';
  const int ANO = 2026;

  std::cout << "Idade: " << idade << "\n";
  std::cout << "Peso: " << peso << "\n";
  std::cout << "Letra: " << letra << "\n";
  std::cout << "Ano: " << ANO << "\n";
  return 0;
}
```

- `const int ANO = 2026;` define uma constante.
- O valor de `ANO` não pode ser alterado após a declaração.

## Como compilar e testar

1. Compile o exemplo em C:

```bash
gcc tipos.c -o tipos_c
./tipos_c
```

2. Compile o exemplo em C++:

```bash
g++ tipos.cpp -o tipos_cpp
./tipos_cpp
```

3. Observe a saída e compare os resultados.

## Dicas importantes

- Use `int` para contagens e índices.
- Use `double` quando precisar de maior precisão.
- Use `float` se quiser economizar memória.
- `char` armazena apenas um caractere.
- Em C, strings são arrays de `char` terminados com `\0`.

## Tipagem: variáveis otimizadas

Para escrever programas eficientes, escolha o menor tipo que atende ao problema.
Por exemplo, se você precisa armazenar apenas valores entre 0 e 255, `unsigned char` ou `uint8_t` usam menos memória do que `int`.

Quando a aplicação exige números inteiros não negativos, prefira `unsigned`.
Quando precisa de maior alcance, use `long` ou `long long`.

Exemplo:

```c
#include <stdio.h>
#include <stdint.h>

int main(void) {
  unsigned char idade = 20;   // 0 a 255
  short conta = 300;          // menor uso de memória que int em alguns sistemas
  int total = 1000;

  printf("Idade: %u\n", idade);
  printf("Conta: %d\n", conta);
  printf("Total: %d\n", total);
  return 0;
}
```

Em C++, use `bool` para verdadeiro/falso e `long long` quando precisar de inteiros muito grandes.
Variáveis otimizadas ajudam a reduzir o uso de memória e a melhorar o desempenho em sistemas embarcados.

## Exercícios

- Adicione uma variável `bool` em C++ e imprima seu valor.
- Defina uma constante para velocidade máxima e use-a em um cálculo.
- Altere a variável `idade` e execute novamente.

## Referências

- Livro: "The C Programming Language" de Kernighan e Ritchie.
- Livro: "A Tour of C++" de Bjarne Stroustrup.
