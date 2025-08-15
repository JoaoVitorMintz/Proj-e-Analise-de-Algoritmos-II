#include <stdio.h>

int maiorV(int v[], int n) {
    if (n == 1) return v[0];
    int maior = maiorV(v, n - 1);

    if (v[n-1] > maior) return v[n-1];
    else return maior;
}

int main() {
    int n = 5;
    int v[5] = {1, 95, 23, 42, 36};


    printf("%d", maiorV(v, n));

    return 0;
}