#include <stdio.h>
#include <stdlib.h>

int melhorDif;
int *melhor, melhorTam;

int absVal(int x) {
    return x < 0 ? -x : x;
}

void busca(int arr[], int n, int index, int *escolhidos, int tamEscolhido,
           int alvoTam, int soma1, int somaTotal) {
    if (tamEscolhido == alvoTam) {
        int soma2 = somaTotal - soma1;
        int dif = absVal(soma1 - soma2);

        if (melhorDif == -1 || dif < melhorDif) {
            melhorDif = dif;
            melhorTam = tamEscolhido;
            for (int i = 0; i < tamEscolhido; i++) {
                melhor[i] = escolhidos[i];
            }
        }
        return;
    }
    if (index == n) return;

    escolhidos[tamEscolhido] = arr[index];
    busca(arr, n, index + 1, escolhidos, tamEscolhido + 1, alvoTam,
          soma1 + arr[index], somaTotal);

    busca(arr, n, index + 1, escolhidos, tamEscolhido, alvoTam,
          soma1, somaTotal);
}

int main() {
    int arr[10] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int somaTotal = 0;
    for (int i = 0; i < n; i++) somaTotal += arr[i];

    int alvoTam;
    if (n % 2 == 0)
        alvoTam = n / 2;
    else
        alvoTam = (n - 1) / 2; 

    int *escolhidos = malloc(alvoTam * sizeof(int));
    melhor = malloc(alvoTam * sizeof(int));

    melhorDif = -1;  

    busca(arr, n, 0, escolhidos, 0, alvoTam, 0, somaTotal);

    printf("Subconjunto 1: ");
    for (int i = 0; i < melhorTam; i++) printf("%d ", melhor[i]);
    printf("\n");

    printf("Subconjunto 2: ");
    int usados[100] = {0};
    for (int i = 0; i < melhorTam; i++) {
        for (int j = 0; j < n; j++) {
            if (!usados[j] && arr[j] == melhor[i]) {
                usados[j] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) if (!usados[i]) printf("%d ", arr[i]);
    printf("\n");

    printf("Diferença mínima = %d\n", melhorDif);

    free(escolhidos);
    free(melhor);
    return 0;
}
