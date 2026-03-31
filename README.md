# curso_seguidor_spirit

Este repositório é um material de treinamento para novos integrantes da equipe Spirit.
A intenção é fornecer uma base sólida com exemplos e explicações claras em programação C e C++, desenvolvimento de código para Arduino e um projeto prático de seguidor de linha.

## Estrutura do repositório

O conteúdo está dividido em três áreas principais:

- `curso-c-cpp`: fundamentos de C e C++. Inclui desde o primeiro programa até orientação a objetos.
- `curso-microcontroladores`: código para Arduino, com base em estrutura de sketch, leitura e escrita de sinais, e uso de bibliotecas.
- `seguidor-de-linha`: projeto prático de robô seguidor de linha, com sensores QTR, controle PD/PID e mapeamento de pista.
- `curso-algoritmos-estruturas-dados`: curso de algoritmos e estruturas de dados baseado no repositório `AlgoritmosEstruturasDadosC`.

Cada área está organizada em subpastas por tópico.
Cada tópico tem um `README.md` com explicações, passo a passo e exemplos de código.

## Como estudar

1. Escolha a área que deseja aprender.
2. Abra o `README.md` do tópico antes de executar o código.
3. Leia a explicação do conceito e os objetivos do tópico.
4. Execute os exemplos e observe o comportamento.
5. Faça pequenas modificações para avaliar o resultado.
6. Só avance depois de entender os conceitos do tópico atual.

## Como usar os exemplos

- Em C:
  ```bash
gcc arquivo.c -o arquivo
./arquivo
  ```
- Em C++:
  ```bash
g++ arquivo.cpp -o arquivo
./arquivo
  ```
- Em Arduino:
  1. Abra o sketch no Arduino IDE ou no PlatformIO.
  2. Selecione a placa e a porta correta.
  3. Compile e envie o código.
  4. Use o monitor serial para ver saídas de depuração.- Em LaTeX:
  1. Abra `curso_seguidor_spirit.tex`.
  2. Compile com `pdflatex curso_seguidor_spirit.tex`.
## Dicas técnicas

- Leia as mensagens de erro do compilador com atenção.
- Comente e descomente trechos para testar variações.
- Use nomes de variáveis claros e descritivos.
- Faça anotações dos conceitos antes de seguir adiante.

## Referências básicas

- Livro: "The C Programming Language" de Brian Kernighan e Dennis Ritchie.
- Livro: "A Tour of C++" de Bjarne Stroustrup.
- Livro: "Getting Started with Arduino" de Massimo Banzi.

## Finalizando

Este material serve como base inicial e como referência para novos integrantes.
Ele pode ser expandido com exercícios, exemplos adicionais e anotações mais profundas.
Se encontrar alguma inconsistência, atualize o material com explicações claras e exemplos revisados.
