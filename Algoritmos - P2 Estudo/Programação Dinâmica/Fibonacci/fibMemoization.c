#include <stdio.h>

// Versão top-down:
int fib(int n, int memo[]) {
    if (memo[n] != -1) return memo[n];
    else if (n == 0 || n == 1) memo[n] = n;
    else memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int main() {
    int n = 5;
    int memo[n+1];

    for (int i = 0; i <= n; i++) memo[i] = -1;

    printf("Fibonacci de %d = %d\n", n, fib(n, memo));

    for (int i = 0; i <= n; i++) printf("%d ", memo[i]);

    return 0;

}