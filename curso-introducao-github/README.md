# Introdução ao GitHub

Guia completo sobre Git e GitHub para usuários Windows.
Este material explora controle de versão, repositórios e fluxos colaborativos de desenvolvimento.

## O que você vai aprender

- A estrutura de um repositório.
- O que são commits, branches e pull requests.
- Como instalar e configurar Git no Windows.
- Fluxo básico: adicionar, commitar, enviar e baixar código.
- Trabalhar com branches e merge.
- Abrir e revisar Pull Requests.
- Boas práticas e padrões de desenvolvimento.

## O que é GitHub?

GitHub é uma plataforma que hospeda repositórios de código usando Git para controle de versão.
Permite que desenvolvedores versionem código, colaborem em equipe e rastreiem mudanças.

## Conceitos fundamentais

### Repositório (Repo)

Um repositório é uma pasta de projeto com controle de versão Git.
Contém todos os arquivos do projeto e um histórico completo de mudanças.
A pasta `.git` (oculta) armazena todas as informações de versionamento.

### Commit

Um commit é um snapshot (foto) do seu projeto em um determinado momento.
Registra quais arquivos foram modificados e inclui uma mensagem descritiva.

Cada commit tem:
- Um hash único (identificador)
- Autor e timestamp
- Mensagem descritiva
- Lista de mudanças

### Branch

Um branch é uma linha de desenvolvimento independente.
Permite trabalhar em features sem afetar o código principal.
O branch `main` é o principal (produção).

Exemplo de fluxo:
```
main:            A -> B -> C -> D -> E
feature/login:           -> F -> G -> [merge]
```

### Merge

Merge é a ação de combinar dois branches.
Geralmente faz-se merge de uma feature branch de volta para main.

### Pull Request (PR)

Um PR é uma solicitação formal para mesclar código de um branch para outro.
Permite revisão de código, discussão e testes antes de aceitar mudanças.

## Instalação no Windows

### Passo 1: Baixar e instalar Git

1. Acesse https://git-scm.com/
2. Clique em "Download for Windows"
3. Execute o instalador
4. Siga as instruções (componentes padrão são suficientes)

### Passo 2: Verificar instalação

Abra Git Bash ou PowerShell:

```bash
git --version
```

Deve retornar algo como: `git version 2.45.0.windows.1`

### Passo 3: Configurar Git

```bash
git config --global user.name "Seu Nome"
git config --global user.email "seu.email@gmail.com"
```

Verifique com:
```bash
git config --list
```

### Passo 4: Criar conta GitHub

1. Acesse https://github.com/
2. Clique em "Sign up"
3. Preencha email, senha e username
4. Verifique seu email

## Fluxo de trabalho básico

### Criar um repositório local

```bash
mkdir meu-projeto
cd meu-projeto
git init
```

Isso cria a pasta `.git` que rastreia mudanças.

### Adicionar arquivos

```bash
# Criar um arquivo
echo "# Meu Projeto" > README.md

# Ver status
git status
```

### Fazer um commit

```bash
# Adicionar arquivo à staging area
git add README.md

# Criar commit
git commit -m "Adiciona README inicial"

# Ver histórico
git log --oneline
```

### Conectar com GitHub

1. Crie repositório em https://github.com/new
2. NÃO inicialize com README

```bash
# Conectar repositório local com remoto
git remote add origin https://github.com/seu-usuario/meu-projeto.git

# Renomear branch
git branch -M main

# Enviar commits
git push -u origin main
```

Pronto! Seu código está no GitHub.

### Depois: Push e Pull

```bash
# Enviar novos commits
git push

# Baixar commits do GitHub
git pull
```

## Comandos essenciais

### Ver informações

| Comando | O que faz |
|---------|-----------|
| `git status` | Status atual dos arquivos |
| `git log` | Histórico de commits |
| `git log --oneline` | Histórico resumido |
| `git diff` | Ver mudanças não commitadas |
| `git branch` | Lista branches locais |
| `git branch -a` | Todos os branches |

### Adicionar e commitar

| Comando | O que faz |
|---------|-----------|
| `git add arquivo.txt` | Adiciona arquivo específico |
| `git add .` | Adiciona todos os arquivos |
| `git commit -m "msg"` | Cria um commit |
| `git reset HEAD arquivo.txt` | Remove de staging |
| `git checkout arquivo.txt` | Desfaz mudanças |

### Branches

| Comando | O que faz |
|---------|-----------|
| `git branch nome` | Cria novo branch |
| `git checkout nome` | Muda para branch |
| `git checkout -b nome` | Cria e muda para branch |
| `git merge nome` | Mescla um branch |
| `git branch -d nome` | Deleta branch |

### Remoto

| Comando | O que faz |
|---------|-----------|
| `git push` | Envia commits para GitHub |
| `git pull` | Baixa commits do GitHub |
| `git fetch` | Baixa sem mesclar |
| `git clone url` | Copia um repositório |
