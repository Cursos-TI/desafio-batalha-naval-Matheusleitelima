#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro 
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};
    int navioDiagonal1[TAMANHO_NAVIO] = {3, 3, 3};
    int navioDiagonal2[TAMANHO_NAVIO] = {3, 3, 3};

    
    int linhaNavio1 = 2, colunaNavio1 = 3; // Navio horizontal
    int linhaNavio2 = 5, colunaNavio2 = 6; // Navio vertical
    int linhaNavio3 = 1, colunaNavio3 = 1; // Navio diagonal para baixo
    int linhaNavio4 = 1, colunaNavio4 = 8; // Navio diagonal para cima

    // Verifica se os navios cabem no tabuleiro
    if (colunaNavio1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        linhaNavio2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        linhaNavio3 + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaNavio3 + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        linhaNavio4 + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaNavio4 - TAMANHO_NAVIO < -1) {
        printf("Erro: Navio fora do tabuleiro!\n");
        return 1;
    }

    // Verifica sobreposição 
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavio1][colunaNavio1 + i] == 3 ||
            tabuleiro[linhaNavio2 + i][colunaNavio2] == 3 ||
            tabuleiro[linhaNavio3 + i][colunaNavio3 + i] == 3 ||
            tabuleiro[linhaNavio4 + i][colunaNavio4 - i] == 3) {
            printf("Erro: Navios se sobrepõem!\n");
            return 1;
        }
    }

    // Posiciona os navios 
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = navioHorizontal[i];
        tabuleiro[linhaNavio2 + i][colunaNavio2] = navioVertical[i];
        tabuleiro[linhaNavio3 + i][colunaNavio3 + i] = navioDiagonal1[i];
        tabuleiro[linhaNavio4 + i][colunaNavio4 - i] = navioDiagonal2[i];
    }

    // 
    printf("   A B C D E F G H I J\n"); 
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // Exibe os números das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
