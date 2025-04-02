#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

int aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int x = linha + i - centro;
            int y = coluna + j - centro;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }
    return 0;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro 
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posições iniciais
    int linhaNavio1 = 2, colunaNavio1 = 3;
    int linhaNavio2 = 5, colunaNavio2 = 6;
    int linhaNavio3 = 1, colunaNavio3 = 1;
    int linhaNavio4 = 1, colunaNavio4 = 8;

    // Posiciona os navios 
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
        tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
        tabuleiro[linhaNavio3 + i][colunaNavio3 + i] = 3;
        tabuleiro[linhaNavio4 + i][colunaNavio4 - i] = 3;
    }

    // Matrizes das habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicar habilidades
    aplicarHabilidade(tabuleiro, 3, 3, cone);
    aplicarHabilidade(tabuleiro, 6, 6, cruz);
    aplicarHabilidade(tabuleiro, 8, 8, octaedro);

    // Exibe o tabuleiro
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
