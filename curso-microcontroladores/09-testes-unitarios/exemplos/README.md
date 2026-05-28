# Exemplos de código

Esta pasta contém exemplos completos prontos para usar como referência.

## Arquivos

- **mock_arduino.h** - Interface dos mocks do Arduino
- **mock_arduino.c** - Implementação dos mocks
- **exemplo_motor.h** - Interface do módulo de motor
- **exemplo_motor.c** - Implementação simplificada do motor
- **test_exemplo_motor.c** - Suite completa de testes do motor
- **run_exemplo.sh** - Script bash para compilar e rodar os exemplos

## Como usar

1. Copie os arquivos para sua pasta de testes
2. Adapte o `exemplo_motor.c` para sua implementação real
3. Use `test_exemplo_motor.c` como referência para seus próprios testes

## Para rodar o exemplo

```bash
chmod +x run_exemplo.sh
./run_exemplo.sh
```

## O que esperar

```
test_motor_inicializa_pinos...PASS
test_motor_inicializa_velocidade_zero...PASS
test_motor_para_ambos...PASS
test_motor_velocidade_50...PASS
test_motor_velocidades_diferentes...PASS
test_motor_limita_velocidade_maxima...PASS
test_motor_velocidade_negativa_vira_zero...PASS
test_motor_motores_independentes...PASS

-----------------------
8 Tests 8 Passed 0 Failed
-----------------------
```

## Próximos passos

- Adicione mais testes para seus outros módulos (sensores, PID, etc)
- Crie mocks mais avançados se precisar simular comportamentos complexos
- Integre com CI/CD para rodar testes automaticamente

