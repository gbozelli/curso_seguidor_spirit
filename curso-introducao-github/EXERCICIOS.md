# Exercícios Práticos

## Nível 1: Iniciante

Exercícios básicos de Git local e repositório remoto.

### 1.1: Instalação e Configuração

Configure Git no Windows:

```bash
git --version
git config --global user.name "Seu Nome"
git config --global user.email "seu@email.com"
git config --list
```

Validação: `git config --list` mostra seu nome e email.

### 1.2: Primeiro Repositório

Crie um repositório local:

```bash
mkdir meu-primeiro-repo
cd meu-primeiro-repo
git init
echo "# Meu Primeiro Repositório" > README.md
git status
git add README.md
git commit -m "Adiciona README inicial"
git log --oneline
```

Validação: `git log` mostra 1 commit.

### 1.3: Múltiplos Commits

Pratique adicionar e commitar:

```bash
echo "## Descrição" >> README.md
git add README.md
git commit -m "Adiciona descrição"

echo "## Objetivos" >> README.md
git add README.md
git commit -m "Adiciona objetivos"

git log --oneline
```

Validação: `git log` mostra 3 commits.

### 1.4: .gitignore

Aprenda a ignorar arquivos:

```bash
touch arquivo.log
mkdir temp
touch temp/arquivo.txt

git status          # Mostra muitos arquivos

cat > .gitignore << EOF
*.log
temp/
EOF

git status          # Menos arquivos
git add .gitignore
git commit -m "Adiciona .gitignore"
```

Validação: `.log` e `temp/` não aparecem em `git status`.

## Nível 2: Intermediário

Trabalhe com GitHub e branches.

### 2.1: Conectar com GitHub

Envie seu repositório para GitHub:

```bash
# Crie repositório em github.com/new
# (NÃO inicialize com README)

git remote add origin git@github.com:seu-usuario/meu-primeiro-repo.git
git branch -M main
git push -u origin main

# Verifique em GitHub
```

Validação: Repositório visível no GitHub com commits.

### 2.2: Criar e Mesclar Branches

Pratique branches locais:

```bash
git branch feature/melhorias
git checkout feature/melhorias

echo "## Como Usar" >> README.md
git add README.md
git commit -m "Adiciona seção Como Usar"

echo "## Autor" >> README.md
git add README.md
git commit -m "Adiciona seção Autor"

git checkout main
git merge feature/melhorias

git branch -d feature/melhorias
git push origin main
```

Validação: `git log` mostra novos commits em main.

### 2.3: Pull Request

Abra uma PR no GitHub:

```bash
git checkout -b feature/adiciona-licenca
cat > LICENSE << EOF
MIT License
...
EOF

git add LICENSE
git commit -m "Adiciona MIT License"
git push origin feature/adiciona-licenca

# Abra PR no GitHub
# Descreva as mudanças
# Mescle via GitHub interface
# Delete branch remoto

git checkout main
git pull origin main
git branch -d feature/adiciona-licenca
```

Validação: PR foi aberta e mergeada.

## Nível 3: Avançado

Fluxos profissionais e situações complexas.

### 3.1: Branches develop

Implemente fluxo com develop:

```bash
git checkout -b develop
git push -u origin develop

git checkout -b feature/testes develop
cat > test.py << EOF
def test_hello():
    assert True
EOF

git add test.py
git commit -m "Adiciona testes iniciais"
git push origin feature/testes

# Abra PR de feature/testes → develop
# Aprove e mescle
# Atualize local

git checkout develop
git pull origin develop

# Quando pronto, merge para main
git checkout main
git merge develop
git push origin main
git tag v1.0.0
git push origin v1.0.0
```

Validação: Branches main, develop e v1.0.0 tag existem.

### 3.2: Resolver Merge Conflict

Pratique resolver conflitos:

```bash
git checkout main
git checkout -b branch-a
echo "Mudança A" >> README.md
git add README.md
git commit -m "Branch A modifica README"

git checkout -b branch-b main
echo "Mudança B" >> README.md
git add README.md
git commit -m "Branch B modifica README"

git checkout main
git merge branch-a

# Agora merge B vai ter conflito
git merge branch-b

# Abra README.md e veja:
# <<<<<<< HEAD
# Mudança A
# =======
# Mudança B
# >>>>>>> branch-b

# Edite e escolha, ou mantenha ambas
git add README.md
git commit -m "Resolve merge conflict"

git log --oneline
```

Validação: Conflito foi resolvido, commit de merge existe.

### 3.3: Rebase

Use rebase para histórico linear:

```bash
git checkout -b feature/refactor main

echo "Mudança 1" > arquivo1.txt
git add arquivo1.txt
git commit -m "Refactor: parte 1"

echo "Mudança 2" > arquivo2.txt
git add arquivo2.txt
git commit -m "Refactor: parte 2"

git checkout main
echo "Mudança main" > main.txt
git add main.txt
git commit -m "Atualiza main"

git checkout feature/refactor
git rebase main

git log --oneline  # History linear
git checkout main
git merge feature/refactor

git log --oneline  # Sem merge commit
```

Validação: Histórico linear, sem merge commits.

### 3.4: Contribuir em Open Source

Faça fork e contribua em projeto:

```bash
# Fork projeto no GitHub
# Clone seu fork

git clone git@github.com:seu-usuario/repositorio.git
cd repositorio

# Adicionar upstream
git remote add upstream git@github.com:projeto-original/repositorio.git

# Criar branch para contribuição
git checkout -b feature/minha-contribuicao

# Fazer mudanças (ex: adicionar nome à lista)
# ...

git add .
git commit -m "Adiciona minha contribuição"

# Sincronizar com upstream
git fetch upstream
git merge upstream/main

# Push para seu fork
git push origin feature/minha-contribuicao

# Abra PR no GitHub para projeto original
# Descreva contribuição
# Aguarde feedback
```

Validação: PR aberta em projeto open-source.

## Checklist Final

Após completar todos os exercícios:

- [ ] Configurar Git no Windows
- [ ] Criar repositório local
- [ ] Fazer commits com mensagens descritivas
- [ ] Criar e mesclar branches
- [ ] Fazer push/pull com GitHub
- [ ] Abrir Pull Requests
- [ ] Revisar código
- [ ] Resolver merge conflicts
- [ ] Entender fluxos profissionais
- [ ] Contribuir em open-source

Prático é aprender fazendo. Depois de completar, você está pronto para usar Git profissionalmente.
