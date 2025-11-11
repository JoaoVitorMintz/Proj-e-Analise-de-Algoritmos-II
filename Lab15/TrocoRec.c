#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int troco(int M[], int T, int n) {
    if (T == 0) {
        return 0;
    }

    if (T < 0) {
        return 1000000;
    }
    
    int menor = 1000000;
    for (int i = 0; i < n; i++) {
        menor = min(menor, troco(M, T - M[i], n) + 1);
    }
    return menor;

}


int main() {
    int M[3] = {1, 4, 6};
    int T = 8;
    int n = 3;

    printf("Menor quantidade de moedas: %d", troco(M, T, n));

    return 0;
}