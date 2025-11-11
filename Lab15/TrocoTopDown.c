#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int troco(int M[], int T, int memo[], int n) {
    if (T == 0) {
        return 0;
    }
    if (T < 0) {
        return 1000000;
    }
    if (memo[T] != -1) {
        return memo[T];
    }
    
    int menor = 1000000;
    for (int i = 0; i < n; i++) {
        menor = min(menor, troco(M, T - M[i], memo, n) + 1);
    }
    memo[T] = menor;
    return memo[T];

}


int main() {
    int M[3] = {1, 4, 6};
    int T = 8;
    int n = 3;
    int memo[9];

    for (int i = 0; i <= T; i++) {
        memo[i] = -1;
    }

    printf("Menor quantidade de moedas: %d", troco(M, T, memo, n));

    return 0;
}