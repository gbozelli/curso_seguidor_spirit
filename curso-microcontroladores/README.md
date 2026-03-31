# curso-microcontroladores

Curso básico de microcontroladores com foco em código para Arduino.
Este módulo explica a estrutura de um sketch e como controlar sinais físicos com software.

## O que você vai aprender

- A estrutura de um programa Arduino.
- O papel de `setup()` e `loop()`.
- Como configurar pinos digitais e analógicos.
- Como usar máquinas de estado e flags.
- Como incluir bibliotecas comuns.

## Organização do curso

- `01-estrutura-arduino`: primeiras linhas de código, `setup()` e `loop()`.
- `02-maquinas-estados-flags`: controle de modos e flags para evitar repetições.
- `03-io-digital-analogica`: leitura de botões, sensores e saída PWM.
- `04-bibliotecas-comuns`: uso de bibliotecas como Servo.

## Como estudar

1. Abra o `README.md` do tópico.
2. Leia a explicação completa.
3. Abra o arquivo `.ino` correspondente.
4. Compile e envie o sketch para a placa.
5. Teste funcionando e faça pequenas alterações.

## Ferramentas necessárias

- Placa Arduino ou compatível.
- Cabo USB.
- Arduino IDE ou PlatformIO.
- Componentes básicos como LED, resistor, botão e potenciômetro.

## Conceitos principais

- `setup()`: executado uma vez após ligar a placa.
- `loop()`: executado repetidamente enquanto a placa estiver ligada.
- `pinMode()`: define o modo do pino (`INPUT`, `OUTPUT`, `INPUT_PULLUP`).
- `digitalRead()`: lê um valor digital.
- `digitalWrite()`: escreve um valor digital.
- `analogRead()`: lê um valor analógico.
- `analogWrite()`: escreve um sinal PWM.

## Dicas de prática

- Use resistores ao trabalhar com LEDs.
- Teste cada componente separadamente.
- Faça o circuito com cuidado antes de enviar o código.
- Se o código não funcionar, revise as conexões e mensagens do compilador.

## Referência

- Livro: "Getting Started with Arduino" de Massimo Banzi.

## Observação

Este módulo trata da parte de software.
Ele não aprofunda a eletrônica, mas mostra como usar o Arduino para ler e escrever sinais.
