# 01-qtr-sensors

Sensores QTR.
Este tópico explica como os sensores QTR detectam a linha e como calibrá-los.

## O que você vai aprender

- Como um sensor QTR mede luz refletida.
- Por que calibrar antes de usar.
- Como ler valores brutos.
- Como obter uma posição a partir dos sensores.
- Como conectar 8 sensores a um ESP32.

## Como funciona

Sensores QTR usam luz infravermelha para detectar a diferença entre preto e branco.
Nosso arranjo tem 8 sensores em linha, criando um perfil de refletância da superfície.

Cada sensor é lido pelo ESP32 e fornece um valor em função da luz refletida.
Sensores próximos à linha preta produzem valores diferentes dos sensores sobre a superfície clara.

```text
ESP32
 |-- S1
 |-- S2
 |-- S3
 |-- S4
 |-- S5
 |-- S6
 |-- S7
 |-- S8

Cada Sx representa um dos 8 sensores QTR alinhados na frente do robô.
```

### Sensor de 8 elementos

O arranjo de 8 sensores permite detectar a posição lateral da linha com mais resolução.
Os sensores centrais detectam quando o robô está alinhado. Os sensores laterais ajudam a identificar curvas e desvios.

## O código de exemplo

O exemplo `qtr_exemplo.ino` faz:

- definição dos pinos dos sensores.
- calibração dos sensores.
- leitura dos valores brutos.
- cálculo da posição da linha.

## O que faz cada parte

- `qtr.setTypeRC()` configura o tipo de leitura.
- `qtr.setSensorPins(...)` informa os pinos usados.
- `qtr.calibrate()` ajusta os limites de cada sensor.
- `qtr.read(sensorValues)` lê os valores atuais.
- `qtr.readLine(sensorValues)` converte as leituras em uma posição.

## Por que calibrar

Cada sensor tem uma resposta diferente.
A calibração permite comparar os sensores entre si.
Sem calibração, o robô pode interpretar mal a linha.

## Como testar

1. Abra `qtr_exemplo.ino`.
2. Execute a calibração com o robô sobre a pista.
3. Observe os valores no monitor serial.
4. Mova o robô e veja como a posição muda.

## Observações

- Sensores QTR costumam usar 5 a 7 elementos.
- A calibração deve ser feita em diferentes posições sobre a pista.
- O valor de corte pode variar conforme a luz ambiente.
- Em ESP32, alguns pinos têm comportamento de entrada diferente.

## Exercícios

- Ajuste `SENSOR_COUNT` para um número diferente.
- Compare os valores brutos de cada sensor.
- Calibre em superfícies diferentes e veja as mudanças.
- Artigos sobre seguidores de linha e mapeamento de pista.
