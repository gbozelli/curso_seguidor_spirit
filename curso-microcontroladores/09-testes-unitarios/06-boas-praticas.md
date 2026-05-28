# 06-boas-praticas

Escrever testes bons é uma habilidade.
Aqui estão padrões que facilitam manutenção e evitam problemas.

## 1. Um conceito por teste

Cada teste deve verificar **apenas uma coisa**.

### ❌ Ruim: Múltiplas coisas

```c
void test_motor(void) {
    inicializarMotor();
    controlarMotor(100, 100);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
    
    pararMotores();
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
    
    controlarMotor(500, 500);
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidadeMotorEsquerdo());
}
```

Problema: Se falhar, você não sabe qual parte quebrou.

### ✅ Bom: Uma coisa por teste

```c
void test_motor_controla_velocidade(void) {
    controlarMotor(100, 100);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
}

void test_motor_para_com_sucesso(void) {
    controlarMotor(100, 100);
    pararMotores();
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
}

void test_motor_limita_velocidade(void) {
    controlarMotor(500, 500);
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidadeMotorEsquerdo());
}
```

Vantagem: Você sabe exatamente qual teste falhou.

## 2. Nomes descritivos

Nome do teste deve descrever o que está sendo testado.

### ❌ Ruim

```c
void test1(void) { }
void test_motor(void) { }
void test_ok(void) { }
void test_case_1(void) { }
```

### ✅ Bom

```c
void test_motor_inicializa_velocidade_zero(void) { }
void test_motor_limita_velocidade_em_255(void) { }
void test_motor_velocidade_negativa_vira_zero(void) { }
void test_motor_motores_independentes(void) { }
```

Benefício: Ao ler a lista de testes, você já sabe o que cada um faz.

## 3. Padrão Arrange-Act-Assert (AAA)

Todo teste deve ter 3 seções claras:

```c
void test_motor_velocidade_limitada(void) {
    // ARRANGE: Preparar
    inicializarMotor();
    
    // ACT: Agir
    controlarMotor(500, 500);  // Tenta acima do máximo
    
    // ASSERT: Verificar
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidadeMotorEsquerdo());
}
```

Vantagem: Estrutura consistente.

## 4. Testes independentes

Cada teste deve funcionar sozinho.

### ❌ Ruim: Dependência entre testes

```c
int velocidade_global;

void test_1_inicializa(void) {
    velocidade_global = inicializarMotor();
}

void test_2_controla(void) {
    // Depende de test_1!
    controlarMotor(100, 100);
    TEST_ASSERT_EQUAL_INT(100, velocidade_global);
}
```

Problema: Se test_1 falhar, test_2 também falha.

### ✅ Bom: Cada teste é independente

```c
void setUp(void) {
    inicializarMotor();  // Rodado antes de CADA teste
    resetMocks();
}

void test_motor_inicializa(void) {
    TEST_ASSERT_TRUE(inicializarMotor() == 0);
}

void test_motor_controla(void) {
    // Começa limpo, não depende de outro teste
    controlarMotor(100, 100);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
}
```

Vantagem: Pode rodar testes em qualquer ordem.

## 5. setUp() e tearDown()

Use estas funções para preparar e limpar.

```c
void setUp(void) {
    // Executado ANTES de cada teste
    // Coloque inicializações e resets aqui
    resetMocks();
    inicializarMotor();
    // Estado limpo para o teste começar
}

void tearDown(void) {
    // Executado DEPOIS de cada teste
    // Coloque limpeza de recursos aqui
    pararMotores();
    // Libera recursos, reseta estado
}
```

Benefício: Evita código repetido em cada teste.

## 6. Cobertura de casos extremos

Sempre teste limites e casos especiais.

```c
// ✅ Testa casos extremos
void test_velocidade_minima(void) {
    controlarMotor(0, 0);
    TEST_ASSERT_EQUAL_INT(0, getVelocidadeMotorEsquerdo());
}

void test_velocidade_maxima(void) {
    controlarMotor(255, 255);
    TEST_ASSERT_EQUAL_INT(255, getVelocidadeMotorEsquerdo());
}

void test_velocidade_acima_maxima(void) {
    controlarMotor(256, 256);
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidadeMotorEsquerdo());
}

void test_velocidade_negativa(void) {
    controlarMotor(-1, -1);
    TEST_ASSERT_GREATER_THAN_OR_EQUAL(0, getVelocidadeMotorEsquerdo());
}
```

Casos extremos frequentemente revelam bugs.

## 7. Mensagens de erro claras

Use `TEST_ASSERT_MESSAGE()` para explicar por quê.

### ❌ Sem mensagem

```c
void test_motor_inicializa_pinos(void) {
    TEST_ASSERT_GREATER_THAN(0, mock_state.pinMode_calls);
    // Se falhar: "Assertion Failed"
    // Onde? Por quê?
}
```

### ✅ Com mensagem

```c
void test_motor_inicializa_pinos(void) {
    TEST_ASSERT_MESSAGE(
        mock_state.pinMode_calls >= 4,
        "Motor deve chamar pinMode() para 4 pinos (ESQ_FRENTE, ESQ_TRAS, DIR_FRENTE, DIR_TRAS)"
    );
}
```

Benefício: Debugar fica muito mais rápido.

## 8. DRY (Don't Repeat Yourself)

Não repita código nos testes.

### ❌ Repetitivo

```c
void test_velocidade_10(void) {
    inicializarMotor();
    resetMocks();
    controlarMotor(10, 10);
    TEST_ASSERT_EQUAL_INT(10, getVelocidadeMotorEsquerdo());
}

void test_velocidade_20(void) {
    inicializarMotor();
    resetMocks();
    controlarMotor(20, 20);
    TEST_ASSERT_EQUAL_INT(20, getVelocidadeMotorEsquerdo());
}

void test_velocidade_30(void) {
    inicializarMotor();
    resetMocks();
    controlarMotor(30, 30);
    TEST_ASSERT_EQUAL_INT(30, getVelocidadeMotorEsquerdo());
}
```

### ✅ DRY

```c
void setUp(void) {
    inicializarMotor();
    resetMocks();
}

void test_velocidade_10(void) {
    controlarMotor(10, 10);
    TEST_ASSERT_EQUAL_INT(10, getVelocidadeMotorEsquerdo());
}

void test_velocidade_20(void) {
    controlarMotor(20, 20);
    TEST_ASSERT_EQUAL_INT(20, getVelocidadeMotorEsquerdo());
}

void test_velocidade_30(void) {
    controlarMotor(30, 30);
    TEST_ASSERT_EQUAL_INT(30, getVelocidadeMotorEsquerdo());
}
```

Benefício: Menos código, mais fácil de manter.

## 9. Teste comportamento, não implementação

Teste o que a função **faz**, não **como** faz.

### ❌ Testa implementação

```c
void test_motor_usa_pwm(void) {
    controlarMotor(100, 100);
    // Testa detalhes internos
    TEST_ASSERT_EQUAL_INT(1, mock_state.ledcWrite_calls);
}
```

Problema: Se você mudar a implementação interna, teste quebra (mas função ainda funciona).

### ✅ Testa comportamento

```c
void test_motor_controla_velocidade(void) {
    controlarMotor(100, 100);
    // Testa o que importa: resultado
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
}
```

Benefício: Testes continuam válidos mesmo se implementação muda.

## 10. Rápido de executar

Testes devem ser rápidos.

### ❌ Lento

```c
void test_motor_aguarda(void) {
    controlarMotor(100, 100);
    sleep(1);  // Aguarda 1 segundo
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
}
```

### ✅ Rápido

```c
void test_motor_velocidade(void) {
    controlarMotor(100, 100);
    TEST_ASSERT_EQUAL_INT(100, getVelocidadeMotorEsquerdo());
}
```

Benefício: Suite de testes roda em segundos, não minutos.

## Checklist de bom teste

- [ ] Um conceito por teste
- [ ] Nome descritivo
- [ ] Segue padrão AAA
- [ ] Independente de outros testes
- [ ] Usa setUp/tearDown
- [ ] Testa casos extremos
- [ ] Tem mensagem de erro clara
- [ ] Sem código repetido
- [ ] Testa comportamento, não implementação
- [ ] Executa rápido

