# 07-estruturas-de-controle

Condicionais e laços em C e C++.
Este tópico apresenta como tomar decisões e repetir ações usando estruturas de controle.

## O que você vai aprender

- Como usar `if`, `else` e `else if`.
- Como combinar condições com operadores lógicos.
- Como executar laços com `while` e `for`.
- Como usar variáveis otimizadas para guardar resultados.
- Como interpretar o ciclo de vida de um loop.

## Tipagem e variáveis otimizadas

Escolher o tipo correto melhora a eficiência do programa.
Use `unsigned` quando o valor nunca for negativo.
Use `short` em vez de `int` quando o intervalo for pequeno, especialmente em sistemas embarcados.

Exemplo em C de variáveis otimizadas:

```c
#include <stdio.h>
#include <stdint.h>

int main(void) {
  unsigned char quantidade = 10; // 0 a 255
  short temperatura = 25;        // intervalos pequenos
  int diferenca = 5;

  printf("Quantidade: %u\n", quantidade);
  printf("Temperatura: %d\n", temperatura);
  printf("Diferença: %d\n", diferenca);
  return 0;
}
```

No C++, você pode usar `bool` para condições e `constexpr` para valores fixos.

## Estruturas condicionais: `if` / `else`

As estruturas condicionais decidem qual bloco de código será executado.

Sintaxe básica:

```c
if (condicao) {
  // instruções quando verdadeiro
} else {
  // instruções quando falso
}
```

Exemplo:

```c
#include <stdio.h>

int main(void) {
  int idade = 19;

  if (idade > 18) {
    printf("É maior de idade\n");
  } else {
    printf("Não é maior de idade\n");
  }

  return 0;
}
```

### `else if`

Use `else if` para testar várias condições em sequência.

```c
if (idade >= 18 && idade < 60) {
  printf("Adulto\n");
} else if (idade >= 60) {
  printf("Idoso\n");
} else {
  printf("Menor de idade\n");
}
```

## Operadores relacionais e lógicos

Operadores relacionais:

- `>` maior que
- `<` menor que
- `>=` maior ou igual
- `<=` menor ou igual
- `==` igual
- `!=` diferente

Operadores lógicos:

- `&&` e lógico
- `||` ou lógico
- `!` negação

Exemplo em C++:

```cpp
#include <iostream>

int main() {
  int idade = 25;
  bool trabalho = true;

  if (idade >= 18 && trabalho) {
    std::cout << "Pode trabalhar legalmente" << std::endl;
  }

  if (!trabalho) {
    std::cout << "Precisa procurar emprego" << std::endl;
  }

  return 0;
}
```

## Laços: `while` e `for`

Laços repetem um bloco de código enquanto uma condição for verdadeira.

### `while`

```c
int i = 0;
while (i < 10) {
  printf("%d", i);
  i = i + 1;
}
```

Esse laço continua até que `i` deixe de ser menor que 10.

### `for`

```c
for (int i = 0; i < 10; i = i + 1) {
  printf("%d", i);
}
```

O `for` é útil quando existe uma variável de controle com inicialização, condição e incremento.

## Exemplo em C

```c
#include <stdio.h>

int main(void) {
  int soma = 0;

  for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
      soma += i;
    }
  }

  printf("Soma dos pares de 1 a 10: %d\n", soma);
  return 0;
}
```

## Exemplo em C++

```cpp
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
```

## Como compilar

1. Abra `controle.c` ou `controle.cpp`.
2. Compile com:

```bash
gcc controle.c -o controle_c
./controle_c
```

```bash
g++ controle.cpp -o controle_cpp
./controle_cpp
```

## Exercícios

- Altere o exemplo para somar apenas os números ímpares.
- Crie um `if` que diferencie números positivos, negativos e zero.
- Use um `for` para preencher um array com os primeiros 10 números pares.
- Converta o exemplo em C para C++ usando `std::cout`.
