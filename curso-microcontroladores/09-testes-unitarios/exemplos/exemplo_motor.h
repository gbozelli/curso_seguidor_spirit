// exemplo_motor.h
// Exemplo simplificado de módulo de motor para teste

#ifndef EXEMPLO_MOTOR_H
#define EXEMPLO_MOTOR_H

// Máxima velocidade permitida
#define VEL_MAX 255

// Inicializa o módulo de motor
void inicializarMotor(void);

// Para ambos os motores
void pararMotores(void);

// Controla velocidade de ambos os motores (0-255)
void controlarMotor(int velocidadeEsq, int velocidadeDir);

// Retorna velocidade do motor esquerdo
int getVelocidadeMotorEsquerdo(void);

// Retorna velocidade do motor direito
int getVelocidadeMotorDireito(void);

#endif
