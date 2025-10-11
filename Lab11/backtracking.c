#include <stdio.h>

void exibirVetor(int S[], int tam)  {
    printf("S = { ");
    for (int j = 0; j < tam; j++) {
        printf("%d ", S[j]);
    }
    printf("}\n");
}

int somaAtual(int S[], int tam) {
    int soma = 0;
    for (int i = 0; i < tam; i++) soma += S[i];
    return soma;
}

void troco(int C[], int n, int valor, int S[], int index) {
    int soma = somaAtual(S, index);

    if (soma == valor) {
        exibirVetor(S, index);
        return;
    }
    if (soma > valor) return;

    for (int i = 0; i < n; i++) {
        S[index] = C[i];
        troco(C, n, valor, S, index + 1);
    }
}

int main() {
    int C[] = {1, 4, 6};
    int S[20];
    int n = sizeof(C) / sizeof(C[0]);
    int valor = 8;

    troco(C, n, valor, S, 0);

    return 0;
}
