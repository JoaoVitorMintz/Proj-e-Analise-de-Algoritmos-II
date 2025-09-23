#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void exibirCombinacoes(int vetor[], int k) {
    printf("[");
    for (int i = 0; i < k; i++) {
        printf("%d", vetor[i]);
        if (i < k - 1) printf(", ");
    }
    printf("], ");
}

void jogarDados(int n, int index, int *vetor) {
    if (index == n) {
        exibirCombinacoes(vetor, n);
        return;
    }

    for (int i = 1; i <= 6; i++) {
        vetor[index] = i;
        jogarDados(n, index + 1, vetor);
    }
}

int main() {
    int n;

    printf("Digite o numero de vezes que deseja jogar os dados: ");
    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int));

    jogarDados(n, 0, vetor);

    free(vetor);
    return 0;
}