#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// ITERATIVA:
int LIS(int i, int num[]) {
    if (i == 0) return 1;

    int maior = 1;
    for (int j = 0; j < i; j++) {
        if (num[j] < num[i]) {
            maior = max(LIS(j, num) + 1, maior);
        }
    }
    return maior;
}

// Recursivo:
int subseq_cresc_mais_longa(int n, int num[]) {
    int maior = 1;
    for (int i = 0; i < n; i++) {
        maior = max(maior, LIS(i, num));
    }
    return maior;
}

int main() {
    int v[10] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = sizeof(v) / sizeof(int);

    // printf("%d", LIS(n, v));
    printf("%d", subseq_cresc_mais_longa(n, v));

    return 0;

}