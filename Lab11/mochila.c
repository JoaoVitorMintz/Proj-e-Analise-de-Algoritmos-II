#include <stdio.h>
#include <stdlib.h>

#define n 3

void ordenar(double *d, double w[], double v[]) {
    for (int i = 0; i < n; i++) {
        d[i] = v[i]/w[i];
    } // Insere valores no vetor densidade
    
    // Ordenar valor:
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (d[j] < d[j + 1]) {
                // Trocar densidade
                double tempD = d[j];
                d[j] = d[j + 1];
                d[j + 1] = tempD;
                
                // Trocar peso correspondente
                double tempW = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempW;
                
                // Trocar valor correspondente
                double tempV = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tempV;
            }
        }
    }
}

void mochila(double w[], double v[], double *d,int W) {
    ordenar(d, w, v);
    int i = 0;
    double x[n];
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }
    
    while (i < n && W > 0) {
        if (w[i] <= W) {
            x[i] = 1;
            W = W - (int)w[i];
        } else {
            x[i] = (double)W / w[i];
            W = 0;
        }
        i++;
    }
    printf("[");
    for (int j = 0; j < n; j++) {
        printf("%.2f ", x[j]);
    }
    printf("]\n");
}

int main()
{
    double valores[n] = {60, 100, 120};
    double peso[n] = {10, 20, 30};
    double *densidade = malloc(sizeof(double) * n);
    int W = 50; // capacidade da mochila
    
    mochila(peso, valores, densidade, W);

    free(densidade);
    return 0;
}