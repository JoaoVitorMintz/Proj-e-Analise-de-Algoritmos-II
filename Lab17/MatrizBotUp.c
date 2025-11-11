#include <stdio.h>
#include <string.h>

int m[10][10];
int s[10][10];

void imprime_parenteses_otimo(int A, int i, int j) {
    if (i == j) {
        return A;
    } else {
        printf("(");
        imprime_parenteses_otimo(A, i, s[i][j]);
        imprime_parenteses_otimo(A, s[i][j] + 1, j);
        printf(")");
    }
}

int calcula_produto(int A,int i, int j) {
    if (i == j) {
        return A;
    } else {
        int X = calcula_produto(A, i, s[i][j]);
        int Y = calcula_produto(A, s[i][j] + 1, j);
        return X * Y;
    }
}

int ordem_cadeia_matriz(int p[], int n) {
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i < n-l+1; i++) {
            int j = i + l - 1;
            m[i][j] = 9999999;
            for (int k = 1; k < j-1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][k] = k;
                }
            }
        }
    }
}


int main()
{
  
    int p[5] = {30, 35, 15, 5, 20};
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }
    
      
    printf("%d", cadeia_matriz_rec(p, 4));

    return 0;
}