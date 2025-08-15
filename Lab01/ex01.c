#include <stdio.h>

int mult(int a, int b) {
    if (b == 1) return a;
    else return mult(a, b-1) + a;
}

int main() {

    int a = 4;
    int b = 3;

    printf("%d", mult(a, b));

    return 0;
}