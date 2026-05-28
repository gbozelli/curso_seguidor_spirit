# 04-setup-unity

Configurar Unity é fácil.
Você só precisa de 3 coisas: baixar Unity, criar a pasta de testes, e começar.

## Passo 1: Baixar Unity

```bash
# Na pasta do seu projeto
cd seguidor-projeto
mkdir -p test
cd test
git clone https://github.com/ThrowTheSwitch/Unity.git
cd ..
```

Pronto. Unity está em `seguidor-projeto/test/Unity/`.

## Passo 2: Estrutura de pastas

Organize seu projeto assim:

```
seguidor-projeto/
├── src/
│   ├── motor/
│   │   ├── motor.h
│   │   └── motor.c
│   ├── pid/
│   │   ├── pid.h
│   │   └── pid.c
│   ├── sensores/
│   │   ├── sensores.h
│   │   └── sensores.c
│   └── config/
│       └── config.h
│
├── test/
│   ├── Unity/                  # Framework (git clone)
│   ├── mock_arduino.h          # Simula Arduino
│   ├── mock_arduino.c
│   ├── test_motor.c            # Testes do motor
│   ├── test_pid.c              # Testes do PID
│   ├── test_sensores.c         # Testes dos sensores
│   └── run_tests.sh            # Script para rodar
│
├── CMakeLists.txt              # (opcional) Build automático
└── README.md
```

## Passo 3: Criar seu primeiro teste

Crie um arquivo `test/test_motor.c`:

```c
#include "unity.h"
#include "../src/motor/motor.h"

void setUp(void) {
    // Executado antes de cada teste
    // Coloque inicializações aqui
}

void tearDown(void) {
    // Executado depois de cada teste
    // Coloque limpeza aqui
}

void test_motor_inicializa(void) {
    // Teste 1: Motor inicializa sem erros
    TEST_ASSERT_TRUE(inicializarMotor() == 0);
}

void test_motor_para(void) {
    // Teste 2: Motor para corretamente
    inicializarMotor();
    pararMotores();
    TEST_ASSERT_EQUAL_INT(0, getVelocidade());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_motor_inicializa);
    RUN_TEST(test_motor_para);
    return UNITY_END();
}
```

## Passo 4: Compilar e rodar

### Opção A: Compilar manualmente

```bash
cd test

# Compilar
gcc -I. -I../src -o test_motor test_motor.c \
    ../src/motor/motor.c \
    mock_arduino.c \
    Unity/src/unity.c

# Rodar
./test_motor
```

### Opção B: Script bash

Crie `test/run_tests.sh`:

```bash
#!/bin/bash

cd "$(dirname "$0")"

echo "Compilando testes..."
gcc -I. -I../src \
    test_motor.c \
    ../src/motor/motor.c \
    mock_arduino.c \
    Unity/src/unity.c \
    -o test_motor

echo "Rodando testes..."
./test_motor
```

Depois:

```bash
chmod +x test/run_tests.sh
./test/run_tests.sh
```

### Opção C: CMake (mais profissional)

Crie `test/CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(SeguidorTests)

# Adicionar Unity
add_library(unity STATIC
    Unity/src/unity.c
)
target_include_directories(unity PUBLIC Unity/src)

# Função para criar testes
function(add_motor_test)
    add_executable(test_motor
        test_motor.c
        ../src/motor/motor.c
        mock_arduino.c
    )
    target_include_directories(test_motor PRIVATE . ../src)
    target_link_libraries(test_motor unity)
    
    add_test(NAME motor COMMAND test_motor)
endfunction()

add_motor_test()
```

Para rodar:

```bash
cd test/build
cmake ..
make
./test_motor
```

## Passo 5: Mock do Arduino

Seu código Arduino provavelmente usa funções como `pinMode`, `digitalWrite`, etc.
Para testar no computador, você precisa simular essas funções.

Crie `test/mock_arduino.h`:

```c
#ifndef MOCK_ARDUINO_H
#define MOCK_ARDUINO_H

// Simular valores do Arduino
#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0

// Pinos do seu projeto
#define PIN_MOTOR_ESQ_FRENTE 25
#define PIN_MOTOR_ESQ_TRAS 26
#define PIN_MOTOR_DIR_FRENTE 27
#define PIN_MOTOR_DIR_TRAS 28

// Canais PWM
#define CANAL_ESQ 0
#define CANAL_DIR 1

// Estrutura para rastrear o que foi chamado
typedef struct {
    int pinMode_calls;
    int digitalWrite_calls;
    int ledcWrite_calls;
    int last_pin;
    int last_value;
} MockState;

extern MockState mock_state;

void resetMocks(void);
void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
void ledcWrite(int channel, int value);

#endif
```

Crie `test/mock_arduino.c`:

```c
#include "mock_arduino.h"

MockState mock_state = {0};

void resetMocks(void) {
    mock_state.pinMode_calls = 0;
    mock_state.digitalWrite_calls = 0;
    mock_state.ledcWrite_calls = 0;
    mock_state.last_pin = 0;
    mock_state.last_value = 0;
}

void pinMode(int pin, int mode) {
    mock_state.pinMode_calls++;
    mock_state.last_pin = pin;
}

void digitalWrite(int pin, int value) {
    mock_state.digitalWrite_calls++;
    mock_state.last_pin = pin;
    mock_state.last_value = value;
}

void ledcWrite(int channel, int value) {
    mock_state.ledcWrite_calls++;
    mock_state.last_value = value;
}
```

## Resultado

Se tudo deu certo, ao rodar os testes você vê:

```
test_motor_inicializa...PASS
test_motor_para...PASS

-----------------------
2 Tests 2 Passed 0 Failed
-----------------------
```

Pronto! Setup completo.

## Próximo passo

Vamos criar uma suite de testes de verdade.

