#include <stdio.h>

void combinacao(int n, int k, int vetor[], int inicio, int index);

void exibirCombinacoes(int vetor[], int k) {
    printf("[");
    for (int i = 0; i < k; i++) {
        printf(" %d ", vetor[i]);
    }
    printf("] ");
}

int main() {
    int n, k;
    
    printf("Indique o número de n: ");
    scanf("%d", &n);
    printf("Indique o número de k: ");
    scanf("%d", &k);
    
    int subVetor[k];
    
    combinacao(n, k, subVetor, 1, 0);
    
    return 0;
}

void combinacao(int n, int k, int vetor[], int inicio, int index) {
    if (index == k) { 
        exibirCombinacoes(vetor, k);
        return;
    }
    
    for (int i = inicio; i <= n; i++) {
        vetor[index] = i;
        combinacao(n, k, vetor, i + 1, index + 1);
    }
}