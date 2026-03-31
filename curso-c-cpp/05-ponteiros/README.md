# 05-ponteiros

Este tópico apresenta o conceito de ponteiros em C, um dos pilares da linguagem.
Ele explica como armazenar endereços de memória, acessar valores indiretamente e usar ponteiros em funções.

## O que são ponteiros

Um ponteiro é uma variável cujo valor é o endereço de outra variável.
Em vez de guardar diretamente um número ou texto, ele guarda o local onde esse dado está armazenado.

- Sintaxe básica:
  - `int *p;` significa que `p` é um ponteiro para um inteiro.
  - `p = &x;` atribui o endereço de `x` ao ponteiro `p`.
  - `*p` acessa o valor armazenado no endereço apontado por `p`.

## Por que usar ponteiros

- Passar grandes estruturas para funções sem copiar todos os bytes.
- Modificar variáveis dentro de funções através de parâmetros por referência.
- Trabalhar com arrays e strings de forma eficiente.
- Interagir com hardware e memória direta em sistemas embarcados.

## Aritmética de ponteiros

Em C, é possível somar e subtrair ponteiros para navegar em arrays.
Por exemplo, `p + 1` aponta para o próximo elemento do mesmo tipo.

## Exemplo de uso em funções

Ponteiros são muito usados para escrever funções que modificam variáveis de fora do escopo local.

## Arquivos deste tópico

- `ponteiros.c`: exemplo de declarações, endereços e passagem por referência.
