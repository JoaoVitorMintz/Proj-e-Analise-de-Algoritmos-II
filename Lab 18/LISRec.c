#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int LIS(int num[], int i) {
    if (i == 0) {
        return 1;
    } else {
        int maior = 1;
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                maior = max(maior, LIS(num, j) + 1);
            }
        }
        return maior;
    }
}

int subsequencia_crescente_mais_longa(int num[], int n) {
    int maior = 1;
    for (int i = 0; i < n; i++) {
        maior = max(maior, LIS(num, i));
    }
    return maior;
}

int main() {
    int v[10] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = sizeof(v) / sizeof(int);


    printf("Tamanho da subsequencia crescente mais longa: %d\n", subsequencia_crescente_mais_longa(v, n));

    return 0;
}