#include <stdio.h>

#define n 3

void escreverBin(int bin[]) {
    for (int i = 0; i < n; i++) {
        printf("%d", bin[i]);
    }
    printf(", ");
}


void binario(int bin[3], int val[3], int index) {
    if (index == n) escreverBin(bin);
    else {
        for (int i = 0; i < 2; i++) {
            bin[index] = val[i];
            binario(bin, val, index + 1);
        }
    }
}


int main() {
    int bin[3];
    int valores[2] = {0, 1};

    binario(bin, valores, 0);

    return 0;
}