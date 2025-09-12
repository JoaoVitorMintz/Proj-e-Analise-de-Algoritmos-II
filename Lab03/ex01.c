/*
ALUNO: João Vitor Garcia Aguiar Mintz
RA: 10440421
*/


#include <stdio.h>

void escreva(int s[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("]  ");
}   

void mostra_sequencias(int s[], int n, int v[], int i) {
    if (i == n) escreva(s, n);
    else {
        for (int j = 0; j <= n-1; j++) {
        s[i] = v[j];
        mostra_sequencias(s, n, v, i + 1);
        }
    }
}

int main()
{
    int s[3];
    int v[3] = {1, 2, 3};
    int n = 3;
    mostra_sequencias(s, n, v, 0);

    return 0;
}