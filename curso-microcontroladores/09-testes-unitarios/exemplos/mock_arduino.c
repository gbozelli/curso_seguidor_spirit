// mock_arduino.c
// Implementação das funções mock

#include "mock_arduino.h"
#include <string.h>

// Instância global do estado
MockState mock_state = {0};

void resetMocks(void) {
    mock_state.pinMode_calls = 0;
    mock_state.digitalWrite_calls = 0;
    mock_state.ledcWrite_calls = 0;
    mock_state.last_pin = 0;
    mock_state.last_value = 0;
    mock_state.last_channel = 0;
    
    // Reset histórico de pinos
    memset(mock_state.pins_configured, 0, sizeof(mock_state.pins_configured));
}

void pinMode(int pin, int mode) {
    mock_state.pinMode_calls++;
    mock_state.last_pin = pin;
    
    // Registra que este pino foi configurado
    if (pin < 32) {
        mock_state.pins_configured[pin] = mode;
    }
}

void digitalWrite(int pin, int value) {
    mock_state.digitalWrite_calls++;
    mock_state.last_pin = pin;
    mock_state.last_value = value;
}

void ledcWrite(int channel, int value) {
    mock_state.ledcWrite_calls++;
    mock_state.last_channel = channel;
    mock_state.last_value = value;
}

void ledcSetup(int channel, int freq, int resolution) {
    // Mock vazio - apenas rastreia se foi chamado
    (void)channel;
    (void)freq;
    (void)resolution;
}

void ledcAttachPin(int pin, int channel) {
    // Mock vazio - apenas rastreia se foi chamado
    (void)pin;
    (void)channel;
}
