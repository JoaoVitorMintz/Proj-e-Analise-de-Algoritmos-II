#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função recursiva com memoização (Top-Down)
// L[i] representa o tamanho da LIS terminando em i
int LIS(int i, int num[], int L[]) {
    int maior = 1;

    // Se já calculamos L[i], simplesmente retorne
    if (L[i] != -1) return L[i];

    // Caso base
    if (i == 0) return (L[i] = 1);

    // Tenta todos os j < i
    for (int j = 0; j < i; j++) {
        if (num[j] < num[i]) {
            maior = max(maior, LIS(j, num, L) + 1);
        }
    }

    return (L[i] = maior);
}

// Avalia qual LIS(i) é a maior — LIS global
int subseq_cresc_mais_longa(int n, int num[], int L[]) {
    int maior = 1;

    for (int i = 0; i < n; i++) {
        maior = max(maior, LIS(i, num, L));
    }
    return maior;
}

int main() {
    int v[10] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = sizeof(v) / sizeof(int);

    int L[n + 1];

    // Inicializa memo com -1 (não calculado)
    for (int i = 0; i <= n; i++)
        L[i] = -1;

    printf("Tamanho da LIS = %d\n", subseq_cresc_mais_longa(n, v, L));

    // Mostra o vetor L (LIS terminando em cada posição)
    printf("Valores de L:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", L[i]);

    printf("\n");
    return 0;
}
