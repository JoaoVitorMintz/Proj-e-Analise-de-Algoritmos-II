#include <stdio.h>

int S[6];

void ordenar(int C[]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 3; j++) {
            if (C[j] > C[i]) {
                int aux = C[i];
                C[i] = C[j];
                C[j] = aux;
            }
        }
    }
}

void troco(int C[], int valor, int qnt_de_moedas) {
    ordenar(C);
    int soma = 0;
    int contador = 0; // Indice para pegar a moeda específica em C[]
    int k = 0; // Indice de S[] para inserir valor da moeda que da esse valor

    while (contador < qnt_de_moedas && soma < valor) {
        int m = C[contador];

        if (soma + m <= valor) {
            soma += m;
            S[k++] = m;
        } else {
            contador++;
        }
    }
}

int main() {
    int N = 12;
    int M[3] = {1,2,5};

    for (int i = 0; i < 6; i++) {
        S[i] = 0;
    }

    troco(M, N, 3);
    printf("Problema do troco (GULOSO):\n");

    printf("C = {");
    for (int i = 0; i < 3; i++) printf("%d ", M[i]);
    printf("}, valor = %d\n", N);

    printf("[");
    for (int i = 0; i < 6; i++) printf("%d ", S[i]);
    printf("]");

    return 0;

}