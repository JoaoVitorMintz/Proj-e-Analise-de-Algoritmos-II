#include <stdio.h>

int M[10][10];
int pesos[4] = {3, 2, 4, 1};
int valores[4] = {8, 3, 9, 6};

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int maior_valor(int n, int W) {
    if (n < 0 || W <= 0) {
        return 0;
    }

    if (M[n][W] != -1) {
        return M[n][W];
    }

    if (pesos[n] > W) {
        M[n][W] = maior_valor(n-1, W);
    } else {
        M[n][W] = max(maior_valor(n-1, W), maior_valor(n-1, W-pesos[n]) + valores[n]);
    }
    return M[n][W];
}

void mochila(int n, int W) {
    int j = W;
    int m[4] = {0};
    for (int i = n; i >= 0; i--) {
        if (M[i][j] == M[i-1][j] || j == 0) {
            m[i] = 0;
        } else {
            m[i] = 1;
        }

        if (j >= pesos[i]) {
            j = j - pesos[i];
        }
    }
    
    printf("\n[");
    for (int x = 0; x < n; x++) {
        printf("%d ", m[x]);
    }
    printf("]\n");
}

int main() {
    int pesoMax = 5;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            M[i][j] = -1;
        }
    }

    printf("Valor máximo possível na mochila: %d", maior_valor(4, pesoMax));
    mochila(4, pesoMax);


    return 0;
}