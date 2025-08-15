#include <stdio.h>

int qtd(int k, int n, int soma) {
    if (n == 0 ) return soma;

    if (n % 10 == k){
        soma += 1;
    } 
    return qtd(k, n / 10, soma);
    
}

int main() {
    int k = 2;
    int n = 291120267;

    printf("%d", qtd(k, n, 0));

    return 0;
    
}