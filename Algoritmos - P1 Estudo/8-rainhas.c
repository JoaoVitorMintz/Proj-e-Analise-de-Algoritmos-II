#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void mostra_matriz(char tabuleiro[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool rainha_salva(char tabuleiro[8][8], int linha, int coluna) {
    int i, j;
    for (i = 0; i < coluna; i++) {
        if (tabuleiro[linha][i] == 'Q') return false;
    }

    // diagonal superior esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == 'Q') return false;
    }

    // diagonal inferior esquerda
    for (i = linha, j = coluna; i < 8 && j >= 0; i++, j--) {
        if (tabuleiro[i][j] == 'Q') return false;
    }

    return true;
}

void posiciona_rainha(char tabuleiro[8][8], int coluna) {
    if (coluna == 8) mostra_matriz(tabuleiro);
    else {
        for (int i = 0; i < 8; i++) {
            if (rainha_salva(tabuleiro, i, coluna)) {
                tabuleiro[i][coluna] = 'Q';
                posiciona_rainha(tabuleiro, coluna + 1);
                tabuleiro[i][coluna] = '-';
            }
        }
    }
}

int main(void) {
    char tabuleiro[8][8];
    memset(tabuleiro, '-', sizeof(tabuleiro));
    posiciona_rainha(tabuleiro, 0);
    
    return 0;
}