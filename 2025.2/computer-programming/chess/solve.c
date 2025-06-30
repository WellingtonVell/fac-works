#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// Constantes para movimentação das peças
const int BISPO_CASAS = 5;
const int TORRE_CASAS = 5;
const int RAINHA_CASAS = 8;

// Funções recursivas
void mover_bispo_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return;
    }
    printf("Cima\n");
    printf("Direita\n");
    mover_bispo_recursivo(casas_restantes - 1);
}

void mover_torre_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return;
    }
    printf("Direita\n");
    mover_torre_recursivo(casas_restantes - 1);
}

void mover_rainha_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return;
    }
    printf("Esquerda\n");
    mover_rainha_recursivo(casas_restantes - 1);
}

int main() {
    printf("=== DESAFIO DE XADREZ - MATECHECK ===\n\n");
    
    // ==================== NIVEL NOVATO ====================
    printf("=== NIVEL NOVATO ===\n");
    
    // Movimentação do Bispo - 5 casas na diagonal superior direita
    printf("\nMovimentacao do Bispo (5 casas diagonal superior direita):\n");
    for (int i = 0; i < BISPO_CASAS; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }
    
    // Movimentação da Torre - 5 casas para a direita
    printf("\nMovimentacao da Torre (5 casas para a direita):\n");
    int torre_contador = 0;
    while (torre_contador < TORRE_CASAS) {
        printf("Direita\n");
        torre_contador++;
    }
    
    // Movimentação da Rainha - 8 casas para a esquerda
    printf("\nMovimentacao da Rainha (8 casas para a esquerda):\n");
    int rainha_contador = 0;
    do {
        printf("Esquerda\n");
        rainha_contador++;
    } while (rainha_contador < RAINHA_CASAS);
    
    // ==================== NIVEL AVENTUREIRO ====================
    printf("\n=== NIVEL AVENTUREIRO ===\n");
    
    // Movimentação do Cavalo em L - para baixo e esquerda
    printf("\nMovimentacao do Cavalo (L para baixo e esquerda):\n");
    for (int movimento = 0; movimento < 1; movimento++) {
        // Primeiro movimento: 2 casas para baixo
        for (int i = 0; i < 2; i++) {
            printf("Baixo\n");
        }
        // Segundo movimento: 1 casa para a esquerda
        int contador_esquerda = 0;
        while (contador_esquerda < 1) {
            printf("Esquerda\n");
            contador_esquerda++;
        }
    }
    
    // ==================== NIVEL MESTRE ====================
    printf("\n=== NIVEL MESTRE ===\n");
    
    // Movimentações usando funções recursivas
    printf("\nMovimentacao do Bispo (RECURSIVO - 5 casas diagonal direita para cima):\n");
    mover_bispo_recursivo(BISPO_CASAS);
    
    printf("\nMovimentacao da Torre (RECURSIVO - 5 casas para a direita):\n");
    mover_torre_recursivo(TORRE_CASAS);
    
    printf("\nMovimentacao da Rainha (RECURSIVO - 8 casas para a esquerda):\n");
    mover_rainha_recursivo(RAINHA_CASAS);
    
    // Movimentação do Cavalo em L avançada - para cima e direita
    printf("\nMovimentacao do Cavalo (L para cima e direita):\n");
    for (int movimento = 0; movimento < 1; movimento++) {
        for (int direcao = 1; direcao <= 2; direcao++) {
            if (direcao == 1) {
                // Primeira parte do L: 2 casas para cima
                for (int passo = 0; passo < 2; passo++) {
                    if (passo >= 2) break;
                    printf("Cima\n");
                    if (passo < 0) continue;
                }
            } else if (direcao == 2) {
                // Segunda parte do L: 1 casa para a direita
                int contador = 0;
                while (contador < 1) {
                    printf("Direita\n");
                    contador++;
                    if (contador >= 1) break;
                }
            }
        }
    }
    
    printf("\nPressione ENTER para encerrar o programa...");
    getchar();
    
    return 0;
}