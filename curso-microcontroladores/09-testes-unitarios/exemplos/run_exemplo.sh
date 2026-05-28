#!/bin/bash

# Script para compilar e rodar o exemplo de testes

echo "=== Compilando exemplo de testes do motor ==="

# Copiar Unity (ou assumir que está em ../Unity/)
if [ ! -d "Unity" ]; then
    echo "Baixando Unity..."
    git clone https://github.com/ThrowTheSwitch/Unity.git
fi

# Compilar
gcc -I. -I./Unity/src \
    test_exemplo_motor.c \
    exemplo_motor.c \
    mock_arduino.c \
    Unity/src/unity.c \
    -o test_motor

if [ $? -ne 0 ]; then
    echo "Erro ao compilar!"
    exit 1
fi

echo ""
echo "=== Rodando testes ==="
echo ""

./test_motor

echo ""
echo "=== Limpando ==="
rm -f test_motor

echo "Feito!"
