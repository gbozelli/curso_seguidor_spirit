# 01-conceitos-basicos

Testes unitários são testes pequenos e focados.
Cada teste verifica se uma única função ou módulo funciona corretamente.

## O que é um teste unitário?

Um teste unitário é um pedaço de código que verifica se outra parte do seu código funciona como esperado.

```c
// Função que queremos testar
int somar(int a, int b) {
    return a + b;
}

// Teste unitário
void test_somar_positivos(void) {
    int resultado = somar(2, 3);
    TEST_ASSERT_EQUAL_INT(5, resultado);  // Espera 5
}
```

Se a função retorna 5, o teste passa.
Se retorna qualquer outra coisa, o teste falha.

## Características de um bom teste

Um bom teste unitário tem:

- **Uma responsabilidade** - Testa apenas uma coisa
- **Nome descritivo** - Diz exatamente o que testa
- **Isolado** - Não depende de outros testes
- **Rápido** - Executa em milissegundos
- **Determinístico** - Sempre passa ou falha (não muda)

## Estrutura: Arrange-Act-Assert

Todos os testes seguem este padrão:

```c
void test_motor_velocidade_limitada(void) {
    // ARRANGE: Preparar o estado
    inicializarMotor();
    
    // ACT: Executar a função
    controlarMotor(500, 500);  // Tenta acima do máximo
    
    // ASSERT: Verificar resultado
    TEST_ASSERT_LESS_THAN_OR_EQUAL(255, getVelocidade());
}
```

### Arrange (Preparar)

Coloque o sistema no estado necessário para o teste.

```c
inicializarMotor();
resetMocks();
```

### Act (Agir)

Execute a função que está testando.

```c
controlarMotor(100, 100);
```

### Assert (Verificar)

Confirme que o resultado é o esperado.

```c
TEST_ASSERT_EQUAL_INT(100, getVelocidade());
```

## Exemplo completo

Vamos testar uma função simples que controla a velocidade do motor:

```c
// Função a testar
void controlarMotor(int velocidade) {
    if (velocidade < 0) velocidade = 0;      // Não permite negativo
    if (velocidade > 255) velocidade = 255;  // Limita em 255
    ledcWrite(CANAL_PWM, velocidade);
}

// Testes
void test_velocidade_zero(void) {
    controlarMotor(0);
    TEST_ASSERT_EQUAL_INT(0, getVelocidade());
}

void test_velocidade_positiva(void) {
    controlarMotor(100);
    TEST_ASSERT_EQUAL_INT(100, getVelocidade());
}

void test_velocidade_maxima(void) {
    controlarMotor(255);
    TEST_ASSERT_EQUAL_INT(255, getVelocidade());
}

void test_velocidade_acima_maximo(void) {
    controlarMotor(500);  // Tenta acima do máximo
    TEST_ASSERT_EQUAL_INT(255, getVelocidade());  // Deve limitar
}

void test_velocidade_negativa(void) {
    controlarMotor(-50);  // Tenta negativo
    TEST_ASSERT_EQUAL_INT(0, getVelocidade());  // Deve virar 0
}
```

## Resultado

Se você executar esses testes, todos devem passar:

```
test_velocidade_zero...PASS
test_velocidade_positiva...PASS
test_velocidade_maxima...PASS
test_velocidade_acima_maximo...PASS
test_velocidade_negativa...PASS

5 testes, 5 passaram, 0 falharam
```

## Por que não testar no Arduino?

Você poderia testar colocando código `if` no Arduino:

```cpp
void setup() {
    Serial.begin(9600);
    
    // Testando manualmente
    controlarMotor(100);
    if (getVelocidade() != 100) {
        Serial.println("ERRO: Velocidade não é 100!");
    }
}
```

Mas isso é tedioso:

- Você precisa carregar código no Arduino
- Cada teste demora segundos
- Fica tudo misturado com lógica de teste
- Não dá para testar automaticamente

Com testes unitários:

- Rode centenas de testes em segundos
- Tudo no seu computador
- Testes separados da lógica
- Integração com git e CI/CD

