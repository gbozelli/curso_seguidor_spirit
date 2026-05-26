# Git & GitHub - Cheat Sheet Rápido

## 🚀 Primeiros Passos (5 min)

```bash
# Configurar pela primeira vez
git config --global user.name "Seu Nome"
git config --global user.email "seu@email.com"

# Criar repositório
git init
# ou
git clone https://github.com/usuario/repo.git

# Fazer primeiro commit
git add .
git commit -m "Commit inicial"

# Enviar para GitHub
git push origin main
```

---

## 📝 Trabalho Diário

### Ver Status
```bash
git status                    # Status atual
git diff                      # Mudanças não commitadas
git log --oneline             # Histórico resumido
git log --oneline --all       # Todas as branches
```

### Adicionar e Commitar
```bash
git add arquivo.txt           # Adiciona arquivo específico
git add .                     # Adiciona tudo
git commit -m "Mensagem"      # Cria commit
git commit --amend            # Corrige último commit
```

### Push e Pull
```bash
git push                      # Envia commits
git push origin main          # Especifica branch
git pull                      # Baixa commits
git fetch                     # Baixa sem mesclar
```

---

## 🌳 Branches

### Criar e Mover
```bash
git branch feature/nova       # Cria branch
git checkout feature/nova     # Muda para branch
git checkout -b feature/nova  # Cria e muda (atalho)
```

### Ver Branches
```bash
git branch                    # Branches locais
git branch -a                 # Todos (local + remoto)
git branch -v                 # Com último commit
```

### Deletar
```bash
git branch -d feature/nova    # Delete local
git branch -D feature/nova    # Force delete
git push origin --delete feature/nova  # Delete remoto
```

### Mesclar
```bash
git merge feature/nova        # Merge em branch atual
git merge --no-ff feature/nova # Cria commit de merge
git merge --squash feature/nova # Squash commits
```

---

## 🔄 Pull Requests (via GitHub)

1. **Criar PR no GitHub**
   - Push seu branch: `git push origin feature/...`
   - Abra PR na página do GitHub
   - Descreva mudanças
   - Solicite revisão

2. **Responder Feedback**
   ```bash
   git add .
   git commit -m "Implementa feedback"
   git push origin feature/...
   ```

3. **Depois de Aprovada**
   ```bash
   git checkout main
   git pull origin main
   git branch -d feature/...
   ```

---

## 🔄 Rebase (Avançado)

```bash
git rebase main                    # Rebase em main
git rebase -i HEAD~3               # Rebase interativo últimas 3 commits
git rebase --continue              # Continuar após resolver conflito
git rebase --abort                 # Cancelar rebase
```

---

## 🔍 Ver Histórico

```bash
git log                        # Histórico completo
git log --oneline              # Resumido
git log --graph --all          # Visualizar branches
git log -5                     # Últimas 5 commits
git log --author="Seu Nome"    # Commits de alguém
git log --since="2 weeks ago"  # Últimas 2 semanas
git show commit-hash           # Ver commit específico
git blame arquivo.txt          # Ver quem modificou cada linha
```

---

## ⚙️ Desfazer Mudanças

### Antes de Commitar
```bash
git restore arquivo.txt        # Desfaz mudanças (Git 2.23+)
git checkout -- arquivo.txt    # Desfaz mudanças (versão antiga)
git reset HEAD arquivo.txt     # Remove de staging
```

### Depois de Commitar
```bash
git revert commit-hash         # Cria novo commit desfazendo
git reset --soft HEAD~1        # Desfaz último commit, mantém mudanças
git reset --mixed HEAD~1       # Desfaz commit e staging
git reset --hard HEAD~1        # Desfaz tudo (⚠️ CUIDADO!)
```

### Resgatar Commits "Perdidos"
```bash
git reflog                     # Ver histórico de operações
git checkout commit-hash       # Ir para commit
```

---

## 🔀 Conflitos

```bash
# Durante merge, se houver conflito:
# 1. Editar arquivos com <<<<<<< ======== >>>>>>>>
# 2. Escolher qual versão manter
# 3. Fazer:
git add .
git commit -m "Resolve conflito"
```

---

## 🔐 Remoto

```bash
git remote -v                  # Ver remotes
git remote add origin url      # Adicionar remoto
git remote remove origin       # Remover remoto
git remote rename origin upstream  # Renomear
git remote set-url origin url  # Mudar URL
```

---

## 🏷️ Tags

```bash
git tag v1.0.0                 # Cria tag leve
git tag -a v1.0.0 -m "Release 1.0" # Tag anotada
git tag -l                     # Lista tags
git push origin v1.0.0         # Enviar tag
git push origin --tags         # Enviar todas tags
```

---

## 🔍 Buscar

```bash
git grep "texto"               # Buscar em arquivos
git log -p -S "texto"          # Ver commits que contêm texto
git log --grep="fix"           # Commits com "fix" na mensagem
```

---

## 💾 Stash (Salvar Temporariamente)

```bash
git stash                      # Salva mudanças
git stash list                 # Ver stashes
git stash pop                  # Restaura último stash
git stash drop                 # Deleta stash
git stash apply stash@{0}      # Aplica stash específico
```

---

## 🐙 Sincronizar com Fork

```bash
# Primeira vez
git remote add upstream https://github.com/original/repo.git

# Depois, para sincronizar
git fetch upstream
git merge upstream/main
# ou
git rebase upstream/main

# Enviar de volta pro seu fork
git push origin main
```

---

## 📊 Estatísticas

```bash
git log --stat                 # Linhas adicionadas/removidas
git log --oneline | wc -l      # Total de commits
git log --author="Nome" --stat # Commits de alguém
git shortlog -sn               # Commits por autor
```

---

## ⚙️ Configuração

```bash
# Ver config
git config --global --list     # Global
git config --local --list      # Local do repo

# Editar config
git config --global user.name "Novo Nome"
git config --global core.autocrlf true
git config --local user.email "outro@email.com"

# Usar editor específico
git config --global core.editor "code --wait"
```

---

## 🔑 SSH

```bash
# Gerar chave
ssh-keygen -t ed25519 -C "seu@email.com"

# Testar conexão
ssh -T git@github.com

# Ver chaves adicionadas
ssh-add -l

# Adicionar chave ao ssh-agent
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
```

---

## 🐛 Debug

```bash
# Ver últimos comandos executados
git reflog

# Ver configuração de um repositório
git config -l

# Verificar integridade do repositório
git fsck

# Ver logs mais detalhados
git -v [comando]

# Modo verbose
git -vv
```

---

## 📋 Aliases Úteis

```bash
# Adicionar aliases
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'
git config --global alias.visual 'log --graph --oneline --all'

# Usar
git st              # git status
git co main         # git checkout main
git ci -m "msg"     # git commit -m "msg"
```

---

## 🎯 Fluxo Completo (Exemplo)

```bash
# 1. Clone repositório
git clone git@github.com:usuario/repo.git
cd repo

# 2. Crie branch para feature
git checkout -b feature/minha-feature

# 3. Faça mudanças
# (editar arquivos no editor)

# 4. Commite
git add .
git commit -m "feat: implementa nova feature"

# 5. Push para GitHub
git push -u origin feature/minha-feature

# 6. Abra PR no GitHub (interface web)

# 7. Após aprovação, mescle no GitHub

# 8. Volta local para main
git checkout main
git pull origin main

# 9. Delete branch local
git branch -d feature/minha-feature
```

---

## 🆘 Quando Algo Dá Errado

| Problema | Solução |
|----------|---------|
| Mudanças perdidas | `git reflog` → `git checkout hash` |
| Commit errado | `git revert hash` ou `git reset` |
| Merge conflict | Editar arquivos com `<<<<` `>>>>` |
| Branch deletada | `git reflog` → `git checkout hash` |
| Push rejeitado | `git pull` antes, ou `git push -f` (cuidado!) |
| "Detached HEAD" | `git checkout main` |

---

## 📱 Atalhos de Teclado Úteis

### Terminal/Git Bash
- `Ctrl+C` - Cancela comando
- `Ctrl+L` - Limpa terminal
- `Ctrl+R` - Busca histórico

### Editor (durante commit)
- `ESC` - Sai do modo edição (Vim)
- `:wq` - Salva e sai (Vim)
- `:q!` - Sai sem salvar (Vim)

---

## 📚 Aprenda Mais

```bash
# Help para qualquer comando
git help comando
git commit --help

# Info rápida
git comando -h
```

---

**Salve este arquivo como referência rápida! 📌**

**Dica:** Imprima este cheat sheet ou salve como favorito!
