#include <stdio.h>

int polinomio(int x, int n, int v[]) {
    if (n == 0) return v[0];
    else return polinomio(x, n - 1, v + 1) * x + v[0];
}

int main() {
    int x = 1;
    int n = 3;
    int vet[4] = {3, 4, 2, -7};

    printf("%d", polinomio(x, n, vet));

    return 0;
    
}