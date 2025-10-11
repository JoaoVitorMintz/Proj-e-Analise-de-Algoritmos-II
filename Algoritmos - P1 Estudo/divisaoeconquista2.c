#include <stdio.h>


void resultado(char v[], int index, int n, int m) {
    if (index == 4) {
        printf("[");
        for (int i = 0; i < 4; i++) {
            printf("%c", v[i]);
        }
        printf("], ");
    }

    if (n != 0) {
        v[index] = 'B';
        resultado(v, index + 1, n-1, m);
    }

    if (m != 0) {
        v[index] = 'A';
        resultado(v, index + 1, n, m - 1);
    }

}

int main() {
    char v[4];
    int n = 1;
    int m = 3;

    resultado(v, 0, n, m);

    return 0;
}