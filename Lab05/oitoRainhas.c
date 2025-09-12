#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 8

void posicionaRainha(char tab[N][N],int coluna);
bool rainhaSalva(char tabuleiro[][N], int linha, int coluna);
void mostraMatriz(char tab[N][N]);


int main() {
    
    char tabuleiro[N][N];
    memset(tabuleiro, '-', sizeof(tabuleiro));
    posicionaRainha(tabuleiro, 0);
    

    return 0;
}

void posicionaRainha(char tab[N][N], int coluna) {
    if (coluna == N) {
        mostraMatriz(tab); 
        printf("\n\n");
    } else {
        for (int i = 0; i < N; i++) {
            if (rainhaSalva(tab, i, coluna) == true) {
                tab[i][coluna] = 'Q';
                posicionaRainha(tab, coluna + 1);
                tab[i][coluna] = '-';
            }
        }
    }
}

bool rainhaSalva(char tab[][N], int linha, int coluna) {
    int i, j;
    for (i = 0; i < coluna; i++) {
        if (tab[linha][i] == 'Q') return false;
    }
    
    for (int i = linha, j = coluna; i >= 0 && j >= 0; i--, j--) {
        if (tab[i][j] == 'Q') return false;
    }
    
    for (int i = linha, j = coluna; i < N && j >= 0; i++, j--) {
        if (tab[i][j] == 'Q') return false;
    }
    return true;
}

void mostraMatriz(char tab[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}