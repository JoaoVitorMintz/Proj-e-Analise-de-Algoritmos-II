#include <stdio.h>
#include <string.h>

int m[10][10];
int s[10][10];

void imprime_parenteses_otimo(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        imprime_parenteses_otimo(i, s[i][j]);
        imprime_parenteses_otimo(s[i][j] + 1, j);
        printf(")");
    }
}

int ordem_cadeia_matriz(int p[], int n) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

int main() {  
    int p[5] = {200, 2, 30, 20, 5};
    int n = (sizeof(p) / sizeof(p[0])) - 1;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m[i][j] = 999999;
        }
    }

    int custo = ordem_cadeia_matriz(p, n);
    printf("Custo mínimo de multiplicações: %d\n", custo);

    printf("Parentização ótima: ");
    imprime_parenteses_otimo(1, n);
    printf("\n");

    return 0;
}