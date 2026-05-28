// test_exemplo_motor.c
// Exemplo completo de teste de motor usando Unity

#include "unity.h"
#include "mock_arduino.h"
#include "exemplo_motor.h"

// ========== SETUP E TEARDOWN ==========

void setUp(void) {
    // Executado ANTES de cada teste
    resetMocks();
    inicializarMotor();
}

void tearDown(void) {
    // Executado DEPOIS de cada teste
    pararMotores();
}

// ========== TESTES ==========

void test_motor_inicializa_pinos(void) {
    // Verifica se pinMode foi chamado
    TEST_ASSERT_GREATER_THAN(0, mock_state.pinMode_calls);
}

void test_motor_inicializa_velocidade_zero(void) {
    // Após inicializar, velocidades devem ser 0
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorDireito());
}

void test_motor_para_ambos(void) {
    // Controla motor e depois para
    controlarMotor(100, 150);
    pararMotores();
    
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorDireito());
}

void test_motor_velocidade_50(void) {
    // Testa velocidade normal
    controlarMotor(50, 50);
    TEST_ASSERT_EQUAL_INT(50, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(50, getVelocidadeMotorDireito());
}

void test_motor_velocidades_diferentes(void) {
    // Testa que motores são independentes
    controlarMotor(100, 200);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(200, getVelocidadeMotorDireito());
}

void test_motor_limita_velocidade_maxima(void) {
    // Testa limitação acima de 255
    controlarMotor(500, 500);
    TEST_ASSERT_LESS_THAN_OR_EQUAL(VEL_MAX, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_LESS_THAN_OR_EQUAL(VEL_MAX, getVelocidadeMotorDireito());
}

void test_motor_velocidade_negativa_vira_zero(void) {
    // Testa que velocidades negativas viram 0
    controlarMotor(-50, -100);
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorDireito());
}

void test_motor_motores_independentes(void) {
    // Testa que mudar um motor não afeta o outro
    controlarMotor(100, 100);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorDireito());
    
    controlarMotor(100, 50);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
    TEST_ASSERT_EQUAL_INT(50, getVelocidadeMotorDireito());
}

// ========== MAIN ==========

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_motor_inicializa_pinos);
    RUN_TEST(test_motor_inicializa_velocidade_zero);
    RUN_TEST(test_motor_para_ambos);
    RUN_TEST(test_motor_velocidade_50);
    RUN_TEST(test_motor_velocidades_diferentes);
    RUN_TEST(test_motor_limita_velocidade_maxima);
    RUN_TEST(test_motor_velocidade_negativa_vira_zero);
    RUN_TEST(test_motor_motores_independentes);
    
    return UNITY_END();
}
