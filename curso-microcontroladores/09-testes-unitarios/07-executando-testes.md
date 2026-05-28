# 07-executando-testes

Vamos aprender as diferentes maneiras de executar testes Unity.

## Opção 1: Compilação manual (mais simples)

Para projetos pequenos, compilar na mão é rápido.

### Passo 1: Compilar

```bash
cd test

gcc -I. \
    -I../src \
    -DTEST \
    test_motor.c \
    ../src/motor/motor.c \
    mock_arduino.c \
    Unity/src/unity.c \
    -o test_motor
```

Explicação:
- `-I.` - Incluir diretório atual (headers do projeto)
- `-I../src` - Incluir pasta src (seus headers)
- `-DTEST` - Define a macro TEST (se seu código usar `#ifdef TEST`)
- `test_motor.c` - Seu arquivo de teste
- `../src/motor/motor.c` - Implementação que está testando
- `mock_arduino.c` - Mocks do Arduino
- `Unity/src/unity.c` - Framework Unity
- `-o test_motor` - Nome do executável

### Passo 2: Executar

```bash
./test_motor
```

### Resultado

```
test_motor_inicializa_pinos...PASS
test_motor_inicializa_velocidade_zero...PASS
test_motor_para_ambos...PASS
test_motor_para_escreve_pwm_zero...PASS

-----------------------
4 Tests 4 Passed 0 Failed
-----------------------
```

## Opção 2: Script bash (mais automatizado)

Para rodar múltiplos testes, use um script.

Crie `test/run_tests.sh`:

```bash
#!/bin/bash

# Cores para output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Diretório do script
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$DIR"

echo "=========================================="
echo "Compilando e rodando testes..."
echo "=========================================="

# Compilar test_motor
echo "Compilando test_motor..."
gcc -I. -I../src -DTEST \
    test_motor.c \
    ../src/motor/motor.c \
    mock_arduino.c \
    Unity/src/unity.c \
    -o test_motor

if [ $? -ne 0 ]; then
    echo -e "${RED}Erro ao compilar test_motor${NC}"
    exit 1
fi

# Compilar test_sensores
echo "Compilando test_sensores..."
gcc -I. -I../src -DTEST \
    test_sensores.c \
    ../src/sensores/sensores.c \
    mock_arduino.c \
    Unity/src/unity.c \
    -o test_sensores

if [ $? -ne 0 ]; then
    echo -e "${RED}Erro ao compilar test_sensores${NC}"
    exit 1
fi

echo ""
echo "=========================================="
echo "Rodando testes..."
echo "=========================================="

# Rodar testes
echo ""
echo "--- Test Motor ---"
./test_motor
RESULT1=$?

echo ""
echo "--- Test Sensores ---"
./test_sensores
RESULT2=$?

echo ""
echo "=========================================="
if [ $RESULT1 -eq 0 ] && [ $RESULT2 -eq 0 ]; then
    echo -e "${GREEN}✓ Todos os testes passaram!${NC}"
    exit 0
else
    echo -e "${RED}✗ Alguns testes falharam${NC}"
    exit 1
fi
```

Para usar:

```bash
chmod +x test/run_tests.sh
./test/run_tests.sh
```

## Opção 3: CMake (mais profissional)

Para projetos maiores, CMake automatiza tudo.

Crie `test/CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(SeguidorTests)

# Adicionar Unity como library
add_library(unity STATIC
    Unity/src/unity.c
)
target_include_directories(unity PUBLIC Unity/src)

# Função auxiliar para criar testes
function(add_test_suite test_name test_file source_files)
    add_executable(${test_name}
        ${test_file}
        ${source_files}
        mock_arduino.c
    )
    target_include_directories(${test_name} PRIVATE . ../src)
    target_link_libraries(${test_name} unity)
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

# Criar testes
add_test_suite(test_motor 
    test_motor.c 
    ../src/motor/motor.c
)

add_test_suite(test_sensores 
    test_sensores.c 
    ../src/sensores/sensores.c
)

add_test_suite(test_pid 
    test_pid.c 
    ../src/pid/pid.c
)

# Habilitar testes
enable_testing()
```

Para usar:

```bash
cd test
mkdir -p build
cd build
cmake ..
make
make test
```

## Opção 4: Makefile (tradicional)

Se preferir Makefile:

Crie `test/Makefile`:

```makefile
CC = gcc
CFLAGS = -I. -I../src -DTEST -Wall -g
SOURCES_UNITY = Unity/src/unity.c
SOURCES_MOTOR = ../src/motor/motor.c mock_arduino.c
SOURCES_SENSORES = ../src/sensores/sensores.c mock_arduino.c

TESTS = test_motor test_sensores

all: $(TESTS)

test_motor: test_motor.c $(SOURCES_MOTOR) $(SOURCES_UNITY)
	$(CC) $(CFLAGS) $^ -o $@

test_sensores: test_sensores.c $(SOURCES_SENSORES) $(SOURCES_UNITY)
	$(CC) $(CFLAGS) $^ -o $@

run: all
	@echo "=== Test Motor ==="
	@./test_motor
	@echo ""
	@echo "=== Test Sensores ==="
	@./test_sensores

clean:
	rm -f $(TESTS)

.PHONY: all run clean
```

Para usar:

```bash
make -C test run
```

## Opção 5: Arduino IDE com teste

Se quiser testar no Arduino mesmo (mais lento):

```cpp
// seguidor-principal.ino

// Incluir na seção de setup
void setup() {
    Serial.begin(9600);
    
    #ifdef TESTE_UNITARIO
        runTests();
    #else
        normalSetup();
    #endif
}

void runTests(void) {
    Serial.println("Iniciando testes...");
    
    test_motor_inicializa();
    test_motor_para();
    test_motor_velocidade();
    
    Serial.println("Testes finalizados!");
}

void test_motor_inicializa(void) {
    inicializarMotor();
    if (getVelocidade() == 0) {
        Serial.println("✓ test_motor_inicializa");
    } else {
        Serial.println("✗ test_motor_inicializa");
    }
}
```

Problema: Lento, não é recomendado.

## Recomendação

| Projeto | Recomendação |
|---------|-------------|
| Pequeno (<5 testes) | Script bash simples |
| Médio (5-20 testes) | Script bash com múltiplos testes |
| Grande (>20 testes) | CMake ou Makefile |

## Integração contínua

Você pode rodar testes automaticamente no git:

Crie `.github/workflows/tests.yml`:

```yaml
name: Unit Tests

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    
    steps:
    - uses: actions/checkout@v2
    
    - name: Compile and run tests
      run: |
        cd test
        mkdir -p build
        cd build
        cmake ..
        make
        make test
```

Agora, a cada push, os testes rodam automaticamente.

