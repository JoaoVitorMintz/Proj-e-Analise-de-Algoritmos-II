#include <stdio.h>

// Versão bottom-up:
int fib(int n, int f[]) {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main() {
    int n = 10;
    int f[n+1];

    printf("Fibonacci de %d = %d", n, fib(n, f));

    return 0;

}