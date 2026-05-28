# 03-frameworks

Existem vários frameworks para testar C/C++.
Escolhemos **Unity** porque é pequeno, leve e perfeito para embarcados.

## Frameworks disponíveis

| Framework | Melhor para | Tamanho | Dificuldade |
|-----------|------------|--------|------------|
| **Unity** | Embarcados, Arduino | 📦 Pequeno | ⭐ Fácil |
| **ArduinoUnit** | Arduino IDE | 📦 Pequeno | ⭐ Fácil |
| **Google Test** | Projetos grandes | 📦📦📦 Grande | ⭐⭐⭐ Difícil |
| **CppUTest** | C/C++ embarcado | 📦📦 Médio | ⭐⭐ Médio |

## Por que Unity?

### Pequeno
Unity é uma única biblioteca de ~700 linhas.
Cabe em qualquer máquina.

### Fácil de usar
```c
#include "unity.h"

void test_exemplo(void) {
    TEST_ASSERT_EQUAL_INT(5, 2 + 3);
}
```

Pronto. Sem configuração complicada.

### Funciona em qualquer lugar
- Computador (Windows, Linux, Mac)
- Arduino
- Embedded Linux
- Qualquer sistema com compilador C

### Funciona com C puro
Muitos frameworks precisam de C++.
Unity funciona com C puro (melhor para embarcados).

## Comparação

### Google Test (GTest)

**Exemplo:**
```cpp
#include <gtest/gtest.h>

TEST(MathTest, Somar) {
    EXPECT_EQ(5, 2 + 3);
}
```

**Vantagens:**
- Muito poderoso
- Grande comunidade
- Muitas features

**Desvantagens:**
- Pesado (centenas de MB)
- Compilação lenta
- Requer C++
- Overkill para pequenos projetos

**Quando usar:** Projetos grandes em C++.

### ArduinoUnit

**Exemplo:**
```cpp
#include <ArduinoUnit.h>

test(soma) {
    assertEqual(5, 2 + 3);
}

void loop() {
    Test::run();
}
```

**Vantagens:**
- Funciona na Arduino IDE
- Simples
- Baixo overhead

**Desvantagens:**
- Menos features
- Comunidade pequena
- Roda apenas no Arduino

**Quando usar:** Se quer testar direto na Arduino IDE.

### CppUTest

**Exemplo:**
```cpp
#include <CppUTest/TestHarness.h>

TEST_GROUP(Math) {
    // Setup
};

TEST(Math, Soma) {
    CHECK_EQUAL(5, 2 + 3);
}
```

**Vantagens:**
- Bom para C/C++
- Features intermediárias
- Boa comunidade

**Desvantagens:**
- Mais complicado que Unity
- Menos leve que Unity

**Quando usar:** Projetos C/C++ embarcados maiores.

### Unity

**Exemplo:**
```c
#include "unity.h"

void test_soma(void) {
    TEST_ASSERT_EQUAL_INT(5, 2 + 3);
}
```

**Vantagens:**
- Leve (700 linhas)
- Simples
- C puro
- Rápido
- Funciona em qualquer lugar

**Desvantagens:**
- Menos features que GTest
- Comunidade menor que GTest

**Quando usar:** Projetos Arduino, embarcados, qualquer coisa pequena.

## Nossa escolha: Unity

Para este projeto de Arduino/Seguidor, usamos **Unity** porque:

1. **É leve** - Cabe em qualquer sistema
2. **É C puro** - Compatível com código Arduino
3. **Funciona no computador** - Você testa sem hardware
4. **Simples** - Aprende em 5 minutos
5. **Documentado** - Bom material online

## Funções principais do Unity

```c
// Assertions básicas
TEST_ASSERT_EQUAL_INT(esperado, resultado);
TEST_ASSERT_EQUAL_FLOAT(esperado, resultado);
TEST_ASSERT_TRUE(condicao);
TEST_ASSERT_FALSE(condicao);
TEST_ASSERT_NULL(ponteiro);
TEST_ASSERT_NOT_NULL(ponteiro);
TEST_ASSERT_MESSAGE(condicao, "Mensagem de erro");

// Comparações
TEST_ASSERT_LESS_THAN(limite, valor);
TEST_ASSERT_GREATER_THAN(limite, valor);
TEST_ASSERT_LESS_THAN_OR_EQUAL(limite, valor);
TEST_ASSERT_GREATER_THAN_OR_EQUAL(limite, valor);

// Arrays
TEST_ASSERT_EQUAL_INT_ARRAY(esperado, resultado, tamanho);
TEST_ASSERT_EQUAL_MEMORY(esperado, resultado, tamanho);

// Setup e Teardown
void setUp(void) {
    // Executado antes de CADA teste
}

void tearDown(void) {
    // Executado depois de CADA teste
}
```

## Como rodar testes com Unity

Simples:

```bash
# Compilar
gcc -I. test_motor.c motor.c mock_arduino.c unity.c -o test_motor

# Executar
./test_motor
```

Pronto!

## Próximo passo

Vamos aprender a fazer setup do Unity.

