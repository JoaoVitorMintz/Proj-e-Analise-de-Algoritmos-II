#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Top-Down
int LIS(int num[], int L[], int i) {
    if (L[i] != -1) {
        return L[i];
    } else if (i == 0) {
        return 1;
    } else {
        int maior = 1;
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                maior = max(maior, LIS(num, L, j) + 1);
            }
        }
        L[i] = maior;
        return L[i];
    }
}

int subsequencia_crescente_mais_longa(int num[], int L[], int n) {
    int maior = 1;
    for (int i = 0; i < n; i++) {
        maior = max(maior, LIS(num, L, i));
    }
    return maior;
}

int main() {
    int v[10] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = sizeof(v) / sizeof(int);
    int L[10];

    for (int i = 0; i < n; i++) {
        L[i] = -1;
    }


    printf("Tamanho da subsequencia crescente mais longa: %d\n", subsequencia_crescente_mais_longa(v, L, n));

    return 0;
}