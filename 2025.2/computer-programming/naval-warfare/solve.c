#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Função para inicializar uma matriz com zeros
void inicializarMatriz(int matriz[][10], int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Função para exibir uma matriz
void exibirMatriz(int matriz[][10], int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para exibir coordenadas de um navio
void exibirCoordenadas(char* tipoNavio, int coordenadas[][2], int tamanho) {
    printf("Coordenadas do navio %s:\n", tipoNavio);
    for(int i = 0; i < tamanho; i++) {
        printf("  Parte %d: (%d, %d)\n", i+1, coordenadas[i][0], coordenadas[i][1]);
    }
    printf("\n");
}

int main() {
    printf("=== DESAFIO BATALHA NAVAL - MATECHECK ===\n\n");
    
    // ==========================================
    // NIVEL NOVATO - Posicionamento dos Navios
    // ==========================================
    printf("=== NIVEL NOVATO - Posicionamento Basico dos Navios ===\n");
    
    // Tabuleiro 5x5 para o nível novato
    int tabuleiroNovato[10][10];
    inicializarMatriz(tabuleiroNovato, 5, 5);
    
    // Navio 1: Vertical (3 posições) - posicao inicial (1,2)
    int navioVertical[3][2] = {{1, 2}, {2, 2}, {3, 2}};
    for(int i = 0; i < 3; i++) {
        tabuleiroNovato[navioVertical[i][0]][navioVertical[i][1]] = 3;
    }
    
    // Navio 2: Horizontal (4 posições) - posicao inicial (0,0)
    int navioHorizontal[4][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
    for(int i = 0; i < 4; i++) {
        tabuleiroNovato[navioHorizontal[i][0]][navioHorizontal[i][1]] = 3;
    }
    
    // Exibir coordenadas dos navios
    exibirCoordenadas("Vertical", navioVertical, 3);
    exibirCoordenadas("Horizontal", navioHorizontal, 4);
    
    printf("Tabuleiro Nivel Novato (5x5):\n");
    exibirMatriz(tabuleiroNovato, 5, 5);
    
    // =============================================
    // NIVEL AVENTUREIRO - Expansão e Diagonais
    // =============================================
    printf("=== NIVEL AVENTUREIRO - Tabuleiro 10x10 com Navios Diagonais ===\n");
    
    // Tabuleiro 10x10 para o nível aventureiro
    int tabuleiroAventureiro[10][10];
    inicializarMatriz(tabuleiroAventureiro, 10, 10);
    
    // Navio 1: Vertical (3 posições) - posicao inicial (1,1)
    int navio1[3][2] = {{1, 1}, {2, 1}, {3, 1}};
    for(int i = 0; i < 3; i++) {
        tabuleiroAventureiro[navio1[i][0]][navio1[i][1]] = 3;
    }
    
    // Navio 2: Horizontal (4 posições) - posicao inicial (5,2)
    int navio2[4][2] = {{5, 2}, {5, 3}, {5, 4}, {5, 5}};
    for(int i = 0; i < 4; i++) {
        tabuleiroAventureiro[navio2[i][0]][navio2[i][1]] = 3;
    }
    
    // Navio 3: Diagonal Principal (3 posições) - posicao inicial (0,6)
    int navio3[3][2] = {{0, 6}, {1, 7}, {2, 8}};
    for(int i = 0; i < 3; i++) {
        tabuleiroAventureiro[navio3[i][0]][navio3[i][1]] = 3;
    }
    
    // Navio 4: Diagonal Secundária (3 posições) - posicao inicial (7,7)
    int navio4[3][2] = {{7, 7}, {8, 6}, {9, 5}};
    for(int i = 0; i < 3; i++) {
        tabuleiroAventureiro[navio4[i][0]][navio4[i][1]] = 3;
    }
    
    // Exibir coordenadas dos navios
    exibirCoordenadas("1 (Vertical)", navio1, 3);
    exibirCoordenadas("2 (Horizontal)", navio2, 4);
    exibirCoordenadas("3 (Diagonal Principal)", navio3, 3);
    exibirCoordenadas("4 (Diagonal Secundaria)", navio4, 3);
    
    printf("Tabuleiro Nivel Aventureiro (10x10):\n");
    printf("(0 = vazio, 3 = navio)\n");
    exibirMatriz(tabuleiroAventureiro, 10, 10);
    
    // =============================================
    // NIVEL MESTRE - Habilidades Especiais
    // =============================================
    printf("=== NIVEL MESTRE - Habilidades Especiais com Padroes ===\n");
    
    // Matriz para habilidade CONE (5x5)
    int habilidadeCone[10][10];
    inicializarMatriz(habilidadeCone, 5, 5);
    
    // Padrao Cone: expansao triangular de cima para baixo
    // Linha 0: posicao central (2)
    habilidadeCone[0][2] = 1;
    // Linha 1: 3 posições centrais
    for(int j = 1; j <= 3; j++) {
        habilidadeCone[1][j] = 1;
    }
    // Linha 2: todas as 5 posições
    for(int j = 0; j <= 4; j++) {
        habilidadeCone[2][j] = 1;
    }
    
    // Matriz para habilidade CRUZ (5x5)
    int habilidadeCruz[10][10];
    inicializarMatriz(habilidadeCruz, 5, 5);
    
    // Padrao Cruz: linha horizontal e vertical se cruzando no centro
    // Linha vertical (coluna 2)
    for(int i = 0; i < 5; i++) {
        habilidadeCruz[i][2] = 1;
    }
    // Linha horizontal (linha 1)
    for(int j = 0; j < 5; j++) {
        habilidadeCruz[1][j] = 1;
    }
    
    // Matriz para habilidade OCTAEDRO (5x5)
    int habilidadeOctaedro[10][10];
    inicializarMatriz(habilidadeOctaedro, 5, 5);
    
    // Padrao Octaedro: formato de diamante
    // Linha 0: posicao central
    habilidadeOctaedro[0][2] = 1;
    // Linha 1: 3 posições centrais
    for(int j = 1; j <= 3; j++) {
        habilidadeOctaedro[1][j] = 1;
    }
    // Linha 2: posicao central novamente
    habilidadeOctaedro[2][2] = 1;
    
    // Exibir as habilidades especiais
    printf("Habilidade CONE (0 = nao afetado, 1 = afetado):\n");
    exibirMatriz(habilidadeCone, 3, 5);
    
    printf("Habilidade CRUZ (0 = nao afetado, 1 = afetado):\n");
    exibirMatriz(habilidadeCruz, 3, 5);
    
    printf("Habilidade OCTAEDRO (0 = nao afetado, 1 = afetado):\n");
    exibirMatriz(habilidadeOctaedro, 3, 5);
    
    // Demonstracao de aplicacao das habilidades no tabuleiro
    printf("=== DEMONSTRACAO: APLICACAO DAS HABILIDADES ===\n");
    
    // Aplicar habilidade cone no tabuleiro aventureiro (posicao 6,0)
    int tabuleiroComHabilidades[10][10];
    inicializarMatriz(tabuleiroComHabilidades, 10, 10);
    
    // Copiar navios do nível aventureiro
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiroComHabilidades[i][j] = tabuleiroAventureiro[i][j];
        }
    }
    
    // Aplicar habilidade cone na posicao (6,0)
    int posX = 6, posY = 0;
    printf("Aplicando habilidade CONE na posicao (%d,%d):\n", posX, posY);
    
    // Aplicar padrao cone
    if(posX < 10 && posY+2 < 10) tabuleiroComHabilidades[posX][posY+2] = 5; // Centro linha 0
    if(posX+1 < 10) {
        for(int j = 1; j <= 3 && posY+j < 10; j++) {
            tabuleiroComHabilidades[posX+1][posY+j] = 5; // Linha 1
        }
    }
    if(posX+2 < 10) {
        for(int j = 0; j <= 4 && posY+j < 10; j++) {
            tabuleiroComHabilidades[posX+2][posY+j] = 5; // Linha 2
        }
    }
    
    printf("Tabuleiro final com habilidades aplicadas:\n");
    printf("(0 = vazio, 3 = navio, 5 = area afetada por habilidade)\n");
    exibirMatriz(tabuleiroComHabilidades, 10, 10);
    
    printf("\nPressione ENTER para encerrar o programa...");
    getchar();
    return 0;
}