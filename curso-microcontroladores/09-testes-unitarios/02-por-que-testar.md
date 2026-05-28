# 02-por-que-testar

Testar é importante.
Especialmente em projetos embarcados onde descobrir um bug é difícil.

## Problemas sem testes

### Sem testes, você enfrenta:

**Bugs descobertos tarde**
- Você escreve código por horas
- Carrega no Arduino
- Descobre que não funciona
- Tem que debugar no hardware

**Refatoração é perigosa**
- Quer melhorar o código?
- Muda algo "pequeno"?
- Tudo quebra
- Você não sabe o que quebrou

**Debugging é demorado**
- Você liga o serial
- Tira prints para ver onde está errado
- Remove prints
- Recompila
- Recarrega no Arduino
- Tira mais prints
- Repete...

**Documentação vira ficção**
- "Esta função deveria fazer X"
- Mas ninguém sabe se realmente faz
- Código fica inconsistente

## Vantagens com testes

### Com testes, você tem:

**Feedback instantâneo**
- Escreve código
- Roda testes
- Em milissegundos, sabe se está certo

**Confiança para refatorar**
- Quer melhorar algo?
- Muda
- Roda testes
- Se passarem, está seguro

**Debugging mais fácil**
- Teste falha
- Você sabe exatamente qual função tem problema
- Não precisa de prints espalhados

**Documentação viva**
- Os testes mostram exatamente como usar cada função
- Se a função muda, os testes quebram
- Você é forçado a manter documentação atualizada

## Comparação: Com e Sem Testes

### Cenário: Você quebrou o motor

**Sem testes:**
1. Carrega código no Arduino
2. Liga o motor
3. Não funciona
4. Abre o código
5. Tira 5 prints de debug
6. Recompila
7. Recarrega
8. Vê um print, ainda não ajuda
9. Tira mais 3 prints
10. Recompila
11. Recarrega
12. Vê que o problema é aqui
13. Tira prints de novo
14. Recompila
15. Recarrega
16. Funciona!

**Tempo total: ~5 minutos**

**Com testes:**
1. Roda suite de testes
2. Ve que `test_motor_para_com_sucesso` falhou
3. Abre `motor.c`
4. Vê a função `pararMotores()`
5. Enxerga o bug imediatamente
6. Conserta em 10 segundos
7. Roda testes novamente
8. Todos passam

**Tempo total: ~1 minuto**

## Exemplo real

Suponha que você escreveu:

```c
void pararMotores(void) {
    ledcWrite(CANAL_ESQ, 0);   // Para motor esquerdo
    ledcWrite(CANAL_DIR, 0);   // Para motor direito
}

int getVelocidadeMotorEsquerdo(void) {
    return velocidade_esq;  // Retorna velocidade armazenada
}
```

Semanas depois, você refatora para economizar RAM:

```c
void pararMotores(void) {
    velocidade_esq = 0;        // Armazena em variável
    velocidade_dir = 0;
    ledcWrite(CANAL_ESQ, 0);
    ledcWrite(CANAL_DIR, 0);
}
```

**Sem testes:** Você não sabe se quebrou algo.

**Com testes:** 
```
test_motor_para_com_sucesso...PASS
test_motor_velocidade_retorna_valor_correto...PASS
test_motor_ambos_motores_param_independentes...PASS

3 testes, 3 passaram
```

Pronto, você sabe que está seguro.

## Testes economizam tempo

No começo, testar parece mais lento:

- Escrever testes leva tempo
- Setup de ferramentas leva tempo

Mas em um projeto grande:

- Você economiza horas debugando
- Refatora com confiança
- Documenta seu código automaticamente
- Evita bugs em produção

## Outros benefícios

**Melhor design de código**
- Código testável é melhor projetado
- Funções menores e focadas
- Menos dependências
- Mais reutilizável

**Integração contínua**
- Testes podem rodar automaticamente
- Cada push para git roda testes
- Pull requests só mergeiam se passarem
- Você nunca quebra o código principal

**Histórico de funcionalidade**
- Testes mostram exatamente como cada função deveria funcionar
- Novo desenvolvedor lê os testes para aprender
- Você lembra como funcionava meses atrás

## Resumo

Sem testes:
- Debugging demorado
- Medo de refatorar
- Bugs tardios
- Documentação ruim

Com testes:
- Feedback instantâneo
- Refatora com segurança
- Bugs detectados cedo
- Documentação automática

**Vale a pena investir tempo em testes.**

