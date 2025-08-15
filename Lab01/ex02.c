#include <stdio.h>

int nImpares(int n) {
    if (n == 1) return 1;
    
    else if (n+1 % 2 != 0) return (2 * n-1) + nImpares(n-1);
}

int main() {
    
    int n = 5;
    
    printf("%d", nImpares(n));
    
    return 0;
}