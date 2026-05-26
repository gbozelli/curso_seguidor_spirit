# Dicas para Windows

Guia específico para instalação e configuração de Git no Windows.

## Git Bash vs PowerShell vs CMD

Use **Git Bash** para aprender.
Ele emula terminal Linux, então comandos funcionam igual em qualquer OS.

```bash
# Abra Git Bash clicando direito na pasta → "Open Git Bash here"
```

## Configuração para Windows

### Quebra de linha (CRLF vs LF)

Windows usa CRLF, mas Git usa LF.
Configure Git para converter automaticamente:

```bash
git config --global core.autocrlf true
```

### Editor padrão

Para usar VS Code:

```bash
git config --global core.editor "code --wait"
```

### Nomes com espaços

Use aspas se seu caminho tiver espaços:

```bash
cd "C:\Users\Seu Nome\Documents\Meu Projeto"
```
