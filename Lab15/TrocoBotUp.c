#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int troco(int M[], int T, int trocoV[], int n) {
    for (int i = 0; i <= T; i++) {
        trocoV[i] = 10000000;
    }
    trocoV[0] = 0;
    for (int i = 0; i <= T; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= M[j]) {
                trocoV[i] = min(trocoV[i], trocoV[i - M[j]] + 1);
            }
        }
    }
    return trocoV[T];
}


int main() {
    int M[3] = {1, 4, 6};
    int T = 8;
    int n = 3;
    int trocoV[9];


    printf("Menor quantidade de moedas: %d", troco(M, T, trocoV, n));

    return 0;
}