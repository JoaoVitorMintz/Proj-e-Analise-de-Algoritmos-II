#include <stdio.h>

void combinatoria(char v[4], int index, int golsA, int golsB, int n);

int main() {
    char vet[4] = {'A', 'A', 'A', 'A'};
    int golsA = 3;
    int golsB = 1;
    int n = golsA * golsB;

    printf("Printando todas as combinações de resultados do time AxB:\n");
    combinatoria(vet, 0, golsA, golsB, n);

    return 0;
}

void combinatoria(char v[4], int index, int golsA, int golsB, int n) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%c", v[i]);
        }
        printf("\n");
        return;
    }
    
    if (golsA > 0) {
        v[index] = 'A';
        combinatoria(v, index + 1, golsA - 1, golsB, n);
    }
    if (golsB > 0) {
        v[index] = 'B';
        combinatoria(v, index + 1, golsA, golsB - 1, n);
    }

}