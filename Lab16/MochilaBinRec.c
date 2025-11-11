#include <stdio.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int maior_valor(int n, int W, int w[], int v[]) {
    if (n < 0 || W <= 0) {
        return 0;
    }

    if (w[n] > W) {
        return maior_valor(n-1, W, w, v); // Não inclui o item por não caber na mochila
    } else {
        return max(maior_valor(n-1, W, w, v), maior_valor(n-1, W - w[n], w, v) + v[n]); // Inclui o item maior
    }
}

int main() {
    int pesos[4] = {3, 2, 4, 1};
    int valores[4] = {8, 3, 9, 6};
    int pesoMax = 5;

    printf("Valor máximo possível na mochila: %d\n", maior_valor(3, pesoMax, pesos, valores));


    return 0;
}