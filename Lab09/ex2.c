#include <stdio.h>
#include <stdlib.h>

void exibirCombinacoes(int vetor[], int k) {
    for (int i = 0; i < k; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void combinatoria(int *v, int index, int n) {
    if (n == 0) {
        exibirCombinacoes(v, index);
        return;
    }

    if (n < 0) return;

    for (int i = 1; i <= 3; i++) {
        v[index] = i;
        combinatoria(v, index + 1, n - i);
    }

}

int main() {
    int n;

    printf("Indique a quantidade de degraus: ");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));

    combinatoria(v, 0, n);

    free(v);
    return 0;
}