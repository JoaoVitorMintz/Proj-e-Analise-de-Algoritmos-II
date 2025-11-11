#include <stdio.h>
#include <string.h>

int m[10][10];

int cadeia_matriz_rec(int p[], int i, int j) {
     
    if (i == j) return 0;
    
    for (int k = i; k < j; k++) {
        int q =  cadeia_matriz_rec(p, i, k) + cadeia_matriz_rec(p, k+1, j) + p[i-1] * p[k] * p[j];
        if (q < m[i][j]) {
            m[i][j] = q;
        }
    }
    
    return m[i][j];
}


int main()
{
  
    int p[5] = {200, 2, 30, 20, 5};
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m[i][j] = 999999;
        }
    }
    
      
    printf("%d", cadeia_matriz_rec(p, 1, 4));

    return 0;
}