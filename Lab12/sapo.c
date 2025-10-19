#include <stdio.h>
#include <stdlib.h>

void sapo(int p[], int n, int delta) {
    int u[n];
    int idx = 0;

    u[idx++] = p[0];
    int ultima_pos = p[0];

    for (int i = 1; i < n; i++) {
        if (p[i] - ultima_pos > delta) {
            ultima_pos = p[i - 1];
            u[idx++] = ultima_pos; 
        }
    }
    u[idx++] = p[n - 1];
    
    printf("Posições selecionadas: ");
    for (int i = 0; i < idx; i++) {
        printf("%d ", u[i]);
    }
    printf("\n");
}

int main() {
    int p[] = {0, 2, 5, 7, 8, 10, 11, 12, 14};
    int n = sizeof(p) / sizeof(p[0]);
    int delta = 2; 

    sapo(p, n, delta);
    
    return 0;
}
