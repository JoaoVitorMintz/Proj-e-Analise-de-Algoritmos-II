#include <stdio.h>

void sapo(int p[], int delta, int n) {
    int pedras[n];
    int idx;

    for (int i = 0; i < n; i++) {
        pedras[i] = 0;
    }

    pedras[idx] = p[n-1]


}

int main() {
    int p[] = {1, 2, 3, 5, 6, 7};
    int delta = 2;
    int n = sizeof(p) / sizeof(p[0]);

    sapo(p, delta, n);

    return 0;
}