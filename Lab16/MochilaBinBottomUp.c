#include <stdio.h>

int M[10][10];
int pesos[4] = {3, 2, 4, 1};
int valores[4] = {8, 3, 9, 6};

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int maior_valor(int n, int W) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (pesos[i-1] > j) {
                M[i][j] = M[i-1][j];
            } else {
                M[i][j] = max(M[i-1][j], M[i-1][j-pesos[i]] + valores[i]);
            }
        }
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
            M[i][j] = 0;
        }
    }

    printf("Valor máximo possível na mochila: %d", maior_valor(4, pesoMax));
    mochila(4, pesoMax);


    return 0;
}