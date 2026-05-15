# Tarefa Integrada: Sistema de Monitoramento de Sensores com Bluetooth

**Nível**: 8 (Iniciante, 1-2 semanas)  
**Módulos**: 05 (Estrutura de Programas) + 07 (Comunicação Bluetooth)  
**Componentes necessários**: Arduino/ESP32, 3 sensores analógicos (potenciômetros ou similares), LEDs (opcional)  
**Objetivo**: Integrar conceitos de modularização, estruturas de dados e comunicação Bluetooth em um projeto coerente.

---

## 📋 Descrição Geral

Você vai criar um **Sistema de Monitoramento de Sensores** que:
- Lê 3 sensores analógicos em intervalos regulares
- Armazena dados em estruturas organizadas
- Permite calibração via comandos Bluetooth
- Envia telemetria em tempo real para um celular
- Implementa uma máquina de estados simples

Este projeto une conceitos de modularização (funções, structs) com comunicação sem fio, preparando você para projetos mais complexos como o seguidor de linha.

---

## ✅ Requisitos de Implementação

### Item 1: Setup Básico e Estrutura de Dados (3-4 dias)

**Objetivo**: Criar a base do programa com structs e inicializações.

**Tarefas**:
1. Configure o ESP32/Arduino com:
   - Serial USB (115200 baud) para debug local
   - Bluetooth Serial com nome "SensorMonitor"
   - 3 pinos analógicos para sensores (use A0, A1, A2 ou equivalentes)
   - 1 LED de status (estado: ligado/calibrando/pronto)

2. Defina duas estruturas:
   ```cpp
   struct Sensor {
     int pino;
     int valor;        // última leitura
     int minimo;       // valor mínimo (calibração)
     int maximo;       // valor máximo (calibração)
     float normalizacao; // valor normalizado 0-100%
   };

   struct SistemaMonitor {
     Sensor sensores[3];
     bool emCalibracao;
     int estadoLED;
     unsigned long ultimaLeitura;
   };
   ```

3. Implemente `setup()` que:
   - Inicializa Serial USB
   - Inicializa Bluetooth
   - Configura os 3 pinos de sensor como INPUT
   - Configura LED como OUTPUT
   - Inicializa a struct SistemaMonitor com valores padrão

**Teste**: Conecte ao ESP32 via USB. Verifique se mensagens aparecem no Serial Monitor e se o Bluetooth está visível no celular.

---

### Item 2: Mini IPO - Função de Leitura de Sensores (3-4 dias)

**Objetivo**: Implementar a função de entrada (I do IPO) com modularização.

**Tarefas**:
1. Crie a função `lerSensores()`:
   ```cpp
   void lerSensores(SistemaMonitor &sistema) {
     // Leia os 3 sensores
     // Armazene em sistema.sensores[i].valor
     // Normalize para 0-100%
     // NÃO use delay(), use millis() para controle
   }
   ```

2. Implemente normalização:
   - Se sensor está em calibração, range é [mínimo, máximo]
   - Após calibração, normalize: `(valor - minimo) / (maximo - minimo) * 100`
   - Garanta que valores fiquem entre 0-100%

3. Crie a função auxiliar `atualizarStatusLED()`:
   ```cpp
   void atualizarStatusLED(int estado) {
     // LED PISCANDO: calibrando
     // LED LIGADO: pronto
     // LED DESLIGADO: aguardando
   }
   ```

4. No `loop()`, chame `lerSensores()` a cada 50ms usando `millis()` (não use `delay()`)

**Teste**: 
- Conecte potenciômetros aos pinos A0, A1, A2
- Vire os potenciômetros e observe valores no Serial Monitor
- Verifique se normalização funciona corretamente

---

### Item 3: Mini IPO - Processamento de Comandos Bluetooth (3-4 dias)

**Objetivo**: Implementar a função de entrada de comandos (processamento de controle).

**Tarefas**:
1. Crie a função `processarComandosBluetooth()`:
   ```cpp
   void processarComandosBluetooth(SistemaMonitor &sistema) {
     // Leia comandos via SerialBT
     // Processe comandos listados abaixo
   }
   ```

2. Implemente estes comandos:
   - `CALIBRA` → Inicia modo calibração (LED pisca, coleta min/max por 10 segundos)
   - `PRONTO` → Finaliza calibração
   - `STATUS` → Envia status atual via Bluetooth
   - `RESET` → Reseta todas as calibrações
   - `TELEMETRIA ON/OFF` → Ativa/desativa envio automático

3. Valide entrada:
   - Use `readStringUntil('\n')` para ler até quebra de linha
   - Limpe espaços com `trim()`
   - Valide comando antes de executar

**Teste**:
- Abra app "Serial Bluetooth Terminal" no celular
- Pareie com "SensorMonitor"
- Envie `CALIBRA` e vire potenciômetros (LED deve piscar)
- Envie `PRONTO`
- Envie `STATUS`

---

### Item 4: Mini IPO - Telemetria em Tempo Real (3-4 dias)

**Objetivo**: Implementar envio de dados (O do IPO).

**Tarefas**:
1. Crie função `enviarTelemetria()`:
   ```cpp
   void enviarTelemetria(SistemaMonitor &sistema) {
     // Envie formato estruturado via Bluetooth
     // Exemplo:
     // "SENS:1=45.2,2=67.8,3=23.5"
   }
   ```

2. Implemente telemetria a cada 200ms (use `millis()`, não `delay()`)

3. Adicione telemetria extendida (envio menos frequente):
   - Status de calibração
   - Hora de operação (quantos segundos rodando)
   - Temperatura (se disponível) ou battery level simulado

4. Crie função `enviarDebug()` para Serial USB:
   ```cpp
   void enviarDebug(SistemaMonitor &sistema) {
     // Mesmo que telemetria, mas vai para Serial USB
     // Útil para debug sem afastar do computador
   }
   ```

5. No `loop()`, use timers para não bloquear:
   ```cpp
   // No loop()
   if (millis() - ultimaTelemetria > 200) {
     ultimaTelemetria = millis();
     enviarTelemetria(sistema);
   }
   if (millis() - ultimoDebug > 500) {
     ultimoDebug = millis();
     enviarDebug(sistema);
   }
   ```

**Teste**:
- App mostra valores dos 3 sensores em tempo real
- Vire potenciômetros, valores mudam na app
- Serial Monitor também mostra mesmo formato

---

### Item 5: Máquina de Estados e Integração Final (4-5 dias)

**Objetivo**: Organizar lógica em máquina de estados, integrando tudo.

**Tarefas**:
1. Implemente máquina de estados:
   ```cpp
   enum Estado { AGUARDANDO, CALIBRANDO, PRONTO, ERRO };
   
   void atualizarEstado(SistemaMonitor &sistema) {
     // Transições de estado baseadas em eventos
     // AGUARDANDO → CALIBRANDO: recebe CALIBRA
     // CALIBRANDO → PRONTO: recebe PRONTO ou timeout 10s
     // PRONTO → AGUARDANDO: recebe RESET
   }
   ```

2. Refatore o `loop()` para ser limpo:
   ```cpp
   void loop() {
     // Mini IPO 1: ENTRADA - Comandos
     processarComandosBluetooth(sistema);
     
     // Mini IPO 2: ENTRADA - Sensores
     if (/* tempo para ler */) {
       lerSensores(sistema);
     }
     
     // PROCESSAMENTO - Estado
     atualizarEstado(sistema);
     atualizarStatusLED(sistema.estadoLED);
     
     // Mini IPO 3: SAÍDA - Telemetria
     if (/* tempo para enviar */) {
       enviarTelemetria(sistema);
     }
     if (/* tempo para debug */) {
       enviarDebug(sistema);
     }
   }
   ```

3. Adicione proteção contra perda de comunicação:
   - Se Bluetooth desconecta, LED muda estado
   - Sistema continua lendo sensores (não bloqueia)

4. Testes de validação:
   - **Teste 1**: Calibração → sensores normalizam corretamente
   - **Teste 2**: Telemetria → app recebe dados a cada 200ms
   - **Teste 3**: Comandos → sistema responde a todos os 5 comandos
   - **Teste 4**: Sem bloquear → LED pisca regularmente mesmo durante telemetria
   - **Teste 5**: LED de status → muda conforme estado

**Teste Final**:
- Sistema roda 10+ minutos sem travamento
- Todos 5 comandos funcionam
- Telemetria consistente
- Pode desconectar/reconectar Bluetooth sem problemas

---

## 📚 Conceitos Aplicados

| Item | Módulo 05 | Módulo 07 |
|------|-----------|----------|
| 1 | Structs, organização | Início Bluetooth |
| 2 | Funções, mini IPO (entrada) | - |
| 3 | Funções, processamento | Receber comandos BT |
| 4 | Mini IPO (saída) | Enviar telemetria BT |
| 5 | Máquina de estados, integração | Bluetooth como periférico |

---

## 🎯 Critérios de Aceitação

- [ ] Código compila sem erros
- [ ] Bluetooth funciona (pareado e recebe comandos)
- [ ] 3 sensores leem corretamente
- [ ] Telemetria envia a cada 200ms via Bluetooth
- [ ] Todos 5 comandos funcionam
- [ ] LED de status muda conforme estado
- [ ] `loop()` não bloqueia (usa `millis()`, não `delay()`)
- [ ] Código está modularizado em funções bem definidas
- [ ] Structs armazenam dados logicamente
- [ ] Sistema roda por 10+ minutos sem travamento

---

## 💡 Dicas

1. **Comece pelo Item 1**: não avance sem que o Bluetooth funcione.
2. **Teste cada função isoladamente**: escreva `Serial.println()` para debug.
3. **Use `millis()` sempre**: `delay()` é inimigo de Bluetooth responsivo.
4. **Manter git**: faça commits após cada item completado.
5. **Documente estruturas**: comente cada campo da struct para lembrar o propósito.
6. **Breakpoints mentais**: após cada item, teste tudo antes de prosseguir.

---

## 🚀 Extensões Opcionais (se tiver tempo)

- Adicione 4º sensor (temperatura, por exemplo)
- Implemente histórico de 100 últimas leituras
- Crie protocolo binário ao invés de string (mais eficiente)
- Adicione autocalibração ao ligar
- Implemente threshold e alertas ("sensor A > 80%")
- Salve calibração em EEPROM (persiste após desligar)

---

## 📞 Checklist de Submissão

Entregue:
1. Código `.ino` completo e compilando
2. README explicando:
   - Como compilar e enviar
   - Como parear Bluetooth
   - Lista de comandos suportados
   - Estrutura de dados (explicar cada campo da struct)
3. Vídeo (20-30s): mostrando sistema rodando no Serial Monitor + app Bluetooth

Tempo estimado: **1-2 semanas** para iniciante cuidadoso.
