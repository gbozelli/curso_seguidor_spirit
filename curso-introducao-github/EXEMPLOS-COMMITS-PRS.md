# Exemplos de Commits e Pull Requests

## ✅ Exemplos de BOM Commit

### Exemplo 1: Feature Simples

```
Adiciona botão de logout

- Cria novo componente Button
- Integra com sistema de autenticação
- Adiciona testes unitários
```

### Exemplo 2: Bug Fix

```
fix: corrige erro ao fazer login com email inválido

Quando o usuário tenta fazer login com um email que não existe,
a aplicação retornava erro genérico ao invés de mensagem específica.

Agora valida email antes de enviar requisição ao servidor,
mostrando mensagem clara: "Email não encontrado"

Testes adicionados em LoginForm.test.js
```

### Exemplo 3: Refatoração

```
refactor: melhora performance do componente Dashboard

- Remove renderizações desnecessárias
- Memoiza callbacks com useCallback
- Reduz de 15 renderizações para 3 ao abrir modal

Performance agora 50% mais rápida conforme medido com React DevTools
```

### Exemplo 4: Documentação

```
docs: adiciona guia de contribuição

- Cria CONTRIBUTING.md
- Documenta processo de setup
- Adiciona instruções de código review
```

### Exemplo 5: Dependências

```
chore: atualiza dependências para versões seguras

- Updates React 18.0.0 → 18.2.0
- Updates Next.js 13.0.0 → 13.4.1
- Removes deprecated package X
```

---

## ❌ Exemplos de RUIM Commit

### Ruim 1: Vago
```
fix bugs
```
❌ Qual bug? Onde? Por quê?

### Ruim 2: Muito Genérico
```
updates
```
❌ O que foi atualizado?

### Ruim 3: Sem Contexto
```
asdfghjkl
```
❌ Não comunica nada!

### Ruim 4: Muito Longo (não segue padrão)
```
Eu estava trabalhando na tela de login e percebi que tinha um bug 
onde se o usuário clicasse duas vezes o botão ele fazia o login duas vezes 
então eu adicionei um flag para desabilitar o botão mas agora preciso adicionar 
testes para isso funcionar direito...
```
❌ Quebra em múltiplas linhas sem estrutura clara

### Ruim 5: Detalhes Técnicos Desnecessários
```
Remove console.log da linha 42 do arquivo LoginForm.js
```
❌ Commit deveria descrever mudança, não implementação técnica

---

## 📋 Padrão de Mensagem de Commit (Recomendado)

```
<tipo>(<escopo>): <assunto em imperativo>

<corpo detalhado - explicar POR QUÊ, não O QUÊ>

<rodapé - referências a issues>
```

### Tipos Recomendados:
- **feat**: Nova funcionalidade
- **fix**: Correção de bug
- **docs**: Mudanças em documentação
- **style**: Formatação (sem mudar lógica)
- **refactor**: Reorganização sem mudança de comportamento
- **perf**: Melhoria de performance
- **test**: Adiciona/modifica testes
- **chore**: Tarefas de build, dependências

### Exemplos Seguindo Padrão:

#### Exemplo A
```
feat(auth): adiciona autenticação com two-factor

Implementa verificação de código OTP enviado por email.
Usuários agora precisam confirmar segundo fator após inserir senha.

Integrado com Twilio para envio de SMS (futuro).
Testes inclusos com 95% de cobertura.

Closes #1234
```

#### Exemplo B
```
fix(payment): corrige cálculo de taxa de imposto

A taxa estava sendo calculada antes de aplicar desconto.
Agora calcula após desconto ser aplicado.

Testado com 50 diferentes combinações de desconto/taxa.

Fixes #5678
```

#### Exemplo C
```
refactor(database): melhora índices da tabela usuarios

Remove índice duplicado que causava lentidão em INSERTs.
Adiciona índice composto em (email, deleted_at).

Queries agora 40% mais rápidas conforme benchmarks.
```

---

## 🔥 Exemplos de BOM Pull Request

### PR Exemplo 1: Simples e Bem Descrita

```markdown
## 📝 Descrição

Implementa página de recuperação de senha.

Usuário pode solicitar reset de senha através de email 
e recebe link para criar nova senha em até 24 horas.

## 🔄 Tipo de Mudança

- [x] Nova feature
- [ ] Bug fix
- [ ] Breaking change
- [ ] Documentação

## 📝 Mudanças

- Adiciona componente ForgotPasswordForm
- Cria endpoint /api/password-reset
- Integra com SendGrid para envio de emails
- Adiciona testes unitários (100% cobertura)

## 🧪 Como Testar

1. Clonar branch: `git checkout feature/forgot-password`
2. Instalar deps: `npm install`
3. Iniciar dev server: `npm run dev`
4. Ir para `/forgot-password`
5. Inserir email válido
6. Verificar email de reset
7. Clicar no link
8. Criar nova senha

## ✅ Checklist

- [x] Código segue o style guide
- [x] Testes foram adicionados
- [x] Documentação foi atualizada
- [x] Sem console.logs/debuggers
- [x] Sem breaking changes
- [x] Build passando (CI/CD)

## 🔗 Relacionado

Closes #999
```

### PR Exemplo 2: Com Screenshots

```markdown
## 🎨 Redesign da Página de Dashboard

Atualiza dashboard com novo design conforme especificação do Figma.

## 📸 Screenshots

### Antes
![before](https://user-images.githubusercontent.com/123/dashboard-before.png)

### Depois
![after](https://user-images.githubusercontent.com/123/dashboard-after.png)

## 🔍 Detalhes

- Novo layout responsivo
- Cores atualizadas conforme brand guidelines
- Cards agora com animação smooth
- Mobile-first approach

## ⚠️ Breaking Changes

Nenhuma

## 📋 Checklist

- [x] Design aprovado pelo time
- [x] Teste em navegadores: Chrome, Firefox, Safari
- [x] Teste em mobile
- [x] Acessibilidade WCAG AA
```

### PR Exemplo 3: Com Discussão Técnica

```markdown
## 🚀 Migração para SWR para Data Fetching

Esta PR substitui `axios + useEffect` por `swr` para melhor 
tratamento de cache e revalidação automática.

## 🤔 Decisão de Design

Consideramos várias soluções:

1. **SWR** ← Escolhido
   - Pro: Cache automático, revalidação, deduplicação
   - Con: Dependência adicional

2. **React Query**
   - Pro: Mais poderoso
   - Con: Overhead maior, overkill para o projeto

3. **GraphQL + Apollo**
   - Pro: Tipagem, schema
   - Con: Muita mudança, API não suporta

## 📊 Impacto de Performance

| Métrica | Antes | Depois | Melhoria |
|---------|-------|--------|----------|
| Requisições duplicadas | 5x | 1x | 80% ↓ |
| Time to Interactive | 2.3s | 1.8s | 22% ↓ |
| Bundle size | 42KB | 45KB | +3KB |

## 🧪 Testes

- [x] Testes unitários (95% cobertura)
- [x] Teste e2e (Chrome, Firefox)
- [x] Performance test com Lighthouse
- [x] Teste de cache com DevTools

## 📚 Referências

- [SWR Docs](https://swr.vercel.app)
- [Data Fetching RFC](https://github.com/nosso-repo/rfcs/pull/123)
```

### PR Exemplo 4: Correção de Bug com Contexto

```markdown
## 🐛 Fix: Upload de arquivo falha com caracteres especiais

## O Problema

Quando usuário tenta fazer upload de arquivo com caracteres especiais 
no nome (ex: `relatorio_2024_@_v2.pdf`), o upload falha com erro 
"Invalid file name".

Isso afeta ~5% dos usuários que têm nomes com `@`, `&`, `#`, etc.

## A Solução

Agora sanitiza nome do arquivo removendo caracteres especiais:
- Remove: `@ # & * ( ) [ ] { } = + [ ] \ / : ; " ' < > , ?`
- Substitui: espaços por `_`
- Resultado: `relatorio_2024_____v2.pdf`

Mantém extensão original.

## 🧪 Testes

Criado novo arquivo de testes com 20+ casos:
- Arquivo sem caracteres especiais (passa intacto)
- Arquivo com `@` (remove)
- Arquivo com apenas caracteres especiais (gera aleatorio)
- Arquivo vazio
- Arquivo muito longo (trunca)

## 📝 Mensagem de Usuário

Usuário vê: "Nome do arquivo foi ajustado para: relatorio_2024_____v2.pdf"

Não é bloqueador, apenas notificação.

## 🔗 Relacionado

Fixes #4456
Relacionado a #4450
```

---

## ❌ Exemplos de RUIM Pull Request

### PR Ruim 1: Sem Descrição
```
Feat: updates
```
❌ O que foi atualizado? Por que?

### PR Ruim 2: Muitos Commits Desorganizados
```
Commit 1: fix typo
Commit 2: add feature
Commit 3: oops forgot this
Commit 4: actually this too
Commit 5: revert previous
```
❌ Histórico confuso, deveria fazer squash

### PR Ruim 3: Mistura de Mudanças
```
Adiciona login + refatora database + atualiza cores

1. Nova tela de login
2. Move função de autenticação
3. Muda cores do design
4. Atualiza dependências
```
❌ Muitas coisas diferentes! Deveria ser 4 PRs separadas

### PR Ruim 4: Sem Testes
```
Implementa nova feature

Descrição: Implementei a feature X

Teste realizado manualmente.
```
❌ Sem testes automatizados

### PR Ruim 5: Sem Contexto
```
URGENT! FIX THIS!!!

Look at code. ASAP!!!
```
❌ Impossível entender o que é o problema

---

## 🎯 Dicas Finais

### Para Commit:
1. ✅ Uma coisa por commit
2. ✅ Mensagem descritiva
3. ✅ Imperativo (Adiciona, Fixa, Atualiza)
4. ✅ Sem pontuação final
5. ✅ Se tiver corpo, deixe linha em branco

### Para PR:
1. ✅ Descrição clara
2. ✅ Sempre inclua WHY, não só WHAT
3. ✅ Screenshots para mudanças visuais
4. ✅ Testes obrigatório
5. ✅ Preencha checklist completo
6. ✅ Uma feature/fix por PR
7. ✅ Mantenha PR pequena (<400 linhas)

### Tamanho Ideal de PR:
- 🟢 **Pequena**: < 100 linhas (revisar em 5 min)
- 🟡 **Média**: 100-400 linhas (revisar em 30 min)
- 🔴 **Grande**: > 400 linhas (difícil revisar, considere dividir)

---

**Boa escrita de commits e PRs! 🚀**
