#include <stdio.h>
#include <stdlib.h>

int fib(int n, int *memo) {
    if (n == 0 || n == 1) {
        return memo[n] = n;  
    } else if (memo[n] != -1) {
        memo[n];
    } else {
        memo[n] = fib(n-1, memo) + fib(n-2, memo);
        return memo[n];
    }
}

int main()
{
    int n = 5;
    int *memo  = malloc((n + 1) * sizeof(int));
    int soma = 0;
    
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    fib(n, memo);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", memo[i]);
        soma += memo[i];
    }
    printf("\nSOMA: %d", soma);
    
    free(memo);

    return 0;
}