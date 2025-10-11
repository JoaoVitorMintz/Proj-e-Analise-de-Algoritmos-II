#include <stdio.h>

#define n 3

void binario(int bin[n], int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", bin[i]);
        }
        printf(", ");
        return;
    }

    bin[index] = 0;
    binario(bin, index + 1);

    bin[index] = 1;
    binario(bin, index + 1);
}

int main() {
    int bin[n];

    binario(bin, 0);

    return 0;
}