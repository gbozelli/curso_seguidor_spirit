# 03-arrays-e-strings

Arrays e strings em C e C++.
Este tópico mostra como guardar várias informações em um único bloco de memória e como manipular texto.

## O que você vai aprender

- Como declarar arrays de tipos diferentes.
- Como um array é representado na memória.
- Por que acessar fora do índice é perigoso.
- Como strings funcionam como arrays de `char`.
- Diferenças entre `char[]` e `std::string`.

## Arrays de tipos diferentes

Um array em C agrupa valores contíguos do mesmo tipo.
O tamanho é fixo no momento da declaração.

Exemplos de declaração:

- `int valores[5]`
- `float temperaturas[4]`
- `double distancias[3]`
- `char letras[5]`

### Estrutura de array na memória

Cada elemento é armazenado em posições consecutivas.
O índice indica a posição do elemento, começando em zero.

```text
int valores[5] = {10, 20, 30, 40, 50};

+-----+-----+-----+-----+-----+
| 10  | 20  | 30  | 40  | 50  |
+-----+-----+-----+-----+-----+
  0     1     2     3     4
```

### Exemplos em C

```c
#include <stdio.h>

int main(void) {
  int valores[5] = {10, 20, 30, 40, 50};
  float temperaturas[4] = {21.5f, 22.0f, 22.7f, 21.9f};
  double distancias[3] = {1.23, 2.34, 3.45};
  char letras[5] = {'S', 'P', 'I', 'R', '\0'};

  for (int i = 0; i < 5; i++) {
    printf("valores[%d] = %d\n", i, valores[i]);
  }

  printf("Temperatura[2] = %.1f\n", temperaturas[2]);
  printf("Distancia[1] = %.2f\n", distancias[1]);
  printf("String char: %s\n", letras);

  int index = 5;
  if (index >= 0 && index < 5) {
    printf("valores[%d] = %d\n", index, valores[index]);
  } else {
    printf("Erro: índice %d fora do limite\n", index);
  }

  return 0;
}
```

### Acesso fora do índice

Quando você usa um índice fora do limite, o comportamento é indefinido.
Isso significa que o programa pode ler lixo de memória, travar ou produzir valores errados.
Nunca confie em valores fora do intervalo declarado.

## O que são strings

Strings são sequências de caracteres.
Em C, strings são arrays de `char` terminados em `\0`.

### Exemplo em C

```c
#include <stdio.h>

int main(void) {
  char nome[10] = "Spirit";
  char frase[20] = "Curso C";

  printf("Nome: %s\n", nome);
  printf("Tamanho do array: %zu\n", sizeof(nome));
  return 0;
}
```

### Exemplo em C++

```cpp
#include <iostream>
#include <string>

int main() {
  std::string nome = "Spirit";
  std::string saudacao = "Ola, ";

  std::cout << saudacao + nome << std::endl;
  std::cout << "Tamanho: " << nome.size() << std::endl;
  return 0;
}
```

- `char nome[10]` reserva 10 bytes e termina com `\0`.
- `std::string` gerencia memória automaticamente.

## Como testar

1. Compile o arquivo C:

```bash
gcc arrays.c -o arrays_c
./arrays_c
```

2. Compile o arquivo C++:

```bash
g++ strings.cpp -o strings_cpp
./strings_cpp
```

3. Observe como os elementos são acessados e exibidos.

## Observações

- O tamanho do array em C é fixo.
- Evite acessar índices fora do limite.
- Em C, a string termina com `\0`.
- Em C++, `std::string` simplifica o tratamento de texto.

## Exercícios

- Crie um segundo array e some os valores das mesmas posições.
- No exemplo em C++, leia uma palavra do usuário e exiba o texto.
- Use `while` em vez de `for` para imprimir o array em C.
