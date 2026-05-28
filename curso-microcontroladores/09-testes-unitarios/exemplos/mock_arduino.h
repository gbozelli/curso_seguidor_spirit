// mock_arduino.h
// Simulação das funções do Arduino para testes no computador

#ifndef MOCK_ARDUINO_H
#define MOCK_ARDUINO_H

#include <stdint.h>

// ========== CONSTANTES ==========

// Níveis digitais
#define HIGH 1
#define LOW 0

// Modos de pino
#define OUTPUT 1
#define INPUT 0
#define INPUT_PULLUP 2

// Pinos do projeto Seguidor
#define PIN_MOTOR_ESQ_FRENTE 25
#define PIN_MOTOR_ESQ_TRAS 26
#define PIN_MOTOR_DIR_FRENTE 27
#define PIN_MOTOR_DIR_TRAS 28

// Canais PWM
#define CANAL_ESQ 0
#define CANAL_DIR 1

// ========== ESTRUTURA DE ESTADO ==========

// Rastreia chamadas e estado das funções mock
typedef struct {
    // Contadores de chamadas
    int pinMode_calls;
    int digitalWrite_calls;
    int ledcWrite_calls;
    
    // Últimos valores
    int last_pin;
    int last_value;
    int last_channel;
    
    // Histórico de pinos configurados
    int pins_configured[32];
} MockState;

// Instância global do estado
extern MockState mock_state;

// ========== FUNÇÕES MOCK ==========

// Reseta todos os mocks para estado inicial
void resetMocks(void);

// Configura modo de um pino (INPUT, OUTPUT, etc)
void pinMode(int pin, int mode);

// Escreve nível digital em um pino (HIGH, LOW)
void digitalWrite(int pin, int value);

// Escreve valor PWM em um canal (0-255)
void ledcWrite(int channel, int value);

// Configura frequência do PWM
void ledcSetup(int channel, int freq, int resolution);

// Anexa pino a um canal PWM
void ledcAttachPin(int pin, int channel);

#endif
