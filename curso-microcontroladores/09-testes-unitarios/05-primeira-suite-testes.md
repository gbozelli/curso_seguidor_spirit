# 05-primeira-suite-testes

Agora vamos criar uma suite de testes real para o módulo de motor.

## Análise da função

Vamos testar a função `controlarMotor()`:

```c
// motor.h
void inicializarMotor(void);
void pararMotores(void);
void controlarMotor(int velocidadeEsq, int velocidadeDir);
int getVelocidadeMotorEsquerdo(void);
int getVelocidadeMotorDireito(void);
```

Essa função:
- Recebe duas velocidades (esquerda e direita)
- Limita velocidade entre 0 e 255
- Controla dois motores independentemente

## Casos de teste

Vamos testar:

1. Inicialização
2. Parando motores
3. Velocidade máxima
4. Velocidade negativa (deve virar 0)
5. Velocidade acima do máximo
6. Motores independentes
7. Valores extremos

## Arquivo completo: test_motor.c

```c
#include "unity.h"
#include "mock_arduino.h"
#include "../src/motor/motor.h"

// Executado ANTES de cada teste
void setUp(void) {
    resetMocks();
    inicializarMotor();
}

// Executado DEPOIS de cada teste
void tearDown(void) {
    pararMotores();
}

// ========== TESTES DE INICIALIZAÇÃO ==========

void test_motor_inicializa_pinos(void) {
    // Motor deve chamar pinMode() para cada pino
    TEST_ASSERT_GREATER_THAN(0, mock_state.pinMode_calls);
    TEST_ASSERT_MESSAGE(
        mock_state.pinMode_calls >= 4,
        "Motor deve configurar pelo menos 4 pinos"
    );
}

void test_motor_inicializa_velocidade_zero(void) {
    // Ao inicializar, velocidade deve ser 0
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorDireito());
}

// ========== TESTES DE PARAR ==========

void test_motor_para_ambos(void) {
    // Após pararMotores(), ambas velocidades devem ser 0
    controlarMotor(100, 150);
    pararMotores();
    
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorDireito());
}

void test_motor_para_escreve_pwm_zero(void) {
    // pararMotores() deve escrever 0 no PWM
    pararMotores();
    TEST_ASSERT_EQUAL_INT(0, mock_state.last_value);
}

// ========== TESTES DE VELOCIDADE NORMAL ==========

void test_motor_velocidade_50_esquerdo(void) {
    controlarMotor(50, 0);
    TEST_ASSERT_EQUAL_INT(50, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorDireito());
}

void test_motor_velocidade_50_direito(void) {
    controlarMotor(0, 50);
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(50, getVelocidadeMotorDireito());
}

void test_motor_velocidades_diferentes(void) {
    controlarMotor(100, 200);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(200, getVelocidadeMotorDireito());
}

// ========== TESTES DE LIMITE MÁXIMO ==========

void test_motor_velocidade_maxima_255(void) {
    controlarMotor(255, 255);
    TEST_ASSERT_EQUAL_INT(255, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(255, getVelocidadeMotorDireito());
}

void test_motor_limita_acima_maximo(void) {
    // Se passar 500, deve limitar em 255
    controlarMotor(500, 500);
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidadeMotorDireito());
}

void test_motor_limita_esquerdo_acima_maximo(void) {
    controlarMotor(1000, 100);
    TEST_ASSERT_EQUAL_INT(255, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorDireito());
}

// ========== TESTES DE VALORES NEGATIVOS ==========

void test_motor_velocidade_negativa_vira_zero(void) {
    controlarMotor(-50, -100);
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorDireito());
}

void test_motor_velocidade_negativa_esquerdo(void) {
    controlarMotor(-100, 50);
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(50, getVelocidadeMotorDireito());
}

// ========== TESTES DE INDEPENDÊNCIA ==========

void test_motor_esquerdo_independente_de_direito(void) {
    // Mudar esquerdo não deve afetar direito
    controlarMotor(100, 200);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
    
    controlarMotor(50, 200);
    TEST_ASSERT_EQUAL_INT(50, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(200, getVelocidadeMotorDireito());
}

void test_motor_direito_independente_de_esquerdo(void) {
    controlarMotor(100, 200);
    TEST_ASSERT_EQUAL_INT(200, getVelocidadeMotorDireito());
    
    controlarMotor(100, 150);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(150, getVelocidadeMotorDireito());
}

// ========== TESTES DE CASOS EXTREMOS ==========

void test_motor_ambos_zero(void) {
    controlarMotor(0, 0);
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorDireito());
}

void test_motor_alternancia(void) {
    // Alternar velocidades várias vezes
    for (int i = 0; i < 10; i++) {
        controlarMotor(50 * i, 100 - 5 * i);
    }
    // Mesmo após mudar várias vezes, deve estar consistente
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidadeMotorDireito());
}

// ========== MAIN ==========

int main(void) {
    UNITY_BEGIN();
    
    // Testes de inicialização
    RUN_TEST(test_motor_inicializa_pinos);
    RUN_TEST(test_motor_inicializa_velocidade_zero);
    
    // Testes de parar
    RUN_TEST(test_motor_para_ambos);
    RUN_TEST(test_motor_para_escreve_pwm_zero);
    
    // Testes de velocidade normal
    RUN_TEST(test_motor_velocidade_50_esquerdo);
    RUN_TEST(test_motor_velocidade_50_direito);
    RUN_TEST(test_motor_velocidades_diferentes);
    
    // Testes de limite máximo
    RUN_TEST(test_motor_velocidade_maxima_255);
    RUN_TEST(test_motor_limita_acima_maximo);
    RUN_TEST(test_motor_limita_esquerdo_acima_maximo);
    
    // Testes de valores negativos
    RUN_TEST(test_motor_velocidade_negativa_vira_zero);
    RUN_TEST(test_motor_velocidade_negativa_esquerdo);
    
    // Testes de independência
    RUN_TEST(test_motor_esquerdo_independente_de_direito);
    RUN_TEST(test_motor_direito_independente_de_esquerdo);
    
    // Testes de casos extremos
    RUN_TEST(test_motor_ambos_zero);
    RUN_TEST(test_motor_alternancia);
    
    return UNITY_END();
}
```

## Resultado esperado

```
test_motor_inicializa_pinos...PASS
test_motor_inicializa_velocidade_zero...PASS
test_motor_para_ambos...PASS
test_motor_para_escreve_pwm_zero...PASS
test_motor_velocidade_50_esquerdo...PASS
test_motor_velocidade_50_direito...PASS
test_motor_velocidades_diferentes...PASS
test_motor_velocidade_maxima_255...PASS
test_motor_limita_acima_maximo...PASS
test_motor_limita_esquerdo_acima_maximo...PASS
test_motor_velocidade_negativa_vira_zero...PASS
test_motor_velocidade_negativa_esquerdo...PASS
test_motor_esquerdo_independente_de_direito...PASS
test_motor_direito_independente_de_esquerdo...PASS
test_motor_ambos_zero...PASS
test_motor_alternancia...PASS

-----------------------
16 Tests 16 Passed 0 Failed
-----------------------
```

## Dicas

**1. Nome descritivo ajuda**

Nomes como `test_motor_limita_esquerdo_acima_maximo()` deixam claro o que está sendo testado.

**2. Agrupe testes logicamente**

Organize testes em seções com comentários (inicialização, parar, etc).

**3. Teste limites**

Sempre teste 0, máximo, negativo, overflow.

**4. Teste independência**

Se dois motores devem ser independentes, test isso explicitamente.

**5. Use setUp/tearDown**

Isso garante que cada teste começa limpo.

## Próximo passo

Vamos aprender boas práticas para escrever testes melhores.

