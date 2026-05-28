# 09-testes-unitarios

Testes unitários em C/C++ para projetos Arduino.
Esta seção ensina como criar testes automatizados para sua lógica de controle sem precisar fazer upload no hardware a cada mudança.

## Por que testar?

Quando seu código roda apenas no Arduino, você tem que recompilar e carregar toda vez para descobrir um bug.
Com testes unitários, você valida sua lógica no computador (muito mais rápido).

## O que você aprenderá

- O que são testes unitários
- Por que testar em projetos embarcados
- Qual framework usar (escolhemos Unity)
- Como escrever uma suite de testes
- Boas práticas de testes
- Como executar testes automaticamente

## Estrutura das aulas

1. **Conceitos básicos** - O que é um teste unitário
2. **Por que testar** - Problemas e vantagens
3. **Frameworks** - Qual escolher e por quê
4. **Setup do Unity** - Configurar o ambiente
5. **Primeira suite de testes** - Exemplos práticos
6. **Boas práticas** - Como escrever testes melhores
7. **Executando testes** - Rodando testes automaticamente

## Visão rápida

Um teste unitário verifica se uma função faz o que deve fazer:

```c
void test_motor_para_com_sucesso(void) {
    inicializarMotor();
    controlarMotor(100, 100);
    pararMotores();
    TEST_ASSERT_EQUAL_INT(0, getVelocidade());
}
```

Se o motor não para, o teste falha.
Se para corretamente, o teste passa.

## Próximos passos

Leia as aulas em ordem para entender:
- Por que testar é importante
- Como setup tudo
- Escrever seus próprios testes

