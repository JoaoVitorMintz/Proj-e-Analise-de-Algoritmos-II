#include <stdio.h>

#define n 3

void binario(int v[n], int index);

int main() {
    int vet[n] = {0, 0, 0};

    printf("Printando todos os binários de 3 dígitos:\n");
    binario(vet, 0);

    return 0;
}

void binario(int v[n], int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", v[i]);
        }
        printf("\n");
        return;
    }

    v[index] = 0;
    binario(v, index + 1);

    v[index] = 1;
    binario(v, index + 1);

}