#include <stdio.h>

void troco(int C[], int n, int valor) {
    int S[100];
    int soma = 0;
    int count = 0; 
    int i = n - 1; 

    while (i >= 0 && soma < valor) {
        int m = C[i]; 

        if (soma + m <= valor) {
            soma = soma + m;
            S[count++] = m;
        } 
        else {
            i--;
        }
    }

    if (soma == valor) {
        printf("S = { ");
        for (int j = 0; j < count; j++) {
            printf("%d ", S[j]);
        }
        printf("}\n");
    } 
    else {
        printf("não encontrei a solução\n");
    }
}

int main() {
    int C[] = {1, 4, 6};
    int n = sizeof(C) / sizeof(C[0]);
    int valor = 8;

    troco(C, n, valor);

    return 0;
}
