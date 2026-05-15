# Compra de Componentes e Datasheets

## Objetivo
Entender como escolher, pesquisar e comprar componentes eletrônicos corretamente, lendo e interpretando datasheets, comunicando-se com fornecedores e evitando armadilhas comuns.

## Tópicos Abordados

- Onde comprar componentes (nacionais e internacionais)
- O que é um datasheet e por que ler
- Especificações técnicas essenciais
- Tensão de operação (3.3V vs 5V)
- Corrente e consumo de energia
- Protocolos de comunicação (I2C, SPI, UART)
- Módulos vs componentes brutos
- Comunicação com fornecedores
- Armadilhas comuns na compra
- Verificação ao receber o componente
- Documentação e salvaguarda

## Por que essa aula é importante?

Muitos projetos falham não por falta de programação, mas por escolhas erradas de componentes. Saber ler um datasheet, entender especificações e comunicar-se com fornecedores economiza tempo, dinheiro e frustração.

## Checklist de Compra

Antes de comprar qualquer componente, verifique:
- [ ] Datasheet disponível e lido
- [ ] Tensão compatível com seu microcontrolador
- [ ] Protocolo de comunicação suportado
- [ ] Pinos disponíveis no seu microcontrolador
- [ ] Corrente dentro dos limites do seu sistema
- [ ] Precisão/faixa adequada para o projeto
- [ ] Vendedor com boa reputação

## Exemplo Prático

Para um seguidor de linha com ESP32, você precisaria de:
- Sensor óptico (QTR-8) - verificar: 3.3V compatível? Analógico? Quantos pinos?
- Motores DC - verificar: tensão? Corrente máxima?
- Módulo PWM se necessário - verificar: compatibilidade?

Cada componente exige pesquisa prévia no datasheet antes da compra.
