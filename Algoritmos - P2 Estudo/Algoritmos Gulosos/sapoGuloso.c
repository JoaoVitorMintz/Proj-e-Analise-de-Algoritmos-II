#include <stdio.h>
#include <stdlib.h>


void pulo_sapo(int p[], int delta, int n) {
    int u[n];

    for (int i = 0; i < n; i++) u[i] = 0;

    u[0] = p[0];
    int ultima_pos = p[0];
    int k = 1; // se indice do p[] é i, indice do u[] é k.

    for (int i = 1; i < n; i++) {
        if (p[i] - ultima_pos > delta) {
            ultima_pos = p[i - 1];
            u[k++] = p[i-1];
        }
    }
    u[k++] = p[n - 1];

    for (int i = 0; i < k; i++) printf("%d ", u[i]);
}

int main() {
    int p[] = {0, 2, 5, 7, 8, 10, 11, 12, 14};
    int n = sizeof(p)/sizeof(p[0]);
    int delta = 2;

    pulo_sapo(p, delta, n);


    return 0;

}