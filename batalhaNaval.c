#include <stdio.h>

int main() {
    int tamanho_tabuleiro = 10;
    int tamanho_navio = 3;
    int tabuleiro[10][10];

    // Inicia o tabuleiro com 0
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vet os navios
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Posições de navios
    int linhaNavio1 = 2, colunaNavio1 = 3;
    int linhaNavio2 = 5, colunaNavio2 = 6;

    // Verifica se os navios tem o tamanho certo
    if (colunaNavio1 + tamanho_navio > tamanho_tabuleiro ||
        linhaNavio2 + tamanho_navio > tamanho_tabuleiro) {
        printf("Erro: Navio fora do tabuleiro!\n");
        return 1;
    }

    // Verifica sobreposição
    int sobreposicao = 0;
    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linhaNavio1][colunaNavio1 + i] == 3 ||
            tabuleiro[linhaNavio2 + i][colunaNavio2] == 3) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: Navio se sobrepõem!\n");
        return 1;
    }

    // Posiciona de navios
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = navioHorizontal[i];
        tabuleiro[linhaNavio2 + i][colunaNavio2] = navioVertical[i];
    }

    // Exibe o tabuleiro
    printf("  A B C D E F G H I J\n");
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
