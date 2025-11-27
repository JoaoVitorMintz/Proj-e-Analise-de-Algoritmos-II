#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função recursiva com memoização (Top-Down)
// int LIS(int i, int num[], int L[]) {
//     int maior = 1;

//     // Se já calculamos L[i], simplesmente retorne
//     if (L[i] != -1) return L[i];

//     // Caso base
//     if (i == 0) return (L[i] = 1);

//     // Tenta todos os j < i
//     for (int j = 0; j < i; j++) {
//         if (num[j] < num[i]) {
//             maior = max(maior, LIS(j, num, L) + 1);
//         }
//     }

//     return (L[i] = maior);
// }

int subseq_cresc_mais_longa(int n, int num[], int L[]) {
    for (int i = 0; i < n; i++) {
        L[i] = 1;
    }

    int maior = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                L[i] = max(L[i], L[j] + 1);
            }
        }
        maior = max(maior, L[i]);
    }
    return maior;
}


int main() {
    int v[10] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = sizeof(v) / sizeof(int);

    int L[n + 1];

    printf("Tamanho da LIS = %d\n", subseq_cresc_mais_longa(n, v, L));

    // Mostra o vetor L (LIS terminando em cada posição)
    printf("Valores de L:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", L[i]);

    printf("\n");
    return 0;
}
