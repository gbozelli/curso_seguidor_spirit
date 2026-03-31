# 01-introducao

Introdução à programação em C.
Este tópico mostra a estrutura básica de um programa e como ele é compilado e executado.

## Estrutura de um programa em C

Um programa em C, comumente, terá a seguinte estrutura:

```c
#include <stdio.h>

int main() {
  // instruções
  return 0;
}
```

- `#include <stdio.h>` importa uma biblioteca com código pronto.
- `int main()` define a função principal.
- As chaves `{}` delimitam o início e o fim do programa.
- `return 0;` indica que o programa terminou corretamente.

## Bibliotecas em C

As bibliotecas são conjuntos de código pronto que facilitam a vida do programador.
Na base, vamos importar código para realizar tarefas específicas.
A biblioteca padrão de C é a `stdio.h`.
Ela permite usar as funções `printf()` e `scanf()`, que são entrada e saída.

Não se preocupe com a implementação dessas funções agora.
O importante é saber que elas existem e que servem para ler e escrever dados.

## O código do exemplo

```c
#include <stdio.h>

int main() {
  printf("Estou estudando C!");
  return 0;
}
```

- `#include <stdio.h>` importa a biblioteca padrão de entrada e saída.
- O `#` indica ao compilador que essa linha é uma diretiva de pré-processamento.
- `printf()` imprime uma mensagem na tela.
- O ponto e vírgula `;` separa comandos e indica o fim de uma instrução.

## O que faz `printf()`

A função `printf()` é usada para exibir texto no monitor.
Ela recebe uma string entre parênteses e mostra essa informação na saída do programa.
Usar `printf()` é uma forma de saída do programa.

## O que faz `return 0;`

A linha `return 0;` é uma convenção que indica ao sistema operacional que o programa terminou com sucesso.
Se retornar outro número, indica que algo deu errado.
Sempre coloque essa linha ao final de `main()`.

## Usando `scanf()`

Até agora, vimos apenas saída de texto.
Para ler dados digitados pelo usuário, existe a função `scanf()`.
Ela representa a entrada do programa.

Exemplo:

```c
#include <stdio.h>

int main() {
  char nome[100];
  printf("Digite seu nome: ");
  scanf("%s", nome);
  printf("Nome: %s", nome);
  return 0;
}
```

- `scanf()` permite ler dados do teclado.
- O primeiro argumento indica o formato do dado.
- O segundo argumento é onde o valor será armazenado.

Essa função será estudada em detalhes mais adiante.
Por enquanto, é suficiente saber que ela existe e serve para entrada de dados.

## Como compilar e executar

1. Salve o arquivo como `exemplo.c`.
2. No terminal, digite:

```bash
gcc exemplo.c -o exemplo
```

3. Execute com:

```bash
./exemplo
```

## Próximo passo

No próximo tópico veremos tipos de dados e variáveis em C.
Vamos usar números, caracteres e constantes para construir programas mais úteis.
- "A Tour of C++" - Bjarne Stroustrup.
- Documentacao do `gcc` e `g++`.
