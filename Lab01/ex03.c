#include <stdio.h>

int potencia(int x, int n) {
    if (n == 0) return 1;
    else return x * potencia(x, n-1);
}

int main() {
    
    int n = 2;
    int x = 5;
    
    printf("%d", potencia(x, n));
    
    return 0;
}