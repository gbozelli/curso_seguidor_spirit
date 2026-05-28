// exemplo_motor.c
// Implementação simplificada de motor para teste

#include "exemplo_motor.h"
#include "mock_arduino.h"

// Estado global dos motores
static int velocidade_esq = 0;
static int velocidade_dir = 0;

void inicializarMotor(void) {
    // Configura pinos como output
    pinMode(PIN_MOTOR_ESQ_FRENTE, OUTPUT);
    pinMode(PIN_MOTOR_ESQ_TRAS, OUTPUT);
    pinMode(PIN_MOTOR_DIR_FRENTE, OUTPUT);
    pinMode(PIN_MOTOR_DIR_TRAS, OUTPUT);
    
    // Setup do PWM
    ledcSetup(CANAL_ESQ, 5000, 8);
    ledcSetup(CANAL_DIR, 5000, 8);
    
    // Anexa pinos aos canais PWM
    ledcAttachPin(PIN_MOTOR_ESQ_FRENTE, CANAL_ESQ);
    ledcAttachPin(PIN_MOTOR_DIR_FRENTE, CANAL_DIR);
    
    // Velocidade inicial é zero
    velocidade_esq = 0;
    velocidade_dir = 0;
}

void pararMotores(void) {
    velocidade_esq = 0;
    velocidade_dir = 0;
    
    ledcWrite(CANAL_ESQ, 0);
    ledcWrite(CANAL_DIR, 0);
}

void controlarMotor(int velocidadeEsq, int velocidadeDir) {
    // Limita velocidade entre 0 e VEL_MAX
    if (velocidadeEsq < 0) velocidadeEsq = 0;
    if (velocidadeEsq > VEL_MAX) velocidadeEsq = VEL_MAX;
    
    if (velocidadeDir < 0) velocidadeDir = 0;
    if (velocidadeDir > VEL_MAX) velocidadeDir = VEL_MAX;
    
    // Armazena velocidades
    velocidade_esq = velocidadeEsq;
    velocidade_dir = velocidadeDir;
    
    // Escreve nos canais PWM
    ledcWrite(CANAL_ESQ, velocidadeEsq);
    ledcWrite(CANAL_DIR, velocidadeDir);
}

int getVelocidadeMotorEsquerdo(void) {
    return velocidade_esq;
}

int getVelocidadeMotorDireito(void) {
    return velocidade_dir;
}
