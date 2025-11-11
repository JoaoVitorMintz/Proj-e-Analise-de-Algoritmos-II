#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Bottom-Up
int subsequencia_crescente_mais_longa(int num[], int L[], int n) {
    for (int i = 0; i < n; i++) {
        L[i] = 1;
    }
    int maior = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                L[i] = max(L[i], L[j] + 1);
            }
            maior = max(maior, L[i]);
        }
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