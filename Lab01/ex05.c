#include <stdio.h>
#include <stdlib.h>

void inverte(int vet[], int fim, int inicio) {
    int aux;
    if (inicio < fim) {
        aux = vet[inicio]; 
        vet[inicio] = vet[fim];
        vet[fim] = aux;
        inverte(vet, fim - 1, inicio + 1);
    }
}

int main() {
    
    int vet[6] = {1, 5, 2, 7, 6, 4};

    printf("{");
    for (int i = 0; i < 6; i++) {
        printf("%d ",  vet[i]);
    }
    printf("}\n");
    
    inverte(vet, 5, 0);
    
    printf("{");
    for (int i = 0; i < 6; i++) {
        printf("%d ",  vet[i]);
    }
    printf("}");

    return 0;
    
}