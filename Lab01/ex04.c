#include <stdio.h>

int fatorial(int n) {
    if (n == 1) return 1;
    else return n * fatorial(n-1);
}


int potencia(int x, int n) {
    if (n == 0) return 1;
    else return x * potencia(x, n-1);
}

int somatorio(int x, int n) {
    if (n == 0) return 1;
    else return potencia(x, n)/fatorial(n) + somatorio(x, n-1);
}

int main() {
    
    int n = 2;
    int x = 5;
    
    printf("%d", somatorio(x, n));
    
    return 0;
}