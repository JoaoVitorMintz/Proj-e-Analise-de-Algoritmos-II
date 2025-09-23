#include <stdio.h>

int seq(int i, int j, int vetor[3], int v, int size);

int main() {

    int vetor[] = {2, 4, 8};
    int v = 10;
    int size = sizeof(vetor)/sizeof(int);

    if (seq(0, 0, vetor, v, size) > 0) {
        printf("true");
    } else {
        printf("false");
    }
}

int seq(int i, int j, int vetor[3], int v, int size) {
    if (i == size) return 0;
    
    if (i != j) {
        int soma = vetor[i] + vetor[j];
        if (soma == v) return 1;
    }
    
    if (j == size) {
        return seq(i + 1, i + 2, vetor, v, size);
    }
    
    return seq(i, j+1, vetor, v, size);
}